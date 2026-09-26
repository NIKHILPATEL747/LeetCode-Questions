class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;
        for (auto &kv : knowledge) mp[kv[0]] = kv[1];
        
        string res, key;
        bool inside = false;
        
        for (char c : s) {
            if (c == '(') {
                inside = true;
                key.clear();
            } else if (c == ')') {
                inside = false;
                res += mp.count(key) ? mp[key] : "?";
            } else {
                if (inside) key += c;
                else res += c;
            }
        }
        return res;
    }
};
