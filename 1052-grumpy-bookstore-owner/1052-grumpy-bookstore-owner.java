class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int minutes) {
        int n = grumpy.length;
        int currUnsat = 0;
        for(int i=0; i<minutes; i++){
            currUnsat += customers[i] * grumpy[i]; 
        }
        int maxUnsat = currUnsat;
        int i=0; 
        int j=minutes;
        while(j<n){
            currUnsat += customers[j] * grumpy[j];
            currUnsat -= customers[i] * grumpy[i];
            maxUnsat = Math.max(maxUnsat,currUnsat);
            
            i++;
            j++;
        }
        int totalSat = maxUnsat;
        for(i=0; i<n; i++){
            if(grumpy[i] == 0)
            totalSat +=  customers[i];
        }
        return totalSat;
    }
}