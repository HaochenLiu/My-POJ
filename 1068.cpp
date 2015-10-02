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
public:
    char c;
    int order;
    group(char c, int order);
};

group::group(char c, int order) {
    this->c = c;
    this->order = order;
}

int main() {
    int N;
    cin>>N;
    for(int i = 0; i < N; i++) {
        int count = 0;
        cin>>count;
        int* a = new int[count];
        for(int j = 0; j < count; j++) {
            cin>>a[j];
        }

        string str = "";
        for(int j = 0; j < count; j++) {
            str += "((";
        }

        for(int j = 0; j < count; j++) {
            str[a[j] + j] = ')';
        }
        
        stack<group> st;
        for(int j = 0; j < 2 * count; j++) {
            if(!st.empty()) {
                if(str[j] == '(') {
                    st.push(group('(',j));
                } else {
                    int first = st.top().order;
                    cout<<(j - first + 1) / 2<<" ";
                    st.pop();
                }
            } else {
                st.push(group('(',j));
            }
        }
        cout<<endl;

        delete[] a;
    }
    return 0;
}
