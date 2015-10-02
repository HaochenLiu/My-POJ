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

int reverse(int x) {
    long long lx = x;
    long long res = 0;
    while(lx) {
        res *= 10;
        res += (lx % 10);
        lx /= 10;
        if(res > INT_MAX || res < INT_MIN) {
            return 0;
        }
    }
    return res;
}

int main() {
    int N;
    cin>>N;
    int A;
    int B;
    for(int i = 0; i < N; i++) {
        cin>>A>>B;
        cout<<reverse(reverse(A) + reverse(B))<<endl;
    }
    return 0;
}
