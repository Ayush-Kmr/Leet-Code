class Solution {
public:
    void solve(int i,int k, int n, vector<int>jobs, vector<int>work,int ans, int &res){
//         Base case
        if(i==n){
             ans = *max_element(work.begin(),work.end());
             res = min(res,ans);
            return;
        }
        if(*max_element(work.begin(),work.end()) >= res) return;
        
        for(int j=0; j<k; j++){
            if(j>0 && work[j]==work[j-1]) continue;
            
         work[j] +=jobs[i];
//             Recursive call
            solve(i+1,k,n,jobs,work,ans,res);
            
//             Backtrack
            work[j]-=jobs[i];
        }
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        sort(jobs.begin(),jobs.end(), greater<int>());
        
        if(n==k) return jobs[0];
        vector<int>work(k,0);
        int assignAns = 0;
        int finalAns = INT_MAX;
        int index =0;
        solve(index, k,  n, jobs, work, assignAns, finalAns);
        return finalAns;
    }
};