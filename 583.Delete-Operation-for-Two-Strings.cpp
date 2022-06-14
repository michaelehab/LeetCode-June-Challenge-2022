class Solution {
public:
    int minDistance(string word1, string word2) {
        int w1 = word1.length();
        int w2 = word2.length();
        
        vector<vector<int>> dp(w2 + 1, vector<int>(w1 + 1));
        
        for(int i = 0; i <= w1; i++) dp[0][i] = i;
        for(int i = 0; i <= w2; i++) dp[i][0] = i;
        
        for(int i = 1; i <= w2; i++){
            for(int j = 1; j <= w1; j++){
                if(word1[j - 1] == word2[i - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }
        
        return dp[w2][w1];
    }
};