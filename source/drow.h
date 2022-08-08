/*
 *  drow.h
 *  con+
 *
 *  Created by 林 孝樹 on 12/11/25.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *  OpenGLの描画についてのファイル
 */


/*円の描写*/
void drow_circle(double x,double y){
	/*差分ーー正12角形*/
	double ds = 2 * 3.14 / 12; 
	
	
	/*描写*/
	if (set.return_conte_size()==0||set.return_conte_size()==1) {
		glBegin(GL_POLYGON);
		for (double angle=0; angle<2*3.14; angle+=ds) 
			glVertex2f(x + 1.0/32*cos(angle), y + 1.0/24*sin(angle));
		glEnd();
	}else if (set.return_conte_size()==2) {
		glBegin(GL_POLYGON);
		for (double angle=0; angle<2*3.14; angle+=ds) 
			glVertex2f(x + 1.0/36*cos(angle), y + 1.0/28*sin(angle));
		glEnd();
	}else {
		glBegin(GL_POLYGON);
		for (double angle=0; angle<2*3.14; angle+=ds) 
			glVertex2f(x + 1.0/44*cos(angle), y + 1.0/36*sin(angle));
		glEnd();
	}

	
	
}
/*円の描写*/
void drow_circle(double x,double y,double r,double g,double b){
	/*差分ーー正12角形*/
	double ds = 2 * 3.14 / 12; 
	
	/*青*/
	//glColor3f(r,g,b );
	
	
	/*描写*/
	if (set.return_conte_size()==0||set.return_conte_size()==1) {
		glBegin(GL_POLYGON);
		for (double angle=0; angle<2*3.14; angle+=ds) 
			glVertex2f(x + 1.0/32*cos(angle), y + 1.0/24*sin(angle));
		glEnd();
	}else if (set.return_conte_size()==2) {
		glBegin(GL_POLYGON);
		for (double angle=0; angle<2*3.14; angle+=ds) 
			glVertex2f(x + 1.0/36*cos(angle), y + 1.0/28*sin(angle));
		glEnd();
	}else {
		glBegin(GL_POLYGON);
		for (double angle=0; angle<2*3.14; angle+=ds) 
			glVertex2f(x + 1.0/44*cos(angle), y + 1.0/36*sin(angle));
		glEnd();
	}
	
	
}

/*tb*/
void drow_tb(double x,double y){
	double ds = 2 * 3.14 / 24; 
	
	/*青*/
	//glColor3f(0.5, 0.5, 1);
	
	if (set.return_conte_size()==0||set.return_conte_size()==1) {
		glBegin(GL_POLYGON);
		for (double angle =0 ; angle<2*3.14; angle+=ds) {
			if(angle<=3.14)
				glVertex2f(x + 1.0/32*cos(angle), y + 1.0/24*sin(angle));
			else
				glVertex2f(x + 1.0/32*cos(angle), y + 3.0/24*sin(angle));
		}
		glEnd();
	}else if (set.return_conte_size()==3) {
		glBegin(GL_POLYGON);
		for (double angle =0 ; angle<2*3.14; angle+=ds) {
			if(angle<=3.14)
				glVertex2f(x + 1.0/44*cos(angle), y + 1.0/36*sin(angle));
			else
				glVertex2f(x + 1.0/44*cos(angle), y + 3.0/36*sin(angle));
		}
		glEnd();
	}
	else {
		glBegin(GL_POLYGON);
		for (double angle =0 ; angle<2*3.14; angle+=ds) {
			if(angle<=3.14)
				glVertex2f(x + 1.0/36*cos(angle), y + 1.0/28*sin(angle));
			else
				glVertex2f(x + 1.0/36*cos(angle), y + 3.0/28*sin(angle));
		}
		glEnd();
		
		}

		
	
}


