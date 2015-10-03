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

int max(int a, int b) {
    if(a > b) return a;
    return b;
}

int getShortestPath(int** a, int N, int source) {
    if(N == 0) return 0;
    vector<int> dist(N, INT_MAX); 
    dist[source] = 0;
    queue<int> q;
    q.push(source); 
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int i = 0; i < N; i++) {
            if(a[cur][i] == INT_MAX) {
                continue;
            }
            if(dist[i] > dist[cur] + a[cur][i]) {
                dist[i] = dist[cur] + a[cur][i];
                q.push(i);
            }
        }
    }
    int res = 0;
    for(int i = 0; i < N; i++) {
        res = max(res, dist[i]);
    }
    return res;
}

int main() {
    int N;
    while(cin>>N) {
        if(N == 0) {
            break;
        }
        int** a = new int*[N];
        for(int i = 0; i < N; i++) {
            a[i] = new int[N];
            for(int j = 0; j < N; j++) {
                a[i][j] = INT_MAX;
            }
        }

        for(int i = 0; i < N; i++) {
            int N2;
            cin>>N2;
            for(int j = 0; j < N2; j++) {
                int P;
                cin>>P;
                P--;
                cin>>a[i][P];
            }
        }

        int minVal = INT_MAX;
        int minIdx = -1;

        for(int i = 0; i < N; i++) {
            int t = getShortestPath(a, N, i);
            if(t < minVal) {
                minVal = t;
                minIdx = i;
            }
        }
        cout<<minIdx + 1<<" "<<minVal<<endl;

        for(int i = 0; i < N; i++) {
            delete[] a[i];
        }
        delete[] a;
    }
    return 0;
}
