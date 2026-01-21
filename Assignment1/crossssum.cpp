#include <bits/stdc++.h>
using namespace std;

int crossSum(vector<int>& arr, int l, int mid, int r) {
    int ls=arr[mid];
    for(int i=mid-1;i>=l;i--){
        if(ls+arr[i]>ls) ls=ls+arr[i];
    }
    int rs=arr[mid+1];
    for(int i=mid+2;i<r;i++){
        if(rs+arr[i]>rs) rs=rs+arr[i];
    }
    return ls+rs;
}

int maxSubarray(vector<int>& arr, int l, int r) {
    if(l==r) return arr[l];
    int mid=(l+r)/2;
    int leftsum=maxSubarray(arr,l,mid);
    int rightsum=maxSubarray(arr,mid+1,r);
    int cross=crossSum(arr,l,mid,r);
    return max(leftsum,max(rightsum,cross));
}

int main() {
    vector<int> arr = {-2, -5, 6, -2, -3, 1, 5, -6};
    cout<<"The Max subarray sum is "<<endl;
    cout << maxSubarray(arr, 0, arr.size() - 1);
    return 0;
}
