class Solution {
public:
   typedef pair<int,int> pii;
   int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
       int n=profits.size();
       vector<pii> cap_prof(n);
       for(int i=0; i<n; i++) cap_prof[i] = {capital[i],profits[i]};
       sort(cap_prof.begin(), cap_prof.end());
       priority_queue<int> maxheap;
       int i=0;
       while(k--){
           while(i<n && cap_prof[i].first<=w) maxheap.push(cap_prof[i++].second);
           if(maxheap.empty()) return w;
           w+=maxheap.top(); maxheap.pop();
       }
       return w;
   }
};