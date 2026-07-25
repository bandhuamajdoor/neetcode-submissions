class TimeMap {
public:
unordered_map<string, vector<pair<int, string>>> mp;
// priority_queue<pair<int, string>> pq; // max heap having {timestamps, key}
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        const auto& timeValVec = mp[key];
        int low = 0;
        int high = timeValVec.size() - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (timeValVec[mid].first <= timestamp) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans == -1 ? "" : timeValVec[ans].second;
    }
};
