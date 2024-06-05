class Solution {
public:
    string minWindow(string s, string t) {
      if (s.empty() || t.empty()) return "";
    
    
    unordered_map<char, int> tFreq;
    for (char c : t) {
        tFreq[c]++;
    }
    
    
    unordered_map<char, int> windowFreq;
    int left = 0, right = 0;
    int required = tFreq.size();
    int formed = 0;
    int minLen = INT_MAX;
    int minLeft = 0;
    
    while (right < s.size()) {
        
        char c = s[right];
        windowFreq[c]++;
        
        
        if (tFreq.find(c) != tFreq.end() && windowFreq[c] == tFreq[c]) {
            formed++;
        }
        
        
        while (left <= right && formed == required) {
            c = s[left];
            
            
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                minLeft = left;
            }
            
            
            windowFreq[c]--;
            if (tFreq.find(c) != tFreq.end() && windowFreq[c] < tFreq[c]) {
                formed--;
            }
            
            left++;
        }
        
        
        right++;
    }
    
    return (minLen == INT_MAX) ? "" : s.substr(minLeft, minLen);  
    }
};  