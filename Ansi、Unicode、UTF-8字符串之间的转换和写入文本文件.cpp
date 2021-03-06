/*
Ansi字符串我们最熟悉，英文占一个字节，汉字2个字节，以一个\0结尾，常用于txt文本文件。
Unicode字符串，每个字符(汉字、英文字母)都占2个字节，以2个连续的\0结尾，NT操作系统内核用的是这种字符串，常被定义为typedef unsigned short wchar_t;
所以我们有时常会见到什么char*无法转换为unsigned short*之类的错误，其实就是unicode。
UTF8是 Unicode一种压缩形式，英文A在unicode中表示为0x0041，老外觉得这种存储方式太浪费，因为浪费了50%的空间，于是就把英文压缩成1 个字节，
成了utf8编码，但是汉字在utf8中占3个字节，显然用做中文不如ansi合算，这就是中国的网页用作ansi编码而老外的网页常用utf8 的原因。
UTF8在还游戏里运用的很广泛，比如WOW的lua脚本等。

下面来说一下转换，主要用代码来说明吧

写文件我用了CFile类，其实用FILE*之类的也是一样，写文件和字符串什么类别没有关系，硬件只关心数据和长度。

Ansi转Unicode

介绍2种方法
UTF-8-bom
标识位：0XBFBBEF（3个字节）
换 行符：0x0A0D
汉字采用三个字节编码
UTF-8
标识位：无
换行符：0X0A0D
汉字采用三个字节编码
Unicode Big Endian(UTF-16/UCS-2大端字节序
Unicode little Endian(UTF-16/UCS-2小端字节序
标识位：0xFFFE
换行符标识位：0x0A000D00
汉字编码：采用2个字节
*/
void CConvertDlg::OnBnClickedButtonAnsiToUnicode()
{
    // ansi to unicode
    char* szAnsi = "abcd1234你我他";
    //预转换，得到所需空间的大小
    int wcsLen = ::MultiByteToWideChar(CP_ACP, NULL, szAnsi, strlen(szAnsi), NULL, 0); //#include <windows.h>
    //分配空间要给'\0'留个空间，MultiByteToWideChar不会给'\0'空间
    wchar_t* wszString = new wchar_t[wcsLen + 1];
    //转换
    ::MultiByteToWideChar(CP_ACP, NULL, szAnsi, strlen(szAnsi), wszString, wcsLen);
    //最后加上'\0'
    wszString[wcsLen] = '\0';
    //unicode版的MessageBox API
    ::MessageBoxW(GetSafeHwnd(), wszString, wszString, MB_OK);

    //接下来写入文本
    //写文本文件，头2个字节0xfeff，低位0xff写在前
    CFile cFile;
    cFile.Open(_T("1.txt"), CFile::modeWrite | CFile::modeCreate);
    //文件开头
    cFile.SeekToBegin();
    cFile.Write("\xff\xfe", 2);
    //写入内容
    cFile.Write(wszString, wcsLen * sizeof(wchar_t));
    cFile.Flush();
    cFile.Close();
    delete[] wszString;
    wszString =NULL;


    //方法2
    //设置当前地域信息，不设置的话，使用这种方法，中文不会正确显示
    //需要#include<locale.h>
    setlocale(LC_CTYPE, "chs");
    wchar_t wcsStr[100];
    //注意下面是大写S，在unicode中，代表后面是ansi字符串
    //swprintf是sprintf的unicode版本
    //格式的前面要加大写L，代表是unicode
    swprintf(wcsStr, L"%S", szAnsi);
    ::MessageBoxW(GetSafeHwnd(), wcsStr, wcsStr, MB_OK);

}

