#include <iostream>
#include <string>
using namespace std;

int max(int a,int b) {
    return (a > b) ? a : b;
}

int trans2num(char c) {
    if(c >= '0' && c <= '9') {
        return c - '0' + 1;
    } else if(c >= 'A' && c <= 'Z') {
        return c - 'A' + 11;
    } else if(c >= 'a' && c <= 'z') {
        return c - 'a' + 37;
    }
}

int main() {
    string s;
    while(cin>>s) {
        char c = s[0];
        for(int i = 1; i < s.length(); i++) {
            if(s[i] > c) {
                c = s[i];
            }
        }
        int N = max(2, trans2num(c));
        while(N != 63) {
            int sum = 0;
            for(int i = 0; i < s.length(); i++) {
                sum += (trans2num(s[i]) - 1);
            }
            if(sum % (N - 1) == 0) {
                break;
            }
            N++;
        }
        if(N == 63) {
            cout<<"such number is impossible!"<<endl;
        } else {
            cout<<N<<endl;
        }
    }
    return 0;
}
