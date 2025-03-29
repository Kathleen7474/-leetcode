class WordDictionary {
public:
    WordDictionary* child[26] = {};
    bool is_word = false;
    int key = -1;
    WordDictionary() {
        
    }
    WordDictionary(int a): key(a) {
        // cout<<"insert key"<<key<<endl;
    }
    
    void addWord(string word) {
        WordDictionary *cur = this;
        for (int letter: word){  
            letter = letter-97;
            if (cur->child[letter]==nullptr){
                cur->child[letter] = new WordDictionary(letter);
            }
            cur = cur->child[letter];

            // cur->is_word = true;
        }
        cur->is_word = true;
    }
    
    bool search(string word) {
        WordDictionary *cur = this;
        if(size(word)==0&&is_word==true){
            return true;
        }else if(size(word)==0){
            return false;
        }
        int letter = word[0]-97;
        // cout<<"word[0] "<<word[0]<<" word size "<<size(word)<<endl;
        // cout<<"my key"<<cur->key<<endl;
        if(letter == -51){
            WordDictionary *tmp_cur;
            for(int i = 0;i<26;i++){
                if(cur->child[i]!=nullptr){
                    tmp_cur = cur->child[i];
                    if (tmp_cur->search(word.substr(1))== true){
                        return true;
                    }
                }
            }
            // cout<<"in . return false"<<endl;
            return false;
        }
        if(cur->child[letter]!=nullptr){
            // cout<<"child key"<<cur->child[letter]->key<<endl;
            cur = cur->child[letter];
            return cur->search(word.substr(1));
        }else{
            // cout<<"letter not found return"<<letter<<endl;
            return false;
        }
    }

};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
