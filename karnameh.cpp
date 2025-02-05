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
    cout << "\n+---------------+---------------+---------------+----------+\n";
    cout << "| Name          | ID            | Field         | GPA      |\n";
    cout << "+---------------+---------------+---------------+----------+\n";
    for (const auto& s : students) {
        cout << "| " << setw(13) << left << s.name
             << "| " << setw(13) << s.ID
             << "| " << setw(13) << s.field
             << "| " << setw(8) << fixed << setprecision(2) << s.GPA << " |\n";
    }
    cout << "+---------------+---------------+---------------+----------+\n";
}

void speceficField(string &spece, const vector<student> &students) {
    bool test = false;
    cout << "\n+---------------+---------------+---------------+----------+\n";
    cout << "| Name          | ID            | Field         | GPA      |\n";
    cout << "+---------------+---------------+---------------+----------+\n";

    for (const auto& s : students) {
        if (spece == s.field) {
            cout << "| " << setw(13) << left << s.name
                 << "| " << setw(13) << s.ID
                 << "| " << setw(13) << s.field
                 << "| " << setw(8) << fixed << setprecision(2) << s.GPA << " |\n";
            test = true;
        }
    }
    cout << "+---------------+---------------+---------------+----------+\n";

    if (!test) cout << "Not Found!\n";
}

void reportCard(string &name, int& sID, const vector<student> &students) {
    bool check = false;
    for (const auto& s : students) {
        if (name == s.name && sID == s.ID) {
            check = true;
            cout << "\n+----------------------+--------+\n";
            cout << "| Name: " << setw(19) << left << s.name << "| ID: " << setw(6) << s.ID << " |\n";
            cout << "+----------------------+--------+\n";
            cout << "| Lesson        | Credit | Point  |\n";
            cout << "+--------------+--------+--------+\n";
            for (const auto& l : s.lessons) {
                cout << "| " << setw(12) << left << l.Lname
                     << "| " << setw(6) << l.credit
                     << "| " << setw(6) << fixed << setprecision(2) << l.point
                     << " |\n";
            }
            cout << "+--------------+--------+--------+\n";
            cout<<"GPA :"<<s.GPA;
            cout << "+--------------+--------+--------+\n";
        }
    }
    if (!check) cout << "NOT FOUND!\n";
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
                    cin.ignore();
                    getline(cin,name);
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
