class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();

        if (n < m) {
            return -1;
        }

        for(int i=0; i<n-m+1; i++){
            if (haystack[i] == needle[0]){
                for(int j=0; j<m; j++){
                    if(haystack[i+j] != needle[j]){
                        break;
                    }else{
                        if(j == m-1){
                            return i;
                        }
                    }
                }
            }
        }

        return -1;
    }
};