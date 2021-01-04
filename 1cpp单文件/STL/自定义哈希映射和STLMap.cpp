#include <iostream>
#include <map> // 二叉树映射，映射也叫字典，不是哈希映射
//#include <hash_map>
#include <vector>
#include <string>
using namespace std;

template<typename Key, typename Value>
class HashMap // 将字符串通过哈希函数映射为数据下标
{
public:
	HashMap(int size=101) : arr(size)
	{
		currentSize = 0;
	}
	void Put(const Key& k, const Value& v)
	{
		int pos = myhash(k);
		arr[pos] = DataEntry(k,v);
		++currentSize;
	}
	Value Get(const Key& k)
	{
		int pos = myhash(k);
		if(arr[pos].key == k)
			return arr[pos].value;
		else
			return Value();
	}

	unsigned hash(const Key& k) const
	{
		unsigned int hashVal = 0;
		const char* keyp = reinterpret_cast<const char*>(&k);
		for(size_t i=0; i<sizeof(k); i++)
			hashVal = 37*hashVal + keyp[i];
		return hashVal;
	}
	int myhash(const Key& k) const
	{
		unsigned hashVal = hash(k);
		hashVal %= arr.size();
		return hashVal;
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
	
	HashMap<string, int> hm;
	hm.Put("Bill",99);
	hm.Put("Tom",88);
	hm.Put("Mary",77);
	cout<<hm.Get("Tom")<<endl;

	cout<<hm.hash("Bill")<<endl;
	cout<<hm.myhash("Bill")<<endl;

	//hash_map<string,int> hm2;
	//hm2["Bill"] = 33;
	//hm2["Mary"] = 44;

	//cout<<hm2["Mary"]<<endl;
	cout<<""<<endl;
    system("pause");
	return 0;
}
