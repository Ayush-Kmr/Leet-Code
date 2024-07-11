class Solution {
        public String reverseParentheses(String s) {
        Stack<String> st = new Stack<>();
        String ans = "";
        
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                st.push(ans);
                ans = "";
            } else if (s.charAt(i) == ')') {
                StringBuilder reversed = new StringBuilder(ans).reverse();
                ans = st.pop() + reversed.toString();
            } else {
                ans += s.charAt(i);
            }
        }
        
        return ans;
    }
}
