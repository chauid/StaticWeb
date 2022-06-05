#include <stdio.h>
#include <conio.h>
char getkey()
{
	if(kbhit()==1) return getch();
	else return '\0';
}
int main()
{
	int i, j, f=1;
	char key, key1, key2;
	while(1)
	{

		key=kbhit();
		while(key==1)
		{
			key1=getkey();
			printf("입력한 문자1 : %c, 값 : %d buffer : %d\n", key1, key1, kbhit());
			key=kbhit();
			printf("buffer2: %d\n", key);
		}
	}
}

