class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        queue<int> q;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            q.push(i);
        }
        int i = 0;
        while (!q.empty()) {
            int fv = q.front();
            q.pop();
            ans[fv] = deck[i++];
            if (!q.empty()) {
                int pv = q.front();
                q.pop();
                q.push(pv);
            }
        }
        return ans;
    }
};
