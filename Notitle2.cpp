#include <iostream>
using namespace std;

class Thucung{
    protected:
        string Ten;
        int Tuoi;
    public:
        virtual ~Thucung(){}
        virtual void keu() = 0;
        virtual void nhap();
        virtual void xuat();
};

void Thucung::nhap(){
    cout << "\nNhap ten: ";
    cin >> ws;
    getline(cin, Ten);
    cout << "\nNhap tuoi: ";
    cin >> Tuoi;
}

void Thucung::xuat(){
    cout << "\nTen: " << Ten;
    cout << "\nTuoi: " << Tuoi;
}

class Meo : public Thucung{
    private:
        string MauLong;
    public:
        void keu() override;
        void nhap() override;
        void xuat() override;
};

void Meo::keu(){
    cout << "\nMeo meo!";
}

void Meo::nhap(){
    Thucung::nhap();
    cout << "\nNhap mau long: ";
    cin >> ws;
    getline(cin, MauLong);
}

void Meo::xuat(){
    cout << "\nLoai: Meo";
    Thucung::xuat();
    cout << "\nMau long: " << MauLong;
}

class Cho : public Thucung{
    private:
        string Giong;
    public:
        void keu() override;
        void nhap() override;
        void xuat() override;
};

void Cho::keu(){
    cout << "\nGau gau!";
}

void Cho::nhap(){
    Thucung::nhap();
    cout << "\nNhap giong: ";
    cin >> ws;
    getline(cin, Giong);
}

void Cho::xuat(){
    cout << "\nLoai: Cho";
    Thucung::xuat();
    cout << "\nGiong: " << Giong;
}

class VuonThu{
    private:
        int SoLuong;
        Thucung* ds[100];
    public:
        ~VuonThu(){
            for(int i = 0; i < SoLuong; i++) delete ds[i];
        }
        void themMeo();
        void themCho();
        void nhap();
        void xuat();
};

void VuonThu::nhap(){
    cout << "\nNhap so luong thu cung: ";
    cin >> SoLuong;
    int Loai;
    for(int i = 0; i < SoLuong; i++){
        cout << "\nNhap loai thu cung (Meo: 0, Cho: 1): ";
        cin >> Loai;
        if(Loai == 0) ds[i] = new Meo;
        else if(Loai == 1) ds[i] = new Cho;
        ds[i]->nhap();
    }
}

void VuonThu::xuat(){
    for(int i = 0; i < SoLuong; i++){
        ds[i]->xuat();
    }
}

void VuonThu::themMeo(){
    ds[SoLuong] = new Meo;
    ds[SoLuong]->nhap();
    SoLuong++;
}

void VuonThu::themCho(){
    ds[SoLuong] = new Cho;
    ds[SoLuong]->nhap();
    SoLuong++;
}

int main(){
    VuonThu VuiVe;
    cout << "\nNhap thong tin vuon thu: ";
    VuiVe.nhap();
    int choice;
    do{
        cout << "\n1. Thêm mèo";
        cout << "\n2. Thêm chó";
        cout << "\n3. Hiển thị danh sách thú cưng";
        cout << "\n4. Thoát";
        cout << "\nNhập lựa chọn: ";
        cin >> choice;
        switch(choice){
            case 1:
                VuiVe.themMeo();
                break;
            case 2:
                VuiVe.themCho();
                break;
            case 3:
                VuiVe.xuat();
                break;
            case 4:
                cout << "\nThoát chương trình.";
                break;
            default:
                cout << "\nLựa chọn không hợp lệ. Vui lòng chọn lại.";
                break;
        }
    }while(choice != 4);
}