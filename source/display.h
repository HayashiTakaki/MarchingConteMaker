/*
 *  display.h
 *  con+
 *
 *  Created by 林 孝樹 on 12/11/25.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include <fstream>
using namespace std;

int waiting(double time){
	clock_t c1=clock(),c2;
	do{c2=clock();
	}while (1000*(c2-c1)/CLOCKS_PER_SEC<time);
	return 0;
}



static class Display{
public:
	Display(){};
	static void play_test();
	static void display();
	static void play2();
  static void play_reverse();
}display;

void Display::display(){/*コンテ表示*/
	
	//フィールド表示
	field::drow_grid(set.return_conte_size(),set.return_conte_grid());
	
	//No，テンポ表示
	print_No(set.return_now());
	if(set.return_now()!=0)
		print_Move(set.return_move(set.return_now()));
	if(set.return_now()==0||set.return_tempo(set.return_now())!=set.return_tempo(set.return_now()-1))
		print_tempo(set.return_tempo(set.return_now()));
	
	
	//範囲選択枠
	if (mouse.drow_rect) {
		glColor3f(1, 1, 0);
		glBegin(GL_LINE_LOOP);
		glVertex2d(mouse.x1,mouse.y1);
		glVertex2d(mouse.x1,mouse.y2);
		glVertex2d(mouse.x2,mouse.y2);
		glVertex2d(mouse.x2,mouse.y1);
		glEnd();
	}
	
  
  //コメントの表示
  if (strcmp(set.get_coment(set.return_now()),("non"))) {
    glColor3d(0, 0, 0);
    DrawString(set.get_coment(set.return_now()), 0.7, 0.5);
  }
 	
  //タイトルの表示
  glColor3d(0, 0, 0);
  DrawString(set.return_title(), 0 - strlen(set.return_title())*0.02, 0.9);


  //距離情報の表示
  print_net();

  cout << member::return_count();

  
	
	 glColor3d(0.5, 0.5, 1);
	/*メンバー表示*/
	for (int i=0; i<member::return_count(); i++) {
		members[i].drow_goust(set.return_now());	
	}
	for (int i=0; i<member::return_count(); i++) {
		members[i].put_member(set.return_now());
	}
	
	
  print_warning_net();


	glutSwapBuffers();
}



int search_close(double x,double y){
	
	int close=0;
	double min=2;
	for (int i = 0; i<set.return_num_of_member();i++) {
		if(members[i].distance(x,y,set.return_now())<min){
			close = i;
			min = members[i].distance(x,y,set.return_now());
		}
		
	}
	
	return close;
}

double search_close_distance(double x,double y){
	
	double min=2;
	for (int i = 0; i<set.return_num_of_member();i++) {
		if(members[i].distance(x,y,set.return_now())<min){
			min = members[i].distance(x,y,set.return_now());
		}
		
	}
	
	return min;
}

void print_net(){
	int n = set.return_now();
	
	for (int i= 0; i<set.return_num_of_member(); i++) {
		double x1 = members[i].return_xpos(n)+members[i].return_sx();
		double y1 = members[i].return_ypos(n)+members[i].return_sy();
		
		for (int k = i+1; k < set.return_num_of_member(); k++) {
			double x2 = members[k].return_xpos(n)+members[k].return_sx();
			double y2 = members[k].return_ypos(n)+members[k].return_sy();
			if((set.return_conte_size()==2 && sqrt(pow((x1-x2)*18, 2)+pow((y1-y2)*14, 2))<sqrt(8.1))||
				 (set.return_conte_size()==1 && sqrt(pow((x1-x2)*16, 2)+pow((y1-y2)*12, 2))<sqrt(8.1))||
				 (set.return_conte_size()==3 && sqrt(pow((x1-x2)*18, 2)+pow((y1-y2)*16, 2))<sqrt(8.1))){
				glLineWidth(1.2);
				glColor3f(0.2,1,0.6);
				glBegin(GL_LINE_STRIP);
				glVertex2d(x1, y1);
				glVertex2d(x2, y2);
				glEnd();
			}
      
		}
	}
}

