class MyCalendar {
public:
    set<pair<int,int>> free;
    MyCalendar() {
        free.insert({0,1e9});
    }
    
    bool book(int start, int end) {
        auto s = free.lower_bound({start + 1, 0});
        if(s==free.begin())return false;
        s--;
        pair<int,int> temp = *s;
        if(temp.second < end - 1)return false;
        free.erase(s);
        if(temp.first <= start - 1)
            free.insert({temp.first, start - 1});
        if(end <= temp.second)
            free.insert({end, temp.second});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */