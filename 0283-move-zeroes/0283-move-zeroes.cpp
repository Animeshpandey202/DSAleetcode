class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n=arr.size();
         int k = 0;
  while (k < n) {
    if (arr[k] == 0) {

      break;
    } else {
      k = k + 1;
    }
  }

  //finding zeros and immediate non-zero elements and swapping them
  int i = k;

  for(int j=k+1;j<n;j++) {
    if (arr[j] != 0) {
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i++;

    }

  }
        
    }
};