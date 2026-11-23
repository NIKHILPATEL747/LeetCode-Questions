class ProductOfNumbers {
public:
    vector<int> nums;

    ProductOfNumbers() {
        nums.clear();
    }

    void add(int num) {
        nums.push_back(num);
    }

    int getProduct(int k) {
        int p = 1;
        int n = nums.size();
        for (int i = n - k; i < n; i++) {
            p *= nums[i];
        }
        return p;
    }
};