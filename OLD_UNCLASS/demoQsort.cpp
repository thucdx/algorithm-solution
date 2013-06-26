#include <iostream>
using namespace std;
#include <stdlib.h>
#include <conio.h>
#include <string.h>
struct person
{
 string name;
 int age;
 double salary;
 person()
 {};
 person(string n, int a, double sal)
 {
  name=n;
  age=a;
  salary=sal;            
 }      
 void set(string n, int a, double sal)
 {
  name=n;
  age=a;
  salary=sal;            
 }      
};
int compare( const void* a, const void *b)
{
 return (* (int*)a- *(int*) b );
}
int compareName( const void *a, const void *b)
{
 return (*(string*)a >*(string*)b);    
}
int compareSal(const void *a, const void *b)
{
 struct person *ia= (person *) a;
 struct person *ib= (person *) b;
 double rs= (ia->salary -ib->salary);
 if(rs>0) return 1;
 else if(rs==0) return 0;
 else return -1;
}
void display(person* a)
{
     int i;
      for(i=0;i<4 ;i++)
           cout<<a[i].name<<' ';
      cout<<endl;                 
}
int main()
{
 //int a[]={-3,4,5,20,45,-45,4566,566,4,432,324,34}    ;
 //qsort(a,sizeof(a)/sizeof(a[0]),sizeof(a[0]),compare);
 //display();
 person a[4];
 a[0].set("Thuc",15,300.3);
 a[1].set("Hai",16,450.3);
 a[2].set("Thanh",24,355.3);
 a[3].set("Tu",24,344);
 cout<<":";
 display(a);
 cout<<":";
 qsort(a,4,sizeof(a[0]),compareSal);
 display(a);
 getch();
}
