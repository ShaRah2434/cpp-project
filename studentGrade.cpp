#include <iostream>
#include <string>
using namespace std;

struct subject {
    string subjectName;
    int credit;
    float mark;
    string grade;
    float gradePoint;
};

struct student {
    string name;
    int age;
    int subjectCount;
    subject subjects[5];
    float cpa;
};


void calculateGrade(subject &subj);
float calculateCPA(const student &stu);
void inputSubject(subject &subj);
void inputStudent(student &stu);
void displayStudent(const student &stu);

int main() {
    int studentCount;
    student students[10];

    cout << "Enter number of students (max 10): ";
    cin >> studentCount;

    for (int i = 0; i < studentCount; i++) {
        cout << "\n=== Student " << i + 1 << " ===\n";
        inputStudent(students[i]);
    }

    cout << "\n======= Student Summary =======\n";
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
    getline(cin, subjectName);

    cout << "Enter subject credit: ";
    cin >> subj.credit;

    do {
        cout << "Enter subject mark (0–100): ";
        cin >> subj.mark;
        if (subj.mark < 0 || subj.mark > 100)
            cout << "Invalid mark! Please enter between 0 and 100.\n";
    } while (subj.mark < 0 || subj.mark > 100);

    calculateGrade(subj);
}


float calculateCPA(const student &stu) {
    float totalPoints = 0, totalCredits = 0;
    for (int i = 0; i < stu.subjectCount; i++) {
        totalPoints += stu.subjects[i].gradePoint * stu.subjects[i].credit;
        totalCredits += stu.subjects[i].credit;
    }
    if (totalCredits == 0) return 0;
    return totalPoints / totalCredits;
}


void inputStudent(student &stu) {
    cout << "\nEnter student name: ";
    getline(cin, stu.name);

    cout << "Enter age: ";
    cin >> stu.age;

    cout << "Enter number of subjects (max 5): ";
    cin >> stu.subjectCount;

    for (int i = 0; i < stu.subjectCount; i++) {
        cout << "\n--- Subject " << i + 1 << " ---\n";
        inputSubject(stu.subjects[i]);
    }

    stu.cpa = calculateCPA(stu);
}


void displayStudent(const student &stu) {
    cout << "Name: " << stu.name << "\nAge: " << stu.age << "\n";
    cout << "Subjects:\n";
    cout << "-------------------------------------\n";
    cout << "Subject\t\tCredit\tMark\tGrade\tPoint\n";
    cout << "-------------------------------------\n";

    for (int i = 0; i < stu.subjectCount; i++) {
        cout << stu.subjects[i].subjectName << "\t"
             << stu.subjects[i].credit << "\t"
             << stu.subjects[i].mark << "\t"
             << stu.subjects[i].grade << "\t"
             << stu.subjects[i].gradePoint << endl;
    }

    cout << "-------------------------------------\n";
    cout << "CPA (UTM): " << stu.cpa << endl;
}
