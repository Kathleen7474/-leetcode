class Solution {
public:
int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        int k;
        while(left<=right){
            k = (left+right)/2;
            long int hours = 0;
            // cout<<k<<endl;
            for(int bananas:piles){
                hours += (bananas + k - 1) / k;
            }
            if(hours<=h){
                right = k - 1;
            }
            else{
                left = k+1;
            }
        }
        return left;
    }
    // int minEatingSpeed(vector<int>& piles, int h) {
    //     sort(piles.begin(), piles.end());
    //     int left = 0, right = piles.size()-1;
    //     // int tmp_left,tmp_right;
    //     int mid = (left+right)/2;
    //     int k = piles[mid];
    //     int flag = 0;
    //     while(left<=right){
    //     // cout<<"left "<<left<<" right "<<right<<endl;
    //     // tmp_left = left, tmp_right = right;
    //         int hours = 0;
    //         for(int bananas:piles){
    //             hours += (bananas + k - 1) / k;
    //         }
    //         // 可以更有餘裕
    //         if(hours<=h){
    //             right = mid - 1;
    //             flag = 1;
    //         }else{
    //             left = mid +1;
    //             flag = 2;
    //         }
    //         mid = (left+right)/2;
    //         k = piles[mid];
    //     }
    //     cout<<"end left "<<left<<" right "<<right<<endl;
    //     // 最後應該會縮在某一個區間，從這個最小區間找
    //     int start;
    //     if(right <= 0){
    //         start = 1;
    //     }else{
    //         start = piles[right];
    //     }
    //     long int hours = 0;
    //     cout<<"右邊界"<<piles[left]<<endl;
    //     for(int i = start;i<=piles[left]+1;i++){
    //         hours = 0;
    //         for(int bananas:piles){
    //             hours += (bananas + i - 1) / i;
    //         }
    //         if(hours<=h)
    //             return i;
    //     }
    //     cout<<"hours"<<hours<<endl;
    //     return 0;
    // }
};
