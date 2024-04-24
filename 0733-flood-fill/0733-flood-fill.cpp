class Solution {
public:
    bool isValid(int row, int col, int i, int j){
        return (i >= 0 && i < row && j >= 0 && j < col);
    }
    
void fill(vector<vector<int>>& image, int sr, int sc, int newColor, int originalColor) {
if(!isValid(image.size(), image[0].size(), sr, sc) || image[sr][sc] != originalColor) {
            return;
        }
        
        image[sr][sc] = newColor;
        
        fill(image, sr + 1, sc, newColor, originalColor);
        fill(image, sr - 1, sc, newColor, originalColor);
        fill(image, sr, sc + 1, newColor, originalColor);
        fill(image, sr, sc - 1, newColor, originalColor);
    }

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int originalColor = image[sr][sc];
        if (originalColor != newColor) {
            fill(image, sr, sc, newColor, originalColor);
        }
        return image;
    }
};
