const int ZERO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        unordered_map<string, vector<string>> group;

        for(auto& s: strs){
           string original = s;
           sort(s.begin(), s.end());
           group[s].push_back(original);
        }    

        for(auto& entry: group){
            ans.push_back(move(entry.second));
        }
        return ans;
    }
};