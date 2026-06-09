#include <iostream>
using namespace std;

struct Node {
    int giaTri;
    Node* trai;
    Node* phai;
    int chieuCao;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int layChieuCao(Node* nut) {
    if (nut == NULL) return 0;
    return nut->chieuCao;
}

Node* taoNut(int x) {
    Node* nut = new Node;
    nut->giaTri = x;
    nut->trai = NULL;
    nut->phai = NULL;
    nut->chieuCao = 1;
    return nut;
}

int heSoCanBang(Node* nut) {
    if (nut == NULL) return 0;

    return layChieuCao(nut->trai)
         - layChieuCao(nut->phai);
}

Node* quayPhai(Node* y) {
    Node* x = y->trai;
    Node* T2 = x->phai;

    x->phai = y;
    y->trai = T2;

    y->chieuCao = 1 + max(
        layChieuCao(y->trai),
        layChieuCao(y->phai)
    );

    x->chieuCao = 1 + max(
        layChieuCao(x->trai),
        layChieuCao(x->phai)
    );

    return x;
}

Node* quayTrai(Node* x) {
    Node* y = x->phai;
    Node* T2 = y->trai;

    y->trai = x;
    x->phai = T2;

    x->chieuCao = 1 + max(
        layChieuCao(x->trai),
        layChieuCao(x->phai)
    );

    y->chieuCao = 1 + max(
        layChieuCao(y->trai),
        layChieuCao(y->phai)
    );

    return y;
}

Node* them(Node* goc, int x) {

    if (goc == NULL)
        return taoNut(x);

    if (x < goc->giaTri)
        goc->trai = them(goc->trai, x);

    else if (x > goc->giaTri)
        goc->phai = them(goc->phai, x);

    else
        return goc;

    goc->chieuCao = 1 + max(
        layChieuCao(goc->trai),
        layChieuCao(goc->phai)
    );

    int bf = heSoCanBang(goc);

    // LL
    if (bf > 1 && x < goc->trai->giaTri)
        return quayPhai(goc);

    // RR
    if (bf < -1 && x > goc->phai->giaTri)
        return quayTrai(goc);

    // LR
    if (bf > 1 && x > goc->trai->giaTri) {
        goc->trai = quayTrai(goc->trai);
        return quayPhai(goc);
    }

    // RL
    if (bf < -1 && x < goc->phai->giaTri) {
        goc->phai = quayPhai(goc->phai);
        return quayTrai(goc);
    }

    return goc;
}

void LNR(Node* goc) {
    if (goc == NULL) return;

    LNR(goc->trai);
    cout << goc->giaTri << " ";
    LNR(goc->phai);
}

void NLR(Node* goc) {
    if (goc == NULL) return;

    cout << goc->giaTri << " ";
    NLR(goc->trai);
    NLR(goc->phai);
}

void LRN(Node* goc) {
    if (goc == NULL) return;

    LRN(goc->trai);
    LRN(goc->phai);
    cout << goc->giaTri << " ";
}

int main() {

    int mang[] = {
        32, 51, 27, 83, 96,
        11, 45, 75, 66
    };

    int n = sizeof(mang) / sizeof(mang[0]);

    Node* goc = NULL;

    for (int i = 0; i < n; i++) {
        goc = them(goc, mang[i]);
    }

    cout << "NLR: ";
    NLR(goc);

    cout << "\n\nLNR: ";
    LNR(goc);

    cout << "\n\nLRN: ";
    LRN(goc);

    cout << endl;

    return 0;
}