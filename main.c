//---------------------------------------
// jdh CS201 Fall 2022
// tests for assigment #2 (linked list)
//---------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.jhenry3.h"

//----------------------------------------------------------------------

int main() {
    ListNode *theList;
    StudentData *record;
    int rc, id, numFails;
    char name[MAX_NAME_LENGTH];

    numFails = 0;

    theList = NULL;

    printf("first test some insertions\n\n");
    // create Rafael Nadal 37
    strcpy(name, "Rafael Nadal");
    id = 37;

    rc = insertStudent(&theList, name, id);
    if (rc == 0) {
        printf("Correct: inserted %s %d\n", name, id);
    } else {
        printf("ERROR: nonzero return code trying to insert %s %d\n", name, id);
        ++numFails;
    }

    printList(theList);
    printf("\n");

    // create Ang Lee 21
    strcpy(name, "Guillermo Del Toro");
    id = 21;

    rc = insertStudent(&theList, name, id);
    if (rc == 0) {
        printf("Correct: inserted %s %d\n", name, id);
    } else {
        printf("ERROR: nonzero return code trying to insert %s %d\n", name, id);
        ++numFails;
    }

    printList(theList);
    printf("\n");

    // create Lin-Manuel Miranda 45
    strcpy(name, "Lin-Manuel Miranda");
    id = 45;

    rc = insertStudent(&theList, name, id);

    if (rc == 0) {
        printf("Correct: inserted %s %d\n", name, id);
    } else {
        printf("ERROR: nonzero return code trying to insert %s %d\n", name, id);
        ++numFails;
    }


    printList(theList);
    printf("\n");

    // create Matt Damon 29
    strcpy(name, "Matt Damon");
    id = 29;

    rc = insertStudent(&theList, name, id);
    if (rc == 0) {
        printf("Correct: inserted %s %d\n", name, id);
    } else {
        printf("ERROR: nonzero return code trying to insert %s %d\n", name, id);
        ++numFails;
    }

    printList(theList);
    printf("\n");

    // create Breanna Stewart 30
    strcpy(name, "Breanna Stewart");
    id = 30;

    rc = insertStudent(&theList, name, id);
    if (rc == 0) {
        printf("Correct: inserted %s %d\n", name, id);
    } else {
        printf("ERROR: nonzero return code trying to insert %s %d\n", name, id);
        ++numFails;
    }

    printList(theList);
    printf("\n");

    // now try to insert a different student with id=29: this should fail
    strcpy(name, "Taylor Swift");
    id = 29;

    rc = insertStudent(&theList, name, id);
    if (rc == 0) {
        printf("ERROR: zero return code trying to add %s %d\n", name, id);
        ++numFails;
    } else {
        printf("Correct: unable to add %s %d\n", name, id);
    }

    printList(theList);
    printf("\n");

    //-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

    printf("now test some lookups\n\n");

    id = 29;
    record = fetchStudent(theList, id);

    if (record != NULL) {
        printf("Correct: found '%s' %d for record with id=%d\n",
               record->name, record->id, id);
    } else {
        printf("ERROR: should have found record for id=%d\n", id);
        ++numFails;
    }

    id = 290;
    record = fetchStudent(theList, id);
    if (record != NULL) {
        printf("ERROR: got record '%s' %d id=%d\n", record->name, record->id, id);
        ++numFails;
    } else {
        printf("Correct: did not fetch record for id=%d\n", id);
    }

    printf("\n");

    //-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

    printf("now test deletions\n\n");

    // try to delete id=29
    id = 29;
    rc = deleteStudent(&theList, id);
    if (rc == 0) {
        printf("Correct: deleted record with id=%d\n", id);
    } else {
        printf("ERROR: failed to delete record with id=%d\n", id);
        ++numFails;
    }

    printList(theList);
    printf("\n");

    // try to delete id=21 (the first node in the list)
    id = 21;
    rc = deleteStudent(&theList, id);
    if (rc == 0) {
        printf("Correct: deleted record with id=%d\n", id);
    } else {
        printf("ERROR: failed to delete record with id=%d\n", id);
        ++numFails;
    }

    printList(theList);
    printf("\n");

    // try to delete id=45
    id = 45;
    rc = deleteStudent(&theList, id);
    if (rc == 0) {
        printf("Correct: deleted record with id=%d\n", id);
    } else {
        printf("ERROR: failed to delete record with id=%d\n", id);
        ++numFails;
    }

    printList(theList);
    printf("\n");

    // try to delete id=300 (doesn't exist)
    id = 300;
    rc = deleteStudent(&theList, id);
    if (rc == 0) {
        printf("ERROR: zero return code from deleting record with id=%d\n", id);
        ++numFails;
    } else {
        printf("Correct: failed to delete record with id=%d\n", id);
    }

    printList(theList);
    printf("\n");

    // try to delete id=30
    id = 30;
    rc = deleteStudent(&theList, id);
    if (rc == 0) {
        printf("Correct: deleted record with id=%d\n", id);
    } else {
        printf("ERROR: failed to delete record with id=%d\n", id);
        ++numFails;
    }

    printList(theList);
    printf("\n");

    // try to delete id=37
    id = 37;
    rc = deleteStudent(&theList, id);
    if (rc == 0) {
        printf("Correct: deleted record with id=%d\n", id);
    } else {
        printf("ERROR: failed to delete record with id=%d\n", id);
        ++numFails;
    }

    printList(theList);
    printf("\n");

    // try to delete id=30: should fail, because list is empty
    id = 30;
    rc = deleteStudent(&theList, id);
    if (rc == 0) {
        printf("ERROR: zero return code from deleting record with id=%d\n", id);
        ++numFails;
    } else {
        printf("Correct: failed to delete record with id=%d\n", id);
    }

    printList(theList);
    printf("\n");

    // now add a new record
    strcpy(name, "Teemu Selanne");
    id = 8;

    rc = insertStudent(&theList, name, id);
    if (rc == 0) {
        printf("Correct: inserted %s %d\n", name, id);
    } else {
        printf("ERROR: nonzero return code trying to insert %s %d\n", name, id);
        ++numFails;
    }

    printList(theList);
    printf("\n");

    if (numFails == 0) {
        printf("All tests pass!\n");
    } else {
        printf("%d tests failed\n", numFails);
    }

    return numFails;
}
