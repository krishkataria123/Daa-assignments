#include <iostream>
using namespace std;
#include<vector>
bool valid(int val,vector<int>& arr,int k){
	int curr=0;
	int seg=1;
	int n=arr.size();
	for(int i=0;i<n;i++){
		if((curr|arr[i])<=val){
			curr|=arr[i];
		}
		else {
			seg++;
			curr=arr[i];
		}
	}
	return (seg<=k);
}
int main() {
	int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<int> arr(N);
        for (int i = 0; i < N; i++)
            cin >> arr[i];
		int low=0;
		int high=0;
		for(auto it:arr){
			low=max(it,low);
			high|=it;
		}
		while(low<=high){
			int mid=low+(high-low)/2;
			if(valid(mid,arr,K)){
				high=mid-1;
			}
			else low=mid+1;
		}
		cout<<low<<endl;
	}
	return 0;
}