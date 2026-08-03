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