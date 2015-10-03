/*
Dijkstra's algorithm
Eulerian path
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

void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

int getShortestPath(vector<vector<int>>& graph, int source, int target) {
    if(source == target) return 0;
    if(graph.empty() || graph[0].empty()) return 0;
    vector<int> dist(graph.size(), INT_MAX); 
    dist[source] = 0;
    queue<int> q;
    q.push(source); 
    int res = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int i = 0; i < graph.size(); i++) {
            if(graph[cur][i] == INT_MAX) {
                continue;
            }
            if(dist[i] > dist[cur] + graph[cur][i]) {
                dist[i] = dist[cur] + graph[cur][i];
                q.push(i);
            }
        }
    }
    return dist[target];
}

int main() {
    string tmp;
    vector<string> input;
    while(cin>>tmp) {
        if(tmp != "deadend") {
            input.push_back(tmp);
            continue;
        }

        int e = input.size();
        vector<vector<int>> graph(26, vector<int>(26, INT_MAX));
        int res = 0;
        map<int, int> inDegree;
        for(int i = 0; i < e; i++) {
            graph[input[i][0] - 'a'][input[i][input[i].size() - 1] - 'a'] = input[i].size();
            graph[input[i][input[i].size() - 1] - 'a'][input[i][0] - 'a'] = input[i].size();
            inDegree[input[i][0] - 'a']++;
            inDegree[input[i][input[i].size() - 1] - 'a']++;
            res += input[i].size();
        }

        int n[2];
        int cnt = 0;
        map<int, int>::iterator it;
        for(it = inDegree.begin(); it != inDegree.end(); it++) {
            if(it->second % 2 == 1) {
                n[cnt] = it->first;
                cnt++;
            }
        }

        if(cnt == 2) {
            res += getShortestPath(graph, n[0], n[1]);
        }

        cout<<res<<endl;
        input.clear();
    }

    return 0;
}
