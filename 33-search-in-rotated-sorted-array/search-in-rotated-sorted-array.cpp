class Solution {
    int pivot(vector<int> &arr) {
        int n = arr.size();
        int s = 0, e = n - 1, mid;
        while (s < e) {
            mid = s + (e - s) / 2;
            if ( mid<e && arr[mid] > arr[mid + 1]) {
                return mid; 
            } 
            else if( mid>s && arr[mid] < arr[mid - 1] ){
                return mid-1;
            }
            else if(arr[s]>= arr[mid]){
                e = mid-1;
            }
            else if(arr[s]<arr[mid]){
                s = mid + 1;
            }
        }
        return -1;
    }
public:
    int search(vector<int>& arr, int target) {
        int peak = pivot(arr);

      
        int s = 0, e = peak, mid;
        while (s <= e) {
            mid = s + (e - s) / 2;
            if (arr[mid] > target) {
                e = mid - 1;
            } else if (arr[mid] < target) {
                s = mid + 1;
            } else {
                return mid;
            }
        }

      
        s = peak + 1;
        e = arr.size() - 1;
        while (s <= e) {
            mid = s + (e - s) / 2;
            if (arr[mid] > target) {
                e = mid - 1;
            } else if (arr[mid] < target) {
                s = mid + 1;
            } else {
                return mid;
            }
        }

        return -1;
    }
};