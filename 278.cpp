// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s = 1;
        int e = n;

        while (s + 1 < e) {
            int m = s + (e - s) / 2;
            if (isBadVersion(m)) {
                e = m;
            } else {
                s = m;
            }
        }

        if (isBadVersion(s)) {
            return s;
        }

        return e;
    }
};