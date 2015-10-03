#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <stack>
#include <sstream>
#include <string.h>
#include <utility>
#include <vector>

using namespace std;

int max(int a, int b) {
    if(a > b) return a;
    return b;
}

int min(int a, int b) {
    if(a < b) return a;
    return b;
}

int main() {
    int N;
    cin>>N;
	vector<string> receptacle;
	receptacle.resize(N);
	for(int i = 0; i < N; i++) {
		cin>>receptacle[i];
	}
	int M;
	cin>>M;
	vector<string> device;
	vector<string> deviceRec;
	device.resize(M);
	deviceRec.resize(M);
	for(int i = 0; i < M; i++) {
		cin>>device[i]>>deviceRec[i];
	}
	int K;
	cin>>K;
	vector<string> adapterFrom;
	vector<string> adapterTo;
	adapterFrom.resize(K);
	adapterTo.resize(K);
	for(int i = 0; i < K; i++) {
		cin>>adapterFrom[i]>>adapterTo[i];
	}

    int res = 0;


    cout<<res<<endl;
    
    return 0;
}
