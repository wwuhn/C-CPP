// https://github.com/d2school/bhcpp/tree/master/03-feelling-1
// 最后两个版本VC6运行有点问题，在线C++14 OK ：https://www.onlinegdb.com/
// 18 cin输入分数时有点问题，在线没有问题
/*
1 经典版
2 中文版
3 函数版之重复调用
4 函数版之带参函数
5 交互版
6 分支版
7 分支版之多分支
8 循环版
9 对象版之构造函数
10 对象版之构造与析构
11 对象版之成员函数
12 对象版之派生
13 对象版之多态
14 对象版之多态之菜单
15 对象版之封装（类与访问控制）
16 STL向量版
17 链表篇
18 函数对象与自定义查找算法
19 自定义查找算法及泛化
20 标准库查找算法
21 成绩管理系统2（标准库排序算法） 1633
22 STL文件篇 2228
*/

#if 0															// 1 经典版
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
#if 0															// 2 中文版
#include <iostream>
using namespace std;

int main()
{
	char str[] = "你好，世界！";	// 内部用两个字节编码一个汉字
    cout << str << endl;
	cout << sizeof(str);			// 13
	system("pause");
    return 0;
}
#endif

//-----------------------------------------------------------------------------
#if 0															// 3 函数版之重复调用
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
#if 0															// 4 函数版之带参函数
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
#if 0																	// 5 交互版
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
#if 0																// 6 分支版
#include <iostream>
#include <string>
using namespace std;

