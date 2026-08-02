/*
Approach:
gas=[1,2,4,5,9]  cost=[3,4,1,10,1]
(amount of gas available at station i),   (cost involved in each gas station to reach next station)

- you have to determine a starting position then move in a loop
- if loop possible  -> return the index of starting position
- if not then return -1
- also if total cost is greater than total gas available then return -1 because it is not possible to complete the loop (totalGas < totalCost) -> not possible
- BRUTE FORCE: as soon you see -ve, stop there and again try the car from any other starting index
- EFFICIENT: iterate over each index and try to start from there (gas - cost = availabe(+ve))

*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
        int totalGas = 0;
        int totalCost = 0;
        for(int i=0;i<gas.size();i++){
            totalGas += gas[i];
            totalCost += cost[i];
        }
        if(totalGas < totalCost)
            return -1;
        int start = 0;
        int tank = 0;
        for(int i=0;i<gas.size();i++){
            tank += gas[i] - cost[i];
            if(tank < 0){
                start = i + 1;
                tank = 0;
            }
        }
        return start;
    }
};