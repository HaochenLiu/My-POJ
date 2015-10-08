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

long long a[10001];

int main() {
    int N;
    cin>>N;

    for(int i = 0; i < N; i++) {
        cin>>a[i];
    }

    sort(a, a + N);

    long long res = 0;
    for(int i = 0; i < N; i++) {
        res += a[i] * (2 * i - N + 1);
    }

    cout<<res * 2<<endl;

    return 0; 
}
