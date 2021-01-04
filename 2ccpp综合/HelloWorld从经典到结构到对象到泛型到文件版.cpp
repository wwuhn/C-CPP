// https://github.com/d2school/bhcpp/tree/master/03-feelling-1
// ��������汾VC6�����е����⣬����C++14 OK ��https://www.onlinegdb.com/
// 18 cin�������ʱ�е����⣬����û������
/*
1 �����
2 ���İ�
3 ������֮�ظ�����
4 ������֮���κ���
5 ������
6 ��֧��
7 ��֧��֮���֧
8 ѭ����
9 �����֮���캯��
10 �����֮����������
11 �����֮��Ա����
12 �����֮����
13 �����֮��̬
14 �����֮��̬֮�˵�
15 �����֮��װ��������ʿ��ƣ�
16 STL������
17 ����ƪ
18 �����������Զ�������㷨
19 �Զ�������㷨������
20 ��׼������㷨
21 �ɼ�����ϵͳ2����׼�������㷨�� 1633
22 STL�ļ�ƪ 2228
*/

#if 0															// 1 �����
#include <iostream>
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
	system("pause");
    return 0;
}
#endif

//-----------------------------------------------------------------------------
#if 0															// 2 ���İ�
#include <iostream>
using namespace std;

int main()
{
	char str[] = "��ã����磡";	// �ڲ��������ֽڱ���һ������
    cout << str << endl;
	cout << sizeof(str);			// 13
	system("pause");
    return 0;
}
#endif

//-----------------------------------------------------------------------------
#if 0															// 3 ������֮�ظ�����
#include <iostream>
using namespace std;

void Hello()
{
    cout << "Hello world!" << endl;
}

int main()
{
    Hello();
    Hello();
	system("pause");
    return 0;
}
#endif

//-----------------------------------------------------------------------------
#if 0															// 4 ������֮���κ���
#include <iostream>
#include <string>
using namespace std;

void Hello(string const name)
{
    cout << "Hello! " << name << "." << endl;
}

int main()
{
    Hello("Xiao A");
    Hello("BOSS");
	system("pause");
    return 0;
}
#endif

//-----------------------------------------------------------------------------
#if 0																	// 5 ������
#include <iostream>
#include <string>
using namespace std;

void Hello(string const name)
{
    cout << "Hello! " << name << "." << endl;
}

int main()
{    
    string name;
    
    cout << "Please input the name: ";
    getline(cin, name);
    Hello(name);
    
    name = "BOSS";
    Hello(name);
	system("pause");
    return 0;
}
#endif

//-----------------------------------------------------------------------------
#if 0																// 6 ��֧��
#include <iostream>
#include <string>
using namespace std;

void Hello(string const name)
{
    if (name == "־��")
    {
        cout << "Hi! ־����á�����С�ǣ��úð��ء���" << endl;
    }
    else
    {
        cout << "Hello! " << name << "." << endl;
    }
}

int main()
{    
    string name;
    
    cout << "Please input the name: ";
    getline(cin, name);
	cin.ignore(32767,'\n'); //���Ե����ж�����ַ�
    Hello(name);
    
    cout << "Please input the name: ";
    getline(cin, name);
    Hello(name);
	system("pause");
    return 0;
}
/*
VC6��Ҫ���λس�
C:\Program Files\Microsoft Visual Studio\VC98\Include\string
_I.rdbuf()->snextc();//ע�͵���δ���
_I.rdbuf()->sbumpc();//�����δ���
*/
#endif

//-----------------------------------------------------------------------------
#if 0															// 7 ��֧��֮���֧
#include <iostream>
#include <string>
using namespace std;

void Hello(string const name)
{
    if (name == "־��")
    {
        cout << "Hi! ־�ᣬ־����á�����С�ǣ��úð��ء���" << endl;
    }
    else if (name == "����")
    {
        cout << "Hi! ���ᣬ������á���������ɣ�" << endl;
    }
    else
    {
        cout << "Hello! " << name << "." << endl;
    }
}

int main()
{
    string name;

    cout << "Please input the name: ";
    getline(cin, name);
	cin.ignore(32767,'\n'); //���Ե����ж�����ַ�
    Hello(name);

    cout << "Please input the name: ";
    getline(cin, name);
    Hello(name);
	system("pause");
    return 0;
}
#endif

//-----------------------------------------------------------------------------
#if 0																// 8 ѭ����
#include <iostream>
#include <string>
using namespace std;

void Hello(string const name)
{
    if (name == "־��")
    {
        cout << "Hi! ־����á�����С�ǣ��úð��ء���" << endl;
    }
    else
    {
        cout << "Hello! " << name << "." << endl;
    }
}

int main()
{
    string name;

    while (true) // while (2>1)
    {
        cout << "Please input the name: ";
        getline(cin, name);
        Hello(name);
    }
	system("pause");
    return 0;
}
#endif

//-----------------------------------------------------------------------------
#if 0															// 9 �����֮���캯��
#include <iostream>

using namespace std;

struct Object
{
    Object()
    {
        std::cout << "Hello world!" << endl;
    }
};

int main()
{
    Object o;
	system("pause");
    return 0;
}
#endif

//-----------------------------------------------------------------------------
#if 1														// 10 �����֮����������
#include <iostream>

using namespace std;

struct Object
{
    char* str;
    Object()
    {
        str = new char[13];
        strcpy(str,"Hello world!");
        std::cout << str << endl;
    }

    ~Object()
    {
        delete [] str;    // ������������Ҫ�������������ڴ�
        std::cout << "Bye-bye world!" << endl;
    }
};

int main()
{
	{Object o1;}
	{Object o2;}
	Object* o3 = new Object;
	delete o3;
	system("pause");
	return 0;
}
/*
Hello world!
Bye-bye world!
Hello world!
Bye-bye world!
Hello world!
Bye-bye world!
*/
#endif

//-----------------------------------------------------------------------------
#if 0														// 11 �����֮��Ա����
#include <iostream>
#include <string>

using namespace std;

struct Person
{
    Person()
    {
        cout << "Wa~Wa~" << endl;
    }

    ~Person()
    {
        cout << "Wu~Wu~" << endl;
    }

    void Introduce()
    {
        cout << "Hi, my name is " << name << "." << endl;
    }

    std::string name;
};

int main()
{{
    Person xiaoA;
    xiaoA.name = "Xiao A";

    Person *xiaoB = new Person;
    xiaoB->name = "Xiao B";

    xiaoA.Introduce();
    xiaoB->Introduce();

    delete xiaoB;
}
	system("pause");
    return 0;
}
/*
Wa~Wa~
Wa~Wa~
Hi, my name is Xiao A.
Hi, my name is Xiao B.
Wu~Wu~
Wu~Wu~
*/
#endif

//-----------------------------------------------------------------------------
#if 0															// 12 �����֮����
#include <iostream>
#include <string>

using namespace std;

struct Person
{
    Person()
    {
        cout << "Wa~Wa~" << endl;
    }

    ~Person()
    {
        cout << "Wu~Wu~" << endl;
    }

    void Introduction()
    {
        cout << "Hi, my name is " << name << "." << endl;
    }

    void Sing() // ��ͨ�ˣ�����һ�������Ա����
    {
        std::cout << "@ # $ % ^ &" << std::endl;
    }

    std::string name;
};

struct Beauty : public Person
{
    void Introduction()
    {
        cout << "��Һã�������Ů: " << name << "��������գ�" << endl;
    }
};

int main()
{
    Person xiaoA;
    xiaoA.name = "Xiao A";

    Beauty* zhiLing = new Beauty; //�ǵģ�־������ǴӴ˲���һ���ࡱ
    zhiLing->name = "־��";

    //�¼�һ����Ů������ջ����
    Beauty jiaLing;
    jiaLing.name = "����";

    xiaoA.Introduction();
    zhiLing->Introduction();
    jiaLing.Introduction();

    delete zhiLing;

    Beauty power;
    power.Sing(); //��Ů�ӻ��ࣨ���ࣩ�̳еĹ���
	system("pause");
    return 0;
}
/*
Wa~Wa~
Wa~Wa~
Wa~Wa~
Hi, my name is Xiao A.
��Һã�������Ů: ־�ᣬ������գ�
��Һã�������Ů: ���ᣬ������գ�
Wu~Wu~
Wa~Wa~
@ # $ % ^ &
*/
#endif

//-----------------------------------------------------------------------------
#if 0														// 13 �����֮��̬
#include <iostream>
#include <string>

using namespace std;

