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

int main() {
    string s = "";
    string tmp;
    for(int i = 1; i <= 4; i++) {
        getline(cin,tmp);
        s += tmp;
    }

    int* letter = new int[26];
    for(int i = 0; i < 26; i++) {
        letter[i] = 0;
    }

    for(int i = 0; i < s.length(); i++) {
        if(s[i] <= 'Z' && s[i] >= 'A') {
            letter[s[i] - 'A']++;
        }
    }

    int max = 0;
    for(int i = 0; i < 26; i++) {
        if(max < letter[i]) {
            max = letter[i];
        }
    }

    for(int j = 0; j < max; j++) {
        for(int i = 0; i < 26; i++) {
            if(letter[i] < max - j) {
                cout<<"  ";
            } else {
                cout<<"* ";
            }
        }
        cout<<endl;
    }

    for(int i = 0; i < 26; i++) {
        cout<<char('A' + i)<<" ";
    }
    cout<<endl;

    return 0;
}
