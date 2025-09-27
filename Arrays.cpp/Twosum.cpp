//SUM of arrays and return the index having largest sum :
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

int main() {
    Solution s;
    int n;
    cout << "Enter the size of the array:" << endl;
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter the target:" << endl;
    cin >> target;

    vector<int> result = s.twoSum(nums, target);

    if(!result.empty()) {
        cout << "Indices: ";
        for(int idx : result) {
            cout << idx << " ";
        }
        cout << endl;
    } else {
        cout << "No solution found!" << endl;
    }

    return 0;
}
