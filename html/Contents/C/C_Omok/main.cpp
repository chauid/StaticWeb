#include "main.h"
#include "func.cpp"
//●:백돌  ○:흑돌 ■:백돌 놓기  □ :흑돌 놓기 // ┳:1, ┻:2, ┣:3, ┫:4, ╋:5, ┏:6, ┓:7, ┗:8, ┛:9 
char OmokTable_print[19][19][3]={ //좌표 시작점 : (0,2)
	"┏","┳","┳","┳","┳","┳","┳","┳","┳","┳","┳","┳","┳","┳","┳","┳","┳","┳","┓",
	"┣","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","┫",
	"┣","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","┫",
	"┣","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","┫",
	"┣","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","┫",
	"┣","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","┫",
	"┣","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","┫",
	"┣","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","┫",
	"┣","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","┫",
	"┣","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","┫",
	"┣","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","┫",
	"┣","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","┫",
	"┣","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","┫",
	"┣","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","┫",
	"┣","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","┫",
	"┣","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","┫",
	"┣","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","┫",
	"┣","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","╋","┫",
	"┗","┻","┻","┻","┻","┻","┻","┻","┻","┻","┻","┻","┻","┻","┻","┻","┻","┻","┛"
};
int main()
{
RE:	int OmokTable_array[19][19]={0}; //1은 흑돌, 2는 백돌 
	bool time;
	int timer=0, timer_var;
	int *ptimer=&timer;
	time=GameSetting(ptimer); //타이머 설정 
	timer_var=timer; //타이머 초기화 
	Start_Screen();
	for(int i=0;i<19;i++) //OmokTable_print 
	{
		for(int j=0;j<19;j++) printf("%s ", OmokTable_print[i][j]);
		Sleep(30);
		printf("\n");
	}
	char input, turn=0; //turn이 0이면 흑돌 1이면 백돌 
	int column=9, row=9, last_col, last_row; //오목판 좌표 변수 
	int iteration=0, time_sec=0, last_time_sec=0, timer_col=0, timer_row=0; //함수 반복 및 시간 변수  
	//시작 위치 : (0,2) => (column*2, row+2) //last는 지나간 자리의 좌표를 저장 
	int *pcol=&column, *prow=&row;
	bool quit=false, turn_change=false, GameStart=false, winner=false;
	bool *pquit=&quit;
S:	while(!quit) //게임 시작 
	{
		if(!GameStart && time) //타이머 출력(72,3)~(75,12) //게임 시작시 첫 타이머 출력 
		{
			gotoxy(72,2); printf("Timer");
			GameTimer(timer); //타이머 출력(72,3)~(75,12) 
			while(timer_var>=10) {timer_var=timer_var-10; timer_col++;} //타이머 지우는 column 계산 
			timer_row=timer_var; //타이머 지우는 row 계산 
			timer_var=timer; //타이머 초기화 
			GameStart=true;
		}
		input=getkey();
		if(input!=0)
		{
			gotoxy(column*2,row+2);
			if(OmokTable_array[column][row]==0) OmokTable_letter(last_col, last_row); //지나간 좌표의 문자열 출력 
			else if(OmokTable_array[column][row]==1) printf("○");
			else if(OmokTable_array[column][row]==2) printf("●");
			column_Printcorrection(column, row);
		}
		last_col=column;
		last_row=row;
		switch(input) //←: -32or224,75  ↑:-32or224,72  →:-32or224,77  ↓:-32or224,80
		{
		case 75:
			column--;
			break;
		case 72:
			row--;
			break;
		case 77:
			column++;
			break;
		case 80:
			row++;
			break;
		case 3: //case 3(Resume)일때 아무것도 하지 않음 
		case 0:
			break;
		case 2:
			Pause(pquit);
			if(quit) goto S;
			break;
		case 1:
			if(OmokTable_array[column][row]!=0) turn_change=false; //돌 중복 놓기 방지 
			else turn_change=true; //턴 넘김 
			break;
		case -1: //게임 종료 
			quit=true;
			gotoxy(0, 22);
			goto S;
		}
		correction(pcol, prow); //출력 전 좌표가 오목판을 벗어나는 것을 방지 
		if(turn_change) //돌을 놓을 때 실행 
		{
			if(turn==0) //흑돌 차례 
			{
				gotoxy(column*2,row+2);
				printf("○");
				OmokTable_array[column][row]=1; //데이터배열에 흑돌값 저장 
				column++;
				turn=1; //백돌 차례로 넘김 
			}
			else //백돌 차례 
			{
				gotoxy(column*2,row+2);
				printf("●");
				OmokTable_array[column][row]=2; //데이터배열에 백돌값 저장 
				column++;
				turn=0; //흑돌 차례로 넘김 
			}
			if(time)
			{
				GameTimer(timer); //타이머 출력(72,3)~(75,12) 
				timer_col=0; timer_row=0; //타이머 column, row 초기화 
				while(timer_var>=10) {timer_var=timer_var-10; timer_col++;} //타이머 지우는 column 계산 
				timer_row=timer_var; //타이머 지우는 row 계산 
				timer_var=timer; //타이머 초기화 
			}
			turn_change=false;
			if(GameWinner(OmokTable_array)!=0) {winner=true; quit=true; goto S;}; //게임 종료 
		}
		if(iteration%16==0) //돌을 놓치 않는 모든 순간에 반복 실행 
		{
			gotoxy(column*2,row+2);
			if(turn==0) printf("□"); //차례==백돌 
			else printf("■"); //차례==흑돌 
		}
		if((iteration+8)%16==0)
		{
			gotoxy(column*2,row+2);
			if(OmokTable_array[column][row]==0) OmokTable_letter(last_col, last_row); //지나간 좌표의 문자열 출력 
			else if(OmokTable_array[column][row]==1) printf("○");
			else if(OmokTable_array[column][row]==2) printf("●");
			column_Printcorrection(column, row);
		}
		Sleep(16); //초당 60ms 대기 
		iteration++; //함수 반복 횟수 : 게임 화면 업데이트 
		if(iteration%60==0) time_sec++;
		if(last_time_sec!=time_sec && time) //타이머 작동 
		{
			if(timer_row==0) {timer_row=10; timer_col--;}
			if(timer_col<1) timer_col=0;
			gotoxy(75-timer_col*2,2+timer_row);
			printf("  ");
			timer_row--;
			last_time_sec=time_sec;
			if(timer_col==0 && timer_row==0) //돌 강제 놓기 
			{
				int c=0, r=0;
				while(OmokTable_array[column][row]!=0)
				{
					if(c<19) {column++; c++;}
					else if(r<19) {row++; r++;}
					else {column++; row++;}
					correction(pcol, prow); //입력 전 커서가 오목판을 벗어나는 것을 방지 
				}
				turn_change=true;
			}
		}
/*		gotoxy(40,8); //함수 반복 횟수 : 게임 화면 업데이트 
		printf("게임 시간 : %d", time_sec);
		gotoxy(55,18);
		printf("함수 반복 횟수 : %d", iteration);*/
		turn_print(turn);
	}
	gotoxy(0,21);
	if(GameWinner(OmokTable_array)==1) printf("승자 : 흑돌!\n");
	if(GameWinner(OmokTable_array)==2) printf("승자 : 백돌!\n");
	if(ReStart(OmokTable_array, winner)) {system("cls"); goto RE;} //게임 재시작 
	printf("오목을 종료합니다.\n");
	system("pause");
/*	for(int j=0;j<19;j++) 오목 배열 보기 
	{
		for(int i=0;i<19;i++) printf("%d ", Omok_array[i][j]);
		printf("\n");
	}*/ 
    return 0;
}
