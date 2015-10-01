#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <stack>
#include <sstream>
#include <string.h>
#include <utility>
#include <vector>

using namespace std;

class color {
public:
    int R;
    int G;
    int B;
    color(int R = 0, int G = 0, int B = 0);
};

color::color(int R, int G, int B) {
    this->R = R;
    this->G = G;
    this->B = B;
}

color rgb[16];
int getNearest(int R, int G, int B) {
    int min = 0;
    int dist = (R - rgb[0].R) * (R - rgb[0].R) + (G - rgb[0].G) * (G - rgb[0].G) + (B - rgb[0].B) * (B - rgb[0].B);
    for(int i = 1; i < 16; i++) {
        int tmp = (R - rgb[i].R) * (R - rgb[i].R) + (G - rgb[i].G) * (G - rgb[i].G) + (B - rgb[i].B) * (B - rgb[i].B);
        if(tmp < dist) {
            dist = tmp;
            min = i;
        }
    }
    return min;
}

int main() {
    int R;
    int G;
    int B;
    for(int i = 0; i < 16; i++) {
        cin>>R>>G>>B;
        rgb[i] = color(R, G, B);
    }

    while(cin>>R>>G>>B) {
        if(R == -1) {
            break;
        }
        int min = getNearest(R, G, B);
        cout<<"("<<R<<","<<G<<","<<B<<")"<<" maps to ";
        cout<<"("<<rgb[min].R<<","<<rgb[min].G<<","<<rgb[min].B<<")"<<endl;
    }
    return 0;
}
