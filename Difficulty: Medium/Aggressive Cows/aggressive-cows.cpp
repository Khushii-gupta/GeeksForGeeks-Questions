class Solution {
  public:
    bool canWePlace(vector<int> &arr, int dist, int k){
        int cntCows = 1, last = arr[0];
        int n = arr.size();
        
        for(int i = 0; i < n; i++){
            if(arr[i] -last >= dist){
                cntCows++;
                last = arr[i];
            }    
            if(cntCows >= k) return true;
        }
        return false;
    }
    
    int aggressiveCows(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int low = 0;
        int high = arr[n -1] - arr[0];
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(canWePlace(arr, mid, k) == true){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return high;
        
    }
};