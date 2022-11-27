#include <iostream>
#include <cstring>
using namespace std;
int ent=5;
class student{
    string Sname;
    int c_num;
    string ID_No;
public:
    void Read(){
        cout<<"Enter Student name: ";
        cin>>Sname;
        cout<<"Enter card number: ";
        cin>>c_num;
        cout<<"Enter ID_No: ";
        cin>>ID_No;
    }
    void display(){
        cout<<"Student name:"<<Sname;
        cout<<"card number:"<<c_num;
        cout<<"ID_No:"<<ID_No;
    }

};
class UGStudent : public student{
    string  electivesubject;
public:
    void readUG(){
        cout<<"Enter Name of the Elective subject: ";
        cin>>electivesubject;
    }
    void DisplayUG(){
        cout<<"Elective subject: ";
        cin>>electivesubject;
    }
};
class PGStudent : public student{
    string specialization;
public:
    void readPG(){
        cout<<"Enter specialization: ";
        cin>>specialization;
    }
    void DisplayPG(){
        cout<<endl<<"Specialization: ";
        cin>>specialization;
    }
};
class book{
    string ISBN,title,author;
    int No_copies,Issued;
public:
    int check_ISBN(){
        if(isdigit(ISBN[0])&&isdigit(ISBN[2])&&isdigit(ISBN[4])&&ISBN[1]=='-'&&ISBN[3]=='-'&&ISBN[5]=='-'&&isdigit(ISBN[6])||isalpha(ISBN[6])){
            return 1;
        }
        else{
            return 0;
        }
    }
    void Read(){          
        cout<<"Enter Name of the book: ";
        cin>>title;
        cout<<"Enter Author of the book: ";
        cin>>author;
        cout<<"Enter ISBN of the book: ";
        cin>>ISBN;
        while(!(check_ISBN())){
            cout<<"The entered ISBN number is invalid!!";
            cin>>ISBN;
        }
        cout<<"Enter Number copies of the book:";
        cin>>No_copies;
    }
    void Display(){
        cout<<"name of the book: "<<title<<endl;
        cout<<"Author of the book: "<<author<<endl;
        cout<<"ISBN of the book: "<<ISBN<<endl;
        cout<<"Number copies of the book: "<<No_copies<<"\n\n";
    }
    friend void issue(UGStudent& s, book bk[] );
};
void issue(UGStudent &s,book bk[]){
    char a;
    string name;
    cout<<"Name of the Book you want you issue: ";
    cin>>name;
    for(int i=0;i<3;i++){
        if(bk[i].title==name){
            if(bk[i].No_copies>0){
                cout<<"Book is issued.\n";
                break;
            }
            else{
                cout<<"The Book cannot be issued.";
            }
        }
    }
}
int main(){
  student S[10];
  book B[10];
  UGStudent s1;
  PGStudent s2;
  int i,b=0,s=0;
  string name;
  while(1){

   cout<<"\nMain Menu\n";
   cout<<"1.Create Book\n";
   cout<<"2.Display Books\n";
   cout<<"3.Issue Book\n";
   cout<<"4.exit\n";
   cin>>i;
   switch (i)
   {
     case 1:
            B[b].Read();
            b++;
            break;
     case 2:
            for(int j=0;j<b;j++)
              B[j].Display();
            break;
     case 3:
            S[s].Read();
            int temp;
            cout<<"1.Undergraduate"<<endl<<"2.Postgraduate"<<endl;
            cin>>temp;
            if(temp==1)
            {
                s1.readUG();
            }
            else if(temp==2)
            {
                s2.readPG();
            }
            s++;

            for(i=0;i<b;i++)
             issue(s1,B);
            break;
     case 4:
            exit(0);
            break;
   }
  }
  return 0;
}