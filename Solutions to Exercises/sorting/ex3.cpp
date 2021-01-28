#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Point {
 public:
  int x;
  int y;
  int d2;

  Point(int x = 0, int y = 0) {
    this->x = x;
    this->y = y;
    this->d2 = (x * x) + (y * y);
  }
  
  bool operator<(const Point &b) const {
    return this->d2 < b.d2;
  }
};

priority_queue<Point> heap;
int n, k;

int main() {
  int i, x, y;

  scanf("%d %d", &n, &k);
  for (i = 0; i < n; i++) {
    scanf("%d %d", &x, &y);
    Point p = Point(x, y);
    if (heap.size() < k) {
      heap.push(p);
    } else if (heap.top().d2 > p.d2) {
      heap.pop();
      heap.push(p);
    }
  }

  while (!heap.empty()) {
    printf("%d %d\n", heap.top().x, heap.top().y);
    heap.pop();
  }

  return 0;
}