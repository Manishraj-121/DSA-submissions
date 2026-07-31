class Solution {
public:
    bool isPresent(unordered_map<char, int>& hash1,
                   unordered_map<char, int>& hash) {
        for (auto &it : hash1) {
            if (hash[it.first] != it.second)
                return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        if (m > n) return false;

        unordered_map<char, int> hash1;
        unordered_map<char, int> hash;

        // Frequency of s1
        for (char c : s1)
            hash1[c]++;

        int i = 0, j = 0;

        while (j < n) {
            // Add current character to window
            hash[s2[j]]++;
            j++;

            // Keep window size equal to m
            while (j - i > m) {
                hash[s2[i]]--;
                if (hash[s2[i]] == 0)
                    hash.erase(s2[i]);
                i++;
            }

            // Check when window size is exactly m
            if (j - i == m && isPresent(hash1, hash))
                return true;
        }

        return false;
    }
};