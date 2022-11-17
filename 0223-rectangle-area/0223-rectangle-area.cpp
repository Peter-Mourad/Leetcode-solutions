class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int commonx = 0,commony = 0;
        if(ax2 >= bx1 && ax2 <= bx2)
            commonx = ax2 - max(bx1,ax1);
        else if(bx2 >= ax1 && bx2 <= ax2)
            commonx = bx2 - max(bx1,ax1);
        
        if(ay2 >= by1 && ay2 <= by2)
            commony = ay2 - max(by1,ay1);
        else if(by2 >= ay1 && by2 <= ay2)
            commony = by2 - max(by1,ay1);
        return abs((ax2 - ax1) * (ay2 - ay1)) + 
                abs((bx2 - bx1) * (by2 - by1)) - 
                abs(commonx * commony);
    }
};