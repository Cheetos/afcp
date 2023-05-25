#include <bits/stdc++.h>

using namespace std;

class Node {
   public:
    int maxValue;
    int a;
    int b;

    Node(int a = 0, int b = 0, int maxValue = 0) {
        this->a = a;
        this->b = b;
        this->maxValue = maxValue;
    }
};

vector<Node> segmentTree;
void buildSegmentTree(vector<int>& x) {
    // find the size of the tree
    int n = 1;
    while (n < x.size()) {
        n *= 2;
    }

    // allocate memory for the segment tree
    segmentTree.resize(2 * n - 1);

    // initialize leaf nodes
    for (int i = 0, j = n - 1; j < 2 * n - 1; i++, j++) {
        if (i < x.size()) {
            segmentTree.at(j) = Node(i, i, x.at(i));
        } else {
            segmentTree.at(j) = Node(i, i, 0);
        }
    }

    // compute internal nodes
    for (int i = 2 * n - 2; i > 0; i -= 2) {
        int a = segmentTree.at(i - 1).a;
        int b = segmentTree.at(i).b;
        int maxValue = max(segmentTree.at(i - 1).maxValue, segmentTree.at(i).maxValue);
        segmentTree.at(i / 2 - 1) = Node(a, b, maxValue);
    }
}

int findMaxValue(int a, int b, int k) {
    if (a > segmentTree[k].b || b < segmentTree[k].a) {
        return 0;
    }

    a = max(a, segmentTree[k].a);
    b = min(b, segmentTree[k].b);

    if (a == segmentTree[k].a && b == segmentTree[k].b) {
        return segmentTree[k].maxValue;
    }

    int maxLeft = findMaxValue(a, b, 2 * k + 1);
    int maxRight = findMaxValue(a, b, 2 * k + 2);
    return max(maxLeft, maxRight);
}

int getMaxValue(int a, int b) {
    return findMaxValue(a, b, 0);
}

typedef pair<int, int> query;

int main() {
    vector<int> x = {5, 3, 8, 1, 5, 7, 4, 0, 9, 2, 6};
    vector<query> queries = {query(3, 9), query(2, 3), query(4, 7), query(9, 10)};

    buildSegmentTree(x);

    int I, J;
    for (int i = 0; i < queries.size(); i++) {
        printf("max value in [%d, %d] = %d\n",
               queries[i].first,
               queries[i].second,
               getMaxValue(queries[i].first, queries[i].second));
    }

    return 0;
}
