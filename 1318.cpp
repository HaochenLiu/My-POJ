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

struct group {
	string str;
	int let[26];
	group(string str);
};

group::group(string str) {
	this->str = str;
	for(int i = 0; i < 26; i++) {
		let[i] = 0;
	}

	for(int i = 0; i < str.length(); i++) {
		let[str[i] - 'a']++;
	}
}

int main() {
	list<group> dic;
	list<group> search;
	string s = "";
	int option = 0;
	while(cin>>s) {
		if(option == 0 && s == "XXXXXX") {
			option = 1;
			continue;
		}

		if(option == 1 && s == "XXXXXX") {
			break;
		}

		if(option == 0) {
			dic.push_back(group(s));
		} else {
			search.push_back(group(s));
		}
	}
	list<group>::iterator it = search.begin();
	list<group>::iterator dicit = dic.begin();
	list<string> tmp;
	while(it != search.end()) {
		int count = 0;
		dicit = dic.begin();
		while(dicit != dic.end()) {
			bool test = true;
			for(int i = 0; i < 26; i++) {
				if(it->let[i] != dicit->let[i]) {	
					test = false;
					break;
				}
			}
			if(test) {
				count++;
				tmp.push_back(dicit->str);
			}
			dicit++;
		}
		if(count == 0) {
			cout<<"NOT A VALID WORD\n******"<<endl;
		} else {
			tmp.sort();
			list<string>::iterator tmpit = tmp.begin();
			while(tmpit != tmp.end()) {
				cout<<*tmpit<<endl;
				tmpit++;
			}
			cout<<"******"<<endl;
			tmp.clear();
		}
		it++;
	}
	return 0;
}
