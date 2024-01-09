/*
Write a C++ program that creates an output file, writes information to it, 
closes the file and open it again as an input file and read the information 
from the file
*/

#include <iostream>
#include <fstream>

using namespace std;
 
int main()
{
   fstream file; //object of fstream class      //is the obj that does all the job
    
   file.open("sample.txt",ios::out);        //opening file "sample.txt" in out(write) mode(as ::in means in writing mode )
    
   if(!file)
   {
       cout<<"Error in creating file!!!"<<endl;
       return 0;
   }
    
   cout<<"File created successfully."<<endl;        //create file if not existing earlier
   
   file<<"ABCD.";               //write text into file
   
   file.close();                //closing the file
    
   file.open("sample.txt",ios::in);         //again open file in read mode(as ::in means in reading mode )
    
   if(!file)
   {
       cout<<"Error in opening file!!!"<<endl;
       return 0;
   }   
    
   
   char ch; //to read single character at a time
   cout<<"File content: ";
    
   while(!file.eof())               //read untill end of file is not found.        eof() means end of file
   {
       file>>ch;     //stores to ch var form file           //read single character from file
       cout<<ch;
   }
    
   file.close();            //close file
    
   return 0;
}