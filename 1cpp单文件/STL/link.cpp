#include <iostream>
using namespace std;
struct node					//定义结点结构类型
{
	char data;				//用于存放字符数据
	node *next;				//用于指向下一个结点（后继结点）
};
				// …………创建…………
node * Create()
{
	node *head=NULL;		//表头指针，一开始没有任何结点，所以为NULL
	node *pEnd=head;		//表尾指针，一开始没有任何结点，所以指向表头
	node *pS;				//创建新结点时使用的指针
	char temp	;			//用于存放从键盘输入的字符
	cout<<"请输入字符串，以#结尾：" <<endl;
	do						//循环至少运行一次
	{
		cin>>temp;
		if (temp!='#')			//如果输入的字符不是#，则建立新结点
		{
			pS=new node;		//创建新结点
			pS->data=temp;		//新结点的数据为temp
			pS->next=NULL;		//新结点将成为表尾，所以next为NULL
			if (head==NULL)	//如果链表还没有任何结点存在
			{
				head=pS;		//则表头指针指向这个新结点
			}
			else				//否则
			{
				pEnd->next=pS;	//把这个新结点连接在表尾
			}
			pEnd=pS;			//这个新结点成为了新的表尾
		}
	}while (temp!='#');			//一旦输入了#，则跳出循环
	return head;				//返回表头指针
}
				//…………遍历…………
void Showlist(node *head)
{
	node *pRead=head;			//访问指针一开始指向表头
	cout<<"链表中的数据为：" <<endl;
	while (pRead!=NULL)			//当访问指针存在时（即没有达到表尾之后）
	{
		cout<<pRead->data;		//输出当前访问结点的数据
		pRead=pRead->next;		//访问指针向后移动（指针偏移）
	}
	cout<<endl;
}
					//…………查找…………
node * Search(node *head,char keyWord)	//返回结点的指针
{
	node *pRead=head;
	while (pRead!=NULL)		//采用与遍历类似的方法，当访问指针没有到达表尾之后
	{
		if (pRead->data==keyWord)	//如果当前结点的数据和查找的数据相符
		{
			return pRead;			//则返回当前结点的指针
		}
		pRead=pRead->next;
							//数据不匹配，pRead指针向后移动，准备查找下一个结点
	}
	return NULL;			//所有的结点都不匹配，返回NULL
}
				// …………插入…………
void Insert(node * &head,char keyWord,char newdata)
										//keyWord是查找的字符（确定插入的位置）
{
	node *newnode=new node;				//新建结点
	newnode->data=newdata;				//newdata是新结点的数据
	node *pGuard=Search(head,keyWord);	//pGuard是插入位置前的结点指针
	if (head==NULL || pGuard==NULL)		//如果链表没有结点或找不到关键字结点
	{									//则插入表头位置
		newnode->next=head;				//先连
		head=newnode;					//后断
	}
	else								//否则
	{									//插入在pGuard之后
		newnode->next=pGuard->next;		//先连
		pGuard->next=newnode;			//后断
	}
}
				// …………节点删除…………
void Delete(node * &head,char keyWord)	//可能要操作表头指针，所以head是引用
{
	if (head!=NULL)						//如果链表没有结点，就直接输出提示
	{
		node *p;
		node *pGuard=head;					//初始化pGuard指针
		if (head->data==keyWord)			//如果头结点数据符合关键字
		{
			p=head;							//头结点是待删除结点
			head=head->next;				//先连
			delete p;						//后断
			cout<<"被删除的结点是" <<keyWord<<endl;
			return;							//结束函数运行
		}
		else								//否则
		{
			while (pGuard->next!=NULL)		//当pGuard没有达到表尾
			{
				if (pGuard->next->data==keyWord)
									//如果pGuard后继结点数据符合关键字
				{
					p=pGuard->next;			//pGuard后继结点是待删除结点
					pGuard->next=p->next;	//先连
					delete p;				//后断
					cout<<"被删除的结点是" <<keyWord<<endl;
					return;					//结束函数运行
				}
				pGuard=pGuard->next;		//pGuard指针向后移动
			}
		}
	}
	cout<<"The keyword node is not found or the link list is empty!" <<endl;
}
				// …………链表删除…………
void Destroy(node * &head)
{
	node *p;
	while (head!=NULL)			//当还有头结点存在时
	{
		p=head;					//头结点是待删除结点
		head=head->next;		//先连
		delete p;				//后断
	}
	cout<<"The link list has been deleted!" <<endl;
}
				//……………倒转列表………
void Reverse(node * &head)
{
	node * prev = NULL;		//前一个节点
	node * cp;				//当前操作节点
	while(head!=NULL)
	{
		cp=head;
		head=head->next;	//head后移
		cp->next = prev;	
		//cp->next(相当于head后移前的head->nex)前指
		prev=cp;			//prev后移
	}
	head = prev;
}
				// …………主函数…………
int main()					
{
	node *head=NULL;
	head=Create();
	Showlist(head);

	cout<<"在e的位置插入i："<<endl;
	Insert(head,'e','i');
	Showlist(head);
	cout<<"插除内容是m的节点："<<endl;
	Delete(head,'e');
	Showlist(head);
	Reverse(head);
	Showlist(head);
	Destroy(head);
	Showlist(head);

	cin.get();
	cin.get();
	return 0;
}