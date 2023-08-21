#include "student.h"

Student* createStudent(int ID, string name)
{
    Student* newStudent = new Student;

    newStudent->name = name;
    newStudent->ID = ID;
    newStudent->next = nullptr;
    newStudent->prev = nullptr;

    return newStudent;
}

void append(Student* &head, int ID, string name)
{
    Student* newStudent = createStudent(ID, name);

    if(head == nullptr) // If list is empty append new student as head 
    {
        head = newStudent;
    }
    else // else find end of list and set newStudent
    {
        Student* temp = head;

        while(temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newStudent; // setting new student at the end of the list
        newStudent->prev = temp; // connecting previous node to end of list
    }
}

void push(Student* &head, int ID, string name)
{
    Student* newStudent = createStudent(ID, name);

    if(head == nullptr) // If list is empty push new student as head 
    {
        head = newStudent;
    }
    else // else create new link and set new student as head
    {
        newStudent->next = head; // connecting new student to head
        head->prev = newStudent; // connecting head to new student
        head = newStudent; // set new student as head
    }   
}

void insertAfter(Student* &head, int ID, int newID, string newName)
{
    Student* newStudent = createStudent(newID, newName);
    Student* temp = head;

    while(temp != nullptr) // while list is not empty
    {
        if(temp->ID == ID) // if found 
        {
            newStudent->next = temp->next; // temp is id so insert new id next
            newStudent->prev = temp; // temp is id so the previous of new student should be temp
            temp->next = newStudent; // connect the link 
            return; // id found so return
        }
        temp = temp->next; // id not found go next
    }  
}

void insertBefore(Student* &head, int ID, int newID, string newName)
{
    Student* newStudent = createStudent(newID, newName);
    Student* temp = head;

    if(head == nullptr || head->ID == ID) // if list is empty or head is id
    {
        push(head, newID, newName); // call push function to add to front
        return;
    }

    while(temp != nullptr)
    {
        if(temp->ID == ID) // if id found 
        {
            newStudent->next = temp; // temp comes after so next points to temp
            newStudent->prev = temp->prev; // keep the list linked backwards
            temp->prev->next = newStudent; // keep the list linked forwards
            temp->prev = newStudent; // connect temp back to newStudent
            return;
        }
        temp = temp->next; // traverse list
    }
}

void reverseList(Student* &head)
{
    Student* temp = nullptr;
    Student* current = head;

    while(current != nullptr) // while list is not empty swap next and prev pointers
    {
        temp = current->prev; // temp saves prev for later
        current->prev = current->next; // prev becomes next
        current->next = temp; // next becomes prev
        current = current->prev; // traverse the list
    }
    if (temp != nullptr)
    {
        head = temp->prev; // update head to the last node
    }
} 

void removeFromList(Student* &head, int ID)
{
    Student* temp = head;

    while(temp != nullptr)
    {
        if(temp->ID == ID) // if id found
        {
            if(temp->prev != nullptr) // if there is a prev 
                temp->prev->next = temp->next; // set the next pointer of the prev node to point past the current

            if(temp->next != nullptr) // if there is a next
                temp->next->prev = temp->prev; // set prev of next node to skip current node
            
            if(temp == head) // if at head
                head = temp->next; // move head to next
            
            delete temp; // delete student
            return; // id found and student removed so return
        }
        temp = temp->next; // traverse list 
    }
}

bool searchList(Student* head, int ID)
{
    while(head != nullptr) // while list is not empty
    {
        if(head->ID == ID)
        {
            cout << "Name: " << head->name << " ,ID: " << head->ID << endl;
            return true; // ID found - return true
        }
        head = head->next; // traverse list
    }
    return false; // id not found - return false
}

void printList(Student* head)
{
    while(head != nullptr) // while not at the end of the list print info and go next
    {
        cout << "Name: " << head->name << " ,ID: " << head->ID << endl;
        head = head->next;
    }
}

void deleteList(Student* &head)
{
    while(head != nullptr) // while list is not empty travere the list and save the prev head in temp for deletion
    {
        Student* temp = head;
        head = head->next;
        delete temp;
    }
}

void printMenu()
{
    cout << "1. Add a student to the end of the list\n";
    cout << "2. Add a student to the beginning of the list\n";
    cout << "3. Insert a student after a particular student\n";
    cout << "4. Insert a student before a particular student\n";
    cout << "5. Reverse the list\n";
    cout << "6. Remove a student from the list\n";
    cout << "7. Search for a student by their ID\n";
    cout << "8. Print the list\n";
    cout << "9. Print menu\n";
    cout << "10. Quit\n";
}