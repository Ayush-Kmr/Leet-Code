// class Comp{
//     bool operator(pair<int,int> )
// };
class Solution {
    int getRoom(vector<bool> res,int n){
        for(int i=0;i<n;i++){
            if(!res[i]){
                return i;
            }
        }
        return -1;
    }
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> count(100,0);
        priority_queue<pair<long,int>,vector<pair<long,int>>, greater<pair<long,int>>> pq;
        sort(meetings.begin(),meetings.end());
        int k=0;
        vector<bool> res(100);
        for(int i=0;i<meetings.size();i++){
            while(!pq.empty() && pq.top().first<=meetings[i][0]){
                res[pq.top().second]=false;
                pq.pop();
            }
            if(pq.size()<n){
                int room=getRoom(res,n);
                res[room]=true;
                pq.push({meetings[i][1],room});
                count[room]++;
            }
            else{
                long end=pq.top().first;
                int room=pq.top().second;
                pq.pop();
                pq.push({(long)end+(meetings[i][1]-meetings[i][0]),room});
                count[room]++;
            }
            cout<<pq.top().first<<" "<<pq.top().second<<endl;
        }
        int ans=0;
        int mini=0;
        for(int i=0;i<n;i++){
            cout<<count[i]<<" ";
            if(count[i]>mini){
                mini=count[i];
                ans=i;
            }
        }
        cout<<endl;
        return ans;
    }
};