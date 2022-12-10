#include<bits/stdc++.h>

using namespace std;

int main() {
	char ch;
	int pos = 0;
	string window = "";
	int windowLength = 14;
	while(cin>>ch) {
		window+=ch;
		pos++;
		if(window.length() == (windowLength + 1)) window.erase(0, 1);
		if(window.length() == windowLength) {
			string temp = window;
			sort(temp.begin(), temp.end());
			bool uniq = true;
			for(int I=1; I<temp.size(); I++) {
				if(temp[I] == temp[I-1]) uniq = false;
			}
			if(uniq == true) {
				cout<<pos<<endl;
				break;
			}
		}
	}
	return 0;
}
