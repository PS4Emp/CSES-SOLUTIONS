class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<array<int, 4>> robots;
        for (int i = 0; i < n; ++i) {
            robots.push_back({positions[i], healths[i], directions[i] == 'R' ? 1 : 0, i});
        }
        sort(robots.begin(), robots.end());
        
        vector<pair<int, int>> stack;
        for (const auto& robot : robots) {
            int health = robot[1];
            int direction = robot[2];
            int index = robot[3];
            
            if (direction == 1) {  
                stack.push_back({health, index});
            } else {  
                while (!stack.empty() && stack.back().first < health) {
                    stack.pop_back();
                    health--;
                }
                
                if (!stack.empty()) {
                    if (stack.back().first > health) {
                        stack.back().first--;
                    } else {  
                        stack.pop_back();
                    }
                } else {
                    stack.push_back({health, index});
                }
            }
        }
        
        vector<int> result(n, 0);
        for (const auto& [health, index] : stack) {
            result[index] = health;
        }
        
        result.erase(remove(result.begin(), result.end(), 0), result.end());
        return result;
    }
};