/*fl*/
void drow_fl(double x,double y){
	double ds = 2 * 3.14 / 24;
	
		
	if (set.return_conte_size()==0||set.return_conte_size()==1) {
		glBegin(GL_POLYGON);
		for (double angle =0 ; angle<2*3.14; angle+=ds) {
			if(angle<=3.14/2 || 3.14*3/2<=angle)
				glVertex2f(x + 1.0/32*cos(angle), y + 1.0/24*sin(angle));
			else
				glVertex2f(x + 3.0/32*cos(angle), y + 1.0/24*sin(angle));
		}
		glEnd();
	}else if (set.return_conte_size()==3) {
		glBegin(GL_POLYGON);
		for (double angle =0 ; angle<2*3.14; angle+=ds) {
			if(angle<=3.14/2 || 3.14*3/2<=angle)
				glVertex2f(x + 1.0/44*cos(angle), y + 1.0/36*sin(angle));
			else
				glVertex2f(x + 3.0/44*cos(angle), y + 1.0/36*sin(angle));
		}
		glEnd();
	}
	else {
		glBegin(GL_POLYGON);
		for (double angle =0 ; angle<2*3.14; angle+=ds) {
			if (angle<=3.14/2 || 3.14*3/2<=angle)
				glVertex2f(x + 1.0/36*cos(angle), y + 1.0/28*sin(angle));
			else
				glVertex2f(x + 3.0/36*cos(angle), y + 1.0/28*sin(angle));
		}
		glEnd();
		
  }
  
  
	
}


/*C.G.*/
void drow_cg(double x,double y){
	//glColor3f(0.5, 0.5, 1);

	if (set.return_conte_size()==0||set.return_conte_size()==1) {
		glBegin(GL_POLYGON);
		glVertex2f(x+1.5/16, y);
		glVertex2f(x, y+1.5/12);
		glVertex2f(x-1.5/16, y);
		glVertex2f(x, y-1.5/12);
		glEnd();
	}else if(set.return_conte_size()==2){
		glBegin(GL_POLYGON);
		glVertex2f(x+1.5/18, y);
		glVertex2f(x, y+1.5/14);
		glVertex2f(x-1.5/18, y);
		glVertex2f(x, y-1.5/14);
		glEnd();
		
	}else{
		glBegin(GL_POLYGON);
		glVertex2f(x+1.5/22, y);
		glVertex2f(x, y+1.5/18);
		glVertex2f(x-1.5/22, y);
		glVertex2f(x, y-1.5/18);
		glEnd();
	}

	
}

/*Battery*/
void drow_ba(double x,double y){
	/*差分ーー正6角形*/
	double ds = 2 * 3.14 / 6; 
	
	/*青*/
	//glColor3f(0.5, 0.5, 1);
	
	/*描写*/
	if (set.return_conte_size()==0||set.return_conte_size()==1) {
		glBegin(GL_POLYGON);
		for (double angle=0; angle<2*3.14; angle+=ds) 
			glVertex2f(x + 2.0/32*cos(angle), y + 2.0/24*sin(angle));
		glEnd();
	}else if(set.return_conte_size()==2) {
		glBegin(GL_POLYGON);
		for (double angle=0; angle<2*3.14; angle+=ds) 
			glVertex2f(x + 2.0/36*cos(angle), y + 2.0/28*sin(angle));
		glEnd();
	}else {
		glBegin(GL_POLYGON);
		for (double angle=0; angle<2*3.14; angle+=ds) 
			glVertex2f(x + 2.0/44*cos(angle), y + 2.0/36*sin(angle));
		glEnd();
	}
	
	return;
}

