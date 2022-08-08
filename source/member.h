#include <iostream>
#include <fstream>

int member::count = 0;
int member::max_member = 0;

member::member(){
	
	if(return_count()!=return_max_member()){
		/*初期位置*/
    
		xpos[0]=1.0/9 * (count%10 - 5) + 1.0/36*2;
		ypos[0]=1.0/7 * (count/(-10) +1);
		
		/*初期化*/
		for (int i=1; i<maximum_member; i++) {
			xpos[i]=0;
			ypos[i]=0;
		}
		dx=0;
		dy=0;
		sx=0;
		sy=0;
		red=0.5;
		green=0.5;
		blue=1;
		
		/*名前入力*/
		
		char c[10];
		for (int i=0; i<10; i++) {
			c[i]=32;
		}
		
		printf("メンバー%dの名前を入力>>",count+1);
		while (c[0]>'z' || c[0]<'!' ) 
			std::cin >> c;
		
		clear_name();
		set_name(c);
    set_shape_type();
		count_up();
	}
}


member::member(int n){
}

void member::put_member(int n,int t=0){
		glColor3f(red, green, blue);

		if(return_shape_type() != Battery)
	{
	
    /*表示形の変更*/
		if (set.return_shape() == 0) {
      switch (return_shape_type()) {
        case Trombone:
          drow_tb(xpos[n]+sx+dx*t,ypos[n]+sy+dy*t);
          break;
        case Color_Guard:
          drow_cg(xpos[n]+sx+dx*t,ypos[n]+sy+dy*t);
          break;
        case Flute:
          drow_fl(xpos[n]+sx+dx*t,ypos[n]+sy+dy*t);
          break;
        case Sousaphone:
          drow_so(xpos[n]+sx+dx*t,ypos[n]+sy+dy*t);
          break;
        case Other_instrument:
          drow_circle(xpos[n]+sx+dx*t,ypos[n]+sy+dy*t);
          break;

        default:
          break;
      }
      }else{
        drow_circle(xpos[n]+sx+dx*t,ypos[n]+sy+dy*t);
      }
      
    //黒文字
		glColor3f(0, 0, 0);
		
    //名前を表示
    glRasterPos2d(xpos[n]+sx+dx*t-0.011*strlen(name)*800/set.size_x(), ypos[n]+sy+dy*t-0.018*600/set.size_y());
		for (int i=0; i<4; i++) {
      glutBitmapCharacter(GLUT_BITMAP_9_BY_15,name[i]);
		}
	}
  
  
	else {
		
		
    if (set.return_shape() == 0) {
      drow_ba(xpos[n]+sx+dx*t,ypos[n]+sy+dy*t);
    }else{
      drow_circle(xpos[n]+sx+dx*t,ypos[n]+sy+dy*t);
    }
		
		glColor3f(0, 0, 0);
    glRasterPos2d(xpos[n]+sx+dx*t-0.011*strlen(name)*800/set.size_x(), ypos[n]+sy+dy*t-0.018*600/set.size_y());
		for (int i=1; i<5; i++) {
				glutBitmapCharacter(GLUT_BITMAP_9_BY_15,name[i]);
		}
	}
	
	
	//glFlush();
	
	/*使用可能フォント一覧
	 GLUT_BITMAP_8_BY_13、GLUT_BITMAP_9_BY_15、
	 GLUT_BITMAP_TIMES_ROMAN_10、GLUT_BITMAP_TIMES_ROMAN_24
	 GLUT_BITMAP_HELVETICA_10、GLUT_BITMAP_HELVETICA_12、
	 GLUT_BITMAP_HELVETICA_18*/
	
}
void member::put_member_for_printout(int n){
	if(name[0]!='*')
	{
		glColor3f(0.7,0.7,0.7);
		
		drow_circle(xpos[n],ypos[n]);
		
		glColor3f(0, 0, 0);
		
		//名前を表示
    glRasterPos2d(xpos[n]-0.011*strlen(name)*800/set.size_x(), ypos[n]-0.018*600/set.size_y());
		for (int i=0; i<4; i++) {
      glutBitmapCharacter(GLUT_BITMAP_9_BY_15,name[i]);
		}

	}
	else {
		glColor3f(0.7,0.7,0.7);
		
		drow_circle(xpos[n],ypos[n]);
		glColor3f(0, 0, 0);
		
		//名前を表示
    glRasterPos2d(xpos[n]-0.011*strlen(name)*800/set.size_x(), ypos[n]-0.018*600/set.size_y());
		for (int i=1; i<5; i++) {
      glutBitmapCharacter(GLUT_BITMAP_9_BY_15,name[i]);
		}

	}
	
	
}


