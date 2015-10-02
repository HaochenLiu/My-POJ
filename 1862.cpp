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

/*贪心法，先排序，大的先结合，最后是小的*/
int main() {
    int N;
    cin>>N;
    vector<int> l;
    int tmp;
    for(int i = 1; i <= N; i++) {
        cin>>tmp;
        l.push_back(tmp);
    }
    sort(l.begin(), l.end());

    stack<double> st;
    vector<int>::iterator it = l.begin();
    while(it != l.end()) {
        st.push(double(*it));
        it++;
    }

    double dtmp;
    double dtmp2;
    while(st.size() != 1) {
        dtmp = st.top();
        st.pop();
        dtmp2 = st.top();
        st.pop();
        st.push(2 * sqrt(dtmp * dtmp2));        
    }
    printf("%.3lf\n",st.top());

    return 0;
}
