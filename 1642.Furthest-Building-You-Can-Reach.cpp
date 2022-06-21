class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        priority_queue<int> bricksHeights;
        int i = 0;
        while(i < h.size() - 1){
            if(h[i] < h[i + 1]){
                int diff = h[i + 1] - h[i];
                if(bricks >= diff){
                    bricks -= diff;
                    bricksHeights.push(diff);
                }
                else{
                    if(!bricksHeights.empty() && bricksHeights.top() > diff && ladders){
                        ladders--;
                        bricks += (bricksHeights.top() - diff);
                        bricksHeights.pop();
                        bricksHeights.push(diff);
                    }
                    else if(ladders) ladders--;
                    else break;
                }
            }
            i++;
        }
        return i;
    }
};