void print_warning_net()
{
  int n = set.return_now();
  double xd, yd;
  if (set.return_conte_size()==2) {
    xd = 18;
    yd = 14;
  }if (set.return_conte_size()==3) {
    xd = 22;
    yd = 18;
  }else{
    xd = 16;
    yd = 12;
  }
  
  
  for (int i= 0; i<set.return_num_of_member(); i++) {
		double x1 = members[i].return_xpos(n)+members[i].return_sx();
		double y1 = members[i].return_ypos(n)+members[i].return_sy();
		
		for (int k = i+1; k < set.return_num_of_member(); k++) {
			double x2 = members[k].return_xpos(n)+members[k].return_sx();
			double y2 = members[k].return_ypos(n)+members[k].return_sy();
      
      double d =sqrt(pow((x1-x2)*xd, 2) + pow((y1-y2)*yd, 2));
      int t1 = members[i].return_shape_type();
      int t2 = members[k].return_shape_type();
      
      double wd = warning_d(t1,t2);
      double ed = error_d(t1,t2);
      
      
      if(d < wd){
        if (d < ed) {
          glColor3f(1,0,0);
        }else{
          glColor3f(1,1,0);
        }
				glLineWidth(2);
				glBegin(GL_LINE_STRIP);
				glVertex2d(x1, y1);
				glVertex2d(x2, y2);
				glEnd();
			}
			
		}
	}

}

void print_net_move(int n,int t){
	
	for (int i= 0; i<set.return_num_of_member(); i++) {
		double x1 = members[i].return_xpos(n)+members[i].return_dx()*t;
		double y1 = members[i].return_ypos(n)+members[i].return_dy()*t;
		
		for (int k = i+1; k < set.return_num_of_member(); k++) {
			double x2 = members[k].return_xpos(n)+members[k].return_dx()*t;
			double y2 = members[k].return_ypos(n)+members[k].return_dy()*t;
      if((set.return_conte_size()==2 && sqrt(pow((x1-x2)*18, 2)+pow((y1-y2)*14, 2))<sqrt(8.1))||
				 (set.return_conte_size()==1 && sqrt(pow((x1-x2)*16, 2)+pow((y1-y2)*12, 2))<sqrt(8.1))||
				  (set.return_conte_size()==3 && sqrt(pow((x1-x2)*22, 2)+pow((y1-y2)*18, 2))<sqrt(8.1))){
				glLineWidth(1.2);
				glColor3f(0.2,1,0.6);
				glBegin(GL_LINE_STRIP);
				glVertex2d(x1, y1);
				glVertex2d(x2, y2);
				glEnd();
			}
			
		}
	}
}

double warning_d(int a, int b)
{
  int n1, n2;
  double e = 0.05;
  
  switch (a) {
    case Trombone:
    case Flute:
    case Other_instrument:
      n1 = 1;
      break;
      
    case Sousaphone:
      n1 = 2;
      break;
    
    case Color_Guard:
      n1 = 3;
      break;
      
    default:
      n1 = 4;
      break;
  }
  
  switch (b) {
    case Trombone:
    case Flute:
    case Other_instrument:
      n2 = 1;
      break;
      
    case Sousaphone:
      n2 = 2;
      break;
      
    case Color_Guard:
      n2 = 3;
      break;
      
    default:
      n2 = 4;
      break;
  }
  
  if (n1==1 && n2==1) {return 2.0-e;}
  else if (n1==1&&n2==2){return 2.0-e;}
  else if (n1==1&&n2==3){return 3.0-e;}
  else if (n1==1&&n2==4){return 2.5-e;}
  else if (n1==2&&n2==1){return 2.0-e;}
  else if (n1==2&&n2==2){return 3.0-e;}
  else if (n1==2&&n2==3){return 4.0-e;}
  else if (n1==2&&n2==4){return 3.0-e;}
  else if (n1==3&&n2==1){return 3.0-e;}
  else if (n1==3&&n2==2){return 4.0-e;}
  else if (n1==3&&n2==3){return 6.0-e;}
  else if (n1==3&&n2==4){return 4.0-e;}
  else if (n1==4&&n2==1){return 2.5-e;}
  else if (n1==4&&n2==2){return 3.0-e;}
  else if (n1==4&&n2==3){return 4.0-e;}
  else if (n1==4&&n2==4){return 2.0-e;}
  
  return 2;
}


double error_d(int a, int b)
{
  int n1, n2;
  double e = 0.05;

  switch (a) {
    case Trombone:
    case Flute:
    case Other_instrument:
      n1 = 1;
      break;
      
    case Sousaphone:
      n1 = 2;
      break;
      
    case Color_Guard:
      n1 = 3;
      break;
      
    default:
      n1 = 4;
      break;
  }
  
  switch (b) {
    case Trombone:
    case Flute:
    case Other_instrument:
      n2 = 1;
      break;
      
    case Sousaphone:
      n2 = 2;
      break;
      
    case Color_Guard:
      n2 = 3;
      break;
      
    default:
      n2 = 4;
      break;
  }
  
  if (n1==1 && n2==1) {return sqrt(2.0)-e;}
  else if (n1==1&&n2==2){return sqrt(2.0)-e;}
  else if (n1==1&&n2==3){return 2.0-e;}
  else if (n1==1&&n2==4){return 2.0-e;}
  else if (n1==2&&n2==1){return sqrt(2.0)-e;}
  else if (n1==2&&n2==2){return 2.0-e;}
  else if (n1==2&&n2==3){return 3.0-e;}
  else if (n1==2&&n2==4){return 2.5-e;}
  else if (n1==3&&n2==1){return 2.0-e;}
  else if (n1==3&&n2==2){return 3.0-e;}
  else if (n1==3&&n2==3){return 3.0-e;}
  else if (n1==3&&n2==4){return 3.0-e;}
  else if (n1==4&&n2==1){return 2.0-e;}
  else if (n1==4&&n2==2){return 2.5-e;}
  else if (n1==4&&n2==3){return 3.0-e;}
  else if (n1==4&&n2==4){return 1.0-e;}
  
  
  return 2;
}


