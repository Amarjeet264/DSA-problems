class Solution {
    int dist(int n, int limit, int cnt) {
        if(n<0||cnt>3)return 0;
        if (n == 0) {
            if (cnt <= 3) {
                return 1;
            }
            return 0;
        }
        int ways = 0;
        for (int k = 0; k <= limit; k++) {
            ways += dist(n - k, limit, cnt + 1);
        }
        return ways;
    }

public:
    int distributeCandies(int n, int limit) {
        return dist(n, limit, 0);
    }
};