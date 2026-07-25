class Solution {
public:
    int bs(vector<int>& nums, int start, int end, int target){
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > target){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int low = 0;
        int n = nums.size();
        int high = n - 1;
        //finding index to min element
        while(low < high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > nums[high]){
                low = mid + 1;
            }else{
                high = mid;
            }
        }
    
        int minIdx = high;
        // now search for target in 0 to minIdx -1 and minIdx to n - 1
        int v1 = bs(nums, 0, minIdx - 1, target);
        int v2 = bs(nums, minIdx, n - 1, target);

        if(v1 != -1) return v1;
        if(v2 != -1) return v2;

        return -1; 
    }
};
