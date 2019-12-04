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

    int count = 0;
    while(input>0) {
        int val = input%10;
        
        if(prevDigit == val) {
            count++;
        }
        else {
            //adjacent digits are different
            //if the previously encountered group is 2 return else continue
            if(count == 1) {
                return true;
            }
            count = 0;
        }
        prevDigit = val;
        input = input/10;
    }
    
    //if the last two digits is a double group return true
    if(count == 1) {
        return true;
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
