#include <time.h>
#include "GiaoVien.h"
#include "SinhVien.h"
#include "ThoiGian.h"
#include "PhieuMuon.h"
#include "Sach.h"
#include "QuanLyThuVien.h"
#include <iomanip>
#include <fstream>
#include <conio.h>
#include <Windows.h>
//Bien toan cuc
#define MAX 50
int PhieuMuon::nTongPM = 0;
//Khai bao nguyen mau ham
void Color(int nX); //Nguon: https://zfull.net/thu-thuat-it/doi-mau-chu-va-mau-nen-don-gian-trong-c/
void PassWord(char pass[]); //Nguon: http://diendan.congdongcviet.com/threads/t1944::lap-trinh-cpp-tao-password-trong-cpp.cpp
void inputFileQuanLy (QuanLyThuVien *a[], int &nSpt);
void outputQuanLy_toScreen (QuanLyThuVien *a[], int nSpt);
void inputFileSach (Sach *pa[], int &nSpt);
void outputSach_toScreen (Sach *b[], int nSpt);
void inputFileBanDoc (BanDoc *c[], int &nSpt);
void outputBanDoc_toScreen (BanDoc *c[], int nSpt);
void inputFilePhieuMuon (PhieuMuon *d[], int &nSpt);
void outputPhieuMuon_toScreen (PhieuMuon *d[], int nSpt);
void taoPhieuMuon (PhieuMuon *d[], int &nTongSoPM,BanDoc *c[], int nSoBanDoc, Sach *b[], int &nSoSach);
void traSach (PhieuMuon *d[], int &nTongSoPM,BanDoc *c[], int nSoBanDoc,Sach *b[], int nSoSach);
bool kiemTraBanDoc (BanDoc *c[] ,int nSoBanDoc,string sMaBD);
bool kiemTraSachDeMuon (Sach *b[], int nSach,string sMaSach);
bool kiemTraTaiKhoanDangNhap (QuanLyThuVien *a[], int nSpt,string sID, string sPass);
bool kiemTraSachTrung (Sach *b[], int nSpt, string sMaSach);
bool kiemTraTKTrung (BanDoc *c[], int nSpt, string sMaBD);
void dangNhap (QuanLyThuVien *a[], int nSpt, string &sID, string &sPass,int &nLanSai);
void timKiemThongTin (Sach *b[], int nSoSach, BanDoc *c[], int nSoBD);
void QuanLy (QuanLyThuVien *a[], int nAd, Sach *b[], int &nSach, BanDoc *c[], int &nSoBanDoc, PhieuMuon *d[], int &nTongSoPM);
void ghiPhieuMuonRaFile (PhieuMuon *d[], int nSpt);
void ghiSachRaFile (Sach *b[], int nSpt);
int tinhSachMuon (Sach *b[], int nSpt);
int tinhSachTrongThuVien (Sach *b[], int nSpt);
void main()
{
	int nChonCNCon = 0;
	char ch[20];
	string sID, sPass;
	string sTuaDe;
	int i;
	int nChonCN = 0;
	int nA, nB, nC, nD;
	QuanLyThuVien *a[MAX];
	Sach *b [MAX];
	BanDoc *c[MAX];
	PhieuMuon *d[MAX];
	//Doc file
	inputFileQuanLy(a,nA);
	inputFileSach (b,nB);
	inputFileBanDoc (c,nC);
	inputFilePhieuMuon (d,nD);
	//Tao menu
	do
	{
		system("cls");
		cout << "\t\t*                  Quan Ly Thu Vien           *\n"; 
		cout << "\n\t  1. Hien thi sach\n";
		cout << "\t  2. Hien thi ban doc\n";
		cout << "\t  3. Tim kiem sach\n";
		cout << "\t  4. Quan ly\n";
		cout << "\t  5. Thoat!\n";
		cout << "Chon chuc nang: ";
		cin >> nChonCN;
		switch(nChonCN)
		{
		case 1:
			outputSach_toScreen (b,nB);
			break;
		case 2:
			outputBanDoc_toScreen (c,nC);
			break;
		case 3:
			cout << "Nhap tua de sach: ";
			fflush(stdin);
			getline(cin,sTuaDe);
			for (i = 0; i < nB; i++)
			{
				if (b[i]->getTuaDe() == sTuaDe)
				{
					b[i]->xuatSach();
					break;
				}
				
			}
			break;
		case 4:
			do
			{
				system("cls");
				cout << "\t\t*                  Dang nhap          *\n"; 
				cout << "Nhap ID: ";
				fflush(stdin);
				getline(cin,sID);
				cout << "Nhap Pass: ";
				fflush(stdin);
				PassWord(ch);
				sPass = ch;
				cout << endl;
			}while (kiemTraTaiKhoanDangNhap (a,nA,sID,sPass)== false);
			do
			{
				system("cls");
				cout << "\t\t*                  Dang nhap          *\n"; 
				cout << "\n\t1. Tao phieu muon\n";
				cout << "\t2. Tra Sach\n";
				cout << "\t3. Xuat phieu muon\n";
				cout << "\t4. So sach dang duoc muon\n";
				cout << "\t5. So sach con lai trong thu vien\n";
				cout << "\t6. Thoat!\n";
				cout << "Chon chuc nang: ";
				cin >> nChonCNCon;
				switch(nChonCNCon)
				{
				case 1:
					taoPhieuMuon (d, nD,c,nC, b, nB);
						 ghiPhieuMuonRaFile (d,nD);
						 ghiSachRaFile (b,nB);
					break;
				case 2:
					traSach (d, nD,c,nC,b, nB);
					ghiPhieuMuonRaFile (d,nD);
					ghiSachRaFile (b,nB);
					break;
				case 3:
					cout << "Xuat thong tin phieu muon: \n";
					outputPhieuMuon_toScreen(d,nD);
					break;
				case 4:
					cout << "So sach dang duoc muon la: " <<  tinhSachMuon (b,nB) << endl;
					break;
				case 5:
					cout << "So sach con lai trong thu vien la: " << tinhSachTrongThuVien(b,nB) << endl;
					break;
				case 6:
					return;
				default:
					cout << "Thoat!!\n";
				}
				system("pause");
			}while(nChonCNCon >= 1 && nChonCNCon <= 6);
			break;
		case 5:
			return;
		default:
			cout << "Thoat!!\n";
		}
		system("pause");
	}while (nChonCN >= 1 && nChonCN <= 5);
	system("pause");
}
int tinhSachTrongThuVien (Sach *b[], int nSpt)
{
	int nDem = 0;
	for (int i = 0; i < nSpt; i++)
	{
		if (b[i]->getTinhTrang() == 0)
			nDem++;
	}
	if (nDem != 0)
		return nDem;
	else
		return -1;
}
int tinhSachMuon (Sach *b[], int nSpt)
{
	int nDem = 0;
	for (int i = 0; i < nSpt; i++)
	{
		if (b[i]->getTinhTrang() != 0)
			nDem++;
	}
	if (nDem != 0)
		return nDem;
	else
		return -1;
}
void outputPhieuMuon_toScreen (PhieuMuon *d[], int nSpt)
{
	for (int i = 0; i < nSpt; i++)
	{
		d[i]->output();
	}
}
void inputFilePhieuMuon (PhieuMuon *d[], int &nSpt)
{
	int nSPM = 0;
	string sMaBD = "";
	string sMaSach = "";
	int nNgayMuon = 0;
	int nThangMuon = 0;
	int nNamMuon = 0;
	int nNgayTra = 0;
	int nThangTra = 0;
	int nNamTra = 0;
	int nTrangThai = 0;
	ifstream file;
	file.open("PhieuMuon.txt");
		file >> nSpt;
	file.ignore(1,'\n');
	for (int i = 0; i < nSpt; i++)
	{
		file >> nSPM;
		file.ignore(1,'#');
		fflush(stdin);
		getline(file,sMaBD,'#');
		fflush(stdin);
		getline(file,sMaSach,'#');
		file >> nNgayMuon;
		file.ignore(1,'#');
		file >> nThangMuon;
		file.ignore(1,'#');
		file >> nNamMuon;
		file.ignore(1,'#');
		file >> nNgayTra;
		file.ignore(1,'#');
		file >> nThangTra;
		file.ignore(1,'#');
		file >> nNamTra;
		file.ignore(1,'#');
		file >> nTrangThai;
		file.ignore(1,'\n');
		d[i] = new PhieuMuon (nSPM, sMaBD,sMaSach,nNgayMuon,nThangMuon,nNamMuon,nNgayTra,nThangTra,nNamTra,nTrangThai);
	}
}
void ghiPhieuMuonRaFile (PhieuMuon *d[], int nSpt)
{
	ofstream file;
	file.open("PhieuMuon.txt");
	file << nSpt << endl;
	for (int i = 0; i < nSpt; i++)
	{
		file<< d[i]->getMaPM() << "#"
			<< d[i]->getBanDoc().getMaBD() << "#"
			<< d[i]->getSach().getMaSach() << "#"
			<< d[i]->getNgayMuon().getNgay() << "#"
			<< d[i]->getNgayMuon().getThang() << "#"
			<< d[i]->getNgayMuon().getNam() << "#"
			<< d[i]->getNgayTra().getNgay() << "#"
			<< d[i]->getNgayTra().getThang() << "#"
			<< d[i]->getNgayTra().getNam() << "#"
			<< d[i]->getTrangThai() << endl;
	}
	file.close();
}
void traSach (PhieuMuon *d[], int &nTongSoPM,BanDoc *c[], int nSoBanDoc,Sach *b[], int nSoSach)
{
	int nMaPM = 0;
	cout << "Nhap ma PM: ";
	cin >> nMaPM;
	for (int i = 0 ; i< nTongSoPM; i++)
	{
		if (d[i]->getMaPM() == nMaPM)
		{
			if (d[i]->getTrangThai() != 0)
			{
				d[i]->setTrangThai(0); 
				string sMaSach = d[i]->getSach().getMaSach(); 
				for (int j = 0; j < nSoSach; j++)
				{
					if (b[j]->getMaSach() == sMaSach)
					{
						b[j]->setTinhTrang(0);
						break;
					}
					
				}
			}
			
		}

	}
	
}
void taoPhieuMuon (PhieuMuon *d[], int &nTongSoPM,BanDoc *c[], int nSoBanDoc, Sach *b[], int &nSoSach)
{
	string sMaBD ="";
	string sMaSach ="";
	do
	{
			cout << "\nNhap ma ban doc: ";
	fflush(stdin);
	getline (cin,sMaBD);
	}while (kiemTraBanDoc (c,nSoBanDoc,sMaBD) == false);
	do
	{
			cout << "\nNhap ma sach: ";
	fflush(stdin);
	getline(cin,sMaSach);
	}while (kiemTraSachDeMuon (b,nSoSach,sMaSach) == false);
	PhieuMuon *p = new PhieuMuon(sMaBD,sMaSach);
	int nViTri = nTongSoPM;
	for (int i = nTongSoPM; i > nViTri; i--)
	{	d[i] = d[i-1];}
	d[nViTri] = p;
	nTongSoPM++;
	
	int nTrangThai = p->getMaPM();
	for (int j = 0; j < nSoSach; j++)
	{
		if (b[j]->getMaSach() == sMaSach)
		{
			b[j]->setTinhTrang(nTrangThai);
			break;
		}
		
	}
}
void outputBanDoc_toScreen (BanDoc *c[], int nSpt)
{
	for (int i = 0; i < nSpt; i++)
	{
		c[i]->output();
		cout << endl;
	}
}
void inputFileBanDoc (BanDoc *c[], int &nSpt)
{
	int nLoai = 0;
	string sMa = "", sTen = "", sKhoa = "";
	int nNgay = 0, nThang = 0, nNam = 0;
	int nKhoaHoc = 0;
	int nNienKhoa = 0;
	string sDiaChi = "", sSDT = "";
	ifstream file;
	file.open("BanDoc.txt");
	file >> nSpt;
	file.ignore(1,'\n');
	for (int i =0; i < nSpt; i++)
	{
		file >> nLoai;
		file.ignore(1,'#');
		if (nLoai == 1) //GV
		{
			fflush(stdin);
			getline(file,sMa,'#');
			fflush(stdin);
			getline(file,sTen,'#');
			fflush(stdin);
			getline(file,sKhoa,'#');
			file >> nNgay;
			file.ignore(1,'#');
			file >> nThang;
			file.ignore(1,'#');
			file >> nNam;
			file.ignore(1,'#');
			fflush(stdin);
			getline(file,sDiaChi,'#');
			fflush(stdin);
			getline(file,sSDT,'\n');
			c[i] = new GiaoVien (sMa,sTen,sKhoa,nNgay,nThang,nNam,sDiaChi,sSDT);
		}
		else 
		{
			fflush(stdin);
			getline(file,sMa,'#');
			fflush(stdin);
			getline(file,sTen,'#');
			fflush(stdin);
			getline(file,sKhoa,'#');
			file >> nNgay;
			file.ignore(1,'#');
			file >> nThang;
			file.ignore(1,'#');
			file >> nNam;
			file.ignore(1,'#');
			file >> nNienKhoa;
			file.ignore(1,'\n');
			c[i] = new SinhVien (sMa, sTen, sKhoa, nNgay, nThang, nNam,nNienKhoa);
		}
	}
	file.close();
}
void inputFileSach (Sach *b[], int &nSpt)
{
	string sMaSach = "", sTuaDe = "",sTacGia = "",
		sNXB = "";
	int nTien = 0, nNamPH = 0,nSoTrang = 0, nNgay = 0, nThang = 0, nNam = 0, nTT = 0;
	ThoiGian xNgayNhap;
	ifstream file;
	file.open("Sach.txt");
	file >> nSpt;
	file.ignore(1,'\n');
	for (int i = 0; i < nSpt; i++)
	{
		fflush(stdin);
		getline(file,sMaSach,'#');
		fflush(stdin);
		getline(file,sTuaDe,'#');
		fflush(stdin);
		getline(file,sTacGia,'#');
		fflush(stdin);
		getline(file,sNXB,'#');
		file >> nTien;
		file.ignore(1,'#');
		file >> nNamPH;
		file.ignore(1,'#');
		file >> nSoTrang;
		file.ignore(1,'#');
		file >> nNgay;
		file.ignore(1,'#');
		file >> nThang;
		file.ignore(1,'#');
		file >> nNam;
		file.ignore(1,'#');
		file >> nTT;
		file.ignore(1,'\n');
		b[i] = new Sach (sMaSach, sTuaDe, sTacGia, sNXB, nTien, nNamPH, nSoTrang, nNgay, nThang, nNam, nTT);
	}
}
void outputSach_toScreen(Sach *b[], int nSpt)
{
	for (int i = 0; i < nSpt; i++ )
	{
		b[i]->xuatSach();
		cout << endl;
	}
}
void ghiSachRaFile (Sach *b[], int nSpt)
{
	ofstream file;
	file.open("Sach.txt");
	file << nSpt << endl;
	for (int i = 0; i < nSpt; i++)
	{
		file << b[i]->getMaSach() << "#"
			<< b[i]->getTuaDe() << "#"
			<< b[i]->getTacGia() << "#"
			<< b[i]->getNXB() << "#"
			<< b[i]->getGiaTien() << "#"
			<< b[i]->getNamPH() << "#"
			<< b[i]->getSoTrang() << "#"
			<< b[i]->getNgayNhapKho() << "#"
			<< b[i]->getThangNhapKho() << "#"
			<< b[i]->getNamNhapKho() << "#"
			<< b[i]->getTinhTrang() << endl;
	}
}
void outputQuanLy_toScreen (QuanLyThuVien *a[], int nSpt)
{
	for (int i = 0; i < nSpt; i++ )
	{
		cout << "Tai khoan: " << a[i]->getID() << endl;
		cout << "Mat khau: " << a[i]->getPass() << endl;
	}
}
void inputFileQuanLy (QuanLyThuVien *a[], int &nSpt)
{
	string sID, sPass;
	ifstream file;
	file.open("QuanLyThuVien.txt");
	file >> nSpt;
	file.ignore(1,'\n');
	for (int i = 0; i < nSpt; i++)
	{

		fflush(stdin);
		getline(file,sID,'#');
		fflush(stdin);
		getline(file,sPass,'\n');
		a[i] = new QuanLyThuVien (sID,sPass);
	}
}
bool kiemTraBanDoc (BanDoc *c[] ,int nSoBanDoc,string sMaBD)
{
	for (int i = 0; i < nSoBanDoc; i++)
	{
		if (c[i]->getMaBD() == sMaBD)
			return true;
	}
	return false;
}
bool kiemTraTKTrung (BanDoc *c[], int nSpt, string sMaBD)
{
	for (int i = 0; i < nSpt; i++)
	{
		if (c[i]->getMaBD() == sMaBD)
			return true;
	}
	return false;

}
bool kiemTraSachTrung (Sach *b[], int nSpt, string sMaSach)
{
	for (int i = 0;i < nSpt; i++)
	{
		if (b[i]->getMaSach() == sMaSach)
			return true;
	}
	return false;
}
bool kiemTraTaiKhoanDangNhap (QuanLyThuVien *a[], int nSpt,string sID, string sPass)
{
	for (int i = 0; i < nSpt; i++)
	{
		if (a[i]->getID() == sID && a[i]->getPass() == sPass)
			return true;
	}
	return false;
}
bool kiemTraSachDeMuon (Sach *b[], int nSach,string sMaSach)
{
	for (int i = 0; i < nSach;i++)
	{
		if (b[i]->getMaSach() == sMaSach && b[i]->getTinhTrang() == 0)
			return true;
	}
	return false;
}
//

void PassWord(char pass[])
{
	char ch;
	int dem=0;
	while((ch=getch())!=13)
	{
		if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9'))
		{
			printf("*");
			pass[dem++]=ch;

		}else
			if(ch==8)
				if(dem>0)
				{
					cout << "\b \b";
					dem--;
				}

	}
	pass[dem]=0;
}
void Color(int nX)
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, nX);
}