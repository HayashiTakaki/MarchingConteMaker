#include <iostream>
#include "no7.cpp"



int main(int argc, char *argv[])
{
	
	if (argc == 2) {
		no7 test(argv[1]);
		test.start_sim();

	}else {
		no7 test;
		test.start_sim();

}
	
	return 0;
}




