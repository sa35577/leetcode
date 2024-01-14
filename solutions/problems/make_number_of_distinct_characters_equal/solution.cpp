class Solution {
public:
    bool isItPossible(string word1, string word2) {
        // frequency map f1,f2
        // count number of distinct characters
        // if same: need to find a char that exists in both word1 and word2, or two different chars that appear in one and not the other return true iff exists
        // if not same: assume word1 has higher. swap if needed
        // if differ by more than 2, impossible
        // if differ by 2, find a char that doesnt exist in word2 that exists once in word1. return true iff exists
        // if differ by 1, find a char that doesnt exist in word2 that exists > 1 time in word1. return true iff exists
        // return false otherwise.
        int f1[26], f2[26];
        memset(f1,0,sizeof(f1));
        memset(f2,0,sizeof(f2));
        int distinct1 = 0, distinct2 = 0;
        for (char c : word1) {
            if (f1[c-'a'] == 0) distinct1++;
            f1[c-'a']++;
        }
        for (char c : word2) {
            if (f2[c-'a'] == 0) distinct2++;
            f2[c-'a']++;
        }
        int diff = abs(distinct1 - distinct2);
        if (diff == 0) {
            // -2 +2
            bool minusTwo = false, plusTwo = false;
            for (int i = 0; i < 26; i++) {
                if (f1[i] == 1 && f2[i] == 0) minusTwo = true;
                if (f2[i] == 1 && f1[i] == 0) plusTwo = true;
            }
            if (minusTwo && plusTwo) return true;

            // -1 +1
            bool minusOne = false, plusOne = false;
            for (int i = 0; i < 26; i++) {
                if (f1[i] == 1 && f2[i] > 0) minusOne = true;
                else if (f1[i] > 1 && f2[i] == 0) minusOne = true;
                else if (f2[i] == 1 && f1[i] > 0) plusOne = true;
                else if (f2[i] > 1 && f1[i] == 0) plusOne = true;
            }
            if (plusOne && minusOne) return true;

            // 0 0
            for (int i = 0; i < 26; i++) {
                if (f1[i] >= 1 && f2[i] >= 1) return true;
            }

            return false;
        }
        else if (diff > 2) {
            return false;
        }
        else if (diff == 2) {
            if (distinct1 < distinct2) {
                for (int i = 0; i < 26; i++) swap(f1[i],f2[i]);
            }
            bool moveTo2 = false, moveTo1 = false;
            for (int i = 0; i < 26; i++) {
                if (f1[i] == 1 && f2[i] == 0) moveTo2 = true;
                if (f1[i] > 0 && f2[i] > 1) moveTo1 = true;
            }
            if (moveTo1 && moveTo2) return true;
            return false;
        }
        else {
            if (distinct1 < distinct2) {
                for (int i = 0; i < 26; i++) swap(f1[i],f2[i]);
            }
            bool moveTo2 = false, moveTo1 = false;
            vector<int> v1,v2,v3,v4;
            for (int i = 0; i < 26; i++) {
                if (f1[i] > 1 && f2[i] == 0) {moveTo2 = true; v1.push_back(i);}
                if (f1[i] == 1 && f2[i] > 0) {moveTo2 = true; v1.push_back(i);}
                if (f2[i] > 1 && f1[i] > 0) { moveTo1 = true; v2.push_back(i);}
                if (f1[i] == 1 && f2[i] == 0) v3.push_back(i);
                if (f1[i] == 0 && f2[i] > 1) v4.push_back(i);
                if (f1[i] > 0 && f2[i] == 1) v4.push_back(i);
            }
            if (moveTo1 && moveTo2) {
                if (v1.size() > 1 || v2.size() > 1) return true;
                if (v1[0] != v2[0]) return true;
            }
            if (v3.size() > 0 && v4.size() > 0) return true;
            return false;
        }

    }
};