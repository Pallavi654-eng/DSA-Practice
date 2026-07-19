/*Question:
The ScenarioYou are interviewing for a software engineering role at a high-speed video streaming platform. 
The interviewer hands you a problem based on network packets.During live streams, video data is split into 
sequential packets. Each packet has a certain data weight (load) measured in megabytes. Due to network jitter,
some packets might experience heavy delays, causing buffering.To prevent buffering, your team wants to deploy
a "Smooth-Stream" cache buffer. This buffer can dynamically look at a continuous window of $K$ packets. 
To optimize memory consumption while keeping the stream smooth, the buffer needs to find a continuous 
segment of exactly $K$ packets where the difference between the maximum packet size and the minimum packet 
size is strictly less than or equal to a threshold $T$.Your task is to find the maximum possible data 
throughput (the total sum of packet sizes) of any valid window of size $K$. If no such window exists that 
satisfies the threshold condition, return -1.Input FormatAn array of integers packets representing the sizes 
of the sequential data packets.An integer K representing the exact window size of the cache buffer.
An integer T representing the maximum allowable difference between the largest and smallest packet in the window.

Input: packets = [4, 2, 3, 7, 8, 6, 5], K = 3, T = 2
Output: 19

Explanation: 
Continuous windows of size 3 are:
- [4, 2, 3] -> Max = 4, Min = 2. Diff = 2 (<= 2). Sum = 9
- [2, 3, 7] -> Max = 7, Min = 2. Diff = 5 (> 2). Invalid.
- [3, 7, 8] -> Max = 8, Min = 3. Diff = 5 (> 2). Invalid.
- [7, 8, 6] -> Max = 8, Min = 6. Diff = 2 (<= 2). Sum = 21
- [8, 6, 5] -> Max = 8, Min = 5. Diff = 3 (> 2). Invalid.

Wait, let's re-verify [7, 8, 6]: Max = 8, Min = 6, Diff = 2. Sum = 21. 
The maximum sum among all valid windows is 21.

*/

// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    // Write C++ code here
    int n;
    cin>>n;
    int packets[n];
    for(int i=0; i<n; i++){
        cin>>packets[i];
    }
    int K,T;
    cin>>K>>T;
    int start=0;
    int end=K-1;
    int answer=-1;
    while(end<n){
        int diff;
        int largest=packets[start];
        int smallest=packets[start];
        int sum=0;
        for(int i=start; i<=end; i++){
            if(packets[i]>largest){
                largest = packets[i];
            }
            if(packets[i]<smallest){
                smallest = packets[i];
            }
            sum+=packets[i];
        }
        diff=largest-smallest;
        if(diff<=T){
            if(answer==-1 || sum>answer){
                answer=sum;
            } 
        }
        // slide window
        start++;
        end++;
    }
   cout<<answer;
    return 0;
}