class OrderedStream {
    int values;
    vector<string> stream;
    int ptr = 0;
public:
    OrderedStream(int n) {
        values = n;
        stream.resize(n);
    }
    vector<string> insert(int idKey, string value) {
        vector<string> output;
        stream[idKey-1] = value;
        for(int i = ptr;i<values;i++){
            if(stream[i] == ""){
                // cout<<"empty";
                break;
            }else{
                output.push_back(stream[i]);
                ptr++;
            }
            // cout<<stream[i]<<" ";
        }
        // cout<<endl;
        return output;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
