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
    }
    else if(startline == 1) {
        return b[(endline - 1) * N + (endcol - 1)] - b[(endline - 1) * N + (startcol - 2)];
    }
    else if(startcol == 1) {
        return b[(endline - 1) * N + (endcol - 1)] - b[(startline - 2) * N + (endcol - 1)];
    }
    else{
        return b[(endline - 1) * N + (endcol - 1)] + b[(startline - 2) * N + (startcol - 2)] - b[(endline - 1) * N + (startcol - 2)] - b[(startline - 2) * N + (endcol - 1)];
    }
}

/*
包括两边
*/
int getMax(int startline, int endline, int startcol, int endcol)
{
    if(endline - startline == 0 && endcol - startcol == 0) {
        return b[(startline - 1) * N + (startcol - 1)];
    }
    if(endline - startline > endcol - startcol) {
        int mid = (startline + endline) >> 1;
        int max1 = getMax(startline, mid, startcol, endcol);
        int max2 = getMax(mid + 1, endline, startcol, endcol);
        int max = (max1 > max2)? max1: max2;
        int cross = 0;
        int tmp = -2000000;
        for(int i = startcol; i <= endcol; i++)
        for(int j = i; j <= endcol; j++) {
            tmp = -2000000;
            for(int k = mid + 1; k <= endline; k++) {
                tmp = (tmp > getsum(mid + 1, k, i, j))? tmp: getsum(mid + 1, k, i, j);
            }
            cross = tmp;
            tmp = -2000000;
            for(int k = mid; k >= startline; k--) {
                tmp = (tmp > getsum(k, mid, i, j))? tmp: getsum(k, mid, i, j);
            }
            cross += tmp;
            max = (max > cross)? max: cross;
            cross = 0;
        }
        return max;
    } else {
        int mid = (startcol + endcol) >> 1;
        int max1 = getMax(startline, endline, startcol, mid);
        int max2 = getMax(startline, endline, mid + 1, endcol);
        int max = (max1 > max2)? max1: max2;
        int cross = 0;
        int tmp = -2000000;
        for(int i = startline; i <= endline; i++)
        for(int j = i; j <= endline; j++) {
            tmp = -2000000;
            for(int k = mid + 1; k <= endcol; k++) {
                tmp = (tmp > getsum(i, j, mid + 1, k))? tmp: getsum(i, j, mid + 1, k);
            }
            cross = tmp;
            tmp = -2000000;
            for(int k = mid; k >= startcol; k--) {
                tmp = (tmp > getsum(i, j, k, mid))? tmp: getsum(i, j, k, mid);
            }
            cross += tmp;
            max = (max > cross)? max: cross;
            cross = 0;
        }
        return max;
    }
}

int main() {
    while(cin>>N) {
        a = new int[N * N];
        for(int i = 0; i < N * N; i++) {
            cin>>a[i];
        }
        b = new int[N * N]; //b为a左上角的长方形和
        b[0] = a[0];
        for(int line = 1; line <= N; line++) {
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
        }
        cout<<getMax(1, N, 1, N)<<endl;
        delete[] a;
        delete[] b;
    }
    return 0;
}
