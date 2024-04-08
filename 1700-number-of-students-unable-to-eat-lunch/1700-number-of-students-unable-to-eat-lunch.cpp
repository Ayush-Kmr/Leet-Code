class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>q;
        for(auto i:students){
            q.push(i);
        }
        int s=0;
        int ans=0;
        int n=students.size();
        for(int i=0; i<sandwiches.size(); ){
            int st = q.front();
            int x=i;
           if(st==sandwiches[i]){
               q.pop();
               i++;
           }
            else {
                q.pop();
                  q.push(st);
            }
            if(x==i)s++;
            else s=0;
            if(s>n)break;
            ans=i;   
        }
        return students.size()-ans;
    }
};