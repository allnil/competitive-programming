/*
Sample Output
BeijuThis_is_a__text
Happy_Birthday_to_Tsinghua_University
*/
#include <stdio.h>
#include <list>
#include <string.h>
#include  <iostream>

using namespace std;

int main(){
	ios :: sync_with_stdio ( false ) ;
	cin.tie ( nullptr ) ;
	cout.tie ( nullptr ) ;

  string s;
  char ss[100002];
  while(scanf("%100000s", ss) != EOF){
    s =ss;
    list < char > line;

    auto it = line.begin();
		for  ( auto & i : s )  {
			if  ( i ==  '[' ) it = line . begin ( ) ;
			else  if  ( i ==  ']' ) it = line . end ( ) ;
			else line . emplace ( it , i ) ;
		}

		for  ( auto & i : line ) cout << i ;
		cout <<  "\n" ;
  }
  return 0;
}