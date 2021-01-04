#include <iostream>
#include <fstream>		//使用文件操作必须包含fstream
using namespace std;
int main()
{
    ofstream out("file");	//定义输出流，并与文件file关联
    ifstream in;			//定义一个输入流对象
    fstream io;
    int i;
   	//将1～10写到输出流对象
    if (!out) 
	{cerr << "create file error\n"; return 1;}	
    for (i = 1; i <= 10; ++i) 
		out.write(reinterpret_cast<char *> (&i), sizeof(int)); 
    out.close();
    in.open("file");						
     if (!in) 
	 {cerr << "open file error\n"; return 1;}
     in.read(reinterpret_cast<char *> (&i), sizeof(int));
	//判断文件结束
	//>>读：可以通过判断输入流对象值是否为0。
	//get读：判断读入字符是否是EOF。
	//其他方式读：通过成员函数eof。eof函数不需要参数，
	//返回一个整型值。当读操作遇到文件结束时，该函数返回1，否则返回0。

     while (!in.eof()) {
	    cout << i << ' ';					
         in.read(reinterpret_cast<char *> (&i), sizeof(int));
     }
	in.close();
	cout << endl;

     // 改写6为20
	io.open("file");
	io.seekp(5 * sizeof(int));             // 写文件定位到6的位置
	i = 20;
    io.write(reinterpret_cast<char *> (&i), sizeof(int));  
	// 重新读文件
	io.seekg(0);
    io.read(reinterpret_cast<char *> (&i), sizeof(int));
	while (!io.eof()) {                
	    cout << i << ' ';					
        io.read(reinterpret_cast<char *> (&i), sizeof(int));
    }
	io.close();

    return 0;
}
