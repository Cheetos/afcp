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

Point Gopher[N];
Point hawk;
int nGophers, R;

int euclideanDistance2(Point, Point);

int main() {
  int dis, gophersInDanger = 0;

  // Read the location of the hawk, the attack radius and
  // the number of gophers
  scanf("%d %d %d %d", &hawk.x, &hawk.y, &R, &nGophers);

  // Read the location of every gopher and calculate
  // the distance to the hawk.
  for (int i = 0; i < nGophers; i++) {
    scanf("%d %d", &Gopher[i].x, &Gopher[i].y);
    dis = euclideanDistance2(hawk, Gopher[i]);
    if (dis <= R * R) {
      gophersInDanger++;
    }
  }

  printf("%d\n", gophersInDanger);
  return 0;
}

int euclideanDistance2(Point a, Point b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}