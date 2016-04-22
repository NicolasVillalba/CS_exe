#include<iostream>
#include<string.h>
using namespace std;

class Student
{
private:
 char *name;
    int id;

public:

    Student(char *pName="no name",int ssId=0)
    {
        id=ssId;
        name=new char[strlen(pName)+1];
        strcpy(name,pName);
        cout<<"construct new student "<< endl;
    }
    
    void copy(Student &s)
    {
        if (this==&s)
        {
            cout<<"Erro:can't copy one to oneself!"<< endl;
            return;
       }else
       {
            name=new char[strlen(s.name)+1];
            strcpy(name,s.name);
            id=s.id;
            cout<<"the function is deposed!" << endl;
        }
    }
    
    void disp()
    {
        cout<<"Name:"<<  name << endl;
    }
    
    ~Student()
    {
        cout<<"Destruct "<<endl;
        delete name;
    }
};

int main()
{
  Student a("Joe",12),b("Tom",23);
  a.disp();
  b.disp();
  a.copy(a);
  b.copy(a);
  a.disp();
  b.disp();
  return 0;
}

