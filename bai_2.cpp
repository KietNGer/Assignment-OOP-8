#include<iostream>
#include<string.h>
#include<math.h>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

class Nguoi
{
protected:
    string HoTen;
    int NamSinh;
    string DiaChi;
public:
    Nguoi();
    ~Nguoi();
    virtual void Nhap();
    virtual void Xuat();
};

class SinhVien : public Nguoi
{
protected:
    int MaSV;
    double DiemTB;
public:
    SinhVien();
    ~SinhVien();
    void Nhap();
    void Xuat();
};

class CongNhan : public Nguoi
{
protected:
    int LuongCoBan;
    int SoNgayPhep;
    int SoNamKN;
public:
    CongNhan();
    ~CongNhan();
    void Nhap();
    void Xuat();
};

class CaSi :public Nguoi
{
protected:
    string DongNhac;
    int SoShowDaDien;
    int SoAlbumRaMat;
public:
    CaSi();
    ~CaSi();
    void Nhap();
    void Xuat();
};

class BacSi :public Nguoi
{
protected:
    string KhoaChuyenMon;
    int SoNamChuaBenh;
public:
    BacSi();
    ~BacSi();
    void Nhap();
    void Xuat();
};

//Nguoi
Nguoi ::Nguoi()
{
    HoTen = " ";
    NamSinh = 0;
    DiaChi = " ";
}

Nguoi ::~Nguoi()
{
    HoTen = " ";
    NamSinh = 0;
    DiaChi = " ";
}

void Nguoi ::Nhap()
{
    cout << "Nhap ten: ";
    cin.ignore();
    getline(cin, HoTen);
    cout << "Nhap nam sinh: ";
    cin >> NamSinh;
    cout << "Nhap dia chi: ";
    cin.ignore();
    getline(cin, DiaChi);
}

void Nguoi ::Xuat()
{
    cout << "+Ten: " << HoTen << endl;
    cout << "+Nam sinh: " << NamSinh << endl;
    cout << "+Dia chi: " << DiaChi << endl;
}

//Sinh vien
SinhVien ::SinhVien()
{
    MaSV = 0;
    DiemTB = 0;
}

SinhVien ::~SinhVien()
{
    MaSV = 0;
    DiemTB = 0;
}

void SinhVien ::Nhap()
{
    Nguoi ::Nhap();
    cout << "Nhap ma sinh vien: ";
    cin >> MaSV;
    cout << "Nhap diem trung binh: ";
    cin >> DiemTB;
}

void SinhVien ::Xuat()
{
    Nguoi ::Xuat();
    cout << "+Ma sinh vien: " << MaSV << endl;
    cout << "+Diem trung binh: " << DiemTB << endl;
}

//Cong nhan
CongNhan ::CongNhan()
{
    LuongCoBan = 0;
    SoNgayPhep = 0;
    SoNamKN = 0;
}

CongNhan ::~CongNhan()
{
    LuongCoBan = 0;
    SoNgayPhep = 0;
    SoNamKN = 0;
}

void CongNhan ::Nhap()
{
    Nguoi ::Nhap();
    cout << "Nhap so luong co ban: ";
    cin >> LuongCoBan;
    cout << "Nhap so ngay phep: ";
    cin >> SoNgayPhep;
    cout << "So nam kinh nghiem: ";
    cin >> SoNamKN;
}

void CongNhan ::Xuat()
{
    Nguoi ::Xuat();
    cout << "+Luong co ban: " << LuongCoBan << endl;
    cout << "+So ngay phep: " << SoNgayPhep << endl;
    cout << "+So nam kinh nghiem: " << SoNamKN << endl;
}

//Ca si
CaSi ::CaSi()
{
    DongNhac = "";
    SoShowDaDien = 0;
    SoAlbumRaMat = 0;
}

CaSi ::~CaSi()
{
    DongNhac = "";
    SoShowDaDien = 0;
    SoAlbumRaMat = 0;
}

void CaSi ::Nhap()
{
    Nguoi ::Nhap();
    cout << "Nhap dong nhac: ";
    cin.ignore();
    getline(cin, DongNhac);
    cout << "Nhap so show da dien: ";
    cin >> SoShowDaDien;
    cout << "Nhap so album ra mat: ";
    cin >> SoAlbumRaMat;
}

void CaSi ::Xuat()
{
    Nguoi ::Xuat();
    cout << "+Dong Nhac: " << DongNhac << endl;
    cout << "+So show da dien: " << SoShowDaDien << endl;
    cout << "+So Album ra mat: " << SoAlbumRaMat << endl;
}

//Bac si
BacSi ::BacSi()
{
    KhoaChuyenMon = "";
    SoNamChuaBenh = 0;
}

BacSi ::~BacSi()
{
    KhoaChuyenMon = "";
    SoNamChuaBenh = 0;
}

void BacSi ::Nhap()
{
    Nguoi ::Nhap();
    cout << "Nhap khoa chuyen mon: ";
    cin.ignore();
    getline(cin, KhoaChuyenMon);
    cout << "Nhap so nam chua benh: ";
    cin >> SoNamChuaBenh;;
}

void BacSi ::Xuat()
{
    Nguoi ::Xuat();
    cout << "+Khoa chuyen mon: " << KhoaChuyenMon << endl;
    cout << "+So nam chua benh: " << SoNamChuaBenh << endl;
}

int main()
{
    cout << "Nhap so luong doi tuong muon nhap: ";
    int n;
    cin >> n;
    vector <Nguoi*> a;
    int n1 = 0, n2 = 0, n3 = 0, n4 = 0;
    while(n--)
    {
        Nguoi *x = NULL;
        cout << "\t1.Nhap sinh vien\n";
        cout << "\t2.Nhap cong nhan\n";
        cout << "\t3.Nhap ca si\n";
        cout << "\t4.Nhap ba si\n";

        int t;
        cout << "==>> Nhap lua chon: ";
        cin >> t;

        switch(t)
        {
        case 1:
        {
            x = new SinhVien;
            x->Nhap();
            a.push_back(x);
            n1++;
            break;
        }

        case 2:
        {
            x = new CongNhan;
            x->Nhap();
            a.push_back(x);
            n2++;
            break;
        }

        case 3:
        {
            x = new CaSi;
            x->Nhap();
            a.push_back(x);
            n3++;
            break;
        }

        case 4:
        {
            x = new BacSi;
            x->Nhap();
            a.push_back(x);
            n4++;
            break;
        }
        }
    }

    cout << "\n====Danh sach vua nhap====";
    for(int i = 0; i < a.size(); i++)
    {
        cout << "\n";
        a[i]->Xuat();
        cout << "\n-------------------------------\n";
    }

    cout << "\nTrong danh sach co: ";
    cout << "\t+" << n1 << "sinh vien\n";
    cout << "\t+" << n2 << "cong nhan\n";
    cout << "\t+" << n3 << "ca si\n";
    cout << "\t+" << n4 << "bac si\n";
    return 0;
}
