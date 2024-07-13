class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        // Pair each robot's position with its index and sort by positions
        vector<pair<int, int>> robots;
        int n = positions.size();
        for (int i = 0; i < n; ++i) {
            robots.push_back({positions[i], i});
        }
        sort(robots.begin(), robots.end());
        
        stack<int> stk; // Stack to store indices of robots
        for (int i = 0; i < n; ++i) {
            int idx = robots[i].second;
            char dir = directions[idx];
            
            // Resolve collisions
            while (!stk.empty() && directions[stk.top()] == 'R' && dir == 'L') {
                int topIdx = stk.top();
                if (healths[topIdx] == healths[idx]) {
                    // Both robots destroy each other
                    healths[topIdx] = 0;
                    healths[idx] = 0;
                    stk.pop();
                    break;
                } else if (healths[topIdx] > healths[idx]) {
                    // The robot on the stack wins
                    healths[topIdx] -= 1;
                    healths[idx] = 0;
                    break;
                } else {
                    // The current robot wins
                    healths[idx] -= 1;
                    healths[topIdx] = 0;
                    stk.pop();
                }
            }
            
            if (healths[idx] > 0) {
                stk.push(idx); // Push the index of the current robot
            }
        }
        
        vector<int> survivedHealths;
        for (int i = 0; i < n; ++i) {
            if (healths[i] > 0) {
                survivedHealths.push_back(healths[i]);
            }
        }
        
        return survivedHealths;
    }
};
