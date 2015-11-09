#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> A(500, 0);
int N;
int m;
int k;

int max(int a, int b) {
    if(a > b) return a;
    return b;
}

bool canFinish(long long time) {
    int cnt = 1;
    long long remain = 0;
    for(int i = 0; i < m; i++) {
        if(remain + A[i] > time) {
            remain = A[i];
            cnt++;
            if(cnt > k) {
                return false;
            }
        } else {
            remain += A[i];
        }
    }
    return true;
}

int getTime() {
    long long left = 0;
    long long right = 0;
    for(int i = 0; i < m; i++) {
        left = max(left, A[i]);
        right += A[i];
    }

    while(left < right) {
        long long mid = left + (right - left) / 2;
        if(canFinish(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    cin>>N;
    while(N--) {
        cin>>m>>k;
        for(int i = 0; i < m; i++) {
            cin>>A[i];
        }
        int time = getTime();
        set<int> par;
        int mergeCnt = 0;
        int remain = 0;
        for(int i = m - 1; i > 0; i--) {
            if(remain + A[i] > time) {
                remain = A[i];
                par.insert(i + 1);
            } else {
                remain += A[i];
                if(mergeCnt == m - k) {
                    for(int j = i; j > 0; j--) {
                        par.insert(j);
                    }
                    break;
                }
                mergeCnt++;
            }            
        }

        cout<<A[0];
        for(int i = 1; i < m; i++) {
            if(par.count(i) > 0) {
                cout<<" / ";
            } else {
                cout<<" ";
            }
            cout<<A[i];
        }
        cout<<endl;
    }

    return 0;
}
