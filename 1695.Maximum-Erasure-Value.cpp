// Using set
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i = 0, j = 0, curr = 0, ans = 0;
        set <int> found;
        while(j < nums.size()){
            while(!found.insert(nums[j]).second){
                curr -= nums[i];
                found.erase(nums[i++]);
            }
            curr += nums[j++];
            ans = max(ans, curr);
        }
        return ans;
    }
};

// Using hash set
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i = 0, j = 0, curr = 0, ans = 0;
        unordered_set <int> found;
        while(j < nums.size()){
            while(found.find(nums[j]) != found.end()){
                curr -= nums[i];
                found.erase(nums[i++]);
            }
            found.insert(nums[j]);
            curr += nums[j++];
            ans = max(ans, curr);
        }
        return ans;
    }
};