const int ZERO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> m;

        for(int i = 0; i < nums.size(); i++){
            int compliment = target - nums[i];
            if(m.contains(compliment)){
                res.push_back(i);
                res.push_back(m[compliment]);
                return res;
            }
            m[nums[i]] = i;
        }

        return res;
    }
};