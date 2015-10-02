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
    int speed;
    int time;
    group(int speed = 0, int time = 0);
};

group::group(int speed, int time) {
    this->speed = speed;
    this->time = time;
}

int main() {
    int n;
    while(cin>>n) {
        if(n == -1) {
            break;
        }

        group* a = new group[n]; 
        for(int i = 0; i < n; i++) {
            cin>>a[i].speed>>a[i].time;
        }

        int sum = a[0].speed * a[0].time;
        for(int i = 1; i < n; i++) {
            sum += (a[i].time - a[i - 1].time) * a[i].speed;
        }
        cout<<sum<<" miles"<<endl;
        delete[] a;
    }
    return 0;
}
