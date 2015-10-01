#include <iostream>
using namespace std;

int* a;
int* b;
int N;

/*
包括两边
*/
int getsum(int startline, int endline, int startcol, int endcol) {
    if(startline == endline && startcol == endcol) {
        return a[(endline - 1) * N + (endcol - 1)];
    }
    
    if(startline == 1 && startcol == 1) {
        return b[(endline - 1) * N + (endcol - 1)];
    } else if(startline == 1) {
        return b[(endline - 1) * N + (endcol - 1)] - b[(endline - 1) * N + (startcol - 2)];
    } else if(startcol == 1) {
        return b[(endline - 1) * N + (endcol - 1)] - b[(startline - 2) * N + (endcol - 1)];
    } else{
        return b[(endline - 1) * N + (endcol - 1)] + b[(startline - 2) * N + (startcol - 2)] - b[(endline - 1) * N + (startcol - 2)] - b[(startline - 2) * N + (endcol - 1)];
    }
}

/*
包括两边
*/
int getMax(int startline, int endline, int startcol, int endcol) {
    int max = a[0];
    for(int i = startline; i <= endline; i++) {
        for(int j = i; j <= endline; j++) {
            for(int k = startcol; k <= endcol; k++) {
                for(int w = k; w <= endcol; w++) {
                    if(getsum(i, j, k, w) > max) {
                        max = getsum(i, j, k, w);
                    }
                }
            }
        }
    }
    return max;
}

int main() {
    while(cin>>N) {
        a = new int[N * N];
        for(int i = 0; i < N * N; i++) {
            cin>>a[i];
        }
        b = new int[N * N]; //b为a左上角的长方形和
        b[0] = a[0];
        for(int line = 1; line <= N; line++)
        for(int col = 1; col <= N; col++) {
            if(line == 1 && col == 1) {
                continue;
            } else if(col == 1) {
                b[(line - 1) * N + (col - 1)] = b[(line - 2) * N + (col - 1)] + a[(line - 1) * N + (col - 1)];
            } else if(line == 1) {
                b[(line - 1) * N + (col - 1)] = b[(line - 1) * N + (col - 2)] + a[(line - 1) * N + (col - 1)];
            } else{
                b[(line - 1) * N + (col - 1)] = a[(line - 1) * N + (col - 1)] - b[(line - 2) * N + (col - 2)] + b[(line - 2) * N + (col - 1)] + b[(line - 1) * N + (col - 2)];
            }
        }
        cout<<getMax(1, N, 1, N)<<endl;
        delete[] a;
        delete[] b;
    }
    return 0;
}
