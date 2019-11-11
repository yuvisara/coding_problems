#include<bits/stdc++.h>

using namespace std;

int main() {
    int N=0,K=0;
    cin>>N>>K;

    vector<int> height(N);
    for(int I=0; I<N; I++) {
        int temp=0;
        cin>>temp;
        height[I] = temp;
    }

    vector<int> cost(N);

    cost[1] = abs(height[0]-height[1]);

    for(int I=2; I<N; I++) {
       int minm = cost[I-1] + abs(height[I]-height[I-1]);
       for(int J=1; J<=K && (I-J) >= 0 ; J++) {
            minm = min(cost[I-J] + abs(height[I] - height[I-J]), minm);
       }
       cost[I] = minm;
    }

    cout<<cost[N-1]<<endl;

    return 0;
}
