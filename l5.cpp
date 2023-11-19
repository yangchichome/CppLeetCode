class Solution {
public:
    string longestPalindrome(string s) {
        string result = "";
        int maxlen = 0;

        for(int i=0; i<s.length(); i++){
            int lenOdd = getLen(s, i, i);
            int lenEven = getLen(s, i, i+1);

            if (lenOdd > maxlen || lenEven > maxlen){
                maxlen = std::max(lenOdd, lenEven);

                if (lenOdd == maxlen){
                    int halflen = maxlen/2;
                    result = s.substr(i-halflen, maxlen);
                }else{
                    int halflen = maxlen/2 - 1; 
                    result = s.substr(i-halflen, maxlen);
                }   
            }
        }
        return result;
    }

    int getLen(const std::string& s, int l, int r) {
    int count = (l == r) ? -1 : 0;
    while (l >= 0 && r < s.length()) {
        if (s[l] == s[r]) {
            count += 2;
            l--;
            r++;
        } else {
            break;
        }
    }
    return count;
}
};