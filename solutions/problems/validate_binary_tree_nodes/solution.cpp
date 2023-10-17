class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        bitset<10005> inLeft,inRight;
        for (int c : leftChild) {
            if (c == -1) continue;
            if (inLeft[c]) return false;
            inLeft[c] = 1;
        }
        for (int d : rightChild) {
            if (d == -1) continue;
            if (inRight[d]) return false;
            if (inLeft[d]) return false;
            inRight[d] = 1;
        }
        int anc = 0;
        bitset<10005> ancestors,vis;

        vector<int> ancestorsList;
        for (int i = 0; i < n; i++) {
            if (!inLeft[i] && !inRight[i]) {
                anc++;
                ancestorsList.push_back(i);
                ancestors[i] = 1;
            }
        }
        if (anc != 1) return false;
        for (int a : ancestorsList) {
            vis[a] = 1;
        }
        for (int a : ancestorsList) {
            deque<int> deck;
            deck.push_back(a);
            while (!deck.empty()) {
                int x = deck.front();
                deck.pop_front();
                if (leftChild[x] != -1) {
                    if (vis[leftChild[x]]) return false;
                    vis[leftChild[x]] = 1;
                    deck.push_back(leftChild[x]);
                }
                if (rightChild[x] != -1) {
                    if (vis[rightChild[x]]) return false;
                    vis[rightChild[x]] = 1;
                    deck.push_back(rightChild[x]);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i]) return false;
        }
        return true;

    }
};