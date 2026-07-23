class Solution {
   public:
    bool isPalindrome(string s) {
        // m1. store all char b/w a to z into another string then check palindrome in this string.
        //  m2 we can also solve it in single traversal compare only alphabate , skip when space or
        //  another char.

        // m2
        int n = s.size();
        int i = 0;
        int j = n - 1;

        while (i <= j) {
            char x = tolower(s[i]);
            char y = tolower(s[j]);
            if (isalnum(x) && isalnum(y)) {
                if (x != y) return false;
                i++;
                j--;
            } else if (!isalnum(x)) {
                i++;
            } else if (!isalnum(y)) {
                j--;
            }
        }
        return true;
    }
};
