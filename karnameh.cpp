#include<iostream>
#include<vector>
#include <iomanip>
#include<string>
#include<algorithm>
#include<limits>
using namespace std;

struct lesson {
    string Lname;
    int credit;
    double point;
};

struct student {
    string name;
    int ID;
    string field;
    double GPA;
    vector<lesson> lessons;
};

bool list(const student &a, const student &b) {
    return a.GPA > b.GPA;
}

void addlesson(lesson &l, student &s) {
    cout << "\nEnter name of lesson :\n";
    cin >> l.Lname;
   judge :
    cout << "Enter count of credits :\n";
    cin >> l.credit;
    if(cin.fail()){
      cout<<"WRONG ANSWER !!,Try again";
       
           cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
          
      goto judge;
    }
    judge2:
    cout << "Enter point of lesson\n";
    cin >> l.point;
    if( cin.fail()){
      cout<<"WRONG ANSWER !.Try again";
       
           cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
           
      goto judge2;
    }
    s.GPA += (l.point * l.credit);
}

void addstude(student &s) {
    cout << "\nEnter student's name :\n";
    cin.ignore();
    getline(cin, s.name);
    rule2:
    cout << "\nEnter ID :\n";
    cin >> s.ID;
    if (cin.fail()) {
        cout << "Wrong answer.Try again\n";
          
           cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
           
       goto rule2;

    }
    rule1 :
    cout << "\nEnter field :\n";
    cin >> s.field;
    if(cin.fail()) {
        cout << "Wrong answer. Try again\n";
         
           cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
             
        goto rule1;
    }
    s.GPA = 0;
    cout << "\n------------------------------------\n";
    int numlesson;
    rule:
    cout << "Enter number of lessons :\n";
    cin >> numlesson;
    if (cin.fail()) {
        cout << "Wrong answer. Try again\n";
         
         
           cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
           
        goto rule;
    }
    for (int i = 0; i < numlesson; i++) {
        lesson l;
        addlesson(l, s);
        s.lessons.push_back(l);
    }
    s.GPA /= numlesson;
    cout << "---------------------------------------\n";
    cout << "Had done completely!\n\n";
}

void show(const vector<student> &students) {
    cout << "\n________________________________________\n";
    cout << left << setw(15) << "| Name |" << setw(15) << "| ID |" << setw(15) << "| Field  |" << setw(10) << "| GPA |" << endl;
    cout << "----------------------------------------\n";
    for (int i = 0; i < students.size(); i++) {
        cout << left << setw(15) << " | " <<setw(15)<< students[i].name << setw(15) << " | " << students[i].ID << setw(15) << " | " << students[i].field << setw(10) << fixed << setprecision(2) << " | " << students[i].GPA << " |";
        cout << "\n----------------------------------------\n\n";
    }
}

void speceficField(string &spece, const vector<student> &students) {
    bool test = false;
    cout << left << setw(15) << "| Name |" << setw(15) << "| ID |" << setw(15) << "| Field  |" << setw(10) << "| GPA |" << endl;
    for (int i = 0; i < students.size(); i++) {
        cout << "\n----------------------------------------\n";
        if (spece == students[i].field) {
            cout << left << setw(15) << " | " << students[i].name << setw(15) << " | " << students[i].ID << setw(15) << " | " << students[i].field << setw(10) << fixed << setprecision(2) << " | " << students[i].GPA << " |";
            test = true;
        }
    }
    if (!test) {
        cout << "Not Found!\n";
    }
}

void reportCard(string &name, int& sID, const vector<student> &students) {
    bool check = false;
    cout << "\n----------------------------------------\n";
    for (int i = 0; i < students.size(); i++) {
        if (name == students[i].name && sID == students[i].ID) {
            check = true;
            cout << "Name: " << students[i].name << setw(10) << right << "ID: " << students[i].ID << endl;
            cout << setw(15) << left << "| Lesson |" << setw(15) << "| Credit |" << setw(15) << "| Point |" << endl;
            for (int j = 0; j < students[i].lessons.size(); j++) {
                cout << setw(15) << left << students[i].lessons[j].Lname << setw(15) << students[i].lessons[j].credit << setw(15) << students[i].lessons[j].point << "\n";
            }
        }
    }
    if (!check) {
        cout << "NOT FOUND!\n";
    }
}

int main() {
    int n, num, sID;
    string spece, name;
    vector<student> students;
    do {
    lbl:
        cout << "Enter your number of your choice:";
        cout << "\n=======================================\n";
        cout << "(1): Add student\n(2): List of students\n(3): List by field\n(4): Report card\n(5): Exit\n";
        cout << "=======================================\n";
        cin>>n;
        if (cin.fail()) {
         cout<<"WRONG ANSWER !.Try again\n";
           cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
             goto lbl;
        }
        else{
            switch (n) {
                case 1: {
                jump:
                    cout << "Enter number of students:\n";
                    cin >> num;
                    if(cin.fail()){
                        cout << "Wrong answer. Try again\n";
                         
        
           cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
           
                        goto jump;

                    }
                    for (int i = 0; i < num; i++) {
                        student s;
                        addstude(s);
                        students.push_back(s);
                    }
                }
                break;
                case 2: {
                    sort(students.begin(), students.end(), list);
                    show(students);
                    break;
                }
                case 3: {
                    cout << "\nEnter your specific field:\n";
                    cin >> spece;
                    speceficField(spece, students);
                    break;
                }
                case 4: {
                    cout << "Enter the student name:\n";
                    cin >> name;
                    cout << "\nEnter the student ID:\n";
                    cin >> sID;
                    reportCard(name, sID, students);
                    break;
                }
                case 5: {
                    cout << "Bro be darak\n";
                    exit(0);
                }
                default: {
                    cout << "Wrong answer. Try again\n";

                    goto lbl;
                }
            }
        
        
        }
    } while (n != 5);

    return 0;
}
