#include <stdio.h>
#include <windows.h>
void gotoxy(int x, int y)
{
	COORD Cd;
	Cd.X=x;
	Cd.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cd);	
}
int main()
{
	int x, y;
	while(1)
	{
		printf("Input x,y : ");
		scanf("%d,%d",&x, &y);
		system("cls");
		gotoxy(x, y);
		printf("бс\n");
		system("pause");
		system("cls");
	}
	return 0;
}
