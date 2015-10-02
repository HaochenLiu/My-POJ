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

int* a;
int* b;
int n;

int f(int i, int j) {
    return b[i * n + j];
}

int main() {
    while(cin>>n) {
        a = new int[n * n];
        for(int i = 0; i < n * n; i++) {
            a[i] = 0;
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                cin>>a[i * n + j];
            }
        }

        b = new int[n * n];
        for(int i = 0; i < n * n; i++) {
            b[i] = 0;
        }
        
        for(int i = n * (n - 1); i < n * n; i++) {
            b[i] = a[i];
        }
        
        for(int i = n - 2; i >= 0; i--) {
            for(int j = 0; j <= i; j++) {
                b[i * n + j] = a[i * n + j] + max(f(i + 1, j), f(i + 1, j + 1));
            }
        }

        cout<<b[0]<<endl;

        delete[] a;
        delete[] b;
    }

    return 0;
}
