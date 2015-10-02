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

struct group {
    string dic;
    int val;
    group(string dic = "", int val = 0);
};

group::group(string dic, int val) {
    this->dic = dic;
    this->val = val;
}

group* g;
int n,m;

int getval(string s) {
    for(int i = 0; i < n; i++) {
        if(g[i].dic == s) {
            return g[i].val;
        }
    }
    return 0;
}

vector<string> split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str);
    string tok;

    while(getline(ss, tok, delimiter)) {
        internal.push_back(tok);
    }
  
    return internal;
}

void solve(string s)
{
    vector<string> l = split(s, ' ');
    vector<string>::iterator it = l.begin();
    int count = 0;
    while(it != l.end()) {
        count += getval((*it));
        it++;
    }    
    cout<<count<<endl;
}

int main() {
    cin>>n>>m;
    g = new group[n];
    for(int i = 0; i < n; i++) {
        cin>>g[i].dic>>g[i].val;
    }

    int count = 0;
    string s = "";
    string tmp = "";
    while(count != m) {
        cin>>tmp;
        if(tmp == ".") {
            count++;
            solve(s);
            s = "";
            tmp = "";
            continue;
        }

        s += " ";
        s += tmp;
    }

    delete[] g;
    return 0;
}
