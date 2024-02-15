const int ZERO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class RecentCounter {
    queue<int> q;
public:
    RecentCounter() {
    }
    
    int ping(int t) {
       while(q.empty() == false && q.front() < (t - 3000)){
           q.pop();
       }
       q.push(t);
       return q.size(); 
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */