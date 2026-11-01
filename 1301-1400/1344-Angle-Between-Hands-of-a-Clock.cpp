class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour = hour % 12;

        double minute_angle = minutes * 6.0;
        double hour_angle = (hour * 30.0) + (minutes * 0.5);

        double diff = std::abs(hour_angle - minute_angle);

        return min(diff, 360.0 - diff);
    }
};