struct Person
{
    Person()
    {
        cout << "Wa~Wa~" << endl;
    }

    virtual ~Person() //���������������ࣩ
    {
        cout << "Wu~Wu~" << endl;
    }

    virtual void Introduction()  //�����е��麯��
    {
        cout << "Hi, my name is " << name << "." << endl;
    }

    std::string name;
};

struct Beauty : public Person
{
    ~Beauty() //override //�����������������ࣩ
    {
        cout << "wu~wu~��������ݡ��Ƴ�¶��������Ĳݣ������յĻ�����" << endl;
    }

    void Introduction() //override //������������ȷָ���ú����ڻ����о����麯�� (C++11)
    {
        cout << "��Һã�������Ů: " << name << "��������գ�" << endl;
    }
};

int main()
{
    Person* xiaoA = new Beauty; //СA��Ϊ Person����ʵΪ Beauty
    xiaoA->name = "Xiao A";

    xiaoA->Introduction();  //���ڣ�СA���ڿ����������磬�ң�Ҳ������Ů������
    delete xiaoA;

    Beauty* zhiLing = new Beauty; //־����ʵһ�£�ȫ��Beauty
    zhiLing->name = "־��";

    zhiLing->Introduction();
    delete zhiLing;
	system("pause");
    return 0;
}
/*
Wa~Wa~
��Һã�������Ů: Xiao A��������գ�
wu~wu~��������ݡ��Ƴ�¶��������Ĳݣ������յĻ�����
Wu~Wu~
Wa~Wa~
��Һã�������Ů: ־�ᣬ������գ�
wu~wu~��������ݡ��Ƴ�¶��������Ĳݣ������յĻ�����
Wu~Wu~
*/
#endif

//-----------------------------------------------------------------------------
#if 0														// 14 �����֮��̬֮�˵�
#include <iostream>
#include <string>

using namespace std;

struct Person
{
    Person()
    {
        cout << "Wa~Wa~" << endl;
    }

    virtual ~Person()
    {
        cout << "Wu~Wu~" << endl;
    }

    virtual void Introduction()
    {
        cout << "Hi, my name is " << name << "." << endl;
    }

    std::string name;
};

struct Beauty : public Person
{
    ~Beauty() //override
    {
        cout << "wu~wu~��������ݡ��Ƴ�¶��������Ĳݣ������յĻ�����" << endl;
    }

    void Introduction() //override
    {
        cout << "��Һã�������Ů: " << name << "��������գ�" << endl;
    }
};

int main()
{
    while(true)
    {
        Person *someone;

        cout << "��ѡ��(1/2/3)��" << endl
            << "1 ��ͨ��" << endl
            << "2 ����" << endl
            << "3 �˳�" << endl;

        int sel = 0;
        cin >> sel;

        if (cin.fail())
        {
            cin.clear();
        }

        cin.sync();    // ���������Ӧ������Դͬ����
                       // �������Ϳ��Զ�����֮ǰû�д�������ݡ�

        if (3 == sel)
        {
            break;
        }

        if (1 == sel)
        {
            someone = new Person;
        }
        else if (2 == sel)
        {
            someone = new Beauty;
        }
        else // �û�����ģ������ǣ���Ҳ���ǣ���Ҳ���ǣ�...
        {
            cout << "��������ɣ�������ѡ��" << endl;
            continue;
        }

        cout << "������������";

        string name;
        getline(cin, name);

        someone->name = name;

        cout << name << "�����ҽ��ܣ�" << endl;
        someone->Introduction();

        delete someone;
    }
	system("pause");
    return 0;
}
#endif

//-----------------------------------------------------------------------------
#if 0												// 15 �����֮��װ��������ʿ��ƣ�
#include <iostream>
#include <string>

using namespace std;

struct Person
{
public:
    Person()
    {
        cout << "Wa~Wa~" << endl;
        cout << "Ϊ������ۿ޵��ˣ�������ְɣ�";
        getline(cin, name);
    }

    virtual ~Person()
    {
        cout << "Wu~Wu~" << endl;
    }

    string GetName() const //�仯���������const
    {
        //name = "��������";  //û�취������ʱĪ�����޸������ˡ���
        return name;
    }

    virtual void Introduction()
    {
        cout << "Hi, my name is " << name << "." << endl;
    }
private:
    std::string name;
};

struct Beauty : public Person
{
    ~Beauty() //override
    {
        cout << "wu~wu~��������ݡ��Ƴ�¶��������Ĳݣ������յĻ�����" << endl;
    }

    void Introduction() //override
    {
        cout << "��Һã�������Ů: " << GetName() << "��������գ�" << endl;
    }
};

int main()
{
    while(true)
    {
        Person *someone;

        cout << "��ѡ��(1/2/3)��" << endl
            << "1 ��ͨ��" << endl
            << "2 ����" << endl
            << "3 �˳�" << endl;

        int sel = 0;
        cin >> sel;

        if (cin.fail())
        {
            cin.clear();
        }

        cin.sync();

        if (3 == sel)
        {
            break;
        }

        if (1 == sel)
        {
            someone = new Person;
        }
        else if (2 == sel)
        {
            someone = new Beauty;
        }
        else //�û�����ģ������ǣ���Ҳ���ǣ���Ҳ���ǣ�...
        {
            cout << "��������ɣ�������ѡ��" << endl;
            continue;
        }

        cout << someone->GetName() << "�����ҽ��ܣ�" << endl;
        someone->Introduction();

        delete someone;
    }
	system("pause");
    return 0;
}
#endif

//-----------------------------------------------------------------------------
#if 0															// 16 STL������
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Person
{
public:
    Person()
    {
        cout << "������������";
        getline(cin, name);
        
        cout << "���������䣺";
        cin >> age;
    }
    
    virtual ~Person()
    {
    }
    
    string GetName() const
    {
        return name;
    }
    
    int GetAge() const
    {
        return age;
    }
    
private:
    string name;
    int age;
};

struct Beauty : public Person
{
public:
    Beauty ()
    {
        cout << "�����������";
        cin.sync();
        getline(cin, nationality);
        
        cout << "��������Χ���ݣ��ء������Σ��������Կո�������س�ȷ�ϣ�";
        cin >> bust >> waist >> hips;
        
        cout << "���������ҽ������ݣ�";
        cin.sync();
        getline(cin, introduction);
    }
    
    string GetNationality() const
    {
        return nationality;
    }

    int GetBust() const
    {
        return bust;
    }
    
    int GetWaist() const
    {
        return waist;
    }
    
    int GetHips() const
    {
        return hips;
    }
        
    void Introduction() const
    {
        cout << introduction << endl;
    }
    
private:
    std::string nationality;  // ����
    
    int bust;   // ��Χ
    int waist;  // ��Χ
    int hips;   // ��Χ
    
    std::string introduction; // ���ҽ�������
};

//��Ů������
struct BeautiesManager
{
public:
    void Input();				// �����µ���Ů
    void Find() const;			// ������������Ů
    
    void Count() const			// ��ʾ��ǰ��Ů����
    {
        cout << "��ǰ��Ů������" << beauties.size() << endl;
    }
    
    void Introduction() const;	// ������Ů�������ҽ���
    void Clear();				// ��յ�ǰ������Ů
    
private:
    vector<Beauty> beauties;	// ����------------------------------------------
};

void BeautiesManager::Input()
{
    Beauty b;    
    beauties.push_back(b);
}

void BeautiesManager::Find() const
{
    cout << "������Ҫ���ҵ���Ů������";
    string name;
    
    getline(cin, name);
    
    int found = 0;
    
    for (unsigned int i=0; i<beauties.size(); ++i)
    {
        if (beauties[i].GetName() == name)
        {
            ++found;
            
            cout << "�ҵ���������Ů��������: " << i << endl;
            
            cout << "������" << beauties[i].GetName() << endl
                 << "���䣺" << beauties[i].GetAge() << endl
                 << "������" << beauties[i].GetNationality() << endl
                 << "��Χ��" << beauties[i].GetBust() << ", "
                 <<  beauties[i].GetWaist() << ", " << beauties[i].GetHips() << endl; 
        }
    }
    
    cout << "���ҵ���" << found << "λ��Ϊ��" << name << "����Ů��" << endl; 
}

void BeautiesManager::Introduction() const
{
    for (unsigned int i=0; i<beauties.size(); ++i)
    {
        cout << "���ڳ������ǣ�" << beauties[i].GetName() << endl;
        beauties[i].Introduction();
    }
}

