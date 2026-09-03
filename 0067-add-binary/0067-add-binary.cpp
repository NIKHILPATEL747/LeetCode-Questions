class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i = a.size() - 1, j = b.size() - 1, c = 0;
        
        while (i >= 0 || j >= 0 || c) {
            int s = c;
            if (i >= 0) s += a[i--] - '0';
            if (j >= 0) s += b[j--] - '0';
            res.push_back((s % 2) + '0');
            c = s / 2;
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};
