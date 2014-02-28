using namespace std;


//結果を格納する為の構造体
struct p {
	int sum;
	int num;
};


class no7{
private:
	int N;
	int K;
	int count;
	int **star;
	int debug;
	
public:
	
	//標準入力
	no7(){
		//N&Kの入力
		printf("input N\n>");
		cin >> N;
		
		printf("input K\n>");
		cin >> K;
		
		
		//配列の割当
		star = (int **)malloc(sizeof(int *) * N);
		
		//error
		if (star == NULL) {
			printf("malloc error\n");
			exit(2);
		}
		
		for (int i = 0; i < N; i++) {
			star[i] = (int *)malloc(sizeof(int) * N);
			
			//error
			if (star[i] == NULL) {
				printf("malloc error\n");
				exit(2);
			}
		}
		
		
		
		//配列の初期化
		for (int n = 0; n < N; n++) {
			for (int k = 0; k < N; k++) {
				star[n][k] = 0;
			}
		}
		
		
		//星の座標を入力
		cout << "input star location X,Y\n";
		int x,y;
		int k = 0;
		while (k < K) {
			
			cout << "star location " << k+1 << " / " << K << ">";
			cin >> x;
			cin >> y;
			while (x<0 || N<=x || y<0 || N<=y) {
				printf("illigal input x or y\n");
				printf("input x&x\n>");
				cin >> x;
				cin >> y;
			}
			
			
			star[x][y] = 1;
			
			k++;
			
			
		}
		
		
		debug = 0;
		printf("***************\n\n");
	}
	
	
	//テキストファイルからの入力
	no7(char *s){
		FILE *fp;
		fp = fopen(s, "r");
		if (fp == NULL) {
			printf("error: %s is not found\n",s);
			exit(2);
		}
		
		
		fscanf(fp, "%d",&N);
		
		//配列の割当
		star = (int **)malloc(sizeof(int *) * N);
		
		//error
		if (star == NULL) {
			printf("malloc error\n");
			exit(2);
		}
		
		
		for (int i = 0; i < N; i++) {
			star[i] = (int *)malloc(sizeof(int) * N);
			
			//error
			if (star[i] == NULL) {
				printf("malloc error\n");
				exit(2);
			}
			
		}
		
		
		
		
		//星の座標を入力
		int k=0;
		while (k <= N*N) {
			for (int i = 0; i < N; i++) {
				for (int n = 0; n < N; n++) {
					fscanf(fp, "%d",&star[i][n]);
				}
			}
			k++;
		}
		
		
		debug = 1;
	}
	
	//x軸で最も星の多い場所を探索
	struct p serch_max_x(){
		int sum = 0;
		
		//結果を格納する為の構造体
		//sum：星の数
		//num：最も星の多い配列の添字
		struct p result;
		result.sum = 0;
		result.num = -1;
		
		for (int i = 0; i < N; i++) {
			//init
			sum = 0;
			for (int k = 0; k < N; k++) {
				sum += star[i][k];
			}
			
			//結果を格納
			if (result.sum < sum) {
				result.sum = sum;
				result.num = i;
			}
		}
		
		return result;
	}
	
	//y軸で最も星の多い場所を探索
	struct p serch_max_y(){
		int sum = 0;
		
		//結果を格納する為の構造体
		//sum：星の数
		//num：最も星の多い配列の添字
		struct p result;
		result.sum = 0;
		result.num = -1;
		
		for (int i = 0; i < N; i++) {
			sum = 0;
			for (int k = 0; k < N; k++) {
				sum += star[k][i];
			}
			
			//結果を格納
			if (result.sum < sum) {
				result.sum = sum;
				result.num = i;
			}
		}
		
		return result;
	}
	
	//x軸のn列目を消去
	void delete_x(int n){
		count++;
		printf("%d times",count);
		
		for (int i = 0; i < N; i++) {
			if (star[n][i]) {
				star[n][i] = 0;
				printf("(%d,%d)",i,n);
			}
		}
		printf("break\n");
		
		return;
	}
	
	//y軸のn行目を消去
	void delete_y(int n){
		count++;
		printf("%d times",count);
		for (int i = 0; i < N; i++) {
			if (star[i][n]) {
				star[i][n] = 0;
				printf("(%d,%d)",i,n);
			}
		}
		
		printf("break\n");

		return;
	}
	
	//星を表示(デバッグ用)
	void show_star(){
		for (int i = 0; i < N; i++) {
			for (int k = 0; k < N; k++) {
				if (star[i][k]) {
					printf("* ");
				}else {
					printf("- ");
				}				
			}
			printf("\n");
		}
		printf("\n");
	}
	
	//シミュレーション開始
	void start_sim(){
		struct p x = serch_max_x();
		struct p y = serch_max_y();
		
		while (x.num != -1 && y.num != -1) {
			if (debug) {
				show_star();
			}
			if (x.sum > y.sum) {
				delete_x(x.num);
			}else {
				delete_y(y.num);
			}
			
			x = serch_max_x();
			y = serch_max_y();
			
		}
		
		if (debug) {
			show_star();
		}
		
		printf("\n\n****************\ntotal %d\n",count);
	}
	
};
