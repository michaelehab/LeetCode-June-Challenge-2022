// Time : O(n) - Space : O(n)
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans(nums.size());
        ans[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i)
            ans[i] = nums[i] + ans[i - 1];
        return ans;
    }
};

// Time : O(n) - Space : O(1)
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i = 1; i < nums.size(); ++i)
            nums[i] += nums[i - 1];
        return nums;
    }
};