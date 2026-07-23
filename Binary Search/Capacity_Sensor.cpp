/*
An IoT sensor network measures continuous data traffic on a server node over time. The traffic readings increase up to
a peak throughput point and then strictly decrease.
Due to a firmware glitch, the logged array of traffic numbers traffic has been split into multiple sub-logs, but we know
the array was originally strictly increasing up to a single peak element, and then strictly decreasing after it (a mountain-shaped array).
The infrastructure team needs to find the index of the peak traffic reading to diagnose the time of maximum load.

Constraints & Challenge:
You must find the peak index in O(log N) time complexity.
You cannot simply loop through the array from start to finish O(N) will time out on hidden large test cases).

Input: traffic = [1, 3, 8, 12, 4, 2]
Output: 3

Explanation: 
- traffic[3] = 12 is the peak element.
- To the left: 1 < 3 < 8 < 12 (strictly increasing).
- To the right: 12 > 4 > 2 (strictly decreasing).
*/

#include <iostream>
using namespace std;

int main() {
    // Write C++ code here
    int n;
    cin>>n;
    vector<int>traffic(n);
    for(int i=0; i<traffic.size(); i++){
        cin>>traffic[i];
    }
    int low=0;
    int high=n-1;
    while(low<high){
        int mid=low+(high-low)/2;
        if(traffic[mid]<traffic[mid+1]){
            low=mid+1;
        }else{
            high=mid;
        }
    }
    cout<<low;
    return 0;
}