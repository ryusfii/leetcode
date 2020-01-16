class Solution {
public: 
    string longestPalindrome(string s) {
        int size = s.size();
        int maxr = 0;
        int maxl = 0;
        
        for (int i = 0; i < size - 1; i++) {
            for (int o = 0; o < 2; o++) {
                int l = i;
                int r = i + o;
            
                while (0 <= l && l <= r && r < size && s.at(l) == s.at(r)) {
                    cout << "Checking: " << s.substr(l, r - l + 1) << endl;
                    if (maxr - maxl < r - l) {
                        cout << "Found: " << s.substr(l, r - l + 1) << endl;
                        maxr = r;
                        maxl = l;
                    }
                    l--;
                    r++;
                }    
            }
        }
        return s.substr(maxl, maxr - maxl + 1);
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
        
        string ret = Solution().longestPalindrome(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
