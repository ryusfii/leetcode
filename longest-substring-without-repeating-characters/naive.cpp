class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;

        int sslen = 1;
        int max = sslen;
        auto ssb = s.cbegin();
        auto sse = next(ssb);
        
        while (sse != s.cend()) {
            if (all_of(ssb, sse, [=](const char c){ return (c != *sse); })) {
                advance(sse, 1);
                ++sslen;
                if (sslen > max) max = sslen;
            } else {
                advance(ssb, 1);
                sse = next(ssb);
                sslen = 1;
            }
        }
        return max;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution().lengthOfLongestSubstring(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
