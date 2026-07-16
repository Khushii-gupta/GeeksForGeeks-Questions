class Solution {
  public:
    int needed(vector<int> &stations, double dist) {
    int cnt = 0;
    int n = stations.size();

    for (int i = 0; i < n - 1; i++) {
        double gap = stations[i + 1] - stations[i];
        cnt += (int)ceil(gap / dist) - 1;
    }

    return cnt;
   }
    
    double minMaxDist(vector<int> &stations, int K) {
        // Code here
        sort(stations.begin(), stations.end());
        int n = stations.size();
        double low = 0;
        double high = stations[n - 1] - stations[0];
        
        while(high - low > 1e-6){
            double mid = low + (high - low) / 2;
            int cnt = needed(stations, mid);
            if(cnt > K){
                low = mid;
            }
            else{
                high = mid;
            }
        }
        return low;
    }
};