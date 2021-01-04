// generate algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::generate
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

// function generator:
int RandomNumber () { return (rand()%100); }

// class generator:
struct c_unique 
{
    int current;
    c_unique() {current=0;}
    int operator()() {return ++current;}
} UniqueNumber;

int main () 
{
    srand ( unsigned ( time(0) ) );
    
    std::vector<int> myvector (8);
    
    std::generate (myvector.begin(), myvector.end(), RandomNumber);
    
    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    
    std::generate (myvector.begin(), myvector.end(), UniqueNumber); // ×´Ì¬¼ÇÒä
    
    std::cout << "myvector contains:";
    for (it=myvector.begin(); it!=myvector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    getchar();
    return 0;
}
/*
myvector contains: 65 59 1 96 74 94 22 29
myvector contains: 1 2 3 4 5 6 7 8
*/