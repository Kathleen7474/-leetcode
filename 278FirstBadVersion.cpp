// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(isBadVersion(1)) 
            return 1;
        long end = n;
        long head = 2;
        long start = n/2;
        if(start==2)
            start = 3;
        bool result = isBadVersion(start);
        bool prev_result = isBadVersion(start-1);
        // cout<<"prev "<<prev_result<<" cur "<<result<<endl;
        while(true){
            if(!prev_result&&result)
                break;
            // cout<<"head "<<head<<" start "<<start<<" end"<<end<<endl;
            // 往前找
            if(result){
                // cout<<"前面"<<endl;
                end = start;
                start = (head+start)/2;
            }else{
                // cout<<"back"<<endl;
                head = start;
                if(start == n-1)
                    start = n;
                else
                    start = (start+end)/2;
            }
            result = isBadVersion(start);
            prev_result = isBadVersion(start-1);
        }

        return start;
    }
};
