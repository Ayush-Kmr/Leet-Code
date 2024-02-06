class Solution {
public:
    void solve(int i,int k, int n, vector<int>jobs, vector<int>worker,int ans, int &res){
//         Base case
        if(i==n){
             ans = *max_element(worker.begin(),worker.end());
             res = min(res,ans);
            return;
        }
        if(*max_element(worker.begin(),worker.end()) >= res) return;
        
        for(int j=0; j<k; j++){
            if(j>0 && worker[j]==worker[j-1]) continue;
            
         worker[j] +=jobs[i];
//             Recursive call
            solve(i+1,k,n,jobs,worker,ans,res);
            
//             Backtrack
            worker[j]-=jobs[i];
        }
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        sort(jobs.begin(),jobs.end(), greater<int>());
        
        if(n==k) return jobs[0];
        vector<int>worker(k,0);
        int assignAns = 0;
        int finalAns = INT_MAX;
        int index =0;
        solve(index, k,  n, jobs, worker, assignAns, finalAns);
        return finalAns;
    }
};