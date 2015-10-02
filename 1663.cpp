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
    int x;
    int y;
    for(int i = 1; i <= N; i++) {
        cin>>x>>y;
        if(x == y) {
            cout<<2 * y - y % 2<<endl;
        } else if(x - 2 == y) {
            cout<<2 * x - 2 - y % 2<<endl;
        } else {
            cout<<"No Number"<<endl;
        }
    }
    return 0;
}
