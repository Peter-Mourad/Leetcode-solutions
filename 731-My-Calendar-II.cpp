class MyCalendarTwo {
public:
    map<int, int> overlapping;
    MyCalendarTwo() {
    }
    
    bool book(int start, int end) {
        overlapping[start]++;
        overlapping[end]--;
        int count = 0,mx = 0;
        for(auto it = overlapping.begin(); it!=overlapping.end();it++){
            count += it->second;
            mx = max(mx, count);
        }
        if(mx > 2){
            overlapping[start]--, overlapping[end]++;
            return false;
        }
        return true;
    }
};