#include <stdio.h>

int A , B ;
char s [12];
int main ()
{
scanf ("% d % d " ,&A ,& B );
scanf ("% s " ,& s );
for ( int i =0; i < A ; i ++) if (!( '0' <= s [ i ] && s [ i ] <= '9'))
{
puts (" No "); return 0;
}
if ( s [ A ]!= '-')
{
puts (" No "); return 0;
}
for ( int i = A +1; i <= A + B ; i ++) if (!( '0' <= s [ i ]&& s [ i ] <= '9'))
{
puts (" No "); return 0;
}
puts (" Yes ");
}