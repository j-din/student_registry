#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

struct Student
{
    int ID;
    string name;

    Student* next = nullptr;
    Student* prev = nullptr;
};

// Function prototypes
Student* createStudent(int ID, string name); // creates an object of the Student struct
void append(Student* &head, int ID, string name); // add to back of list 
void push(Student* &head, int ID, string name); // add to front of list
void insertAfter(Student* &head, int ID, int newID, string newName); // Insert after given ID
void insertBefore(Student* &head, int ID, int newID, string newName); // Insert before given ID
void reverseList(Student* &head); 
void removeFromList(Student* &head, int ID);
bool searchList(Student* head, int ID);
void printList(Student* head);
void deleteList(Student* &head);
void printMenu();

#endif