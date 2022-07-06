#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <process.h>

int displayMenu(void);
void menu1(void);
void menu2(void);
void menu3(void);
void prompt(int, int);

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
	char subMenu[][20] = { "서브메뉴1", "서브메뉴2", "정기 예금 가입하", "종료하기" };

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
	prompt(30, 7); printf("은행 현재 고시 이자율 확인");
	prompt(20, 20); printf("# 아무키나 입력하면 메인 메뉴로 돌아갑니다");
	getch();
}

// menu2
void menu2(void)
{
	system("cls");
	prompt(30, 7); printf("나의 예상 수익율 확인");
	prompt(20, 20); printf("# 아무키나 입력하면 메인 메뉴로 돌아갑니다");
	getch();
}

// menu3
void menu3(void)
{
	char ch;
	
	while()
	system("cls");
	prompt(30, 7); printf(" 원하시는 예금 액수를 입력하세요:");
	fflush(stdin);
	ch=getchar();
	
	
}

void menu3next(void)
	do
        {
            printf("입력하신 금액이 맞습니까(Y/N)? ");

            scanf("%c", &repeat);
            repeat = toupper(repeat);
            if (repeat != 'Y' && repeat != 'N')         
                printf("Invalid answer. Please enter 'Y' or 'N'.\n\n");
            fflush(stdin);               //*why is this required?*               

        } while (repeat != 'N' && repeat != 'Y');
