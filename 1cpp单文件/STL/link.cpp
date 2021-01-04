#include <iostream>
using namespace std;
struct node					//������ṹ����
{
	char data;				//���ڴ���ַ�����
	node *next;				//����ָ����һ����㣨��̽�㣩
};
				// ��������������������
node * Create()
{
	node *head=NULL;		//��ͷָ�룬һ��ʼû���κν�㣬����ΪNULL
	node *pEnd=head;		//��βָ�룬һ��ʼû���κν�㣬����ָ���ͷ
	node *pS;				//�����½��ʱʹ�õ�ָ��
	char temp	;			//���ڴ�ŴӼ���������ַ�
	cout<<"�������ַ�������#��β��" <<endl;
	do						//ѭ����������һ��
	{
		cin>>temp;
		if (temp!='#')			//���������ַ�����#�������½��
		{
			pS=new node;		//�����½��
			pS->data=temp;		//�½�������Ϊtemp
			pS->next=NULL;		//�½�㽫��Ϊ��β������nextΪNULL
			if (head==NULL)	//�������û���κν�����
			{
				head=pS;		//���ͷָ��ָ������½��
			}
			else				//����
			{
				pEnd->next=pS;	//������½�������ڱ�β
			}
			pEnd=pS;			//����½���Ϊ���µı�β
		}
	}while (temp!='#');			//һ��������#��������ѭ��
	return head;				//���ر�ͷָ��
}
				//��������������������
void Showlist(node *head)
{
	node *pRead=head;			//����ָ��һ��ʼָ���ͷ
	cout<<"�����е�����Ϊ��" <<endl;
	while (pRead!=NULL)			//������ָ�����ʱ����û�дﵽ��β֮��
	{
		cout<<pRead->data;		//�����ǰ���ʽ�������
		pRead=pRead->next;		//����ָ������ƶ���ָ��ƫ�ƣ�
	}
	cout<<endl;
}
					//�����������ҡ�������
node * Search(node *head,char keyWord)	//���ؽ���ָ��
{
	node *pRead=head;
	while (pRead!=NULL)		//������������Ƶķ�����������ָ��û�е����β֮��
	{
		if (pRead->data==keyWord)	//�����ǰ�������ݺͲ��ҵ��������
		{
			return pRead;			//�򷵻ص�ǰ����ָ��
		}
		pRead=pRead->next;
							//���ݲ�ƥ�䣬pReadָ������ƶ���׼��������һ�����
	}
	return NULL;			//���еĽ�㶼��ƥ�䣬����NULL
}
				// �����������롭������
void Insert(node * &head,char keyWord,char newdata)
										//keyWord�ǲ��ҵ��ַ���ȷ�������λ�ã�
{
	node *newnode=new node;				//�½����
	newnode->data=newdata;				//newdata���½�������
	node *pGuard=Search(head,keyWord);	//pGuard�ǲ���λ��ǰ�Ľ��ָ��
	if (head==NULL || pGuard==NULL)		//�������û�н����Ҳ����ؼ��ֽ��
	{									//������ͷλ��
		newnode->next=head;				//����
		head=newnode;					//���
	}
	else								//����
	{									//������pGuard֮��
		newnode->next=pGuard->next;		//����
		pGuard->next=newnode;			//���
	}
}
				// ���������ڵ�ɾ����������
void Delete(node * &head,char keyWord)	//����Ҫ������ͷָ�룬����head������
{
	if (head!=NULL)						//�������û�н�㣬��ֱ�������ʾ
	{
		node *p;
		node *pGuard=head;					//��ʼ��pGuardָ��
		if (head->data==keyWord)			//���ͷ������ݷ��Ϲؼ���
		{
			p=head;							//ͷ����Ǵ�ɾ�����
			head=head->next;				//����
			delete p;						//���
			cout<<"��ɾ���Ľ����" <<keyWord<<endl;
			return;							//������������
		}
		else								//����
		{
			while (pGuard->next!=NULL)		//��pGuardû�дﵽ��β
			{
				if (pGuard->next->data==keyWord)
									//���pGuard��̽�����ݷ��Ϲؼ���
				{
					p=pGuard->next;			//pGuard��̽���Ǵ�ɾ�����
					pGuard->next=p->next;	//����
					delete p;				//���
					cout<<"��ɾ���Ľ����" <<keyWord<<endl;
					return;					//������������
				}
				pGuard=pGuard->next;		//pGuardָ������ƶ�
			}
		}
	}
	cout<<"The keyword node is not found or the link list is empty!" <<endl;
}
				// ������������ɾ����������
void Destroy(node * &head)
{
	node *p;
	while (head!=NULL)			//������ͷ������ʱ
	{
		p=head;					//ͷ����Ǵ�ɾ�����
		head=head->next;		//����
		delete p;				//���
	}
	cout<<"The link list has been deleted!" <<endl;
}
				//������������ת�б�����
void Reverse(node * &head)
{
	node * prev = NULL;		//ǰһ���ڵ�
	node * cp;				//��ǰ�����ڵ�
	while(head!=NULL)
	{
		cp=head;
		head=head->next;	//head����
		cp->next = prev;	
		//cp->next(�൱��head����ǰ��head->nex)ǰָ
		prev=cp;			//prev����
	}
	head = prev;
}
				// ����������������������
int main()					
{
	node *head=NULL;
	head=Create();
	Showlist(head);

	cout<<"��e��λ�ò���i��"<<endl;
	Insert(head,'e','i');
	Showlist(head);
	cout<<"���������m�Ľڵ㣺"<<endl;
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