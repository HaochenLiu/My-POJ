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
    int factor;
    int exp;
    group(int factor, int exp);
};

group::group(int factor, int exp) {
    this->factor = factor;
    this->exp = exp;
}

int main() {
    int n;
    vector<group> l;
    while(cin>>n) {
        l.clear();
        while(n % 2 == 0) {
            n /= 2;
        }

        int factor = 1;
        int exp = 0;
        while(n != 1) {
            int max = (int)sqrt((double)n);
            if(factor <= max + 1) {
                factor += 2;
            } else {
                factor = n;
            }

            exp = 0;
            while(n % factor == 0) {
                n /= factor; 
                exp++;
            }
            l.push_back(group(factor, exp));
        }

        int total = 1;
        vector<group>::iterator it = l.begin();
        while(it != l.end()) {
            total *= ((*it).exp + 1);
            it++;
        }
        cout<<total<<endl;
    }

    return 0;
}
