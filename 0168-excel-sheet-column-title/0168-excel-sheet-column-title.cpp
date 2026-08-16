class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        while (columnNumber > 0) {
            columnNumber--; // adjust because 'A' starts at 1, not 0
            int remainder = columnNumber % 26;
            result = char('A' + remainder) + result;
            columnNumber /= 26;
        }
        return result;
    }
};
