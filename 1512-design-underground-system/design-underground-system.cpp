#include <unordered_map>
#include <string>
#include <utility>
#include <map>
using namespace std;

class UndergroundSystem {
    // Map to store check-in information: id -> (start station, time)
    unordered_map<int, pair<string, int>> checkIns;
    // Map to store total time and count for each start-end station pair: (start, end) -> (total time, count)
    map<pair<string, string>, pair<double, int>> tripStats;

public:
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        checkIns[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        // Find the corresponding check-in information
        auto checkInInfo = checkIns[id];
        checkIns.erase(id); // Remove the check-in information once checked out
        
        // Calculate the duration of the trip
        int duration = t - checkInInfo.second;
        
        // Update the total time and count for this start-end station pair
        pair<string, string> stations = make_pair(checkInInfo.first, stationName);
        tripStats[stations].first += duration;
        tripStats[stations].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        // Calculate the average time for the given start-end station pair
        pair<string, string> stations = make_pair(startStation, endStation);
        auto tripInfo = tripStats[stations];
        return tripInfo.first / tripInfo.second;
    }
};
