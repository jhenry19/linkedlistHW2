#define MAX_NAME_LENGTH 32
typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
} StudentData;

typedef struct ListNode {
    StudentData *data;
    struct ListNode *next;
} ListNode;

int insertStudent(ListNode **studentList, char *name, int id);
int deleteStudent(ListNode **studentList, int id);
StudentData *fetchStudent(ListNode *studentList, int id);
void printList(ListNode *studentList);