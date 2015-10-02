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
    int N;
    cin>>N;
    int sum, ab;
    for(int i = 1; i <= N; i++) {
        cin>>sum>>ab;
        if(sum < ab || (sum - ab) % 2 == 1) {
            cout<<"impossible"<<endl;
        } else {
            cout<<(sum + ab) / 2<<" "<<(sum - ab) / 2<<endl;
        }
    }
    return 0;
}
