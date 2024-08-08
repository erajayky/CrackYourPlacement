class Solution {
public:
    bool canCross(vector<int>& stones) {
        map<int, map<int, bool>> mp;
        if(stones[1] != 1) return false;
        return util(stones, mp , 1, 1);
    }

    bool util(vector<int> &stones, map<int, map<int, bool>> &mp, int pos, int jump){
        if(pos == stones.back()) return true;
        if(mp.find(pos) != mp.end() && mp[pos].find(jump) != mp[pos].end()) return mp[pos][jump];

        for(int i=jump-1; i<=jump+1; i++){
            if(i>0){
                int nextPos = pos + i;
                if(binary_search(stones.begin(), stones.end(), nextPos) && util(stones, mp, nextPos, i)){
                    return mp[pos][jump] = true;
                }
            }
        }

        return mp[pos][jump] = false;
    }
};