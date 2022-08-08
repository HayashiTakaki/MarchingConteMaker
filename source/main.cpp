#define Rate 24


enum{
  Trombone,Sousaphone,Color_Guard,Battery,Flute,Other_instrument
};

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/stat.h>
#include <time.h>
//#include <unistd.h>
//#include <GLUT/glut.h>
//#include <OpenGL/gl.h>
//win
#include <GL/glut.h>

#include "head.h"
#include "bmp.h"
#include "member.h"
#include "setting.h"
#include "field.h"
#include "display.h"
#include "Key.h"
#include "Mouse_Contorol.h"
#include "drow.h"







int main (int argc, char** argv) {
   	
	print_how_to_use();

  
//  //backupフォルダが存在しなければ作成
//	if (access("back up", 0)) {
//    mkdir("back up", 0777);
//  }
//  
//  chdir("back up");
//
//  //chdir("../");

	if(set.return_num_of_member()==0){
		cout << set.return_title() << "<<<<<<<\n";
		set.read_file(set.return_title());
		member::set_max_member(set.return_num_of_member());
		member::count_set(set.return_num_of_member());
		
}

	
	
	
	
	
	/*初期設定*/
	glutInit(&argc,argv);
	/*ディスプレイの設定*/
	glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);
	/*表示場所の指定*/
	glutInitWindowPosition(0, 0);
	/*ウィンドサイズの指定*/
	glutInitWindowSize(800, 600);
	glutCreateWindow("Continuity v2.3 for Windows");

	/*再描画*/
	glutDisplayFunc(Display::display);
	glutReshapeFunc(resize);
	glutMouseFunc(Mouse_Contorol::crick_motion); //マウスのクリック
	glutMotionFunc(Mouse_Contorol::drug_motion); //ドラッグ処理
	glutKeyboardFunc(Key::keyboard);//キーボード処理
	glutSpecialFunc(Key::exkeyboard);
	GLUT_SET_MENU();
	
	/*ウィンドウを塗りつぶす際の色を指定0~1*/
	glClearColor(1, 1, 1,1);//赤，緑，青，透明度
	
	
	/*処理開始*/
	glutMainLoop();
	
	
    return 0;
}
