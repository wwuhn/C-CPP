#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

vector<string> split0(string str,char deli) // string+vector逐字节处理
{
    vector<string> vec;
    string tmp;
    string::iterator it=str.begin();
    for(; it != str.end();it++)
    {
        if (*it != deli)
            tmp += *it;
        else
        {
            vec.push_back(tmp);
            tmp = "";
        }
    }
    return vec;
}

vector<string> split1(char* src,const char* separators)  // strtok()，分隔符可以指定多个
{
    if (strlen(src) ==  0)
        exit(0);
    vector<string> vec;
    char *pNext = (char *)strtok(src,separators); 
    while(pNext != NULL) 
    {
        vec.push_back(pNext);
        pNext = (char *)strtok(NULL,separators);
    }  
    return vec;
} 

int splitc(char *src,const char *separator,char **dest)  // 放到一个字符指针数组内
{
     int count = 0;
     if (src == NULL || strlen(src) == 0)
        return 0;
     if (separator == NULL || strlen(separator) == 0)
        return 0;
     char *pNext = (char *)strtok(src,separator);
     while(pNext != NULL) {
          *dest++ = pNext;
          ++count;
         pNext = (char *)strtok(NULL,separator);
    }  
    return count;
} 

vector<string> split2(string str, string delis) // .find_first_of()+substr()
{
	vector<string> vec;
	size_t current;
	size_t next = -1;
	do{
		current = next + 1;
		next = str.find_first_of(delis, current);
		vec.push_back(str.substr(current, next - current));
	}while(next != string::npos); // static const size_t npos = -1;
	return vec;
}

vector<string> split3(string str,char deli) // string+vector逐段处理
{
    vector<string> vec;
    string line;
    int pos = str.find(deli);
    while(pos != string::npos)
    {
        line = str.substr(0,pos);
        vec.push_back(line);
        str.erase(0,pos+1);
        pos = str.find(deli);
    }
    return vec;
}

vector<string> split(string str, char deli)  // 字符串流+string+vector处理
{
    stringstream ss(str);
    string tmp;
    vector<string> vec;
    while(getline(ss, tmp, deli)) 
        vec.push_back(tmp);
    return vec;
}

struct split
{
  enum empties_t { empties_ok, no_empties };
};

template <typename Container>
Container& splitt(
    Container&                                 box,
    const typename Container::value_type&      s,
    typename Container::value_type::value_type deli,
    split::empties_t                           empties = split::empties_ok )
{
    box.clear();
    std::istringstream ss( s );
    while (!ss.eof())
    {
        typename Container::value_type field;
        getline(ss, field, deli);
        if((empties == split::no_empties) && field.empty()) 
			continue;
        box.push_back( field );
    }
    return box;
}

vector<string> split(string str)   // fstream+string+vector处理
{
    ofstream ofs("tmp.txt");
    ofs<<str.c_str();
    ofs.close();
    ifstream ifs("tmp.txt");
    vector<string> vec;
    string tmp;
    while(getline(ifs,tmp))
        vec.push_back(tmp);
    //cout<<ifs.rdbuf();
    ifs.close();
    return vec;
}

void Print(vector<string>& vec)
{
    vector<string>::iterator it=vec.begin();
    for(;it!=vec.end();it++)
        printf("%s\n", (*it).c_str());
}

void Print(char **ppstr, int num)
{
	for(int i=0; i<num; i++)
		printf("%s\n",ppstr[i]);
}

int main()
{
    string str  = "上善若水。\n水善利万物而不争，\n";
           str += "处众人之所恶，故几于道。\n";

    vector<string> vec = split0(str,'\n');
    Print(vec);

    string str1 = "We are the world!\nwe are the one!\n";
    vec = split1(const_cast<char*>(str1.c_str()),"\r\n");
    Print(vec);

	char *buf[3] = {0};
	char str2[] = "知善知恶\n为善去恶\n知行合一";
	splitc(str2,"\n",buf);
	Print(buf,3);

    vec = split2(str,"\n");
    Print(vec);

    vec = split3(str,'\n');
    Print(vec);

    vec = split(str,'\n');
    Print(vec);	

	//splitt(vec,str,'\n');
	//Print(vec);
	
    vec = split(str);
    Print(vec);

    cin.get();
    return 0;
}

/* output：
上善若水。
水善利万物而不争，
处众人之所恶，故几于道。
We are the world!
we are the one!
知善知恶
为善去恶
知行合一
上善若水。
水善利万物而不争，
处众人之所恶，故几于道。

上善若水。
水善利万物而不争，
处众人之所恶，故几于道。
上善若水。
水善利万物而不争，
处众人之所恶，故几于道。
上善若水。
水善利万物而不争，
处众人之所恶，故几于道。

https://ask.csdn.net/questions/690685
https://blog.csdn.net/qq_36743440/article/details/91999615
http://www.cplusplus.com/reference/cstring/strtok/
http://www.cplusplus.com/faq/sequences/strings/split/
*/

#if 0
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<string> split(string str, char del) {
	stringstream ss(str);
	string temp;
	vector<string> ret;
	while (getline(ss, temp, del)) {
		ret.push_back(temp);
	}
	return ret;
}

int main()
{
    string str  = "上善若水。\n水善利万物而不争，\n";
		   str += "处众人之所恶，故几于道。\n";
	 
    vector<string> vec = split(str,'\n');

	vector<string>::iterator vit=vec.begin();
    for(;vit!=vec.end();vit++)
    {
        printf("%s\n", (*vit).c_str());
    } 
    cin.get();
	return 0;
}
#endif