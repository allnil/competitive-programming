const int ZERO = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 1;
}();

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> nums_set;
        for(int e: nums){
            if (!nums_set.insert(e).second) {
                return true;
            }
        }
        return false;
    }
};