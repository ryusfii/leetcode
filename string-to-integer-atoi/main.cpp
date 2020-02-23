class Solution {
public:
    bool isDigit(const char c) {
        return ('0' <= c && c <= '9');
    }
    
    int myAtoi(string str) {
        int len = 0;
        int pos = 0;
        int sign = 0;
        int res = 0;
        
        for (auto c: str) {
            if (sign == 0 && c == ' ') continue;
            if (sign == 0 && c == '+') {
                sign = 1;
                continue;
            }
            if (sign == 0 && c == '-') {
                sign = -1;
                continue;
            }
            if (sign == 0 && !isDigit(c)) return 0;
            if (sign != 0 && !isDigit(c)) break;
            
            if (res > (INT_MAX - (c - '0')) / 10) {
                return (sign == -1)?INT_MIN:INT_MAX;
            }
            
            if (sign == 0) sign = 1;
            res = res * 10 + (c - '0');
        }
        
        return (sign == -1)?(sign * res):(res);
    }
};
