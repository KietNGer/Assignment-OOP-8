#include<iostream>
#include<string.h>
#include<math.h>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef long long ll;

class NhanVien
{
protected:
    string HoTen;
    int ngay;
    int thang;
    int nam;
    long Luong;
public:
    NhanVien();
    ~NhanVien();
    virtual void Nhap();
    virtual void Xuat();
    bool kiemtra();
    virtual long Tinh_luong();
};

class NVVP: public NhanVien
{
    int songaylamviec;
public:
    NVVP();
    ~NVVP();
    void Nhap();
    void Xuat();
    long Tinh_luong();
};

class NVSX: public NhanVien
{
    int sosanpham;
    int Luongcoban;
public:
    NVSX();
    ~NVSX();
    void Nhap();
    void Xuat();
    long Tinh_luong();
};

//NhanVien
NhanVien ::NhanVien()
{
    HoTen = "";
    ngay = 0;
    thang = 0;
    nam = 0;
    Luong = 0;
}

NhanVien ::~NhanVien()
{
    HoTen = "";
    ngay = 0;
    thang = 0;
    nam = 0;
    Luong = 0;
}

bool NhanVien ::kiemtra()
{
    if(nam < 0 || thang <= 0 || thang > 12)
        return false;
    if(nam % 4 == 0 && nam % 100 != 0 || nam % 400 == 0)
    {
        switch(thang)
        {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if(ngay <= 0 || ngay > 31)
                return false;
            break;
        case 4: case 6: case 9: case 11:
            if(ngay <= 0 || ngay > 30)
                return false;
            break;
        case 2:
            if(ngay <= 0 || ngay > 29)
                return false;
            break;
        }
    }

    else
    {
        switch(thang)
        {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if(ngay <= 0 || ngay > 31)
                return false;
            break;
        case 4: case 6: case 9: case 11:
            if(ngay <= 0 || ngay > 30)
                return false;
            break;
        case 2:
            if(ngay <= 0 || ngay > 28)
                return false;
            break;
        }
    }

    return true;
}

void NhanVien ::Nhap()
{
    cout << "Nhap thong tin nhan vien vao: \n";
    cout << "Nhap ten nhan vien: ";
    cin.ignore();
    getline(cin, HoTen);
    do
    {
        cout << "Nhap ngay thang nam sinh cua nhan vien: ";
        cin >> ngay >> thang >> nam;
    }while(kiemtra() == false);
}

void NhanVien ::Xuat()
{
    cout << "THONG TIN CUA NHAN VIEN\n";
    cout << "+Ten Nhan vien: " << HoTen << endl;
    cout << "+Ngay thang nam: " << ngay << "/" << thang << "/" << nam << endl;
}

long NhanVien ::Tinh_luong()
{
    return Luong;
}

//NVVP
NVVP ::NVVP()
{
    songaylamviec = 0;
}

NVVP ::~NVVP()
{
    songaylamviec = 0;
}

void NVVP::Nhap()
{
    NhanVien ::Nhap();
    cout << "Nhap so ngay lam viec cua nhan vien: ";
    cin >> songaylamviec;
}

void NVVP ::Xuat()
{
    NhanVien ::Xuat();
    cout << "+So ngay lam viec cua nhan vien: " << songaylamviec << endl;
    cout << "+Luong cua nhan vien van phong la: " << Tinh_luong();
    cout << endl;
}

long NVVP ::Tinh_luong()
{
    Luong = songaylamviec * 100000;
    return Luong;
}

//NVSX
NVSX ::NVSX()
{
    Luongcoban = 0;
    sosanpham = 0;
}

NVSX ::~NVSX()
{
    Luongcoban = 0;
    sosanpham = 0;
}

void NVSX ::Nhap()
{
    NhanVien ::Nhap();
    cout << "Nhap luong co ban cua nhan vien: ";
    cin >> Luongcoban;
    cout << "Nhap so san pham nhan vien lam duoc: ";
    cin >> sosanpham;
}

void NVSX ::Xuat()
{
    NhanVien ::Xuat();
    cout << "+Luong co ban cua nhan vien: " << Luongcoban << endl;
    cout << "+So san pham nhan vien lam duoc: " << sosanpham << endl;
    cout << "+Luong cua nhan vien: " << Tinh_luong();
    cout << endl;
}

long NVSX ::Tinh_luong()
{
    Luong = Luongcoban + sosanpham * 5000;
    return Luong;
}

int main()
{
    cout << "Nhap so luong nhan vien van phong: ";
    int n1;
    cin >> n1;
    NhanVien *x[n1];
    for(int i = 0; i < n1; i++)
    {
        int n;
        do
        {
            cout << "Nhap 1 de nhap nhan vien van phong, 2 de nhap nhan vien san xuat: ";
            cin >> n;
        }while(n > 2 || n < 1);
        if(n == 1)
        {
            cout << "Nhan vien van phong\n";
            x[i] = new NVVP;
            x[i]->Nhap();
        }
        else if(n == 2)
        {
            cout << "Nhan vien san xuat\n";
            x[i] = new NVSX;
            x[i]->Nhap();
        }
    }

    cout << "\n===Danh sach nhan vien===\n";
    for(int i = 0; i < n1; i++)
    {
        x[i]->Xuat();
    }

    cout << "\n===Nhan vien co luong cao nhat, nhan vien co luong thap nhat===\n";
    int max = 0;
    int min = 0;
    for(int i = 0; i < n1; i++)
    {
        if(x[i]->Tinh_luong() > x[max]->Tinh_luong())
        {
            max = i;
        }
        if(x[i]->Tinh_luong() < x[min]->Tinh_luong())
        {
            min = i;
        }
    }
    cout << "Nhan vien co luong cao nhat: \n";
    x[max]->Xuat();
    cout << "Nhan vien co luong thap nhat: \n";
    x[min]->Xuat();
    return 0;
}
