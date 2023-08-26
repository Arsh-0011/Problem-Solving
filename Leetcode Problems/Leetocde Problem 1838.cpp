class Solution {
public:
    bool possible(vector<int>&nums,int windowSize,int k){
        long long int currentSum=0;
        for(int i=0;i<windowSize;i++){
            currentSum+=nums[i];
        }
        if(currentSum+k>=(long long)windowSize*nums[windowSize-1]) return true;
        for(int i=windowSize;i<nums.size();i++){
            currentSum=currentSum+nums[i]-nums[i-windowSize];
            if(currentSum+k>=(long long)windowSize*nums[i]) return true;
        }
        return false;
    }
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int low=1,high=nums.size();
        int ans=0;
        while(low<=high){
            int windowSize=low+(high-low)/2;
            if(possible(nums,windowSize,k)){
                ans=max(ans,windowSize);
                low=windowSize+1;                
            }else{
                high=windowSize-1;
            }
            cout<<windowSize<<" "<<ans<<endl;
        }
        return ans;
    }
};