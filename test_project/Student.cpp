#pragma once
#include "Student.h"

void Print(ostream& out, Student stu[], int numelement)
{
    for (int i = 0; i < numelement; i++)
    {
        stu[i].Print(out);
    }
}
void Student::Print(ostream& out)
{
    out << id << "\t" << name << "\t" << gpa << endl;
}
void Student::InitValue(int _id, char* _name, float _gpa)
{
    id = _id;
    strcpy(name, _name);
    gpa = _gpa;
}
void Student::getValue(int& _id, char* _name, float& _gpa)
{
    _id = id;
    strcpy(_name, name);
    _gpa = gpa;
}
char* Student::getName()
{
    return name;
}
void Student::operator = (Student stu)
{
    id = stu.id;
    strcpy(name, stu.name);
    gpa = stu.gpa;
}

void PrintByPointer(ostream& out, Student* values[], int numValues)
{
    for (int i = 0; i < numValues; i++)
    {
        (*values[i]).Print(out);
    }
}

void Swap(Student& item1, Student& item2)
// Post: Contents of item1 and item2 have been swapped.
{
    Student tempItem;

    tempItem = item1;
    item1 = item2;
    item2 = tempItem;
}
