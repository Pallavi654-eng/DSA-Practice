/*Question:
You are in a coding round for a remote collaboration tool engineering team. They are building a lightweight version control tracking system for text documents.
When a user edits a document, the system records the original string S and a modified string T. Due to a software patch rule, 
a modification is considered "Legitimate" if and only if the string T can be formed by inserting exactly one specific character
multiple times (zero or more times) into string S, right next to an existing match of that exact character.
In simpler terms, you need to check if T is a valid "expanded" version of S where some characters in S might have been typed 
or repeated extra times (like a sticky keyboard effect).

Return true if T is a legitimate edit of S, and false otherwise.
Input Format
A string S representing the original text.
A string T representing the edited text.

Example:
Input: S = "hello", T = "hheellloo"
Output: true
Explanation: 'h', 'e', 'l', and 'o' were repeated. No new unmatching characters were introduced, and the order is preserved.

Input: S = "exam", T = "exxame"
Output: false
Explanation: Even though 'x' was repeated legitimately, an extra 'e' was appended at the very end where there was no 'e' in 
the original sequence at that position.

Expected Time Complexity: O(S.length + T.length)
Expected Space Complexity: O(1)
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    // how to take input of strings
    string S, T;
    cin>>S>>T;
    int i=0;
    int j=0;
    // always have praactice to write 
    int n=S.length();
    int m=T.length();
    while(i<n && j<m){
        if(S[i]==T[j]){
            i++;
            j++;
        }else if(i>0 && T[j]==S[i-1]){
            j++;
        }
        // Invalid character
        else{
            cout<<"false";
            return 0;
        }
    }
    // If S should be completly matched
    if(i!=n){
        cout<<"false";
        return 0;
    }
    // Remaining characters in T must be repetition
    while(j<m){
        if(T[j] == S[n-1]){
            j++;
        }else{
            cout << "false";
            return 0;
        }
    }
    cout<<"true";
    return 0;
}