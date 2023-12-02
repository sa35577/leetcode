class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<int,int> cfreq;
        for (char c : chars) {
            if (cfreq.find(c) == cfreq.end()) cfreq[c] = 0;
            cfreq[c]++;
        }
        int cnt = 0;
        for (string word : words) {
            map<int,int> wfreq;
            for (char c : word) {
                if (wfreq.find(c) == wfreq.end()) wfreq[c] = 0;
                wfreq[c]++;
            }
            bool bad = false;
            for (auto it = wfreq.begin(); it != wfreq.end(); it++) {
                if (cfreq.find(it->first) == cfreq.end() || cfreq[it->first] < wfreq[it->first]) {
                    bad = true;
                    break;
                }
            }
            if (!bad) cnt += word.size();
        }
        return cnt;
    }
};