class MyCalendarThree {
public:
    map<int, int> overlapping;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        overlapping[startTime]++;
        overlapping[endTime]--;
        int count = 0,mx = 0;
        for(auto it = overlapping.begin(); it != overlapping.end(); it++){
            count += it->second;
            mx = max(mx, count);
        }
        return mx;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */