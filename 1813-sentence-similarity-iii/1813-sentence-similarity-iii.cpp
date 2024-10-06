class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> vec1, vec2;
        string temp = "";

        // Split sentence1 into words and store them in vec1
        for (int i = 0; i < sentence1.length(); i++) {
            if (sentence1[i] == ' ') {
                vec1.push_back(temp);
                temp = "";
            } else {
                temp += sentence1[i];
            }
        }
        vec1.push_back(temp);  // Push the last word

        temp = "";
        // Split sentence2 into words and store them in vec2
        for (int i = 0; i < sentence2.length(); i++) {
            if (sentence2[i] == ' ') {
                vec2.push_back(temp);
                temp = "";
            } else {
                temp += sentence2[i];
            }
        }
        vec2.push_back(temp);  // Push the last word

        int n = vec1.size();
        int m = vec2.size();

        // Ensure vec1 is always the smaller or equal sized sentence for comparison
        if (n > m) {
            swap(vec1, vec2);
            swap(n, m);
        }

        int i = 0, j = n - 1;
        int k = 0, l = m - 1;

        // Compare the sentences from both ends (start and end)
        while (i <= j && k <= l) {
            if (vec1[i] == vec2[k]) {  // Matching from start
                i++;
                k++;
            } else if (vec1[j] == vec2[l]) {  // Matching from end
                j--;
                l--;
            } else {
                break;  // If neither start nor end matches, break out of the loop
            }
        }

        // If all words from vec1 are matched within vec2, then return true
        return i > j;
    }
};
