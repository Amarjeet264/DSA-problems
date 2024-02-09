class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hangle= ((hour%12)/12.0)*360.0 + 0.5*minutes; 
        double mangle= (minutes/60.0)*360.0;
        double ans=abs(mangle-hangle);
        return min(ans, 360.0-ans);
    }
};