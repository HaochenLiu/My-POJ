/*
Kruskal's algorithm
最小生成树
并查集

因为已经给定了一些edge，此题Prim's algorithm不适用。
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

struct Edge {
    int x;
    int y;
    int w;
    Edge(int x = 0, int y = 0, int w = 0);
};

Edge::Edge(int x, int y, int w) {
    this->x = x;
    this->y = y;
    this->w = w;
}

int max(int a, int b) {
    if(a > b) return a;
    return b;
}

int min(int a, int b) {
    if(a < b) return a;
    return b;
}

void swap(Edge& a, Edge& b) {
    Edge t = a;
    a = b;
    b = t;
}

void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

int getFather(vector<int>& father, int x) {
    if(father[x] == -1) {
        father[x] = x;
        return x;
    }
    while(x != father[x]) {
        x = father[x];
    }
    return x;
}

int main() {
    int N;
    cin>>N;
    vector<Edge> nroad;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            Edge e;
            scanf("%d", &e.w);
            if(i < j) {
                e.x = i;
                e.y = j;
                nroad.push_back(e);
            }
        }
    }

    int Q;
    cin>>Q;
    vector<int> father;
    father.resize(N);
    for(int i = 0; i < N; i++) {
        father[i] = -1;
    }
    vector<vector<bool>> hasRoad(N, vector<bool>(N, false));
    for(int i = 0; i < Q; i++) {
        int tx, ty;
        cin>>tx>>ty;
        tx--;
        ty--;
        if(tx > ty) {
            swap(tx, ty);
        }
        hasRoad[tx][ty] = true;
        int fx = getFather(father, tx);
        int fy = getFather(father, ty);
        father[fx] = min(fx, fy);
        father[fy] = min(fx, fy);
    }

    int sz = nroad.size();
    for(int i = 0; i < sz; i++) {
        for(int j = i + 1; j < sz; j++) {
            if(nroad[i].w > nroad[j].w) {
                swap(nroad[i], nroad[j]);
            }
        }
    }

    int res = 0;
    for(int i = 0; i < sz; i++) {
        int tx = nroad[i].x;
        int ty = nroad[i].y;
        if(hasRoad[tx][ty]) {
            continue;
        }
        if(getFather(father, tx) == getFather(father, ty)) {
            continue;
        }
        res += nroad[i].w;
        int fx = getFather(father, tx);
        int fy = getFather(father, ty);
        father[fx] = min(fx, fy);
        father[fy] = min(fx, fy);
    }

    cout<<res<<endl;
    
    return 0;
}
