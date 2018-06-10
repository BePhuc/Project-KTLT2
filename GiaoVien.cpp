#include "GiaoVien.h"



int GiaoVien::get_LoaiBD()
{
	return 1;
}
string GiaoVien::getDiaChi ()
{
	return this->sDiaChi;
}
string GiaoVien::getSTD()
{
	return this->sSDT;
}
void GiaoVien::setDiaChi (string sDC)
{
	this->sDiaChi = sDC;
}
void GiaoVien::setSDT (string sSDT)
{
	this->sSDT = sSDT;
}
void GiaoVien::output()
{
	BanDoc::xuatBD();
	cout << "Dia chi: " << this->sDiaChi << endl;
	cout << "SDT: " << this->sSDT << endl;
}
