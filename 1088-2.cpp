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

/*
经典滑雪题
最长路径
DFS
*/

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool inBound(int x, int y, int R, int C) {
    return (x >= 0) && (x < R) && (y >= 0) && (y < C);
}

int dfs(vector<vector<int>>& dp, vector<vector<int>>& h, int x, int y, int R, int C) {
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

int main() {
    int R;
    int C;
    while(cin>>R>>C) {
        vector<vector<int>> h(R, vector<int>(C, 0));
        vector<vector<int>> dp(R, vector<int>(C, 1));
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                cin>>h[i][j];
            }
        }

        int maxVal = 0;
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                maxVal = max(maxVal, dfs(dp, h, i, j, R, C));
            }
        }
        cout<<maxVal<<endl;
    }

    return 0;
}
