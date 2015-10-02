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

bool same(int* a, int n) {
    for(int i = 1; i < n; i++) {
        if(a[i] != a[0]) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    while(cin>>N) {
        if(N == 0) {
            break;
        }

        int* a = new int[N];
        int* tmp = new int[N];
        for(int i = 0; i < N; i++) {
            cin>>a[i];
        }

        int count = 0;
        while(!same(a, N)) {
            count++;
            for(int i = 0; i < N; i++) {
                tmp[i] = a[i] / 2;
            }

            for(int i = 1; i < N; i++) {
                a[i] = tmp[i] + tmp[i - 1];
            }
            a[0] = tmp[0] + tmp[N - 1];

            for(int i = 0; i < N; i++) {
                if(a[i] % 2 == 1) {
                    a[i]++;
                }
            }
        }
        cout<<count<<" "<<a[0]<<endl;
        
        delete[] a;
        delete[] tmp;
    }
    return 0;
}
