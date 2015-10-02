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

int getNumber(string s) {
    if(s == "zero") {
        return 0;
    } else if(s == "one") {
        return 1;
    } else if(s == "two") {
        return 2;
    } else if(s == "three") {
        return 3;
    } else if(s == "four") {
        return 4;
    } else if(s == "five") {
        return 5;
    } else if(s == "six") {
        return 6;
    } else if(s == "seven") {
        return 7;
    } else if(s == "eight") {
        return 8;
    } else if(s == "nine") {
        return 9;
    } else if(s == "ten") {
        return 10;
    } else if(s == "eleven") {
        return 11;
    } else if(s == "twelve") {
        return 12;
    } else if(s == "thirteen") {
        return 13;
    } else if(s == "fourteen") {
        return 14;
    } else if(s == "fifteen") {
        return 15;
    } else if(s == "sixteen") {
        return 16;
    } else if(s == "seventeen") {
        return 17;
    } else if(s == "eighteen") {
        return 18;
    } else if(s == "nineteen") {
        return 19;
    } else if(s == "twenty") {
        return 20;
    } else if(s == "thirty") {
        return 30;
    } else if(s == "forty") {
        return 40;
    } else if(s == "fifty") {
        return 50;
    } else if(s == "sixty") {
        return 60;
    } else if(s == "seventy") {
        return 70;
    } else if(s == "eighty") {
        return 80;
    } else if(s == "ninety") {
        return 90;
    } else if(s == "hundred") {
        return 100;
    } else if(s == "thousand") {
        return 1000;
    } else if(s == "million") {
        return 1000000;
    }
    return 0;
}

vector<string> split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str);
    string tok;

    while(getline(ss, tok, delimiter)) {
        internal.push_back(tok);
    }
  
    return internal;
}

int main() {
    string s;
    while(getline(cin,s)) {
        if(s == "") {
            break;
        }
        vector<string> input = split(s, ' '); 

        int sign = 1;
        int number = 0;

        if((input[0]) == "negative") {
            sign = -1;
            input.erase(input.begin());
        }

        vector<string>::reverse_iterator rit = input.rbegin();
        int option = 0;
        while(rit != input.rend()) {
            if(option == 0) {
                if(getNumber(*rit) < 20 && getNumber(*rit) >=0) {
                    number += getNumber(*rit);
                } else if(getNumber(*rit) < 100 && getNumber(*rit) >= 20) {
                    number += getNumber(*rit);
                } else if(getNumber(*rit) == 100 || getNumber(*rit) == 1000 || getNumber(*rit) == 1000000) {
                    option = getNumber(*rit); 
                }
            } else {
                if(getNumber(*rit) < 20 && getNumber(*rit) >=0) {
                    number += getNumber(*rit) * option;
                } else if(getNumber(*rit) < 100 && getNumber(*rit) >= 20) {
                    number += getNumber(*rit) * option;
                } else {
                    if(option < getNumber(*rit)) {
                        option = getNumber(*rit);
                    } else {
                        option *= getNumber(*rit);
                    }
                }
            }
            rit++;
        }
        if(sign == -1) {
            cout<<"-";
        }
        cout<<number<<endl;
    }

    return 0;
}
