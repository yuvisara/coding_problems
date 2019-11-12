#include<bits/stdc++.h>

using namespace std;

int main() {
    int N=0;
    vector<int> height;
    
    cin>>N;
    for(int I=0; I<N; I++) {
        int temp=0;
        cin>>temp;
        height.push_back(temp);
    }

    vector<int> cost(N);
    cost[1] = abs(height[0] - height[1]);
    for(int I=2; I<N; I++) {
        cost[I] = min((cost[I-1] + abs(height[I-1]-height[I])) ,(cost[I-2]+abs(height[I-2]-height[I])));
    }

    cout<<cost[N-1]<<endl;


    return 0;
}
