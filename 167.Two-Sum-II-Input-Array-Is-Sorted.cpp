class Solution {
public:
    int binarySearch(int start, int target, vector<int>&nums){
        int l = start, r = nums.size() - 1;
        while(l <= r){
            int mid = l + (r - l)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> ans(2);
        for(int i = 0; i < nums.size() - 1; i++){
            int other = binarySearch(i + 1, target - nums[i], nums);
            if(other != -1){
                ans[0] = i + 1;
                ans[1] = other + 1;
                break;
            }
        }
        return ans;
    }
};