class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> graph(n);
        for (vector<int> v : paths) {
            graph[v[0]-1].push_back(v[1]-1);
            graph[v[1]-1].push_back(v[0]-1);
        }
        vector<int> colour(n);
        fill(colour.begin(),colour.end(),0);
        for (int i = 0; i < colour.size(); i++) {
            set<int> st;
            for (int x : graph[i]) st.insert(colour[x]);
            if (st.find(1) == st.end()) colour[i] = 1;
            else if (st.find(2) == st.end()) colour[i] = 2;
            else if (st.find(3) == st.end()) colour[i] = 3;
            else if (st.find(4) == st.end()) colour[i] = 4;
        }
        return colour;
    }
};