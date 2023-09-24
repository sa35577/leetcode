class Solution {
public:

    int maxAreaFunction(vector<int> &heights, int L, int R) {
        // cout << L << " " << R << endl;
        if (L == R) return heights[L];
        if (R - L == 1) return max(heights[L],max(heights[R],min(heights[L],heights[R])*2));
        int mid = (L + R)/2;

        int leftResult = maxAreaFunction(heights,L,mid);
        int rightResult = maxAreaFunction(heights,mid+1,R);

        int startLeftPtr = mid, startRightPtr = mid+1;
        int minHeight = min(heights[startLeftPtr],heights[startRightPtr]);
        int maxArea = minHeight*2;

        while (startLeftPtr >= L && startRightPtr < R+1) {
            if (startLeftPtr - 1 >= L && startRightPtr + 1 < R+1) {
                if (heights[startLeftPtr-1] > heights[startRightPtr+1]) { 
                    // shiftLeft = true; shiftRight = false; 
                    startLeftPtr--;
                    minHeight = min(minHeight,heights[startLeftPtr]);
                }
                else if (heights[startLeftPtr-1] < heights[startRightPtr+1]) { 
                    //shiftLeft = false; shiftRight = true;
                    startRightPtr++;
                    minHeight = min(minHeight,heights[startRightPtr]);
                }
                else {
                    startLeftPtr--;
                    startRightPtr++;
                    minHeight = min(minHeight,heights[startLeftPtr]);
                    minHeight = min(minHeight,heights[startRightPtr]);
                }
            }
            else if (startLeftPtr - 1 >= L) {
                // shiftLeft = true;
                // shiftRight = false;
                startLeftPtr--;
                minHeight = min(minHeight,heights[startLeftPtr]);
            }
            else if (startRightPtr + 1 < R+1) {
                // shiftLeft = false;
                // shiftRight = true;
                startRightPtr++;
                minHeight = min(minHeight,heights[startRightPtr]);
            }
            else {
                break;
            }

            
            maxArea = max(maxArea,(startRightPtr-startLeftPtr+1) * minHeight);

        }

        return max(maxArea,max(leftResult,rightResult));
    }

    int largestRectangleArea(vector<int>& heights) {
        return maxAreaFunction(heights,0,heights.size()-1);
    }

    void printHeights(vector<int> &heights) {
        for (int i : heights) cout << i << " " ;
        cout << endl;
    }


    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> heights;
        for (int i = 0; i < matrix[0].size(); i++) heights.push_back(0);
        int mx = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == '0') heights[j] = 0;
                else heights[j]++;
            }
            //printHeights(heights);
            mx = max(mx,largestRectangleArea(heights));
        }
        return mx;
    }
};