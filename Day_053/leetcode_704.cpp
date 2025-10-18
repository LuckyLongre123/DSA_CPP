class Solution
{
private:
    int binerySearch(vector<int> &arr, int s, int e, int key)
    {
        if (s > e)
            return -1;

        int mid = s + (e - s) / 2;

        if (arr[mid] == key)
            return mid;

        else if (arr[mid] > key)
            return binerySearch(arr, s, mid - 1, key);
        else
            return binerySearch(arr, mid + 1, e, key);
    }

public:
    int search(vector<int> &nums, int target)
    {
        return binerySearch(nums, 0, nums.size() - 1, target);
    }
};