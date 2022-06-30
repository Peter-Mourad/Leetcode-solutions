#define ll long long
class Solution {
public:
    bool isPossible(vector<int>& target) {
        ll sum = 0;
        priority_queue<int> q;
        sort(target.begin(), target.end());
        for(int i = 0;i < target.size();i++){
            sum += target[i];
            q.push(target[i]);
            if(i && target[i]==target[i - 1] && target[i]!=1){
                return false;
            }
        }
        while(q.top() != 1){
            int a = q.top(); 
            q.pop();
            sum-=a;
            if(!sum || sum >= a) return false;
            int prev = a % sum;
            if(sum != 1 && !(a % sum)) return false;
            q.push(prev);
            sum += prev;
        }
        
        return true;
    }
};