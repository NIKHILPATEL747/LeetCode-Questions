class ProductOfNumbers {
public:
    vector<int> nums; // stores cumulative products since the last zero
    int n;

    ProductOfNumbers() {
        nums.clear();
        n = 0;
    }

    void add(int num) {
        if (num == 0) {
            nums = {};
            n = 0;
        } else {
            if (nums.empty()) {
                nums.push_back(num);
            } else {
                nums.push_back(nums[n - 1] * num);
            }
            n++;
        }
    }

    int getProduct(int k) {
        if (k > n) {
            return 0;
        }
        if (k == n) {
            return nums[n - 1];
        }
        return nums[n - 1] / nums[n - 1 - k];
    }
};