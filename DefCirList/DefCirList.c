#include "DefCirList.h"

//初始化链表
#define CListInit(c) \
{\
  (c)->_pHead = NULL;\
  (c)->_len = 0;\
}

//尾部插入元素
#define CListPushBack(c, data) \
  do{\
    pNode* pNewNode = (pNode*)malloc(sizeof(pNode));\
    strcpy(pNewNode->_data, data);\
    if(NULL == (c)->_pHead)\
    {\
      (c)->_pHead = pNewNode;\
      (c)->_pHead->_pNext = (c)->_pHead;\
      (c)->_pHead->_pPrev = (c)->_pHead;\
    }\
    else if((c)->_pHead == (c)->_pHead->_pNext)\
    {\
      (c)->_pHead->_pNext = pNewNode;\
      (c)->_pHead->_pPrev = pNewNode;\
      pNewNode->_pPrev = (c)->_pHead;\
      pNewNode->_pNext = (c)->_pHead;\
    }\
    else\
    {\
      (c)->_pHead->_pPrev->_pNext = pNewNode;\
      pNewNode->_pPrev = (c)->_pHead->_pPrev;\
      pNewNode->_pNext = (c)->_pHead;\
      (c)->_pHead->_pPrev = pNewNode;\
    }\
    (c)->_len++;\
  }while(0)

//尾部删除元素
#define CListPopBack(c) \
  do{\
    if(NULL == (c)->_pHead)\
    {\
      return -1;\
    }\
    else if((c)->_pHead == (c)->_pHead->_pNext)\
    {\
      free((c)->_pHead);\
      (c)->_pHead = NULL;\
    }\
    else\
    {\
      pNode* pCur = (c)->_pHead->_pPrev;\
      (c)->_pHead->_pPrev->_pPrev->_pNext = (c)->_pHead;\
      (c)->_pHead->_pPrev = (c)->_pHead->_pPrev->_pPrev;\
      free(pCur);\
    }\
    (c)->_len--;\
  }while(0)

//头部插入元素
#define CListPushFront(c, data) \
{\
  CListPushBack((c), (data));\
  (c)->_pHead = (c)->_pHead->_pPrev;\
}

//头部删除元素
#define CListPopFront(c) \
  do{\
    if(NULL == (c)->_pHead)\
    {\
      return -1;\
    }\
    (c)->_pHead = (c)->_pHead->_pNext;\
    CListPopBack(c);\
  }while(0)

//定位插入元素
#define CListInsert(c, pos, data) \
  do{\
    pNode* pNewNode = (pNode*)malloc(sizeof(pNode));\
    strcpy(pNewNode->_data, (data));\
    pNode* pCur = (c)->_pHead;\
    int count = 0;\
    if(0 == (pos))\
    {\
      CListPushFront((c), (data));\
    }\
    else if(0 < (pos))\
    {\
      while(count != (pos))\
      {\
        count++;\
        pCur = pCur->_pNext;\
      }\
      pNewNode->_pNext = pCur;\
      pCur->_pPrev->_pNext = pNewNode;\
      pNewNode->_pPrev = pCur->_pPrev;\
      pCur->_pPrev = pNewNode;\
      (c)->_len++;\
    }\
  }while(0)

//定位删除元素
#define CListErase(c, pos) \
  do{\
    if(NULL == (c)->_pHead)\
    {\
      return -1;\
    }\
    int count = (c)->_len-1;\
    if((pos) < 0 || (pos) > count)\
    {\
      return -1;\
    }\
    pNode* pCur = (c)->_pHead;\
    count = 0;\
    if(0 == pos)\
    {\
      CListPopFront(c);\
    }\
    else\
    {\
      while(count != (pos))\
      {\
        pCur = pCur->_pNext;\
        count++;\
      }\
      pCur->_pPrev->_pNext = pCur->_pNext;\
      pCur->_pNext->_pPrev = pCur->_pPrev;\
      free(pCur);\
      (c)->_len--;\
    }\
  }while(0)

//清空链表
#define CListClear(c) \
  do{\
    if(NULL == (c)->_pHead || (c)->_pHead == (c)->_pHead->_pNext)\
    {\
      (c)->_pHead = NULL;\
    }\
    else\
    {\
      (c)->_pHead->_pNext = NULL;\
      (c)->_pHead->_pPrev = NULL;\
      (c)->_pHead = NULL;\
    }\
    (c)->_len = 0;\
  }while(0)

//打印链表内元素个数
#define CListSize(c) printf("元素个数为：%d\n", (c)->_len)

