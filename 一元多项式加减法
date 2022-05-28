#include <stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct polynomial
{
    int coefficient;//系数
    int exp;//指数
    struct polynomial *next;
}*Link,Node;

Link insert(FILE *fp1)
{
    Link pre,nextt;

    Link head = new Node;
    head->next = NULL;
    
	printf("请输入系数和指数(如：\"2 3\"表示2x^3)：");
    while(1)//连续输入多个系数和指数
    {
		Link node = new Node;
		scanf("%d%d",&node->coefficient,&node->exp);
		fscanf(fp1, "%d %d", &node->coefficient,&node->exp);
		
		if(!node->coefficient || !node->exp)
			break;
		
		pre = head;
		nextt = head->next;
		while(nextt && nextt->exp > node->exp)
		{
			pre = nextt;
			nextt = nextt->next;
		}
		node->next = nextt;
		pre->next = node;
    }
    return head->next;
}

void print(Link head,FILE *fp2)
{
	if (head->coefficient != 0)
    {
        printf("%dx^%d", head->coefficient, head->exp);
        fprintf(fp2, "%dx^%d", head->coefficient, head->exp);
    }
    head = head->next;
	while(head)
	{
		if (head->coefficient > 0)
        {
            printf("+");
            fprintf(fp2, "+");
        }
        else if (head->coefficient == 0) //跳过结果中系数为0的项
        {
            head = head->next;
            continue;
        }
        if (head->exp == 0)
        {
            printf("%d", head->coefficient);
            fprintf(fp2, "%d", head->coefficient);
        }
        else
        {
            printf("%dx^%d", head->coefficient, head->exp);
            fprintf(fp2,"%dx^%d", head->coefficient, head->exp);
        }
       	head = head->next;
	}
	fprintf(fp2,"\n");
}

Link addition(Link heada,Link headb,Link plus)
{
    Link pa,pb,p,f;//指向a，b链表和ab的指针
    pa=heada;
    pb=headb;
    p=plus;
    while(pa != NULL && pb != NULL)//a,b链表都没有没有访问完毕
    {
        if (pa->exp > pb->exp)    //如果指数a>指数b，a节点插入ab链表，a指针后移
        {
            f = (Link)malloc(sizeof(Node));
            f->exp = pa->exp;
            f->coefficient = pa->coefficient;
            p->next = f;
            p = f;
            pa = pa->next;
        }
        else if (pa->exp == pb->exp)      //如果指数a==指数b，a、b系数相加，插入ab链表，a、b指针后移
        {
            f = (Link)malloc(sizeof(Node));
            f->coefficient = pa->coefficient + pb->coefficient;
            f->exp = pa->exp;
            p->next = f;
            p = f;
            pa = pa->next;
            pb = pb->next;
        }
        else     //如果指数a<指数b，b节点插入ab链表，b指针后移
        {
            f = (Link)malloc(sizeof(Node));
            f->coefficient = pb->coefficient;
            f->exp = pb->exp;
            p->next = f;
            p = f;
            pb = pb->next;
        }
        p->next = NULL;
    }

     //如果a、b链表还有尾巴，将它加到ab链表后面
    if(pa!=NULL)
    {
        p->next=pa;
    }
    if(pb!=NULL)
    {
        p->next=pb;
    }
    return plus->next;
}

Link subtraction(Link heada,Link headb,Link minus){
	Link b = headb;
    while (b)
    {
        b->coefficient = b->coefficient * (-1);
        b = b->next;
    }
    addition(heada, headb, minus);
}


int main()
{
	FILE *fp1, *fp2;
    if ((fp1 = fopen("shuru.txt", "w")) == NULL)
    {
        printf("无法打开此文件\n");
        exit(EXIT_FAILURE);
    }
    if ((fp2 = fopen("shuchu.txt", "w")) == NULL)
    {
        printf("无法打开此文件\n");
        exit(EXIT_FAILURE);
    }
	
	Link headA,headB;
	Link plus,minus;
	plus = new Node;
	minus = new Node; 
    
    printf("请输入第一个多项式的系数和指数，以(0 0)结束：\n");
    headA = insert(fp1);
    printf("第一个");
    print(headA,fp2);
    printf("请输入第二个多项式的系数和指数，以(0 0)结束：\n");
    headB = insert(fp1);
    printf("第二个");
    print(headB,fp2);

    printf("合并后");
	plus = addition(headA,headB,plus);
	print(plus,fp2);
	printf("\n");
    minus = subtraction(headA,headB,minus);
    print(minus,fp2);

    free(headA);
    free(headB);
    free(plus);
    free(minus);
    return 0;
}