/*sou*/
void drow_so(double x,double y){
	/*差分ーー正12角形*/
	double ds = 2 * 3.14 / 12; 
	
	/*青*/
	//glColor3f(0.5, 0.5, 1);
	
	/*描写*/
	if (set.return_conte_size()==0||set.return_conte_size()==1) {
		glBegin(GL_POLYGON);
		for (double angle=0; angle<2*3.14; angle+=ds) 
			glVertex2f(x + 2.0/32*cos(angle), y + 2.0/24*sin(angle));
		glEnd();
	}else if(set.return_conte_size()==2) {
		glBegin(GL_POLYGON);
		for (double angle=0; angle<2*3.14; angle+=ds) 
			glVertex2f(x + 2.0/36*cos(angle), y + 2.0/28*sin(angle));
		glEnd();
	}else {
		glBegin(GL_POLYGON);
		for (double angle=0; angle<2*3.14; angle+=ds) 
			glVertex2f(x + 2.0/44*cos(angle), y + 2.0/36*sin(angle));
		glEnd();
	}
	
}


/*半透明の円の描写*/
void drow_goust_circle(double x,double y){
	/*差分ーー正八角形*/
	double ds = 2 * 3.14 / 12; 
	
	/*青*/
	glColor3f(0.85, 0.85, 1);
	
	/*描写*/
	if (set.return_conte_size()==0||set.return_conte_size()==0) {
		glBegin(GL_POLYGON);
		for (double angle=0; angle<2*3.14; angle+=ds) 
			glVertex2f(x + 1.0/32*cos(angle), y + 1.0/24*sin(angle));
		glEnd();
	}else if(set.return_conte_size()==2) {
		glBegin(GL_POLYGON);
		for (double angle=0; angle<2*3.14; angle+=ds) 
			glVertex2f(x + 1.0/36*cos(angle), y + 1.0/28*sin(angle));
		glEnd();
	}else {
		glBegin(GL_POLYGON);
		for (double angle=0; angle<2*3.14; angle+=ds) 
			glVertex2f(x + 1.0/44*cos(angle), y + 1.0/36*sin(angle));
		glEnd();
	}
	
}


/*2点間の直線*/
void drow_goust_Line(double x1,double y1,double x2,double y2){
	glLineWidth(1);

	//通常
	if (set.return_conte_size()==0||set.return_conte_size()==0) {
		if(sqrt(pow((x1-x2)*16, 2)+pow((y1-y2)*12, 2))>set.return_move(set.return_now()))
			glColor3f(1, 0.85, 0);
		else glColor3f(0.85,0.85 , 1); //←要変更
	}else if(set.return_conte_size()==2) {
		if(sqrt(pow((x1-x2)*18, 2)+pow((y1-y2)*14, 2))>set.return_move(set.return_now()))
			glColor3f(1, 0.85, 0);
		else glColor3f(0.85,0.85 , 1); //←要変更
	}else{
		if(sqrt(pow((x1-x2)*22, 2)+pow((y1-y2)*18, 2))>set.return_move(set.return_now()))
			glColor3f(1, 0.85, 0);
		else glColor3f(0.85,0.85 , 1); //←要変更
	}

	
	glBegin(GL_LINE_STRIP);
	glVertex2d(x1, y1);
	glVertex2d(x2, y2);
	glEnd();
	
	
}

