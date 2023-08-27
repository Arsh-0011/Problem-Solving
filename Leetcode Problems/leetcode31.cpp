class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index=nums.size()-2;
        while(index>=0 && nums[index]>=nums[index+1]){
            index--;
        }
        if(index<0) sort(nums.begin(),nums.end());
        else{
            for(int i=nums.size()-1;i>=index;i--){
                if(nums[i]>nums[index]){
                    swap(nums[index],nums[i]);
                    break;
                }
            }
            sort(nums.begin()+index+1,nums.end());
        }
    }
};