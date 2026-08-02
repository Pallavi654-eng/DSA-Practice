/*
                        TOUGH - TOUGH   
You are in a coding round for a cloud security infrastructure team.An API gateway handles incoming requests arriving at
specific timestamps given in a sorted array timestamps. You are given an integer K, representing the maximum number of
new monitoring checkpoints you are allowed to add, and an integer budget constraint.To ensure even log coverage across traffic 
spikes, you want to place up to K new checkpoints anywhere between existing timestamps (at non-integer or integer positions)
such that the maximum distance between any two adjacent checkpoints (or existing timestamps) is minimized.Return the minimum
possible maximum gap between adjacent checkpoints. Your answer will be accepted if it is within 10^{-5} of the actual value.

Example:
Input: timestamps = [1, 13, 17, 23], K = 5
Output: 3.00000

Explanation:
Original gaps are:
- Between 1 and 13: gap = 12
- Between 13 and 17: gap = 4
- Between 17 and 23: gap = 6

If we add K = 5 new checkpoints:
- Place 3 checkpoints between 1 and 13 -> splits 12 into 4 equal segments of size 3.0 (at 4, 7, 10).
- Place 0 checkpoints between 13 and 17 -> gap is 4.0? Wait: if max gap is 3.0, gap 4 needs 1 checkpoint -> splits into two segments of 2.0.
- Place 1 checkpoint between 17 and 23 -> splits 6 into two segments of 3.0 (at 20).
Total checkpoints used: 3 + 1 + 1 = 5 checkpoints.
The maximum distance between adjacent nodes is now 3.0.

Expected Time Complexity: O(N log(max_gap))
*/

/*
Answer ko directly calculate nahi kar sakte
↓
Kisi guessed answer ko verify kar sakte hain.
↓
YES / NO mil raha hai.
↓
Binary Search on Answer.
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool possible(vector<int>& timestamps, int K, double mid){
    int used=0;
    for(int i=1; i<timestamps.size(); i++){
        double gap = timestamps[i]-timestamps[i-1];
        used += ceil(gap/mid)-1;
        if(used>K)return false;
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    vector<int> timestamps(n);
    for(int i=0; i<n; i++){
        cin>>timestamps[i];
    }
    int K;
    cin>>K;

    double low=0;
    double high=0;
    for(int i=1; i<n; i++){
        high = max(high, (double)(timestamps[i]-timestamps[i-1]));
    }
    while
    (high-low>1e-5){
        double mid = low+(high-low)/2;
        if(possible(timestamps, K, mid)){
            high=mid;
        }
        else{
            low=mid;
        }
    }
    cout<<fixed<<setprecision(5)<<high<<endl;
    return 0;
}