void out_put_jpeg(){
  int width = set.size_x();
  int height = set.size_y();
  string temp;
  int No = 0;
  
  //ファイル名調整
  char print[30];
  memset(print, 0, sizeof(print));
  int seak=0;
  strcpy(print, set.return_title());
  seak = strlen(print);
  
  print[seak]='-';
  print[seak+3]='.';
  print[seak+4]='b';
  print[seak+5]='m';
  print[seak+6]='p';
  
  
  int n;
  for (int nz = 0; nz<set.return_max_conte()+1; nz++) {
    if (nz%2 == 0) {
      n = nz + 1;
    }else {
      n = nz - 1;
    }
    
    //フィールド表示
    field::drow_grid(set.return_conte_size(),set.return_conte_grid());
    
    //No表示
    print_No(n);
    if(n!=0)
      print_Move(set.return_move(n));
    if(n==0||set.return_tempo(n)!=set.return_tempo(n-1))
      print_tempo(set.return_tempo(n));
    
    //コメントの表示
  if (strcmp(set.get_coment(set.return_now()),("non"))) {
      glColor3d(0, 0, 0);
      DrawString(set.get_coment(set.return_now()), 0.7, 0.5);
    }
    
    //タイトルの表示
    glColor3d(0, 0, 0);
    DrawString(set.return_title(), 0 - strlen(set.return_title())*0.02, 0.9);
    
    
    /*メンバー表示*/
    for (int i=0; i<member::return_count(); i++) {
      members[i].drow_line(n);
    }
    
    for (int i=0; i<member::return_count(); i++) {
      members[i].put_member_for_printout(n);
    }
    glFlush();
    
    //通し番号を入力
    
    print[seak+1]='0'+No/10;
    print[seak+2]='0'+No%10;
    
    if (n%2 == 1) {
      
      
      WriteBitmap(print,width,height);
    }else {
      add_WriteBitmap(print, width, height);
      No++;
    }
  }
  
  //空白を出力
  if (set.return_max_conte()%2 == 1) {
   	glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
    add_WriteBitmap(print, width, height);
  }
  
  printf("出力完了(,,・ω・,,)！！\n");
  return;

}


/*No move数等の出力*/
void print_No(int now){
	glColor3f(0,0,0);
	
  char a,b;
	
	a=now/10+'0';
	b=now%10+'0';

  
	glRasterPos2d(0.7, 0.8);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'N');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'o');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'.');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,a);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,b);
	
}

void print_Move(int i){
	
	char a,b;
	if(i>0){
		a=i/10+'0';
		b=i%10+'0';
	}else {
		a=-i/10+'0';
		b=-i%10+'0';
	}
	
	
	if(i>=0){
		
		glRasterPos2d(0.7, 0.7);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'M');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'o');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'v');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'e');
		if(a=='0'){
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,b);
			
		}else {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,a);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,b);
		}
		
		
	}else {
		glRasterPos2d(0.7, 0.7);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'H');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'a');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'l');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'t');
		if(a=='0'){
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,b);
			
		}else {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,a);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,b);
		}
		
		
	}
	
	
	
}

void print_tempo(int t){
	char a,b,c;
	a=t/100+'0';
	b=t%100 /10+'0';
	c=t%10+'0';
	glRasterPos2d(0.7, 0.6);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'T');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'e');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'m');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'p');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'o');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'=');
	
	if (a=='0') {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,b);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,c);
		
	}else {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,a);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,b);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,c);
		
	}
	
	
	
	
}

void print_how_to_use(){
	
	std::cout <<"\n\n＊＊＊主な操作方法＊＊＊"<<std::endl;
	
	std::cout <<"n:次のコンテ"<<std::endl;
	std::cout <<"b:前のコンテ"<<std::endl;
	std::cout <<"o:最初のコンテ"<<std::endl;
	std::cout <<"l:最後のコンテ"<<std::endl;
	std::cout <<"m:Move数の変更"<<std::endl;
	std::cout <<"t:Tempoの変更"<<std::endl;
	std::cout <<"スペース:位置補正"<<std::endl;
	std::cout <<"a:自動補正切り替え"<<std::endl;	
	std::cout <<"p:再生"<<std::endl;
	std::cout <<"s:保存"<<std::endl;
	std::cout <<"q:終了"<<std::endl;
	std::cout <<"方向キー:微調整(0.5歩補正)"<<std::endl;
	
}


void main_menu(int x)
{
	key.keyboard(x,0,0);
	glutPostRedisplay();

}

void move_menu(int x){
	set.change_move(x);
	glutPostRedisplay();
}

void tempo_menu(int x){
	set.change_tempo(x);
	glutPostRedisplay();
	
}

void other_menu(int x)
{
	key.keyboard(x,0,0);
	glutPostRedisplay();
}

void edit(int x){
  switch (x) {
    case 0:
      delete_all_conte();
      break;
      
    case 1:
      delete_this_conte();
      break;
      
    case 2:
      add_conte();
      break;
      
    default:
      break;
  }
}



