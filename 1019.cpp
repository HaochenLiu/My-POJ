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

int big[6] = {0, 45, 9045, 1395495, 189414495}; //原大整数的第45位是一位数的最后一位，之后进入两位数循环
int startcircle[6] = {0, 1, 11, 192, 2893, 38894}; //首次进入第二位循环，该循环有11位
int singlestart[6] = {0, 1, 10, 190, 2890, 38890}; //对于某一个数的循环，第10位是两位数的开始
int power[6] = {0, 1,10, 100, 1000, 10000};

/*
转化为字符串
*/
template<class T> string toString(T n) {
    ostringstream ost;ost<<n;
    ost.flush();
    return ost.str();
}

/*
给出的等差数列的首项，项数，公差，求和。要防溢出
*/
int getSum(int a1, int n, int d) {
    int an = a1 + (n - 1) * d;
    if(((an - a1)/d + 1) % 2 == 0) {
        return ((an - a1)/d + 1) / 2 * (a1 + an);
    } else {
        return (a1 + an) / 2 * ((an - a1)/d + 1);
    }
}

/*
从1234...的序列中的第order个位
*/
int getDigit(int order) {
    int newdigit = 0;
    for(newdigit = 1; newdigit <= 4; newdigit++) {
        if(order <= singlestart[newdigit + 1]) {
            break;
        }
    }
    order -= (singlestart[newdigit] - 1);

    int shift = (order - 1)/newdigit;
    order -= (shift * newdigit);
    string s = toString(power[newdigit] + shift);
        
    return s[order - 1] - '0';
}

int solve(int n) {
    int digit = 5; //默认为大
    for(int i = 1; i <= 4; i++) {
        if(n <= big[i]) {
            digit = i;
            break;
        }
    }
    n -= (big[digit - 1]); //把前面位都清掉
            
    double tmp = pow((double)digit - 2.0 * (double)startcircle[digit], 2.0);
    double delta = (double)(tmp + 8.0 * (double)(n - 1) * (double)digit);
    int current = ((double)digit - 2.0 * (double)startcircle[digit] + sqrt(delta)) / (2.0 * (double)digit); 
    //以startcircle[digit]为首项，digit为公差，current为项数的等差数列的和，是小于n，且最接近n的最大的和。防溢出！

    n -= getSum(startcircle[digit], current, digit); //把同位数，之前的数都清掉

    return getDigit(n);
}

int main() {
    int N;
    cin>>N;
    for(int i = 0; i < N; i++) {
        int n;
        cin>>n;
        cout<<solve(n)<<endl;
    }
    return 0;
}
