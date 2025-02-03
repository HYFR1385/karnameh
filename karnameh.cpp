#include<iostream>
#include<vector>
#include <iomanip>
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

  cout<<"\nEnter name of lesson :\n";
  cin>>l.Lname;
  cout<<"Enter count of credits :\n";
  cin>>l.credit;
  cout<<" Enter point of lesson\n";
  cin >> l.point;
    s.GPA += l.point;


  }
  
 void addstude(student &s){
  punch :
  cout<<"\nEnter name :\n";
   cin.ignore();
   getline(cin,s.name);
   if(!(getline(cin,s.name))){
   cout <<"\nEnter ID :\n";
   cin>>s.ID;
   if(cin>>s.ID){
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
    cout<<" had done compeletly !\n\n";
   }
     }    
     else{
     cout<<"wrong answer.return again"  ;
      goto punch;}
     
 }


   void show(vector <student>students){
      cout << "\n________________________________________\n";
    cout << left << setw(15) << "| Name |" << setw(15) << "| ID |" << setw(15) << "| Field  |" << setw(10) << "| GPA |" << endl;
    cout << "----------------------------------------\n";
    for (int i = 0; i < students.size(); i++) {
        cout << left << setw(15) <<" | "<< students[i].name<< setw(15) <<" | "<< students[i].ID<< setw(15) <<" | "<< students[i].field<< setw(10) << fixed << setprecision(2) <<" | "<< students[i].GPA<<" |";
         cout << "\n----------------------------------------\n\n";
       }
       
    }
    void speceficField(string &spece,vector<student> &students){
      bool test=false;
        cout << left << setw(15) << "| Name |" << setw(15) << "| ID |" << setw(15) << "| Field  |" << setw(10) << "| GPA |" << endl;
      for(int i=0; i < students.size(); i++) {
        cout << "\n----------------------------------------\n";
        if(spece==students[i].field){
        cout << left << setw(15) <<" | "<< students[i].name<< setw(15) <<" | "<< students[i].ID<< setw(15) <<" | "<< students[i].field<< setw(10) << fixed << setprecision(2) <<" | "<< students[i].GPA<<" |";
        test=true;

      }   
     else
       cout<<"\nNot FOUND !";


    }    
    }
    
    void reportCard(string &name, int& sID, vector<student>students)
    {
      cout << "\n----------------------------------------\n";
     for (int i =0 ; i< students.size() ; i++){
      if (name == students[i].name && sID == students[i].ID){
        cout << "Name: " << students[i].name << setw(10) << right << "ID: " << students[i].ID << endl;
            cout << setw(15) << left << "| Lesson |" << setw(15) << "| Credit |" << setw(15) << "| Point |" << endl;
            for (int j =0 ; j < students[i].lessons.size(); j++) {
                 cout << setw(15) << left << students[i].lessons[j].Lname  << setw(15) << students[i].lessons[j].credit<< setw(15) << students[i].lessons[j].point <<"\n";
            }
     }
     else
       cout<<"\nNOT FOUND !!";
     }
     }
int main(){
int n,num,sID;
string spece,name;
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
   jump: 
   cout<<"Enter number of student :\n";
    cin>>num;
    if(cin>>num){
    for (int i = 0 ; i<num; i++){
    student s;
    addstude(s);
    students.push_back(s);
    }
    }
    else
    {
      cout<<"wrong answer.return again";
      goto jump;
    }
    
    }
    break;
    case 2 : {
     sort(students.begin(),students.end(),list);
      show(students);
     break;
    }
    case 3:
    {
    cout<<"\nEnter your specefic field :\n ";
    cin>>spece;
    speceficField(spece,students);
    break;
    }
    case 4:
    {
      cout<<"Enter the student name:\n";
      cin >>name; 
      cout<<"\nEnter the student ID:\n";
      cin>>sID;
      reportCard(name,sID,students);
      break;
    }
default:
    break;
}


}while(n!=5);





}