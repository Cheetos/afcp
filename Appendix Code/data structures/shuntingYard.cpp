#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
  int i, j, n, m;
  char car;
  string str;
  stack<char> S;

  while (getline(cin, str) && str.length() > 0) {
    car = str[0];
    if (car >= '0' && car <= '9') {
      cout << car; // is digit, print it
    } else {
      if (S.size() == 0) {
        S.push(car);
      } else {
        if (car == ')') {
          // Pop everything until left parenthesis appear
          while (S.top() != '(') {
            cout << S.top();
            S.pop();
          }
          S.pop(); // pop the left parenthesis
        } else if (car == '(') {
          S.push(car); // left parenthesis - add to stack
        } else {
          while (!S.empty()) {
            // Stop pop if left parenthesis appear
            if (S.top() == '(') {
              break;
            }
            if (car == '+' || car == '-') {
              cout << S.top(); // Continue printing the top element
            } else if (car == '*' || car == '/') {
              if (S.top() == '*' || S.top() == '/') {
                cout << S.top(); // Print operator if priority is the same
              } else {
                break; // Stop if priority is lower
              }
            }
            S.pop();
          }
          // Add the operator into the stack
          S.push(car);
        }
      }
    }
  }

  // Print remaining elements in the stack
  while (!S.empty()) {
    cout << S.top();
    S.pop();
  }
  cout << "\n";

  return 0;
}