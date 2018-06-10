#include "SinhVien.h"


int SinhVien::get_LoaiBD()
{
	return 2;
}
int SinhVien::getNienKhoa()
{
	return this->nNienKhoa;
}
void SinhVien::setNienKhoa(int  nK)
{
	this->nNienKhoa = nK;
}
void SinhVien::output()
{
	BanDoc::xuatBD();
	cout << "Khoa hoc: " << this->nNienKhoa << endl;
}



