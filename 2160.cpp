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

struct rec {
    int a;
    int b;
};

int main() {
    rec input[6];
    int tmp1, tmp2;
    for(int i = 0; i < 6; i++) {
        cin>>tmp1>>tmp2;
        if(tmp1 < tmp2) {
            int tmp = tmp1;
            tmp1 = tmp2;
            tmp2 = tmp;
        }
        input[i].a = tmp1;
        input[i].b = tmp2;
    }

    for(int i = 0; i < 5; i++) {
        for(int j = i + 1; j < 6; j++) {
            if(input[i].a < input[j].a) {
                rec tmp = input[i];
                input[i] = input[j];
                input[j] = tmp;
            }
        }
    }

    for(int i = 0; i < 5; i++) {
        for(int j = i + 1; j < 6; j++) {
            if(input[i].a == input[j].a) {
                if(input[i].b < input[j].b) {
                    int tmp = input[i].b;
                    input[i].b = input[j].b;
                    input[j].b = tmp;
                }
            }
        }
    }

    if( input[0].a != input[1].a ||
        input[0].b != input[1].b ||
        input[2].a != input[3].a ||
        input[2].b != input[3].b ||
        input[4].a != input[4].a ||
        input[4].b != input[5].b)
    {
        cout<<"IMPOSSIBLE"<<endl;
    } else {
        if(input[0].a == input[2].a) {
            if(input[0].b == input[4].a && input[2].b == input[4].b) {
                cout<<"POSSIBLE"<<endl;
            } else if(input[0].b == input[4].b && input[2].b == input[4].a) {
                cout<<"POSSIBLE"<<endl;
            } else {
                cout<<"IMPOSSIBLE"<<endl;
            }
        } else if(input[0].a == input[2].b) {
            if(input[0].b == input[4].a && input[2].a == input[4].b) {
                cout<<"POSSIBLE"<<endl;
            } else if(input[0].b == input[4].b && input[2].a == input[4].a) {
                cout<<"POSSIBLE"<<endl;
            } else {
                cout<<"IMPOSSIBLE"<<endl;
            }
        } else {
            cout<<"IMPOSSIBLE"<<endl;
        }
    }
    return 0;
}
