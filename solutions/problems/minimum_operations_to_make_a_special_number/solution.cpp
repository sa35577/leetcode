class Solution {
public:
    int minimumOperations(string num) {
        int mn = num.size();
        int lastZero = num.size()-1, lastFive = num.size()-1;
        while (lastZero >= 0 && num[lastZero] != '0') lastZero--;
        while (lastFive >= 0 && num[lastFive] != '5') lastFive--;
        if (lastZero == -1 && lastFive == -1) return mn;
        int lfive = lastZero-1, lseven = lastFive - 1, ltwo = lastFive-1,lzero = lastZero-1;
        while (lfive >= 0 && num[lfive] != '5') lfive--;
        while (lseven >= 0 && num[lseven] != '7') lseven--;
        while (ltwo >= 0 && num[ltwo] != '2') ltwo--;
        while (lzero >= 0 && num[lzero] != '0') lzero--;

        if (lfive >= 0) mn = min(mn,(int)(num.size()-1-lfive+1-2));
        if (lseven >= 0) mn = min(mn,(int)(num.size()-1-lseven+1-2));
        if (ltwo >= 0) mn = min(mn,(int)(num.size()-1-ltwo+1-2));
        if (lzero >= 0) mn = min(mn,(int)(num.size()-1-lzero+1-2));
        if (lastZero != -1) {
            mn = min(mn,int(num.size()-1));
        }


        return mn;
        

    }
};