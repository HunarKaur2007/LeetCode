class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;

    KthLargest(int K, vector<int>& nums) {
        this->k = K;

        for (int &i : nums) {
            pq.push(i);

            if (pq.size() > k)
                pq.pop();
        }
    }

    int add(int val) {
        pq.push(val);

        if (pq.size() > k)
            pq.pop();

        return pq.top();
    }
};