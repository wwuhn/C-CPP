#include <iostream>

class CUser
{
private:
	char m_Username[128];
	char m_Password[128];

public:
	CUser()
	{
		strcpy(m_Username,"MR");
		strcpy(m_Password,"kj");
	}

	CUser(const char *pUsername,const char *pPassword)
	{
		if(pUsername !=NULL && pPassword != NULL)
		{
			strcpy(m_Username,pUsername);
			strcpy(m_Password,pPassword);
		}
	}

	char* GetUsername()const
	{
		return (char*)m_Username;
	}
	char* GetPassword()const;
};

char* CUser::GetPassword()const
{
    return (char*)m_Password;
}

int main()
{
	CUser user;
	printf("%s\n",user.GetUsername());
	CUser Customer("SK","songkun");
	printf("%s\n",Customer.GetUsername());
	
	system("pause");
	return 0;
}