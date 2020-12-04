#include<bits/stdc++.h>

using namespace std;
    
bool neverDecrease(long long input) {
    int val = input%10;
    while(input>0) {
        if(val >= (input%10)) {
            val = (input%10);
            input = input/10;
        }
        else {
            return false;
        }
    }

    return true;
}

bool checkDouble(long long input) {
    int prevDigit = input%10;
    input = input/10;

    while(input>0) {
        int val = input%10;
        if(prevDigit == val) {
            return true;
        }
        
        prevDigit = val;
        input = input/10;
    }

    return false;
}

int main() {
    long long min, max;
    cin>>min>>max;
    long long count = 0;
    for(long long I=min; I<=max; I++) {
        if(checkDouble(I) && neverDecrease(I)) {
            cout<<"Found value: "<<I<<endl;
            count++;
        }
    }

    cout<<"Total Count: "<<count<<endl;
}
