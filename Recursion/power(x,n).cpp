#include <iostream>
using namespace std;

// Recursive function
double power(double x, long long n) {

    // Base Case
    if (n == 0)
        return 1;
    double half = power(x, n / 2);

    // If exponent is even
    if (n % 2 == 0)
        return half * half;

    // If exponent is odd
    return x * half * half;
}

int main() {
    double x;
    int n;
    cout << "Enter base (x): ";
    cin >> x;
    cout << "Enter exponent (n): ";
    cin >> n;
    long long N = n;
    // Handle negative powers
    if (N < 0) {
        x = 1 / x;
        N = -N;
    }

    cout << "Answer = " << power(x, N);
    return 0;
}