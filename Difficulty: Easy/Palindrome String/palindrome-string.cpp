class Solution {
  public:
    bool isPalindrome(string& s) {
        // code here
        int start = 0;
        int end = s.length() - 1;
        
        while(start < end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};