#include <iostream>
#include <cstdio>
#include <string>
#include <list>
#include <map>

using namespace std;

int M,N;
int state = 0; //0 right,1 down, 2 left, 3 up
char* a;

int getNext(int pos) {
    while(true) {
        if(state == 0) {
            if(a[pos + 1] == 0) {
                return pos + 1;
            } else {
                state = (state + 1) % 4;
            }
        }
        if(state == 1) {
            if(a[pos + (N + 2)] == 0) {
                return pos + (N + 2);
            } else {
                state = (state + 1) % 4;
            }
        }
        if(state == 2) {
            if(a[pos - 1] == 0) {
                return pos - 1;
            } else {
                state = (state + 1) % 4;
            }
        }
        if(state == 3) {
            if(a[pos - (N + 2)] == 0) {
                return pos - (N + 2);
            } else {
                state = (state + 1) % 4;
            }
        }
    }
    return 0;
}

int main() {
    cin>>M>>N;
    int pos = N + 3;
    int cnt = N * M - 1;
    int cnt2 = 0;
    a = new char[(M + 2) * (N + 2)];
    for(int i = 0; i < (N + 2) * (M + 2); i++) {
        if(i / (N + 2) == 0
        || i / (N + 2) == M + 1
        || i % (N + 2) == 0
        || i % (N + 2) == N + 1) {
            a[i] = '1';
        } else {
            a[i] = 0;
        }
    }
    a[pos] = 'A' + cnt2 % 26;
    while(cnt--) {    
        pos = getNext(pos);
        a[pos] = 'A' + (cnt2 + 1) % 26;
        cnt2++;
    }
    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= N; j++) {
            cout<<"   "<<a[i * (N + 2) + j];
        }
        cout<<endl;
    }

    return 0;
}
