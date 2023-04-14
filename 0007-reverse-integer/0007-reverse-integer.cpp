class Solution {
public:
    int reverse(int N) {
         long reverse = 0;
        while(N!=0)
        {
            int digit = N%10;
            reverse = reverse*10+digit;
            N = N/10;
        }
        if(reverse>INT_MAX || reverse<INT_MIN)return 0;
        return reverse;
    }
};