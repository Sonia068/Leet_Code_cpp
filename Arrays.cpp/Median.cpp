// MEDIAN OF TWO SORTED ARRAYS:
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> merged(n + m);

 
        for (int i = 0; i < n; i++) {
            merged[i] = nums1[i];
        }
        for (int j = 0; j < m; j++) {
            merged[n + j] = nums2[j];
        }

        for (int i = 0; i < merged.size(); i++) {
            for (int j = i + 1; j < merged.size(); j++) {
                if (merged[i] > merged[j]) {
                    int temp = merged[i];
                    merged[i] = merged[j];
                    merged[j] = temp;
                }
            }
        }

        for(int i=0;i<n;i++){
            nums1[i]=merged[i];
        }
      
         for(int j=0;j<m;j++){
            nums2[j]=merged[n+j];
        }
      
        int l = merged.size();
        double median;
        if (l % 2 == 0) {
            median = (merged[l / 2 - 1] + merged[l / 2]) / 2.0;   // In mathematics,we can write (n/2+1) and (n/2)
        } else {
            median = merged[l / 2];      // In mathematics,we can write (n/2+1) 
        }
        return median;
    }
};

int main() {
    Solution sol;
    int n, m;

    cout << "Enter the size of first array: ";
    cin >> n;
    vector<int> nums1(n);
    cout << "Enter elements of first array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums1[i];
    }

    cout << "Enter the size of second array: ";
    cin >> m;
    vector<int> nums2(m);
    cout << "Enter elements of second array: ";
    for (int i = 0; i < m; i++) {
        cin >> nums2[i];
    }

    double median = sol.findMedianSortedArrays(nums1, nums2);
    cout << "Median: " << median << endl;

    return 0;
}
