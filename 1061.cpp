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
Bezout等式
先抽离L和step的公因子
再做出a*L - b*step = 1
之后，乘以常数，取模，得到最小整数解
*/

long long gcd(long long a, long long b) {
    if(a == b) return a;
    if(a < b) return gcd(b, a);
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    long long x;
    long long y;
    long long m;
    long long n;
    long long L;
    cin>>x>>y>>m>>n>>L;

    long long dist = x - y; //距离差
    dist %= L;
    if(dist < 0) {
        dist += L;
    }

    long long step = m - n; //步长差
    step %= L;
    if(step < 0) {
        step += L;
    }
    
    long long tmp = gcd(L, step);

    /*
    除不尽，无解
    */
    if(dist % tmp != 0) {
        cout<<"Impossible"<<endl;
    } else {
        // 消去最大公约数
        L /= tmp;
        step /= tmp;
        dist /= tmp;

        long long A = L;
        long long B = step;
        /*
        把较大值给A，较小值给B
        */
        if(A < B) {
            long long C = B;
            B = A;
            A = C;
        }

        /*
        速度相同，无解
        */
        if(B == 0) {
            cout<<"Impossible"<<endl;
        } else if(B == 1) {//步长是1
            cout<<A - dist<<endl;
        } else {
            //    co1 * A - co2 * B = 1;
            long long originA = A; //保留原始数据
            long long originB = B; //保留原始数据

            long long co1_1, co2_1, co1_2, co2_2; 
            //以下求得Bezout等式的系数
            //后缀是1的，代表最近的一次
            //后缀是2的，代表倒数第二次
            
            long long option = 1; //第几次进入循环
            long long tmp = 0;
            while(B != 1) {
                long long quo = A / B;

                if(option == 1) {//第1次进入循环
                    co1_1 = 1;        
                    co2_1 = quo;
                    option = 2;
                } else if(option == 2) {//第2次进入循环
                    co1_2 = co1_1;
                    co2_2 = co2_1;
                    co1_1 = -quo * co1_1;
                    co2_1 = -(quo * co2_1 + 1);
                    option = 3;
                } else {//2次以上进入循环
                    tmp = co1_2;
                    co1_2 = co1_1;
                    co1_1 = tmp - co1_1 * quo;

                    tmp = co2_2;
                    co2_2 = co2_1;
                    co2_1 = -co2_1*quo + tmp;
                }

                /*辗转相除法*/
                tmp = B;
                B = A - quo * B;
                A = tmp;
            }

            dist %= originA;
            co2_1 %= originA; //求最小整数    
            if(co2_1 < 0) {
                co2_1 += originA;
            }
            long long res = co2_1 * dist; //乘以距离
            res %= originA; //求最小整数

            cout<<res<<endl;
        }
    }
    return 0;
}
