#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct SinhVien {
    int maSo;
    char hoDem[21];
    char ten[41];
    int ngaySinh, thangSinh, namSinh;
    char phai[4];
    float diemTB;
};

bool compareByMaSo(const SinhVien& sv1, const SinhVien& sv2) {
    return sv1.maSo < sv2.maSo;
}

int main() {
    // a. Nh?p danh sách sinh viên và lýu vào file
    ofstream file("SINHVIEN.DAT", ios::binary);
    if (!file) {
        cerr << "Khong the mo file SINHVIEN.DAT\n";
        return 1;
    }

    SinhVien sv;
    for (int i = 0; i < 10; i++) {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << ":\n";
        cout << "Ma so: "; cin >> sv.maSo;
        cout << "Ho va dem: "; cin.ignore(); cin.getline(sv.hoDem, 21);
        cout << "Ten: "; cin.getline(sv.ten, 41);
        cout << "Ngay sinh: "; cin >> sv.ngaySinh;
        cout << "Thang sinh: "; cin >> sv.thangSinh;
        cout << "Nam sinh: "; cin >> sv.namSinh;
        cout << "Phai: "; cin >> sv.phai;
        cout << "Diem trung binh: "; cin >> sv.diemTB;
        file.write(reinterpret_cast<char*>(&sv), sizeof(SinhVien));
    }

    file.close();

    // b. S?p x?p và in danh sách sinh viên
    ifstream readFile("SINHVIEN.DAT", ios::binary);
    if (!readFile) {
        cerr << "Khong the mo file SINHVIEN.DAT de doc\n";
        return 1;
    }

    vector<SinhVien> danhSachSV;
    while (readFile.read(reinterpret_cast<char*>(&sv), sizeof(SinhVien))) {
        danhSachSV.push_back(sv);
    }
    readFile.close();

    sort(danhSachSV.begin(), danhSachSV.end(), compareByMaSo);

    cout << "\nDanh sach sinh vien sau khi sap xep theo ma so:\n";
    for (const auto& sinhVien : danhSachSV) {
        cout << "Ma so: " << sinhVien.maSo << ", Ten: " << sinhVien.ten << ", Diem TB: " << sinhVien.diemTB << endl;
    }

    return 0;
}
