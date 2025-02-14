#include <cmath>
#include <algorithm>

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minutesAngle = minutes * 6;
        double hourAngle = ( hour%12 + minutes/60.0 )* 30;
        double diff = std::abs(hourAngle - minutesAngle);
        return std::min(diff, 360 - diff);
    }
};
