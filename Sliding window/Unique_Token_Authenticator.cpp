/*An API security gateway generates authentication token streams as lowercase string logs S. To ensure session security,
a valid authorization window must be a continuous substring of length $K$ that contains at most $U$ unique characters.
The engineering team wants to identify the total number of valid $K$-length windows in the token stream S that satisfy this
security condition.

Input Format:
A string S representing the token log stream.
An integer K representing the exact length of the window.
An integer U representing the maximum allowable unique characters in that window.

Example:
Input: S = "aabacbe", K = 4, U = 2
Output: 2

Explanation:
Windows of length K = 4 are:
1. "aaba" -> Unique chars: {'a', 'b'} = 2. (Valid! <= 2)
2. "abac" -> Unique chars: {'a', 'b', 'c'} = 3. (Invalid > 2)
3. "bacb" -> Unique chars: {'a', 'b', 'c'} = 3. (Invalid > 2)
4. "acbe" -> Unique chars: {'a', 'c', 'b', 'e'} = 4. (Invalid > 2)

Total valid windows = 2? Wait, let's re-check:
Window 1: "aaba" -> 'a':3, 'b':1 -> 2 unique <= 2. Count = 1.
Window 2: "abac" -> 3 unique.
Window 3: "bacb" -> 3 unique.
Window 4: "acbe" -> 4 unique.
So output is 1!


Constraints:
Expected time complexity: O(N)
Expected space complexity: O(U) using a Frequency MAp/Unordered Map or array

*/

#include <iostream>
using namespace std;

int main() {
    string S;
    cin>>S;
    int K;
    cin>>K;
    int U;
    cin>>U;
    int count=0;
    unordered_map<char,int>mp;
    for(int i=0; i<K; i++){
        mp[S[i]]++;
    }
    if(mp.size()<=U){
        count++;
    }
    //Now i have to slide the window
    //How to do that??
    int start=0;
    int end=K-1;
    //slide window
    while(end<S.length()-1){
        mp[S[start]]--;
        //kisi ki frequency 0 ho gyi toh usse remove kro window se
        if(mp[S[start]]==0){
            mp.erase(S[start]);
        }
        //move window
        start++;
        end++;
        //add new character
        mp[S[end]]++;
        //
        if(mp.size()<=U){
            count++;
        }
    }
    cout<<count;
    return 0;
}