double member::return_xpos(int i){if(i<=0)i=0;return xpos[i];}
double member::return_ypos(int i){if(i<=0)i=0;return ypos[i];}
double member::return_sx(){return sx;}
double member::return_sy(){return sy;}
double member::return_dx(){return dx;}
double member::return_dy(){return dy;}
char * member::return_name(){return name;}


void member::set_name(char *c){
	strcpy(name,c);
	
}
void member::clear_name(){
	for (int i=0; i<10; i++) 
		name[i]=0;
	
}

void member::print_member(int i){}

void member::pos_change(int i,double x,double y){
	xpos[i]=x;
	ypos[i]=y;
}
void member::change_color(double r,double g,double b){
	red=r;
	green=g;
	blue=b;
	return;
}

void member::count_set(int i){count=i;}
void member::count_down(){count--;}
void member::count_up(){count++;}
int member::return_count(){return count;}

void member::put_name(){
}

double member::distance(double x,double y,int i){
	return sqrt(pow(xpos[i]-x,2)+pow(ypos[i]-y, 2));
}

int member::return_max_member(){return max_member;}
void member::set_max_member(int i){max_member=i;}
void member::print_positions(int i){printf("%f,%f\n",xpos[i],ypos[i]);}

void member::drow_goust(int now){
	if (now!=0) {
		if ((xpos[now]+sx)!=xpos[now-1] || (ypos[now]+sy)!=ypos[now-1]) {
			/*半透明の円を表示*/
			drow_goust_circle(xpos[now-1], ypos[now-1]);
			
			/*線を表示*/
			drow_goust_Line(xpos[now]+sx, ypos[now]+sy,xpos[now-1], ypos[now-1]);
			
		}
	}
}


void member::drow_line(int now){
	if (now!=0) {
    glLineWidth(1);
    glColor3f(0.7,0.7,0.7);
				/*線を表示*/
    glBegin(GL_LINE_STRIP);
    glVertex2d(xpos[now]+sx, ypos[now]+sy);
    glVertex2d(xpos[now-1], ypos[now-1]);
    glEnd();
		
  }
}

void member::next_move(int i){
	if (xpos[i]==0.0 && ypos[i]==0.0) {
		xpos[i]=xpos[i-1];
		ypos[i]=ypos[i-1];
	}
}

void member::pos_reset(int i){
	if(i!=0){
		xpos[i]=xpos[i-1];
		ypos[i]=ypos[i-1];
	}
}

void member::set_shape_type(){
  
  //Trombone
    if(strncmp(name, "TB", 2)==0 || strncmp(name, "Tb", 2)==0 || strncmp(name, "tb",2) == 0 )
      shape_type = Trombone;
  //Souza
    else if(strncmp(name, "SO", 2) == 0 || strncmp(name, "So", 2) == 0 || strncmp(name, "so", 2) == 0 )
      shape_type = Sousaphone;
  //CG
    else if(strncmp(name, "CG", 2) == 0 || strncmp(name, "C.", 2) == 0 || strncmp(name, "cg", 2) == 0)
      shape_type = Color_Guard;
  //Battery
    else if(name[0] == '*')
      shape_type = Battery;
  //Flute
    else if(strncmp(name, "Fl", 2)==0 ||strncmp(name, "fl", 2)==0 ||strncmp(name, "FL", 2)==0)
      shape_type = Flute;
  //oher
    else
      shape_type = Other_instrument;
  }

void member::change_xpos(int i,double x){xpos[i]=x;}
void member::change_ypos(int i,double y){ypos[i]=y;}
void member::change_dx(double x){dx=x;}
void member::change_dy(double y){dy=y;}
void member::change_sx(double x){sx=x;}
void member::change_sy(double y){sy=y;}
int  member::return_shape_type(){return shape_type;}

void member::add_d(){sx+=dx;sy+=sy;}


