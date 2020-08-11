#include"CirList.h"
#include<stdio.h>
#include<stdlib.h>

#define CHOICE1 1
#define CHOICE2 2
#define CHOICE3 3
#define CHOICE4 4
#define CHOICE5 5
#define CHOICE6 6
#define CHOICE7 7
#define CHOICE8 8
#define CHOICE9 9
#define CHOICE10 10
#define CHOICE0 0

int menu()
{
	printf("====================\n");
	printf("1.头部增加结点\n");
	printf("2.尾部增加结点\n");
	printf("3.定位增加结点\n");
	printf("4.头部删除结点\n");
	printf("5.尾部删除结点\n");
	printf("6.定位删除结点\n");
	printf("7.清空链表\n");
	printf("8.获取结点个数\n");
	printf("9.打印链表\n");
	printf("10.销毁链表\n");
	printf("0.退出\n");
	printf("====================\n");
	printf("请输入：");
  int choice;
  scanf("%d", &choice);
  return choice;
}

int main()                                                                       
{ 
	CList c;
	CListInit(&c);
  int choice;
	while(1)
	{
		choice = menu();
		switch(choice)
		{
			case CHOICE0:
				printf("再见\n");
				exit(0);
        break;
			case CHOICE1:	
				printf("头部增加结点\n");
				char data1[1024];
				printf("请输入您要插入的值：");
				scanf("%s", data1);
				CListPushFront(&c, data1);
				printf("增加成功\n");
				break;
			case CHOICE2:
				printf("尾部增加结点\n");
				char data2[1024];
				printf("请输入您要插入的值：");
				scanf("%s", data2);
				CListPushBack(&c, data2);
				printf("增加成功\n");
				break;
			case CHOICE3:	
				printf("定位增加结点\n");
				char data3[1024];
				int pos1;
				printf("请输入您要插入的位置和值：");
				scanf("%d,%s", &pos1, data3);
        if(!(pos1 >= 0 && pos1 <= Size(&c)))
        {
          printf("你敲nm呢,给爷爬\n");
          break;
        }
				CListInsert(&c, pos1, data3);
				printf("增加成功\n");
				break;
			case CHOICE4:	
				printf("头部删除结点\n");
        if(NULL == c._pHead)
        {
          printf("无结点，删除失败\n");
          break;
        }
				CListPopFront(&c);
				printf("删除成功\n");
				break;
			case CHOICE5:
				printf("尾部删除结点\n");
        if(NULL == c._pHead)
        {
          printf("无结点，删除失败\n");
          break;
        }
				CListPopBack(&c);
				printf("删除成功\n");
				break;
			case CHOICE6:
				printf("定位删除结点\n");
        if(NULL == c._pHead)
        {
          printf("无结点，删除失败\n");
          break;
        }
				int pos2;
				printf("请输入您要删除的位置：");
				scanf("%d", &pos2);
        if(!(pos2 >= 0 && pos2 < Size(&c)))
        {
          printf("你敲nm呢,给爷爬\n");
          break;
        }
				CListErase(&c, pos2);
				printf("删除成功\n");
				break;	
			case CHOICE7:
				CListClear(&c);
				printf("链表清空成功\n");
				break;
			case CHOICE8:
				CListSize(&c);
				break;
			case CHOICE9:
				Print(&c);
				break;	
			case CHOICE10:
				Destroy(&c);
				printf("链表已销毁\n");
				exit(0);
        break;
			default:
				printf("输入有误，请重新输入：\n");
		}
    scanf("%*[^\n]%*c");
	}
	return 0;
}
