class Solution {
public:
    bool canCross(vector<int>& stones) {
        map<int,set<int>> mp;
        for(int i=0;i<stones.size();i++){
            mp[stones[i]]={};
        }
        mp[0].insert(0);
        for(int i=0;i<stones.size();i++){
            if(mp[stones[i]].empty()) continue;
            for(set<int>::iterator itr=mp[stones[i]].begin();itr!=mp[stones[i]].end();itr++){
                int current=*itr;
                if(mp.find(stones[i]+current)!=mp.end() && stones[i]+current!=stones[i]){
                    mp[stones[i]+current].insert(current);
                }
                if(mp.find(stones[i]+current+1)!=mp.end() && stones[i]+current+1!=stones[i]){
                    mp[stones[i]+current+1].insert(current+1);
                }
                if(mp.find(stones[i]+current-1)!=mp.end() && stones[i]+current-1!=stones[i]){
                    mp[stones[i]+current-1].insert(current-1);
                }
            }
        }
        return !(mp[stones[stones.size()-1]].empty());
    }
};