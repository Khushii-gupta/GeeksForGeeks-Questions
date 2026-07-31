class Solution {
  public:
    bool ternarySearch(vector<int> &arr, int x) {
        // code here
        int low = 0;
        int high = arr.size() - 1;

        while (low <= high) {
            int mid1 = low + (high - low) / 3;
            int mid2 = high - (high - low) / 3;

            if (arr[mid1] == x)
                return true;

            if (arr[mid2] == x)
                return true;

            if (x < arr[mid1]) {
                high = mid1 - 1;
            }
            else if (x > arr[mid2]) {
                low = mid2 + 1;
            }
            else {
                low = mid1 + 1;
                high = mid2 - 1;
            }
        }
        return false;
    }
};