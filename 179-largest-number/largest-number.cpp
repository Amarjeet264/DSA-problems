class Solution {
    static bool comp(int x, int y) {
        string xs = to_string(x);
        string ys = to_string(y);
        return xs + ys > ys + xs; // Compare concatenated results
    }

public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp); // Sort based on custom comparator
        
        // If the largest number is '0', the result is "0"
        if (nums[0] == 0) return "0";
        
        string result = "";
        for (int num : nums) {
            result += to_string(num);
        }
        
        return result;
    }
};
