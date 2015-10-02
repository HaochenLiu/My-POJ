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

/*
化简为
(n+m+1)(n-m) = 2*N;
实际上就是求N的奇数因子的个数
要分解质因数
*/

struct group {
    double x;
    double y;
    group(double x = 0, double y = 0);
};

group::group(double x, double y) {
    this->x = x;
    this->y = y;
}

int value(group g) {
    int sum = 0;
    double r = (g.x * g.x) + (g.y * g.y);
    if(r <= 3 * 3) {
        sum = 100;
    } else if(r <= 6 * 6) {
        sum = 80;
    } else if(r <= 9 * 9) {
        sum = 60;
    } else if(r <= 12 * 12) {
        sum = 40;
    } else if(r <= 15 * 15) {
        sum = 20;
    }

    return sum;
}

int main() {
    group A[3], B[3];
    int Agrade, Bgrade;
    while(cin>>A[0].x>>A[0].y>>A[1].x>>A[1].y>>A[2].x>>A[2].y>>B[0].x>>B[0].y>>B[1].x>>B[1].y>>B[2].x>>B[2].y) {
        if(A[0].x == -100) {
            break;
        }
    
        Agrade = 0;
        Bgrade = 0;
        for(int i = 0; i < 3; i++) {
            Agrade += value(A[i]);
        }
        for(int i = 0; i < 3; i++) {
            Bgrade += value(B[i]);
        }

        if(Agrade == Bgrade) {
            cout<<"SCORE: "<<Agrade<<" to "<<Bgrade<<", TIE."<<endl;
        } else if(Agrade > Bgrade) {
            cout<<"SCORE: "<<Agrade<<" to "<<Bgrade<<", PLAYER 1 WINS."<<endl;
        } else {
            cout<<"SCORE: "<<Agrade<<" to "<<Bgrade<<", PLAYER 2 WINS."<<endl;
        }
    }

    return 0;
}
