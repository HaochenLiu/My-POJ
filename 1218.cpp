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

struct comp {
public:
    int i;
    int count;
    int times;
    comp(int i, int count, int times);
};

comp::comp(int i, int count, int times) {
    this->i = i;
    this->count = count;
    this->times = times;
}

int main() {
    int N;
    int tmp;
    cin>>N;
    for(int i = 0; i < N; i++) {
        cin>>tmp;
        cout<<int(sqrt(double(tmp)))<<endl;
    }
    return 0;
}
