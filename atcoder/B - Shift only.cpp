#include <stdio.h>
#include <cstring>

// A1, ,,,, AN

int nums[220];

int main(){
  int n; scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &nums[i]);
  }
  
  bool eveness = true;
  int cnt = 0;
  while(eveness){
    for(int i = 0; i < n; i++){
      if(nums[i] & 1) {
        eveness = false;
        break;
      }
      nums[i] = nums[i] / 2;
    }
    if(eveness)
      cnt++;
  }
  printf("%d\n", cnt);
  return 0;
}