const int ZERO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
    
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // Sort the people
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });

        list<vector<int>> que;
        for (int i = 0; i < people.size(); i++) {
            auto it = que.begin();
            int pos = people[i][1];
            while(pos--) {
                ++it;
            }
            que.insert(it, people[i]);
        }
        return vector<vector<int>>(que.begin(), que.end());
    }
};