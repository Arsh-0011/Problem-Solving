class Solution {
public:
    void findAns(vector<int>&nums,vector<vector<int>>&ans,vector<int>&current){
        if(current.size()==nums.size()){
            ans.push_back(current);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==11) continue;
            int temp=nums[i];
            current.push_back(nums[i]);
            nums[i]=11;
            findAns(nums,ans,current);
            current.pop_back();
            nums[i]=temp;
        }
    } 
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>current;
        findAns(nums,ans,current);
        return ans;
    }
};