class Solution {
  public:
    vector<int> twoRepeated(vector<int>& arr) {
        // code here
        int n = arr.size() - 2;

        vector<int> freq(n + 1, 0);
        vector<int> ans;

        for (int x : arr) {
            freq[x]++;
            if (freq[x] == 2)
                ans.push_back(x);
        }

        return ans;
    }
};
