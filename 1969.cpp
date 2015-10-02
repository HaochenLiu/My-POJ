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
    int order;
    while(cin>>order) {
        int sum = (3.0 + sqrt(8.0 * order - 7.0)) / 2.0;
        int neworder = order - (sum - 1) * (sum - 2) / 2;
        if(sum % 2 == 1) {
            cout<<"TERM "<<order<<" IS "<<neworder<<"/"<<sum - neworder<<endl;
        } else {
            cout<<"TERM "<<order<<" IS "<<sum - neworder<<"/"<<neworder<<endl;
        }
    }
    return 0;
}