void BeautiesManager::Clear()
{
    cout << "��ȷ��Ҫ���������Ů�����𣿸ò������ɻָ��� (y/n)��";
    
    char c;
    cin >> c;
    
    cin.sync();
    
    if (c == 'y')
    {
        beauties.clear();
        cout << "�����������" << endl;
    }
}

// ��ʾ���˵�:
int ShowMenu()
{
    cout << "��ѡ��" << endl;
    cout << "1 ��Ů��Ϣ¼��" << endl
         << "2 ��Ů��Ϣ����" << endl
         << "3 �����Ů����" << endl
         << "4 ��Ů�������ҽ���" << endl
         << "5 ���ȫ����Ů����" << endl
         << endl
         << "6 ���ڱ�����" << endl
         << "7 �˳�" << endl;
        
    int sel = 0;
    cin >> sel;
    cin.sync();
    
    return sel;
}

void About()
{
    cout <<  "���أأع�����Ů������Ϣ����ϵͳ Ver 1.0��" << endl
        << "���ߣ���С�� Copyright 2008~???" << endl;
}

int main()
{
    enum {sel_input = 1, sel_find, sel_count, sel_introduction, sel_clear, sel_about, sel_exit};
 
    cout << "XXX������Ů������ӭ����" << endl;
 
    BeautiesManager bm;
       
    while(true)
    {
        int sel = ShowMenu();
                
        if ( sel_input == sel)
        {
            bm.Input();
        }        
        else if (sel_find == sel)
        {
            bm.Find();
        }
        else if (sel_count == sel)
        {
            bm.Count();
        }
        else if (sel_introduction == sel)
        {
            bm.Introduction();
        }
        else if (sel_clear == sel)
        {
            bm.Clear();
        }
        else if (sel_about == sel)
        {
            About();
        }
        else if (sel_exit == sel)
        {
            break;
        }
        else				// ʲôҲ����?
        {
            if (cin.fail ())
            {
                cin.clear(); // ���cin��ǰ���ܴ��ڴ���״̬�������
                cin.sync();
            }
            
            cout << "ѡ����������ѡ��" << endl;
        }
    }
    system("pause");
    return 0;
}
#endif

//-----------------------------------------------------------------------------
#if 0																// ��������
#include <iostream>
#include <list> 

using namespace std;

int main()
{
    list<int> lst;

    lst.push_front(10);
    lst.push_front(20);

    lst.push_back(8);
    lst.push_back(9);

    lst.pop_front();
    lst.pop_back();
    
    lst.clear();
    
    lst.push_back(1);
    lst.push_back(2);
    
    int a = lst.front();
    cout << a << endl;

    int b = lst.back();
    cout << b << endl;

    int count = lst.size();
    cout << count << endl;

    cout << lst.empty() << endl;
    lst.clear();
    cout << lst.empty() << endl;

    lst.push_back(1);
    lst.push_back(2);
    list<int>::iterator  iter = lst.begin();
    a = *iter;
    cout << a << endl;
    *iter = 1000;
    cout << *iter << endl;
    cout << a << endl;
    b = *iter;
    cout << b << endl;
    
    /*
    lst<int>::iterator iter2 = lst.end();
    int a = *iter2; // ���ѷ���
    *iter2 = 100;	// ���ѷ���
    */
        
    lst.clear();
    lst.push_back(10);
    lst.push_back(100);
    iter = lst.begin();
    ++iter;					// iterǰ��1����ָ��ڶ���Ԫ��
    lst.insert(iter, 1);	// �ڵڶ���Ԫ�ص�λ���ϣ�������Ԫ��

    iter = lst.begin();
    ++iter;
    lst.erase(iter);

    list<int>::const_iterator  c_iter = lst.begin();  // ��ʱ���õ��ǳ�����
    a = *c_iter;		// ��ȷ
    cout << a << endl;
    //*c_iter = 1000;	// ����c_iter��ֻ������������������޸����󶨵�Ԫ��
    
    for (list<int>::const_iterator c_iter2 = lst.begin();
        c_iter2 != lst.end();
        ++c_iter2)
    {
        cout << *c_iter2 << endl;
    }
  /*  
    for (list<int>::const_reverse_iterator c_iter3 = lst.rbegin();
        c_iter3 != lst.rend();
        ++c_iter3)
    {
        cout << *c_iter3 << endl;
    }
*/
	system("pause");
    return 0;
}
#endif

//-----------------------------------------------------------------------------
#if 0																// 17 ����ƪ
#include <iostream>
#include <list> 
#include <vector>
#include <string>

using namespace std;

struct Student			// ѧ��
{
  unsigned int number;	// ѧ��
  string name;
};

struct Score			// �ɼ�
{
   unsigned int number; // ѧ��
   float mark;			// ����
};

struct StudentScoreManager // ѧ���ɼ�������
{
public:
    void InputStudents(); 
    void InputScores();
    void OutputScores() const;
    
private:
    vector<Student> students;
    list<Score> scores;
};

void StudentScoreManager::InputStudents()
{
    unsigned int number = 1; // ѧ�Ŵ�1��ʼ
    
    while(true)
    {
        cout << "������" << number << "��ѧ������(����x��ʾ����)��";     
        string name;   
        getline(cin, name);
        
        if (name == "x")
        {
            break;
        }
        
        Student student;
        student.number = number;
        student.name = name;
        
        students.push_back(student);    
        ++number;
    }
}

void StudentScoreManager::InputScores()
{
    while(true)
    {
        unsigned int number;
        
        cout << "������ѧ�ţ�����0��ʾ��������";
        
        cin >> number;
        
        if (number == 0)
        {
            break;
        }
               
        if (number > students.size()) // ���ж�ѧ���Ƿ���ȷ�� 
        {
            cout << "����ѧ�ű���λ��: 1 ~ " << students.size() << " ֮�䡣" << endl;
            continue; 
        }
        
        float mark;
        cout << "�������ѧԱ�ɼ���";
        cin >> mark;
        
        Score score;
        score.number = number;
        score.mark = mark;
        
        scores.push_back(score);
    }
}

void StudentScoreManager::OutputScores() const
{
    for (unsigned int i=0; i<students.size(); ++i)
    {
        unsigned int number = students[i].number; // ѧ��

        cout << "ѧ�ţ�" << number << endl;
        cout << "������" << students[i].name << endl;
                
        // ���ҳɼ�:
        bool found = false;
        
        for (list<Score>::const_iterator iter = scores.begin(); 
             iter != scores.end(); 
             ++iter)
        {
            if (iter->number == number)
            {
                found = true;	// �ҵ���
                
                cout << "�ɼ���" << iter->mark << endl;
                
                break;
            }
        }
        
        if (found == false)		// û�ҵ�??
        {
            cout << "�ɼ���" << "���޳ɼ���" << endl;
        }
    }
}

int main()
{
    StudentScoreManager ssm;
    
    ssm.InputStudents();
    ssm.InputScores();
    ssm.OutputScores();
    system("pause");
    return 0;
}
/*
������1��ѧ������(����x��ʾ����)��wwu
������2��ѧ������(����x��ʾ����)��fwu
������3��ѧ������(����x��ʾ����)��x
������ѧ�ţ�����0��ʾ��������1
�������ѧԱ�ɼ���11
������ѧ�ţ�����0��ʾ��������2
�������ѧԱ�ɼ���22
������ѧ�ţ�����0��ʾ��������0
ѧ�ţ�1
������wwu
�ɼ���11
ѧ�ţ�2
������fwu
�ɼ���22
*/
#endif

//-----------------------------------------------------------------------------
#if 0												// 18 �����������Զ�������㷨
// cin�������ʱ�е����⣬���߿������У�https://www.onlinegdb.com/
#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

struct Student			// ѧ��
{
  unsigned int number;	// ѧ��
  string name;
};

struct Score			// �ɼ�
{
   unsigned int number; // ѧ��
   float mark;			// ����
};

struct StudentScoreManager // ѧ���ɼ�������
{
public:
    void InputStudents();
    void InputScores();
    void OutputScores() const;

private:
    vector<Student> students;
    list<Score> scores;
};

void StudentScoreManager::InputStudents()
{
    unsigned int number = 1;  // ѧ�Ŵ�1��ʼ

    while(true)
    {
        cout << "������" << number << "��ѧ������(����x��ʾ����)��";

        string name;

        getline(cin, name);
		//cin.ignore(32767,'\n');
		//cin.clear(); //�˴���cin.clear()����־��λ
		//cin.sync();
        if (name == "x")
        {
            break;
        }

        Student student;
        student.number = number;
        student.name   = name;

        students.push_back(student);

        ++number;
    }
}

