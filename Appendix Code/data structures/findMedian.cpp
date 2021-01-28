#include <cstdio>
#include <queue>
#define N 100001
using namespace std;

int n;
int A[N];
priority_queue<int> LH, UH;

void getMedians();

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }

  getMedians();
  return 0;
}

void getMedians() {
  int k;
  double median;

  // The first median is the first number of the array
  printf("%.1lf\n", (double)A[0]);

  // Add the first number to the lower heap
  LH.push(A[0]);

  for (int i = 1; i < n; i++) {
    if (A[i] <= LH.top()) {
      LH.push(A[i]);  // Add A[i] to the lower heap
    } else {
      UH.push(-A[i]);  // Add A[i] to the upper heap
    }

    // Do we have more elements in the lower heap?
    if ((int)LH.size() - (int)UH.size() >= 2) {
      k = LH.top();
      LH.pop();     // Remove the largest element of the lower heap
      UH.push(-k);  // Add it to the upper heap
    } else if ((int)UH.size() - (int)LH.size() >= 2) {
      k = -UH.top();
      UH.pop();    // Remove the smallest element of the upper heap
      LH.push(k);  // Add it to the lower heap
    }

    // Get the median
    if ((int)LH.size() == (int)UH.size()) {
      median = (LH.top() - UH.top()) / 2.0;
    } else if ((int)LH.size() > (int)UH.size()) {
      median = (double)LH.top();
    } else {
      median = -1.0 * UH.top();
    }

    printf("%.1lf\n", median);
  }
}