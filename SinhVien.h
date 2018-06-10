#pragma once
#include "bandoc.h"
class SinhVien :
	virtual public BanDoc
{
private:
	int nNienKhoa;
public:
	int getNienKhoa();
	void setNienKhoa(int nK);
	void output();
	int get_LoaiBD();
	SinhVien(string sMaBD = "",string sHoTen = "", string sKhoa = "", int nNgay = 0, int nThang = 0, int nNam = 0,int nNienKhoa =0):BanDoc(sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam)
	{
		this->nNienKhoa = nNienKhoa;
	}
	virtual~SinhVien(void){};
};