struct CompareByNumber_Equal
{
   unsigned int number; // ѧ��

   bool operator () (unsigned int current_number) const  //��������---------
   {
        return current_number == number;
   }
};

// �Զ�������㷨------------------------------------
list<Score>::iterator  find (list<Score> scores, CompareByNumber_Equal cmp)
{
   for (list<Score>::iterator iter = scores.begin();
        iter != scores.end();
        ++iter)
    {
        if (cmp(iter->number))
        {
            return iter;
        }
    }
    return scores.end();
}

void StudentScoreManager::InputScores()
{
    while(true)
    {
        unsigned int number;

        cout << "������ѧ�ţ�����0��ʾ��������";
        cin >> number;
        if (number == 0)
        {
            break;
        }

        // ���ж�ѧ���Ƿ���ȷ��
        if (number > students.size())
        {
            cout << "����ѧ�ű���λ��: 1 ~ " << students.size() << " ֮�䡣" << endl;
            continue;
        }

        float mark;
        cout << "�������ѧԱ�ɼ���";
        cin >> mark;
		//scanf("%f",&mark);
		//cin.ignore(32767,'\n');
		//cin.clear(); //�˴���cin.clear()����־��λ
		//cin.sync();
        Score score;
        score.number = number;
        score.mark   = mark;

        scores.push_back(score);
    }
}

void StudentScoreManager::OutputScores() const
{
    for (unsigned int i=0; i<students.size(); ++i)
    {
        unsigned int number = students[i].number; //ѧ��

        cout << "ѧ�ţ�" << number << endl;
        cout << "������" << students[i].name << endl;

        // ���ҳɼ�:
        CompareByNumber_Equal cmp;
        cmp.number = number;

        //list<Score>::const_iterator iter = find(scores.begin(), scores.end(), cmp);
		list<Score>::const_iterator iter = find(scores, cmp);
        if (iter != scores.end())
        {
            cout << "�ɼ���" << iter->mark << endl;
        }
        else // û�ҵ�
        {
             cout << "�ɼ���" << "���޳ɼ���" << endl;
        }
    }
}

int main()
{
    StudentScoreManager ssm;

    ssm.InputStudents();
    ssm.InputScores();
    ssm.OutputScores();
	system("pause");
    return 0;
}
/*
������1��ѧ������(����x��ʾ����)��wwu                                                                                   
������2��ѧ������(����x��ʾ����)��wwf                                                                                   
������3��ѧ������(����x��ʾ����)��x                                                                                     
������ѧ�ţ�����0��ʾ��������1                                                                                          
�������ѧԱ�ɼ���11                                                                                                    
������ѧ�ţ�����0��ʾ��������2                                                                                          
�������ѧԱ�ɼ���22                                                                                                    
������ѧ�ţ�����0��ʾ��������0                                                                                          
ѧ�ţ�1                                                                                                                 
������wwu                                                                                                               
�ɼ���11                                                                                                                
ѧ�ţ�2                                                                                                                 
������wwf                                                                                                               
�ɼ���22                                                                                                                
sh: 1: pause: not found   
*/
#endif

//-----------------------------------------------------------------------------
#if 0											     // 19 �Զ�������㷨������
#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

struct Student				// ѧ��
{
  unsigned int number;		// ѧ��
  string name;
};

struct Score				// �ɼ�
{
   unsigned int number;		// ѧ��
   float mark;				// ����
};

struct StudentScoreManager	// ѧ���ɼ�������
{
public:
    void InputStudents();
    void InputScores();
    void OutputScores() const;

private:
    vector<Student> students;
    list<Score> scores;
};

void StudentScoreManager::InputStudents()
{
    unsigned int number = 1;  // ѧ�Ŵ�1��ʼ

    while(true)
    {
        cout << "������" << number << "��ѧ������(����x��ʾ����)��";

        string name;

        getline(cin, name);

        if (name == "x")
        {
            break;
        }

        Student student;
        student.number = number;
        student.name = name;

        students.push_back(student);

        ++number;
    }
}

struct CompareByNumber_Equal
{
   unsigned int number;  // ѧ��

   bool operator () (unsigned int current_number) const
   {
        return current_number == number;
   }
};

//�� find ��������������������Բ�ͬ�������Լ���ͬ������Ԫ�أ�������������
template <typename T>
T find (T beg, T end, CompareByNumber_Equal cmp)
{
    for (T iter = beg; iter != end; ++iter)
    {
        if (cmp (iter->number))
        {
            return iter;
        }
    }

    return end;
}

void StudentScoreManager::InputScores()
{
    while(true)
    {
        unsigned int number;

        cout << "������ѧ�ţ�����0��ʾ��������";

        cin >> number;

        if (number == 0)
        {
            break;
        }

        // ���ж�ѧ���Ƿ���ȷ��
        if (number > students.size())
        {
            cout << "����ѧ�ű���λ��: 1 ~ " << students.size() << " ֮�䡣" << endl;
            continue;
        }

        float mark;
        cout << "�������ѧԱ�ɼ���";
        cin >> mark;

        Score score;
        score.number = number;
        score.mark = mark;

        scores.push_back(score);
    }
}

void StudentScoreManager::OutputScores() const
{
    for (unsigned int i=0; i<students.size(); ++i)
    {
        unsigned int number = students[i].number; //ѧ��

        cout << "ѧ�ţ�" << number << endl;
        cout << "������" << students[i].name << endl;

        // ���ҳɼ�:
        CompareByNumber_Equal cmp;
        cmp.number = number;

        list<Score>::const_iterator iter = find(scores.begin(), scores.end(), cmp);

        if (iter != scores.end())
        {
            cout << "�ɼ���" << iter->mark << endl;
        }
        else // û�ҵ�
        {
             cout << "�ɼ���" << "���޳ɼ���" << endl;
        }
    }
}

int main()
{
    StudentScoreManager ssm;

    ssm.InputStudents();
    ssm.InputScores();
    ssm.OutputScores();
	system("pause");
    return 0;
}
/*
������1��ѧ������(����x��ʾ����)��wwu
������2��ѧ������(����x��ʾ����)��wwf
������3��ѧ������(����x��ʾ����)��x
������ѧ�ţ�����0��ʾ��������1
�������ѧԱ�ɼ���11
������ѧ�ţ�����0��ʾ��������2
�������ѧԱ�ɼ���22
������ѧ�ţ�����0��ʾ��������0
ѧ�ţ�1
������wwu
�ɼ���11
ѧ�ţ�2
������wwf
�ɼ���22
*/
#endif

//-----------------------------------------------------------------------------
#if 0														// 20 ��׼������㷨
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Student
{
  unsigned int number;		// ѧ��
  string name;
};

struct Score				// �ɼ�
{
   unsigned int number;		// ѧ��
   float mark;				// ����
};

struct StudentScoreManager	// ѧ���ɼ�������
{
public:
    void InputStudents();
    void InputScores();
    void OutputScores() const;

private:
    vector<Student> students;
    list<Score> scores;
};

void StudentScoreManager::InputStudents()
{
    unsigned int number = 1;  // ѧ�Ŵ�1��ʼ

    while(true)
    {
        cout << "������" << number << "��ѧ������(����x��ʾ����)��";

        string name;

        getline(cin, name);

        if (name == "x")
        {
            break;
        }

        Student student;
        student.number = number;
        student.name = name;

        students.push_back(student);

        ++number;
    }
}

struct CompareByNumber_Equal
{
   unsigned int number;  // ѧ��

   bool operator () (Score const & current_score) const  // ��������
   {
       return (current_score.number == number);
   }
};

void StudentScoreManager::InputScores()
{
    while(true)
    {
        unsigned int number;

        cout << "������ѧ�ţ�����0��ʾ��������";

        cin >> number;

        if (number == 0)
        {
            break;
        }

        //���ж�ѧ���Ƿ���ȷ��
        if (number > students.size())
        {
            cout << "����ѧ�ű���λ��: 1 ~ " << students.size() << " ֮�䡣" << endl;
            continue;
        }

        float mark;
        cout << "�������ѧԱ�ɼ���";
        cin >> mark;

        Score score;
        score.number = number;
        score.mark = mark;

        scores.push_back(score);
    }
}

