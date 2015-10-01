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

const double pi=acos(-1.0);//NOTES:pi

using namespace std;

int main() {
    int N = 0;
    cin>>N;
    double tmpx;
    double tmpy;
    for(int i = 0; i < N; i++) {
        cin>>tmpx>>tmpy;
        cout<<"Property "<<1 + i<<": This property will begin eroding in year "<<1 + int(pi * (tmpx * tmpx + tmpy * tmpy) / 100)<<"."<<endl;
    }
    cout<<"END OF OUTPUT."<<endl;
    return 0;
}
