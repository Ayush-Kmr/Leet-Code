class Solution {
    public boolean judgeSquareSum(int c) {
        int a = 0;
        int b = (int)Math.sqrt(c);
        while(a <= b){
            long sum = (long)a*a + (long)b*b;
            if(sum == c) return true;
            else if (sum < c) a++;
            else if (sum > c) b--;
        }
        return false;
    }
}
