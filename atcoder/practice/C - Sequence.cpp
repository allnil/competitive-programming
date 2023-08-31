#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int ZERO = []{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

int main(){
  int N;
  cin >> N;
  vector<ll>  A(N);

  for(int i = 0; i < N; i++){
    cin >> A[i];
  }

  ll sum_positive = 0, sum_negative = 0, tot_op_positive = 0, tot_op_negative = 0;

  for(int i = 0; i < N; i++){
    sum_positive += A[i];
    sum_negative += A[i];

    if( i % 2 == 0 ){
      if(sum_positive <= 0){
        tot_op_positive += abs(sum_positive) + 1;
        sum_positive = 1;
      }
      if(sum_negative >= 0 ){
        tot_op_negative += abs(sum_negative) + 1;
        sum_negative = -1;
      }
    } else {
      if(sum_positive >= 0){
        tot_op_positive += abs(sum_positive) + 1;
        sum_positive = -1;
      }
      if(sum_negative <= 0){
        tot_op_negative += abs(sum_negative) + 1;
        sum_negative = 1;
      }
    }
  }

  cout << min(tot_op_negative, tot_op_positive) << endl;
  return 0;
}
