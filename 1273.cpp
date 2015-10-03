#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;

const int maxn = 202;
const int inf = 0x3f3f3f3f;

int mp[maxn][maxn];
bool vis[maxn];
int pre[maxn];
int n;
int m;
int s;
int e;

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
    memset(vis, 0, sizeof(vis));
    vis[s] = 1;
    q.push(s);
    while(!q.empty()) {
        int first = q.front();
        if(first == e) {
            return true;
        }
        q.pop();
        for(int i = 1;i <= n; i++) {
            if(!vis[i] && mp[first][i]) {
                q.push(i);
                vis[i] = 1;
                pre[i] = first;
            }
        }
    }
    return false;
}

int max_flow() {
    int ans = 0;
    while(true) {
        if(!bfs()) {
            return ans;
        }
        int Min = inf;
        for(int i = e; i != s; i = pre[i]) {
            Min = min(Min, mp[pre[i]][i]);
        }
        for(int i = e; i != s; i = pre[i]) {
            mp[pre[i]][i] -= Min;
            mp[i][pre[i]] += Min;
        }
        ans += Min;
    }
}

int main() {
    while(scanf("%d%d", &m, &n) != EOF) {
        memset(mp, 0, sizeof(mp));
        int u;
        int v;
        int c;
        while(m--) {
            scanf("%d%d%d", &u, &v, &c);
            mp[u][v] += c;
        }
        s = 1;
        e = n;
        printf("%d\n", max_flow());
    }
    return 0;
}
