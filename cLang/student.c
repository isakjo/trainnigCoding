#include <stdio.h>
struct student{
	char firstName[50];
	int classNumber;
	int studentNumber;
}s[5]; 

int num = 5;
int i = 1;
int j = 1;

int main() {
	for(i;i<num+1;i++){
		printf("%d번째 학생 정보 입력\n",i);
		printf("이름:");
		scanf("%s",&s[i].firstName); 
		printf("클래스 번호:");
		scanf("%d",&s[i].classNumber);
		printf("학생 번호:");
		scanf("%d",&s[i].studentNumber);
		printf("\n\n");
	}
  
	for(j;j<num+1;j++){
		printf("%d번째 학생 정보\n",j);
		printf("이름:%s,클래스 번호:%d,학생 번호:%d\n",s[j].firstName,s[j].classNumber,s[j].studentNumber);
	}
		
	
    printf("\n------------------------------------------------------------------------\n");
    printf("written by : 조이삭\n");
    printf("------------------------------------------------------------------------\n");
    return 0;
}
