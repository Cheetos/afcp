#include <cstdio>
#include <cmath>
#include <cstring>
#define MAX (1 << 19)
using namespace std;

class ComplexNumber {
 public:
  double a;
  double b;

  ComplexNumber(double a = 0.0, double b = 0.0) {
    this->a = a;
    this->b = b;
  }

  double SquareDiff() const {
    return a * a + b * b;
  }
  ComplexNumber bar() const { 
    return ComplexNumber(this->a, -this->b); 
  }
  ComplexNumber operator+(ComplexNumber b) const {
    return ComplexNumber(this->a + b.a, this->b + b.b);
  }
  ComplexNumber operator-(ComplexNumber b) const {
    return ComplexNumber(this->a - b.a, this->b - b.b);
  }
  ComplexNumber operator*(ComplexNumber b) const {
    return ComplexNumber(this->a * b.a - this->b * b.b,
                         this->a * b.b + this->b * b.a);
  }
  ComplexNumber operator/(ComplexNumber b) const {
    ComplexNumber r = ComplexNumber(this->a, this->b) * b.bar();
    return ComplexNumber(r.a / b.SquareDiff(), r.b / b.SquareDiff());
  }
};

const double two_pi = 4 * acos(0);
int n, m;
double C[MAX + 100];  // Cos array
double S[MAX + 100];  // Sin array
ComplexNumber a[MAX + 100], b[MAX + 100];
ComplexNumber A[MAX + 100], B[MAX + 100];
ComplexNumber P[MAX + 100], INV[MAX + 100];

/////////////////////////////////////////////////////

ComplexNumber angle(int dir, int k) { 
  return ComplexNumber(C[k], dir * S[k]); 
}

void FFT(ComplexNumber *in, ComplexNumber *out, int step, int size, int dir) {
  if (size < 1) {
    return;
  }

  if (size == 1) {
    out[0] = in[0];
    return;
  }

  FFT(in, out, step * 2, size / 2, dir);
  FFT(in + step, out + size / 2, step * 2, size / 2, dir);

  for (int i = 0; i < size / 2; i++) {
    ComplexNumber even = out[i];
    ComplexNumber odd = out[i + size / 2];
    out[i] = even + angle(dir, i * step) * odd;
    out[i + size / 2] = even - angle(dir, i * step) * odd;
  }
}

/////////////////////////////////////////////////////

int main() {
  int temp;

  scanf("%d %d", &n, &m);

  temp = 0;
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  for (int i = 0; i < n; i++) {
    scanf("%d", &temp);
    a[i] = temp;
  }

  for (int i = 0; i < m; i++) {
    scanf("%d", &temp);
    b[i] = temp;
  }

  // Generate Complex Numbers
  for (int i = 0; i <= MAX; i++) {
    C[i] = cos(two_pi * i / MAX);
    S[i] = sin(two_pi * i / MAX);
  }

  // Get the FFT of coefficientes a and b
  FFT(a, A, 1, MAX, 1);
  FFT(b, B, 1, MAX, 1);

  // Multiply FFT(a) * FFT(b)
  for (int i = 0; i < MAX; i++) {
    P[i] = A[i] * B[i];
  }

  // Calculate the FFT inverse of P
  FFT(P, INV, 1, MAX, -1);


  // Scale the coefficients
  for (int i = 0; i < MAX; i++) {
    INV[i] = INV[i] / MAX;
  }

  for (int i = 0; i < n + m - 1; i++) {
    printf("%.2lf ", INV[i].a);
  }
  printf("\n");

  return 0;
}