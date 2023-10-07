const int ZERO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;
        for (auto& n : nums) {
            frequency[n]++;
        }
        unordered_map<int, vector<int>> buckets;

        for(auto entry: frequency){
            int freq = entry.second;
            int el = entry.first;
            buckets[freq].push_back(el);
        }

        vector<int> freq;
        for(auto entry: buckets){
            freq.push_back(entry.first);
        }

        sort(freq.rbegin(), freq.rend());

        vector<int> ans;
        for(int f: freq){
            for(int key: buckets[f]){
                ans.push_back(key);
                if((int)ans.size() == k){
                    return ans;
                }
            }
        }
        return ans;
    }
};