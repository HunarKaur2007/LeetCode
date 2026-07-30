class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {

        int n = nums.size();

        vector<int> left(n), right(n);
        stack<int> st;

        // Prefix Sum
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        // Previous Smaller Element
        for (int i = 0; i < n; i++) {

            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();

            if (st.empty())
                left[i] = -1;
            else
                left[i] = st.top();

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();

            if (st.empty())
                right[i] = n;
            else
                right[i] = st.top();

            st.push(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {

            int L = left[i] + 1;
            int R = right[i] - 1;

            long long rangeSum = prefix[R + 1] - prefix[L];

            long long product = rangeSum * nums[i];

            ans = max(ans, product);
        }

        return ans % 1000000007;
    }
};