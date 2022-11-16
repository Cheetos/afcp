#include <bits/stdc++.h>
using namespace std;

enum STATE { OUTSIDE, BORDER, INSIDE };

typedef struct stPoint {
  int x;
  int y;
  stPoint(int x = 0, int y = 0) {
    this->x = x;
    this->y = y;
  }
} Point;

typedef struct stLine {
  Point A;
  Point B;
  stLine(int x1, int y1, int x2, int y2) {
    A = Point(x1, y1);
    B = Point(x2, y2);
  }
} Line;

int n;
vector<Line> lines = {Line(1, 1, 2, 3),  Line(2, 3, 4, 3),  Line(4, 3, 2, 7),
                      Line(2, 7, 4, 9),  Line(4, 9, 6, 5),  Line(6, 5, 8, 8),
                      Line(8, 8, 10, 8), Line(10, 8, 9, 3), Line(9, 3, 10, 1),
                      Line(10, 1, 7, 1), Line(7, 1, 6, 4),  Line(6, 4, 4, 1),
                      Line(4, 1, 1, 1)};

STATE isInsidePolygon(Point);
int area(Point, Point, Point);
int main() {
  int k, aux, c;
  Point p;

  for (int i = 0; i < lines.size(); i++) {
    if (lines[i].A.x > lines[i].B.x) {
      swap(lines[i].A, lines[i].B);
    }
  }

  cout << isInsidePolygon(Point(3, 2)) << "\n";  // 2 - INSIDE
  cout << isInsidePolygon(Point(3, 4)) << "\n";  // 0 - OUTSIDE
  cout << isInsidePolygon(Point(3, 5)) << "\n";  // 1 - BORDER

  return 0;
}

STATE isInsidePolygon(Point p) {
  int nLinesCrossed = 0;
  for (int i = 0; i < lines.size(); i++) {
    if (p.x >= lines[i].A.x && p.x < lines[i].B.x) {
      int triangleArea = area(lines[i].A, lines[i].B, p);
      if (triangleArea > 0) {
        nLinesCrossed++;
      } else if (triangleArea == 0) {
        return BORDER;
      }
    }
  }

  if (nLinesCrossed % 2 == 0) {
    return OUTSIDE;
  }

  return INSIDE;
}

int area(Point a, Point b, Point c) {
  return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}