class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<pair<int, int>> robots;
        for (int i = 0; i < n; ++i) {
            robots.push_back({positions[i], i});
        }
        sort(robots.begin(), robots.end());
        
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            int index = robots[i].second;
            if (directions[index] == 'R') {
                s.push(index);
            } else {
                while (!s.empty() && healths[s.top()] < healths[index]) {
                    healths[s.top()] = 0;
                    s.pop();
                }
                if (!s.empty() && healths[s.top()] == healths[index]) {
                    healths[s.top()] = 0;
                    healths[index] = 0;
                    s.pop();
                } else if (!s.empty()) {
                    healths[s.top()]--;
                    healths[index] = 0;
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (healths[i] > 0) {
                result.push_back(healths[i]);
            }
        }
        return result;
    }
};