void print_warning_net_move(int n, int t){
  double xd, yd;
  if (set.return_conte_size()==2) {
    xd = 18;
    yd = 14;
  }else if (set.return_conte_size()==3) {
    xd = 22;
    yd = 18;
  }else{
    xd = 16;
    yd = 12;
  }
  
  
  for (int i= 0; i<set.return_num_of_member(); i++) {
		double x1 = members[i].return_xpos(n)+members[i].return_dx()*t;
		double y1 = members[i].return_ypos(n)+members[i].return_dy()*t;
		
		for (int k = i+1; k < set.return_num_of_member(); k++) {
			double x2 = members[k].return_xpos(n)+members[k].return_dx()*t;
			double y2 = members[k].return_ypos(n)+members[k].return_dy()*t;
      
      double d =sqrt(pow((x1-x2)*xd, 2) + pow((y1-y2)*yd, 2));
      int t1 = members[i].return_shape_type();
      int t2 = members[k].return_shape_type();
     
      double wd = warning_d(t1,t2);
      double ed = error_d(t1,t2);
      
      
      if(d < wd){
        if (d < ed) {
          glColor3f(1,0,0);
        }else{
          glColor3f(1,1,0);
        }
				glLineWidth(2);
				glBegin(GL_LINE_STRIP);
				glVertex2d(x1, y1);
				glVertex2d(x2, y2);
				glEnd();
			}
			
		}
	}
}



/*ファイルへの書き出し*/
void save(){
	std::string buff;
	printf("save \n");
	cout << set.return_title();
	

	char title[maximum_member];
	strcpy(title, set.return_title());
	strcat(title, ".con");
	
	ofstream fout(title,ios::trunc );
	
	if(fout) {
		fout << "Num_of_member " << set.return_num_of_member() <<endl;
		fout << "Finish_conte " << set.return_max_conte() <<endl;
    fout << "Conte_size " << set.return_conte_size() << endl;
 		
		fout << "Move ";
		for (int i=0; i<maximum_member; i++)
			fout << set.return_move(i) << " ";
		fout << endl;
		
		fout << "Tempo ";
		for (int i=0; i<maximum_member; i++)
			fout << set.return_tempo(i) << " ";
		
	}
	
	fout << endl << endl << endl;
	for (int i=0; i<set.return_num_of_member(); i++) {
		
		fout << members[i].return_name() <<endl;
		
		for (int j=0; j<maximum_member; j++)
			fout << members[i].return_xpos(j) <<"\t";
		
		fout << endl;
		
		for (int j=0; j<maximum_member; j++)
			fout <<members[i].return_ypos(j) <<"\t";
		
		fout << endl << endl << endl;
		
		
	}
  
  
  for (int i = 0; i < maximum_member; i++) {
    fout << i << "\t";
	fout << set.get_coment(i) << endl;
  }
	
	printf("ほぞんかんりょう\nおつかれさまでした(´･ω･` )");
	
}

void time_move(int d){
	
  /*フィールド　No　Moveを表示*/
	field::drow_grid(set.return_conte_size(),set.return_conte_grid());
	print_No(set.temp_no+1);
	print_Move(set.return_move(set.temp_no+1));
	if (set.temp_no==0 || set.return_tempo(set.temp_no+1)!=set.return_tempo(set.temp_no))
		print_tempo(set.return_tempo(set.temp_no+1));
	
  //コメントの表示
 if (strcmp(set.get_coment(set.return_now()),("non"))) {
    glColor3d(0, 0, 0);
    DrawString(set.get_coment(set.return_now()), 0.7, 0.5);
  }
 	
  //タイトルの表示
  glColor3d(0, 0, 0);
  DrawString(set.return_title(), 0 - strlen(set.return_title())*0.02, 0.9);
  

  
	/*補助線表示*/
	print_net_move(set.temp_no,d);
  
	/*メンバー表示*/
	for (int k=0; k<member::return_count(); k++)
		members[k].put_member(set.temp_no,d);
	
  
  print_warning_net_move(set.temp_no, d);

	glutSwapBuffers();
	
}

