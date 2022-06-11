class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = 0;
        for(const int& n : nums) total += n;

		if(total < x) return -1;
		if(total == x) return nums.size();

		int target = total - x, sum = 0, start = 0, mx = 0;
		for(int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			while(sum > target) sum -= nums[start++];
			if(sum == target) mx = max(mx, i - start + 1);
		}

		return (mx) ? (nums.size() - mx) : (-1);
    }
};