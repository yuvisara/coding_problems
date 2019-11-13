#include<bits/stdc++.h>

using namespace std;

int main() {
    long long N=0, W=0;
    cin>>N>>W;
    
    long long dp[N+1][W+1];

    vector<long long> weight;
    vector<long long> val;
    for(int I=0; I<N; I++) {
        long long wt=0, value=0;
        cin>>wt>>value;
        weight.push_back(wt);
        val.push_back(value);
    }

    for(int I=0; I<=N; I++) {
        for(int w=0; w<=W; w++) {
            if(I==0 || w==0) {
                dp[I][w] = 0;
            }
            else if(weight[I-1] > w) {
                dp[I][w] = dp[I-1][w];
            }
            else {
                dp[I][w] = max(dp[I-1][w-weight[I-1]] + val[I-1] , dp[I-1][w]);   
            }
        }
    }
    
    cout<<dp[N][W]<<endl;

    return 0;
}
