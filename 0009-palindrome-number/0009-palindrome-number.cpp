class Solution {
    int reverse(int X) {
       long Y = 0;
       while (X > 0) {
          //Extract the last digit
          int digit = X % 10;
          //Appending last digit
          Y = Y * 10 + digit;
          // Shrinking X by discarding the last digit
          X = X / 10;
       }
   return Y;
}
public:
    bool isPalindrome(int x) {
        int y=reverse(x);
        if(x==y)return true;
        return false;
    }
};