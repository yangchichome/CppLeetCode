class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> arr(26, 0);

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            arr[c - 'a']++;
        }

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (arr[c - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};
