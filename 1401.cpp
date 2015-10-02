#include <iostream>
using namespace std;

int main() {
    int N;
    cin>>N;
    int n;
    int zerocount;
    for(int i = 0; i < N; i++) {
        cin>>n;
        zerocount = 0;
        while(n != 0) {
            zerocount += (n /= 5);
        }
        cout<<zerocount<<endl;
    }

    return 0;
}
