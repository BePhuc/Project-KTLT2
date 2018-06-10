#pragma once
#include "bandoc.h"
class GiaoVien :
	virtual public BanDoc
{
private:
	string sDiaChi;
	string sSDT;
public:
	string getDiaChi ();
	string getSTD();
	void setDiaChi (string sDC);
	void setSDT (string sSDT);
	void output();
	int get_LoaiBD();
	GiaoVien(string sMaBD = "",string sHoTen = "", string sKhoa = "", int nNgay = 0, int nThang = 0, int nNam = 0, string sDiaChi = "", string sSDT = ""):BanDoc(sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam)
	{
		this->sDiaChi = sDiaChi;
		this->sSDT = sSDT;
	}
	virtual~GiaoVien(void){};
};

