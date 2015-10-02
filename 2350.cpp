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

void solve(int n) {
    double d = 0.0;
    for(int i = n; i >= 1; i--) {
        d += (1 / (double)i);
    }
    d /= 2.0;

    printf("Cards  Overhang\n");
    printf("%5d     %.3lf\n",n,d);
}

int main() {
    int N;
    cin>>N;
    for(int i = 0; i < N; i++) {
        int count;
        cin>>count;
        int* grade = new int[count];
        int sum = 0;
        for(int j = 0; j < count; j++) {
            cin>>grade[j];
            sum += grade[j];
        }
        double aver = sum / (double)count;
        
        int above = 0;
        for(int j = 0; j < count; j++) {
            if(grade[j] > aver) {
                above++;
            }
        }
        printf("%.3lf%%\n", 100.0 * above / (double)count);
        delete[] grade;
    }

    return 0;
}
