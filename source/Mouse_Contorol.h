/*
 *  mouse.h
 *  con+
 *
 *  Created by 林 孝樹 on 12/11/25.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
//void idle(void){
//	glutPostRedisplay();
//}










Mouse_Contorol::Mouse_Contorol(){
  count = 0;
	ButtonStatus=0;
	x1=0;
	x2=0;
	y1=0;
	y2=0;
	mx=0;
	my=0;
	flag=0;
	drow_rect=0;
	
	for (int i = 0; i<maximum_member; i++) {
		marray[i]=NULL;
	}
}

void Mouse_Contorol::crick_motion(int button, int state, int x, int y){
	
	/*座標変換*/
	double xp =2* ((double)x - (set.size_x()/2) )  / set.size_x();
	double yp =2* ((double)-y + (set.size_y()/2) )  / set.size_y();
	
	
	/*左　押す*/
	if (button==GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		left_click_start(xp, yp);
		glutPostRedisplay();
	}
	
	/*左　離す*/
	if(button==GLUT_LEFT_BUTTON && state == GLUT_UP){
		left_click_end(xp, yp);
		glutPostRedisplay();
		
	}
		
}

void Mouse_Contorol::left_click_start(double x,double y){
	//範囲選択済み
	mouse.mx=x;
	mouse.my=y;
  
  
  //CTRLを押しながらの場合は配列に追加
  if (glutGetModifiers() & GLUT_ACTIVE_CTRL  && search_close_distance(x,y)<0.125) {
    mouse.x1=x;
    mouse.y1=y;
    mouse.x2=x;
    mouse.y2=y;
    mouse.marray[mouse.count]= &members[search_close(x, y)];
    mouse.marray[mouse.count]->change_color(1, 0.5, 1);
    mouse.count++;
    return;
  }
	
	if (mouse.flag) {
		//選択範囲内
		if (x <= mouse.x1 && x >= mouse.x2&&
				y <= mouse.y1 && y >= mouse.y2) 
		{
			mouse.mx=x;
			mouse.my=y;
		}
		
		
		//選択範囲外->初期化　to範囲未選択
		else {
			mouse.flag=0;
			for (int i = 0; i<maximum_member; i++) {
				mouse.marray[i]=NULL;
        mouse.count = 0;
			}
		}
		
	}
	//範囲未選択	
	if (!mouse.flag) {

	//距離1.5歩以上
		if(search_close_distance(x,y)>0.125){
			//mouse.flag=1;
			
			mouse.x1=x;
			mouse.y1=y;
			mouse.x2=x;
			mouse.y2=y;
			
			for (int i = 0; i<maximum_member; i++) {
				mouse.marray[i]=NULL;
			}
			
			//色の再設定
			int n = set.return_now();
			for (int i=0; i<set.return_num_of_member(); i++) {
				//位置が同じ
				if(members[i].return_xpos(n-1) == members[i].return_xpos(n) &&
					 members[i].return_ypos(n-1) == members[i].return_ypos(n)){
					members[i].change_color(0.5, 0.5, 1);				
				}
				//位置が異なる
				else{
					members[i].change_color(0.7, 0.7, 1);
				}
			}
		}
		
		
		//1.5歩以内->最も近いものを追加
		else {
			mouse.flag=1;
			mouse.x1=x;
			mouse.y1=y;
			mouse.x2=x;
			mouse.y2=y;
			mouse.marray[0]= &members[search_close(x, y)];
			mouse.marray[0]->change_color(1, 0.5, 1);
		}
		
	}
	
		
	
	
		
	
}

void Mouse_Contorol::left_click_end(double x,double y){
	//変更を反映
	if (mouse.flag) {
		int n = set.return_now();
		double xpos=-1,ypos=-1;
		double tempx=-1,tempy=-1;
		double dx = 1.0/32;
		double dy = 1.0/24;
		
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
	
	
		
			
		for (int i = 0; mouse.marray[i] != NULL; i++) {
			
			xpos=mouse.marray[i]->return_xpos(n)+mouse.marray[i]->return_sx();
			ypos=mouse.marray[i]->return_ypos(n)+mouse.marray[i]->return_sy();
			
			if (set.return_aut()) {
				for (; fabs(tempx-xpos)>dx/2; tempx+=dx);
				for (; fabs(tempy-ypos)>dy/2; tempy+=dy);
				
				xpos=tempx;
				ypos=tempy;
				tempx=-1;
				tempy=-1;
				
			}
			mouse.marray[i]->pos_change(n, xpos, ypos);
			mouse.marray[i]->change_sx(0);	
			mouse.marray[i]->change_sy(0);
			
			mouse.x1=0;
			mouse.x2=0;
			mouse.y1=0;
			mouse.y2=0;
		}
		
    if (glutGetModifiers() & GLUT_ACTIVE_CTRL){
      return;
    }
			
		for (int i=0; i<set.return_num_of_member(); i++) {
			//位置が同じ
			if(members[i].return_xpos(n-1) == members[i].return_xpos(n) &&
				 members[i].return_ypos(n-1) == members[i].return_ypos(n)){
				members[i].change_color(0.5, 0.5, 1);				
			}
			//位置が異なる
			else{
				members[i].change_color(0.7, 0.7, 1);
			}
		}	
		
		
	}else {
		//int count=0;
		double temp;
		mouse.flag=1;
		
					
					
		//正規化
		if (mouse.x1<mouse.x2) {
			temp=mouse.x1;
			mouse.x1=mouse.x2;
			mouse.x2=temp;
		}
		if (mouse.y1<mouse.y2) {
			temp=mouse.y1;
			mouse.y1=mouse.y2;
			mouse.y2=temp;
		}
		
		//範囲内のメンバーを配列に追加
		for (int i=0; i<set.return_num_of_member(); i++) {
			if (members[i].return_xpos(set.return_now()) <= mouse.x1&&
					members[i].return_xpos(set.return_now()) >= mouse.x2&&
					members[i].return_ypos(set.return_now()) <= mouse.y1&&
					members[i].return_ypos(set.return_now()) >= mouse.y2) 
			{
				mouse.marray[mouse.count] = &members[i];
				mouse.count++;
				members[i].change_color(1, 0.5, 1);
			}
		}
			
	}
	
}



void Mouse_Contorol::drug_motion(int x,int y){
	double xp =2* ((double)x - (set.size_x()/2) )  / set.size_x();
	double yp =2* ((double)-y + (set.size_y()/2) )  / set.size_y();
	
	//範囲指定済み
	if (mouse.flag) {
		for (int i = 0; mouse.marray[i]!=NULL; i++) {
			mouse.marray[i]->change_sx(xp-mouse.mx);
			mouse.marray[i]->change_sy(yp-mouse.my);
		}
	}
	
	//範囲未指定->最も近いメンバーを移動
	else {
		//座標を変更
		mouse.x2=xp;
		mouse.y2=yp;
		mouse.drow_rect=1;
	}
	
	glutPostRedisplay();
	
	
}

