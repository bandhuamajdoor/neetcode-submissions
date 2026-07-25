class Solution {
public:
    void solve(vector<int>& nums, int i, int xorTillNow, int& sum){
        if(i >= nums.size()){
            sum += xorTillNow;
            return;
        }

        // notTake 
        solve(nums, i + 1, xorTillNow, sum);

        // take
        xorTillNow ^= nums[i];
        solve(nums, i + 1, xorTillNow, sum);
    }

    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        solve(nums, 0, 0, sum);
        return sum;
    }
};