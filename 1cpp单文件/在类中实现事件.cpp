/*
在类中实现事件

  在许多语言中都有对事件的定义，事件的作用是可以在类外实现一个事件，然后在类中调用这个事件。
  这样在设计类时就可以不必实现某些功能，而这些功能可以交给外部函数来处理，这样更增加了程序的灵活性。
  本实例实现了如何在类中实现事件。
  
    在C++语言中实现事件可以使用函数回调的方法，而函数回调就是使用函数指针来实现的。
    注意这里针对的是普通的函数，不包括完全依赖于不同语法和语义规则的类成员函数。
    声明函数指针回调函数是一个程序员不能显式调用的函数，通过将回调函数的地址传给调用者从而实现调用。
    要实现回调，必须首先定义函数指针。尽管定义的语法有点不可思议，但如果你熟悉函数声明的一般方法，
    便会发现函数指针的声明与函数声明非常类似。请看下面的例子：
    
      void f()；// 函数原型
      
        上面的语句声明了一个函数，没有输入参数并返回void。那么函数指针的声明方法如下：
        
          void (*f) ();
*/
#include "stdlib.h"
#include "ioStream.h"
#include "string.h"

class CLoad;
typedef void (*TEvent)(CLoad * e);	// 事件指针

class CLoad
{
private:
    char filename[10];				// 文件名
public:
    TEvent OnLoad22;				// 载入事件
    void Load(char *FileName)
    {
        strcpy(filename,FileName);
        cout << "执行内部载入操作" << endl;
        if (OnLoad22 != NULL)		// 是否存在事件
            OnLoad22(this);			// 执行事件
    }
    char * GetFileName()
    {
        return filename;
    }
};

void OnLoad22(CLoad* e)				// 定义外部事件
{
    cout << "执行外部事件加载文件：" << e->GetFileName() << endl;
}

int main(int argc, char* argv[])
{
    CLoad ld;
    ld.OnLoad22 = OnLoad22;			// 添加事件
    ld.Load("c:\\123.txt");
    system("pause");
    return 0;
}
/*
执行内部载入操作
执行外部事件加载文件：c:\123.txt
*/