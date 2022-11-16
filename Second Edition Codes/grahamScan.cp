#include <bits/stdc++.h>
using namespace std;

typedef struct stPoint {
  int x;
  int y;
  stPoint(int x = 0, int y = 0) {
    this->x = x;
    this->y = y;
  }
} Point;

int n = 13;
vector<Point> points = {Point(1, 1), Point(4, 1),  Point(7, 1), Point(10, 1),
                        Point(9, 3), Point(10, 8), Point(8, 8), Point(4, 9),
                        Point(2, 7), Point(6, 5),  Point(4, 3), Point(2, 3),
                        Point(6, 4)};
vector<Point> LH, UH, ZH;
vector<int> convexHull;
Point pl, pr;

bool compare(Point, Point);
int area(Point, Point, Point);
void sortPoints();
void grahamScan();

int main() {
  sortPoints();
  grahamScan();

  cout << "Number of points in the convex hull: " << convexHull.size() << "\n";
  for (int i = 0; i < convexHull.size(); i++) {
    printf("%d, %d\n", points[convexHull[i]].x, points[convexHull[i]].y);
  }

  return 0;
}

void sortPoints() {
  int pos1 = 0;
  int pos2 = 0;
  for (int i = 0; i < n; i++) {
    if (points[i].x < points[pos1].x) {
      pos1 = i;
    } else if (points[i].x == points[pos1].x && points[i].y < points[pos1].y) {
      pos1 = i;
    }

    if (points[i].x > points[pos2].x) {
      pos2 = i;
    } else if (points[i].x == points[pos2].x && points[i].y < points[pos2].y) {
      pos2 = i;
    }
  }

  pl = points[pos1];
  pr = points[pos2];
  for (Point point : points) {
    int a = area(pl, point, pr);
    if (a > 0) {
      LH.push_back(point);
    } else if (a < 0) {
      UH.push_back(point);
    } else {
      ZH.push_back(point);
    }
  }

  sort(LH.begin(), LH.end(), compare);
  sort(UH.begin(), UH.end(), compare);
  sort(ZH.begin(), ZH.end(), compare);

  // Merge LH, ZH and UH
  n = 0;
  if (LH.empty()) {
    for (int i = 0; i < ZH.size(); i++) {
      points[n++] = ZH[i];
    }
    for (int i = 0; i < UH.size(); i++) {
      points[n++] = UH[i];
    }
  } else if (UH.empty()) {
    points[n++] = pl;
    for (int i = 0; i < LH.size(); i++) {
      points[n++] = LH[i];
    }
    for (int i = ZH.size() - 1; i > 0; i--) {
      points[n++] = ZH[i];
    }
  } else {
    points[n++] = pl;
    for (int i = 0; i < LH.size(); i++) {
      points[n++] = LH[i];
    }
    for (int i = 1; i < ZH.size(); i++) {
      points[n++] = ZH[i];
    }
    for (int i = 0; i < UH.size(); i++) {
      points[n++] = UH[i];
    }
  }
}

void grahamScan() {
  convexHull.clear();
  convexHull.push_back(0);
  convexHull.push_back(1);
  convexHull.push_back(2);

  for (int i = 3; i < n; i++) {
    int k = convexHull.size() - 1;
    while (k > 0 &&
           area(points[convexHull[k]], points[convexHull[k - 1]], points[i]) >
               0) {
      convexHull.pop_back();
      k = convexHull.size() - 1;
    }

    convexHull.push_back(i);
  }

  int pos = convexHull.size() - 1;
  if (area(points[convexHull[pos]], points[convexHull[pos - 1]],
           points[convexHull[0]]) > 0) {
    convexHull.pop_back();
  }

  convexHull.push_back(convexHull[0]);
}

bool compare(Point sp1, Point sp2) {
  int a = area(pl, sp1, sp2);
  if (a > 0) {
    return true;
  } else if (a == 0) {
    int d1 = (sp1.x - pl.x) * (sp1.x - pl.x) + (sp1.y - pl.y) * (sp1.y - pl.y);
    int d2 = (sp2.x - pl.x) * (sp2.x - pl.x) + (sp2.y - pl.y) * (sp2.y - pl.y);
    a = area(pl, sp1, pr);

    if (a < 0) {
      if (d1 < d2) {
        return false;
      } else {
        return true;
      }
    } else {
      if (d1 < d2) {
        return true;
      } else {
        return false;
      }
    }
  } else {
    return false;
  }
}

int area(Point a, Point b, Point c) {
  return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}