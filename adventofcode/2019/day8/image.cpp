#include<bits/stdc++.h>

using namespace std;

int main() {
    char ch;
    
    int minZero = 10e6+1;
    int minOneCount = 0;
    int minTwoCount = 0;
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;
    
    int numPixels = 25*6;
    int cntPixels = 0;

    while(cin>>ch) {
        cout<<ch;
        cntPixels++;
        if(ch == '0') {
            zeroCount++;
        }
        else if(ch == '1') {
            oneCount++;
        }
        else if(ch == '2') {
            twoCount++;
        }

        if(cntPixels == numPixels) {
            cout<<endl<<zeroCount<<" "<<oneCount<<" "<<twoCount;
            if(zeroCount < minZero) {
                cout<<endl<<"less";
                minZero = zeroCount;
                minOneCount = oneCount;
                minTwoCount = twoCount;
            }
            oneCount = 0;
            twoCount = 0;
            zeroCount = 0;
            cntPixels = 0;
            cout<<endl;
        }
    }
    cout<<endl;
    cout<<"Min: "<<minOneCount<<" "<<minTwoCount<<" "<<minOneCount*minTwoCount<<endl;
    return 0;
}
