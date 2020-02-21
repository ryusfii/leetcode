class StreamChecker {
    struct Node {
        Node(): value(0), children({nullptr}) {};
        int value;
        Node* children[26];
    };
    Node* root;
    Node* pos;
    list<char> queries;
    
public:
    /*StreamChecker(vector<string>& words) {
        
        root = new Node;
        pos = root;
        
        for (const string& word: words) {
            for (const char c: word) {
                char i = c - 'a';
                if (pos->children[i] == nullptr) {
                    pos->children[i] = new Node;
                }
                pos = pos->children[i];
            }
            pos->value = 1;
            pos = root;
        }
    }*/

    StreamChecker(vector<string>& words) {
        root = new Node;
        pos = root;
        
        for (const string& word: words) {
            for (auto it = word.rbegin(); it != word.rend(); it++) {
                char i = *it - 'a';
                if (pos->children[i] == nullptr) {
                    pos->children[i] = new Node;
                }
                pos = pos->children[i];
            }
            pos->value = 1;
            pos = root;
        }
    }
    
    bool query(char letter) {
        if (queries.size() > 2000) {
            queries.pop_front();
        }
        queries.push_back(letter);
        
        pos = root;
        for (auto it = queries.rbegin(); it != queries.rend(); it++) {
            char c = *it - 'a';
        
            if (pos->children[c] == nullptr) {
                //pos = root;
                return false;
            }
            if (pos->children[c]->value == 1) {
                pos = root;
                return true;
            }
            pos = pos->children[c];
        }

        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
