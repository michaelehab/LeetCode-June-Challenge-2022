// Normal Sorting O(nlogn)
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int moves = 0;
        for(const int& n : nums) moves += abs(n - nums[nums.size() / 2]);
        return moves;
    }
};

// But I only care about the median so using nth_element makes it O(n)
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + (nums.size() / 2), nums.end());
        int moves = 0;
        for(const int& n : nums) moves += abs(n - nums[nums.size() / 2]);
        return moves;
    }
};