//Unicode转Ansi
//也是2种方法
void CConvertDlg::OnBnClickedButtonUnicodeToAnsi()
{
    // unicode to ansi
    wchar_t* wszString = L"abcd1234你我他";
    //预转换，得到所需空间的大小，这次用的函数和上面名字相反
    int ansiLen = ::WideCharToMultiByte(CP_ACP, NULL, wszString, wcslen(wszString), NULL, 0, NULL, NULL);
    //同上，分配空间要给'\0'留个空间
    char* szAnsi = new char[ansiLen + 1];
    //转换
    //unicode版对应的strlen是wcslen
    ::WideCharToMultiByte(CP_ACP, NULL, wszString, wcslen(wszString), szAnsi, ansiLen, NULL, NULL);
    //最后加上'\0'
    szAnsi[ansiLen] = '\0';
    //Ansi版的MessageBox API
    ::MessageBoxA(GetSafeHwnd(), szAnsi, szAnsi, MB_OK);

    //接下来写入文本
    //写文本文件，ANSI文件没有BOM
    CFile cFile;
    cFile.Open(_T("1.txt"), CFile::modeWrite | CFile::modeCreate);
    //文件开头
    cFile.SeekToBegin();
    //写入内容
    cFile.Write(szAnsi, ansiLen * sizeof(char));
    cFile.Flush();
    cFile.Close();
    delete[] szAnsi;
    szAnsi =NULL;


    //方法2
    //和上面一样有另一种方法
    setlocale(LC_CTYPE, "chs");
    char szStr[100];
    //注意下面是大写，在ansi中，代表后面是unicode字符串
    //sprintf
    sprintf(szStr, "%S", wszString);
    ::MessageBoxA(GetSafeHwnd(), szStr, szStr, MB_OK);
}

//Unicode转UTF8
void CConvertDlg::OnBnClickedButtonUnicodeToU8()
{
    // unicode to UTF8
    wchar_t* wszString = L"abcd1234你我他";
    //预转换，得到所需空间的大小，这次用的函数和上面名字相反
    int u8Len = ::WideCharToMultiByte(CP_UTF8, NULL, wszString, wcslen(wszString), NULL, 0, NULL, NULL);
    //同上，分配空间要给'\0'留个空间
    //UTF8虽然是Unicode的压缩形式，但也是多字节字符串，所以可以以char的形式保存
    char* szU8 = new char[u8Len + 1];
    //转换
    //unicode版对应的strlen是wcslen
    ::WideCharToMultiByte(CP_UTF8, NULL, wszString, wcslen(wszString), szU8, u8Len, NULL, NULL);
    //最后加上'\0'
    szU8[u8Len] = '\0';
    //MessageBox不支持UTF8,所以只能写文件

    //接下来写入文本
    //写文本文件，UTF8的BOM是0xbfbbef
    CFile cFile;
    cFile.Open(_T("1.txt"), CFile::modeWrite | CFile::modeCreate);
    //文件开头
    cFile.SeekToBegin();
    //写BOM，同样低位写在前
    cFile.Write("\xef\xbb\xbf", 3);
    //写入内容
    cFile.Write(szU8, u8Len * sizeof(char));
    cFile.Flush();
    cFile.Close();
    delete[] szU8;
    szU8 =NULL;

}

//UTF8转UNICODE
void CConvertDlg::OnBnClickedButtonU8ToUnicode()
{
    //UTF8 to Unicode
    //由于中文直接复制过来会成乱码，编译器有时会报错，故采用16进制形式
    char* szU8 = "abcd1234\xe4\xbd\xa0\xe6\x88\x91\xe4\xbb\x96\x00";
    //预转换，得到所需空间的大小
    int wcsLen = ::MultiByteToWideChar(CP_UTF8, NULL, szU8, strlen(szU8), NULL, 0);
    //分配空间要给'\0'留个空间，MultiByteToWideChar不会给'\0'空间
    wchar_t* wszString = new wchar_t[wcsLen + 1];
    //转换
    ::MultiByteToWideChar(CP_UTF8, NULL, szU8, strlen(szU8), wszString, wcsLen);
    //最后加上'\0'
    wszString[wcsLen] = '\0';
    //unicode版的MessageBox API
    ::MessageBoxW(GetSafeHwnd(), wszString, wszString, MB_OK);

    //写文本同ansi to unicode
}

//Ansi转换utf8和utf8转换Ansi就是上面2个的结合，把unicode作为中间量，进行2次转换即可
