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

int solve(string s) {
    int count = 0;
    for(int i = 0; i < 8; i++) {
        if(s[i] == '1') {
            count += pow(2, 7 - i);
        }
    }
    return count;
}

int main() {
    int N;
    cin>>N;
    string s;
    string sub[4];
    for(int i = 1; i <= N; i++) {
        cin>>s;
        sub[0] = s.substr(0, 8);
        sub[1] = s.substr(8, 8);
        sub[2] = s.substr(16, 8);
        sub[3] = s.substr(24, 8);

        cout<<solve(sub[0])<<".";
        cout<<solve(sub[1])<<".";        
        cout<<solve(sub[2])<<".";
        cout<<solve(sub[3])<<endl;
    }

    return 0;
}
