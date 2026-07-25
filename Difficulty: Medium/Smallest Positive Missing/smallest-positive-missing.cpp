class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        int n = arr.size();

        vector<bool> present(n + 2, false);

        for (int x : arr) {
            if (x > 0 && x <= n + 1) {
                present[x] = true;
            }
        }

        for (int i = 1; i <= n + 1; i++) {
            if (!present[i]) {
                return i;
            }
        }

        return n + 1;
    }
};