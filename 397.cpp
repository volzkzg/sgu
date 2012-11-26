#include <cstdio>  
#include <cstring>  
#include <list>  
#include <iostream>
#include <string>
      
using namespace std;  

string org;

int main(void) {  
    list<char> word;  
    cin >> org;
    int i;  
    int len = org.size(); 
    list<char>::iterator it = word.begin();  
    for (i = 0; i < len; ++i) {  
	if (org[i] == 'L') {  
	    if (it != word.begin()) {  
		--it;  
	    }  
	} else if (org[i] == 'R') {  
	    if (it != word.end()) {  
		++it;  
	    }  
	} else {  
	    word.insert(it,org[i]);  
	}  
    }  
    for (it = word.begin(); it != word.end(); ++it) {  
	printf ("%c", *it);  
    }  
    printf ("\n");  
    return 0;  
}  
