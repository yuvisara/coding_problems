#include<bits/stdc++.h>

using namespace std;

int main() {
    long long T=100;
    
    long long totalFuel=0;
    while(T--) {
        long long val=0;
        cin>>val;
        totalFuel += ((val/3)-2);
    }

    cout<<totalFuel<<endl;

    return 0;
}
