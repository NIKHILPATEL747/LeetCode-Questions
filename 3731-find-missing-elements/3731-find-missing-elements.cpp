class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        
        vector<bool> present(mx - mn + 1, false);
        for (int num : nums) {
            present[num - mn] = true;
        }
        
        vector<int> missing;
        for (int i = mn; i <= mx; i++) {
            if (!present[i - mn]) {
                missing.push_back(i);
            }
        }
        
        return missing;
    }
};
