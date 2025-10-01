class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         vector<int> arr;
         int n = nums1.size();
         for(int i = 0;i<n;i++){
             arr.push_back(nums1[i]);
         }
         int m = nums2.size();
         for(int i = 0;i<m;i++){
             arr.push_back(nums2[i]);
         }
         sort(arr.begin(),arr.end());
         n = arr.size();
         if(n%2==0){
              return (arr[n/2] + arr[n/2 - 1]) * 0.5;
         }
        return arr[n/2] ;

    }
};