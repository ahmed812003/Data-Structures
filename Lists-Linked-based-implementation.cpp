#include <iostream>
using namespace std;

typedef struct node {
    int entry;
    struct node* next;

} ListNode;

typedef struct List {
    int size;
    ListNode* head;
} list;

void CreatList(list& s) {
    s.size = 0;
    s.head = NULL;
}

void InsertList (int val , int pos , list& s) {
    ListNode* ptr , *temp ; int i;
    ptr = (ListNode*)malloc(sizeof(ListNode));
    ptr->entry = val;
    ptr->next = NULL;
    if (pos == 0) {
        ptr->next = s.head;
        s.head = ptr;
    }
    else {
        temp = s.head;
        for (i = 0 ; i < pos - 1 ; i++) {
            temp = temp->next;
        }
        ptr->next = temp->next;
        temp->next = ptr;
    }
    s.size++;
}

void DeleteList (int& val , int pos , list& s) {
    ListNode* ptr , *temp; int i;
    if (pos == 0) {
        val = s.head->entry;
        temp = s.head->next;
        free(s.head);
        s.head = temp;
    }
    else {
        for (ptr = s.head , i = 0 ; i < pos - 1 ; i++)
            ptr = ptr->next;
        val = ptr->next->entry;
        temp = ptr->next->next;
        free(ptr->next);
        ptr->next = temp;
    }
    s.size--;
}

void RetrieveList (int& val , int pos , list& s) {
    ListNode* ptr; int i;
    for (ptr = s.head , i = 0 ; i < pos ; i++)
        ptr = ptr->next;
    val = ptr->entry;
}

void ReplaceList (int val , int pos , list& s) {
    ListNode* ptr; int i;
    for (ptr = s.head , i = 0 ; i < pos ; i++)
        ptr = ptr->next;
    ptr->entry = val;
}

int ListEmpty (list& s) {
    return !s.size;
}

int ListFull (list& s) {
    return 0;
}

int ListSize(list& s) {
    return s.size;
}

void DestroyList(list& s) {
    ListNode* ptr;
    while (s.head) {
        ptr = s.head->next;
        free(s.head);
        s.head = ptr;
    }
    s.size == 0;
}

void TravelseList (list& s) {
    ListNode* ptr = s.head;
    while (ptr) {
        cout << ptr->entry << " ";
        ptr = ptr->next;
    }
    cout << "\n";
}

int main()
{
    list s;
    CreatList(s);
    int pos = 0;
    if (pos >= 0 && pos <= ListSize(s)) {
        InsertList(10 , pos , s);
    }
    pos = 1;
    if (pos >= 0 && pos <= ListSize(s)) {
        InsertList(11 , pos , s);
    }
    pos = 2;
    if (pos >= 0 && pos <= ListSize(s)) {
        InsertList(12 , pos , s);
    }
    pos = 3;
    if (pos >= 0 && pos <= ListSize(s)) {
        InsertList(13 , pos , s);
    }
    pos = 4;
    if (pos >= 0 && pos <= ListSize(s)) {
        InsertList(14 , pos , s);
    }
    cout << ListSize(s) << "\n";
    TravelseList(s);
    int val;
    DeleteList(val , 3 , s);
    cout << val << "\n";
    cout << ListSize(s) << "\n";
    TravelseList(s);
    cout << ListEmpty(s) << "\n";
    RetrieveList(val , 2 , s);
    cout << val << "\n";
    ReplaceList(15 , 2 , s);
    TravelseList(s);
    return 0;
}
