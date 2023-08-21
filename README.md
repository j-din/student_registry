# student_registry
This C++ program allows users to create and manipulate a doubly linked list of student records. 

When run, the program will prompt the user with a menu of choices that the user can choose from:
1. Add a student to the end of the list
2. Add a student to the beginning of the list
3. Insert a student after a particular student
4. Insert a student before a particular student
5. Reverse the list
6. Remove a student from the list
7. Search for a student by their ID
8. Print the list
9. Print menu
10. Quit

Program Functions:
createStudent(int ID, string name)
Creates a new student object with the given ID and name.

append(Student* &head, int ID, string name)
Appends a new student to the end of the list.

push(Student* &head, int ID, string name)
Pushes a new student to the beginning of the list.

insertAfter(Student* &head, int ID, int newID, string newName)
Inserts a new student after a specified student in the list.

insertBefore(Student* &head, int ID, int newID, string newName)
Inserts a new student before a specified student in the list.

reverseList(Student* &head)
Reverses the order of students in the list.

removeFromList(Student* &head, int ID)
Removes a student with a specified ID from the list.

searchList(Student* head, int ID)
Searches for a student by their unique ID and displays their information.

printList(Student* head)
Displays the information of all students in the list.

deleteList(Student* &head)
Deletes all student records in the list.

printMenu()
Displays the program menu with available options.