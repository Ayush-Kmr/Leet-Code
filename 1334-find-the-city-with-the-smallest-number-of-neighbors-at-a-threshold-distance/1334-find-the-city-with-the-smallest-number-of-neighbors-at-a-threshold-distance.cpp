class Solution {
public:
    #define P pair<int, int>

    // Khandaani Dijkstra's algorithm to find shortest paths from a source city
    void dijkstra(int n, unordered_map<int, vector<P>>& adj, vector<int>& result, int S) {
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, S});
        fill(result.begin(), result.end(), INT_MAX);
        result[S] = 0;  // Distance to source itself is zero

        // Process nodes in priority order
        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto& p : adj[node]) {
                int adjNode = p.first;
                int dist = p.second;

                if (d + dist < result[adjNode]) {
                    result[adjNode] = d + dist;
                    pq.push({d + dist, adjNode});
                }
            }
        }
    }

    int getCityWithFewestReachable(int n, const vector<vector<int>>& shortestPathMatrix, int distanceThreshold) {
        int cityWithFewestReachable = -1;
        int fewestReachableCount = INT_MAX;

        // Count number of cities reachable within the distance threshold for each city
        for (int i = 0; i < n; i++) {
            int reachableCount = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && shortestPathMatrix[i][j] <= distanceThreshold) {
                    reachableCount++;
                }
            }

            if (reachableCount <= fewestReachableCount) {
                fewestReachableCount = reachableCount;
                cityWithFewestReachable = i;
            }
        }
        return cityWithFewestReachable;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int, vector<P>> adj;

        vector<vector<int>> shortestPathMatrix(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; i++) {
            shortestPathMatrix[i][i] = 0;  // Distance to itself is zero
        }

        for (const auto& edge : edges) {
            int start = edge[0];
            int end = edge[1];
            int weight = edge[2];
            adj[start].push_back({end, weight});
            adj[end].push_back({start, weight});
        }

        // Compute shortest paths from each city using Dijkstra's algorithm
        for (int i = 0; i < n; i++) {
            dijkstra(n, adj, shortestPathMatrix[i], i);
        }

        return getCityWithFewestReachable(n, shortestPathMatrix, distanceThreshold);
    }
};