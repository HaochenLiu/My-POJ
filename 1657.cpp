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

int main() {
    int N;
    cin>>N;
    string start, end;
    int pos[4];
    for(int i = 1; i <= N; i++) {
        cin>>start>>end;
        if(start == end) {
            cout<<"0 0 0 0"<<endl;
        } else {
            pos[0] = start[0] - 'a' + 1;
            pos[1] = start[1];
            pos[2] = end[0] - 'a' + 1;
            pos[3] = end[1];

            /*王*/
            cout<<max(abs(pos[0] - pos[2]), abs(pos[1] - pos[3]))<<" "; 

            /*后*/
            if(pos[0] == pos[2] || pos [1] == pos[3] || pos[0] - pos[1] == pos[2] - pos[3] || pos[0] + pos[1] == pos[2] + pos[3]) {
                cout<<"1"<<" ";
            } else {
                cout<<"2"<<" ";
            }

            /*车*/
            if(pos[0] == pos[2] || pos [1] == pos[3]) {
                cout<<"1"<<" ";
            } else {
                cout<<"2"<<" ";
            }

            /*象*/
            if((pos[0] + pos[1] + pos[2] + pos[3]) % 2 == 1) {
                cout<<"Inf"<<endl;
            } else if(pos[0] - pos[1] == pos[2] - pos[3] || pos[0] + pos[1] == pos[2] + pos[3]) {
                cout<<"1"<<endl;
            } else {
                cout<<"2"<<endl;
            }
        }
    }

    return 0;
}
