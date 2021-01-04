#include <iostream>
#include <map> // 二叉树映射，映射也叫字典，不是哈希映射
#include <vector>
#include <string>
using namespace std;

template<typename Key, typename Value>
class LinearMap
{
public:
    LinearMap(int size=101) : arr(size)
    {
        currentSize = 0;
    }
    
    void Put(const Key& k, const Value& v)
    {
        arr[currentSize] = DataEntry(k,v);
        ++currentSize;
    }
    
    Value Get(const Key& k)  // 相对于红黑树的搜索，线性查找要慢很多
    {
        for(size_t i=0; i<currentSize; ++i)
        {
            if(arr[i].key == k)
                return arr[i].value;
        }
        return Value();
    }
private:
    struct DataEntry{
        Key key;
        Value value;
        DataEntry(const Key& k = Key(),
                  const Value& v = Value()):
        key(k),value(v){}
    };
    std::vector<DataEntry> arr;
    int currentSize;
};

int main()
{
    map<string,int> m;
    m["bill"] = 98;
    m["Tom"] = 67;
    m["Mary"] = 100;
    // ……
    cout<< m["Tom"] <<endl;
    
    LinearMap<string, int> lm;
    lm.Put("Bill",99);
    lm.Put("Tom",88);
    lm.Put("Mary",77);
    cout<<lm.Get("Tom")<<endl;
    cout<<""<<endl;
    system("pause");
    return 0;
}