void StudentScoreManager::OutputScores() const
{
    for (unsigned int i=0; i<students.size(); ++i)
    {
        unsigned int number = students[i].number; //ѧ��

        cout << "ѧ�ţ�" << number << endl;
        cout << "������" << students[i].name << endl;

        // ���ҳɼ�:
        CompareByNumber_Equal cmp;
        cmp.number = number;
		// STL ���Һ���
        list<Score>::const_iterator iter = find_if(scores.begin(), scores.end(), cmp);

        if (iter != scores.end())
        {
            cout << "�ɼ���" << iter->mark << endl;
        }
        else // û�ҵ�
        {
             cout << "�ɼ���" << "���޳ɼ���" << endl;
        }
    }
}

int main()
{
    StudentScoreManager ssm;

    ssm.InputStudents();
    ssm.InputScores();
    ssm.OutputScores();
	system("pause");
    return 0;
}

#endif

//-----------------------------------------------------------------------------
#if 0											// 21 �ɼ�����ϵͳ2����׼�������㷨��
// scores.sort(cmp)�е����⣬����OK��https://www.onlinegdb.com/
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Student				 // ѧ��
{
  unsigned int number;		 // ѧ��
  string name;				 // ����
};

struct Score				// �ɼ�
{
   unsigned int number;		// ѧ��
   float mark;				// ����
};

struct StudentScoreManager	// ѧ���ɼ�������
{
public:
    void InputStudents();	// ¼��ѧ��������Ϣ��¼��ǰ�Զ����ԭ�����ݣ�
    void InputScores();		// ¼��ɼ���¼��ǰ�����ԭ�����ݣ�
    void ClearScores();		// ��ճɼ�����

    void OutputScoresByNumber() const;	// ��ѧ�Ŵ������ÿ��ѧ����Ϣ�������ɼ�
    void OutputScoresByMark() const;	// �Է������������ÿ���ɼ�������ѧ��������Ϣ

    void FindStudentByNumber() const;	// ͨ��ѧ�ţ�����ѧ������ʾ������ѧ�ţ��ɼ�
    void FindStudentByName() const;		// ͨ������������ѧ������ʾ������ѧ�ţ��ɼ�

private:
    // �ڲ����õĺ���:
    // ����һ��ѧ�ţ���scores�в��ң�����������
    void FindScoreByNumber(unsigned int number) const;

    vector<Student> students;
    list<Score> scores;
};

// ����Ƿ������������У����������״̬�������ء��桱.
bool CheckInputFail()
{
    if (cin.fail ())	// ��� cin�ǲ��ǳ����ˣ�
    {
        // ������...
        cin.clear();	// ���cin��ǰ���ܴ��ڴ���״̬
        cin.sync();		// �������ǰ����δ���������

        cout << "�������������´���" << endl;

        return true;
    }

    return false;
}

// ����ѧ���ɼ�
void StudentScoreManager::InputStudents()
{
    // ����Ƿ��Ѿ�������:
    if (students.empty() == false)
    {
        cout << "ȷ��Ҫ����¼��ѧ��������Ϣ��(y/n)";
        char c;
        cin >> c;

        if (c != 'y')
        {
            return;
        }

        cin.sync(); // �Ե��س���.
    }

    // ��Ϊ�����û�����¼�룬����������Ҫ���ԭ������
    students.clear();

    unsigned int number = 1; // ѧ�Ŵ�1��ʼ

    while(true)
    {
        cout << "������ѧ������(����x��ʾ����), " << number << "�ţ�";

        string name;

        getline(cin, name);

        if (name == "x")
        {
            break;
        }

        Student student;
        student.number = number;
        student.name = name;

        students.push_back(student);

        ++number;
    }
}

// �Ƚ������Ƚ������Ƿ����
// ������students�в���ָ��������ѧ��
struct CompareByName4Find
{
    bool operator () (Student student) const
    {
        return student.name == name;
    }

    // �����ҵ�����
    string name;
};

// �Ƚ������Ƚϳɼ��е�ѧ���Ƿ����
// ������ scores�в���ָ��ѧ�ŵĳɼ�
struct CompareByNumber_Equal4Find
{
    bool operator () (Score s) const
    {
        return (s.number == number);
    }

    unsigned int number;
};

// �ڲ����õĺ���:
// ����һ��ѧ�ţ���scores�в��ң�����������
void StudentScoreManager::FindScoreByNumber(unsigned int number) const
{
    CompareByNumber_Equal4Find cbne;
    cbne.number = number;

    list<Score>::const_iterator itScore = find_if(scores.begin(), scores.end(), cbne);

    if (itScore == scores.end())
    {
       // �Ҳ����ɼ���
       cout << "���ɼ������޳ɼ���";
    }
    else
    {
        // �鵽�ɼ��ˣ���ʾ��
        cout << "���ɼ���" << itScore->mark;
    }
}

// ͨ��ѧ�Ų鵽��ϸ��Ϣ
void StudentScoreManager::FindStudentByNumber() const
{
    cout << "������Ҫ���ҵ�ѧ�ţ�";

    unsigned int number;
    cin >> number;

    // �û�����������ַ�ʱ����ʱ��������
    if (CheckInputFail())
    {
        return;
    }

    // ����ǲ����ںϷ���Χ�ڵ�ѧ��:
    unsigned int maxNumber = students.size();

    if (number > maxNumber)
    {
        cout << "ѧ��ֻ������ 1~" << maxNumber << " ֮�䣡" << endl;
        return;
    }

    cout << "ѧ�ţ�" << number;
    cout << "��������" << students[number - 1].name;

    // �����飺��ѧ�Ų����:
    FindScoreByNumber(number);

    cout << endl;
}

// ͨ���������ҵ�ѧ��������Ϣ��Ȼ����ͨ��ѧ���ҵ�ѧ���ɼ���
// ����ʾ�鵽�Ľ��������ж��ͬ��ѧ������ȫ�������
void StudentScoreManager::FindStudentByName() const
{
    cout << "����������ҵ�ѧԱ������";

    string name;

    getline(cin, name);

    CompareByName4Find cmp;
    cmp.name = name;

    int foundCount = 0; // �Ѿ����ҵ��������ˣ�

    vector<Student>::const_iterator beg = students.begin(); // ���������

    while(true)
    {
        // ����ѧ����ע����ҷ�ΧΪ: beg ~ students.end()
        beg = find_if(beg, students.end(), cmp);

        if (beg == students.end())
        {
            break; // �Ҳ�������...����ѭ��
        }

        // �鵽��ѧ����...
        ++foundCount; // �ҵ���������1��

        // ��ʾѧ��������Ϣ��
        cout << "������" << name;
        cout << "��ѧ�ţ�" << beg->number;

        // �����飺��ѧ�Ų����:
        FindScoreByNumber(beg->number);

        cout << endl;

        // ��Ҫ����begǰ������һ��λ�ã�
        // ��˼�ǣ��´β���ʱ�����ӵ�ǰ�ҵ�����ѧ������һ��λ�ÿ�ʼ����
        beg++;
    }

    cout << "�ܹ��鵽" << foundCount << "λѧ������Ϊ��" << name << endl;
}

// ����ѧ�ŵĴ������ѧ���ɼ���û�гɼ���ѧԱ����ʾ�����޳ɼ���
void StudentScoreManager::OutputScoresByNumber() const
{
    for (unsigned int i=0; i<students.size(); ++i)
    {
        unsigned int number = students[i].number; // ѧ��

        cout << "ѧ�ţ�" << number;
        cout << "��������" << students[i].name;

        // ���ҳɼ�:
        CompareByNumber_Equal4Find cmp;
        cmp.number = number;

        list<Score>::const_iterator iter = find_if(scores.begin(), scores.end(), cmp);

        if (iter != scores.end())
        {
            cout << "���ɼ���" << iter->mark << endl;
        }
        else // û�ҵ�
        {
             cout << "���ɼ���" << "���޳ɼ���" << endl;
        }
    }
}

// �Ƚ������Ƚϳɼ��еķ����ߵ�
// ��InputScores()�У�¼��ɼ�֮�󣬻�����ʹ�ñ��Ƚ϶Գɼ���������
struct CompareByMarkBigger
{
    bool operator () (Score s1, Score s2) const
    {
        return (s1.mark > s2.mark);
    }
};

