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
    int n;
    cout<<"PERFECTION OUTPUT"<<endl;
    while(cin>>n) {
        if(n == 0) {
            break;
        }
        
        int sum = 0;
        int tmp = (int)sqrt((double)n);
        for(int i = 1; i <= tmp; i++) {
            if(n % i == 0) {
                sum += (i + n/i);
            }
        }

        if(n == (tmp * tmp)) {
            sum -= tmp;
        }
        sum -= (2 * n);

        printf("%5d",n);
        if(sum == 0) {
            printf("  PERFECT\n");
        } else if(sum > 0) {
            printf("  ABUNDANT\n");
        } else {
            printf("  DEFICIENT\n");
        }
    }
    cout<<"END OF OUTPUT"<<endl;    
    return 0;
}
