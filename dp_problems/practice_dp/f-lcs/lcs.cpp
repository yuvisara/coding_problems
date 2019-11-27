#include<bits/stdc++.h>

using namespace std;

const int LEN=1001;

string lcs(string s, string t) {
    int dp[LEN][LEN];
    for(int I=0; I<LEN; I++) {
        for(int J=0; J<LEN; J++) {
        dp[I][J] = 0;
        }
    }
    
    for(int I=0; I<=s.length(); I++) {
        for(int J=0; J<=t.length(); J++) {
            if(J>0 || I>0) {
                if(s[I-1]==t[J-1]) {
                    dp[I][J] = dp[I-1][J-1]+1;
                }
                else {
                    dp[I][J] = max(dp[I-1][J], dp[I][J-1]);
                }
            }
        }
    }
   string result="";
   for(int I=1; I<=s.length(); I++) {
        if(dp[I][t.length()] == (dp[I-1][t.length()]+1)) {
            result += s[I-1];
        }
   }
   return result;
}

//TODO
string lcs_optimized(string s, string t) {
    vector<int> dpt_old(t.length(), 0);
    vector<int> dpt(t.length(), 0);
    
    for(int I=0; I<=s.length(); I++) {
        for(int J=0; J<=t.length(); J++) {
            if(J>0 || I>0) {
                if(s[I-1]==t[J-1]) {
                    dpt[J] = dpt_old[J-1]+1;
                }
                else {
                    dpt[J] = max(dpt_old[J], dpt[J-1]);
                }
            }
        }
        dpt_old = dpt;
    }
   string result="";
   //WA
   for(int I=1; I<=t.length(); I++) {
    if(dpt[I] == (dpt[I-1]+1)) {
        result += t[I-1];
    }
    cout<<dpt[I] <<" ";
   }
   cout<<endl;
   return result;
}



int main() {
    string s, t;
    cin>>s>>t;
    //string result = lcs(s,t);
    string result = lcs_optimized(s,t);
    cout<<result<<endl;
    return 0;
}
