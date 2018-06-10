#include "ThoiGian.h"


int ThoiGian::getNgay()
{
	return this->nNgay;
}
int ThoiGian::getThang()
{
	return this->nThang;
}
int ThoiGian::getNam()
{
	return this->nNam;
}
void ThoiGian::setNgay (int nN)
{
	this->nNgay = nN;
}
void ThoiGian::setThang (int nT)
{
	this->nThang = nT;
}
void ThoiGian::setNam (int nNam)
{
	this->nNam = nNam;
}
void ThoiGian::xuat()
{
	cout << this->nNgay << "/" << this->nThang << "/" << this->nNam << endl;
}
