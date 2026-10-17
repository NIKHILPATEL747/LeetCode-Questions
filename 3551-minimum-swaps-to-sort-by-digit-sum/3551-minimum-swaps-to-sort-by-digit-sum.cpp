class Solution {
private:
    // Helper to calculate the sum of digits of a number
    int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
      
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end(), [this](int a, int b) {
            int sumA = getDigitSum(a);
            int sumB = getDigitSum(b);
            if (sumA != sumB) {
                return sumA < sumB; 
            }
            return a < b; 
        });
        
      
        unordered_map<int, int> targetIndex;
        for (int i = 0; i < n; ++i) {
            targetIndex[sortedNums[i]] = i;
        }
        
    
        vector<bool> visited(n, false);
        int totalSwaps = 0;
        
        for (int i = 0; i < n; ++i) {
        
            if (visited[i] || targetIndex[nums[i]] == i) {
                continue;
            }
          
            int cycleSize = 0;
            int currentPos = i;
            while (!visited[currentPos]) {
                visited[currentPos] = true;
                currentPos = targetIndex[nums[currentPos]];
                cycleSize++;
            }
            
            
            if (cycleSize > 1) {
                totalSwaps += (cycleSize - 1);
            }
        }
        
        return totalSwaps;
    }
};