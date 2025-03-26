// ps 最少訪問是LFU(least frequently used)
class LRUCache {
public:
    LRUCache(int capacity) {
        // cout<<"init ";
        cache_size = capacity;
    }
    
    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }
        // pos應該會是一個pointer，但這裡要直接娶第二個元素，因此直接->second（如果list只有一個元素的話則是要用*)
        auto pos = m[key];
        int output = pos->second;
        cache.erase(pos);
        cache.push_front({key, output});
        m[key] = cache.begin();
        return output;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            cache.erase(m[key]);
        }
        cache.push_front({key, value});
        m[key] = cache.begin();
        if (size(cache)>cache_size){
            auto last = cache.back();
            // cout<<"key "<<key<<" value "<<value<<endl;
            // cout<<"last會拿到啥？ "<<last.second<<endl;
            cache.erase(m[last.first]); // 這行如果改成pop back? -->沒有大區別
            m.erase(last.first);  //他們erase機制好像不一樣，一個用iterator一個用key（所有容器都可以用iterator erase
        }
        return;
    }
private:
    list<pair<int, int>> cache;
    int cache_size = 0;
    int cache_que_size = 0;
    unordered_map<int, list<pair<int, int>>::iterator> m; // 等等可以改unordered map試試，它的作用是紀錄每個list的位置 --->快一點點
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
