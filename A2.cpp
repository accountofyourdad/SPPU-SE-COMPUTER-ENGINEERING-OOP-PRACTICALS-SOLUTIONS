/*
Develop an object oriented program in C++ to create a database of student
information system containing the following information: Name, Roll
number, Class, division, Date of Birth, Blood group, Contact address,
telephone number, driving license no. etc Construct the database with
suitable member functions for initializing and destroying the data viz
constructor, default constructor, Copy constructor, destructor, static member
functions, friend class, this pointer, inline code and dynamic memory
allocation operators-new and deletE

*/

#include <iostream>
#include <string.h> // this for using strcopy
using namespace std;
class student
{
public:
  int roll_no;
  char clas[10];
  int sr_no;
  long int tele_no;
  char name[20];
  char div;
  char blood_grp[3];
  char DOB[10];
  static int count; // declared static so that cannot loose value        //value dont changes even in other obj of same class
  // The static keyword can be used to declare variables and functions at global scope, namespace scope, and class scope.

  void getdata();
  friend void display(student &obj);
  inline void fin() { cout << "\nInline Function!"; } // C++ provides inline functions to reduce the function call overhead. An inline function is a function that is expanded in line when it is called

  student() // default Constructor
  {
    roll_no = 0;
    cout << "\tConstructor";
    roll_no = count; // just initialize it
    count++;         // counting no of times the obj created
  }

  ~student() // Destructor
  {
    cout << "\nDestructor";
    cout << "\n\n"
         << this->name << "(Object) is destroyed!";
    cout << "\nDestroying the object";
    count--;
  }

  student(int roll_no) // parameterized constructer
  {
    this->roll_no = roll_no;
  }

  student(student &obj) // copy constructer
  {
    roll_no = obj.roll_no;
    strcpy(name, obj.name);
    strcpy(DOB, obj.DOB);
    strcpy(clas, obj.clas);
    strcpy(blood_grp, obj.blood_grp); // if blood group is char[n] will require strcpy
    // blood_grp=obj.blood_grp;        //if blood group is char
    div = obj.div;
    tele_no = obj.tele_no;
    sr_no = count;
    count++;
  }
};
int student ::count = 0; // declare outside only or else exit with error 1
void student::getdata()
{
  cout << "\n"
       << "Enter the roll number of the student:";
  cin >> roll_no;

  cout << "\n"
       << "Enter the name of the student:";
  cin >> name;

  cout << "\n"
       << "Enter the date of birth of the student:";
  cin >> DOB;

  cout << "\n"
       << "Enter the blood group of the student:";
  cin >> blood_grp;

  cout << "\n"
       << "Enter the class of the student:";
  cin >> clas;

  cout << "\n"
       << "Enter the division of the student:";
  cin >> div;

  cout << "\n"
       << "Enter the contact of the student:";
  cin >> tele_no;
}
void display(student &obj)
{
  cout << "\n"
       << obj.roll_no;
  cout << "\t" << obj.name;
  cout << "\t" << obj.DOB;
  cout << "\t" << obj.blood_grp;
  cout << "\t" << obj.clas;
  cout << "\t" << obj.div;
  cout << "\t" << obj.tele_no;
}

int main()
{

  student s1;
  cout << "\n Enter the details of a student below ";
  s1.getdata();

  cout << "\nAll data is as displayed below:"
       << "\n";
  cout << "\n---------------------------------------------------------------------";
  cout << "\nROLL NUMBER\tNAME\tDOB\tBLOOD GRP\tCLASS\tDIVISION\tCONTACT NUMBER";
  display(s1); // void datatype
  cout << "\n---------------------------------------------------------------------";

  student s2(s1); // copy things from s1 to s2
  cout << "\ncopy constructer involk bellow is the data copied" << endl;
  cout << "\n---------------------------------------------------------------------";
  cout << "\nROLL NUMBER\tNAME\tDOB\tBLOOD GRP\tCLASS\tDIVISION\tCONTACT NUMBER";
  display(s2);
  cout << "\n---------------------------------------------------------------------";
  int i, n;

  student *s[50];
  cout << "\nEnter how many student object do you want us to create?"
       << "\n";
  cin >> n;

  for (i = 0; i < n; i++)
  {
    s[i] = new student();
  }

  for (i = 0; i < n; i++)
  {
    s[i]->getdata();
    cout << "now enter next student details";
  }

  for (i = 0; i < n; i++)
  {
    display(*s[i]);
  }

  for (i = 0; i < n; i++)
  {
    delete (s[i]);
  }
  return 0;
}