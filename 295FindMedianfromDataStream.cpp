class MedianFinder {
    // 存下半
    priority_queue<int> maxHeap;
    // 存上半
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int total = 0;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // cout<<num;
        int lower_max;
        if(total==0){
            minHeap.push(num);
            total++;
            return;
        }
        if(total==1){
            lower_max = INT_MIN;
        }
        else
            lower_max = maxHeap.top();
        int upper_min = minHeap.top();
        if(total%2==0){
            // 讓minheap多一個
            if(num<lower_max){
                maxHeap.pop();
                maxHeap.push(num);
                minHeap.push(lower_max);
            }else{
                minHeap.push(num);
            }
        }else{
            if(num>upper_min){
                minHeap.pop();
                minHeap.push(num);
                maxHeap.push(upper_min);
            }else{
                maxHeap.push(num);
            }
        }
        total++;
    }
    
    double findMedian() {
        // cout<<"find";
        int lower_max;
        int upper_min = minHeap.top();
        if(total>1){
            lower_max = maxHeap.top();
        }
        double output;
        if(total%2==0){
            output = lower_max + upper_min;
            output = output/2;
        }else{
            output = upper_min;
        }
        return output;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
