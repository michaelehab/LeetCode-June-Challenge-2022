class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int i = cardPoints.size() - k, j = cardPoints.size() - 1;
        int sum = accumulate(cardPoints.begin() + i, cardPoints.end(), 0);
        int ans = sum;
        while(j != k - 1){
            sum -= cardPoints[i];
            i = (i + 1) % cardPoints.size();
            j = (j + 1) % cardPoints.size();
            sum += cardPoints[j];
            ans = max(ans, sum);
        }
        return ans;
    }
};