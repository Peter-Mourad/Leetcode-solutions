class MedianFinder {
public:
    int cnt = 0,num2;
    multiset<int> f, s;
    MedianFinder() {
        
    }
    // try to make first half holds (cnt + 1) / 2 elements
    // and second half holds cnt / 2 elements
    void addNum(int num) {
        cnt++;
        if(f.size() < (cnt + 1) / 2){
            if(s.empty()){
                f.insert(num);
            }
            else{
                auto it = s.begin();
                num2 = *it;
                if(num2 < num){
                    s.erase(it);
                    f.insert(num2);
                    s.insert(num);
                }
                else 
                    f.insert(num);
            }
        }
        else{ 
            auto it = f.end();
            it--;
            num2 = *it;
            if(num2 > num){
                f.erase(it);
                f.insert(num);
                s.insert(num2);
            }
            else
                s.insert(num);
        }
    }
    
    double findMedian() {
        if(cnt & 1){
            auto it = f.end();
            it--;
            return double(*it);
        }
        else{
            auto it = f.end();
            it--;
            auto it2 = s.begin();
            double ans = *it + *it2;
            return ans / 2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */