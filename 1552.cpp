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

list<int> l;
bool find(list<int> l, int num) {
    list<int>::iterator it = l.begin();
    while(it != l.end()) {
        if((*it) == num) {
            return true;
        }
        it++;
    }
    return false;
}

void solve() {
    l.sort();
    list<int>::iterator it = l.begin();
    int count = 0;
    while(it != l.end()) {
        if((*it) % 2 == 0) {
            if(find(l, (*it)/2)) {
                count++;
            }
        }
        it++;
    }
    cout<<count<<endl;
}

int main() {
    int first;
    int next;
    while(cin>>first) {
        if(first == -1) {
            break;
        } else {
            l.clear();
            l.push_back(first);
            while(cin>>next) {
                if(next == 0) {
                    solve();
                    break;
                } else {
                    l.push_back(next);
                }
            }
        }
    }
    return 0;
}
