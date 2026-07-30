/*In a automated fulfillment warehouse, a collection of logistics robots move along a narrow 1D automated rail line. 
You are given an array positions representing the starting coordinates of $N$ robots and an array directions representing
their movement direction (1 for moving Right, -1 for moving Left).All robots move at the exact same constant speed.
When two robots collide:
The robot with the smaller mass (given in a third array masses) is destroyed and removed from the rail line.
If two colliding robots have equal mass, BOTH robots are destroyed!
Robots moving in the same direction or away from each other never collide.

Return a list of the remaining surviving robots' masses in the order they were originally placed on the rail line.

Input Format:
An array of integers positions.
An integer array masses.
An integer array directions (contains only 1 or -1).

Example:
Input: 
positions  = [3, 5, 8]
masses     = [10, 20, 15]
directions = [1, -1, 1]   (Robot 0 goes Right, Robot 1 goes Left, Robot 2 goes Right)

Output: [20, 15]

Explanation:
- Robot 0 (pos 3, mass 10, going Right) and Robot 1 (pos 5, mass 20, going Left) move toward each other.
- They collide at position 4. Robot 1 has greater mass (20 > 10), so Robot 0 is destroyed!
- Robot 1 (mass 20, moving Left) keeps going Left.
- Robot 2 (pos 8, mass 15, moving Right) moves away from Robot 1 (which is at pos 4 and moving Left).
- They never collide!
- Remaining surviving masses: [20, 15].


Expected Time Complexity: O(N log N) (or O(N) if already sorted by position).
Both of these directly test your mastery over Sliding Window + Frequency Maps and Stack-based Collision Management!

*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct Robot
{
    int position;
    int mass;
    int direction;   // 1 = Right, -1 = Left
    int index;       // Original index
    bool alive = true;
};

int main() {
    int n;
    cin >> n;
    vector<Robot> robots(n);

    // Input positions
    for(int i = 0; i < n; i++){
        cin >> robots[i].position;
    }
    // Input masses
    for(int i = 0; i < n; i++){
        cin >> robots[i].mass;
    }
    // Input directions
    for(int i = 0; i < n; i++){
        cin >> robots[i].direction;
        robots[i].index = i;
    }
    // Sort according to position
    sort(robots.begin(), robots.end(),[](Robot &a, Robot &b){
            return a.position < b.position;
        });
    stack<int> st;   // Stores indices of robots vector

    for(int i = 0; i < n; i++){
        // Moving Right → just push
        if(robots[i].direction == 1){
            st.push(i);
        }
        else{
            // Moving Left
            while(!st.empty() &&
                robots[st.top()].direction == 1 &&
                robots[i].alive){

                // Right robot is stronger
                if(robots[st.top()].mass > robots[i].mass){
                    robots[i].alive = false;
                }

                // Left robot is stronger
                else if(robots[st.top()].mass < robots[i].mass)
                {
                    robots[st.top()].alive = false;
                    st.pop();
                }

                // Equal masses
                else
                {
                    robots[st.top()].alive = false;
                    robots[i].alive = false;
                    st.pop();
                }
            }
        }
    }

    // Sort back to original order
    sort(robots.begin(), robots.end(),[](Robot &a, Robot &b){
            return a.index < b.index;
        });

    // Print surviving masses
    for(auto robot : robots)
    {
        if(robot.alive)
        {
            cout << robot.mass << " ";
        }
    }
    
    
    return 0;
}