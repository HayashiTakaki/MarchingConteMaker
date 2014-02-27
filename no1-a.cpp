#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main (int argc, char * const argv[]) {
	string c;
	int i,k;
	
	//input
	cin >> c;
	
	//比較
	for (i = 0; i < c.length() ; i++) {
		for (k = i + 1; k < c.length(); k++) {
			
			//重複があればfalseを出力
			if (c[i] == c[k]) {
				cout << "false" << endl;
				return (0);
			}
		}
	}
	
	//重複が無ければtureを出力
	cout << "ture" << endl;
	return (0);
}
