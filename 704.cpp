class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() -1;

        while(s+1 < e){
            int m = s + (e-s)/2;
            if(nums[m] > target){
                e = m;
            } else if(nums[m] < target){
                s = m;
            } else{                
                return m;
            }
        }

        if (nums[s] == target){
            return s;
        }else if (nums[e] == target){
            return e;
        }

        return -1;
    }
};