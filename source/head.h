#define maximum_member 150


void resize(int w, int h);
void drow_circle(double x,double y);
void drow_circle(double x,double y,double r,double g,double b);
void drow_goust_circle(double x,double y);
void drow_tb(double x,double y);
void drow_cg(double x,double y);
void drow_ba(double x,double y);
void drow_so(double x,double y);
void drow_fl(double x,double y);
void drow_goust_Line(double x1,double y1,double x2,double y2);
void print_No(int now);
void print_Move(int i);
void print_tempo(int t);
void print_how_to_use();
void print_net();
void print_net_move(int n,int t);
void print_warning_net();
void print_warning_net_move(int n, int t);
void change_name();
void revise();
void main_menu(int x);
void move_menu(int x);
void tempo_menu(int x);
void sizemenu(int n);
void out_put_jpeg();
void GLUT_SET_MENU();
int search_close(double x,double y);
double search_close_distance(double x,double y);
void  delete_all_conte();
void delete_this_conte();
void add_conte();
void DrawString(std::string str, double x, double y);
double warning_d(int a, int b);
double error_d(int a, int b);





class member{
private:
	static int count;
	static int max_member;
	char name[10];
  int shape_type;
	double xpos[maximum_member];
	double ypos[maximum_member];
	double dx;
	double dy;
	double sx;
	double sy;
	double red;
	double blue;
	double green;
	
	
	
public:
	
	member();
	member(int n);
	void put_member(int n,int t);
	void put_name();
	void clear_name();
	void set_name(char *c);
	
	double return_xpos(int i);
	double return_ypos(int i);
	double return_sx();
	double return_sy();
	double return_dx();
	double return_dy();


	char * return_name();
	
	void add_d();
	
	void print_member(int i);
	void put_member_for_printout(int n);
	
	void pos_change(int i,double x,double y);
	void change_xpos(int i,double x);
	void change_ypos(int i,double y);
	void change_dx(double x);
	void change_dy(double y);
	void change_sx(double x);
	void change_sy(double y);

	void change_color(double r,double g,double b);
	
	void pos_reset(int i);
	void print_positions(int i);
	double distance(double x,double y,int i);
	void drow_goust(int i);
  void drow_line(int now);

	void next_move(int i);
	static void count_set(int i);
	static void count_down();
	static void count_up();
	static int return_count();
	static int return_max_member();
  int return_shape_type();
	static void set_max_member(int now);
  void set_shape_type();
};


static class Mouse_Contorol{
	int ButtonStatus;
	
	
	
public:
  int count;
	double x1;
	double x2;
	double y1;
	double y2;
	double mx;
	double my;
	member *marray[maximum_member];
	int flag;
	bool drow_rect;
	Mouse_Contorol();
	static void crick_motion(int button, int state, int x, int y);
	static void drug_motion(int x,int y);
	static void left_click_start(double x,double y);
	static void left_click_end(double x,double y);	
}mouse;


class field{
	static double x;
	static double y;
	
public:
	//con=1:春コン用　op=1:補助線追加
	static void drow_grid(int con,int op);
	static void drow_24_24();
	static void drow_36_36();
private:
	static void put_point(double x,double y);
	static void drow_L_and_X(void);
};

static class setting{
private:
	int tempo[maximum_member];
	int move[maximum_member];
	int max_conte;
	int now;
	int member_num;
	int display_size_x;
	int display_size_y;
	int point;
	int conte_size;
	bool conte_grid;
	char title[25];
	bool aut;
	double xinterbal;
	double yinterbal;
  bool shape;
  char coment[maximum_member][30];


	
public:
	
	int temp_no;
	bool start_stop;
  int screen_mode;

	setting();
	int return_num_of_member();
	int return_now();
	int return_max_conte();
	int return_tempo(int i);
	int return_w();
	int return_h();
	int return_point();
	int return_move(int i);
	bool return_aut();
	int return_conte_size();
	bool return_conte_grid();
	double return_xinterbal();
	double return_yinterbal();
  bool return_shape();
	
	
	void set_display_size(int x,int y);
	void set_point(int i);
	void change_move(int i);
	void change_tempo(int i);
	void change_aut();
	void change_conte_grid();
	void change_conte_size(int n);
	void change_start_stop();
  void change_shape();
  void change_no_and_maxconte(int no, int max);
	void reset_position();
  void set_coment(int i, char* s);
	
	void last();
	int size_x();
	int size_y();
	void next();
	void back();
	void origin();
	
	char *  return_title();
	
	int print_tempo(int i);
	int print_move(int i);
	int print_max_conte();
	
	void read_file(char * name);
  char * get_coment(int n);
  void set_coment(char* s);
	
	
}set;


