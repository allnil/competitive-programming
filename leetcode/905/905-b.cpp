const int ZERO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 1;
}();


class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        deque<int> sorted;
       for(int i = 0; i < nums.size(); i++){
           if(nums[i] & 1){
             sorted.push_back(nums[i]);
             continue;
           }
           sorted.push_front(nums[i]);
       }
       for(int i = 0; i < nums.size(); i++){
           nums[i] = sorted.front();
           sorted.pop_front();
       }
       return nums; 
    }
};