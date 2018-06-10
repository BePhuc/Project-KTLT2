#pragma once
#include "ThoiGian.h"
#include <iostream>
#include <string>
using namespace std;
class ThoiGian;
class Sach
{
private:
	string sMaSach; 
	string sTuaDe;
	string sTacGia;
	string sNXB;
	int nGiaTien;
	int nNamPhatHanh;
	int nSoTrang;
	ThoiGian xNgay;
	int nTinhTrang;
public:
	friend ThoiGian;
	string getMaSach();
	string getTuaDe();
	string getTacGia();
	string getNXB();
	int getGiaTien();
	int getNamPH();
	int getSoTrang();
	int getNgayNhapKho();
	int getThangNhapKho();
	int getNamNhapKho();
	int getTinhTrang();
	void setMaSach(string sMa);
	void setTuaDe(string sTuaDe);
	void setTacGia(string sTG);
	void setNXB(string sNXB);
	void setGiaTien(int nTien);
	void setNamPH(int nNamPH);
	void setSoTrang(int nSoTrang);
	void setTinhTrang(int nTT);
	void setNgayNhapKho(int nN);
	void setThangNhapKho(int nT);
	void setNamNhapKho(int nN);
	void xuatSach();
	Sach(string sMa = "", string sTuaDe="", string sTacGia="", string sNXB="", int nTien = 0, int nNamPH = 0, int nSoTrang = 0,int nNgay = 0, int nThang = 0, int nNam = 0, int nTinhTrang = 0):xNgay(nNgay,nThang,nNam)
	{
		this->sMaSach = sMa;
		this->sTuaDe = sTuaDe;
		this->sTacGia = sTacGia;
		this->sNXB = sNXB;
		this->nGiaTien = nTien;
		this->nNamPhatHanh = nNamPH;
		this->nSoTrang = nSoTrang;
		this->xNgay = xNgay;
		this->nTinhTrang = nTinhTrang;
	}
	~Sach(void){};
};
