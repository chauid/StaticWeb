#include "main.h"
#include "func.cpp"
//��:�鵹  ��:�浹 ��:�鵹 ����  �� :�浹 ���� // ��:1, ��:2, ��:3, ��:4, ��:5, ��:6, ��:7, ��:8, ��:9 
char OmokTable_print[19][19][3]={ //��ǥ ������ : (0,2)
	"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��",
	"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��",
	"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��",
	"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��",
	"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��",
	"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��",
	"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��",
	"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��",
	"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��",
	"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��",
	"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��",
	"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��",
	"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��",
	"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��",
	"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��",
	"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��",
	"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��",
	"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��",
	"��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��"
};
int main()
{
RE:	int OmokTable_array[19][19]={0}; //1�� �浹, 2�� �鵹 
	bool time;
	int timer=0, timer_var;
	int *ptimer=&timer;
	time=GameSetting(ptimer); //Ÿ�̸� ���� 
	timer_var=timer; //Ÿ�̸� �ʱ�ȭ 
	Start_Screen();
	for(int i=0;i<19;i++) //OmokTable_print 
	{
		for(int j=0;j<19;j++) printf("%s ", OmokTable_print[i][j]);
		Sleep(30);
		printf("\n");
	}
	char input, turn=0; //turn�� 0�̸� �浹 1�̸� �鵹 
	int column=9, row=9, last_col, last_row; //������ ��ǥ ���� 
	int iteration=0, time_sec=0, last_time_sec=0, timer_col=0, timer_row=0; //�Լ� �ݺ� �� �ð� ����  
	//���� ��ġ : (0,2) => (column*2, row+2) //last�� ������ �ڸ��� ��ǥ�� ���� 
	int *pcol=&column, *prow=&row;
	bool quit=false, turn_change=false, GameStart=false, winner=false;
	bool *pquit=&quit;
S:	while(!quit) //���� ���� 
	{
		if(!GameStart && time) //Ÿ�̸� ���(72,3)~(75,12) //���� ���۽� ù Ÿ�̸� ��� 
		{
			gotoxy(72,2); printf("Timer");
			GameTimer(timer); //Ÿ�̸� ���(72,3)~(75,12) 
			while(timer_var>=10) {timer_var=timer_var-10; timer_col++;} //Ÿ�̸� ����� column ��� 
			timer_row=timer_var; //Ÿ�̸� ����� row ��� 
			timer_var=timer; //Ÿ�̸� �ʱ�ȭ 
			GameStart=true;
		}
		input=getkey();
		if(input!=0)
		{
			gotoxy(column*2,row+2);
			if(OmokTable_array[column][row]==0) OmokTable_letter(last_col, last_row); //������ ��ǥ�� ���ڿ� ��� 
			else if(OmokTable_array[column][row]==1) printf("��");
			else if(OmokTable_array[column][row]==2) printf("��");
			column_Printcorrection(column, row);
		}
		last_col=column;
		last_row=row;
		switch(input) //��: -32or224,75  ��:-32or224,72  ��:-32or224,77  ��:-32or224,80
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
		case 3: //case 3(Resume)�϶� �ƹ��͵� ���� ���� 
		case 0:
			break;
		case 2:
			Pause(pquit);
			if(quit) goto S;
			break;
		case 1:
			if(OmokTable_array[column][row]!=0) turn_change=false; //�� �ߺ� ���� ���� 
			else turn_change=true; //�� �ѱ� 
			break;
		case -1: //���� ���� 
			quit=true;
			gotoxy(0, 22);
			goto S;
		}
		correction(pcol, prow); //��� �� ��ǥ�� �������� ����� ���� ���� 
		if(turn_change) //���� ���� �� ���� 
		{
			if(turn==0) //�浹 ���� 
			{
				gotoxy(column*2,row+2);
				printf("��");
				OmokTable_array[column][row]=1; //�����͹迭�� �浹�� ���� 
				column++;
				turn=1; //�鵹 ���ʷ� �ѱ� 
			}
			else //�鵹 ���� 
			{
				gotoxy(column*2,row+2);
				printf("��");
				OmokTable_array[column][row]=2; //�����͹迭�� �鵹�� ���� 
				column++;
				turn=0; //�浹 ���ʷ� �ѱ� 
			}
			if(time)
			{
				GameTimer(timer); //Ÿ�̸� ���(72,3)~(75,12) 
				timer_col=0; timer_row=0; //Ÿ�̸� column, row �ʱ�ȭ 
				while(timer_var>=10) {timer_var=timer_var-10; timer_col++;} //Ÿ�̸� ����� column ��� 
				timer_row=timer_var; //Ÿ�̸� ����� row ��� 
				timer_var=timer; //Ÿ�̸� �ʱ�ȭ 
			}
			turn_change=false;
			if(GameWinner(OmokTable_array)!=0) {winner=true; quit=true; goto S;}; //���� ���� 
		}
		if(iteration%16==0) //���� ��ġ �ʴ� ��� ������ �ݺ� ���� 
		{
			gotoxy(column*2,row+2);
			if(turn==0) printf("��"); //����==�鵹 
			else printf("��"); //����==�浹 
		}
		if((iteration+8)%16==0)
		{
			gotoxy(column*2,row+2);
			if(OmokTable_array[column][row]==0) OmokTable_letter(last_col, last_row); //������ ��ǥ�� ���ڿ� ��� 
			else if(OmokTable_array[column][row]==1) printf("��");
			else if(OmokTable_array[column][row]==2) printf("��");
			column_Printcorrection(column, row);
		}
		Sleep(16); //�ʴ� 60ms ��� 
		iteration++; //�Լ� �ݺ� Ƚ�� : ���� ȭ�� ������Ʈ 
		if(iteration%60==0) time_sec++;
		if(last_time_sec!=time_sec && time) //Ÿ�̸� �۵� 
		{
			if(timer_row==0) {timer_row=10; timer_col--;}
			if(timer_col<1) timer_col=0;
			gotoxy(75-timer_col*2,2+timer_row);
			printf("  ");
			timer_row--;
			last_time_sec=time_sec;
			if(timer_col==0 && timer_row==0) //�� ���� ���� 
			{
				int c=0, r=0;
				while(OmokTable_array[column][row]!=0)
				{
					if(c<19) {column++; c++;}
					else if(r<19) {row++; r++;}
					else {column++; row++;}
					correction(pcol, prow); //�Է� �� Ŀ���� �������� ����� ���� ���� 
				}
				turn_change=true;
			}
		}
/*		gotoxy(40,8); //�Լ� �ݺ� Ƚ�� : ���� ȭ�� ������Ʈ 
		printf("���� �ð� : %d", time_sec);
		gotoxy(55,18);
		printf("�Լ� �ݺ� Ƚ�� : %d", iteration);*/
		turn_print(turn);
	}
	gotoxy(0,21);
	if(GameWinner(OmokTable_array)==1) printf("���� : �浹!\n");
	if(GameWinner(OmokTable_array)==2) printf("���� : �鵹!\n");
	if(ReStart(OmokTable_array, winner)) {system("cls"); goto RE;} //���� ����� 
	printf("������ �����մϴ�.\n");
	system("pause");
/*	for(int j=0;j<19;j++) ���� �迭 ���� 
	{
		for(int i=0;i<19;i++) printf("%d ", Omok_array[i][j]);
		printf("\n");
	}*/ 
    return 0;
}
