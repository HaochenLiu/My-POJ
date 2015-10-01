# include <iostream>
using namespace std;

int main() {
    int p, e, i, d;
    int result = 0;
    int count = 0;
    while(cin>>p>>e>>i>>d) {
        if(p == -1) {
            break;
        }        
        count++;
        result = (p * 28 * 33 * 6 + e * 23 * 33 * 19 + i * 23 * 28 * 2 - d) % (23 * 28 * 33);
        //最后乘上一个数，使得模另一个数，余1
        if(result <= 0) {
            result += 23 * 28 * 33;
        }
        cout<<"Case "<<count<<": the next triple peak occurs in "<<result<<" days."<<endl;
    }

    return 0;
}
