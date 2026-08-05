/*
                    The Automated Package Delivery Drone
A logistics company uses an automated drone to deliver N packages. The weights of the packages are given in an array weights.
The packages must be shipped in the exact sequential order given in the array—you cannot reorder them!The drone has a maximum 
weight capacity C per trip. Each day, the drone makes one trip loaded with as many packages as possible without exceeding 
capacity C.Given that you have D days to deliver all packages, find the least weight capacity C of the drone such that 
all packages are delivered within D days.
Input Format:
An array of integers weights.An integer D (number of days).

Example:
Input: weights = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], D = 5
Output: 15

Explanation:
A drone capacity of 15 allows packages to be shipped in 5 days as follows:
- Day 1: 1, 2, 3, 4, 5 (Total weight = 15)
- Day 2: 6, 7 (Total weight = 13)
- Day 3: 8 (Total weight = 8)
- Day 4: 9 (Total weight = 9)
- Day 5: 10 (Total weight = 10)

If capacity was 14, it would take more than 5 days. Minimum valid capacity is 15.

Constraints:
1 <= D <= weights.length <= 5 * 10^4
1 <= weights[i] <= 500
Time Complexity: O(N log (summation (weights)))

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Function to check if a given capacity is enough
bool isPossible(vector<int> &weights, int D, int capacity){
    int days = 1;          // Start with Day 1
    int currentWeight = 0; // Current load on the drone

    for (int weight : weights){
        // If adding this package exceeds the capacity,
        // send the current drone and start the next day.
        if (currentWeight + weight > capacity){
            days++;
            currentWeight = weight;
        }
        else{
            currentWeight += weight;
        }
    }
    return days <= D;
}

int leastCapacity(vector<int> &weights, int D){
    // Minimum possible capacity
    int low = *max_element(weights.begin(), weights.end());

    // Maximum possible capacity
    int high = accumulate(weights.begin(), weights.end(), 0);
    int answer = high;
    while (low <= high){
        int mid = low + (high - low) / 2;
        if (isPossible(weights, D, mid)){
            answer = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return answer;
}

int main()
{
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int D = 5;
    cout << leastCapacity(weights, D);
    return 0;
}

/*
        ANOTHER SYNTAX
class Solution {
public:

    bool isPossible(vector<int>& weights, int days, int capacity)
    {
        int currentWeight = 0;
        int requiredDays = 1;

        for(int weight : weights)
        {
            if(currentWeight + weight > capacity)
            {
                requiredDays++;
                currentWeight = weight;
            }
            else
            {
                currentWeight += weight;
            }
        }

        return requiredDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days)
    {
        int low = *max_element(weights.begin(), weights.end());

        int high = accumulate(weights.begin(), weights.end(), 0);

        int ans = high;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(isPossible(weights, days, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};

*/