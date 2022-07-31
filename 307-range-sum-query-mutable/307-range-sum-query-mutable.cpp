class NumArray {
public:
    
    int t[120000], n, x[30000];
    void build(int i, int l, int r){
        if(l == r) {
            t[i] = x[l];return;
        }
        int mid = (l + r) / 2;
        build(i * 2 + 1, l, mid);
        build(i * 2 + 2, mid + 1, r);
        t[i] = (t[i * 2 + 1] + t[i * 2 + 2]);
    }
    int query(int i,int l,int r,int s,int e){
        if(l > e || r < s) return 0;
        if(l >= s && r <= e)
            return t[i];
        int mid = (l + r) / 2;
        return (query(i * 2 + 1, l, mid, s, e) + query(i * 2 + 2, mid + 1, r, s, e));
    }
    void update(int i,int l,int r,int pos,int val){
        if(l == r)
            t[i] = val;
        else{
            if(pos <= (l + r) / 2)
                update(i * 2 + 1, l,(l + r) / 2,pos,val);
            else update(i * 2 + 2,(l + r) / 2 + 1, r, pos, val);
            t[i] = (t[i * 2 + 1] + t[i * 2 + 2]);
        }
    }
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        for(int i = 0;i < n;i++)
            x[i] = nums[i];
        build(0,0,n - 1);
    }
    
    void update(int index, int val) {
        update(0,0,n - 1,index,val);
    }
    
    int sumRange(int left, int right) {
        return query(0,0,n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */