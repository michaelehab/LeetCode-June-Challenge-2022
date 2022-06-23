class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](vector<int> a, vector<int> b){
            return a[1] < b[1];
        });
        priority_queue<int> durations;
        int time = 0;
        for(auto i : courses){
            if(time + i[0] <= i[1]){
                durations.push(i[0]);
                time += i[0];
            }
            else if(!durations.empty() && durations.top() > i[0]){
                time -= (durations.top() - i[0]);
                durations.pop();
                durations.push(i[0]);
            }
        }
        return durations.size();
    }
};