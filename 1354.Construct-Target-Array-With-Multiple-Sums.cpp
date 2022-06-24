class Solution {
public:
    bool isPossible(vector<int>& target) {
        if(target.size() == 1) return target[0] == 1;
        priority_queue<int> max_heap;
        long long total = 0;
        for(const int& n : target){
            max_heap.push(n);
            total += n;
        }
        while(max_heap.top() > 1){
            int prev_val = max_heap.top() % (total - max_heap.top());
            if(!prev_val){
                if(total - max_heap.top() == 1) return true;
                else return false;
            }
            if(prev_val == max_heap.top()) return false;
            
            total -= (max_heap.top() - prev_val);
            max_heap.pop();
            max_heap.push(prev_val);
        }
        return true;
    }
};