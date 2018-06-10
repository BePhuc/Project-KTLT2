#include "BanDoc.h"

string BanDoc::getMaBD()
{
	return this->sMaBD;
}
string BanDoc::getTen()
{
	return this->sHoTen;
}
string BanDoc::getKhoa()
{
	return this->sKhoa;
}
int BanDoc::getNgay()
{
	return xNgayDK.getNgay();
}
int BanDoc::geTThang()
{
	return xNgayDK.getThang();
}
int BanDoc::getNam()
{
	return xNgayDK.getNam();
}
void BanDoc::xuatBD()
{
	cout << "************************************\n";
	cout << "Ma ban doc: " << this->sMaBD << endl;
	cout << "Ngay dang ky the: ";
	xNgayDK.xuat();
	cout << "Ho va Ten: " << this->sHoTen << endl;
	cout << "Khoa: " << this->sKhoa << endl;
}
void BanDoc::setMaBD (string sMa)
{
	this->sMaBD = sMa;
}
void BanDoc::setTen (string sTen)
{
	this->sHoTen = sTen;
}
void BanDoc::setKhoa (string sKhoa)
{
	this->sKhoa = sKhoa;
}
void BanDoc::setNgay(int nN)
{
	this->xNgayDK.setNgay(nN);
}
void BanDoc::setThang(int nT)
{
	this->xNgayDK.setThang(nT);
}
void BanDoc::setNam (int nN)
{
	this->xNgayDK.setNam(nN);
}