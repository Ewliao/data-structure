#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void jieguo(FILE *fp,FILE *fp1);
int levelf(char);

typedef struct {
	char symbol;
	int level;
}stacksym;

int main(){
	FILE *fp,*fp1;
    if((fp=fopen("data.txt","r"))==NULL)
    {
        printf("无法打开data.txt\n");//打开文件失败时输出
        exit(EXIT_FAILURE);
    }
    if((fp1=fopen("data1.txt","w"))==NULL)
    {
        printf("无法打开data1.txt\n");//打开文件失败时输出
        exit(EXIT_FAILURE);
    }
    
	jieguo(fp,fp1); 
	fclose(fp);
    fclose(fp1);
    system("pause");
    return 0;
}

int levelf(char ch){
	int level;
	if(ch=='+'||ch=='-')//将+-运算符优先级定义为1
	    return 1;
	else if(ch=='*'||ch=='/')//将乘除运算符优先级定义为2
	    return 2;
	else//结尾用‘#’来标志，运算优先级最弱
	    return 0;
}

void jieguo(FILE *fp,FILE *fp1){
	stacksym character[20];
    int num[20];
	character[0].level = -1;
	char ch;
	int a = -1, b = -1; 
	int shu,level;
	while(1){
		fscanf(fp,"%d %c",&shu,&ch);
		level = levelf(ch);
		if(level>character[b].level || b==-1)//优先级高的入栈
        {
        	a++;
            b++;
            num[a]=shu;
            character[b].symbol=ch;
            character[b].level=level;
        }
        else 
        {
        	a++;
        	num[a]=shu;
            while(level<=character[b].level && b>-1)//优先级小于等于之前元素
            {            
                switch(character[b].symbol)
                {
                    case '+':num[a-1]=num[a-1]+num[a];
                    break;
                    case '-':num[a-1]=num[a-1]-num[a];
                    break;
                    case '*':num[a-1]=num[a-1]*num[a];
                    break;
                    case '/':num[a-1]=num[a-1]/num[a];
                    break;
                }
                a--;
                b--;
            }
            b++;
            character[b].symbol=ch;
            character[b].level=level;
            if(character[b].symbol=='#')
            {
                printf("%d",num[a]);
                fprintf(fp1, "%d", num[a]);
                break;
            }
        }
	}
}