// ¼��ѧ���ɼ���¼����ɺ�������
void StudentScoreManager::InputScores()
{
    while(true)
    {
        unsigned int number;

        cout << "������ѧ�ţ�����0��ʾ��������";

        cin >> number;

        // ����û������ǲ��ǺϷ�������
        if (CheckInputFail())
        {
            continue;
        }

        if (number == 0)
        {
            break;
        }

        // �ж�ѧ�Ŵ�С�Ƿ��ںϷ��ķ�Χ�ڣ�
        if (number > students.size())
        {
            cout << "����ѧ�ű���λ��: 1 ~ " << students.size() << " ֮�䡣" << endl;
            continue;
        }

        float mark;
        cout << "������ɼ�(" << students[number-1].name << ")��"; // ����˴�������������ʾ
        cin >> mark;

        // ����û������ǲ��ǺϷ��ĸ�����
        if (CheckInputFail())
        {
            continue;
        }

        Score score;
        score.number = number;
        score.mark = mark;

        scores.push_back(score);
    }

    // �����������ܣ�¼��ɼ��������������ߵ�����
    // ��֤scores�е�Ԫ����Զ�������
    CompareByMarkBigger cmp;
    scores.sort(cmp); // c++14 OK ������------------------------------------------------
}

// ��ճɼ�
void StudentScoreManager::ClearScores()
{
    cout << "��ȷ��Ҫ���ȫ���ɼ����ݣ� (y/n)";

    char c;
    cin >> c;

    if (c == 'y')
    {
        scores.clear();
        cout << "�ɼ����������ϣ�" << endl;
    }

    cin.sync();
}

// �������ߵͣ����ÿ���ɼ�������ѧ��������û�вμӿ���ѧԱ�������ᱻ���
void StudentScoreManager::OutputScoresByMark() const
{
    // ��ÿ��¼��ɼ�֮�����Ƕ������sort����Ϊ���гɼ���������
    // ����scores�е����гɼ����Ѿ��ǰ��ߵͷ�������
    // �����ǣ�������ͬʱ���봦�����β��С��������

    int index = 1;		// ��ǰ����,������1��ʼ
    int count = 0;		// ��ͬ��������
    double last = -1.0; // ��һ�η������տ�ʼʱ����ʼ��Ϊһ�������ܵķ���

    for (list<Score>::const_iterator it = scores.begin();
        it != scores.end();
        ++it)
    {
        if (last != it->mark)	// �µķ�������
        {
            last = it->mark;
            index += count;
            count = 1;
        }
        else					// ����ԭ���ķ�����ͬ�֣�
        {
            ++count;
        }

        cout << "���Σ�" << index;
        cout << "��������" << students[it->number - 1].name; // ͨ��ѧ�ŵõ�����
        cout << "��ѧ�ţ�" << it->number;
        cout << "���ɼ���" << it->mark << endl;
    }
}

void About()
{
    system("cls");

    cout << "ѧ���ɼ�����ϵͳ Ver 2.0" << endl;
    cout << "copyright 2008~?" << endl;
    cout << "���ߣ���С��" << endl;
    cout << "���ԣ�www.d2school.com/�׻�C++" << endl;
}

void Help()
{
    system("cls");

    cout << "1 ¼��ѧ��������Ϣ��" << endl
        << "��ע�⣬����¼��ʱ��ԭ�����ݻ���գ�" << endl
        << endl;

    cout << "2 ¼��ɼ���" << endl
        << "��ע�⣬����ԭ�гɼ�������¼�룬�����Ҫ��ճɼ�����ʹ�ã���ճɼ���" << endl
        << endl;

    cout << "3 ��ճɼ���" << endl
        << "֮ǰ¼��ĳɼ�������������������ɻָ���" << endl
        << endl;

    cout << "4 ��ѧ�Ŵ�����ʾ�ɼ���" << endl
        << "��ѧ�Ŵ�С��������ɼ�������������δ�μӿ��Ի�¼��ɼ�ѧԱ������ʾ���޳ɼ���" << endl
        << endl;

    cout << "5 ������������ʾ�ɼ���" << endl
        << "�������Ӹߵ�������ɼ����������Σ�ѧ�ţ������ȡ�" << endl
        << "�Ҹ棺��˵��������ֹѧУ�����ɼ�������" << endl
        << endl;

    cout << "6 ��ѧ�Ų���ѧ����" << endl
        << "����ѧ�ţ����ҵ�ָ��ѧ����ѧ����Ϣ�������ɼ���" << endl
        << endl;

    cout << "7 ����������ѧ����" << endl
        << "�����������鵽�������ֵ�ѧ�������������Ϣ�������ɼ����������������������" << endl
        << endl;

    cout << "8 ���ڣ����ڱ������һЩ��Ϣ��" << endl << endl;
    cout << "9 ��������ʾ��������Ϣ��" << endl << endl;
    cout << "0 �˳�������0���˳�������" << endl << endl;
}

int Menu()
{
    cout << "-------------------------------" << endl;
    cout << "----ѧ���ɼ�����ϵͳ Ver2.0----" << endl;
    cout << "-------------------------------" << endl;

    cout << "��ѡ��(0~9)" << endl;

    cout << "1 ¼��ѧ��������Ϣ" << endl;
    cout << "2 ¼��ɼ�" << endl;
    cout << "3 ��ճɼ�" << endl;

    cout << endl;
    cout << "4 ��ѧ�Ŵ�����ʾ�ɼ�" << endl;
    cout << "5 ������������ʾ�ɼ�" << endl;

    cout << endl;
    cout << "6 ��ѧ�Ų���ѧ��" << endl;
    cout << "7 ����������ѧ��" << endl;

    cout << endl;
    cout << "8 ����" << endl;
    cout << "9 ����" << endl;

    cout << endl;
    cout << "0 �˳�" << endl;

    int sel;
    cin >> sel;

    if (CheckInputFail())
    {
        return -1;
    }

    cin.sync(); //�����������֮��� �س���

    return sel;
}

int main()
{
    StudentScoreManager ssm;

    while(true)
    {
        int sel = Menu();

        if (sel == 1)
        {
            ssm.InputStudents();
        }
        else if (sel == 2)
        {
            ssm.InputScores();
        }
        else if (sel == 3)
        {
            ssm.ClearScores();
        }
        else if (sel == 4)
        {
            ssm.OutputScoresByNumber();
        }
        else if (sel == 5)
        {
            ssm.OutputScoresByMark();
        }
        else if (sel == 6)
        {
            ssm.FindStudentByNumber();
        }
        else if (sel == 7)
        {
            ssm.FindStudentByName();
        }
        else if (sel == 8)
        {
            About();
        }
        else if (sel == 9)
        {
            Help();
        }
        else if (sel == 0)
        {
            break;
        }
        else // ʲôҲ����..
        {
            cout << "����ȷ����ѡ�񣺷�Χ�� 0 ~ 9 ֮�ڡ�" << endl;
        }

        system("Pause");
    }

    cout << "bye~bye~" << endl;

    return 0;
}
#endif

//-----------------------------------------------------------------------------
#if 0															// �ļ���д����
//getline(ifs, line);�е����⣬����OK��https://www.onlinegdb.com/
#include <iostream>
#include <fstream> // 'f' -> 'file'

using namespace std;

istream& skip_comma ( istream& str )
{
    char c = str.peek();

    if (c == ',')
    {
        return str.ignore();
    }

    return str;
}

int main()
{
    ofstream ofs;

    ofs.open("./hello_file_stream.txt");

    ofs << "Hello world!" << endl;
    ofs << "11,22,33" << endl << "44" << endl;
    ofs << "1 2" << endl;

    ofs.close();

    ifstream ifs;

    ifs.open("./hello_file_stream.txt");

    if (!ifs)
    {
        cout << "open file fail!" << endl;
    }
    else
    {
        string line;

        getline(ifs, line); // c++ 14 OK

        cout << line << endl;

        int n1,n2,n3,n4;

        ifs >> n1 >> skip_comma >> n2 >> skip_comma >> n3;
        cout << n1 << ", " << n2 << ", " << n3 << endl;
        ifs >> n4;
        cout << n4 << endl;

        n1 = n2 = -1;
        string spaces;
        //char c;
        ifs >> n1;

        ifs.unsetf(ios::skipws);
        ifs >> spaces;

        ifs.setf(ios::skipws);
        ifs >> n2;
        cout << n1 << "," << spaces << n2 << endl;
    }

    return 0;
}
#endif


//-----------------------------------------------------------------------------
#if 0																// 22 STL�ļ�ƪ
// ��������https://www.onlinegdb.com/
#include <iostream>
#include <list> 
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

struct Student				// ѧ��
{
  unsigned int number;		// ѧ��
  string name;				// ����
};

struct Score				// �ɼ�
{
   unsigned int number;		// ѧ��
   float mark;				// ����
};

