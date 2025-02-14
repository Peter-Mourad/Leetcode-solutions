class ProductOfNumbers {
public:
    vector<int> stream, pref, zero;
    ProductOfNumbers() {
        pref = {1};
        zero = {0};
    }
    
    void add(int num) {
        stream.push_back(num);
        pref.push_back(max(num * pref.back(), num));
        zero.push_back(zero.back() + (!num ? 1 : 0));
    }
    
    int getProduct(int k) {
        cout<<zero.back() - zero[zero.size() - k - 1]<<'\n';
        if(zero.back() - zero[zero.size() - k - 1]) return 0;
        if(pref[pref.size() - k - 1])
            return pref.back() / pref[pref.size() - k - 1];
        return pref.back();
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */