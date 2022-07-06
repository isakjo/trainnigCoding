#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <process.h>

int displayMenu(void);
void menu1(void);
void menu2(void);
void menu3(void);
void prompt(int, int);

//void menu1next(void);
//void menu2next(void);
void menu3next(int k);
void inputdollor(int k);
int dollor;
int k;
int main(void)
{
	int select;

	while(1)
	{
		select = displayMenu(); // 메뉴 화면 출력
		if(select=='4') {break;}  // 'exit'
		switch(select){
			case '1' : menu1(); break;
			case '2' : menu2(); break;
			case '3' : menu3(); break;
		}
	}
}

// prompt
void prompt(int xx, int yy) 
{ 
	COORD locate = {xx-1, yy-1}; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), locate); 
}

// displayMenu
int displayMenu(void)
{
	int select = 0;
	int i;
	char subMenu[][100] = { "은행 현재 고시 이자율 확인", "나의 예상 수익율 확인", "정기 예금 가입하기", "종료하기" };

	system("cls");
	for(i=0; i < 4; i++){
		prompt(30, 4+i*2);
		printf("%2d. %s", i+1, subMenu[i]);
	}
	while(select < '1' || select > '4'){
		prompt(25, 17);printf("* 원하시는 메뉴를 선택하세요 : _\b");
		select = getchar();
		fflush(stdin);
	}
	return(select);
}

// menu1
void menu1(void)
{
	system("cls");
	prompt(5, 10); printf("은행 현재 고시 이자율 확인");
	prompt(5, 12); printf("세전금리 세후금리 최고우대금리 중도해지금리 이자계산방식");
	prompt(5, 13); printf("--------------------------------------------------------");
	prompt(5, 17); printf("--------------------------------------------------------");	
	prompt(5, 20); printf("# 아무키나 입력하면 메인 메뉴로 돌아갑니다");
	getch();
}

// menu2
void menu2(void)
{
	system("cls");
	prompt(3, 7); printf("나의 예상 수익율 확인(%d 원 입금 기준)",dollor);
	prompt(3, 9); printf("세전금리 세후금리 최고우대금리 중도해지금리 이자계산방식 세후이자 만기시예상금액");
	prompt(3, 14); printf("--------------------------------------------------------");
	prompt(3, 18); printf("--------------------------------------------------------");
	prompt(3, 20); printf("# 아무키나 입력하면 메인 메뉴로 돌아갑니다");
	getch();
}

// menu3

void menu3(void)
{
//	char ch;
	int k;
	
//	while(((ch = getchar()) != '\n' && ch != EOF)){
		
		system("cls");
		prompt(30, 7); printf(" 원하시는 예금 액수를 입력하세요:");
		fflush(stdin);
//		ch=getchar();
		scanf("%d",&k);
//		if(ch = '\n'){
		return menu3next(k);
//		}
}


void menu3next(int k){
	char ch3n;

	system("cls");
	prompt(30, 5); printf("계약금액 %d 원",k);
	prompt(30, 7); printf("입력하신 내용이 맞습니까(y/n)?");
	ch3n = getchar();
	scanf("%c",&ch3n);
	if(ch3n == 'n'){
		return menu3();
	}else if(ch3n == 'y'){
		return inputdollor(k);
	} 
}

void inputdollor(int k){
	k = dollor;
}
