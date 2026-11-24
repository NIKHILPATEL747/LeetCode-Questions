class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            long long hoursSpent = 0;
            
            for (int pile : piles) {
             
                hoursSpent += (long long)(pile + mid - 1) / mid;
            }
            
            if (hoursSpent <= h) {
                right = mid; 
            } else {
                left = mid + 1; 
            }
        }
        
        return left;
    }
};