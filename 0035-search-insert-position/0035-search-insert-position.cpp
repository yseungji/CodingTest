class Solution {
public:
    short searchInsert(vector<int>& nums, short target) {
        short left = 0;
        short right = nums.size()-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid] < target){
                left = mid+1;
            }
            else if(nums[mid] > target){
                right = mid-1;
            }
            else { return mid;}
        }
        return left;
    }
};