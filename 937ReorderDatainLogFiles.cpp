class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> output;
        vector<string> output_digit;
        cout<<"len log "<<logs.size()<<endl;
        vector<string> identifier;
        vector<string> logs_wokey;
        // 存原本的idx
        vector<pair<int, string>> indexed_str_arr;
        // 建立好vector
        for (auto tmp_str: logs){
            stringstream ss(tmp_str);
            string tmp;
            ss>>tmp;
            identifier.push_back(tmp);
            getline(ss, tmp);
            logs_wokey.push_back(tmp);
        }

        // 
        cout<<endl;
        // cout<<logs_wokey[0].compare(logs_wokey[1])<<endl;
        for (int i = 0;i<logs.size();i++){
            if (logs_wokey[i][1]<58&&logs_wokey[i][1]>47){
                // cout<<"is num "<< logs_wokey[i]<<endl;
                output_digit.push_back(logs[i]);
            }
            else{
                indexed_str_arr.push_back({i, logs_wokey[i]});
            }
        }
        // cout<<"--------------------"<<endl;
        // for (auto element: indexed_str_arr){
        //     cout<<element.first<<" "<<element.second<<endl;
        // }
        sort(indexed_str_arr.begin(), indexed_str_arr.end(), 
              [identifier](const pair<int, string>& a, const pair<int, string>& b){
                    if (a.second == b.second){
                        // cout<<"a ident "<<identifier[a.first]<<" b idnet "<<identifier[b.first]<<endl;
                        return identifier[a.first]<identifier[b.first];
                    }
                    return a.second < b.second;  // 按字符串的字典顺序排序
              });
        cout<<"----------after sort----------"<<endl;
        for (auto element: indexed_str_arr){
            // cout<<element.first<<" "<<element.second<<endl;
            output.push_back(logs[element.first]);
        }
        output.insert(output.end(), output_digit.begin(), output_digit.end());

        return output;
    }
};
