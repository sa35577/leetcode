class Solution {
public:
    int longestWPI(vector<int>& hours) {
        bool hasover = false;
        for (int i = 0; i < hours.size(); i++){
            if (hours[i] > 8) {
                hours[i] = 1;
                hasover = true;
            }
            else hours[i] = -1;
        }
        vector<int> psa;
        for (int i : hours) {
            if (psa.empty()) psa.push_back(i);
            else psa.push_back(psa.back()+i);
            //cout << psa.back() << " " ;
        }
        int mxInterval = 0;
        for (int i = 0; i < psa.size(); i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0) {
                    if (psa[i] > 0) {mxInterval = max(mxInterval,i-j+1); break;}
                }
                else {
                    if (psa[i] - psa[j-1] > 0) {mxInterval = max(mxInterval,i-j+1); break;}
                }
            }
        }
        return mxInterval;
        
        

    }
};