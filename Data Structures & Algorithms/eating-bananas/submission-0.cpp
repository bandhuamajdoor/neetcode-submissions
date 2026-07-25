class Solution {
public:
    bool check(vector<int>& piles, int h, long long k){
        if(piles.size() > h){
            return false;
        }

        int hours = 0;
        for(int i = 0; i < piles.size(); ++i){
            hours += ((piles[i] + k - 1) / k);
            if(hours > h) return false;
        }
    
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1;
        long long high = 1e9;
        while(low < high){
            long long mid = low + (high - low)/2;

            if(check(piles, h, mid)){
                high = mid;
            }else{
                low = mid + 1;
            }
        }
    
        return high;
    }
};
