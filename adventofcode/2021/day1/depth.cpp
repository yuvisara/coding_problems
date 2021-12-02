#include<bits/stdc++.h>

using namespace std;

int main() {
    int num = 0;
    int prevNum = INT_MAX; //set to max so that the first one is not counted
    int count = 0;

    while(cin>>num) {
        if(prevNum < num) count++;
        prevNum = num;
    }
    
    cout<<count<<endl;

    return 0;
}
