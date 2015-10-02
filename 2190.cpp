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
        int pos = 0;
        int sum = 0;
        for(int i = 0; i < 10; i++) {    
            if(s[i] == '?') {
                pos = 10 - i;
                s[i] = '0';
            }
            
            if(s[i] >= '0' && s[i] <= '9') {
                sum += (10 - i) * (s[i] - '0');
            } else if(s[i] == 'x' || s[i] == 'X') {
                sum += (10 - i) * 10;
            }
        }
    
        sum %= 11;
        bool find = false;
        for(int i = 0; i <= 10; i++) {
            if((sum + i * pos) % 11 == 0) {
                find = true;
                if(pos == 1 && i == 10)                {
                    cout<<'X'<<endl;
                } else if(i == 10) {
                    cout<<"-1"<<endl;
                } else {
                    cout<<i<<endl;
                }
                break;
            }
        }
        if(!find) {
            cout<<"-1"<<endl;
        }
    }

    return 0;
}
