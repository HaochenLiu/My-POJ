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

int prime[78498]; //储存素数

void calPrime() {
    bool find = true;
    prime[0] = 2;
    int count = 1;
    for(int i = 3; i < 1000000; i += 2) {
        int tmp = (int)sqrt((double)i);
        find = true;
        for(int j = 3; j <= tmp; j += 2) {
            if(i % j == 0) {
                find = false;
                break;
            }
        }
        if(find) {
            prime[count++] = i;
        }
    }
}

bool search(int n) {
    int low = 0;
    int high = 78497;
    int med = (low + high)/2;
    while(low < high && prime[med] != n) {
        if(n > prime[med]) {
            low = med + 1;
        } else {
            high = med -1;
        }
        med = (low + high) / 2;
    }
    if(n == prime[med]) {
        return true;
    } else {
        return false;
    }
}

/*
歌德巴赫猜想错不了
小于1M，有78498个素数
*/

int main() {
    int n;
    calPrime();
    while(cin>>n) {
        if(n == 0) {
            break;
        }
    
        for(int i = 0; i < 78498; i++) {
            if(search(n - prime[i])) {
                cout<<n<<" = "<<prime[i]<<" + "<<n - prime[i]<<endl;
                break;
            }
        }
    }
    return 0;
}
