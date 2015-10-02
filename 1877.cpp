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
    int m,n;
    int order = 0;
    while(cin>>m>>n) {
        if(m == 0) {
            break;
        }

        order++;
        int tot = m*n;
        int* a = new int[tot];
        for(int i = 0; i < tot; i++) {
            cin>>a[i];
        }
        
        int vol;
        cin>>vol;

        for(int i = 0; i < tot - 1; i++) {
            for(int j = i + 1; j < tot; j++) {
                if(a[i] > a[j]) {
                    int tmp = a[i];
                    a[i] = a[j];
                    a[j] = tmp;
                }
            }
        }

        int count = 0; //被淹没的地点数
        double depth = 0;
        for(count = 0; count < tot - 1; count++) {
            if(vol > 0 && (a[count + 1] - a[count]) * (count + 1) * 100 <= vol) {
                vol -= 100 * (a[count + 1] - a[count]) * (count + 1);
                for(int i = 0; i <= count; i++) {
                    a[i] = a[count + 1];
                }
                depth = a[count + 1];
            } else if(vol > 0 && (a[count + 1] - a[count]) * (count + 1) * 100 > vol) {
                double remain = (double)vol / (double)(count + 1) / 100.0;
                depth = (double)a[count] + remain;
                vol = 0;
                break;
            }
            if(vol == 0) {
                break;
            }
        }
        if(vol > 0) {
            double remain = (double)vol / (double)tot / 100.0;
            depth = (double)a[count] + remain;
        }

        cout<<"Region "<<order<<endl;
        cout<<"Water level is ";
        printf("%.2lf",depth);
        cout<<" meters."<<endl;
        printf("%.2lf",100.0 * (count + 1) / tot);
        cout<<" percent of the region is under water."<<endl;            

        delete[] a;
    }
    return 0;
}
