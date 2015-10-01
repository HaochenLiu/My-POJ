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

int getInvCount(string s) {
    int invcount = 0;
    for(unsigned int i = 0; i < s.length() - 1; i++) {
        for(unsigned int j = i + 1; j < s.length(); j++) {
            if(s[i] > s[j]) {
                invcount++;
            }
        }
    }
    return invcount;
}

class DNAcount {
public:
    string DNAstr;
    int invcount;
};

int main() {
    int len = 0;
    int count = 0;
    cin>>len>>count;
    DNAcount* DNA = new DNAcount[count];
    string tmp;
    for(int i = 0; i < count; i++) {
        cin>>tmp;
        DNA[i].DNAstr = tmp;
        DNA[i].invcount = getInvCount(tmp);
    }
    DNAcount tmpDNA;

    for(int i = 0; i < count - 1; i++) {
        for(int j = i + 1; j < count; j++) {
            if(DNA[i].invcount > DNA[j].invcount) {
                tmpDNA = DNA[i];
                DNA[i] = DNA[j];
                DNA[j] = tmpDNA;
            }
        }
    }
    for(int i = 0; i < count; i++) {
        cout<<DNA[i].DNAstr<<endl;
    }

    delete[] DNA;
    return 0;
}
