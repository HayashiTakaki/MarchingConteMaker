#include <iostream>
#define N 3


//struct list{
//	int sum;
//	struct list *ritht;
//	struct list *left;
//	int x[N * 2];
//};

//括弧の数を数える
//右括弧の方が多い場合のみ偽を返す
int check_sum(int *x){
	int sum = 0;
	
	for (int i = 0; i < N*2; i++) {
		sum += x[i];
		
		if (sum < 0 || sum > N) {
			return 0;
		}
	}
	
	return 1;
}

void print_result(int *x){
	int i;
	for (i = 0; i < N*2; i++) {
		if (x[i] == 1) {
			printf("(");
		}else {
			printf(")");
		}
	}
	
	printf("\n");
}



void add(int *x){
	for (int i = 0; i<N*2; i++) {
		printf("%2d",x[i]);
	}printf("\n");
	
	
	printf("  sum %d\n\n",check_sum(x));
	if (!check_sum(x)) {
		return;
	}
	

	
	
	
	int i;
	int x1[N*2];
	int x2[N*2];
	
	//x1,x2にコピー
	for (i = 0; i < N*2; i++) {
		x1[i] = x[i];
		x2[i] = x[i];
	}
	
	
	
	i = 0;
	for (i = 0; i < N*2; i++) {
		if (x[i] == 0) {
			break;
		}
	}
	printf("pos = %d\n",i);
	
	if (i == N*2) {
		print_result(x);
		return;
	}
	
	x1[i] = 1;
	add(x1);
	
	x2[i] = -1;
	add(x2);
	
	
}

//struct list *make_root(){
//	struct list *p;
//	p = (struct list*)malloc(sizeof(struct list));
//	if (p == NULL) {
//		printf("error: malloc not succeed");
//	}
//	for (int i = 0; i < N*2; i++) {
//		p->x[i] = 0;
//	}
//	p->x[0] = 1;
//	p->x[N*2-1] = -1;
//	sum = 0;
//	
//	return p;
//}


int main (int argc, char * const argv[]) {
//	list *p;
//	p = make_root();
	
	//init
	int x[N*2];
//	x[0] = 1;
//	x[N*2-1] = -1;
	memset(x, 0, sizeof(x));
	add(x);
	
	
	
    return 0;
}
