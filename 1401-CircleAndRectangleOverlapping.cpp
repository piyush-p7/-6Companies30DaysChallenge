//Question Link: https://leetcode.com/problems/circle-and-rectangle-overlapping/description/
#include <iostream>
using namespace std;

class Solution {
    public:
     bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int close_Xaxis = x1>(x2<xCenter ? x2 : xCenter) ? x1 : (x2<xCenter ? x2 : xCenter);
        int close_Yaxis = y1>(y2<yCenter ? y2 : yCenter) ? y1 : (y2<xCenter ? y2 : xCenter);
        int distanceX = xCenter - close_Xaxis;
        int distanceY = yCenter - close_Yaxis;
        if(distanceX * distanceX + distanceY*distanceY <= radius*radius){
            return true;
        }
        return false;
    }
};

int main(){
    Solution s = Solution();
    cout<<"Circle and Rectangle is overlapping: "<<s.checkOverlap(1, 0, 0, 1, -1, 3, 1);
}