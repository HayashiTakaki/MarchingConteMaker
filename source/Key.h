/*
 *  Key.h
 *  con+
 *
 *  Created by 林 孝樹 on 12/11/28.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */


static class Key{
private:
	int state;
	
public:
	Key();
	static void keyboard(unsigned char key,int x,int y);
	static void exkeyboard(int key, int x, int y);
}key;

Key::Key(){
	state=0;
	
}
void Key::exkeyboard(int key, int x, int y){
	double dx = 1.0/32;
	double dy = 1.0/24;
	double start = -1.0;
	
	if (set.return_conte_size()==2) {
		dx = 1.0/36;
		dy = 1.0/28;
	}
	
	
	switch(key){
		case GLUT_KEY_LEFT:		//左
			for (; start<members[set.return_point()].return_xpos(set.return_now()); start+=dx);
			members[set.return_point()].change_xpos(set.return_now(), start-dx);
			glutPostRedisplay();
			
			break;
			
		case GLUT_KEY_RIGHT:	//右
			for (; start<=members[set.return_point()].return_xpos(set.return_now()); start+=dx);
			members[set.return_point()].change_xpos(set.return_now(), start);
			glutPostRedisplay();
			break;
			
		case GLUT_KEY_UP:		//上
			for (; start<=members[set.return_point()].return_ypos(set.return_now()); start+=dy);
			members[set.return_point()].change_ypos(set.return_now(), start);
			glutPostRedisplay();
			break;
			
		case GLUT_KEY_DOWN:		//下
			for (; start<members[set.return_point()].return_ypos(set.return_now()); start+=dy);
			members[set.return_point()].change_ypos(set.return_now(), start-dy);
			glutPostRedisplay();
			break;
			
	}
}

void Key::keyboard(unsigned char key,int x,int y){
  char buff[100];
  memset(buff, 0, sizeof(buff));
  
	switch (key) {
			/*終了*/
		case 'q':
		case 'Q':
		case '\033':  /* '\033' は ESC の ASCII コード */
			exit(0);
			
			
			/*Next move*/
		case 'n':
		case 'N':
			set.next();
			glutPostRedisplay();
			
			printf("%d:Next Move( `･ω･)\n",set.return_now());
			for (int i=0; i<set.return_num_of_member(); i++) {
				members[i].next_move(set.return_now());
				members[i].change_color(0.5, 0.5, 1);			
			}
			break;
			
			
			/*privious move*/
		case 'b':
		case 'B':
			set.back();
			glutPostRedisplay();
			printf("%d:Previous Move(･ω･` )\n",set.return_now());
			break;
      
    case 'c':
		case 'C':
			cout << "コメントを入力\n>";
			
      std::cin >> buff;
      set.set_coment(buff);
      glutPostRedisplay();
			break;
		
			/*reset position*/
		case 'r':
			set.reset_position();
			glutPostRedisplay();
			break;
			
		/*start playing*/
		case 'P':
			Display::play2();
			break;
		
    /*start test playing*/
		case 'p':
        Display::play_test();
      break;
      
      /*start test playing*/
		case '@':
      Display::play_reverse();
      break;
      
			
			/*last*/
		case 'l':
		case 'L':
			set.last();
			glutPostRedisplay();
			break;
			
		case ' ':
			set.change_start_stop();
			break;

			
			/*orijin*/	
		case 'o':
		case 'O':
			set.origin();
			glutPostRedisplay();
			break;
			
		case '*':
			
			change_name();
			glutPostRedisplay();
			break;
			
			/*save*/
		case 's':
		case 'S':
			save();
			break;
			
			/*Move数の変更*/
		case 'm':
		case 'M':
		{
			int i=0;
			std::cout << "Move数を入力してください.Haltの場合は負の値にしてください．\n" << std::endl;
			std::cin >> i;
			
			set.change_move(i);
			glutPostRedisplay();
		}
			break;
			
			/*表示形式変更*/
    case 'f':
		case 'F':
		{
			set.change_shape();
      glutPostRedisplay();
		}
			break;
      
			/*テンポ設定*/	
		case 't':
		case 'T':
		{
			int i=0;
			std::cout << "テンポを入力してください.\n" << std::endl;
			std::cin >> i;
			
			set.change_tempo(i);
			glutPostRedisplay();
			
		}
			
			
		case 'a':
		case 'A':
			set.change_aut();
			break;
			
		case '-':
			set.change_conte_grid();
			glutPostRedisplay();

				break;

		case 'v':
      if(set.screen_mode){
        resize(800, 600);
        glutReshapeWindow(800, 600);
        set.screen_mode = 0;
      }else {
        glutFullScreen();
        set.screen_mode = 1;
      }
      glutPostRedisplay();
      break;
			
		case 'K':
      out_put_jpeg();
			break;
		
		default:
			glutPostRedisplay();
			break;
	}
	
}