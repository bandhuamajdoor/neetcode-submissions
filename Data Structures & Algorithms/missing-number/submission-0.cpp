class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total_XOR = 0;
        int arr_XOR = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            total_XOR ^= i;
            arr_XOR ^= nums[i];
        }
        total_XOR ^= nums.size();

        return arr_XOR ^ total_XOR;

    }
};