void sizemenu(int n){
  int old = set.return_conte_size();
  int now = set.return_now();
  
  //座標調整
  if (old == 2 && old != n) {
    for (int i = 0; i < set.return_num_of_member(); i++) {
      members[i].change_xpos(now, members[i].return_xpos(now)*0.625/0.555556);
      members[i].change_ypos(now, members[i].return_ypos(now)*0.833333/0.714286);
    }
  }else if (old != 2 && 2 == n){
    for (int i = 0; i < set.return_num_of_member(); i++) {
      members[i].change_xpos(now, members[i].return_xpos(now)*0.555556/0.625);
      members[i].change_ypos(now, members[i].return_ypos(now)*0.714286/0.833333);
    }
  }
  
	set.change_conte_size(n);
	glutPostRedisplay();

}


void GLUT_SET_MENU()
{
	int MENU_ID[5];
	
	/*MOVE*/
	MENU_ID[0] = glutCreateMenu(move_menu);
	glutAddMenuEntry("Move2", 2);
	glutAddMenuEntry("Move4", 4);
	glutAddMenuEntry("Move6", 6);
	glutAddMenuEntry("Move8", 8);
	glutAddMenuEntry("Move10", 10);
	glutAddMenuEntry("Move12", 12);
	glutAddMenuEntry("Move16", 16);
	glutAddMenuEntry("Halt2", -2);
	glutAddMenuEntry("Halt4", -4);
	glutAddMenuEntry("Halt6", -6);
	glutAddMenuEntry("Halt8", -8);
	glutAddMenuEntry("Halt10", -10);
	glutAddMenuEntry("Halt12", -12);
	glutAddMenuEntry("Halt16", -16);
	glutAddMenuEntry("Halt32", -32);
	
	
	
	/*TEMPO*/
	MENU_ID[1] = glutCreateMenu(tempo_menu);
	glutAddMenuEntry("60", 60);
	glutAddMenuEntry("72", 72);
	glutAddMenuEntry("80", 80);
	glutAddMenuEntry("92", 92);
	glutAddMenuEntry("100", 100);
	glutAddMenuEntry("104", 104);
	glutAddMenuEntry("108", 108);
	glutAddMenuEntry("112",112);
	glutAddMenuEntry("116", 116);
	glutAddMenuEntry("120", 120);
	glutAddMenuEntry("126", 126);
	glutAddMenuEntry("132", 132);
	glutAddMenuEntry("138", 138);
	glutAddMenuEntry("144", 144);
	
	MENU_ID[2] = glutCreateMenu(other_menu);
	glutAddMenuEntry("自動位置補正切替(a)", 'a');
	glutAddMenuEntry("名前の変更(*)", '*');
	glutAddMenuEntry("補助線切替(-)", '-');
  glutAddMenuEntry("フルスクリーン(v)", 'v');
  glutAddMenuEntry("楽器の形状変更(f)", 'f');
  glutAddMenuEntry("最初のコンテ(O)", 'o');
	glutAddMenuEntry("最後のコンテ(L)", 'l');



  
	
	MENU_ID[3] = glutCreateMenu(sizemenu);
	glutAddMenuEntry("夏ドリ", 0);
	glutAddMenuEntry("春コン", 1);
	glutAddMenuEntry("SAYAKA", 2);
	glutAddMenuEntry("メモコン", 3);
  
  MENU_ID[4] = glutCreateMenu(edit);
	glutAddMenuEntry("このコンテより後を全て削除", 0);
	glutAddMenuEntry("このコンテのみ削除", 1);
	glutAddMenuEntry("このコンテの後ろに1枚追加", 2);
	
	
	
	glutCreateMenu(main_menu);
	glutAddMenuEntry("次のコンテ(N)", 'n');
	glutAddMenuEntry("前のコンテ(B)", 'b');
  glutAddMenuEntry("初期位置に戻す(r)", 'r');
	glutAddMenuEntry("1枚再生(p)", 'p');
	glutAddMenuEntry("1枚逆再生(@)", '@');
	glutAddMenuEntry("全再生(P)", 'P');
  glutAddMenuEntry("コメント入力(c)", 'c');
  glutAddSubMenu("Move数(M)", MENU_ID[0]);
	glutAddSubMenu("テンポ(T)", MENU_ID[1]);
	glutAddSubMenu("その他設定", MENU_ID[2]);
	glutAddSubMenu("コンテサイズ切替", MENU_ID[3]);
  glutAddSubMenu("編集", MENU_ID[4]);
	glutAddMenuEntry("保存(S)", 's');
	glutAddMenuEntry("出力(K)", 'K');
	glutAddMenuEntry("終了(Q)", 'q');
  
	
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}


