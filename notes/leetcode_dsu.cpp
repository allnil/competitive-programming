bool compare_vectors(const vector<int>& a, const vector<int>& b){
    return a[0] < b[0];
}

struct DSU {
    vector<int> e;
    DSU(int N) { e = vector<int>(N, -1); }

    // get representive component (uses path compression)
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

    bool same_set(int a, int b) { return get(a) == get(b); }

    int size(int x) { return -e[get(x)]; }

    bool unite(int x, int y) {  
        x = get(x), y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y]; e[y] = x; return true;
    }
};

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end(), compare_vectors);

        DSU dsu(n);

        for (int i = 0; i < logs.size(); i++) {            
            dsu.unite(logs[i][1], logs[i][2]);

            if (dsu.size(0) == n) {
                return logs[i][0];
            }
        }
            
        return -1;
    }
};