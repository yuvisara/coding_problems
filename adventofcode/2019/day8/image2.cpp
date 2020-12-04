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
    
    
    int height = 6;
    int width = 25;
    int numPixels = height*width;
    int cntPixels = 0;
    

    
    char image[height][width];
    
    for(int I=0; I<height; I++) {
        for(int J=0; J<width; J++) {
            image[I][J] = '2';
        }
    }



    while(cin>>ch) {
        cout<<ch;
        
        int J=cntPixels%width;
        int I=cntPixels/width;
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

        if(image[I][J] == '2') {
            if(ch != '2') {
                image[I][J] = ch;
            }
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
    
    for(int I=0; I<height; I++) {
        for(int J=0; J<width; J++) {
            if(image[I][J] == '1'){
                cout<<"#";
            }
            else {
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
