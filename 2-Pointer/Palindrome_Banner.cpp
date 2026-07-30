/*Question:
An e-commerce app displays promotional coupon codes on its home banner. Marketing wants every coupon code string S to be
a palindrome (reads the same forward and backward).
To save development cost, the team decided on a simple rule: You are allowed to delete at most ONE character from anywhere in the string S to see if it can become a valid palindrome.
Write a program that returns true if S can be made a palindrome after deleting at most one character, and false otherwise.

Time Complexity: O(N)
Space Complexity: O(1)

Input:
Example 1:
Input: S = "radcar"
Output: true
Explanation: Delete 'c' at index 3 to get "radar", which is a valid palindrome.

Example 2:
Input: S = "abcdef"
Output: false
Explanation: Deleting any single character will not make it a palindrome.
*/

// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

bool isPalindrome(string &S, int left, int right){
    while(left < right){
        if(S[left] != S[right])
            return false;
        left++;
        right--;
    }
    return true;
}
int main() {
    // Write C++ code here
    string S;
    cin>>S;
    int left=0;
    int N=S.length();
    int right=N-1;
    while(left<=right){
        if(S[left]==S[right]){
            left++;
            right--;
        }else{
            //delete the character
            if(isPalindrome(S, left + 1, right) ||isPalindrome(S, left, right - 1)){
                cout << "true";
            }
            else{
                cout << "false";
            }
            return 0;
        }
    }
    cout<<"true";
    return 0;
    
}