class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = ((nums1.size() + nums2.size()) / 2) + 1;
        bool odd = (nums1.size() + nums2.size()) % 2;
        vector<int> nums(2, 0);
        int i1 = 0;
        int i2 = 0;
        
        for (int i = 0; i<size; i++) {
            if (i1 >= nums1.size()) {
                nums.at(i%2) = nums2.at(i2++);
            } else if (i2 >= nums2.size()) {
                nums.at(i%2) = nums1.at(i1++);
            } else if (nums1.at(i1) < nums2.at(i2)) {
                nums.at(i%2) = nums1.at(i1++);
            } else {
                nums.at(i%2) = nums2.at(i2++);
            }
        }
        
        if (odd)
            return nums.at((size+1)%2);
        else
            return ((double)nums.at(0) + (double)nums.at(1)) / 2;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);
        
        double ret = Solution().findMedianSortedArrays(nums1, nums2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
