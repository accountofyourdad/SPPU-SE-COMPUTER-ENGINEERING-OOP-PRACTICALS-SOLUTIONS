/*Write C++ program using STL for sorting and searching user defined records such as
 personal records (Name, DOB, Telephone number etc) using vector container. OR
 Write C++ program using STL for sorting and searching user defined records such as
 Item records (Item code, name, cost, quantity etc) using vector container.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; // NOTE!!  Whenever the deal is with (const item & obj) we have to deal with object.variable as we have const in (const item & i1)
class item
{ // (item & object) in this case we deal with objects nothing other than that ahead any thing can happen object.variable or else any thing
public:
    char name[10];
    int cost, quantity, code;
    bool operator==(const item &i1) // overloading operator == ,here after value after == will be object.variable of class item as((const item & i1))
    {                               // left object.variable will be compared with right object.variable
        if (code == i1.code)
            return 1;
        else
            return 0;
    }
    bool operator<(const item &i1) // overloading operator < ,here after value after < will be object.variable of class item as((const item & i1))  will be compared with left side of <
    {                              //// left object.variable will be compared with right object.variable
        if (code < i1.code)        // means l.h.s obj.var is smaller than r.h.s obj.var
            return 1;
        else
            return 0;
    }
};
vector<item> v1;      // vector with datatype class(item) i.e the vector will be the array of obj of class item
void print(item &i1); // here (item &) only can work i1 just is an object
void display();
void insert();
void search();
void del(); // del as delete is inbuilt function
bool compare(const item &i1, const item &i2)        //comparing two objects based on there cost bosed on that the list is sorted
{
    return i1.cost < i2.cost; // returns 1 if true else 0       //sorts withrespect to cost
}
int main()
{
    int ch;
    do
    {
        cout << "------------------menu---------------------" << endl;
        cout << "Enter your Choice below accordingly  :" << endl;
        cout << "  1.insert" << endl;
        cout << "  2.display" << endl;
        cout << "  3.search" << endl;
        cout << "  4.sort" << endl;
        cout << "  5.delete" << endl;
        cout << "  6.EXIT" << endl;
        cout << "--->" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;
        case 4:
            sort(v1.begin(), v1.end(), compare);    //sort is function that takes 3 arguments (begin,end,whichFunctionToExecute)
            cout << "\n\n Sorted on Cost : ";       //sort(v1.begin(), v1.end(), compare); this is generaly done for {[a,b],[c,d],[e,f]} for comparing internal as here comparing cost
            display();
        case 5:
            del();
            break;
        case 6:
            exit(0); // whole program exits
        }
    } while (ch < 7 && ch > 0);
}
void insert()
{
    item i1; // no matter how many times you declared i1 in program just make sure it is in local scope
    cout << "enter Iteam name :";
    cin >> i1.name;
    cout << "\nenter Iteam code :";
    cin >> i1.code;
    cout << "\nenter Iteam cost :";
    cin >> i1.cost;
    cout << "\nenter Iteam quantity :";
    cin >> i1.quantity;
    v1.push_back(i1); // push_back is inbuilt function    here iteam's obj is pushed at the end of the vector name v1
}
void display()
{                                          // `|` this for_each is bulit in function in vector
    for_each(v1.begin(), v1.end(), print); // for each obj (of class) in vector from .begin() to .end() execute function print() below(declared)
}
void print(item &i1)
{
    cout << "\n name of item : " << i1.name;
    cout << "\n code of item : " << i1.code;
    cout << "\n cost of item : " << i1.cost;
    cout << "\n quantity of item : " << i1.quantity<<endl;
}
void search()
{
    vector<item>::iterator p; // instead of declaring new vector of class intem declared an iterater for traversing
    item i1;                  // iterator traverse element of vector and represent itself as it for some time and goes ahead from element to element
    cout << "\n code of item to search : ";
    cin >> i1.code;                     //.begin point to the first element of vector       //.end points to the next of the last element
    p = find(v1.begin(), v1.end(), i1);     // its basically find the element and give value to the iterator p  // look for the i1 in the vector with the help of the i1.code from begining to end and if found than point iterator to the obj i.e the element of vector     if not found points to next of the last element
    if (p == v1.end())                  // basically the .end() point to the next of the last element i.e is empty that means the element not found from first to last so pointing to noting(.end)
        cout << "\nnot found";          // find(begin,end,const index & i1)  3rd parameter will be what to be find here working with object so i1 passed   //note we are working with values inside class so used const as for working with i1.cost
    else
        cout << "\n!! FOUND !!";
}
void del()
{
    vector<item>::iterator p;
    item i1;
    cout << "\n enter element to be deleted :";
    cin >> i1.code;
    p = find(v1.begin(), v1.end(), i1);
    if (p == v1.end())
        cout << "\n not found";
    else
    {
        v1.erase(p);            // note that is the iterater is been deleted not the obj of item aas iterator point at that place and is been erase i.e the position of the obj that means the element is deleted
        cout << "\ndeleted !!"; // erase is builtin fn in vector  takes what to delete as an iterator pointing to it (the element in the vector)
    }
}