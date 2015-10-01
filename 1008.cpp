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

int turn1(string s) {
    if(s == "pop") {
        return 1;
    } else if(s == "no") {
        return 2;
    } else if(s == "zip") {
        return 3;
    } else if(s == "zotz") {
        return 4;
    } else if(s == "tzec") {
        return 5;
    } else if(s == "xul") {
        return 6;
    } else if(s == "yoxkin") {
        return 7;        
    } else if(s == "mol") {
        return 8;
    } else if(s == "chen") {
        return 9;
    } else if(s == "yax") {
        return 10;
    } else if(s == "zac") {
        return 11;
    } else if(s == "ceh") {
        return 12;
    } else if(s == "mac") {
        return 13;
    } else if(s == "kankin") {
        return 14;        
    } else if(s == "muan") {
        return 15;
    } else if(s == "pax") {
        return 16;
    } else if(s == "koyab") {
        return 17;
    } else if(s == "cumhu") {
        return 18;
    } else if(s == "uayet") {
        return 19;
    } else {
        return 0;
    }
}

string turn2(int i) {
    if(i == 1) {
        return "imix";
    } else if(i == 2) {
        return "ik";
    } else if(i == 3) {
        return "akbal";
    } else if(i == 4) {
        return "kan";
    } else if(i == 5) {
        return "chicchan";
    } else if(i == 6) {
         return "cimi";
    } else if(i == 7) {
        return "manik";        
    } else if(i == 8) {
        return "lamat";
    } else if(i == 9) {
        return "muluk";
    } else if(i == 10) {
        return "ok";
    } else if(i == 11) {
        return "chuen";
    } else if(i == 12) {
        return "eb";
    } else if(i == 13) {
        return "ben";
    } else if(i == 14) {
        return "ix";
    } else if(i == 15) {
        return "mem";        
    } else if(i == 16) {
        return "cib";
    } else if(i == 17) {
        return "caban";
    } else if(i == 18) {
        return "eznab";
    } else if(i == 19) {
        return "canac";
    } else if(i == 20) {
        return "ahau";
    }
}

int main() {
    int N;
    cin>>N;
    int day;
    char stuff;
    string month;
    int year;
    int total = 0;
    int oyear;
    int omonth;
    int oday;
    cout<<N<<endl;
    for(int i = 0; i < N; i++) {
        cin>>day;
        cin>>stuff;
        cin>>month;
        cin>>year;

        total = year * 365 + 20*(turn1(month) - 1) + day;
        oyear = total / 260;
        omonth = total % 20 + 1;
        oday = total % 13 + 1;

        cout<<oday<<" "<<turn2(omonth)<<" "<<oyear<<endl;
    }
    return 0;
}
