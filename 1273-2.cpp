/*
Edmonds–Karp algorithm
*/

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;

const int maxn = 201;

int mp[maxn][maxn];
bool vis[maxn];
int pre[maxn];
int n;
int m;
int source;
int sink;

int max(int a, int b) {
    if(a > b) return a;
    return b;
}

int min(int a, int b) {
    if(a < b) return a;
    return b;
}

bool bfs() {
    queue<int> q;
    memset(vis, false, sizeof(vis));
    vis[source] = true;
    q.push(source);
    while(!q.empty()) {
        int cur = q.front();
        if(cur == sink) {
            return true;
        }
        q.pop();
        for(int i = 1;i <= n; i++) {
            if(!vis[i] && mp[cur][i]) {
                vis[i] = true;
                pre[i] = cur;
                q.push(i);
            }
        }
    }
    return false;
}

int max_flow() {
    int res = 0;
    while(true) {
        if(!bfs()) {
            return res;
        }
        int minVal = INT_MAX;
        for(int i = sink; i != source; i = pre[i]) {
            minVal = min(minVal, mp[pre[i]][i]);
        }
        for(int i = sink; i != source; i = pre[i]) {
            mp[i][pre[i]] += minVal;
            mp[pre[i]][i] -= minVal;
        }
        res += minVal;
    }
}

int main() {
    while(scanf("%d%d", &m, &n) != EOF) {
        memset(mp, 0, sizeof(mp));
        int x;
        int y;
        int c;
        while(m--) {
            scanf("%d%d%d", &x, &y, &c);
            mp[x][y] += c;
        }
        source = 1;
        sink = n;
        printf("%d\n", max_flow());
    }
    return 0;
}
