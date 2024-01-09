/*
Write a function template selection sort. Write a program that inputs, sorts
and outputs an int array and a float array.
*/

#include <iostream>
using namespace std;

template <class T>
        //  for simplicity just assume any data type instead of that T as it is declared afterwords what it is 
void selection_sort()      //    function selection_sort with return later to be declared       //after assuming T as int the code seems to be more familier
{                                  //after assuming T as int the code seems to be more familier
    int n;
    cout << "Enter no of elements";
    cin >> n;
    T a[n];
    
    for (int i = 0; i < n; i++) // Accepting elements
    {
        cout << "a[" << i << "]=";
        cin >> a[i];                //arrey of datatype T   
    }
    int tem;                // for selection sort   // than j traverse from | .......here.......to here......| for finding lowest number in the array
    for (int i = 0; i < n; i++)      // Sorting logic             __a__   __b__   __c__   __d__   __e__   __f__  
    {                                            //  at first tem at ^ and than transversed by for loop
        tem = i;            //done like this so that i must not be lost
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[tem]) {        //Find the minimum element in the unsorted part of the array and swap it with the first element 
                tem = j;                //find the smallest and swipe with ith element
            }
        }
        swap(a[i], a[tem]);
    }

    for (int i = 0; i < n; i++) // Displaying logic
    {
        cout << a[i] << " ";
    }
}

int main()
{

    int c;
    cout << "\n --------- MENU ---------";
    cout << "\n 1. for interger Sorting ";
    cout << "\n 2. for floating Sorting ";
    cout << "\n 3. for string Sorting ";
    cout << "\n Enter your choice : ";
    cin >> c;
    switch (c)
    {
    case 1:
        cout << "Integer sorting...\n";

        selection_sort<int>();          //pass from here what you want in this class instead of template T  in <datatype>
        break;
    case 2:

        cout << "Floating sorting...\n";

        selection_sort<float>();        //pass from here what you want in this class instead of template T  in <datatype>
        break;
    case 3:

        cout << "char sorting...\n";

        selection_sort<string>();       //pass from here what you want in this class instead of template T  in <datatype>
        break;
    }
}