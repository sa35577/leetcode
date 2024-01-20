class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        double min = -1,max = -1, mean = 0, median = 0, mode = 0;
        int freq = 0;
        //min
        for (int i = 0; i < count.size(); i++) {
            if (count[i] > 0) {
                min = i;
                break;
            }
        }
        //max
        for (int i = 255; i >= 0; i--) {
            if (count[i] > 0) {
                max = i;
                break;
            }
        }
        int sz = 0;
        for (int & c : count) sz += c;
        //mean
        for (int i = 0; i < count.size(); i++) {
            mean += ((double)(i) / (double)(sz)) * (double)(count[i]);
        }
        //mode
        int maxFreq = -1;
        for (int i = 0; i < 256; i++) {
            if (count[i] > maxFreq) {
                maxFreq = count[i];
                mode = i;
            }
        }
        if (sz % 2 == 1) {
            int cnt = 0;
            for (int i = 0; i < 256; i++) {
                if (cnt + count[i] >= (sz + 1)/2) {
                    median = i;
                    break;
                }
                else cnt += count[i];
            }
        }
        else {
            int cnt = 0;
            bool imm = false;
            for (int i = 0; i < 256; i++) {
                if (imm && count[i] > 0) {
                    median += (double)(i) / 2.0;
                    break;
                }
                if (cnt + count[i] > sz/2) {
                    median = i;
                    break;
                }
                else if (cnt + count[i] == sz/2) {
                    imm = true;
                    median += (double)(i) / 2.0;
                }
                else {
                    cnt += count[i];
                }
            }
        }
        return {min,max,mean,median,mode};
    }
};