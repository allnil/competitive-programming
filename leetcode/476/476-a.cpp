class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        int bit = 0;

        while(num != 0){
            ans |= ((num & 1) ^ 1) << bit;
            num >>= 1;
            bit++;
        }
        return ans;
    }
};