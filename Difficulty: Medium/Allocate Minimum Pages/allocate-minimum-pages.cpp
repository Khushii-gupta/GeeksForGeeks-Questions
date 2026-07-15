class Solution {
  public:
    bool allocationPossible(vector<int> &arr, long long barrier, int k){
        int allocatedStud = 1;
        long long pages = 0;
        int n = arr.size();
        
        for(int i = 0; i < n; i++){
            if(arr[i] > barrier) return false;
            if(pages + arr[i] > barrier){
                allocatedStud += 1;
                pages = arr[i];
            }
            else{
                pages += arr[i];
            }
            if(allocatedStud > k) return false;
        }
        return true;
    }
    
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(k > n) return -1;
        long long low = *max_element(arr.begin(), arr.end());
        long long ans = -1;
        long long sum = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
        }
        long long high = sum;
        
        while(low <= high){
            long long mid = low + (high - low) / 2;
            if(allocationPossible(arr, mid, k)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return (int)ans;
    }
};