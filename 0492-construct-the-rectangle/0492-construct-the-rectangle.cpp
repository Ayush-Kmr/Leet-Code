class Solution {
public:
    vector<int> constructRectangle(int area) {
        int i=sqrt(area);
        for(;i>=1;i--)
        {
            if(area%i==0)
                return {area/i,i};
        }
        return {};
        
    }
};