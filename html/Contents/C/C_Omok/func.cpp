#include "main.h"

char getkey_v1() //입력받을 때까지 대기 
{
	char first_key, second_key;
	first_key=getch();
	if(first_key==-32 || first_key==224)
	{
		second_key=getch();
		return second_key;
	}
	else if(first_key==17) return -1; //Ctrl+q입력시 음수반환 -> 프로그램 종료 
	else if(first_key==13) return 1; //Enter 
	else if(first_key==16) return 2; //Pause 
	else if(first_key==18) return 3; //Resume 
	else return 0; //0이면 아무것도 실행하지 않음 
}
char getkey() //←: -32or224,75  ↑:-32or224,72  →:-32or224,77  ↓:-32or224,80
{
	char first_key, second_key;
	if(kbhit()==1)
	{
		first_key=getch();
		if(first_key==-32 || first_key==224)
		{
			second_key=getch();
			return second_key;
		}
		else if(first_key==17) return -1; //Ctrl+q입력시 음수반환 -> 프로그램 종료 
		else if(first_key==13) return 1; //Enter 
		else if(first_key==16) return 2; //Pause 
		else if(first_key==18) return 3; //Resume 
		else return 0; //0이면 아무것도 실행하지 않음 
	}
	else return 0;
}
void SetCursor(int Cursor_size, int Cursor_Visible) //커서 사이즈(1~100), 1이면 커서 활성화, 0이면 커서 비활성화 
{
	CONSOLE_CURSOR_INFO Cursorinfo;
	Cursorinfo.dwSize = Cursor_size;
	Cursorinfo.bVisible = Cursor_Visible;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Cursorinfo);
}
void gotoxy(int x, int y) //커서의 이동 
{
	COORD Cd;
	Cd.X=x;
	Cd.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cd);
}
bool GameSetting(int *time)
{
	SetCursor(1,0);
	system("title 오목");
	bool set=true, time_set;
	int timerSR=0;
	printf("타이머를 설정하시겠습니까?\n\n");
	printf("    <예>\t<아니오>");
	while(set)
	{
		Sleep(50);
		char input=getkey();
		switch(input) //←: -32or224,75  ↑:-32or224,72  →:-32or224,77  ↓:-32or224,80
		{
		case 75:
			timerSR++;
			break;
		case 77:
			timerSR++;
			break;
		case 1:
			set=false;
		default:
			break;
		}
		if(timerSR%2==0) //타이머 설정 O 
		{
			gotoxy(15,2); printf(" ");
			gotoxy(3,2); printf("*");
			time_set=true;
		}
		else //타이머 설정 X 
		{
			gotoxy(3,2); printf(" ");
			gotoxy(15,2); printf("*");
			time_set=false;
		}
	}
	system("cls");
	if(time_set)
	{
		printf("1턴의 제한시간을 설정하시오.(최대 제한시간은 30을 넘을 수 없습니다.)\nTime : ");
		scanf("%d", time);
		if(*time>30) *time=30;
		if(*time<=0) *time=10;
	}
	system("cls");
	if(timerSR%2==0) return true;
	else return false;
}
void Start_Screen()
{
	printf("\t\t오목\n");
	Sleep(30);
	gotoxy(40,3);
	printf("백돌 차례 "); //50,3에 차례 표시 * 
	Sleep(30);
	gotoxy(40,5);
	printf("흑돌 차례 "); //50,5에 차례 표시 *
	Sleep(30);
	gotoxy(40,14);
	printf("게임 일시정지 -> Ctrl+p");
	gotoxy(40,15);
	printf("게임 종료 -> Ctrl+q");
	gotoxy(0,2);
}
void turn_print(int turn)
{
	if(turn==0) //흑돌 
	{
		gotoxy(50,3); //지난 턴 지우기 
		printf(" ");
		gotoxy(50,5); //현재 턴 표시 
		printf("*");
	}
	else //백돌 
	{
		gotoxy(50,5); //지난 턴 지우기 
		printf(" ");
		gotoxy(50,3);//현재 턴 표시 
		printf("*");
	}
}
void correction(int *col, int *row) //커서가 오목판을 벗어나는 것을 방지(커서 교정)
{
	if(*col<0) *col=18;
	if(*col>18) *col=0;
	if(*row<0) *row=18;
	if(*row>18) *row=0;
}
void column_Printcorrection(int col, int row) //column 튀어 나옴 방지 
{
	if(col>18)
	{
		gotoxy(col*2,row+2);
		printf(" ");
	}
}
void OmokTable_letter(int col, int row) // ┳:1, ┻:2, ┣:3, ┫:4, ╋:5, ┏:6, ┓:7, ┗:8, ┛:9 
{
	if(col==0)
	{
		if(row==0) printf("┏ ");
		else if(row==18) printf("┗ ");
		else printf("┣ ");
	}
	else if(col==18)
	{
		if(row==0) printf("┓ ");
		else if(row==18) printf("┛ ");
		else printf("┫ ");
	}
	else if(row==0) printf("┳ ");
	else if(row==18) printf("┻ ");
	else printf("╋ "); 
}
void GameTimer(int time)
{
	int j_max=0, i_max=0;
	while(time>=10) {time=time-10; j_max++;}
	i_max=time;
	for(int j=0;j<j_max;j++) for(int i=3;i<13;i++) {gotoxy(75-j*2,i); printf("▽");} //(71,3)~(75,13) 
	for(int i=0;i<i_max;i++) {gotoxy(75-j_max*2,3+i); printf("▽");}
}
int GameWinner(int (*Omok_array)[19])
{
	int black=0, white=0, black_max=0, white_max=0;
	bool black_win, white_win;
	for(int j=0;j<19;j++) //가로줄 확인 
	{
		for(int i=0;i<19;i++)
		{
			if(Omok_array[j][i]==1) {if(white==5) {white_win=true; goto E;} black++; white=0;}
			if(Omok_array[j][i]==2) {if(black==5) {black_win=true; goto E;} white++; black=0;}
			if(Omok_array[j][i]==0) {if(black==5) {black_win=true; goto E;} if(white==5) {white_win=true; goto E;} black=0; white=0;}
		}
	}
	for(int j=0;j<19;j++) //세로줄 확인 
	{
		for(int i=0;i<19;i++)
		{
			if(Omok_array[i][j]==1) {if(white==5) {white_win=true; goto E;} black++; white=0;}
			if(Omok_array[i][j]==2) {if(black==5) {black_win=true; goto E;} white++; black=0;}
			if(Omok_array[i][j]==0) {if(black==5) {black_win=true; goto E;} if(white==5) {white_win=true; goto E;} black=0; white=0;}
		}
	}
	for(int k=0;k<19;k++) //(0,0), (18,0), (18,18) '\' 대각선 확인 
	{
		for(int j=k,i=0;j<19;j++,i++)
		{
			if(Omok_array[j][i]==1) {if(white==5) {white_win=true; goto E;} black++; white=0;}
			if(Omok_array[j][i]==2) {if(black==5) {black_win=true; goto E;} white++; black=0;}
			if(Omok_array[j][i]==0) {if(black==5) {black_win=true; goto E;} if(white==5) {white_win=true; goto E;} black=0; white=0;}
		}
	}
	for(int k=1;k<19;k++) //(1,0), (0,18), (17,18) '\' 대각선 확인 
	{
		for(int j=k,i=0;j<19;j++,i++)
		{
			if(Omok_array[i][j]==1) {if(white==5) {white_win=true; goto E;} black++; white=0;}
			if(Omok_array[i][j]==2) {if(black==5) {black_win=true; goto E;} white++; black=0;}
			if(Omok_array[i][j]==0) {if(black==5) {black_win=true; goto E;} if(white==5) {white_win=true; goto E;} black=0; white=0;}
		}
	}
	for(int k=18;k>=0;k--) //(0,0), (18,0), (0,18) '/' 대각선 확인 
	{
		for(int i=k,j=0;i>=0;j++,i--)
		{
			if(Omok_array[j][i]==1) {if(white==5) {white_win=true; goto E;} black++; white=0;}
			if(Omok_array[j][i]==2) {if(black==5) {black_win=true; goto E;} white++; black=0;}
			if(Omok_array[j][i]==0) {if(black==5) {black_win=true; goto E;} if(white==5) {white_win=true; goto E;} black=0; white=0;}
		}
	}
	for(int k=1;k<19;k++) //(1,18), (18,1), (18,18) '/' 대각선 확인 
	{
		for(int j=k,i=18;j<19;j++,i--)
		{
			if(Omok_array[j][i]==1) {if(white==5) {white_win=true; goto E;} black++; white=0;}
			if(Omok_array[j][i]==2) {if(black==5) {black_win=true; goto E;} white++; black=0;}
			if(Omok_array[j][i]==0) {if(black==5) {black_win=true; goto E;} if(white==5) {white_win=true; goto E;} black=0; white=0;}
		}
	}
E:	if(black_win==true) return 1;
	if(white_win==true) return 2;
	return 0;
}
void Pause(bool *quit)
{
	char input;
	int Iteration=0;
	gotoxy(40,11);
	printf("게임 재개 -> Ctrl+r");
	while(true)
	{
		Sleep(50);
		input=getkey();
		if(input==3)
		{
			gotoxy(40,10);
			printf("     ");
			gotoxy(40,11);
			printf("                   ");
			break;
		}
		if(Iteration%20==0)
		{
			gotoxy(40,10);
			printf("Pause");
		}
		if((Iteration+10)%20==0)
		{
			gotoxy(40,10);
			printf("     ");
		}
		if(input<0)
		{
			gotoxy(40,10);
			printf("     ");
			gotoxy(40,11);
			printf("                   ");
			*quit=true;
			break;
		}
		Iteration++;
	}
}
bool ReStart(int (*Omok_array)[19], bool win)
{
	char input;
	bool set=true, Re;
	int Res=0, row=22;
	if(win) row++;
	printf("\n    <다시하기>\t<끝내기>");
	while(set)
	{
		Sleep(50);
		input=getkey();
		switch(input) //←: -32or224,75  ↑:-32or224,72  →:-32or224,77  ↓:-32or224,80
		{
		case 75:
			Res++;
			break;
		case 77:
			Res++;
			break;
		case 1:
			set=false;
		default:
			break;
		}
		if(Res%2==0) //다시하기 
		{
			gotoxy(15,row); printf(" ");
			gotoxy(3,row); printf("*");
			Re=true;
		}
		else //끝내기 
		{
			gotoxy(3,row); printf(" ");
			gotoxy(15,row); printf("*");
			Re=false;
		}
	}
	printf("\n");
	return Re;
}
