#include<bits/stdc++.h>

using namespace std;

int INF=10e6+1;
class Point {
    public:
    int x;
    int y;
    Point(int xx, int yy): x(xx), y(yy) {}
    int getSlope(Point p) {
        if(p.x == x) {
            return INF;
        }
        else {
            double slope = (p.y-y)/(p.x-x);
            slope = abs(slope)*100;
            return (int)slope;
        }
    }
};


int main() {
    string line;
    vector<Point> map;
    int I=0;
    while(cin>>line) {
        int J=0;
        for(char ch: line) {
            if(ch == '#') {
                Point p(I, J);
                map.push_back(p);       
            }
            J++;
        }
        I++;
        cout<<line<<endl;
    }
    
    int maxNum = 0;
    for(int I=0; I<map.size(); I++) {
        unordered_map<int, bool> slopeMap;
        for(int J=0; J<map.size(); J++) {
            if(I!=J) {
                    slopeMap[map[I].getSlope(map[J])] = true;
                }
            }
        if(maxNum < slopeMap.size()) {
            maxNum = slopeMap.size();
        }

        cout<<slopeMap.size()<<endl;
    }

    cout<<"Max number: "<<maxNum<<endl;

    return 0;
}
