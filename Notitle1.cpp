#include <bits/stdc++.h>
using namespace std;

class HocVien{
    protected:
        int MaHV;
        string Hoten;
        double Chuyencan;
        double Giuaky;
        double Cuoiky;
    public:
        virtual ~HocVien(){}
        virtual void nhap();
        virtual void xuat();
        virtual double Tongket();
};

void HocVien::nhap(){
    cout << "\nNhap ma hoc vien: ";
    cin >> MaHV;
    cout << "\nNhap ho ten hoc vien: ";
    cin >> ws;
    getline(cin,Hoten);
    cout << "\nNhap diem chuyen can: ";
    cin >> Chuyencan;
    cout << "\nNhap diem giua ky: ";
    cin >> Giuaky;
    cout << "\nNhap diem cuoi ky: ";
    cin >> Cuoiky;
}

double HocVien::Tongket(){
    return 0.1*Chuyencan + 0.3*Giuaky + 0.6*Cuoiky;
}

void HocVien::xuat(){
    cout << "\nMa hoc vien: " << MaHV;
    cout << "\nHo ten hoc vien: " << Hoten;
    cout << "\nDiem chuyen can: " << Chuyencan;
    cout << "\nDiem giua ky: " << Giuaky;
    cout << "\nDiem cuoi ky: " << Cuoiky;
}

class HocVienHocBong : public HocVien{
    private:
        int HocBong;
    public:
        void nhap() override;
        void xuat() override;
        double Tongket() override;
};

void HocVienHocBong::nhap(){
    HocVien::nhap();
    cout << "\nNhap muc hoc bong: ";
    cin >> HocBong;
}

void HocVienHocBong::xuat(){
    HocVien::xuat();
    cout << "\nMuc hoc bong: " << HocBong << "%";
}

double HocVienHocBong::Tongket(){
    double diemHB = (HocBong/100.0)*0.5;
    if(diemHB < 0.5) return 0.1*Chuyencan + 0.3*Giuaky + 0.6*Cuoiky + diemHB;
    else return 0.1*Chuyencan + 0.3*Giuaky + 0.6*Cuoiky + 0.5;
}

class LopHoc{
    private:
        int SoHocVien;
        HocVien* ds[1000];
    public:
        ~LopHoc(){
            for(int i = 0; i < SoHocVien; i++) delete ds[i];
        }
        void nhap();
        void xuat();
        void xuatkemdiemtongket();
        double tinhDiemTB();
        void dshocvientren8();
        void tongketcaonhat();
};

void LopHoc::nhap(){
    cout << "Nhap so luong hoc vien: ";
    cin >> SoHocVien;
    int LoaiHV;
    for(int i = 0; i < SoHocVien; i++){
        cout << "\nNhap loai hoc vien(Thuong: 0, Hoc bong: 1): ";
        cin >> LoaiHV;
        if(LoaiHV == 0) ds[i] = new HocVien;
        else if(LoaiHV == 1) ds[i] = new HocVienHocBong;
        ds[i]->nhap();
    }
}

void LopHoc::xuat(){
    cout << "\nDanh sach hoc vien: ";
    for(int i = 0; i < SoHocVien; i++) ds[i]->xuat();
}

void LopHoc::xuatkemdiemtongket(){
    cout << "\nDanh sach hoc vien kem diem tong ket: ";
    for(int i = 0; i < SoHocVien; i++){
        ds[i]->xuat();
        cout << "\nDiem tong ket: "<< ds[i]->Tongket();
    }
}

double LopHoc::tinhDiemTB(){
    double tongDiem = 0;
    for(int i = 0; i < SoHocVien; i++) tongDiem += ds[i]->Tongket();
    return tongDiem/SoHocVien;
}

void LopHoc::dshocvientren8(){
    int found = false;
    for(int i = 0; i < SoHocVien; i++){
        double diemTK = ds[i]->Tongket();
        if(diemTK >= 8){
            found = true;
            break;
        }
    }
    if(found){
        cout << "\nDanh sach hoc vien co diem tong ket tren 8: ";
        for(int i = 0; i < SoHocVien; i++){
            double diemTK = ds[i]->Tongket();
            if(diemTK >= 8){
                ds[i]->xuat();
            }
        }
    }
    else cout << "\nKhong co hoc vien nao tren 8";
}

void LopHoc::tongketcaonhat(){
    double diemCaoNhat = 0;
    int maSo = -1;
    for(int i = 0; i < SoHocVien; i++){
        double diemTK = ds[i]->Tongket();
        if(diemTK > diemCaoNhat){
            diemCaoNhat = diemTK;
            maSo = i;
        }
    }
    if(diemCaoNhat == 0) cout << "\nKhong co hoc vien";
    else {
        cout << "\nHoc vien co diem cao nhat: ";
        ds[maSo]->xuat();
    }
}

int main(){
    LopHoc MaSoi;
    MaSoi.nhap();
    cout << "\nTen lop hoc: Lop Hoc Ma Soi";
    MaSoi.xuat();
    MaSoi.xuatkemdiemtongket();
    cout << "\nDiem trung binh lop hoc: " << MaSoi.tinhDiemTB();
    MaSoi.dshocvientren8();
    MaSoi.tongketcaonhat();
    return 0;
}