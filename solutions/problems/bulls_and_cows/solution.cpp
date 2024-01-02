class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        int secretFreq[10];
        int guessFreq[10];
        memset(secretFreq,0,sizeof(secretFreq));
        memset(guessFreq,0,sizeof(guessFreq));
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) bulls++;
            else {
                secretFreq[secret[i]-'0']++;
                guessFreq[guess[i]-'0']++;
            }
        }
        for (int i = 0; i < 10; i++) {
            cows += min(secretFreq[i],guessFreq[i]);
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};