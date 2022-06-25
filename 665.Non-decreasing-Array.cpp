class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool mod = false;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i - 1] > nums[i]){
                if(mod) return false;
                
                if(i == 1 || nums[i - 2] <= nums[i]) nums[i - 1] = nums[i];
                else nums[i] = nums[i - 1];
                
                mod = true;
            }
        }
        return true;
    }
};