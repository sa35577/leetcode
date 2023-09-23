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

            // if (shiftLeft) {
            //     startLeftPtr--;
            //     minHeight = min(minHeight,heights[startLeftPtr]);
            //     maxArea = max(maxArea,(startRightPtr-startLeftPtr+1) * minHeight);
            // }
            // else if (shiftRight) {
            //     startRightPtr++;
            //     minHeight = min(minHeight,heights[startRightPtr]);
            //     maxArea = max(maxArea,(startRightPtr-startLeftPtr+1) * minHeight);
            // }
            // else {
            //     startLeftPtr--;
            //     startRightPtr++;
            //     minHeight = min(minHeight,heights[startRightPtr]);
            //     maxArea = max(maxArea,(startRightPtr-startLeftPtr+1) * minHeight);
            // }
        }

        return max(maxArea,max(leftResult,rightResult));
    }

    int largestRectangleArea(vector<int>& heights) {
        return maxAreaFunction(heights,0,heights.size()-1);
    }
};