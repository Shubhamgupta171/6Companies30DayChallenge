class Solution {
public:
    bool checkOverlap(int r, int x, int y, int x1, int y1, int x2, int y2) {
        x = std::clamp(x, x1, x2) - x;
        y = std::clamp(y, y1, y2) - y;
        return x * x + y * y <= r * r;
    }
};