void resize(int w, int h){
	/* ウィンドウ全体をビューポートにする */
	set.set_display_size(w, h);
	glViewport(0, 0, w, h);
	
	/* 変換行列の初期化 */
	glLoadIdentity();
	
}

void revise(){
	int no = set.return_now();
	double dx = 1.0/32;
	double dy = 1.0/24;
	double x=-1;
	double y=-1;
	
	//SAYAKAvar.
	if (set.return_conte_size()==2) {
		dx = 1.0/36;
		dy = 1.0/28;
	}
	//memocon??
	if (set.return_conte_size()==3) {
		dx = 1.0/44;
		dy = 1.0/36;
	}
	
	
	for (int i = 0; mouse.marray[i]!=NULL; i++) {
	
	
	for (; fabs(members[i].return_xpos(no)-x)>dx/2; x+=dx);
	for (; fabs(members[i].return_ypos(no)-y)>dy/2; y+=dy);
	
	members[i].pos_change(no, x, y);
	}
	glutPostRedisplay();
	
	
}

void change_name(){
  
  //範囲選択済み
  if (mouse.marray[0] != NULL) {
    for (int i = 0; mouse.marray[i]!=NULL; i++) {
      printf("名前の変更:%s->",mouse.marray[i]->return_name());
      char buff[6];
      std::cin>>buff;
      mouse.marray[i]->set_name(buff);
      mouse.marray[i]->set_shape_type();
    }
  
  }
	
}

void delete_all_conte(){
  int No = set.return_now();
  
  
  for (int n = No+1 ; n <= set.return_max_conte(); n++) {
    for (int i = 0; i < set.return_num_of_member(); i++) {
      members[i].change_xpos(n, 0);
      members[i].change_ypos(n, 0);
    }
    std::cout << "delete" << n << "\n";
  }
  
  set.change_no_and_maxconte(No, No);
  glutPostRedisplay();

}

void delete_this_conte(){
  int No = set.return_now();
  for (int n = No; n < set.return_max_conte(); n++) {
    for (int i = 0; i < set.return_num_of_member(); i++) {
      members[i].change_xpos(n, members[i].return_xpos(n+1));
      members[i].change_ypos(n, members[i].return_ypos(n+1));
    }

  }
  set.change_no_and_maxconte(No-1, set.return_max_conte()-1);
	glutPostRedisplay();

}


void add_conte(){
  int No = set.return_now();
  for (int n = set.return_max_conte(); n >= No; n--) {
    for (int i = 0; i < set.return_num_of_member(); i++) {
      members[i].change_xpos(n+1, members[i].return_xpos(n));
      members[i].change_ypos(n+1, members[i].return_ypos(n));
    }
  }
  set.change_no_and_maxconte(No+1, set.return_max_conte()+1);
  glutPostRedisplay();

}


void DrawString(std::string str,double x, double y)
{
   // 画面上にテキスト描画
  glRasterPos2f(x, y);
  int size = (int)str.size();
  for(int i = 0; i < size; ++i){
    char c = str[i];
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
  }
//  GLUT_BITMAP_9_BY_15
  
}

