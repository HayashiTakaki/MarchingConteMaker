#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int isSubstring(string s1, string s2){
	
	int i, k;
	
	if (s1.empty() || s2.empty()) {
		cout << "error:s1 or s2 is NULL" << endl;
		exit(1);
	}
	
	//比較
	for (i = 0; i < s1.length(); i++) {
		
		//先頭からを比較
		for (k = 0; k < s2.length(); k++) {
			cout << s1[i + k] << ";" << s2[k] << endl;
			if (s1[i + k] != s2[k]) {
				break;
			}
		}
		
		//kが終端まで達していれば真(1)と判定
		if (k == s2.length()) {
			return (1);
		}
		
	}
	
	//一部となっていなければ偽(0)と判定
	return (0);
}

int main (int argc, char * const argv[]) {
	string s1,s2;
	
	//input
	cout << "input s1" << endl;
	cin >> s1;
	
	cout << "input s2" << endl;
	cin >> s2;
	
	
	
	if (isSubstring(s1, s2)) {
		cout << "ture" << endl;
	}else {
		cout << "false" << endl;
	}
	
	return (0);
}
