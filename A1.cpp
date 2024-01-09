#include<iostream>
using namespace std;
class complex{
	float real,img;
	public:
	complex();          //constructer
	friend istream &operator >>(istream &, complex &);          // declaration of function defination below
	friend ostream &operator <<(ostream &, complex &);          // declaration of function defination below
	complex operator+(complex);         // declaration of function defination below
	complex operator*(complex);         // declaration of function defination below
};
complex::complex(){
	img = 0;
	real = 0;
}
ostream &operator <<(ostream &out, complex &obj){           // note that object of ostream used
	out<<obj.real<<" +"<<obj.img<<"i"<<endl;
	return out;
}

istream &operator >>(istream &in, complex &obj){            // note that object of istream used
	in>>obj.real;
	in>>obj.img;
	return in;
}

complex complex ::operator+(complex c1){
	complex temp;
	temp.real = real + c1.real;
	temp.img = img + c1.img;
	return temp;
}

complex complex ::operator*(complex c2){
	complex temp1;
	temp1.real = real * c2.real;
	temp1.img = img * c2.img;
	return temp1;
}
int main(){
	complex c1,c2,c3,c4,c5;
	char b;
	int flag = 1, a;
    cout<<"by using constructer we have: "<<c5<<endl;
	cout<<"enter first complex number"; cin>>c1;
	cout<<"enter secound complex number"; cin>>c2;
	int f = 1;
	while(f==1){
	cout<<"-----------menu --------------"<<endl;
	cout<<"-----------1. addition --------------"<<endl;
	cout<<"-----------2. multiplication --------------"<<endl;
	cout<<"-----------3. exit --------------"<<endl;
	cin>>a;
	switch(a) {
case 1:	
	c4 = c1 + c2;
	cout<<"addition is: "<<c4<<endl;
	cout<<"y or n"<<endl;
	cin>>b;
	if(b=='y' || b=='Y' ){
	f=1;}
	else{ f= 0; break;}
	// code block
	break;

case 2:
	c4 = c1 * c2;
	cout<<"multi : "<<c4<<endl;
	cout<<"y or n"<<endl;
	cin>>b;
	if(b=='y' || b=='Y' ){
	f=1;}
	else{ f= 0;break;}
	break;

// code block
case 3:
	f= 0;
	break;
// code block
default:
	cout<<"enter valid input"<<endl;
	break;
}
}
}