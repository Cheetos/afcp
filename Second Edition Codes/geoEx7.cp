#include <bits/stdc++.h>
using namespace std;

class Circle {
    public:
    double x, y, r;
    
    Circle(double x = 0, double y = 0, double r = 0) {
        this->x = x;
        this->y = y;
        this->r = r;
    }
};

vector<Circle> circles;
vector<int> parentCircle;

int findCirclePath(vector<double> &);
void printCirclePath(int);
int main() {
	vector<double> radius = {3, 25, 35, 5, 4, 32, 4};
	int lastCircle = findCirclePath(radius);
	
	printCirclePath(lastCircle);
	cout << "\n";
	cout << "d = " << circles[lastCircle].x + circles[lastCircle].r << "\n";
	return 0;
}

int findCirclePath(vector<double> &radius) {
    int n = (int)radius.size();
    int lastCircle = 0;
    double maxBoxSize = 2.0 * radius[0];
    
    circles = vector<Circle>(n);
    parentCircle = vector<int>(n, -1);
    
    circles[0] = Circle(radius[0], radius[0], radius[0]);
    parentCircle[0] = -1;
    for (int i = 1; i < n; i++) {
        circles[i].x = circles[i - 1].x + 2.0 * sqrt(radius[i] * circles[i - 1].r);
        circles[i].y = radius[i];
        circles[i].r = radius[i];
        parentCircle[i] = i - 1;
        
        for (int j = i - 2; j >= 0; j--) {
            double deltaX2 = (circles[i].x - circles[j].x) * (circles[i].x - circles[j].x);
            double deltaY2 = (circles[i].y - circles[j].y) * (circles[i].y - circles[j].y);
            double d = sqrt(deltaX2 + deltaY2);
            
            if (d  < radius[i] + circles[j].r) {
                circles[i].x = circles[j].x + 2.0 * sqrt(radius[i] * circles[j].r);
                parentCircle[i] = j;
            }
        }
        
        if (circles[i].x - radius[i] < 0.0) {
            circles[i].x = radius[i];
            parentCircle[i] = -1;
        } 
        
        if (circles[i].x + radius[i] > maxBoxSize) {
            maxBoxSize = circles[i].x + radius[i];
            lastCircle = i;
        }
    }
    
    return lastCircle;
}

void printCirclePath(int k) {
    if (parentCircle[k] == -1) {
        cout << k;
        return;
    }
    printCirclePath(parentCircle[k]);
    cout << " - " << k; 
}
