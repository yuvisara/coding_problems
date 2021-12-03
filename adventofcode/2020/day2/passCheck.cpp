#include<bits/stdc++.h>

using namespace std;

int isValidPass(int start, int end, char ch, string str) {
   int count = 0; 
   for(int I=0; I< str.length(); I++) {
    if(str[I] == ch) count++;
   }
    if(count >= start && count<= end) return 1;
    return 0;
}

int isValidPass2(int start, int end, char ch, string str) {
    start--;
    end--;

    if(start >=0 && start <= str.length() &&
        end >= 0 && end <= str.length()) {
            if(str[start] == ch && str[end] == ch) return 0;
            if(str[start] == ch && str[end] != ch) return 1;
            if(str[start] != ch && str[end] == ch) return 1;
        }
    return 0;
}

int main() {
    string limit;
    int count = 0;
    while(cin>>limit) {
        string mid;
        string str;
        cin>>mid>>str;
        
        int start=0, end=0;
        char ch;
        sscanf(limit.c_str(), "%d-%d", &start, &end);
        sscanf(mid.c_str(), "%c:", &ch);
        count += isValidPass2(start, end, ch, str);
        cout<<str<<endl;
    }
    cout<<count<<endl;
    return 0;
}
