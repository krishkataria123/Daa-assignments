#include<bits/stdc++.h>
using namespace std;

int solve (int N, vector<int> A) {
    sort(A.begin(),A.end());
    int maxlen=0;
    int l=0;
    int r=0;
    while(r<N){
        if(abs(A[r]-A[l])>10){
            maxlen=max(maxlen,r-l);
            l=r;
            r=r+1;
        }
        else r++;
    }
   return maxlen;
   
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i_A = 0; i_A < N; i_A++)
    {
    	cin >> A[i_A];
    }

    int out_;
    out_ = solve(N, A);
    cout << out_;
}