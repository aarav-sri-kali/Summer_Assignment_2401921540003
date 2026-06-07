class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int key=0;
            for(int i=1;i<nums.size();i++)
            {
                if(nums[i]!=nums[key])
                {
                    key++;
                    nums[key]=nums[i];
                }
            }
            return key+1;
        }
};
