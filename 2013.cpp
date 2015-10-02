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
    int count = 0;
    while(cin>>N) {
        if(N == 0) {
            break;
        }
        
        count++;
        vector<string> str(N, "");
        for(int i = 0; i < N; i++) {
            cin>>str[i];
        }

        vector<int> order(N, 0);
        if(N % 2 == 0) {
            for(int i = 0; i < N / 2; i++) {
                order[i] = 2 * i;
            }
            for(int i = N / 2; i < N; i++) {
                order[i] = 2 * (N - i) - 1;
            }
        } else {
            for(int i = 0; i <= N / 2; i++) {
                order[i] = 2 * i;
            }
            for(int i = N / 2 + 1; i < N; i++) {
                order[i] = 2 * (N - i) - 1;
            }
        }

        cout<<"SET "<<count<<endl;
        for(int i = 0; i < N; i++) {
            cout<<str[order[i]]<<endl;
        }
    }
    return 0;
}
