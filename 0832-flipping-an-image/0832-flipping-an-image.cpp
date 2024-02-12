class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
      for (int i = 0; i < image.size(); i++) {
        int start = 0;
        int end = image.size() - 1;
        while (start < end) {
            swap(image[i][start],image[i][end]);
            start++;
            end--;
        }
    }
        for(int i=0; i<image.size(); i++){
            for(int j=0; j<image.size(); j++){
                if(image[i][j] == 1) image[i][j] = 0;
                else image[i][j] = 1;
            }
        }
        return image;
    }
};