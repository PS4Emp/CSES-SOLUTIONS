class Solution {
    public: 
        bool checkInclusion(string s1, string s2) {
            int len1 = s1.size();
            int len2 = s2.size();

            if(len1 > len2) return false;

            vector<int> s1Count(26, 0);
            vector<int> windowCount(26, 0);

            for( char c : s1) {
                s1Count[c - 'a']++;
            }

            for(int i  = 0; i < len1; i++){
                windowCount[s2[i] - 'a']++;
            }

            if( s1Count == windowCount) return true;

            for(int i = len1; i< len2; i++){
                windowCount[s2[i] - 'a']++;

                windowCount[s2[i - len1] - 'a']--;


                if(windowCount == s1Count ) return true;
            }

            return false; 
        }
}