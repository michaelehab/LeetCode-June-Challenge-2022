// Using Set
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
        int i = 0, j = 0, maxlen = 0;
        set <char> found;
        while(i < s.length()){
            while(found.find(s[i]) != found.end()) found.erase(s[j++]);
            found.insert(s[i++]);
            maxlen = max(maxlen, i - j);
        }
        return maxlen;
    }
};

// Using map
class Solution {
public:
    bool valid(map <char, int>& occ){
        for(auto& c : occ)
            if(c.second > 1) return false;
        return true;
    }
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
        int i = 0, j = 0, maxlen = 0;
        map <char, int> occ;
        while(j < s.length()){
            occ[s[j] - 'a']++;
            while(!valid(occ) && i < j) occ[s[i++] - 'a']--;
            maxlen = max(maxlen, j - i);
            j++;
        }
        return maxlen + 1;
    }
};