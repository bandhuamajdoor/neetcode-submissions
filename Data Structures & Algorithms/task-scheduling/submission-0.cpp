class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> hsh(26, 0);
        for(char c: tasks){
            hsh[c - 'A']++;
        }

        priority_queue<int> pq; // freq

        for(int i = 0; i < 26; ++i){
            if(hsh[i] != 0) pq.push(hsh[i]);
        }

        int time = 0;
        queue<pair<int, int>> q; // {remFreq, nextAvailableTime}
        while(!pq.empty() || !q.empty()){
            // increment time
            time++;

            // if some task is in queue and is available bring to priority_queue
            while(!q.empty() && q.front().second <= time){
                pq.push({q.front().first});
                q.pop();
            }
            
            // remaining tasks that can be performed in is in queue so select the one with the max freq
            // for this particular CPU cycle
            if(!pq.empty()){
                int freq = pq.top();
                pq.pop();
                int remaining = freq - 1;
                if(remaining > 0){
                    q.push({remaining, time + n + 1});
                }
            }
        
        }

        return time;
    }
};
