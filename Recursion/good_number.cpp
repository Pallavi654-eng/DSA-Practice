/*Question : Count good number:
LEETCODE: 1922. Count Good Numbers
A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).
"2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime
*/

class Solution {
public:
    long long MOD = 1e9 + 7;

    // Fast Binary Exponentiation
    long long power(long long x, long long n) {

        if (n == 0)
            return 1;

        long long half = power(x, n / 2);
        long long ans = (half * half) % MOD;

        if (n % 2 == 1)
            ans = (ans * x) % MOD;
        return ans;
    }

    /* Formula: 5^even × 4^odd */
    int countGoodNumbers(long long n) {

        long long even = (n + 1) / 2;
        long long odd = n / 2;

        return (power(5, even) * power(4, odd)) % MOD;
    }
};