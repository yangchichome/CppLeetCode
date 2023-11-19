class Solution {
public:
    int longestPalindrome(string s) {
        int cnt[126];
        int OddCount = 0;
        int ans = 0;

        memset(cnt, 0, sizeof(cnt));

        for(char c: s){
            cnt[c- 'A']++;
        }

        for (int i=0; i<126; i++){
            ans+=cnt[i]/2 * 2;
            if(cnt[i] % 2){
                OddCount = 1;
            }
        }

        ans+= OddCount;

        return ans;
    }
};