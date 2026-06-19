class Solution {
public:
    set<vector<int>> block;
    vector<pair<int,int>> adj = {{-1,0}, {0,-1}, {0,1}, {1,0}};
    bool solve(int blocks_size, vector<int> &source, vector<int> &target) {
        //max area we can consider square and right triangle also works
        //imagine the source is at (0,0) and 200 are blocks are blocking in diagonal way it is also possible configuration
        int area = (blocks_size * blocks_size)/2;
        set<pair<int,int>> visited;
        queue<pair<int,int>> que;
        que.push({source[0],source[1]});
        int cnt = 0;
        while(!que.empty()) {
            int row = que.front().first;
            int col = que.front().second;
            que.pop();
            if(row == target[0] && col == target[1]) return true;
            if(cnt > area) return true;
            for(int i = 0;i < 4;i++) {
                int new_row = row + adj[i].first;
                int new_col = col + adj[i].second;
                if(new_row >= 0 && new_row < 1e6 && new_col >= 0 && new_col < 1e6) {
                    if(visited.find({new_row,new_col}) == visited.end() && block.find({new_row,new_col}) == block.end()) {
                        que.push({new_row,new_col});
                        visited.insert({new_row,new_col});
                    }
                }
            }
            cnt++;
        }
        return false;
    }
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        for(auto &x : blocked) {
            block.insert(x);
        }
        return solve(blocked.size(),source,target) && solve(blocked.size(),target,source);
    }
};