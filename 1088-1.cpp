/*
经典滑雪题
最长路径
DFS
排序后，从低到高搜索。
*/

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

struct Point {
    int x;
    int y;
};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int** h;
int** dp;
Point* p;

int max(int a, int b) {
    if(a > b) return a;
    return b;
}

bool inBound(int x, int y, int R, int C) {
    return (x >= 0) && (x < R) && (y >= 0) && (y < C);
}

int dfs(int** dp, int** h, int x, int y, int R, int C) {
    if(dp[x][y] > 1) return dp[x][y];

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(!inBound(nx, ny, R, C)) continue;
        if(h[nx][ny] >= h[x][y]) continue;
        dp[x][y] = max(dp[x][y], dfs(dp, h, nx, ny, R, C) + 1);
    }
    return dp[x][y];
}

bool comp(Point a, Point b) {
    return (h[a.x][a.y] < h[b.x][b.y]);
}

int main() {
    int R;
    int C;
    while(cin>>R>>C) {
        h = new int*[R];
        for(int i = 0; i < R; i++) {
            h[i] = new int[C];
            for(int j = 0; j < C; j++) {
                cin>>h[i][j];
            }
        }

        dp = new int*[R];
        for(int i = 0; i < R; i++) {
            dp[i] = new int[C];
            for(int j = 0; j < C; j++) {
                dp[i][j] = 1;
            }
        }

        p = new Point[R * C];
        for(int i = 0; i < R * C; i++) {
            p[i].x = i / C;
            p[i].y = i % C;
        }

        for(int i = 0; i < R * C; i++) {
            for(int j = i + 1; j < R * C; j++) {
                int ix = p[i].x;
                int iy = p[i].y;
                int jx = p[j].x;
                int jy = p[j].y;
                if(h[ix][iy] > h[jx][jy]) {
                    Point t = p[i];
                    p[i] = p[j];
                    p[j] = t;
                }
            }
        }

        int maxVal = 0;
        for(int i = 0; i < R * C; i++) {
            int nx = p[i].x;
            int ny = p[i].y;
            maxVal = max(maxVal, dfs(dp, h, nx, ny, R, C));
        }

        cout<<maxVal<<endl;
    }

    return 0;
}
