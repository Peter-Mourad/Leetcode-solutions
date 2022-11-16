/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long l = 1,r = n,mid;
        while(l <= r){
            mid = (l + r) / 2;
            int res = guess(mid);
            if(!res)break;
            else if(~res)l = mid + 1;
            else r = mid - 1;
        }
        return mid;
    }
};