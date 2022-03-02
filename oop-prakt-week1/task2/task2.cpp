#include <iostream>
using namespace std;

const int studentsNumber = 5;

struct Student
{
    int facultyNumber;
    int course;
    double averageGrade;
};

int integerLen(const int number)
{
    int len = 0;
    int n = number;
    while (n != 0)
    {
        len++;
        n = n / 10;
    }
    return len;
}

void validationStudent(const int course, const double averageGrade, const int facultyNumber)
{
    if (course < 1 || course > 4)
    {
        cout << "Students can be only 1, 2, 3 or 4 course" << endl;
    }
    if (averageGrade < 2 || averageGrade > 6)
    {
        cout << "Student's grades are between 2 and 6" << endl;
    }
    if (integerLen(facultyNumber) != 5)
    {
        cout << "Student's faculty number has 5 digits" << endl;
    }
}

void initStudent(const int& facultyNumber, const int& course, const double& averageGrade, Student& student)
{
    validationStudent(course, averageGrade, facultyNumber);
    student = { facultyNumber,course,averageGrade };
}

void print(const Student& student)
{
    cout << "<Student information>" << endl;
    cout << "Faculty Number:" << student.facultyNumber << endl;
    cout << "Course:" << student.course << endl;
    cout << "Average grade:" << student.averageGrade;
}

struct Group
{
    Student students[studentsNumber];
    double averageGroupGrade;
};

bool isNotNegative(const int number)
{
    return (number > 0);
}

double averageGrades(const Student students[])
{
    double sum = 0;
    for (int i = 0; i < studentsNumber; i++)
    {
        sum += students[i].averageGrade;
    }
    return sum / studentsNumber;
}


void InitGroup(Group& group, const Student students[])
{
    if (!isNotNegative(studentsNumber))
    {
        cout << "Number of group members can not be negative." << endl;
        return;
    }
    for (int i = 0; i < studentsNumber; i++)
    {
        group.students[i] = students[i];
    }
    group.averageGroupGrade = averageGrades(group.students);
}


int scholars(const Group& group, double minGrade)
{
    int br = 0;
    for (int i = 0; i < studentsNumber; i++)
            br += (group.students[i].averageGrade >= minGrade);
    return br;
}

void printArr(const Student arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        print(arr[i]);
        cout << endl;
    }
}

void selectionSort(Student st[], int len)
{
    Student tmp;
    for (int i = 0; i < len; i++) 
    {
        for (int j = i + 1; j < len; j++) 
        {
            if (st[j].averageGrade > st[i].averageGrade) 
            {
                tmp.averageGrade = st[i].averageGrade;
                tmp.course = st[i].course;                
                tmp.facultyNumber = st[i].facultyNumber;
                st[i].averageGrade = st[j].averageGrade;
                st[i].course = st[j].course;
                st[i].facultyNumber = st[j].facultyNumber;
                st[j].averageGrade = tmp.averageGrade;
                st[j].course = tmp.course;
                st[j].facultyNumber = tmp.facultyNumber;
            }
        }
    }
}

void scholarshipSortedList(const Group& group, double minimumGrade)
{
    Student scholars[studentsNumber];
    int len = 0;
    for (int i = 0; i < studentsNumber; i++)
    {
        if (group.students[i].averageGrade >= minimumGrade)
        {
            scholars[len].facultyNumber = group.students[i].facultyNumber;
            scholars[len].averageGrade = group.students[i].averageGrade;
            scholars[len].course = group.students[i].course;
            len++;
        }
    }
    selectionSort(scholars, len);
    printArr(scholars, len);
}

int main()
{
    int facNum;
    double grade;
    int course;
    Group group;
    Student students[studentsNumber];
    for (int i = 0; i < studentsNumber; i++)
    {
        cout << "Enter a student(faculty number, course and grade)" << endl;
        cin >> facNum >> course >> grade;
        initStudent(facNum, course, grade, students[i]);
    }
    InitGroup(group, students);
    int minGrade;
    cout << "Enter minimum grade for scholarship: ";
    cin >> minGrade;
    cout << scholars(group, minGrade) << endl;
    scholarshipSortedList(group, minGrade);
    return 0;
}
