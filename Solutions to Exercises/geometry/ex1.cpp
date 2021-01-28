#include <cstdio>
#include <algorithm>
#define N 101
using namespace std;

class Point {
 public:
  int x;
  int y;
  Point(int x = 0, int y = 0) {
    this->x = x;
    this->y = y;
  }
};

Point P[N];
int n;

int area(Point, Point, Point);

int main() {
  int nCollinear, maxCollinear;

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &P[i].x, &P[i].y);
  }

  maxCollinear = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      nCollinear = 0;
      for (int k = 0; k < n; k++) {
        int A = area(P[i], P[j], P[k]);
        if (A == 0) {
          nCollinear++;
        }
      }

      maxCollinear = max(maxCollinear, nCollinear);
    }
  }

  printf("%d\n", maxCollinear);
  return 0;
}

int area(Point a, Point b, Point c) {
  return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}