#include <iostream>

//引き算
//返り値　a-bの結果
int minus(int a, int b){
	int n;
	if (a > b) {
		
		//a+n=bになる数を探索
		for (n = 0; n <= abs(a)+abs(b); n++) {
			if (b + n == a) {
				return n;
			}
		}
	}else {

		//b+n=aになる数を探索
		for (n = 0; n <= abs(a)+abs(b); n += (-1)) {
			if (b + n == a) {
				return n;
			}
		}
	}

	return 0;
}


//かけ算
//返り値　a*bの結果
int multiply(int a, int b){
	
	int sum = 0;
	
	//swap
	if (abs(a) < abs(b)) {
		int c;
		c = a;
		a = b;
		b = c;
	}
	
	//sumにaをb回加算する
	for (int i = 0; i < abs(b); i++) {
		sum += a;
	}
	
	//符号の調整
	if (a < 0 && b < 0) {
		sum = minus(0, sum);
	}else if (b < 0) {
		sum = minus(0, sum);
	}
	
	return sum;
}


//割り算
//返り値　a/bの結果
//0の場合はエラーを返す
int divide(int a, int b){
	int ans = 0;
	int temp = abs(a);
	
	
	//0除算
	if (b == 0) {
		printf("error: divided by 0\n");
		exit(2);
	}
	
	//a<bならば0を返却
	if (abs(a) < abs(b)) {
		return 0;
	}
	
	//a<bになるまでa-bを繰り返す
	while (temp > 0) {
		temp = minus(temp, abs(b));
		ans += 1;
	}
	ans = minus(ans, 1);
	
	
	
	//符号の調整
	if (a < 0 && b > 0  ||  a > 0 && b < 0) {
		ans = minus(0, ans);
	}
	
	
	return ans;
}

int main (int argc, char * const argv[]) {
	int a,b;
	a = 0;
	b = 0;
	
	printf("a = %d, b = %d\n",a, b);
	printf("minus %d\n",minus(a, b));
	printf("mul %d\n",multiply(a, b));
	printf("div %d\n\n",divide(a, b));
	
	printf("a = %d, b = %d\n",-a, b);
	printf("minus %d\n",minus(-a, b));
	printf("mul %d\n",multiply(-a, b));
	printf("div %d\n\n",divide(-a, b));
	
	printf("a = %d, b = %d\n",a, -b);
	printf("minus %d\n",minus(a, -b));
	printf("mul %d\n",multiply(a, -b));
	printf("div %d\n\n",divide(a, -b));
	
	printf("a = %d, b = %d\n",-a, -b);
	printf("minus %d\n",minus(-a, -b));
	printf("mul %d\n",multiply(-a, -b));
	printf("div %d\n\n",divide(-a, -b));
	
	return 0;
}
