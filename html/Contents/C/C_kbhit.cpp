#include <stdio.h>
#include <conio.h>
char getkey() //left 75, right 77, up 72, down 80
{
	if(kbhit()==1) return getch();
	else return '\0';
}
int main()
{
	char key;
	while(1)
	{
		key=kbhit();
		while(key==1)
		{
			key=getkey();
			if(key == -32)
			{
				key=getkey();
				switch(key)
				{
					case 75: printf("�Է��� ���� : ��\n"); break;
					case 77: printf("�Է��� ���� : ��\n"); break;
					case 72: printf("�Է��� ���� : ��\n"); break;
					case 80: printf("�Է��� ���� : ��\n"); break;
					default: break;
				}
			}
			else printf("�Է��� ���� : %c, �� : %d buffer : %d\n", key, key, kbhit());
		}
	}
}