//打印链表
#define Print(c) \
  do{\
    pNode* pCur = (c)->_pHead;\
    if(NULL == (c)->_pHead)\
    {\
      printf("NULL<--->NULL");\
    }\
    else if((c)->_pHead == (c)->_pHead->_pNext)\
    {\
      printf("%s<--->%s", (c)->_pHead->_data, (c)->_pHead->_data);\
    }\
    else\
    {\
      printf("%s<--->", (c)->_pHead->_data);\
      while(pCur->_pNext != (c)->_pHead)\
      {\
        pCur = pCur->_pNext;\
        printf("%s<--->", pCur->_data);\
      }\
      printf("%s", (c)->_pHead->_data);\
    }\
    printf("\n");\
  }while(0)

//销毁链表
#define CListDestroy(c) \
{\
  (c)->_pHead = NULL;\
}

int ret;//接收scanf的返回值

//菜单
#define Menu() \
{\
  printf("====================\n");\
  printf("1.头部增加结点\n");\
  printf("2.尾部增加结点\n");\
  printf("3.定位增加结点\n");\
  printf("4.头部删除结点\n");\
  printf("5.尾部删除结点\n");\
  printf("6.定位删除结点\n");\
  printf("7.清空链表\n");\
  printf("8.获取结点个数\n");\
  printf("9.打印链表\n");\
  printf("10.销毁链表\n");\
  printf("0.退出\n");\
  printf("====================\n");\
  printf("请输入：");\
}

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

int main()
{
  CList c;
  CListInit(&c);
  int choice = 0;
  while(1)
  {
    Menu();
    ret = scanf("%d", &choice);
    if((!((choice >= 0) && (choice <= 10) && (ret != 0))) || getchar() != '\n')
    {
      printf("输入有误，请重新输入：\n");
      scanf("%*[^\n]%*c");
      continue;
    }
    switch(choice)
    {
      case CHOICE0:
        printf("再见\n");
        exit(0);
        break;
      case CHOICE1:
        while(1)
        {
          printf("头部增加结点\n");
          char data1[1024];
          printf("请输入您要插入的值：");
          scanf("%[^\n]", data1);
          CListPushFront(&c, data1);
          printf("增加成功\n");
          break;
        }
        break;
      case CHOICE2:
        while(1)
        {
          printf("尾部增加结点\n");
          char data2[1024];
          printf("请输入您要插入的值：");
          scanf("%[^\n]", data2);
          CListPushBack(&c, data2);
          printf("增加成功\n");
          break;
        }
        break;
      case CHOICE3:
        while(1)
        {
          printf("定位增加结点\n");
          int pos1;
          char data3[1024];
          printf("请输入您要插入的位置：");
          ret = scanf("%d", &pos1);
          if((!((pos1 >= 0) && (pos1 <= (&c)->_len) && (ret != 0))) || getchar() != '\n')
          {
            printf("输入位置有误，请重新输入：\n");
            scanf("%*[^\n]%*c");
            continue;
          }
          setbuf(stdin, NULL);
          printf("请输入您要插入的值：");
          scanf("%[^\n]", data3);
          CListInsert(&c, pos1, data3);
          printf("增加成功\n");
          break;
        }
        break;
      case CHOICE4:
        printf("头部删除结点\n");
        if(NULL == (&c)->_pHead)
        {
          printf("无结点，删除失败\n");
          break;
        }
        CListPopFront(&c);
        printf("删除成功\n");
        break;
      case CHOICE5:
        printf("尾部删除结点\n");
        if(NULL == (&c)->_pHead)
        {
          printf("无结点，删除失败\n");
          break;
        }
        CListPopBack(&c);
        printf("删除成功\n");
        break;
      case CHOICE6:
        while(1)
        {
          printf("定位删除结点\n");
          if(NULL == (&c)->_pHead)
          {
            printf("无结点，删除失败\n");
            break;
          }
          int pos2;
          printf("请输入您要删除的位置：");
          ret = scanf("%d", &pos2);
          if(!(pos2 >= 0 && pos2 < (&c)->_len && ret != 0))
          {
            printf("输入位置有误，请重新输入：\n");
            scanf("%*[^\n]%*c");
            continue;
          }
          CListErase(&c, pos2);
          printf("删除成功\n");
          break;
        }
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
        CListDestroy(&c);
        printf("链表已销毁\n");
        exit(0);
      default:
        printf("输入有误，请重新输入：\n");
    }
  }
  return 0;
}
