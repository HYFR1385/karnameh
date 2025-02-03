#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

struct lesson{
 string Lname;
 int  credit; 
 double point;
};

struct student{
string name;
int ID;
string field;
double GPA;
vector <lesson> lessons;
};
bool list(student &a, student &b){
 return a.GPA > b.GPA ;
}
  void addlesson(lesson & l,student &s){

  cout<<"Enter name of lesson :";
  cin>>l.Lname;
  cout<<"Enter count of credits :";
  cin>>l.credit;
  cout<<" Enter point of lesson";
  cin >> l.point;
    s.GPA += l.point;


  }
  
 void addstude(student &s){
  cout<<"\nEnter name :";
   cin.ignore();
   getline(cin,s.name);
   cout <<"\nEnter ID :\n";
   cin>>s.ID;
   cout <<"\nEnter field :\n";
   cin>> s.field;
   s.GPA =0;
   cout<<"\n------------------------------------\n";
   int numlesson;
   cout<<" Enter number of lessons :";
   cin>> numlesson;
   for(int i=0 ; i<numlesson ; i++){
   lesson l;
   addlesson(l,s);
   s.lessons.push_back(l);
   }

   s.GPA /= numlesson;
    cout<<"---------------------------------------\n";
    cout<<" had done compeletly !";

     }      

    show(vector <student>students){
       

    } 

int main(){
int n,num;
vector <student> students;
do 
{
   
 cout<<"Enter your number of your choice:";
 cout<<"\n=======================================\n";
 cout << "(1): add student\n(2): list of student\n(3): list by field\n(4): report card\n(5): exit";
 cout<<"\n=======================================\n";
 cin>>n;
switch (n)
{
case 1:{
    cout<<"Enter number of student :\n";
    cin>>num;
    for (int i = 0 ; i<num; i++){
    student s;
    addstude(s);
    students.push_back(s);
    }
    }
    break;
    case 2 : {
     sort(students.begin(),students.end(),list);
      show(students);

    }
default:
    break;
}


}while(n!=5);





}