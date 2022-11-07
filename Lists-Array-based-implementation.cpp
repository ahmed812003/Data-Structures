#include <iostream>
using namespace std;
const int MaxSize = 100000;

typedef struct List {
    int size = 0;
    int entry[MaxSize];
} list;

void CreatList(list& s) {
    s.size = 0;
}

void InsertList (int val , int pos , list& s) {
    for (int i = s.size - 1 ; i >= pos ; i--) {
        s.entry[i + 1] = s.entry[i];
    }
    s.entry[pos] = val;
    s.size++;
}

void DeleteList (int& val , int pos , list& s) {
    val = s.entry[pos];
    for (int i = pos + 1 ; i < s.size ; i++) {
        s.entry[i - 1] = s.entry[i];
    }
    s.size--;
}

void RetrieveList (int& val , int pos , list& s) {
    val = s.entry[pos];
}

void ReplaceList (int val , int pos , list& s) {
    s.entry[pos] = val;
}

int ListEmpty (list& s) {
    return !s.size;
}

int ListFull (list& s) {
    return s.size == MaxSize;
}

int ListSize(list& s) {
    return s.size;
}

void DestroyList(list& s) {
    s.size == 0;
}

void TravelseList (list& s) {
    for (int i = 0 ; i < s.size ; i++) {
        cout << s.entry[i] << " ";
    }
    cout << "\n";
}

int main()
{
    freopen("output.txt", "w", stdout);
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
