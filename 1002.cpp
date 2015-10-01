#include <map>
#include <string>
#include <iostream>
using namespace std;

int main() {
    map<string, int> tele;
    map<string, int>::iterator iter;
    string number;

    int N = 0;
    cin>>N;

    for(int i = 0; i < N; i++) {
        cin >> number;
        for(int j = 0; j < number.size(); j++) {
            if(number[j] <= 'C' && number[j] >= 'A') {
                number[j] = '2';
            } else if(number[j] <= 'F' && number[j] >= 'D') {
                number[j] = '3';
            } else if(number[j] <= 'I' && number[j] >= 'G') {
                number[j] = '4';
            } else if(number[j] <= 'L' && number[j] >= 'J') {
                number[j] = '5';
            } else if(number[j] <= 'O' && number[j] >= 'M') {
                number[j] = '6';
            } else if(number[j] == 'P' || number[j] == 'R' || number[j] == 'S') {
                number[j] = '7';
            } else if(number[j] <= 'V' && number[j] >= 'T') {
                number[j] = '8';
            } else if(number[j] <= 'Y' && number[j] >= 'W') {
                number[j] = '9';
            }
        }

        for(int j = 0; j < number.size(); j++) {
            if(number[j] == '-') {
                number.erase(j, 1);
                j--;
            }
        }

        if(tele.find(number) != tele.end()) {
            tele[number]++;
        } else {
            tele.insert(pair<string, int>(number, 1));
        }
    }

    int cnt = 0;
    for(iter = tele.begin(); iter != tele.end(); iter++) {
        if(iter->second > 1) {
            cnt = 1;
            cout<<iter->first.substr(0, 3)<<"-"<<iter->first.substr(3, 4)<<" "<<iter->second<<endl;
        }
    }
    if(cnt == 0) {
        cout<<"No duplicates."<<endl;
    }

    return 0;
}
