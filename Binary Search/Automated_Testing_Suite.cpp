/*Question:             HARD
A software testing suite runs N test cases sequentially. The time taken by the i-th test case is given in an array 
timeRequired. You have K parallel testing workers available.Because the test cases must be executed in the exact sequential 
order they are defined to maintain state dependencies, you must divide the array into K continuous subarrays. Each worker is 
assigned exactly one continuous block of test cases.The total time to complete the entire suite is determined by the worker 
who takes the longest time to finish their assigned block. Your goal is to distribute the test cases such that the maximum 
total time taken by any single worker is minimized.

Input Format:
An array of integers timeRequired.
An integer K (number of workers).
Example:
Input: timeRequired = [1, 2, 3, 4, 5, 6, 7], K = 3
Output: 9

Explanation:
We can split the sequential tests into 3 continuous blocks:
Worker 1: [1, 2, 3] -> Total time = 6
Worker 2: [4, 5]    -> Total time = 9
Worker 3: [6, 7]    -> Total time = 13
Max time here is 13.

An optimal split is:
Worker 1: [1, 2, 3, 4] -> Total time = 10
Worker 2: [5, 6]       -> Total time = 11
Worker 3: [7]          -> Total time = 7
Max time here is 11.

Can we do better? Let's check a max time of 9:
Worker 1: [1, 2, 3] -> Total time = 6
Worker 2: [4, 5]    -> Total time = 9
Worker 3: [6]       -> Total time = 6 (Wait, we have 7 left, so this fails).

Let's look at another distribution:
Worker 1: [1, 2, 3, 4] -> 10
Worker 2: [5, 6] -> 11
Worker 3: [7] -> 7
Minimizing the maximum workload gives an optimal bottleneck of 9 if partitioned as:
[1, 2, 3, 4] -> 10? No.
Let's find the absolute minimum max:
If Max = 9: [1,2,3] (6), [4,5] (9), [6] (6) -> 7 is left over.
If Max = 9 is impossible, let's check the combination that yields 9:
Actually, for [1, 2, 3, 4, 5, 6, 7] with K=3:
Split: [1,2,3,4] (10), [5,6] (11), [7] (7) -> Max is 11.
Alternative Split: [1,2,3,4,5] (15) -> No.
Let's check if 9 is possible: No, because 6+7=13. The smallest last block is 7, but the block before it is 6, so [6,7] is 13. 
If separated, [6] and [7]. Then [1,2,3,4,5] must be done by 1 worker (15).
Therefore, the minimum possible maximum workload for this specific array is 11.

*/

// Make the largest worker load as small as possible.
// Trying every split takes millions of possible partitions
/* Wherever you see :
-> Minimize the maximum
-> Maximize the minimum
-> Split into K parts
-> Allocate K workers
-> Partition array
-> Continuous subarrays
            Think of Binary Search
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int>& timeRequired, int k, int maxTime){
    int workers =1;             //we already have first worker
    int currentSum=0;       //bcz current worker hasn't received any work
    for(int time : timeRequired){
        if(currentSum + time > maxTime){
            workers++;
            currentSum = time;
        } else {
            currentSum += time;
        }
    }
    return workers <= k;
}

int minimizeMAximumTime(vector<int>& timeRequired, int k){
    int low = *max_element(timeRequired.begin(), timeRequired.end());
    int high = accumulate(timeRequired.begin(), timeRequired.end(), 0);
    int answer = high;

    while(low <= high){
        int mid = low + (high - low) / 2;
        
        if(isPossible(timeRequired, k, mid)){
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return answer;
}

int main(){
    vector<int> timeRequired = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    int result = minimizeMAximumTime(timeRequired, k);
    cout << "The minimum possible maximum workload is: " << result << endl;
    return 0;
}

