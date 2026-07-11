//Implement pow(x, n), which calculates x raised to the power n (i.e., x^xn).

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


//2nd logic:
/*
class Solution {
public:
    double myPow(double x, int n) {
        long long power = n;
        double ans = 1.0;
        if(power < 0){
            x = 1 / x;
            power = -power;
        }
        while(power > 0)
        {
            if(power % 2 == 1)
                ans *= x;
            x *= x;
            power /= 2;
        }
        return ans;
    }
};
*/