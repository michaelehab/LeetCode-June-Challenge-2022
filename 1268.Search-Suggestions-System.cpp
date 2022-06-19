class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        sort(products.begin(), products.end());
        int l = 0, r = products.size() - 1;
        for(int i = 0; i < searchWord.length(); ++i){
            vector<string> suggestion;
            while(l <= r && products[l][i] != searchWord[i]) l++;
            while(r >= l && products[r][i] != searchWord[i]) r--;
            int num = 0, idx = l;
            while(num++ < 3 && idx <= r) suggestion.push_back(products[idx++]);
            ans.push_back(suggestion);
        }
        return ans;
    }
};