/*Question: 
You are interviewing with a cloud infrastructure company. The team is designing an energy-saving algorithm for a green data 
center.The data center has N servers lined up in a row. Each server has a specific power consumption level per hour when 
active, given in an array power. The company has set a strict maximum daily total energy budget $B$ for a specific cluster.
To meet this budget, you must choose a uniform power cap X. If a server's original power consumption is greater than X, 
its power usage is safely scaled down to exactly X. If its consumption is already less than or equal to X, it runs normally
at its original power level.Your goal is to find the maximum possible integer value for the power cap X such that the total 
power consumed by all $N$ servers combined does not exceed the budget B. If even setting X = 0 exceeds the budget, return 0. 
If the budget is so large that no cap is needed at all, return the maximum element in the array.
Input Format
An array of integers power representing the hourly consumption of each server.
An integer B representing the total energy budget.
Input: power = [4, 9, 3, 2, 8], B = 22
Output: 5

Explanation:
If we choose a power cap X = 5:
- Server 0 (4) -> stays 4 (since 4 <= 5)
- Server 1 (9) -> capped to 5
- Server 2 (3) -> stays 3
- Server 3 (2) -> stays 2
- Server 4 (8) -> capped to 5
Total sum = 4 + 5 + 3 + 2 + 5 = 19. (19 <= 22, valid!)
If we try X = 6:
Total sum = 4 + 6 + 3 + 2 + 6 = 21. (21 <= 22, valid!)
If we try X = 7:
Total sum = 4 + 7 + 3 + 2 + 7 = 23. (23 > 22, invalid!)

The maximum integer cap that keeps us under or equal to 22 is 5 (wait, 21 is <= 22, so X = 6 works! Let's check X=6 
again: 4+6+3+2+6 = 21. Yes! X = 6 is valid. X = 7 gives 23, which is invalid. So the max cap is 6).

Expected time complexity: O(N log M), where M is the maximum value in the power array.
*/

//BRUTE-FORCE
// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[n];
    int maximum=0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(arr[i]>maximum){
            maximum=arr[i];
        }
    }
    int B;
    cin>>B;
    int answer=0;
    for(int X=0; X<=maximum; X++){
        int sum=0;
        for(int i=0; i<n; i++){
            if(arr[i]>X){
                sum+=X;
            }else{
                sum+=arr[i];
            }
        }
        if(sum<=B){
            answer=X;
        }
    }
    cout<<answer;
    return 0;
}

//Time complexity: O(N * maximum_element)

//OPTIMAL CODE

// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[n];
    int maximum=0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(arr[i]>maximum){
            maximum=arr[i];
        }
    }
    int B;
    cin>>B;
    int low=0;
    int high=maximum;
    int answer=0;
    while(low<=high){
        int mid=low+(high-low)/2;
        int sum =0;
        // calculate sum
        for(int i=0; i<n; i++){
            if(arr[i]>mid){
                sum+=mid;
            }
            else{
                sum+=arr[i];
            }
        }
        if(sum<=B){
            answer=mid;
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    
    cout<<answer;
    return 0;
}

// Time complexity: O(n * log(maximum_element))