struct StudentScoreManager	// ѧ���ɼ�������
{
public:
    void InputStudents();		// ¼��ѧ��������Ϣ��¼��ǰ�Զ����ԭ�����ݣ� 
    void SaveStudents() const;	// ����ѧ��������Ϣ���ļ�
    void LoadStudents();		// ���ļ��ж���ѧ��������Ϣ��
       
    void InputScores();			// ¼��ɼ���¼��ǰ�����ԭ�����ݣ�
    void ClearScores();			// ��ճɼ�����
    
    void OutputScoresByNumber() const;	// ��ѧ�Ŵ������ÿ��ѧ����Ϣ�������ɼ�
    void OutputScoresByMark() const;	// �Է������������ÿ���ɼ�������ѧ��������Ϣ
    
    void FindStudentByNumber() const;	// ͨ��ѧ�ţ�����ѧ������ʾ������ѧ�ţ��ɼ�
    void FindStudentByName() const;		// ͨ������������ѧ������ʾ������ѧ�ţ��ɼ�
    
private:
    //�� �����õĺ���:
    // ����һ��ѧ�ţ���scores�в��ң�����������
    void FindScoreByNumber(unsigned int number) const;

    vector<Student> students;
    list<Score> scores;
};

// ����Ƿ������������У����������״̬�������ء��桱.
bool CheckInputFail()
{
    if (cin.fail ()) // ��� cin�ǲ��ǳ����ˣ�
    {
        // ������...
        cin.clear(); // ���cin��ǰ���ܴ��ڴ���״̬
        cin.sync();	 // �������ǰ����δ���������
        
        cout << "�������������´���" << endl;
        
        return true;
    }
    
    return false;
}

// ����ѧ���ɼ�
void StudentScoreManager::InputStudents()
{
    // ����Ƿ��Ѿ�������:
    if (students.empty() == false)
    {
        cout << "ȷ��Ҫ����¼��ѧ��������Ϣ��(y/n)";
        char c;
        cin >> c;
        
        if (c != 'y')
        {
            return;
        }
        
        cin.sync(); // �Ե��س���.
    }
    
    // ��Ϊ�����û�����¼�룬����������Ҫ���ԭ������
    students.clear(); 
    
    unsigned int number = 1; // ѧ�Ŵ�1��ʼ
    
    while(true)
    {
        cout << "������ѧ������(����x��ʾ����), " << number << "�ţ�";
        
        string name;
        
        getline(cin, name);
        
        if (name == "x")
        {
            break;
        }
        
        Student student;
        student.number = number;
        student.name = name;
        
        students.push_back(student);
        
        ++number;
    }    
}

//����ѧ��������Ϣ���ض����ļ��У�--------------------------------------
void StudentScoreManager::SaveStudents() const
{
    ofstream ofs;
    ofs.open(".\\students_base_info.txt");
    
    if (!ofs)
    {
        cout << "�򿪳ɼ�����ļ�ʧ�ܣ�" << endl;
        return;
    }
    
    // ��������ѧԱ�����������ں���Ķ��ļ�����
    unsigned int count = students.size();
    ofs << count << endl;
    
    for (unsigned int i=0; i<count; ++i)
    {
        ofs << students[i].number << endl; 
        ofs << students[i].name << endl; 
    }
    
    ofs.close(); 
    
    cout << "������ϣ�������" << count << "λѧ��������Ϣ��" << endl;
}

// ���ض����ļ��У�����ѧ��������Ϣ��
void StudentScoreManager::LoadStudents() 
{
    ifstream ifs;
    ifs.open(".\\students_base_info.txt");
    
    if (!ifs)
    {
        cout << "�򿪳ɼ������ļ�ʧ�ܣ�" << endl;
        return;
    }
    
    students.clear();		// ���ԭ����ѧ������
    
    unsigned int count = 0;
    ifs >> count;			// �������

    for (unsigned int i=0; i<count; ++i)
    {
        Student stu; 
        
        ifs >> stu.number; 
        
        ifs.ignore();		// �������getline������ѧ��֮��Ļ��з�
        getline(ifs, stu.name);  // ��������
       
        students.push_back(stu); // ����
    }
    
    cout << "������ϣ������أ�" << count << "λѧ���Ļ�����Ϣ��" << endl;
}

// �Ƚ������Ƚ������Ƿ����
// ������students�в���ָ��������ѧ��
struct CompareByName4Find
{
    bool operator () (Student student) const
    {
        return student.name == name;
    }
    
    // �����ҵ�����
    string name;
};

// �Ƚ������Ƚϳɼ��е�ѧ���Ƿ����
// ������ scores�в���ָ��ѧ�ŵĳɼ�
struct CompareByNumber_Equal4Find
{
    bool operator () (Score s) const
    {
        return (s.number == number);
    }
    
    unsigned int number;
};

// �ڲ����õĺ���:
// ����һ��ѧ�ţ���scores�в��ң�����������
void StudentScoreManager::FindScoreByNumber(unsigned int number) const
{
    CompareByNumber_Equal4Find cbne;
    cbne.number = number;
    
    list<Score>::const_iterator itScore = find_if(scores.begin(), scores.end(), cbne);
    
    if (itScore == scores.end()) 
    {
       // �Ҳ����ɼ���
       cout << "���ɼ������޳ɼ���"; 
    }
    else
    {
        // �鵽�ɼ��ˣ���ʾ��
        cout << "���ɼ���" << itScore->mark;
    }
}

// ͨ��ѧ�Ų鵽��ϸ��Ϣ
void StudentScoreManager::FindStudentByNumber() const 
{
    cout << "������Ҫ���ҵ�ѧ�ţ�";
    
    unsigned int number;
    cin >> number;
    
    // �û�����������ַ�ʱ����ʱ��������
    if (CheckInputFail()) 
    {
        return;
    }
    
    // ����ǲ����ںϷ���Χ�ڵ�ѧ��:
    unsigned int maxNumber = students.size();
    
    if (number > maxNumber)
    {
        cout << "ѧ��ֻ������ 1~" << maxNumber << " ֮�䣡" << endl;
        return;
    }
    
    cout << "ѧ�ţ�" << number;
    cout << "��������" << students[number - 1].name;
    
    // �����飺��ѧ�Ų����:
    FindScoreByNumber(number);
    
    cout << endl;
}

// ͨ���������ҵ�ѧ��������Ϣ��Ȼ����ͨ��ѧ���ҵ�ѧ���ɼ���
// ����ʾ�鵽�Ľ��������ж��ͬ��ѧ������ȫ�������
void StudentScoreManager::FindStudentByName() const
{
    cout << "����������ҵ�ѧԱ������";
    
    string name;
    
    getline(cin, name);
    
    CompareByName4Find cmp;
    cmp.name = name;
    
    int foundCount = 0; // �Ѿ����ҵ��������ˣ�
    
    vector<Student>::const_iterator itStu = students.begin(); // ���������
    
    while(itStu != students.end())
    {
        // ����ѧ����ע����ҷ�ΧΪ: itStu ~ students.end()
        itStu = find_if(itStu, students.end(), cmp);
        
        if (itStu == students.end())
        {
            break; // �Ҳ�������...����ѭ��
        }
        
        // �鵽��ѧ����...
        ++foundCount; // �ҵ���������1��
        
        //��ʾѧ��������Ϣ��
        cout << "������" << name;
        cout << "��ѧ�ţ�" << itStu->number;
        
        // �����飺��ѧ�Ų����:
        FindScoreByNumber(itStu->number);

        cout << endl;
       
        // ��Ҫ����itStuǰ������һ��λ�ã�
        // ��˼�ǣ��´β���ʱ�����ӵ�ǰ�ҵ�����ѧ������һ��λ�ÿ�ʼ����
        itStu++;
    }
    
    cout << "�ܹ��鵽" << foundCount << "λѧ������Ϊ��" << name << endl;
}

// ����ѧ�ŵĴ������ѧ���ɼ���û�гɼ���ѧԱ����ʾ�����޳ɼ���
void StudentScoreManager::OutputScoresByNumber() const
{
    for (unsigned int i=0; i<students.size(); ++i)
    {
        unsigned int number = students[i].number; //ѧ��

        cout << "ѧ�ţ�" << number;
        cout << "��������" << students[i].name;
                
        // ���ҳɼ�:
        CompareByNumber_Equal4Find cmp;
        cmp.number = number;
  
        list<Score>::const_iterator iter = find_if(scores.begin(), scores.end(), cmp);
        
        if (iter != scores.end())
        {
            cout << "���ɼ���" << iter->mark << endl;
        }
        else // û�ҵ�
        {
             cout << "���ɼ���" << "���޳ɼ���" << endl;
        }
    }    
}

