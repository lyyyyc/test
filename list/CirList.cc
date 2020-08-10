#include <iostream>
#include <list>

using namespace std;

int Menu()
{
  cout<<"===================="<<endl;
  cout<<"1.头部增加结点"<<endl;
  cout<<"2.尾部增加结点"<<endl;
  cout<<"3.定位增加结点"<<endl; 
  cout<<"4.头部删除结点"<<endl;
  cout<<"5.尾部删除结点"<<endl;
  cout<<"6.定位删除结点"<<endl;
  cout<<"7.清空链表"<<endl;
  cout<<"8.获取结点个数"<<endl;
  cout<<"9.打印链表"<<endl;
  cout<<"10.销毁链表"<<endl;
  cout<<"0.退出"<<endl;
  cout<<"===================="<<endl;
  cout<<"请输入：";
  int choice;
  cin>>choice;
  return choice;
}

int main()
{
  list<char> CirList;
  while(1)
  {
    int choice = Menu();
    if (0 == choice)
    {
      cout<<"再见"<<endl;
      exit(0);
    }
    else if(1 == choice)
    {
      cout<<"头部增加结点"<<endl;
      cout<<"请输入您要插入的值：";
      char data[1024];
      cin >> data;
      CirList.push_front(*data);
      cout<<"增加成功"<<endl;
      continue;
    }
    else if(2 == choice)
    {
      cout<<"尾部增加结点"<<endl;
      cout<<"请输入您要插入的值：";
      char data[1024];
      cin >> data;
      CirList.push_back(*data);
      cout<<"增加成功"<<endl;
      continue;
    }
    else if(3 == choice)
    {
      cout<<"定位增加结点"<<endl;
      cout<<"请输入您要插入的位置和值：";
      int pos;
      char data[1024];
      cin >> pos >> data;
      //CirList.insert(pos, data);
      cout<<"增加成功"<<endl;
      continue;
    }
    else if(4 == choice)
    {
      cout<<"头部删除结点"<<endl;
      CirList.pop_front();
      cout<<"删除成功"<<endl;
      continue;
    }
    else if(5 == choice)
    {
      cout<<"尾部删除结点"<<endl;
      CirList.pop_back();
      cout<<"删除成功"<<endl;
      continue;
    }
    else if(6 == choice)
    {
      cout<<"定位删除结点"<<endl;
      int pos;
      cin >> pos;
      //CirList.erase(pos);
      cout<<"删除成功"<<endl;
      continue;
    }
    else if(7 == choice)
    {
      CirList.clear();
      cout<<"链表清空成功"<<endl;
      continue;
    }
    else if(8 == choice)
    {
      cout<<"结点个数="<<CirList.size()<<endl;
    }
    else if(9 == choice)
    {
      for(auto& it : CirList)                                                                                                                 
      {
         cout << it << "<--->";
      }
      cout<<CirList.front()<<endl;
      continue;
    }
    else if(10 == choice)
    {
      CirList.erase(CirList.begin(), CirList.end());
      cout<<"链表已销毁"<<endl;
      break;
    }
    else
    {
      cout<<"输入有误，请重新输入："<<endl;
      continue;
    }
  }
  return 0;
}
