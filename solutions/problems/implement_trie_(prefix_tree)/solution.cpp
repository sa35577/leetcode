class Trie {
public:
    bool hasEnding;
    bool init[26];
    vector<Trie*> v;
    Trie() {
        v.resize(26);
        hasEnding = false;
        for (int i = 0; i < 26; i++) init[i] = false;
    }
    
    void insert(string word) {
        if (word == "") hasEnding = true;
        else {
            int idx = word[0] - 'a';
            init[idx] = true;
            if (v[idx] == nullptr) v[idx] = new Trie;
            v[idx]->insert(word.substr(1));
        }
        
    }
    
    bool search(string word) {
        if (word == "") {
            return hasEnding;
        }
        if (!init[word[0]-'a']) return false;
        return v[word[0]-'a']->search(word.substr(1));
    }
    
    bool startsWith(string prefix) {
        if (prefix == "") {
            for (int i = 0; i < 26; i++) {
                if (init[i]) return true;
            }
            return hasEnding;
        }
        if (!init[prefix[0]-'a']) return false;
        return v[prefix[0]-'a']->startsWith(prefix.substr(1));
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */