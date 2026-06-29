class Solution {
public:

    void merge(vector<int>& nums, int low, int mid, int high) {

        vector<int> temp;

        int left = low;
        int right = mid + 1;

        // Compare elements from both halves
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } else {
                temp.push_back(nums[right]);
                right++;
            }
        }

        // Copy remaining elements from left half
        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        // Copy remaining elements from right half
        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        // Copy temp back to original array
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }

    void mergeSort(vector<int>& nums, int low, int high) {

        // Base case
        if (low >= high)
            return;

        int mid = low + (high - low) / 2;

        // Sort left half
        mergeSort(nums, low, mid);

        // Sort right half
        mergeSort(nums, mid + 1, high);

        // Merge both halves
        merge(nums, low, mid, high);
    }

    vector<int> sortArray(vector<int>& nums) {

        mergeSort(nums, 0, nums.size() - 1);

        return nums;
    }
};
