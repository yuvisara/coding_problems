#include<bits/stdc++.h>
//For each day there are three possibilities that we can endup with a or b or c
//At each state we go to these states with maximum weight there by end up with max weight at the last day
using namespace std;

int main() {
    int N=0;
    cin>>N;
    
    vector<int> day(3);
    vector<int> prevDayCost(3);
    while(N--) {
        cin>>day[0]>>day[1]>>day[2];
        vector<int> costDay(3);
        for(int I=0; I<3; I++) {
            for(int J=0; J<3; J++) {
                if(I!=J) {
                    costDay[I] = max(costDay[I], (prevDayCost[J]+day[I]));
                }
            }
        }
       prevDayCost = costDay;
    }

    cout<<max(prevDayCost[0], max(prevDayCost[1], prevDayCost[2]))<<endl;

    return 0;
}
