#include <iostream>

using namespace std;

struct group {
    int x;
    int y;
    int cnt;
    group(int x = 0, int y = 0, int cnt = 0);
};

group::group(int x, int y, int cnt) {
    this->x = x;
    this->y = y;
    this->cnt = cnt;
}

const int N = (1<<21);
group* h;

int getHash(int x, int y) {
    return (x * y + 1331 * x - 3113 * y + 32) & (N - 1);
}

int main() {
    int t;
    scanf("%d", &t);
    h = new group[N];
    while(t) {
        t--;
        int n;
        scanf("%d", &n);
        memset(h, 0, sizeof(group) * N);
        int x[1000];
        int y[1000];
        int res = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d%d", &x[i], &y[i]);
            for(int j = 0; j < i; j++) {
                int tmph = getHash(x[j] + x[i], y[j] + y[i]);
                while(h[tmph].cnt > 0) {
                    if(x[j] + x[i] == h[tmph].x && y[j] + y[i] == h[tmph].y) {
                        res += h[tmph].cnt;
                        h[tmph].cnt++;
                        break;
                    }
                    tmph = (tmph + 1) & (N - 1);
                }
                if(h[tmph].cnt == 0) {
                    h[tmph].x = x[j] + x[i];
                    h[tmph].y = y[j] + y[i];
                    h[tmph].cnt = 1;
                }
            }
        }

        printf("%d\n", res);
    }
    delete[] h;

    return 0;
}
