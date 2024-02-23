const int ZERO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 1;
}();

class Solution {
public:
    int majorityElement(vector<int>& a) {
        mt19937 gen(2125);
        size_t need = a.size() / 2 + 1;
        while(true){
            int value = a[uniform_int_distribution<size_t>(0, a.size() - 1)(gen)];
            size_t count = 0;
            for(int v: a){
                count += (value == v);
            }
            if(count >= need){
                return value;
            }
        }
    }
};


