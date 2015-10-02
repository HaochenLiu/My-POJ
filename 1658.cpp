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
    int pos[4];
    for(int i = 1; i <= N; i++) {
        cin>>pos[0]>>pos[1]>>pos[2]>>pos[3];
        cout<<pos[0]<<" "<<pos[1]<<" "<<pos[2]<<" "<<pos[3]<<" ";
        if(pos[0] + pos[2] == 2*pos[1]) {
            cout<<2 * pos[3] - pos[2]<<endl;
        } else {
            cout<<pos[3] * pos[3] / pos[2]<<endl;
        }
    }

    return 0;
}
