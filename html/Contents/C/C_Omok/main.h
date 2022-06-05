#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
char getkey_v1(); //실험용 
char getkey(); //←: -32or224,75  ↑:-32or224,72  →:-32or224,77  ↓:-32or224,80
void SetCursor(int Cursor_size, int Cursor_Visible); // 커서 사이즈(1~100), 1이면 커서 활성화, 0이면 커서 비활성화 
void gotoxy(int x, int y); //커서의 이동 
bool GameSetting(int *time); //게임 시작 전 타이머 설정 
void Start_Screen(); //게임 화면 출력 
void turn_print(int turn); //턴을 표시 
void correction(int *col, int *row); //커서가 오목판을 벗어나는 것을 방지(커서 교정) 
void column_Printcorrection(int col, int row); //column 튀어 나옴 방지 
void OmokTable_letter(int col, int row); // ┳:1, ┻:2, ┣:3, ┫:4, ╋:5, ┏:6, ┓:7, ┗:8, ┛:9 
void GameTimer(int time); //타이머 출력(71,3)~(75,13) 
int GameWinner(int (*Omok_array)[19]); //게임 승리 조건 
void Pause(bool *quit); //게임 일시정지 
bool ReStart(int (*Omok_array)[19], bool win); //게임 재시작 
