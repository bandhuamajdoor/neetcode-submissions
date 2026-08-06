class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> hsh;
        for(int x: nums){
            if(hsh[x] == 1) return true;
            hsh[x]++;
        }
    
        return false;
    }
};