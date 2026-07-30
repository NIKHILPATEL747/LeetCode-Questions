class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        int res = 0;
        if (n == 1)
            return cost[0];
        sort(cost.begin(), cost.end());
        for (int i = n - 1; i >= 0; i--) {
            res += cost[i];
            if (i - 1 < 0)
                break;
            res += cost[i - 1];

            i -= 2;
        }

        return res;
    }
};