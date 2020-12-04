#include<bits/stdc++.h>

using namespace std;


long long getFuel(long long val) {
    long long totFuel = 0;
    
    val = ((val/3)-2);
    while(val > 0) {
        totFuel += val;
        val = ((val/3)-2);
    }
    return totFuel;
}


int main() {
    long long T=100;
    
    long long totalFuel=0;
    while(T--) {
        long long val=0;
        cin>>val;
        totalFuel += getFuel(val);
    }

    cout<<totalFuel<<endl;

    return 0;
}
