#include "Sach.h"

void Sach::setNgayNhapKho(int nN)
{
	this->xNgay.setNgay(nN);
}
void Sach::setThangNhapKho(int nT)
{
	this->xNgay.setThang(nT);
}
void Sach::setNamNhapKho(int nN)
{
	this->xNgay.setNam(nN);
}
string Sach::getMaSach()
{
	return this->sMaSach;
}
string Sach::getTuaDe()
{
	return this->sTuaDe;
}
string Sach::getTacGia()
{
	return this->sTacGia;
}
string Sach::getNXB()
{
	return this->sNXB;
}
int Sach::getGiaTien()
{
	return this->nGiaTien;
}
int Sach::getNamPH()
{
	return this->nNamPhatHanh;
}
int Sach::getSoTrang()
{
	return this->nSoTrang;
}
int Sach::getNgayNhapKho()
{
	return this->xNgay.getNgay();
}
int Sach::getThangNhapKho()
{
	return this->xNgay.getThang();
}
int Sach::getNamNhapKho()
{
	return this->xNgay.getNam();
}
int Sach::getTinhTrang()
{
	return this->nTinhTrang;
}
void Sach::setMaSach(string sMa)
{
	this->sMaSach = sMa;
}
void Sach::setTuaDe(string sTuaDe)
{
	this->sTuaDe = sTuaDe;
}
void Sach::setTacGia(string sTG)
{
	this->sTacGia = sTG;
}
void Sach::setNXB(string sNXB)
{
	this->sNXB = sNXB;
}
void Sach::setGiaTien(int nTien)
{
	this->nGiaTien = nTien;
}
void Sach::setNamPH(int nNamPH)
{
	this->nNamPhatHanh = nNamPH;
}
void Sach::setSoTrang(int nSoTrang)
{
	this->nSoTrang = nSoTrang;
}
void Sach::setTinhTrang(int nTT)
{
	this->nTinhTrang = nTT;
}
void Sach::xuatSach() 
{
	cout << "Ma sach: " << this->sMaSach << endl;
	cout << "Tieu de: " << this->sTuaDe << endl;
	cout << "Tac gia: " << this->sTacGia << endl;
	cout << "NXB: " << this->sNXB << endl;
	cout << "Tri gia: " << this->nGiaTien << "  dong" << endl;
	cout << "Nam phat hanh: " << this->nNamPhatHanh << endl;
	cout << "So trang: " << this->nSoTrang << endl; 
	cout << "Ngay nhap kho: ";
	this->xNgay.xuat();
	cout << endl;
}

