/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int, int>> arr; // time, type
        int rooms = 0;
        for(auto it: intervals){
            arr.push_back({it.start, 1});
            arr.push_back({it.end, 0});
        }

        sort(arr.begin(), arr.end());
        int maxi = 0;

        for(auto it: arr){
            if(it.second == 1){
                rooms++;
                maxi = max(rooms, maxi);
            }else{
                rooms--;
            }
        }
        return maxi;
    }
};
