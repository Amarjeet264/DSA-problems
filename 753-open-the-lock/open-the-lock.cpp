class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<string> q;
        q.push("0000");
        visited.insert("0000");
        if (dead.count("0000")) return -1; // Special case: "0000" is a dead end
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string curr = q.front(); q.pop();
                if (curr == target) return steps;
                // Generate neighbors of curr by rotating each digit up or down
                for (int i = 0; i < 4; ++i) {
                    for (int j = -1; j <= 1; j += 2) {
                        string next = curr;
                        next[i] = (next[i] - '0' + j + 10) % 10 + '0';
                        if (!visited.count(next) && !dead.count(next)) {
                            q.push(next);
                            visited.insert(next);
                        }
                    }
                }
            }
            ++steps;
        }
        return -1; // Target not reachable
    }
};
