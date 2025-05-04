// Department maintains a student information. The file contains roll number, name,
// division and address. Allow user to add, delete information of student. Display
// information of particular employee. If record of student does not exist an appropriate
// message is displayed. If it is, then the system displays the student details. Use sequential
// file to main the data.

#include <bits/stdc++.h>
using namespace std;

struct Student
{
    string roll;
    string name;
    string div;
    string address;
};

void addStudent(){
    Student stud;

    cout << "Enter the name of the student : ";
    getline(cin, stud.name);

    cout << "Enter rollno : ";
    getline(cin, stud.roll);

    cout << "Enter division : ";
    getline(cin, stud.div);

    cout << "Enter the address : ";
    getline(cin, stud.address);

    fstream f("student.txt", ios::out | ios::app);
    f << stud.roll << endl << stud.name << endl << stud.div << endl << stud.address << endl;
    f.close();

}

void displayStudent(int roll){
    fstream f("student.txt", ios::in);
    if(!f){
        cout << "File doesnt exist";
        return;
    }
    bool found = false;
    string r;
    string n, d, a;

    while(getline(f, r)){
        if(r == to_string(roll)){
            cout << "\nStudent details found!!\n";
            found = true;

            getline(f, n);
            getline(f, d);
            getline(f, a);

            cout << "\nName : " << n;
            cout << "\nRoll no :" << r;
            cout << "\nDivision : " << d;
            cout << "\nAddress : " << a;
            cout <<"\n";
            return;
        }
    }
    if(!found){
        cout << "Student not found\n";
        return;
    }
}

void deleteStudent(int roll){
    fstream f1("temp.txt", ios::out | ios::app);
    fstream f2("student.txt", ios::in);

    string r, n, d, a;
    bool found = false;

    while(getline(f2, r)&&getline(f2, n)&&getline(f2, d)&&getline(f2, a)){
        if(r == to_string(roll)){
            found = true;
            cout << "Student deleted!!\n";
            continue;
        }
        else{
            f1 << r << endl; 
            f1 << n << endl; 
            f1 << d << endl; 
            f1 << a << endl; 
        }
    }
    if(!found){
        cout << "Roll number not found!!\n";
        return;
    }

    f1.close();
    f2.close();

    remove("student.txt");
    rename("temp.txt", "student.txt");
}

int main(){
    int choice, roll;

    do{
        cout << "\n--- Student Information System ---\n";
        cout << "1. Add Student\n2. Display Student\n3. Delete Student\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice){
        case 1:
        
            addStudent();
            break;
        case 2:
            cout << "Enter Roll No to display: ";
            cin >> roll;
            displayStudent(roll);
            break;
        case 3:
            cout << "Enter Roll No to delete: ";
            cin >> roll;
            deleteStudent(roll); 
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    }while (choice != 4);

    return 0;
}
