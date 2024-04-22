class Solution {
    vector<vector<int>> directions{{1,-1},{1,-1},{1,-1},{1,-1}};
public:
    int openLock(vector<string>& deadends, string target) {
        int count = 0;

        unordered_set<string> dead;

        unordered_set<string> vis;

        // create a set of all dead ends states
        for(auto& str : deadends) {
            dead.insert(str);
        }

        // initialise the starting string i.e. "0000";
        string start = "0000";

        queue<string> q;

        q.push(start);

        while(!q.empty()) {
            int n = q.size();

            for(int i=0; i<n; i++) {
                string curr = q.front();
                q.pop();

                // check if the current string is a part of dead end state or not
                if(dead.find(curr) != dead.end()) {
                    continue;
                }

                // check if the current string is the target string
                if(curr == target)  return count;

                for(int i=0; i<4; i++) {
                    for(int dir : directions[i]) {
                        string next = curr;
                        // will explain the next line later
                        next[i] = (next[i] - '0' + dir + 10)% 10 + '0'; // Rotate wheel

                        if(vis.find(next) == vis.end()) {
                            q.push(next);
                            vis.insert(next);
                        }

                    }
                }
            }
            
            count++;
        }

        return -1;
    }
};