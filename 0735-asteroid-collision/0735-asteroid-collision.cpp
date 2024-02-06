class Solution {
public:
    vector<int> asteroidCollision(vector<int>& as) {
        vector<int>v;
        int n = as.size();
        for(int i =0; i<n; i++){
            if(v.size()==0) v.push_back(as[i]);
            else{
                if(as[i]<0){
                    if(v.back()>0){
                        if(abs(as[i])>v.back()){
                            v.pop_back();
                            i--;     
                        }
                        else if(abs(as[i])==v.back()){
                            v.pop_back();
                        }
                    }
                    else{
                        v.push_back(as[i]);
                    }
                }
                else{
                    v.push_back(as[i]);
                }
            }
        }
        return v;
    }
};