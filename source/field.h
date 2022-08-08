/*
 *  field.h
 *  con+
 *
 *  Created by 林 孝樹 on 12/11/22.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

void field::drow_24_24(){
	glClear(GL_COLOR_BUFFER_BIT);
	double dy = 1.0/14;
	double dx = 1.0/18;
	
	//補助線
	glLineWidth(1);
	if (set.return_conte_grid()) {
		glLineWidth(1);
		glColor3f(0.75, 0.75, 0.75);
		for (int i = -24; i<=24; i++) {
			//縦
			glBegin(GL_LINES);
			glVertex2d(dx*i*0.5,dy*12);
			glVertex2d(dx*i*0.5,-dy*12);
			glEnd();
		}
		for (int i = -24; i<=24; i++) {
			//横
			glBegin(GL_LINES);
			glVertex2d(dx*12,dy*i*0.5);
			glVertex2d(-dx*12,dy*i*0.5);
			glEnd();
		}
	}
	
	//メインの線
	glLineWidth(1);
	glColor3f(0.1, 0.1, 0.1);
	for (int i = -12; i<=12; i++) {
		//縦
		glBegin(GL_LINES);
		glVertex2d(dx*i,dy*12);
		glVertex2d(dx*i,-dy*12);
		glEnd();
	}
	for (int i = -12; i<=12; i++) {
		//横
		glBegin(GL_LINES);
		glVertex2d(dx*12,dy*i);
		glVertex2d(-dx*12,dy*i);
		glEnd();
	}
	
	
	glLineWidth(6);
	glColor3f(0, 0, 0);

	//十字
	glBegin(GL_LINES);
	glVertex2d(-dx, 0);	
	glVertex2d( dx, 0);
	glEnd();
	
	glBegin(GL_LINES);
	glVertex2d( 0,-dy);	
	glVertex2d( 0, dy);
	glEnd();
	
	//L字
	glBegin(GL_LINE_STRIP);
	glVertex2d( dx*3, dy*4);	
	glVertex2d( dx*4, dy*4);	
	glVertex2d( dx*4, dy*3);	
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2d(-dx*3,-dy*4);	
	glVertex2d(-dx*4,-dy*4);	
	glVertex2d(-dx*4,-dy*3);	
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2d( dx*3,-dy*4);	
	glVertex2d( dx*4,-dy*4);	
	glVertex2d( dx*4,-dy*3);	
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2d(-dx*3, dy*4);	
	glVertex2d(-dx*4, dy*4);	
	glVertex2d(-dx*4, dy*3);	
	glEnd();
	
	
	//point
	
	glColor3f(0, 0, 0);
	for (int i = -12; i<=12; i+=4) {
		for (int k = -12; k<=12; k+=4) {
			glPointSize(6);
			glBegin(GL_POINTS);
			glVertex2d(i*dx,k*dy);
			glEnd();	
		}
	}
	
	glLineWidth(2);

	
	return;
	
	
	
}

void field::drow_36_36(){
	glClear(GL_COLOR_BUFFER_BIT);
	double dy = 1.0/18;
	double dx = 1.0/22;
	
	//補助線
	glLineWidth(1);
	if (set.return_conte_grid()) {
		glLineWidth(1);
		glColor3f(0.75, 0.75, 0.75);
		for (int i = -32; i<=32; i++) {
			//縦
			glBegin(GL_LINES);
			glVertex2d(dx*i*0.5,dy*16);
			glVertex2d(dx*i*0.5,-dy*16);
			glEnd();
		}
		for (int i = -32; i<=32; i++) {
			//横
			glBegin(GL_LINES);
			glVertex2d(dx*16,dy*i*0.5);
			glVertex2d(-dx*16,dy*i*0.5);
			glEnd();
		}
	}
	
	//メインの線
	glLineWidth(1);
	glColor3f(0.1, 0.1, 0.1);
	for (int i = -16; i<=16; i++) {
		//縦
		glBegin(GL_LINES);
		glVertex2d(dx*i,dy*16);
		glVertex2d(dx*i,-dy*16);
		glEnd();
	}
	for (int i = -16; i<=16; i++) {
		//横
		glBegin(GL_LINES);
		glVertex2d(dx*16,dy*i);
		glVertex2d(-dx*16,dy*i);
		glEnd();
	}
	
	
	glLineWidth(6);
	glColor3f(0, 0, 0);

	//十字
	glBegin(GL_LINES);
	glVertex2d(-dx, 0);	
	glVertex2d( dx, 0);
	glEnd();
	
	glBegin(GL_LINES);
	glVertex2d( 0,-dy);	
	glVertex2d( 0, dy);
	glEnd();
	
	//L字
	glBegin(GL_LINE_STRIP);
	glVertex2d( dx*3, dy*4);	
	glVertex2d( dx*4, dy*4);	
	glVertex2d( dx*4, dy*3);	
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2d(-dx*3,-dy*4);	
	glVertex2d(-dx*4,-dy*4);	
	glVertex2d(-dx*4,-dy*3);	
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2d( dx*3,-dy*4);	
	glVertex2d( dx*4,-dy*4);	
	glVertex2d( dx*4,-dy*3);	
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2d(-dx*3, dy*4);	
	glVertex2d(-dx*4, dy*4);	
	glVertex2d(-dx*4, dy*3);	
	glEnd();
	
	
	//point
	
	glColor3f(0, 0, 0);
	for (int i = -16; i<=16; i+=4) {
		for (int k = -16; k<=16; k+=4) {
			glPointSize(6);
			glBegin(GL_POINTS);
			glVertex2d(i*dx,k*dy);
			glEnd();	
		}
	}
	
	glLineWidth(2);

	
	return;
	
	
	
}



void field::drow_grid(int con,int op){
	
	if (con == 2) {
		drow_24_24();
		return;
	}
	if (con == 3) {
		drow_36_36();
		return;
	}
	
	glClear(GL_COLOR_BUFFER_BIT);
	/*灰色*/
	
	//縦
	double dx = (double) 1/16;		//=0.0625
	double max_dx = (double) 10/12;
	
	//横
	double dy = (double)1/12;		//=0.08333
	double max_dy = (double)14/16;
	
	
	glLineWidth(1);	
	//夏ドリ補助線描画
	if(op==1){
		glColor3f(0.75, 0.75, 0.75);
		for (int i = -10; i<=9; i++) {
			//縦
			glBegin(GL_LINES);
			glVertex2d(dx*i+0.031,max_dx);
			glVertex2d(dx*i+0.031,-max_dx);
			glEnd();
			//横
			glBegin(GL_LINES);
			glVertex2d(0.625,dy*i+0.0417);
			glVertex2d(-0.625,dy*i+0.0417);
			glEnd();
		}
	}
	
	//春コン用補助線追加
	if(con==1 && op==1){
		glColor3f(0.75, 0.75, 0.75);
		for (int i = 10; i<=13; i++) {
			//縦
			glBegin(GL_LINES);
			glVertex2d(dx*i+0.031,-max_dx);
			glVertex2d(dx*i+0.031,0);
			glEnd();
			glBegin(GL_LINES);
			glVertex2d(-dx*i-0.031,-max_dx);
			glVertex2d(-dx*i-0.031,0);
			glEnd();
		}
		for (int i = 1; i<=10; i++) {
			//横
			glBegin(GL_LINES);
			glVertex2d(max_dy,-dy*i+0.0417);
			glVertex2d(-max_dy,-dy*i+0.0417);
			glEnd();
		}
	}
	glLineWidth(1);
	//夏ドリ用描画
	glColor3f(0.1, 0.1, 0.1);
	for (int i = -10; i<=10; i++) {
		//縦
		glBegin(GL_LINES);
		glVertex2d(dx*i,max_dx);
		glVertex2d(dx*i,-max_dx);
		glEnd();
		//横
		glBegin(GL_LINES);
		glVertex2d(0.625,dy*i);
		glVertex2d(-0.625,dy*i);
		glEnd();
	}
	glLineWidth(1);
	//春コン用追加
	if(con==1){
		glColor3f(0.1, 0.1, 0.1);
		for (int i = 11; i<=14; i++) {
			//縦
			glBegin(GL_LINES);
			glVertex2d(dx*i,-max_dx);
			glVertex2d(dx*i,0);
			glEnd();
			glBegin(GL_LINES);
			glVertex2d(-dx*i,-max_dx);
			glVertex2d(-dx*i,0);
			glEnd();
		}
		for (int i = 0; i<=10; i++) {
			//横
			glBegin(GL_LINES);
			glVertex2d(max_dy,-dy*i);
			glVertex2d(-max_dy,-dy*i);
			glEnd();
		}
	}
	
	
	
	//ポイント
	glColor3f(0, 0, 0);
	for (int i=-2; i<=2; i++) {
		for (int j=-2; j<=2; j++) {
			put_point(i*dx*4, j*dy*4);
		}
	}
	
	//拡大部分のポイント
	if(con==1){
		put_point( 0.625, -4*dy);
		put_point(-0.625, -4*dy);	
		put_point( 0.625, -8*dy);	
		put_point(-0.625, -8*dy);
	}
	
	drow_L_and_X();
}


void field::put_point(double x,double y){
	glPointSize(8);
	glBegin(GL_POINTS);
	glVertex2d(x,y);
	glEnd();	
	return;
}

void field::drow_L_and_X(void){
	double x = (double) 1/16;		//=0.0625 1歩
	double y = (double)1/12;		//=0.08333　1歩
	glLineWidth(8);
	//十字
	glBegin(GL_LINES);
	glVertex2d(-x, 0);	
	glVertex2d( x, 0);
	glEnd();
	
	glBegin(GL_LINES);
	glVertex2d( 0,-y);	
	glVertex2d( 0, y);
	glEnd();
	
	//L字
	glBegin(GL_LINE_STRIP);
	glVertex2d( x*3, y*4);	
	glVertex2d( x*4, y*4);	
	glVertex2d( x*4, y*3);	
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2d(-x*3,-y*4);	
	glVertex2d(-x*4,-y*4);	
	glVertex2d(-x*4,-y*3);	
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2d( x*3,-y*4);	
	glVertex2d( x*4,-y*4);	
	glVertex2d( x*4,-y*3);	
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2d(-x*3, y*4);	
	glVertex2d(-x*4, y*4);	
	glVertex2d(-x*4, y*3);	
	glEnd();
	return;
	
}