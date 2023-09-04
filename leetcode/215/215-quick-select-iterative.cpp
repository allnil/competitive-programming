const int ZERO = [](){ 
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    return 0;
}();

class Solution {
    void nth_element(vector<int>& a, int first, int need, int last, mt19937 &gen){
    while(true){
        if(first == last){
                    return;
                }

        int key = a[uniform_int_distribution<int>(first, last)(gen)];
        int begin = first;
        int end = last;

        while(begin <= end){
            while(a[begin] < key){
                begin++;
            }
            while(a[end] > key){
                end--;
            }
            if(begin <= end){
                swap(a[begin], a[end]);
                begin++;
                end--;
            }
        }
        if(end + 2 == begin && need == end + 1){
            return;
        }
        if(need <= end){
            last = end;
        } else {
            first = begin;
        }
    }
    }

public:
    int findKthLargest(vector<int>& a, int k) {
       mt19937 gen(
           chrono::high_resolution_clock::now()
           .time_since_epoch().count());
        nth_element(a, 0, a.size() - k, a.size() - 1, gen);
        return a[a.size() - k];
    }
};