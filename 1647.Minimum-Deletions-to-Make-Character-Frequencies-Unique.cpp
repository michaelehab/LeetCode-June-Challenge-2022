class Solution {
public:
    int minDeletions(string s) {
        int deletions = 0;
        unordered_map <char, int> freq;
        for(const char& c : s) freq[c]++;
        priority_queue<int> max_heap;
        for(auto i : freq) max_heap.push(i.second);
        while(!max_heap.empty()){
            int top1 = max_heap.top();
            max_heap.pop();
            if(top1 && !max_heap.empty() && top1 == max_heap.top()){
                max_heap.push(top1 - 1);
                deletions++;
            }
        }
        return deletions;
    }
};