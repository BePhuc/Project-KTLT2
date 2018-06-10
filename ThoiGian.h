#pragma once
#include <iostream>
using namespace std;
class ThoiGian
{
private:
	int nNgay;
	int nThang;
	int nNam;
public:
	void ThoiGian::xuat();
	int getNgay();
	int getThang();
	int getNam();
	void setNgay (int nN);
	void setThang (int nT);
	void setNam (int nNam);
	ThoiGian(void)
	{
		nNgay = 0;
		nThang = 0;
		nNam = 0;
	}
	ThoiGian (int nNgay, int nThang, int nNam)
	{
		this->nNgay = nNgay;
		this->nThang = nThang;
		this->nNam = nNam;
	}
	~ThoiGian(void){};
};