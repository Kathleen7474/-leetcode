class MapSum {
public:
map<string, int> map_data;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        // map_data.erase(map_data.find("Clay"));
        // map_data.insert(pair<string, int>(key, val));
        map_data[key] = val;
        return;
    }
    
    int sum(string prefix) {
        int substring_get;
        int sum = 0;
        for (auto &m: map_data) {
            cout << m.first << ": "<< m.second << endl;
            string map_string = m.first;

            substring_get = map_string.find(prefix);
            cout<<"substring get"<<substring_get<<endl;
            if(substring_get==0){
                sum = sum +m.second;
            }
        }
        cout<<sum<<"sum"<<endl;
        
        return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
