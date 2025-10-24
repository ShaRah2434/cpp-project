#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct subject {
    string subjectName;
    int credit; //credit hour
    float mark; 
    string grade;
    float gradePoint;
};

struct student {
    string name;
    int age;
    int subjectCount;
    subject subjects[5];
    float cpa; // Cumulative Point Average
};

//function declarations
void calculateGrade(subject &subj);
float calculateCPA(const student &stu);
void inputSubject(subject &subj);
void inputStudent(student &stu);
void displayStudent(const student &stu);

int main() {
    int studentCount;
    student students[10];

    do{
        cout << "Enter number of students (max 10): ";
        cin >> studentCount;
        if(studentCount < 1 || studentCount > 10) {
            cout << "Invalid number of students.\n";
        }
    }while(studentCount < 1 || studentCount > 10);

    for (int i = 0; i < studentCount; i++) {
        cout << "\n=== Student " << i + 1 << " ===\n";
        inputStudent(students[i]);
    }

    cout << "\n======= Student Information =======\n";
    for (int i = 0; i < studentCount; i++) {
        displayStudent(students[i]);
    }

    return 0;
}

void calculateGrade(subject &subj) {
    if (subj.mark >= 80){ 
        subj.grade = "A"; subj.gradePoint = 4.00;
    }else if (subj.mark >= 75){ 
        subj.grade = "A-"; subj.gradePoint = 3.67;
    }else if (subj.mark >= 70){ 
        subj.grade = "B+"; subj.gradePoint = 3.33; 
    }else if (subj.mark >= 65){
        subj.grade = "B"; subj.gradePoint = 3.00; 
    }else if (subj.mark >= 60){
        subj.grade = "B-"; subj.gradePoint = 2.67; 
    }else if (subj.mark >= 55){
        subj.grade = "C+"; subj.gradePoint = 2.33; 
    }else if (subj.mark >= 50){
        subj.grade = "C"; subj.gradePoint = 2.00;
    }else if (subj.mark >= 45){
        subj.grade = "D+"; subj.gradePoint = 1.67;
    }else if (subj.mark >= 40){
        subj.grade = "D"; subj.gradePoint = 1.33;
    }else{
        subj.grade = "F"; subj.gradePoint = 0.00;
    }
}


void inputSubject(subject &subj) {
    cout << "Enter subject name: ";
    getline(cin,subj.subjectName);
    if(subj.subjectName.empty()){
        getline(cin,subj.subjectName); // Handle leftover newline
    }

    cout << "Enter subject credit (1-6): ";
    cin >> subj.credit;

    //validate credit input
    while(subj.credit<1 || subj.credit>6){
        cout << "Invalid credit (1-6). Enter subject credit: ";
        cin >> subj.credit;
    }

    //validate mark input
    do {
        cout << "Enter subject mark (0–100): ";
        cin >> subj.mark;
        if (subj.mark < 0 || subj.mark > 100)
            cout << "Invalid mark must not exceed 100\n";
    } while (subj.mark < 0 || subj.mark > 100);

    calculateGrade(subj); //calculate grade and grade point
}


float calculateCPA(const student &stu) {
    float totalPoints = 0, totalCredits = 0;
    for (int i = 0; i < stu.subjectCount; i++) {
        //grade point x credit = weighted points
        totalPoints += stu.subjects[i].gradePoint * stu.subjects[i].credit;
        totalCredits += stu.subjects[i].credit;
    }
    // CPA = total weighted points / total credits
    if (totalCredits == 0) return 0;
    return totalPoints / totalCredits;
}


void inputStudent(student &stu) {
    cout << "\nEnter student name: ";
    getline(cin, stu.name);
    if(stu.name.empty()){
    getline(cin, stu.name); // Handle leftover newline
    } 

    cout << "Enter age: ";
    cin >> stu.age;

    do{
        cout << "Enter number of subjects (max 5): ";
        cin >> stu.subjectCount;
        if(stu.subjectCount < 1 || stu.subjectCount > 5) {
            cout << "Invalid number of subjects.\n";
        }
    }while(stu.subjectCount < 1 || stu.subjectCount > 5);

    for (int i = 0; i < stu.subjectCount; i++) {
        cout << "\n--- Subject " << i + 1 << " ---\n";
        inputSubject(stu.subjects[i]);
    }

    //calculate overall CPA
    stu.cpa = calculateCPA(stu);
}


void displayStudent(const student &stu) {
    cout << "Name: " << stu.name << "\nAge: " << stu.age << "\n";
    cout << "-------------------------------------\n";
    cout << "Subjects:\n";
    cout << "Subject\t\tCredit\tMark\tGrade\tPoint\n";

    //subject details
    for (int i = 0; i < stu.subjectCount; i++) {
        cout << stu.subjects[i].subjectName << "\t\t"
             << stu.subjects[i].credit << "\t"
             << stu.subjects[i].mark << "\t"
             << stu.subjects[i].grade << "\t"
             << stu.subjects[i].gradePoint << endl;
    }

    //display CPA
    cout << "-------------------------------------\n";
    cout << "CPA (UTM): " << fixed << setprecision(2) << stu.cpa << "\n\n";
}
