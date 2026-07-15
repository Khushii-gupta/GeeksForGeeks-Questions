class Solution {
  public:
    int time(vector<int>& arr, long long painter, int k){
        int count = 1;
        long long allPaint = 0;
        
        for(int x : arr){
            if(x > painter){
                return false;
            }
            if(allPaint + x > painter){
                count++;
                allPaint = x;
            }
            else{
                allPaint += x;
            }
            if(count > k){
                return false;
            }
        }
        return true;
    }
    
    int minTime(vector<int>& arr, int k) {
        // code here
        long long low = *min_element(arr.begin(), arr.end());
        int n = arr.size();
        long long sum = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
        }
        long long high = sum;
        
        while(low <= high){
            long long mid = low + (high - low) / 2;
            if(time(arr, mid, k)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return (int)low;
    }
};