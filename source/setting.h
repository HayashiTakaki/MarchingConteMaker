#include <iostream>
#include <fstream>
using namespace std;



member* members = new member[maximum_member];


setting::setting(){
	char title_co[25];
  
  /*変数の初期化*/
	for (int i =0; i<25; i++){
		title[i]=0;
    title_co[i]=0;
  }
	
	now = 0;
	max_conte = 0;
	point = 0;
	member_num = 0;
	aut = 1;
	display_size_x=800;
	display_size_y=600;
	conte_size = 2;
	xinterbal = 1/20;
	yinterbal = 1/16;
	start_stop = 0;
  shape = 0;
  screen_mode = 0;
  
	
	
	for (int i=0; i<maximum_member; i++) {
		tempo[i]=120;
		move[i]=8;
    strcpy(coment[i] , "non");
	}
	
	
	
	/*初期設定*/
	printf("開くファイル名を入力してください.\n");
	std::cin >> title;
  
  strcpy(title_co, title);
	strcat(title_co, ".con");
	
	
	/*=======================*/
	/*ファイルが存在するか検索　　 */
	
	ifstream fread(title_co);
	if(fread){
		cout << title_co<<"を読み込みます.\n";
	}else {
		cout << title_co<<"が存在しないので新規作成します.\n";
		
		std::cout << "メンバー数を入力してください.\n";
		std::cin >> member_num;
		
		member::set_max_member(member_num);
		
		
	}
	
}

int setting:: return_num_of_member(){return member_num;}

void setting::set_display_size(int x,int y){
	display_size_x=x;
	display_size_y=y;
}


int setting::size_x(){return display_size_x;}
int setting::size_y(){return display_size_y;}
int setting::return_now(){return now;}

void setting::set_point(int i){point = i;}
int setting::return_point(){return point;}

void setting::next(){
	now++;
	if(now>max_conte)
		max_conte++;
}
void setting::origin(){now=0;}
void setting::change_move(int i){move[now]=i;}
void setting::change_tempo(int i){
	for (int w=0; w+now<maximum_member; w++) 
		tempo[now+w]=i;
}

void setting::back(){if(now!=0)now--;}
void setting::change_no_and_maxconte(int no, int max){
  now = no;
  max_conte = max;
}


char * setting::return_title(){return title;}

int setting::return_move(int i){return move[i];}
int setting::return_tempo(int i){return tempo[i];}
int setting::return_max_conte(){return max_conte;}
bool setting::return_aut(){return aut;}
int setting::return_conte_size(){return conte_size;}
bool setting::return_conte_grid(){return conte_grid;}
bool setting::return_shape(){return shape;}

void setting::last(){now=max_conte;}

void setting::change_aut(){
	if(aut==1)aut=0;
	else aut=1;
}
void setting::change_conte_size(int n){
	conte_size = n;
}
void setting::change_conte_grid(){
	if(conte_grid==1)conte_grid=0;
	else conte_grid=1;
}

void setting::change_start_stop(){
	if(start_stop==1)start_stop=0;
	else start_stop=1;
}

void setting::change_shape(){
  if(shape==1)shape=0;
	else shape=1;
}


void setting::reset_position(){
	if (return_now() == 0)return;
	int n = return_now();
	
  //範囲選択済み
  if (mouse.marray[0] != NULL) {
    for (int i = 0; mouse.marray[i]!=NULL; i++) {
			mouse.marray[i]->change_xpos(n, mouse.marray[i]->return_xpos(n-1));
			mouse.marray[i]->change_ypos(n, mouse.marray[i]->return_ypos(n-1));
		}
  
  //範囲選択無し→全員リセット
  }else{
    for (int i = 0; i < return_num_of_member(); i++) {
      members[i].change_xpos(n, members[i].return_xpos(n-1));
      members[i].change_ypos(n, members[i].return_ypos(n-1));
    }
  }
}

void setting::set_coment(int i, char* s){
  strcpy(coment[i] , s);
}

char * setting::get_coment(int n)
{
  return coment[n];
}

void setting::set_coment(char* s)
{
  strcpy(coment[now] , s);
}




void setting::read_file(char * name){
	
  char s[maximum_member];
  strcpy(s, name);
  strcat(s, ".con");
  cout << s;
	ifstream read(s);
	
	
	char buff[500];
	
  //捨て
	read >> buff;
  //メンバー数
	read >> member_num;
	
  //捨て
	read >> buff;
  //コンテの最後
	read >> max_conte;
  
  //捨て
	read >> buff;
  //コンテサイズ
	read >> conte_size;
  
	
  //捨て
	read >> buff;
  //Move数
	for (int i=0; i<maximum_member; i++) 
		read >> move[i];
	
  //捨て
	read >> buff;
  //テンポ
	for (int i=0; i<maximum_member; i++) 
		read >> tempo[i];
	
	char c[4];
	double x;
	
  //メンバー情報
  for (int i=0; i<member_num; i++) {
		//名前
    read >> c;
		cout <<i<< c <<endl;
		members[i].set_name(c);
    members[i].set_shape_type();
		
    //x座標
		for (int j=0; j<maximum_member; j++) {
			read >> x;
			members[i].change_xpos(j,x);
		}
    
    //y座標
		for (int j=0; j<maximum_member; j++) {
			read >> x;
			members[i].change_ypos(j,x);
		}
	}
  
  
  //coment
  for (int i = 0; i < maximum_member; i++) {
    read >> buff;
    read >> buff;
    set_coment(i,buff);
  }
	
	
}





