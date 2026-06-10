class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n);
        int i=0;
        int j=n-1;
        while(i<=j&&n>0){
            if((nums[i]*nums[i])>=(nums[j]*nums[j])){
                result[n-1]=nums[i]*nums[i];
                i++;
            }
            else{
                result[n-1]=nums[j]*nums[j];
                j--;
            }
            n--;
        }
        return result;
        
    }
};