// �Ƚ������Ƚϳɼ��еķ����ߵ�
// ��InputScores()�У�¼��ɼ�֮�󣬻�����ʹ�ñ��Ƚ϶Գɼ���������
struct CompareByMarkBigger
{
    bool operator () (Score s1, Score s2) const
    {
        return (s1.mark > s2.mark);
    }
};

// ¼��ѧ���ɼ���¼����ɺ�������
void StudentScoreManager::InputScores()
{
    while(true)
    {
        unsigned int number;
        
        cout << "������ѧ�ţ�����0��ʾ��������";
        
        cin >> number;
        
        // ����û������ǲ��ǺϷ�������
        if (CheckInputFail())
        {
            continue;
        }
        
        if (number == 0)
        {
            break;
        }
        
        // �ж�ѧ�Ŵ�С�Ƿ��ںϷ��ķ�Χ�ڣ�        
        if (number > students.size())
        {
            cout << "����ѧ�ű���λ��: 1 ~ " << students.size() << " ֮�䡣" << endl;
            continue; 
        }
        
        float mark;
        cout << "������ɼ�(" << students[number-1].name << ")��"; // ����˴�������������ʾ
        cin >> mark;
        
        // ����û������ǲ��ǺϷ��ĸ�����
        if (CheckInputFail())
        {
            continue;
        }

        Score score;
        score.number = number;
        score.mark = mark;
        
        scores.push_back(score);
    }
    
    // �����������ܣ�¼��ɼ��������������ߵ�����
    // ��֤scores�е�Ԫ����Զ�������
    CompareByMarkBigger cmp;
    scores.sort(cmp);    
}

// ��ճɼ�
void StudentScoreManager::ClearScores()
{
    cout << "��ȷ��Ҫ���ȫ���ɼ����ݣ� (y/n)";
    
    char c;
    cin >> c;
    
    if (c == 'y')
    {
        scores.clear();
        cout << "�ɼ����������ϣ�" << endl;
    }
    
    cin.sync();
}

// �������ߵͣ����ÿ���ɼ�������ѧ��������û�вμӿ���ѧԱ�������ᱻ���
void StudentScoreManager::OutputScoresByMark() const
{
    // ��ÿ��¼��ɼ�֮�����Ƕ������sort����Ϊ���гɼ���������
    // ����scores�е����гɼ����Ѿ��ǰ��ߵͷ�������
    // �����ǣ�������ͬʱ���봦�����β��С��������
    
    int currentIndex = 1; //��ǰ����,������1��ʼ
    int sameMarkCount = 0; //��ͬ��������
    double lastMark= -1; //��һ�η������տ�ʼʱ����ʼ��Ϊһ�������ܵķ���
    
    for (list<Score>::const_iterator it = scores.begin();
        it != scores.end();
        ++it)
    {
        if (lastMark != it->mark)
        {
            lastMark = it->mark;
            currentIndex += sameMarkCount;
            sameMarkCount = 1;
        }
        else // ������ͬ
        {
            ++sameMarkCount; 
        }
        
        cout << "���Σ�" << currentIndex;
        cout << "��������" << students[it->number - 1].name; // ͨ��ѧ�ŵõ�����
        cout << "��ѧ�ţ�" << it->number;
        cout << "���ɼ���" << it->mark << endl;        
    }
}

void About()
{
    system("cls");
    
    cout << "ѧ���ɼ�����ϵͳ Ver 3.0" << endl;
    cout << "copyright 2008~?" << endl;
    cout << "���ߣ���С��" << endl;
    cout << "���ԣ�www.d2school.com/�׻�C++" << endl; 
}

void Help()
{
    system("cls");
    
    cout << "1 ¼��ѧ��������Ϣ��" << endl 
        << "��ע�⣬����¼��ʱ��ԭ�����ݻ���գ�" << endl 
        << endl;
    
    cout << "2 ¼��ɼ���" << endl 
        << "��ע�⣬����ԭ�гɼ�������¼�룬�����Ҫ��ճɼ�����ʹ�ã���ճɼ���" << endl 
        << endl; 
        
    cout << "3 ��ճɼ���" << endl 
        << "֮ǰ¼��ĳɼ�������������������ɻָ���" << endl 
        << endl;
    
    cout << "4 ��ѧ�Ŵ�����ʾ�ɼ���" << endl 
        << "��ѧ�Ŵ�С��������ɼ�������������δ�μӿ��Ի�¼��ɼ�ѧԱ������ʾ���޳ɼ���" << endl 
        << endl;

    cout << "5 ������������ʾ�ɼ���" << endl 
        << "�������Ӹߵ�������ɼ����������Σ�ѧ�ţ������ȡ�" << endl
        << "�Ҹ棺��������ֹѧУ�����ɼ�������" << endl
        << endl;
        
    cout << "6 ��ѧ�Ų���ѧ����" << endl 
        << "����ѧ�ţ����ҵ�ָ��ѧ����ѧ����Ϣ�������ɼ���" << endl 
        << endl;
        
    cout << "7 ����������ѧ����" << endl 
        << "�����������鵽�������ֵ�ѧ�������������Ϣ�������ɼ����������������������" << endl 
        << endl;
        
    cout << "8 ����ѧ��������Ϣ��" << endl
        << "�����������ѧ��������Ϣ����Ӹ��ļ�����ѧ��������Ϣ��ע�⣺��ǰ���е�ѧ����Ϣ����ʧ��"
        << endl << endl;
        
    cout << "9 ����ѧ��������Ϣ��" << endl 
        << "���浱ǰѧ��������Ϣ���ļ�������Ѿ�ԭ���ļ�����ԭ���ļ����ݽ���ˢ�£�" 
        << endl << endl;
    
    cout << "10 ���ڣ����ڱ������һЩ��Ϣ��" << endl << endl;
    cout << "11 ��������ʾ��������Ϣ��" << endl << endl;

    cout << "0 �˳�������0���˳�������" << endl << endl;
}

int Menu()
{
    cout << "-------------------------------" << endl;
    cout << "----ѧ���ɼ�����ϵͳ Ver3.0----" << endl;
    cout << "-------------------------------" << endl;
    
    cout << "��ѡ��(0~9)" << endl;
    
    cout << "1 ¼��ѧ��������Ϣ" << endl;
    cout << "2 ¼��ɼ�" << endl;
    cout << "3 ��ճɼ�" << endl;

    cout << endl;
    cout << "4 ��ѧ�Ŵ�����ʾ�ɼ�" << endl;
    cout << "5 ������������ʾ�ɼ�" << endl;
    
    cout << endl;
    cout << "6 ��ѧ�Ų���ѧ��" << endl;
    cout << "7 ����������ѧ��" << endl;

    cout << endl;
    cout << "8 ����ѧ��������Ϣ" << endl;
    cout << "9 ����ѧ�������ļ�" << endl;
    
    cout << endl;
    cout << "10 ����" << endl;
    cout << "11 ����" << endl;
    
    cout << endl;
    cout << "0 �˳�" << endl;
    
    int sel;
    cin >> sel;
        
    if (CheckInputFail())
    {
        return -1;
    }
    
    cin.sync(); // �����������֮��� �س���

    return sel;
}

int main()
{
    StudentScoreManager ssm;

    while(true)
    {
        int sel = Menu();
                
        if (sel == 1)
        {
            ssm.InputStudents();
        }
        else if (sel == 2)
        {
            ssm.InputScores();
        }
        else if (sel == 3)
        {
            ssm.ClearScores();
        }
        else if (sel == 4)
        {
            ssm.OutputScoresByNumber();
        }
        else if (sel == 5)
        {
            ssm.OutputScoresByMark();
        }
        else if (sel == 6)
        {
            ssm.FindStudentByNumber();
        }
        else if (sel == 7)
        {
            ssm.FindStudentByName();
        }
        else if (sel == 8)
        {
            ssm.LoadStudents();
        }
        else if (sel == 9)
        {
            ssm.SaveStudents();
        }
        else if (sel == 10)
        {
            About();
        }
        else if (sel == 11)
        {
            Help();
        }
        else if (sel == 0)
        {
            break;
        }
        else // ʲôҲ����..
        {
            cout << "����ȷ����ѡ�񣺷�Χ�� 0 ~ 11 ֮�ڡ�" << endl; 
        }
        
        system("Pause"); 
    }
    
    cout << "bye~bye~" << endl;
    
    return 0;
}
#endif

// https://www.onlinegdb.com/