void Hello(string const name)
{
    if (name == "志玲")
    {
        cout << "Hi! 志玲你好。你演小乔，好好棒呢～～" << endl;
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
	cin.ignore(32767,'\n'); //忽略掉流中多余的字符
    Hello(name);
    
    cout << "Please input the name: ";
    getline(cin, name);
    Hello(name);
	system("pause");
    return 0;
}
/*
VC6需要两次回车
C:\Program Files\Microsoft Visual Studio\VC98\Include\string
_I.rdbuf()->snextc();//注释掉这段代码
_I.rdbuf()->sbumpc();//添加这段代码
*/
#endif

//-----------------------------------------------------------------------------
#if 0															// 7 分支版之多分支
#include <iostream>
#include <string>
using namespace std;

void Hello(string const name)
{
    if (name == "志玲")
    {
        cout << "Hi! 志玲，志玲你好。你演小乔，好好棒呢～～" << endl;
    }
    else if (name == "嘉玲")
    {
        cout << "Hi! 嘉玲，嘉玲你好。不丹好玩吧！" << endl;
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
	cin.ignore(32767,'\n'); //忽略掉流中多余的字符
    Hello(name);

    cout << "Please input the name: ";
    getline(cin, name);
    Hello(name);
	system("pause");
    return 0;
}
#endif

//-----------------------------------------------------------------------------
#if 0																// 8 循环版
#include <iostream>
#include <string>
using namespace std;

void Hello(string const name)
{
    if (name == "志玲")
    {
        cout << "Hi! 志玲你好。你演小乔，好好棒呢～～" << endl;
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
#if 0															// 9 对象版之构造函数
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
#if 1														// 10 对象版之构造与析构
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
        delete [] str;    // 析构函数的主要任务是析构堆内存
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
#if 0														// 11 对象版之成员函数
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
#if 0															// 12 对象版之派生
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

    void Sing() // 普通人，增加一个唱歌成员函数
    {
        std::cout << "@ # $ % ^ &" << std::endl;
    }

    std::string name;
};

struct Beauty : public Person
{
    void Introduction()
    {
        cout << "大家好，我是美女: " << name << "，请多多关照！" << endl;
    }
};

int main()
{
    Person xiaoA;
    xiaoA.name = "Xiao A";

    Beauty* zhiLing = new Beauty; //是的，志玲跟我们从此不是一“类”
    zhiLing->name = "志玲";

    //新加一个美女，改用栈变量
    Beauty jiaLing;
    jiaLing.name = "嘉玲";

    xiaoA.Introduction();
    zhiLing->Introduction();
    jiaLing.Introduction();

    delete zhiLing;

    Beauty power;
    power.Sing(); //美女从基类（人类）继承的功能
	system("pause");
    return 0;
}
/*
Wa~Wa~
Wa~Wa~
Wa~Wa~
Hi, my name is Xiao A.
大家好，我是美女: 志玲，请多多关照！
大家好，我是美女: 嘉玲，请多多关照！
Wu~Wu~
Wa~Wa~
@ # $ % ^ &
*/
#endif

//-----------------------------------------------------------------------------
#if 0														// 13 对象版之多态
#include <iostream>
#include <string>

using namespace std;

struct Person
{
    Person()
    {
        cout << "Wa~Wa~" << endl;
    }

    virtual ~Person() //虚析构函数（基类）
    {
        cout << "Wu~Wu~" << endl;
    }

    virtual void Introduction()  //基类中的虚函数
    {
        cout << "Hi, my name is " << name << "." << endl;
    }

    std::string name;
};

struct Beauty : public Person
{
    ~Beauty() //override //虚析构函数（派生类）
    {
        cout << "wu~wu~人生似蚍蜉、似朝露；似秋天的草，似夏日的花……" << endl;
    }

    void Introduction() //override //在派生类中明确指明该函数在基类中就是虚函数 (C++11)
    {
        cout << "大家好，我是美女: " << name << "，请多多关照！" << endl;
    }
};

int main()
{
    Person* xiaoA = new Beauty; //小A名为 Person，但实为 Beauty
    xiaoA->name = "Xiao A";

    xiaoA->Introduction();  //现在，小A终于可以宣告世界，我（也）是美女！！！
    delete xiaoA;

    Beauty* zhiLing = new Beauty; //志玲名实一致，全是Beauty
    zhiLing->name = "志玲";

    zhiLing->Introduction();
    delete zhiLing;
	system("pause");
    return 0;
}
/*
Wa~Wa~
大家好，我是美女: Xiao A，请多多关照！
wu~wu~人生似蚍蜉、似朝露；似秋天的草，似夏日的花……
Wu~Wu~
Wa~Wa~
大家好，我是美女: 志玲，请多多关照！
wu~wu~人生似蚍蜉、似朝露；似秋天的草，似夏日的花……
Wu~Wu~
*/
#endif

//-----------------------------------------------------------------------------
#if 0														// 14 对象版之多态之菜单
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
        cout << "wu~wu~人生似蚍蜉、似朝露；似秋天的草，似夏日的花……" << endl;
    }

    void Introduction() //override
    {
        cout << "大家好，我是美女: " << name << "，请多多关照！" << endl;
    }
};

int main()
{
    while(true)
    {
        Person *someone;

        cout << "请选择(1/2/3)：" << endl
            << "1 普通人" << endl
            << "2 美人" << endl
            << "3 退出" << endl;

        int sel = 0;
        cin >> sel;

        if (cin.fail())
        {
            cin.clear();
        }

        cin.sync();    // 让流与其对应的数据源同步，
                       // 这样流就可以丢弃掉之前没有处理的数据。

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
        else // 用户输入的，即不是１，也不是２，也不是３...
        {
            cout << "输入有误吧？请重新选择。" << endl;
            continue;
        }

        cout << "请输入姓名：";

        string name;
        getline(cin, name);

        someone->name = name;

        cout << name << "的自我介绍：" << endl;
        someone->Introduction();

        delete someone;
    }
	system("pause");
    return 0;
}
#endif

//-----------------------------------------------------------------------------
#if 0												// 15 对象版之封装（类与访问控制）
#include <iostream>
#include <string>

using namespace std;

struct Person
{
public:
    Person()
    {
        cout << "Wa~Wa~" << endl;
        cout << "为这个哇哇哭的人，起个名字吧：";
        getline(cin, name);
    }

    virtual ~Person()
    {
        cout << "Wu~Wu~" << endl;
    }

    string GetName() const //变化在这里，加了const
    {
        //name = "王二麻子";  //没办法在问名时莫明地修改名字了……
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
        cout << "wu~wu~人生似蚍蜉、似朝露；似秋天的草，似夏日的花……" << endl;
    }

    void Introduction() //override
    {
        cout << "大家好，我是美女: " << GetName() << "，请多多关照！" << endl;
    }
};

int main()
{
    while(true)
    {
        Person *someone;

        cout << "请选择(1/2/3)：" << endl
            << "1 普通人" << endl
            << "2 美人" << endl
            << "3 退出" << endl;

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
        else //用户输入的，即不是１，也不是２，也不是３...
        {
            cout << "输入有误吧？请重新选择。" << endl;
            continue;
        }

        cout << someone->GetName() << "的自我介绍：" << endl;
        someone->Introduction();

        delete someone;
    }
	system("pause");
    return 0;
}
#endif

//-----------------------------------------------------------------------------
#if 0															// 16 STL向量版
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Person
{
public:
    Person()
    {
        cout << "请输入姓名：";
        getline(cin, name);
        
        cout << "请输入年龄：";
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
        cout << "请输入国籍：";
        cin.sync();
        getline(cin, nationality);
        
        cout << "请输入三围数据（胸、腰、臀），数据以空格隔开，回车确认：";
        cin >> bust >> waist >> hips;
        
        cout << "请输入自我介绍内容：";
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
    std::string nationality;  // 国籍
    
    int bust;   // 胸围
    int waist;  // 腰围
    int hips;   // 臀围
    
    std::string introduction; // 自我介绍内容
};

//美女管理类
struct BeautiesManager
{
public:
    void Input();				// 输入新的美女
    void Find() const;			// 按姓名查找美女
    
    void Count() const			// 显示当前美女总数
    {
        cout << "当前美女个数：" << beauties.size() << endl;
    }
    
    void Introduction() const;	// 所有美女依次自我介绍
    void Clear();				// 清空当前所有美女
    
private:
    vector<Beauty> beauties;	// 向量------------------------------------------
};

void BeautiesManager::Input()
{
    Beauty b;    
    beauties.push_back(b);
}

void BeautiesManager::Find() const
{
    cout << "请输入要查找的美女姓名：";
    string name;
    
    getline(cin, name);
    
    int found = 0;
    
    for (unsigned int i=0; i<beauties.size(); ++i)
    {
        if (beauties[i].GetName() == name)
        {
            ++found;
            
            cout << "找到啦！该美女的索引是: " << i << endl;
            
            cout << "姓名：" << beauties[i].GetName() << endl
                 << "年龄：" << beauties[i].GetAge() << endl
                 << "国籍：" << beauties[i].GetNationality() << endl
                 << "三围：" << beauties[i].GetBust() << ", "
                 <<  beauties[i].GetWaist() << ", " << beauties[i].GetHips() << endl; 
        }
    }
    
    cout << "共找到：" << found << "位名为：" << name << "的美女！" << endl; 
}

void BeautiesManager::Introduction() const
{
    for (unsigned int i=0; i<beauties.size(); ++i)
    {
        cout << "现在出场的是：" << beauties[i].GetName() << endl;
        beauties[i].Introduction();
    }
}

void BeautiesManager::Clear()
{
    cout << "您确认要清除所有美女数据吗？该操作不可恢复！ (y/n)：";
    
    char c;
    cin >> c;
    
    cin.sync();
    
    if (c == 'y')
    {
        beauties.clear();
        cout << "数据已清除！" << endl;
    }
}

// 显示主菜单:
int ShowMenu()
{
    cout << "请选择：" << endl;
    cout << "1 美女信息录入" << endl
         << "2 美女信息查找" << endl
         << "3 检查美女总数" << endl
         << "4 美女出场自我介绍" << endl
         << "5 清空全部美女数据" << endl
         << endl
         << "6 关于本程序" << endl
         << "7 退出" << endl;
        
    int sel = 0;
    cin >> sel;
    cin.sync();
    
    return sel;
}

void About()
{
    cout <<  "《ＸＸＸ国际美女大赛信息管理系统 Ver 1.0》" << endl
        << "作者：丁小明 Copyright 2008~???" << endl;
}

int main()
{
    enum {sel_input = 1, sel_find, sel_count, sel_introduction, sel_clear, sel_about, sel_exit};
 
    cout << "XXX国际美女大赛欢迎您！" << endl;
 
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
        else				// 什么也不是?
        {
            if (cin.fail ())
            {
                cin.clear(); // 清除cin当前可能处于错误状态，需清除
                cin.sync();
            }
            
            cout << "选择有误，请重选。" << endl;
        }
    }
    system("pause");
    return 0;
}
#endif

//-----------------------------------------------------------------------------
#if 0																// 链表热身
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
    int a = *iter2; // 灾难发生
    *iter2 = 100;	// 灾难发生
    */
        
    lst.clear();
    lst.push_back(10);
    lst.push_back(100);
    iter = lst.begin();
    ++iter;					// iter前进1步，指向第二个元素
    lst.insert(iter, 1);	// 在第二个元素的位置上，插入新元素

    iter = lst.begin();
    ++iter;
    lst.erase(iter);

    list<int>::const_iterator  c_iter = lst.begin();  // 此时调用的是常量版
    a = *c_iter;		// 正确
    cout << a << endl;
    //*c_iter = 1000;	// 错误！c_iter是只读版迭代器，不允许修改它绑定的元素
    
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
#if 0																// 17 链表篇
#include <iostream>
#include <list> 
#include <vector>
#include <string>

using namespace std;

struct Student			// 学生
{
  unsigned int number;	// 学号
  string name;
};

struct Score			// 成绩
{
   unsigned int number; // 学号
   float mark;			// 分数
};

struct StudentScoreManager // 学生成绩管理类
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
    unsigned int number = 1; // 学号从1开始
    
    while(true)
    {
        cout << "请输入" << number << "号学生姓名(输入x表示结束)：";     
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
        
        cout << "请输入学号（输入0表示结束）：";
        
        cin >> number;
        
        if (number == 0)
        {
            break;
        }
               
        if (number > students.size()) // 简单判断学号是否正确： 
        {
            cout << "错误：学号必须位于: 1 ~ " << students.size() << " 之间。" << endl;
            continue; 
        }
        
        float mark;
        cout << "请输入该学员成绩：";
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
        unsigned int number = students[i].number; // 学号

        cout << "学号：" << number << endl;
        cout << "姓名：" << students[i].name << endl;
                
        // 查找成绩:
        bool found = false;
        
        for (list<Score>::const_iterator iter = scores.begin(); 
             iter != scores.end(); 
             ++iter)
        {
            if (iter->number == number)
            {
                found = true;	// 找到了
                
                cout << "成绩：" << iter->mark << endl;
                
                break;
            }
        }
        
        if (found == false)		// 没找到??
        {
            cout << "成绩：" << "查无成绩。" << endl;
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
请输入1号学生姓名(输入x表示结束)：wwu
请输入2号学生姓名(输入x表示结束)：fwu
请输入3号学生姓名(输入x表示结束)：x
请输入学号（输入0表示结束）：1
请输入该学员成绩：11
请输入学号（输入0表示结束）：2
请输入该学员成绩：22
请输入学号（输入0表示结束）：0
学号：1
姓名：wwu
成绩：11
学号：2
姓名：fwu
成绩：22
*/
#endif

//-----------------------------------------------------------------------------
#if 0												// 18 函数对象与自定义查找算法
// cin输入分数时有点问题，在线可以运行：https://www.onlinegdb.com/
#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

struct Student			// 学生
{
  unsigned int number;	// 学号
  string name;
};

struct Score			// 成绩
{
   unsigned int number; // 学号
   float mark;			// 分数
};

struct StudentScoreManager // 学生成绩管理类
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
    unsigned int number = 1;  // 学号从1开始

    while(true)
    {
        cout << "请输入" << number << "号学生姓名(输入x表示结束)：";

        string name;

        getline(cin, name);
		//cin.ignore(32767,'\n');
		//cin.clear(); //此处用cin.clear()流标志复位
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
   unsigned int number; // 学号

   bool operator () (unsigned int current_number) const  //函数对象---------
   {
        return current_number == number;
   }
};

// 自定义查找算法------------------------------------
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

        cout << "请输入学号（输入0表示结束）：";
        cin >> number;
        if (number == 0)
        {
            break;
        }

        // 简单判断学号是否正确：
        if (number > students.size())
        {
            cout << "错误：学号必须位于: 1 ~ " << students.size() << " 之间。" << endl;
            continue;
        }

        float mark;
        cout << "请输入该学员成绩：";
        cin >> mark;
		//scanf("%f",&mark);
		//cin.ignore(32767,'\n');
		//cin.clear(); //此处用cin.clear()流标志复位
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
        unsigned int number = students[i].number; //学号

        cout << "学号：" << number << endl;
        cout << "姓名：" << students[i].name << endl;

        // 查找成绩:
        CompareByNumber_Equal cmp;
        cmp.number = number;

        //list<Score>::const_iterator iter = find(scores.begin(), scores.end(), cmp);
		list<Score>::const_iterator iter = find(scores, cmp);
        if (iter != scores.end())
        {
            cout << "成绩：" << iter->mark << endl;
        }
        else // 没找到
        {
             cout << "成绩：" << "查无成绩。" << endl;
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
请输入1号学生姓名(输入x表示结束)：wwu                                                                                   
请输入2号学生姓名(输入x表示结束)：wwf                                                                                   
请输入3号学生姓名(输入x表示结束)：x                                                                                     
请输入学号（输入0表示结束）：1                                                                                          
请输入该学员成绩：11                                                                                                    
请输入学号（输入0表示结束）：2                                                                                          
请输入该学员成绩：22                                                                                                    
请输入学号（输入0表示结束）：0                                                                                          
学号：1                                                                                                                 
姓名：wwu                                                                                                               
成绩：11                                                                                                                
学号：2                                                                                                                 
姓名：wwf                                                                                                               
成绩：22                                                                                                                
sh: 1: pause: not found   
*/
#endif

//-----------------------------------------------------------------------------
#if 0											     // 19 自定义查找算法及泛化
#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

struct Student				// 学生
{
  unsigned int number;		// 学号
  string name;
};

struct Score				// 成绩
{
   unsigned int number;		// 学号
   float mark;				// 分数
};

struct StudentScoreManager	// 学生成绩管理类
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
    unsigned int number = 1;  // 学号从1开始

    while(true)
    {
        cout << "请输入" << number << "号学生姓名(输入x表示结束)：";

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
   unsigned int number;  // 学号

   bool operator () (unsigned int current_number) const
   {
        return current_number == number;
   }
};

//将 find “泛化”，让它可以针对不同容器，以及不同的容器元素，都可以作查找
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

        cout << "请输入学号（输入0表示结束）：";

        cin >> number;

        if (number == 0)
        {
            break;
        }

        // 简单判断学号是否正确：
        if (number > students.size())
        {
            cout << "错误：学号必须位于: 1 ~ " << students.size() << " 之间。" << endl;
            continue;
        }

        float mark;
        cout << "请输入该学员成绩：";
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
        unsigned int number = students[i].number; //学号

        cout << "学号：" << number << endl;
        cout << "姓名：" << students[i].name << endl;

        // 查找成绩:
        CompareByNumber_Equal cmp;
        cmp.number = number;

        list<Score>::const_iterator iter = find(scores.begin(), scores.end(), cmp);

        if (iter != scores.end())
        {
            cout << "成绩：" << iter->mark << endl;
        }
        else // 没找到
        {
             cout << "成绩：" << "查无成绩。" << endl;
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
请输入1号学生姓名(输入x表示结束)：wwu
请输入2号学生姓名(输入x表示结束)：wwf
请输入3号学生姓名(输入x表示结束)：x
请输入学号（输入0表示结束）：1
请输入该学员成绩：11
请输入学号（输入0表示结束）：2
请输入该学员成绩：22
请输入学号（输入0表示结束）：0
学号：1
姓名：wwu
成绩：11
学号：2
姓名：wwf
成绩：22
*/
#endif

//-----------------------------------------------------------------------------
#if 0														// 20 标准库查找算法
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Student
{
  unsigned int number;		// 学号
  string name;
};

struct Score				// 成绩
{
   unsigned int number;		// 学号
   float mark;				// 分数
};

struct StudentScoreManager	// 学生成绩管理类
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
    unsigned int number = 1;  // 学号从1开始

    while(true)
    {
        cout << "请输入" << number << "号学生姓名(输入x表示结束)：";

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
   unsigned int number;  // 学号

   bool operator () (Score const & current_score) const  // 函数对象
   {
       return (current_score.number == number);
   }
};

void StudentScoreManager::InputScores()
{
    while(true)
    {
        unsigned int number;

        cout << "请输入学号（输入0表示结束）：";

        cin >> number;

        if (number == 0)
        {
            break;
        }

        //简单判断学号是否正确：
        if (number > students.size())
        {
            cout << "错误：学号必须位于: 1 ~ " << students.size() << " 之间。" << endl;
            continue;
        }

        float mark;
        cout << "请输入该学员成绩：";
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
        unsigned int number = students[i].number; //学号

        cout << "学号：" << number << endl;
        cout << "姓名：" << students[i].name << endl;

        // 查找成绩:
        CompareByNumber_Equal cmp;
        cmp.number = number;
		// STL 查找函数
        list<Score>::const_iterator iter = find_if(scores.begin(), scores.end(), cmp);

        if (iter != scores.end())
        {
            cout << "成绩：" << iter->mark << endl;
        }
        else // 没找到
        {
             cout << "成绩：" << "查无成绩。" << endl;
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
#if 0											// 21 成绩管理系统2（标准库排序算法）
// scores.sort(cmp)有点问题，在线OK：https://www.onlinegdb.com/
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Student				 // 学生
{
  unsigned int number;		 // 学号
  string name;				 // 姓名
};

struct Score				// 成绩
{
   unsigned int number;		// 学号
   float mark;				// 分数
};

struct StudentScoreManager	// 学生成绩管理类
{
public:
    void InputStudents();	// 录入学生基本信息（录入前自动清空原有数据）
    void InputScores();		// 录入成绩（录入前不清空原有数据）
    void ClearScores();		// 清空成绩数据

    void OutputScoresByNumber() const;	// 以学号次序，输出每个学生信息，包括成绩
    void OutputScoresByMark() const;	// 以分数排名，输出每个成绩，包括学生基本信息

    void FindStudentByNumber() const;	// 通过学号，查找学生，显示姓名，学号，成绩
    void FindStudentByName() const;		// 通过姓名，查找学生，显示姓名，学号，成绩

private:
    // 内部调用的函数:
    // 给定一个学号，在scores中查找，并输出其分数
    void FindScoreByNumber(unsigned int number) const;

    vector<Student> students;
    list<Score> scores;
};

// 检查是否输入有误，如有，则清除出错状态，并返回“真”.
bool CheckInputFail()
{
    if (cin.fail ())	// 检查 cin是不是出错了？
    {
        // 出错了...
        cin.clear();	// 清除cin当前可能处于错误状态
        cin.sync();		// 再清除当前所有未处理的输入

        cout << "输入有误，请重新处理。" << endl;

        return true;
    }

    return false;
}

// 输入学生成绩
void StudentScoreManager::InputStudents()
{
    // 检查是否已经有数据:
    if (students.empty() == false)
    {
        cout << "确信要重新录入学生基本信息吗？(y/n)";
        char c;
        cin >> c;

        if (c != 'y')
        {
            return;
        }

        cin.sync(); // 吃掉回车键.
    }

    // 因为允许用户重新录入，所以现在需要清除原有数据
    students.clear();

    unsigned int number = 1; // 学号从1开始

    while(true)
    {
        cout << "请输入学生姓名(输入x表示结束), " << number << "号：";

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

// 比较器：比较姓名是否相等
// 用于在students中查找指定姓名的学生
struct CompareByName4Find
{
    bool operator () (Student student) const
    {
        return student.name == name;
    }

    // 待查找的姓名
    string name;
};

// 比较器：比较成绩中的学号是否相等
// 用于在 scores中查找指定学号的成绩
struct CompareByNumber_Equal4Find
{
    bool operator () (Score s) const
    {
        return (s.number == number);
    }

    unsigned int number;
};

// 内部调用的函数:
// 给定一个学号，在scores中查找，并输出其分数
void StudentScoreManager::FindScoreByNumber(unsigned int number) const
{
    CompareByNumber_Equal4Find cbne;
    cbne.number = number;

    list<Score>::const_iterator itScore = find_if(scores.begin(), scores.end(), cbne);

    if (itScore == scores.end())
    {
       // 找不到成绩：
       cout << "，成绩：查无成绩。";
    }
    else
    {
        // 查到成绩了，显示：
        cout << "，成绩：" << itScore->mark;
    }
}

// 通过学号查到详细信息
void StudentScoreManager::FindStudentByNumber() const
{
    cout << "请输入要查找的学号：";

    unsigned int number;
    cin >> number;

    // 用户输入非数字字符时，此时检查出错误
    if (CheckInputFail())
    {
        return;
    }

    // 检查是不是在合法范围内的学号:
    unsigned int maxNumber = students.size();

    if (number > maxNumber)
    {
        cout << "学号只允许在 1~" << maxNumber << " 之间！" << endl;
        return;
    }

    cout << "学号：" << number;
    cout << "，姓名：" << students[number - 1].name;

    // 继续查：用学号查分数:
    FindScoreByNumber(number);

    cout << endl;
}

// 通过姓名查找到学生基本信息，然后再通过学号找到学生成绩。
// 逐步显示查到的结果。如果有多个同名学生，则全部输出。
void StudentScoreManager::FindStudentByName() const
{
    cout << "请输入待查找的学员姓名：";

    string name;

    getline(cin, name);

    CompareByName4Find cmp;
    cmp.name = name;

    int foundCount = 0; // 已经查找到几个人了？

    vector<Student>::const_iterator beg = students.begin(); // 从哪里查起

    while(true)
    {
        // 查找学生，注意查找范围为: beg ~ students.end()
        beg = find_if(beg, students.end(), cmp);

        if (beg == students.end())
        {
            break; // 找不到人了...结束循环
        }

        // 查到该学生了...
        ++foundCount; // 找到的人数加1。

        // 显示学生基本信息：
        cout << "姓名：" << name;
        cout << "，学号：" << beg->number;

        // 继续查：用学号查分数:
        FindScoreByNumber(beg->number);

        cout << endl;

        // 重要：将beg前进到下一个位置，
        // 意思是：下次查找时，将从当前找到的那学生的下一个位置开始找起
        beg++;
    }

    cout << "总共查到" << foundCount << "位学生，名为：" << name << endl;
}

// 根据学号的次序输出学生成绩，没有成绩的学员，显示“查无成绩”
void StudentScoreManager::OutputScoresByNumber() const
{
    for (unsigned int i=0; i<students.size(); ++i)
    {
        unsigned int number = students[i].number; // 学号

        cout << "学号：" << number;
        cout << "，姓名：" << students[i].name;

        // 查找成绩:
        CompareByNumber_Equal4Find cmp;
        cmp.number = number;

        list<Score>::const_iterator iter = find_if(scores.begin(), scores.end(), cmp);

        if (iter != scores.end())
        {
            cout << "，成绩：" << iter->mark << endl;
        }
        else // 没找到
        {
             cout << "，成绩：" << "查无成绩。" << endl;
        }
    }
}

// 比较器：比较成绩中的分数高低
// 在InputScores()中，录入成绩之后，会立即使用本比较对成绩进行排序
struct CompareByMarkBigger
{
    bool operator () (Score s1, Score s2) const
    {
        return (s1.mark > s2.mark);
    }
};

// 录入学生成绩，录入完成后即行排序
void StudentScoreManager::InputScores()
{
    while(true)
    {
        unsigned int number;

        cout << "请输入学号（输入0表示结束）：";

        cin >> number;

        // 检查用户输入是不是合法的数字
        if (CheckInputFail())
        {
            continue;
        }

        if (number == 0)
        {
            break;
        }

        // 判断学号大小是否在合法的范围内：
        if (number > students.size())
        {
            cout << "错误：学号必须位于: 1 ~ " << students.size() << " 之间。" << endl;
            continue;
        }

        float mark;
        cout << "请输入成绩(" << students[number-1].name << ")："; // 本版此处新增了姓名提示
        cin >> mark;

        // 检查用户输入是不是合法的浮点数
        if (CheckInputFail())
        {
            continue;
        }

        Score score;
        score.number = number;
        score.mark = mark;

        scores.push_back(score);
    }

    // 本版新增功能：录入成绩后，立即按分数高低排序
    // 保证scores中的元素永远是有序的
    CompareByMarkBigger cmp;
    scores.sort(cmp); // c++14 OK ，排序------------------------------------------------
}

// 清空成绩
void StudentScoreManager::ClearScores()
{
    cout << "您确信要清空全部成绩数据？ (y/n)";

    char c;
    cin >> c;

    if (c == 'y')
    {
        scores.clear();
        cout << "成绩数据清除完毕！" << endl;
    }

    cin.sync();
}

// 按分数高低，输出每个成绩，包括学生姓名，没有参加考试学员，将不会被输出
void StudentScoreManager::OutputScoresByMark() const
{
    // 在每次录入成绩之后，我们都会调用sort立即为所有成绩进行排序
    // 所以scores中的所有成绩，已经是按高低分排序了
    // 问题是：分数相同时必须处理“名次并列”的情况。

    int index = 1;		// 当前名次,排名从1开始
    int count = 0;		// 相同分数个数
    double last = -1.0; // 上一次分数，刚开始时，初始化为一个不可能的分数

    for (list<Score>::const_iterator it = scores.begin();
        it != scores.end();
        ++it)
    {
        if (last != it->mark)	// 新的分数出现
        {
            last = it->mark;
            index += count;
            count = 1;
        }
        else					// 还是原来的分数（同分）
        {
            ++count;
        }

        cout << "名次：" << index;
        cout << "，姓名：" << students[it->number - 1].name; // 通过学号得到名字
        cout << "，学号：" << it->number;
        cout << "，成绩：" << it->mark << endl;
    }
}

void About()
{
    system("cls");

    cout << "学生成绩管理系统 Ver 2.0" << endl;
    cout << "copyright 2008~?" << endl;
    cout << "作者：丁小聪" << endl;
    cout << "来自：www.d2school.com/白话C++" << endl;
}

void Help()
{
    system("cls");

    cout << "1 录入学生基本信息：" << endl
        << "请注意，重新录入时，原有数据会清空！" << endl
        << endl;

    cout << "2 录入成绩：" << endl
        << "请注意，会在原有成绩数据上录入，如果需要清空成绩，请使用：清空成绩。" << endl
        << endl;

    cout << "3 清空成绩：" << endl
        << "之前录入的成绩将被清除，本操作不可恢复。" << endl
        << endl;

    cout << "4 按学号次序显示成绩：" << endl
        << "按学号从小到大输出成绩，包括姓名。未参加考试或还录入成绩学员，将显示查无成绩。" << endl
        << endl;

    cout << "5 按分数名次显示成绩：" << endl
        << "按分数从高到低输出成绩，包括名次，学号，姓名等。" << endl
        << "忠告：听说教育部禁止学校公布成绩排名。" << endl
        << endl;

    cout << "6 按学号查找学生：" << endl
        << "输入学号，查找到指定学生的学生信息，包括成绩。" << endl
        << endl;

    cout << "7 按姓名查找学生：" << endl
        << "输入姓名，查到到该名字的学生，并输出其信息，包括成绩，如有重名，连续输出。" << endl
        << endl;

    cout << "8 关于：关于本软件的一些信息。" << endl << endl;
    cout << "9 帮助：显示本帮助信息。" << endl << endl;
    cout << "0 退出：输入0，退出本程序。" << endl << endl;
}

int Menu()
{
    cout << "-------------------------------" << endl;
    cout << "----学生成绩管理系统 Ver2.0----" << endl;
    cout << "-------------------------------" << endl;

    cout << "请选择：(0~9)" << endl;

    cout << "1 录入学生基本信息" << endl;
    cout << "2 录入成绩" << endl;
    cout << "3 清空成绩" << endl;

    cout << endl;
    cout << "4 按学号次序显示成绩" << endl;
    cout << "5 按分数名次显示成绩" << endl;

    cout << endl;
    cout << "6 按学号查找学生" << endl;
    cout << "7 按姓名查找学生" << endl;

    cout << endl;
    cout << "8 关于" << endl;
    cout << "9 帮助" << endl;

    cout << endl;
    cout << "0 退出" << endl;

    int sel;
    cin >> sel;

    if (CheckInputFail())
    {
        return -1;
    }

    cin.sync(); //清掉输入数字之后的 回车键

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
        else // 什么也不是..
        {
            cout << "请正确输入选择：范围在 0 ~ 9 之内。" << endl;
        }

        system("Pause");
    }

    cout << "bye~bye~" << endl;

    return 0;
}
#endif

//-----------------------------------------------------------------------------
#if 0															// 文件读写热身
//getline(ifs, line);有点问题，在线OK：https://www.onlinegdb.com/
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
#if 0																// 22 STL文件篇
// 在线运行https://www.onlinegdb.com/
#include <iostream>
#include <list> 
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

struct Student				// 学生
{
  unsigned int number;		// 学号
  string name;				// 姓名
};

struct Score				// 成绩
{
   unsigned int number;		// 学号
   float mark;				// 分数
};

struct StudentScoreManager	// 学生成绩管理类
{
public:
    void InputStudents();		// 录入学生基本信息（录入前自动清空原有数据） 
    void SaveStudents() const;	// 保存学生基体信息到文件
    void LoadStudents();		// 从文件中读入学生基本信息。
       
    void InputScores();			// 录入成绩（录入前不清空原有数据）
    void ClearScores();			// 清空成绩数据
    
    void OutputScoresByNumber() const;	// 以学号次序，输出每个学生信息，包括成绩
    void OutputScoresByMark() const;	// 以分数排名，输出每个成绩，包括学生基本信息
    
    void FindStudentByNumber() const;	// 通过学号，查找学生，显示姓名，学号，成绩
    void FindStudentByName() const;		// 通过姓名，查找学生，显示姓名，学号，成绩
    
private:
    //内 部调用的函数:
    // 给定一个学号，在scores中查找，并输出其分数
    void FindScoreByNumber(unsigned int number) const;

    vector<Student> students;
    list<Score> scores;
};

// 检查是否输入有误，如有，则清除出错状态，并返回“真”.
bool CheckInputFail()
{
    if (cin.fail ()) // 检查 cin是不是出错了？
    {
        // 出错了...
        cin.clear(); // 清除cin当前可能处于错误状态
        cin.sync();	 // 再清除当前所有未处理的输入
        
        cout << "输入有误，请重新处理。" << endl;
        
        return true;
    }
    
    return false;
}

// 输入学生成绩
void StudentScoreManager::InputStudents()
{
    // 检查是否已经有数据:
    if (students.empty() == false)
    {
        cout << "确信要重新录入学生基本信息吗？(y/n)";
        char c;
        cin >> c;
        
        if (c != 'y')
        {
            return;
        }
        
        cin.sync(); // 吃掉回车键.
    }
    
    // 因为允许用户重新录入，所以现在需要清除原有数据
    students.clear(); 
    
    unsigned int number = 1; // 学号从1开始
    
    while(true)
    {
        cout << "请输入学生姓名(输入x表示结束), " << number << "号：";
        
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

//保存学生基本信息到特定的文件中：--------------------------------------
void StudentScoreManager::SaveStudents() const
{
    ofstream ofs;
    ofs.open(".\\students_base_info.txt");
    
    if (!ofs)
    {
        cout << "打开成绩输出文件失败！" << endl;
        return;
    }
    
    // 特意输入学员个数，方便于后面的读文件过程
    unsigned int count = students.size();
    ofs << count << endl;
    
    for (unsigned int i=0; i<count; ++i)
    {
        ofs << students[i].number << endl; 
        ofs << students[i].name << endl; 
    }
    
    ofs.close(); 
    
    cout << "保存完毕，共保存" << count << "位学生基本信息。" << endl;
}

// 从特定的文件中，读入学生基本信息：
void StudentScoreManager::LoadStudents() 
{
    ifstream ifs;
    ifs.open(".\\students_base_info.txt");
    
    if (!ifs)
    {
        cout << "打开成绩输入文件失败！" << endl;
        return;
    }
    
    students.clear();		// 清除原来的学生数据
    
    unsigned int count = 0;
    ifs >> count;			// 读入个数

    for (unsigned int i=0; i<count; ++i)
    {
        Student stu; 
        
        ifs >> stu.number; 
        
        ifs.ignore();		// 替后续的getline跳过：学号之后的换行符
        getline(ifs, stu.name);  // 读入姓名
       
        students.push_back(stu); // 加入
    }
    
    cout << "加载完毕，共加载：" << count << "位学生的基本信息。" << endl;
}

// 比较器：比较姓名是否相等
// 用于在students中查找指定姓名的学生
struct CompareByName4Find
{
    bool operator () (Student student) const
    {
        return student.name == name;
    }
    
    // 待查找的姓名
    string name;
};

// 比较器：比较成绩中的学号是否相等
// 用于在 scores中查找指定学号的成绩
struct CompareByNumber_Equal4Find
{
    bool operator () (Score s) const
    {
        return (s.number == number);
    }
    
    unsigned int number;
};

// 内部调用的函数:
// 给定一个学号，在scores中查找，并输出其分数
void StudentScoreManager::FindScoreByNumber(unsigned int number) const
{
    CompareByNumber_Equal4Find cbne;
    cbne.number = number;
    
    list<Score>::const_iterator itScore = find_if(scores.begin(), scores.end(), cbne);
    
    if (itScore == scores.end()) 
    {
       // 找不到成绩：
       cout << "，成绩：查无成绩。"; 
    }
    else
    {
        // 查到成绩了，显示：
        cout << "，成绩：" << itScore->mark;
    }
}

// 通过学号查到详细信息
void StudentScoreManager::FindStudentByNumber() const 
{
    cout << "请输入要查找的学号：";
    
    unsigned int number;
    cin >> number;
    
    // 用户输入非数字字符时，此时检查出错误
    if (CheckInputFail()) 
    {
        return;
    }
    
    // 检查是不是在合法范围内的学号:
    unsigned int maxNumber = students.size();
    
    if (number > maxNumber)
    {
        cout << "学号只允许在 1~" << maxNumber << " 之间！" << endl;
        return;
    }
    
    cout << "学号：" << number;
    cout << "，姓名：" << students[number - 1].name;
    
    // 继续查：用学号查分数:
    FindScoreByNumber(number);
    
    cout << endl;
}

// 通过姓名查找到学生基本信息，然后再通过学号找到学生成绩。
// 逐步显示查到的结果。如果有多个同名学生，则全部输出。
void StudentScoreManager::FindStudentByName() const
{
    cout << "请输入待查找的学员姓名：";
    
    string name;
    
    getline(cin, name);
    
    CompareByName4Find cmp;
    cmp.name = name;
    
    int foundCount = 0; // 已经查找到几个人了？
    
    vector<Student>::const_iterator itStu = students.begin(); // 从哪里查起
    
    while(itStu != students.end())
    {
        // 查找学生，注意查找范围为: itStu ~ students.end()
        itStu = find_if(itStu, students.end(), cmp);
        
        if (itStu == students.end())
        {
            break; // 找不到人了...结束循环
        }
        
        // 查到该学生了...
        ++foundCount; // 找到的人数加1。
        
        //显示学生基本信息：
        cout << "姓名：" << name;
        cout << "，学号：" << itStu->number;
        
        // 继续查：用学号查分数:
        FindScoreByNumber(itStu->number);

        cout << endl;
       
        // 重要：将itStu前进到下一个位置，
        // 意思是：下次查找时，将从当前找到的那学生的下一个位置开始找起
        itStu++;
    }
    
    cout << "总共查到" << foundCount << "位学生，名为：" << name << endl;
}

// 根据学号的次序输出学生成绩，没有成绩的学员，显示“查无成绩”
void StudentScoreManager::OutputScoresByNumber() const
{
    for (unsigned int i=0; i<students.size(); ++i)
    {
        unsigned int number = students[i].number; //学号

        cout << "学号：" << number;
        cout << "，姓名：" << students[i].name;
                
        // 查找成绩:
        CompareByNumber_Equal4Find cmp;
        cmp.number = number;
  
        list<Score>::const_iterator iter = find_if(scores.begin(), scores.end(), cmp);
        
        if (iter != scores.end())
        {
            cout << "，成绩：" << iter->mark << endl;
        }
        else // 没找到
        {
             cout << "，成绩：" << "查无成绩。" << endl;
        }
    }    
}

// 比较器：比较成绩中的分数高低
// 在InputScores()中，录入成绩之后，会立即使用本比较对成绩进行排序
struct CompareByMarkBigger
{
    bool operator () (Score s1, Score s2) const
    {
        return (s1.mark > s2.mark);
    }
};

// 录入学生成绩，录入完成后即行排序
void StudentScoreManager::InputScores()
{
    while(true)
    {
        unsigned int number;
        
        cout << "请输入学号（输入0表示结束）：";
        
        cin >> number;
        
        // 检查用户输入是不是合法的数字
        if (CheckInputFail())
        {
            continue;
        }
        
        if (number == 0)
        {
            break;
        }
        
        // 判断学号大小是否在合法的范围内：        
        if (number > students.size())
        {
            cout << "错误：学号必须位于: 1 ~ " << students.size() << " 之间。" << endl;
            continue; 
        }
        
        float mark;
        cout << "请输入成绩(" << students[number-1].name << ")："; // 本版此处新增了姓名提示
        cin >> mark;
        
        // 检查用户输入是不是合法的浮点数
        if (CheckInputFail())
        {
            continue;
        }

        Score score;
        score.number = number;
        score.mark = mark;
        
        scores.push_back(score);
    }
    
    // 本版新增功能：录入成绩后，立即按分数高低排序
    // 保证scores中的元素永远是有序的
    CompareByMarkBigger cmp;
    scores.sort(cmp);    
}

// 清空成绩
void StudentScoreManager::ClearScores()
{
    cout << "您确信要清空全部成绩数据？ (y/n)";
    
    char c;
    cin >> c;
    
    if (c == 'y')
    {
        scores.clear();
        cout << "成绩数据清除完毕！" << endl;
    }
    
    cin.sync();
}

// 按分数高低，输出每个成绩，包括学生姓名，没有参加考试学员，将不会被输出
void StudentScoreManager::OutputScoresByMark() const
{
    // 在每次录入成绩之后，我们都会调用sort立即为所有成绩进行排序
    // 所以scores中的所有成绩，已经是按高低分排序了
    // 问题是：分数相同时必须处理“名次并列”的情况。
    
    int currentIndex = 1; //当前名次,排名从1开始
    int sameMarkCount = 0; //相同分数个数
    double lastMark= -1; //上一次分数，刚开始时，初始化为一个不可能的分数
    
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
        else // 分数相同
        {
            ++sameMarkCount; 
        }
        
        cout << "名次：" << currentIndex;
        cout << "，姓名：" << students[it->number - 1].name; // 通过学号得到名字
        cout << "，学号：" << it->number;
        cout << "，成绩：" << it->mark << endl;        
    }
}

void About()
{
    system("cls");
    
    cout << "学生成绩管理系统 Ver 3.0" << endl;
    cout << "copyright 2008~?" << endl;
    cout << "作者：丁小聪" << endl;
    cout << "来自：www.d2school.com/白话C++" << endl; 
}

void Help()
{
    system("cls");
    
    cout << "1 录入学生基本信息：" << endl 
        << "请注意，重新录入时，原有数据会清空！" << endl 
        << endl;
    
    cout << "2 录入成绩：" << endl 
        << "请注意，会在原有成绩数据上录入，如果需要清空成绩，请使用：清空成绩。" << endl 
        << endl; 
        
    cout << "3 清空成绩：" << endl 
        << "之前录入的成绩将被清除，本操作不可恢复。" << endl 
        << endl;
    
    cout << "4 按学号次序显示成绩：" << endl 
        << "按学号从小到大输出成绩，包括姓名。未参加考试或还录入成绩学员，将显示查无成绩。" << endl 
        << endl;

    cout << "5 按分数名次显示成绩：" << endl 
        << "按分数从高到低输出成绩，包括名次，学号，姓名等。" << endl
        << "忠告：教育部禁止学校公布成绩排名。" << endl
        << endl;
        
    cout << "6 按学号查找学生：" << endl 
        << "输入学号，查找到指定学生的学生信息，包括成绩。" << endl 
        << endl;
        
    cout << "7 按姓名查找学生：" << endl 
        << "输入姓名，查到到该名字的学生，并输出其信息，包括成绩，如有重名，连续输出。" << endl 
        << endl;
        
    cout << "8 加载学生基本信息：" << endl
        << "如果曾经保存学生基本信息，则从该文件读出学生基本信息，注意：当前已有的学生信息将丢失！"
        << endl << endl;
        
    cout << "9 保存学生基本信息：" << endl 
        << "保存当前学生基本信息到文件，如果已经原有文件，则原有文件内容将被刷新！" 
        << endl << endl;
    
    cout << "10 关于：关于本软件的一些信息。" << endl << endl;
    cout << "11 帮助：显示本帮助信息。" << endl << endl;

    cout << "0 退出：输入0，退出本程序。" << endl << endl;
}

int Menu()
{
    cout << "-------------------------------" << endl;
    cout << "----学生成绩管理系统 Ver3.0----" << endl;
    cout << "-------------------------------" << endl;
    
    cout << "请选择：(0~9)" << endl;
    
    cout << "1 录入学生基本信息" << endl;
    cout << "2 录入成绩" << endl;
    cout << "3 清空成绩" << endl;

    cout << endl;
    cout << "4 按学号次序显示成绩" << endl;
    cout << "5 按分数名次显示成绩" << endl;
    
    cout << endl;
    cout << "6 按学号查找学生" << endl;
    cout << "7 按姓名查找学生" << endl;

    cout << endl;
    cout << "8 加载学生基本信息" << endl;
    cout << "9 保存学生基本文件" << endl;
    
    cout << endl;
    cout << "10 关于" << endl;
    cout << "11 帮助" << endl;
    
    cout << endl;
    cout << "0 退出" << endl;
    
    int sel;
    cin >> sel;
        
    if (CheckInputFail())
    {
        return -1;
    }
    
    cin.sync(); // 清掉输入数字之后的 回车键

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
        else // 什么也不是..
        {
            cout << "请正确输入选择：范围在 0 ~ 11 之内。" << endl; 
        }
        
        system("Pause"); 
    }
    
    cout << "bye~bye~" << endl;
    
    return 0;
}
#endif

// https://www.onlinegdb.com/

