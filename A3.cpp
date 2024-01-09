//BOOKSTORE IMAGINATION OOP

#include<iostream>
#include<stdio.h>       //by this we can use string data type in this program
using namespace std;
class publication{ 
    string title;
    float price;
    public:
    void add(){
        cout<<"enter the publication information below \n";
        cout<<"enter title of publication : "; 
        cin>>title;   
         //getline function is used instead of cin for strings
         //here getline takes two arg one as cin and other as the variable it is to be stored 
        cout<<"\nenter price of publication : ";
        cin>>price;
    }
    void display(){
        cout<<"\n ----------------------------\n";
        cout<<"title of publication : "<<title<<endl;
        cout<<"price of publication : "<<price<<endl;
    }
};
class book : public publication{ 
    int page_count;
    public:
    void addbook(){
        try{
            add();      //will call add function of the parent(base class)   ...not a inbuild function
            cout<<"\nenter page count of the book : ";
            cin>>page_count;
            if(page_count <= 0 ){
                throw page_count;
            }
        }
        catch(...){         //here it will get any thing thrown 
            cout<<"invalid page count \n";
            page_count = 0;
        }
    }
    void diaplay_book(){
        display();      //will call display function of the parent(base class)   ...not a inbuild function
        cout<<"page count of the book is : "<<page_count<<endl;
        cout<<"\n ---------------------------";
    }
};

class tape : public publication{ 
    float minutes;
    public:
    void addtape(){
        try{
            add();      //will call add function of the parent(base class)   ...not a inbuild function
            cout<<"\nenter minute count of the tape : ";
            cin>>minutes;
            if(minutes <= 0 ){
                throw minutes;
            }
        }
        catch(...){         //here it will get any thing thrown 
            cout<<"invalid page count \n";
            minutes = 0;
        }
    }
    void diaplay_tape(){
        display();      //will call display function of the parent(base class)   ...not a inbuild function
        cout<<"minute count of the tape is : "<<minutes;
        cout<<"\n ---------------------------";
    }
};

int main(){ 
    book obj_book[5];   //arrey of object
    tape obj_tape[5];   //arrey of object
    int x , b_count = 0 , t_count = 0 ;
    do
    {
        cout<<"\n------------------ menu ------------------";
        cout<<"\n  1. add info to books";
        cout<<"\n  2. add info to tape";
        cout<<"\n  3. display info of books";
        cout<<"\n  4. display info of tape";
        cout<<"\n  5. EXIT \n";
        cout<<"ENTER YOUR CHOICE FROM ABOVE -->";
        cin>>x;
        switch (x)
        {
        case 1:
            obj_book[b_count].addbook();
            b_count++;
            break;
        
        case 2:
            obj_tape[t_count].addtape();
            t_count++;
            break;
        
        case 3:
            for(int i = 0 ; i < b_count ; i++){
                obj_book[i].diaplay_book();
            }
            break;
        
        case 4:
            for(int i = 0 ; i < t_count ; i++){
                obj_tape[i].diaplay_tape();
            }
            break;
        
        case 5:
            cout<<"thank U ...";
            exit(0);        //exits the program. it just means program executed without any error or interupt 

        }
    } while ( 0 < x && x < 5 );
    return 0;
}