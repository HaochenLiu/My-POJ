#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void computeMinCost(const vector<int>& A, vector<vector<int>>& cost) {
    // Min cost of building a post office between house (i, j).
    // This post office must be in median position.
    const int n = A.size();
    for(int i = 0; i < n; i++) {
        cost[i][i] = 0;
    }

    for(int i = 0; i < n - 1; i++) {
        cost[i][i + 1] = A[i + 1] - A[i];
    }

    for(int i = 1; i < n - 1; i++) {
        for(int j = 1; j <= i && j < n - i; j++) {
            cost[i - j][i + j] = cost[i - j + 1][i + j - 1] + A[i + j] - A[i - j];
        }
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = 2; j <= i + 1 && j < n - i; j++) {
            cost[i - j + 1][i + j] = cost[i - j + 2][i + j - 1] + A[i + j] - A[i - j + 1];
        }
    }
}

int postOffice(vector<int>& A, int k) {
    const int n = A.size();
    if (A.empty() || k >= n || k <= 0) return 0;
    sort(A.begin(), A.end());

    // Precompute cost.
    // Time:  O(n^2)
    // Space: O(n^2)
    vector<vector<int>> cost(n, vector<int>(n, 0));
    computeMinCost(A, cost);

    // DP of sum.
    // Time:  O(nk)
    // Space: O(nk)
    // sum[i][j] denotes the smallest sum of
    // picking i + 1 post offices for the first j + 1 houses.
    vector<vector<int>> sum(k, vector<int>(n, INT_MAX / 2));
    vector<vector<int>> pos(k, vector<int>(n + 1, 0));
    for(int j = 0; j < n; j++) {
        sum[0][j] = cost[0][j];
    }

    for(int i = 0; i < k; i++) {
        sum[i][0] = 0;
    }

    for(int i = 1; i < k; i++) {
        pos[i][n] = n - 2;
        for(int j = n - 1; j >= 1; j--) {
            for(int r = pos[i - 1][j]; r <= pos[i][j + 1]; r++) {
                if(sum[i - 1][r] + cost[r + 1][j] < sum[i][j]) {
                    sum[i][j] = sum[i - 1][r] + cost[r + 1][j];
                    pos[i][j] = r;
                }
            }
        }
    }
    return sum[k - 1][n - 1];
}

int main() {
    int V;
    int P;
    cin>>V>>P;
    vector<int> A(V, 0);
    for(int i = 0; i < V; i++) {
        cin>>A[i];
    }
    cout<<postOffice(A, P)<<endl;

    return 0;
}
