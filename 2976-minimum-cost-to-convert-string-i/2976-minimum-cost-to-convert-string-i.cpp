class Solution {
public:
    vector<vector<long long>> floydWarshall(vector<vector<pair<int, long long>>>& adjList) {
        int numVertices = 26;
        vector<vector<long long>> dist(numVertices, vector<long long>(numVertices, LLONG_MAX));
        
        for (int i = 0; i < numVertices; i++) {
            for (const auto& neighbor : adjList[i]) {
                dist[i][neighbor.first] = min(dist[i][neighbor.first], neighbor.second);
            }
        }
        
        for (int k = 0; k < numVertices; k++) {
            for (int i = 0; i < numVertices; i++) {
                for (int j = 0; j < numVertices; j++) {
                    if (dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        return dist;
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int numVertices = 26;
        vector<vector<pair<int, long long>>> adjList(numVertices);
        
        for (int i = 0; i < cost.size(); i++) {
            int from = original[i] - 'a';
            int to = changed[i] - 'a';
            long long transformationCost = cost[i];
            adjList[from].push_back({to, transformationCost});
        }
        
        vector<vector<long long>> dist = floydWarshall(adjList);
        long long totalCost = 0;
        
        for (int i = 0; i < source.size(); i++) {
            int sourceChar = source[i] - 'a';
            int targetChar = target[i] - 'a';
            if (source[i] != target[i]) {
                if (dist[sourceChar][targetChar] == LLONG_MAX) return -1;
                totalCost += dist[sourceChar][targetChar];
            }
        }
        
        return totalCost;
    }
};
