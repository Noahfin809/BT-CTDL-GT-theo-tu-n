#include <iostream>
using namespace std;

struct Node {
    int namSinh;
    Node *trai;
    Node *phai;
};

typedef Node* Cay;

// tạo node mới
Node* taoNode(int x) {
    Node* p = new Node;
    p->namSinh = x;
    p->trai = NULL;
    p->phai = NULL;
    return p;
}

// thêm vào cây BST
void themNode(Cay &t, int x) {
    if (t == NULL) {
        t = taoNode(x);
        return;
    }

    // nhỏ hơn hoặc bằng thì qua trái
    if (x <= t->namSinh) {
        themNode(t->trai, x);
    }
    // lớn hơn thì qua phải
    else {
        themNode(t->phai, x);
    }
}

// tìm kiếm năm sinh
bool timKiem(Cay t, int x) {
    if (t == NULL) {
        return false;
    }

    if (t->namSinh == x) {
        return true;
    }

    if (x < t->namSinh) {
        return timKiem(t->trai, x);
    }
    else {
        return timKiem(t->phai, x);
    }
}

// duyệt cây NLR cho dễ nhìn
void duyetNLR(Cay t) {
    if (t != NULL) {
        cout << t->namSinh << " ";
        duyetNLR(t->trai);
        duyetNLR(t->phai);
    }
}

int main() {

    Cay cay = NULL;

    int dsNam[] = {2001, 2002, 2006, 2007, 2003, 2004, 2005, 2001, 1999, 2004};

    int n = 10;

    // thêm dữ liệu vào BST
    for (int i = 0; i < n; i++) {
        themNode(cay, dsNam[i]);
    }

    cout << "Cay nhi phan tim kiem:\n";
    duyetNLR(cay);

    int canTim = 2004;

    cout << "\n\nTim nam sinh " << canTim << ":\n";

    if (timKiem(cay, canTim)) {
        cout << "Co sinh vien nam " << canTim;
    }
    else {
        cout << "Khong co sinh vien nam " << canTim;
    }

    return 0;
}
