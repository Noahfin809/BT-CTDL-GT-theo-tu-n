#include <iostream>
#include <string>
using namespace std;

// ===== STRUCT =====
struct File {
    string name;
    double size; // MB
    int time;
};

struct Node {
    File data;
    Node* next;
};

struct LinkedList {
    Node* head;
};

// ===== INIT =====
void initList(LinkedList &list) {
    list.head = NULL;
};

// ===== CREATE NODE =====
Node* createNode(File f) {
    Node* p = new Node;
    p->data = f;
    p->next = NULL;
    return p;
}

// ===== INSERT =====
void insertFile(LinkedList &list, File f) {
    Node* p = createNode(f);

    if (list.head == NULL || f.time < list.head->data.time) {
        p->next = list.head;
        list.head = p;
        return;
    }

    Node* cur = list.head;
    while (cur->next != NULL && cur->next->data.time < f.time) {
        cur = cur->next;
    }

    p->next = cur->next;
    cur->next = p;
}

// ===== PRINT =====
void printList(LinkedList list) {
    Node* cur = list.head;
    cout << "\n===== DANH SACH FILE =====\n";
    while (cur != NULL) {
        cout << cur->data.name 
             << " | " << cur->data.size << " MB | time: " 
             << cur->data.time << endl;
        cur = cur->next;
    }
}

// ===== TOTAL SIZE =====
double totalSize(LinkedList list) {
    double sum = 0;
    Node* cur = list.head;
    while (cur != NULL) {
        sum += cur->data.size;
        cur = cur->next;
    }
    return sum;
}

// ===== SORT SIZE =====
void sortBySize(LinkedList &list) {
    for (Node* i = list.head; i != NULL; i = i->next) {
        Node* minNode = i;
        for (Node* j = i->next; j != NULL; j = j->next) {
            if (j->data.size < minNode->data.size) {
                minNode = j;
            }
        }
        File temp = i->data;
        i->data = minNode->data;
        minNode->data = temp;
    }
}

// ===== BACKUP =====
void prepareBackup(LinkedList &list) {
    double LIMIT = 32000; // MB
    double sum = totalSize(list);

    cout << "\nTong dung luong: " << sum << " MB\n";

    if (sum <= LIMIT) {
        cout << "Tat ca file deu vua USB 32GB\n";
        return;
    }

    sortBySize(list);

    while (sum > LIMIT && list.head != NULL) {
        Node* temp = list.head;
        cout << "Xoa: " << temp->data.name << endl;

        sum -= temp->data.size;
        list.head = temp->next;
        delete temp;
    }

    cout << "Con lai: " << sum << " MB\n";
}

// ===== MAIN (QUAN TRỌNG) =====
int main() {
    LinkedList folder;
    initList(folder);

    insertFile(folder, {"A.txt", 2.5, 5});
    insertFile(folder, {"B.mp4", 15000, 1});
    insertFile(folder, {"C.pdf", 500, 8});
    insertFile(folder, {"D.iso", 20000, 3});
    insertFile(folder, {"E.jpg", 1.2, 10});

    printList(folder);

    prepareBackup(folder);

    printList(folder);

    return 0;
}