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
#include <hash_set>
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

using namespace stdext; // 用hash_map需要加上这一句
using namespace std;

int max(int a, int b) {
    if(a > b) return a;
    return b;
}

bool isUpperCase(char c) {
    return (c >= 'A') && (c <= 'Z');
}

bool isLowerCase(char c) {
    return (c >= 'a') && (c <= 'z');
}

bool isLetter(char c) {
    return (c >= 'A') && (c <= 'Z') || (c >= 'a') && (c <= 'z');
}

bool isDigit(char c) {
    return (c >= '0') && (c <= '9');
}

char toLowerCase(char c) {
    return (isUpperCase(c)) ? (c + 32) : c;
}

char toUpperCase(char c) {
    return (isLowerCase(c)) ? (c - 32) : c;
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

int main() {
    int N1, N2;
    int count = 0;
    while(cin>>N1>>N2) {
        count++;
        vector<string> key(N1, "");
        for(int i = 0; i < N1; i++) {
            cin>>key[i];
        }
        vector<string> excuse(N2, "");
        vector<vector<string>> l(N2, vector<string>(N1, ""));
        vector<string>::iterator it;
        char c;
        gets(&c);//读后面的一个回车    
        for(int i = 0; i < N2; i++) {
            getline(cin, excuse[i]);
            string tmp = excuse[i];
            for(int i = 0; i < tmp.size(); i++) {
                if(!isLetter(tmp[i])) {
                    tmp[i] = ' ';
                } else {
                    tmp[i] = toLowerCase(tmp[i]);
                }
            }
            l[i] = split(tmp, ' ');
        }
        vector<int> num(N2, 0);
        for(int i = 0; i < N2; i++) {
            num[i] = 0;
            for(int j = 0; j < N1; j++) {
                for(int k = 0; k < l[i].size(); k++) {
                    if(l[i][k] == key[j]) {
                        num[i]++;
                    }
                }
            }
        }
        int maxVal = 0;

        for(int i = 0; i < N2; i++) {
            maxVal = max(maxVal, num[i]);
        }
        cout<<"Excuse Set #"<<count<<endl;
        for(int i = 0; i < N2; i++) {
            if(maxVal == num[i]) {
                cout<<excuse[i]<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}
