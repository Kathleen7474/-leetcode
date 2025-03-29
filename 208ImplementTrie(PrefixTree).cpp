class Trie {
public:
    // 大括號是要把所有26個ptr指向nullptr
    Trie *child[26] = {};
    bool is_word = false;
    // int word;
    Trie() {
        // cout<<"new trie"<<endl;
    }
    // Trie(int a): word(a){
    //     // cout<<"new trie input: "<<word<<endl;
    // } 
    void insert(string word) {
        Trie *cur = this;
        for (int letter:word){
            letter = letter - 97;
            // cout<<letter<<endl;
            if(cur->child[letter]==nullptr){
                cur->child[letter] = new Trie();
            }
            cur = cur->child[letter];
        }
        cur->is_word = true;

        // cout<<"fin insert-----------------"<<endl;
    }
    
    bool search(string word) {
        Trie *cur = this;
        for (int letter:word){
            letter = letter - 97;
            // cout<<letter<<endl;
            if(cur->child[letter]!=nullptr){
                cur = cur->child[letter];
            }
            else return false;
        }
        return cur->is_word;
    }
    
    bool startsWith(string prefix) {
        Trie *cur = this;
        for (int letter:prefix){
            letter = letter - 97;
            // cout<<letter<<endl;
            if(cur->child[letter]!=nullptr){
                cur = cur->child[letter];
            }
            else return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
