class Solution {
public:
    /**
     * @param image: a binary matrix with '0' and '1'
     * @param x: the location of one of the black pixels
     * @param y: the location of one of the black pixels
     * @return: an integer
     */
    int minArea(vector<vector<char>> &image, int x, int y) {
        // write your code here
        int row = image.size();
        int col = image[0].size();
        int n = 0,m = 0;
        for(int i = 0;i < row;i++){
        	int mm = 0;
        	int flag = true;
        	for(int j = 0;j < col;j++){
        		if(image[i][j] = '1'){
        			mm++
        			if(flag)
        				n++;
        			flag = false;
        		}
        	}
        	m = max(mm,m);
        }
    }
};