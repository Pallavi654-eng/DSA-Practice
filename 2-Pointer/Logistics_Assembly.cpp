/*Question:
You are in the final coding round of an e-commerce giant. The interviewer gives you a problem faced by their 
warehouse logistics management software.Packages arrive at a shipping bay with specific destination priority 
codes (integers). Due to an automated sorting error, the packages arrived completely jumbled. To put them onto 
delivery trucks, they must be paired up.A truck can carry exactly two packages. However, due to weight 
distribution limits, the absolute difference between the priority codes of the two paired packages must be 
exactly equal to a target value $P$.Because time is money, the warehouse manager wants to know how many unique 
pairs of packages can be formed from the current batch to fully utilize the trucks. Two pairs are considered 
unique if they consist of different priority code values, even if those values appear multiple times in the inventory.
Input Format
An array of integers priorities representing the priority codes of the incoming packages.
An integer P representing the exact target difference required for pairing.

Example:
Input: priorities = [1, 5, 3, 4, 2], P = 2
Output: 3

Explanation: 
The unique pairs with an absolute difference of 2 are:
1. (1, 3) -> |1 - 3| = 2
2. (5, 3) -> |5 - 3| = 2
3. (4, 2) -> |4 - 2| = 2
Total unique pairs = 3.

Expected time complexity: O(N log N)
*/

#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int diff;
    cin>>diff;
    sort(arr, arr+n);
    int left=0;
    int right=1;
    int count=0;
    while(right<n){
        int currentDiff=arr[right]-arr[left];
        if(currentDiff==diff){
            count++;
            //also have to move pointers
            left++;
            right++;
            //skip duplicates
            while(left<n && arr[left]==arr[left-1])
                left++;
            while(right<n && arr[right]==arr[right-1])
                right++;
                
        }
        else if(currentDiff<diff){
            right++;
        }else{
            left++;
            //ensure pointers don't overlap
            if(left==right)
            right++;
        }
    }
    cout<<count;
    
    return 0;
}

// if you will not sort -> you will be confused in pointers, kisko badhau kaise compare kru, use of while loop instead of for loop, 