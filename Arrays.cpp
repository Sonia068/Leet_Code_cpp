//MEDIAN OF TWO SORTED ARRAYS:
#include <iostream>
using namespace  std;
#include <vector>



class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        
        vector<int>merged(n+m);
        for(int i=0;i<n;i++){
            merged[i]=nums1[i];
        }

          for(int j=0;j<m;j++){
            merged[n+j]=nums2[j];
        }

        for(int i=0;i<merged.size();i++){
            for(int j=i+1;j<merged.size();j++){
            if(merged[i]>merged[j]){
                int temp=merged[i];
                merged[i]=merged[j];
                merged[j]=temp;
            }
        }
    }

          for(int i=0;i<n;i++){
             nums1[i]=merged[i];
        }

        
          for(int j=0;j<m;j++){
             nums2[j]=merged[n+j];
        }
        int l=merged.size();
        double median;
        if(l%2==0){
            median=(merged[l/2-1]+merged[l/2])/2.0;        // in mathematics,median=((l/2)+(l/2)+1))/2
              cout<<"Median:"<<median<<endl;
              return median;
          
            }
        else{
          median=merged[l/2];         // In mathematics ,median= ((l/2)+1)
          cout<<"Median:"<<median<<endl;
          return median;

        }
        return 0;
      }
};

int main() {
    Solution s;
    vector<int> arr1 = {1, 2};
    vector<int> arr2 = {3, 4};

  s.findMedianSortedArrays(arr1, arr2);

  for(int i=0;i<arr1.size();i++){
    cout<<arr1[i]<<" ";
  }

  for(int i=0;i<arr2.size();i++){
    cout<<arr2[i]<<" ";
  }
     //   or
    // for (int num : arr1) {
    //     cout << num << ' ';
    // }

    // for (int num : arr2) {
    //     cout << num << ' ';
    // }
    // cout << endl;

    return 0;
}