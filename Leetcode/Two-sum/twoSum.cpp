#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    // copy array 'nums' to temporary array 'arr'
    vector<int> arr = nums;
    sort(arr.begin(), arr.end());
    int low = 0, high = n - 1;
    int first = -1, second = -1; // values of answer

    while (low < high) {
        if (arr[low] + arr[high] == target) {
            first = arr[low];
            second = arr[high];
            break;
        } else if ((arr[low] + arr[high]) < target)
            low++;
        else
            high--;
    }

    int res1 = -1, res2 = -1;
    // find the indices of the first and second number in the real array

    for (int i = 0; i < n; i++) {
        if (nums[i] == first) {
            res1 = i;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (nums[i] == second && i != res1) {
            res2 = i;
            break;
        }
    }
    vector<int> res  = {res1, res2};
    return res;
}

int main() {
    vector<int> v = {1, 3, 4, 6, 7, 8, 9};
    int target = 4;
    vector<int> ans = twoSum(v, target);

    // Output the result
    cout << "Result: ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
