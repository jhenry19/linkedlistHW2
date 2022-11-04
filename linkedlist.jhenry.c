#include <strings.h>
#include <stdlib.h>
#include <printf.h>
#include "linkedlist.jhenry3.h"

int insertStudent(ListNode **studentList, char *name, int id) {
    // If name is NULL or id is not positive, then leave the list unchanged and return one.
    if (name == NULL || id <= 0) {
        return 1;
    }

    //create a new StudentData record,
    StudentData *newStudent = malloc(sizeof(StudentData));

    // fill it in with the supplied name and id
    strcpy(newStudent->name, name);
    newStudent->id = id;

    ListNode *newItem = malloc(sizeof(ListNode));
    newItem->data = newStudent;
    newItem->next = NULL;

    //Prepare to go through the list
    ListNode *curr = *studentList;
    ListNode *prev = NULL;

    if (curr == NULL) { // if list is empty
        *studentList = newItem;
    } else {
        // loop through until correct placement for id is found
        while (curr != NULL && id > curr->data->id) {
            prev = curr;
            curr = curr->next;
            if (curr != NULL && id == curr->data->id) { // If there is a duplicate record an error code is given
                return 1;
            }
        }
        // Place record before curr
        newItem->next = curr;
        if (prev != NULL) {
            prev->next = newItem;
        } else { // if the new record goes at the front of the list
            *studentList = newItem;
        }
    }
    return 0;
}

int deleteStudent(ListNode **studentList, int id) {
    //Prepare to go through the list
    ListNode *curr = *studentList;
    ListNode *prev = NULL;

    //loops through list until search id is passed
    while (curr != NULL) {
        // If a record with same id is found, the previous pointer is changed
        if (id == curr->data->id) {
            if (prev != NULL) {
            prev->next = curr->next;
            }
            else { // if it is the first node the pointer to the list is changed
                *studentList = curr;
            }

            return 0;
        }
        prev = curr;
        curr = curr->next;
    }
    // If no record with the same id was found
    return 1;
}

StudentData *fetchStudent(ListNode *studentList, int id)
{
    // Prepare to go through the list
    ListNode *curr = studentList;

    // loops through list while search id is less than current id
    while (curr != NULL) {
        if (id == curr->data->id) { // If the id is found, the data is returned
            return curr->data;
        }
        curr = curr->next;
    }
    return NULL; // if data with search id is not found, NULL is returned
}
void printList(ListNode *studentList) {
    if (studentList == NULL) {  // if the list is empty
        printf("(list is empty)\n");
    }
    else {
        ListNode *curr = studentList;
        // loops through list
        while (curr != NULL) {
            printf("|%s|%d\n",curr->data->name, curr->data->id);
            curr = curr->next;
        }
    }
}
