// author : Hou Jie (���)
// date : 2015/10/28 
// compiler : DevC++ 5.11 (MinGW with GNU 4.9.9.2)
//
// �f�����@�Ǻ�� E-learning video "C++�˜ʎ�" �Č�����ʽ.
// ԓ�n�̵����Мyԇ�����F�ڴ�.
// ÿһ��С�yԇ��Ԫ�������Mһ�� namespace ��, 
// ��˱��ָ���Ԫ�g���Ī�����.
// ÿ�� namespace �Ϸ�����ԓ��Ԫ������ #include <...> 
// ����п���������ʽ���}���� (included) ĳЩ headers. 
// �@�o���^�����ÿ�� standard headers �������ҷ��l�C�ƣ���׌�Լ��� included ����.
//
// ���ļ��õ����� C++ 2.0 New Features��������������ļ��ɭh�� (IDE) ���O�� "C++11 on". 
// �����ľ��g�����e������������õ� (�yԇ) GNU �˜ʎ�Ī��� (�ǘ˜�) �M�� (�؄e�� allocators)��
// �����e�Z��Ğ��]�� (comments) ����ͨ�^���g. 

//---------------------------------------------------
#include <cstdlib> //rand() and RAND_MAX
namespace jjxx
{
void test_containers()
{
int choice;
long value;  
     
    srand(time(NULL));
 
    cout << "\n\ntest_containers()......... \n";
    cout << "select: \n";
    cout << "       (1)array (2)vector (3)list (4)forward_list (5)deque (6)multiset \n";
    cout << "       (7)multimap (8)unordered_multiset (9)unordered_multimap (10)slist \n";
    cout << "       (11)hash_multiset (12)hash_multimap (13)set (14)map (15)unordered_set \n";
    cout << "       (16)unordered_map (17)stack (18)queue \n";    
    cout << " (2),(3),(5),(6),(8) will test also moveable elements. \n"; 
    cin >> choice;
    if ( choice != 1 ) {    //1 ==> array, use ASIZE
        cout << "how many elements: ";
        cin >> value;         
    }
 
    switch (choice) 
    {
        case 1 :    jj01::test_array();     
                    break;
        case 2 :    jj02::test_vector(value);   
                    //jj02::test_vector_with_move(value);   
                    break;      
        case 3 :    jj03::test_list(value);
                    break;      
        case 4 :    jj04::test_forward_list(value); 
                    break;      
        case 5 :    jj05::test_deque(value);        
                    break;      
        case 6 :    jj06::test_multiset(value); 
                    break;      
        case 7 :    jj07::test_multimap(value); 
                    break;          
        case 8 :    jj08::test_unordered_multiset(value);       
                    break;      
        case 9 :    jj09::test_unordered_multimap(value);   
                    break;  
        case 10:    jj10::test_slist(value);    
                    break;                  
        case 11:    jj11::test_hash_multiset(value);        
                    break;      
        case 12:    jj12::test_hash_multimap(value);    
                    break;  
        case 13 :   jj13::test_set(value);  
                    break;      
        case 14 :   jj14::test_map(value);  
                    break;          
        case 15 :   jj15::test_unordered_set(value);        
                    break;      
        case 16 :   jj16::test_unordered_map(value);
                    break;          
        case 17 :   jj17::test_stack(value);        
                    break;      
        case 18 :   jj18::test_queue(value);    
                    break;                                                              
        default: 
                    break;      
    }
}
}
//---------------------------------------------------
#include <cstdlib> //rand() and RAND_MAX
int main(int argc, char** argv) 
{
    jj00::test_misc();      
         
    jjxx::test_containers();
     
    jj20::test_list_with_special_allocator();   
    jj25::test_components_sizeof(); 
    jj30::test_all_components();
    jj31::test_Rb_tree();   
    jj32::test_Hashtable();
     
    jj33::test_iterator_category();
    jj34::test_accumulate();
    jj35::test_for_each();  
    jj36::test_sort();  
         
    return 0;
}