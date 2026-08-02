class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() - 1;
        int i = 0;
        int farthest = nums[0];
        while(i <= n){
            if(i > farthest) return false;

            farthest = max(farthest, i + nums[i]);
            
            if(farthest >= n) return true;
            i++;
        }
    
        return false;
    }
};
