class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = 0;
        while( i>=0 && j < n && nums1[i] > nums2[j]){
                swap(nums1[i], nums2[j]);
                i--;
                j++;
        }
        for(int k = m;k<m+n;k++){
             nums1[k] = nums2[k-m];
        }
        sort(nums1.begin(),nums1.end());
    }
};