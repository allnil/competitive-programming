class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        unordered_map<string, vector<string>> group;

        string original;
        for(auto& s: strs){
           original = s;
           sort(s.begin(), s.end());
           group[s].push_back(original);
        }    

        for(auto& entry: group){
            ans.push_back(entry.second);
        }
        return ans;
    }
};