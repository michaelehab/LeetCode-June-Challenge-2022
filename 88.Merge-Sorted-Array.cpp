class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector <int> tmp_nums1 = nums1;
        int i = 0, j = 0, k = 0;
        while(k < m + n){
            if(i == m){
                while(j < n){
                    nums1[k++] = nums2[j++];
                }
            }
            else if(j == n){
                while(i < m){
                    nums1[k++] = tmp_nums1[i++];
                }
            }
            else if(tmp_nums1[i] < nums2[j]){
                nums1[k++] = tmp_nums1[i++];
            }
            else if(tmp_nums1[i] > nums2[j]){
                nums1[k++] = nums2[j++];
            }
            else{
                nums1[k++] = tmp_nums1[i++];
                nums1[k++] = nums2[j++];
            }
        }
    }
};