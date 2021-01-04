#include <iostream>
using namespace std;

class Outer
{
public:
    class Inner
    {
        friend class Outer;  //Outer是Inner的友元类
    public:
        void func(const Outer &outer) const
        {
            cout << "I'm Inner." << endl;
            cout << "He's " << outer.name << endl;
        }
    private:
        const char *const name = "Inner";
    };

    void func(const Inner &inner) const
    {
        cout << "I'm Outer." << endl;
        cout << "He's " << inner.name << endl;
    }

private:
    const char *const name = "Outer";
};

int main()
{
    Outer().func(Outer::Inner());
    cout << endl;
    Outer::Inner().func(Outer());
    return 0;
}