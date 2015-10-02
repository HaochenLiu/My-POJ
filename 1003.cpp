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
    string s;
    while(cin>>s) {
        if(s == "0.00") {
            break;
        }
        int m = (s[0] - '0') * 100 + (s[2] - '0') * 10 + (s[3] - '0');
        double val = 0.0;
        for(int i = 2; i <= 300; i++) {
            val += (double)1 / (double)i;
            if(val * 100 >= (double)m) {
                cout<<i - 1<<" card(s)"<<endl;
                break;
            }
        }
    }

    return 0;
}
