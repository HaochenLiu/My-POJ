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

/*
以d为切入点。C[d] = S[i]推出M[d] = P[i]
然后向前推进M[d-1],...
*/
int get(string s, char c) {
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == c) {
            return i;
        }
    }
    return -1;
}

int main() {
    int x;
    string S, P, C, M;
    while(cin>>x) {
        if(x == 0) {
            break;
        }
    
        cin>>S>>P>>C;
        M = C;//先将长度设定
        int n = M.length();
        int d = (int)(sqrt(double(n * n * n)) + x) % n;
        
        M[d] = P[get(S, C[d])];
        for(int i = d; i != (n + d + 1)%n; i = (n + i - 1) % n) {
            int num1 = get(S, M[i]);
            int num2 = get(S, C[(n + i - 1) % n]);
            int num = num1 ^ num2;
            M[(n + i - 1) % n] = P[num]; 
        }
        cout<<M<<endl;
    }
    return 0;
}
