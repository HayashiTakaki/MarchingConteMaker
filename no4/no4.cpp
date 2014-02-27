#include <iostream>

int minus(int a, int b){
	
	if (a > b) {
		//a+n=bになる数を探索
		for (int n = 0; n < b; n++) {
			if (b + n == a) {
				return n;
			}
		}
	}else {
		//a+n=bになる数を探索
		for (int n = 0; n < b; n += (-1)) {
			if (b + n == a) {
				return n;
			}
		}
	}

	return 0;
}

int multiply(int a, int b){
	
	int sum = 0;
	
	for (int i = 0; i < abs(b); i++) {
		sum += a;
	}
	
	return sum;
}

int divide(int a, int b){
	int ans = 0;
	while (a > 0) {
		a = minus(a, b);
	}
	
	return (ans+1);
}

int main (int argc, char * const argv[]) {
	int a,b;
	a = 5;
	b = 3;
	
	printf("minus %d\n",minus(a, b));
	printf("mul %d\n",multiply(a, b));
	printf("div %d\n",divide(a, b));
	
	return 0;
}
