class Solution {
public:
    int candy(vector<int>& ratings) {
        // 如果有加減才需要cnt增加
        int cnt = size(ratings);
        int i = 1;
        while(i<size(ratings)){
            // 因為平坡一定會歸1所以不用寫
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }
            
            // 爬坡
            int peak = 0;
            while(ratings[i]>ratings[i-1]){
                cout<<"peak"<<endl;
                peak++;
                cnt = cnt+peak;
                i++;
                if (i==size(ratings))
                    return cnt;
            }
            int valley = 0;
            while(i<size(ratings) &&ratings[i]<ratings[i-1]){
                cout<<"valley i "<<i<<endl;
                valley++;
                cnt = cnt+valley;
                i++;
            }
            cnt = cnt - min(peak, valley);
        }
        return cnt;



        // garbage
        // // 當給出了最低數字要更新位置
        // vector<int> base_pos;
        // base_pos.push_back(-1);
        // vector<int> candy;
        // int cur = 1;
        // int cnt = 0;
        // for(int i =0; i< size(ratings);i++){
        //     // first and last
        //     if (i==0){
        //         if (ratings[i]<ratings[i+1]){
        //             cur = 1;
        //             candy.push_back(cur);
        //             base_pos.push_back(i);
        //         }else{
        //             cur = 2;
        //             candy.push_back(cur);
        //         }
        //         cnt = cnt + cur;
        //         // continue;
        //     }
        //     // 最後一個(也會有不夠扣)
        //     else if (i == size(ratings)-1){
        //         if(ratings[i]<=ratings[i-1]){
        //             // 在這裡
        //             if (cur ==1){
        //                 reset_candies(base_pos, candy, cnt, i,ratings);
        //             }
        //             cur = 1;
        //             cnt = cnt + cur;
        //             candy.push_back(cur);
        //         }
        //         else{
        //             cur = cur + 1;
        //             cnt = cnt + cur;
        //             candy.push_back(cur);
        //         }
        //     }
            
        //     // 不夠扣的情況？到推回去還有可能撞車
        //     // 1.小於左大於右(不夠扣應該在這)
        //     else if(ratings[i]<ratings[i-1]&&ratings[i]>ratings[i+1]){
        //         cur = cur - 1;
        //         if (cur == 0){
        //             reset_candies(base_pos, candy, cnt, i,ratings);
                    
        //         }
        //         cur = 1;
        //         if (cur == 1){
        //             candy.push_back(cur);
        //             base_pos.push_back(i);
        //         }

        //         cnt = cnt + cur;
        //     }

        //     // 2.大於左小於右（直接加一
        //     else if(ratings[i]>ratings[i-1]){
        //         cur = cur + 1;
        //         cnt = cnt + cur;
        //         candy.push_back(cur);
        //     }
        //     // 3.等於左大於右
        //     else if(ratings[i]<=ratings[i-1]&&ratings[i]>ratings[i+1]){
        //         cur = 1;
        //         candy.push_back(cur);
        //         base_pos.push_back(i);
        //         cnt = cnt + cur;
        //     }

            
            

        //     // 左右最低點
        //     else if(ratings[i]<=ratings[i+1]&&ratings[i]<=ratings[i-1]){
        //         cur = 1;
        //         cnt = cnt + cur;
        //         base_pos.push_back(i);
        //         candy.push_back(cur);
        //     }
        //     cout<<"i finish "<<i<<endl;
        //     print_candies(candy);
        //     cout<<"cnt "<<cnt<<endl;
        // }
        // return cnt;
    }
private:
void print_candies(vector<int>& candy){
    cout<<"print candy ";
    for (int i = 0;i<size(candy);i++){
        cout<<" "<<candy[i];
    }
    cout<<endl;
    return;
}
// 好像從base的下一個加一就好？
void reset_candies(vector<int>& base_pos, vector<int>& candy,int& cnt,int pos, vector<int>& ratings){
    cout<<"pos "<<pos<<" base back "<<base_pos.back()<<endl;

    int back_pos = (base_pos.back() == -1) ? 0 : base_pos.back();
    int times = pos - back_pos;
    for (int i = 0;i<times;i++){
        cout<<"in loop"<<pos-i<<endl;
        candy[pos-i-1] = candy[pos-i-1] + 1;
        cnt++;
    }
    cout<<"in reset ";
    print_candies(candy);
    cout<<"old back "<<base_pos.back()<<endl;
    if(base_pos.back()==-1){
        return;
    }
    if(ratings[back_pos-1]!=ratings[back_pos]){
        base_pos.pop_back();
    }
    
    cout<<"new back "<<base_pos.back()<<endl;
    if(base_pos.back()==-1){
        if(candy[0]==candy[back_pos]){
        reset_candies(base_pos, candy, cnt, back_pos, ratings);
        }
        return;
    }
    if(candy[back_pos-1]==candy[back_pos]&&ratings[back_pos-1]>ratings[back_pos]){
        cout<<"reset reset: bask pos"<<back_pos<<endl;
        reset_candies(base_pos, candy, cnt, back_pos, ratings);
    }
    return ;
}
// 還有撞車的情形
};
