class Solution {
public:
    bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
        int xi = 0, yi = 0;
        // first try to get x co-ordinates
        if(xc < x1){
            xi = x1;
        } else if (xc > x2){
            xi = x2;
        }else{
            xi = xc;
        }

        if(yc < y1){
            yi = y1;
        } else if (yc > y2){
            yi = y2;
        }else{
            yi = yc;
        }

        // distance between 2 points = sqrt((x2-x1)^2 + (y2-y1)^2) 
        int dx = abs(xi-xc);
        int dy = abs(yi-yc);
        int d = sqrt((dx)*(dx) + (dy)*(dy));
        if(d>r){
            return false;
        }
        return true;
    }
};