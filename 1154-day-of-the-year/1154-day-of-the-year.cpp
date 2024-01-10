class Solution {
public:
    
     int isLeap(int n){
        //code here
        if(n%4==0)
        {
            if(n%100==0)
            {
                if(n%400==0)
                {
                    return 1;
                }
                else{
                    return 0;
                }
            }
            else{
                return 1;
            }
        }
            
        return 0;
    }
    
    int dayOfYear(string date) {
        int d=(date[8]-'0')*10+(date[9]-'0');
        int m=(date[5]-'0')*10+(date[6]-'0');
        int y=(date[0]-'0')*1000+(date[1]-'0')*100+(date[2]-'0')*10+(date[3]-'0');
        
        int ans=0;
        for(int month_i=1; month_i<m; month_i++){
            if(month_i==1 || month_i==3 || month_i==5 || month_i==7 || month_i==8 || month_i==10  || month_i==12){
                ans+=31;
            }
            else if(month_i==2){
                if(isLeap(y)){
                    ans+=29;
                }
                else{
                    ans+=28;
                }
            }
            else{
                ans+=30;
            }
        }
        ans+=d;
        return ans;
    }
};