class StockSpanner {
public:
    int t[400010];
    int query(int i,int l,int r,int s,int e){
        if(l > e || r < s) return 0;
        if(l >= s && r <= e)
            return t[i];
        int mid = (l + r) / 2;
        return max(query(i * 2 + 1, l, mid, s, e), query(i * 2 + 2, mid + 1, r, s, e));
    }
    void update(int i,int l,int r,int pos,int val){
        if(l == r)
            t[i] = val;
        else{
            if(pos <= (l + r) / 2)
                update(i * 2 + 1, l,(l + r) / 2,pos,val);
            else update(i * 2 + 2,(l + r) / 2 + 1, r, pos, val);
            t[i] = max(t[i * 2 + 1], t[i * 2 + 2]);
        }
    }
    int in = 1;
    StockSpanner() {
    }
    
    int next(int price) {
        update(0,0,1e5,price,in);
        return in++ - query(0,0,1e5,price + 1,1e5);
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */