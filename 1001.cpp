#include <string>
#include <stdio.h>
#include <memory.h>
#include <iostream>

using namespace std;

const int N = 1000; 

struct bignum{
    int a[N];
    int point; 
} num; 

bignum operator*(bignum x, bignum y) {
    bignum z;
    z.point = x.point + y.point;
    memset(z.a, 0, sizeof(z.a)); 

	for(int i = 0; i < N; i++) {
		for(int j = 0; j <= i; j++) {
			z.a[i] += x.a[j] * y.a[i - j];
		}
	}

    int carry = 0;

	for(int i = 0; i < N; i++){
		z.a[i] = z.a[i] + carry;
		carry = z.a[i] / 10;
		z.a[i] %= 10;
	}

	return z;
} 
                 
bignum square(bignum x){
	return x * x;
}

/*
x^y
*/
bignum operator&(bignum x,int y){
	if(y == 1) return x;
	if((y & 1) == 0) {
		return square(x & (y >> 1));
	} else {
		return x * square(x & (y >> 1));
	}
}

void printNum(bignum num) {
	for(int i = 0; i < N; i++) {
		cout<<num.a[i];
	}
	cout<<endl;
	cout<<"num.point "<<num.point<<endl;

	return;
}

int main(){
	char ch[6];
	int n = 0;
	while(cin>>ch>>n){
		int i = 0;
		int j = 0;
		num.point = 0;
		for(i = 5; i >= 0; i--) {
			if(ch[i] == '.') {
				num.point = 5 - i;
			} else {
				num.a[j] = ch[i] - '0';
				j++;
			}
		}

		for(; j < N; j++) {
			num.a[j] = 0;
		}

		num = (num & n);

		for(j = N - 1; j >= num.point; j--) {
			if(num.a[j] != 0) {
				break;
			}
		}

		if(j < num.point) {
			cout<<".";
			for(i = 0; i < N; i++) {
				if(num.a[i] != 0) {
					break;
				}
			}

			for(; j >= i; j--) {
				cout<<num.a[j];
			}
			cout<<endl;
		} else {
			for(; j >= num.point; j--) {
				cout<<num.a[j];
			}

			for(i = 0; i < N; i++) {
				if(num.a[i] != 0) {
					break;
				}
			}

			if(j >= i) {
				cout<<".";
				for(; j >= i; j--) {
					cout<<num.a[j];
				}
			}
			cout<<endl;
		}
	}
	return 0; 
}
