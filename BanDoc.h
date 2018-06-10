#pragma once
#include <string>
#include "ThoiGian.h"
using namespace std;
class ThoiGian;
class BanDoc
{
protected:
	string sMaBD;
	string sHoTen;
	string sKhoa;
	ThoiGian xNgayDK;
public:
	friend ThoiGian;
	virtual int get_LoaiBD(){return 0;};
	virtual void output(){};
	void xuatBD();
	string getMaBD();
	string getTen();
	string getKhoa();
	int getNgay();
	int geTThang();
	int getNam();
	void setMaBD (string sMa);
	void setTen (string sTen);
	void setKhoa (string sKhoa);
	void setNgay(int nN);
	void setThang(int nT);
	void setNam (int nN);
	BanDoc(string sMaBD = "",string sHoTen = "", string sKhoa = "", int nNgay = 0, int nThang = 0, int nNam = 0):xNgayDK(nNgay, nThang, nNam)
	{
		this->sMaBD = sMaBD;
		this->sHoTen = sHoTen;
		this->sKhoa = sKhoa;
		this->xNgayDK = xNgayDK;
	}
	virtual~BanDoc(void){};
};
