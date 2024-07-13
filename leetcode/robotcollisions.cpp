class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<array<int, 4>> robots;
        for (int i = 0; i < n; ++i) {
            robots.push_back({positions[i], healths[i], directions[i] == 'R' ? 1 : 0, i});
        }
        sort(robots.begin(), robots.end());
        
        vector<int> stack;
        vector<int> result(n);
        
        for (int i = 0; i < n; ++i) {
            int direction = robots[i][2];
            int index = robots[i][3];
            
            if (direction == 1) {  
                stack.push_back(i);
            } else {  
                while (!stack.empty() && healths[robots[stack.back()][3]] < healths[index]) {
                    healths[index]--;
                    healths[robots[stack.back()][3]] = 0;
                    stack.pop_back();
                }
                
                if (!stack.empty()) {
                    if (healths[robots[stack.back()][3]] > healths[index]) {
                        healths[robots[stack.back()][3]]--;
                        healths[index] = 0;
                    } else {  
                        healths[robots[stack.back()][3]] = 0;
                        healths[index] = 0;
                        stack.pop_back();
                    }
                }
            }
        }
        
        vector<int> survived;
        for (int i = 0; i < n; ++i) {
            if (healths[i] > 0) {
                survived.push_back(healths[i]);
            }
        }
        
        return survived;
    }
};