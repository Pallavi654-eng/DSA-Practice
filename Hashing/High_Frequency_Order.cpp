/*
An algorithmic trading desk processes buy and sell orders. Each order has a stock ticker symbol (a string).
To optimize order execution, the engine needs to reorder the incoming batch of stock ticker symbols such that tickers 
appearing most frequently are placed first. If two tickers have the exact same frequency, they must be ordered alphabetically (lexicographically).
Return the reordered list of stock ticker symbols according to this priority.

Input Format:
An array of strings tickers.

Example:
Input: tickers = ["AAPL", "GOOG", "AAPL", "MSFT", "GOOG", "AAPL", "TSLA"]
Output: ["AAPL", "AAPL", "AAPL", "GOOG", "GOOG", "MSFT", "TSLA"]

Explanation:
Counts:
- "AAPL": 3
- "GOOG": 2
- "MSFT": 1
- "TSLA": 1

"AAPL" has highest frequency (3).
"GOOG" has frequency 2.
"MSFT" and "TSLA" both have frequency 1 -> "MSFT" comes before "TSLA" alphabetically.

Constraints:
1<= tickers.length <= 10^5
Each ticker is a string of uppercase letters.
Time Complexity: O(N log N) or O(N log K) where K is the number of unique tickers.


*/

#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<string> tickers(n);
    for(int i=0; i<n; i++){
        cin>>tickers[i];
    }

    //frequency count
    unordered_map <string, int> freq;
    for(int i=0; i<n; i++){
        freq[tickers[i]]++;
    }

    sort(tickers.begin(), tickers.end(), [&](string a, string b){
        if(freq[a]==freq[b]) return a<b;
        return freq[a]>freq[b];
    });

    for(int i=0; i<n; i++){
        cout<<tickers[i]<<" ";
    }
}