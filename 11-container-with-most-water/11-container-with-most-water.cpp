class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        map<int,int> l,r;
        for(int i = 0;i < n;i++){
            r[height[i]] = i + 1;
            if(!l[height[i]])
                l[height[i]] = i + 1;
        }
        auto it = l.end();
        int mn = 1e9,mx = 0;
        int ans = 0;
        while(it!=l.begin()){
            it--;
            if((*it).second < mn)
                mn = (*it).second;
            if(r[(*it).first] > mx)
                mx = r[(*it).first];
            
            if(ans < (mx - mn) * ((*it).first))
                ans = (mx - mn) * ((*it).first);
        }
        return ans;
    }
};