void time_move_b(int d){
	
  /*フィールド　No　Moveを表示*/
	field::drow_grid(set.return_conte_size(),set.return_conte_grid());
	print_No(set.temp_no+1);
	print_Move(set.return_move(set.temp_no+1));
	if (set.temp_no==0 || set.return_tempo(set.temp_no+1)!=set.return_tempo(set.temp_no))
		print_tempo(set.return_tempo(set.temp_no+1));
	
  //コメントの表示
 if (strcmp(set.get_coment(set.return_now()),("non"))) {
    glColor3d(0, 0, 0);
    DrawString(set.get_coment(set.return_now()), 0.7, 0.5);
  }
 	
  //タイトルの表示
  glColor3d(0, 0, 0);
  DrawString(set.return_title(), 0 - strlen(set.return_title())*0.02, 0.9);
  

	/*補助線表示*/
	print_net_move(set.temp_no+1,d);
  
	/*メンバー表示*/
	for (int k=0; k<member::return_count(); k++)
		members[k].put_member(set.temp_no+1 ,d);
	
  print_warning_net_move(set.temp_no+1, d);

	glutSwapBuffers();
	
}

void time_no(int no){
  
  if (set.start_stop == 1) {
    return;
  }
  
	set.temp_no=no;
	double card = fabs((double)(24 * set.return_move(no+1) * 60 / set.return_tempo(no+1)) );
	double count_t = 1000.0/Rate;
	
  
	for (int i=0; i<card; i++) {
		glutTimerFunc(count_t * i, time_move, i);
	}
	
	/*移動量計算*/
	for (int i =0; i<set.return_num_of_member(); i++) {
		members[i].change_dx(( members[i].return_xpos(no+1) - members[i].return_xpos(no) )/card);
		members[i].change_dy(( members[i].return_ypos(no+1) - members[i].return_ypos(no) )/card);
		
	}
	
	if(no+1<set.return_max_conte()){
		glutTimerFunc(card*count_t, time_no, no+1);
		
	}else {
		printf("*****End*****\n");
  }
	
}

void time_no_for_test(int n){
  int no = set.temp_no;
	double card = fabs((double)(24 * set.return_move(no+1) * 60 / set.return_tempo(no+1)) );
	double count_t = 1000.0/24;
  
  /*移動量計算 初回のみ*/
  if (n == 0) {
    for (int i =0; i<set.return_num_of_member(); i++) {
      members[i].change_dx(( members[i].return_xpos(no+1) - members[i].return_xpos(no) )/card);
      members[i].change_dy(( members[i].return_ypos(no+1) - members[i].return_ypos(no) )/card);
    }
	}
  
  /*移動を表示*/
  time_move(n);
  
  /*start_stopが0の時再帰呼び出し*/
	if(n<card && set.start_stop == 0) {
    n++;
		glutTimerFunc(count_t, time_no_for_test, n);
	}else {
    set.start_stop = 0;
  }
  
  return;
  
}

void time_no_for_test_b(int n){
  int no = set.temp_no;
	double card = fabs((double)(24 * set.return_move(no+1) * 60 / set.return_tempo(no+1) ));
	double count_t = 1000.0/24;
  
  /*移動量計算 初回のみ*/
  if (n == 0) {
    for (int i =0; i<set.return_num_of_member(); i++) {
      members[i].change_dx(( members[i].return_xpos(no) - members[i].return_xpos(no+1) )/card);
      members[i].change_dy(( members[i].return_ypos(no) - members[i].return_ypos(no+1) )/card);
    }
	}
  
  /*移動を表示*/
  time_move_b(n);
  
  /*start_stopが0の時再帰呼び出し*/
	if(n<card && set.start_stop == 0) {
    n++;
		glutTimerFunc(count_t, time_no_for_test_b, n);
	}else {
    set.start_stop = 0;
  }
  
  return;
  
}


void Display::play2(){
	printf("再生開始\n");
	set.start_stop = 0;
	glutTimerFunc(0, time_no, set.return_now());
	
}

void Display::play_reverse(){
  printf("逆再生(・A・)!!\n");
  set.start_stop = 0;
  if (set.return_now() != 0){
    set.temp_no = set.return_now() - 1;
    time_no_for_test_b(0);
  }
}

void Display::play_test(){
	printf("再生(・∀・)!!\n");
  set.start_stop = 0;
  if (set.return_now() != 0){
	set.temp_no = set.return_now() - 1;
	time_no_for_test(0);
	}
}

