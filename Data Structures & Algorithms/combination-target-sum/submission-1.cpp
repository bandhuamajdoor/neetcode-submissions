class Solution {
public:
    void solve(vector<int>& nums, int i, int target, vector<int>& temp, vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(target < 0) return;
        if(i >= nums.size()) return;

        //take
        temp.push_back(nums[i]);
        solve(nums, i, target - nums[i], temp, ans);

        //notTake
        temp.pop_back();
        solve(nums, i + 1, target, temp, ans);

    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        vector<vector<int>> res;
        solve(nums, 0, target, temp, res);

        return res;
    }
};
