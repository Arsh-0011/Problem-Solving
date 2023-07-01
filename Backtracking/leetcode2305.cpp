class Solution {
public:
    int ans=INT_MAX;

    void performBacktracking(vector<int>&cookies,int currentIndex,vector<int>&temp,int k){
        
        if(currentIndex==cookies.size()){
            int currentAns=INT_MIN;
            for(int i=0;i<k;i++){
                currentAns=max(currentAns,temp[i]);
            }
            ans=min(currentAns,ans);
            return;
        }
        for(int i=0;i<k;i++){
            temp[i]+=cookies[currentIndex];
            performBacktracking(cookies,currentIndex+1,temp,k);
            temp[i]-=cookies[currentIndex];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>storeCookies(k,0);
        performBacktracking(cookies,0,storeCookies,k);
        return ans;
    }
};