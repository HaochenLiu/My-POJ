/*
Max flow
Edmonds–Karp algorithm
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

vector<vector<int>> graph;
vector<vector<int>> capacities;
vector<vector<int>> flowPassed;
vector<int> parentsList;
vector<int> currentPathCapacity;
int e;
int v;

int max(int a, int b) {
    if(a > b) return a;
    return b;
}

int min(int a, int b) {
    if(a < b) return a;
    return b;
}

int bfs(int startNode, int endNode) {
    queue<int> q;
    q.push(startNode);
    parentsList.clear();
    currentPathCapacity.clear();
    parentsList.resize(v, -1);
    currentPathCapacity.resize(v, 0);
    parentsList[startNode] = -2;
    currentPathCapacity[startNode] = INT_MAX;
    while(!q.empty()) {
        int currentNode = q.front();
        q.pop();
        for(int i = 0; i < graph[currentNode].size(); i++) {
            int to = graph[currentNode][i];
            if(parentsList[to] == -1) {
                if(capacities[currentNode][to] - flowPassed[currentNode][to] > 0) {
                    parentsList[to] = currentNode;
                    currentPathCapacity[to] = min(currentPathCapacity[currentNode], 
                    capacities[currentNode][to] - flowPassed[currentNode][to]);
                    if(to == endNode) {
                        return currentPathCapacity[endNode];
                    }
                    q.push(to);
                }
            }
        }
    }
    return 0;
}
 
int edmondsKarp(int startNode, int endNode) {
    int maxFlow = 0;
    while(true) {
        int flow = bfs(startNode, endNode);
        if (flow == 0) {
            break;
        }
        maxFlow += flow;
        int currentNode = endNode;
        while(currentNode != startNode) {
            int previousNode = parentsList[currentNode];
            flowPassed[previousNode][currentNode] += flow;
            flowPassed[currentNode][previousNode] -= flow;
            currentNode = previousNode;
        }
    }
    return maxFlow;
}

int main() {
    while(cin>>e>>v) {
        if(e == 0) {
            cout<<0<<endl;
            continue;
        }
        graph.clear();
        capacities.clear();
        flowPassed.clear();
        graph.resize(v, vector<int>());
        capacities.resize(v, vector<int>(v, 0));
        flowPassed.resize(v, vector<int>(v, 0));

        for(int i = 0; i < e; i++) {
            int x;
            int y;
            cin>>x>>y;
            x--;
            y--;
            if(capacities[x][y] == 0) {
                graph[x].push_back(y);
                graph[y].push_back(x);
            }
            int c;
            cin>>c;
            capacities[x][y] += c;
        }

        int source = 0;
        int sink = v - 1;
        int maxFlow = edmondsKarp(source, sink);
        cout<<maxFlow<<endl;
    }

    return 0;
}
