class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if (s.size() == 1) return true;
        if (s[s.size()-1]=='1') return false;
        
        deque<int> deck;
        deck.push_back(0);
        
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '0') {
                while (!deck.empty() && (i-deck.front() > maxJump)) deck.pop_front();
                if (deck.empty()) return false;
                if (i-deck.front() >= minJump) deck.push_back(i);
            }
        }
        
        return (s.size()-1-deck.front() >= minJump);
    }
};