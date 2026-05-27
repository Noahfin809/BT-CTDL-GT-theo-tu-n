#include <iostream>
using namespace std;

void xuatMang(int a[], int sl)
{
    cout << "{ ";

    for(int i = 0; i < sl; i++)
    {
        cout << a[i];

        if(i != sl - 1)
            cout << " , ";
    }

    cout << " }\n";
}

void heapify(int a[], int n, int vt)
{
    int lonNhat = vt;

    int trai = vt * 2 + 1;
    int phai = vt * 2 + 2;

    if(trai < n && a[trai] > a[lonNhat])
        lonNhat = trai;

    if(phai < n && a[phai] > a[lonNhat])
        lonNhat = phai;

    if(lonNhat != vt)
    {
        swap(a[vt], a[lonNhat]);

        heapify(a, n, lonNhat);
    }
}

void taoHeap(int a[], int n)
{
    int dem = 1;

    for(int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);

        cout << "Lan vun " << dem << ": ";
        xuatMang(a, n);

        dem++;
    }
}

void heapSort(int a[], int n)
{
    int step = 1;

    for(int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);

        heapify(a, i, 0);

        cout << "Buoc sap xep " << step << ": ";
        xuatMang(a, n);

        step++;
    }
}

int main()
{
    cout << "===== CAY 1 =====\n\n";

    int ds1[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};

    int n1 = sizeof(ds1) / sizeof(ds1[0]);

    cout << "Mang luc dau:\n";
    xuatMang(ds1, n1);

    cout << "\nQua trinh tao heap:\n";
    taoHeap(ds1, n1);

    cout << "\nQua trinh sap xep:\n";
    heapSort(ds1, n1);

    cout << "\nKet qua cuoi cung:\n";
    xuatMang(ds1, n1);

    cout << "\n\n============================\n\n";

    cout << "===== CAY 2 =====\n\n";

    int ds2[] = {11, 34, 32, 106, 38, 78, 203, 16, 84, 17, 39, 15};

    int n2 = sizeof(ds2) / sizeof(ds2[0]);

    cout << "Mang luc dau:\n";
    xuatMang(ds2, n2);

    cout << "\nQua trinh tao heap:\n";
    taoHeap(ds2, n2);

    cout << "\nQua trinh sap xep:\n";
    heapSort(ds2, n2);

    cout << "\nKet qua cuoi cung:\n";
    xuatMang(ds2, n2);

    return 0;
}