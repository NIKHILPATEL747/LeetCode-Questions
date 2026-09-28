class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for (int n : nums) {
            freq[n]++;  
        }
        
        vector<pair<int,int>> arr;
        for (auto &p : freq) {
            arr.push_back({p.second, p.first});
        }
        
        sort(arr.begin(), arr.end(), [](auto &a, auto &b){
            return a.first > b.first;
        });
        
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(arr[i].second);
        }
        return res;
    }
};