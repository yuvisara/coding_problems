#include<bits/stdc++.h>

using namespace std;

int naiveAlgo(vector<int> &tow) {
    //find the number of down towers
    int boundary=0;
    //start with -1
    if(tow[0]== 1) {
        boundary++;
    }

    //end with -1
    if(tow[tow.size()-1] == -1) {
        boundary++;
    }

    if(tow.size() == 2) {
        return boundary;
    }
    
    int after_count=0;
    for(int I=1; I<(tow.size()-1); I++) {
        if(tow[I] == -1) {
            after_count++;
        }
    }
    
    if(after_count == 0) {
        return boundary;
    }

    int before_count=0;
    int minCount=(tow.size()-2)+boundary;
    for(int I=1; I<(tow.size()-1); I++) {
       
       if(tow[I] == -1) {
        before_count++;
        after_count--;
       }
       
       int temp = (I-before_count) + after_count + boundary;
       if(temp < minCount) {
        minCount = temp;
       }
    }
    return minCount;
}

int main() {
    int T=0;
    cin>>T;
    while(T--) {
        int len=0;
        cin>>len;
        vector<int> tow(len);
        for(int I=0; I<len; I++) {
            int temp=0;
            cin>>temp;
            tow[I] = temp;
        }

        int result = naiveAlgo(tow);
        cout<<result<<endl;
    }
    return 0;
}
