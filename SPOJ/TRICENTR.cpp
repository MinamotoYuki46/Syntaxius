#include<bits/stdc++.h>
using namespace std;

struct triangle{
    double sideA, centroidA, centroidB, centroidC;
};

int main(){
    int testcase;
    cin >> testcase;

    vector<triangle> dreieck(testcase);

    for (int i = 0; i < testcase; i++){
        cin >> dreieck[i].sideA >> dreieck[i].centroidA >> dreieck[i].centroidB >> dreieck[i].centroidC;
    }
    return 0;
}