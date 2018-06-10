#include "PhieuMuon.h"



void PhieuMuon::output()
{
	cout << "Ma phieu muon: " << this->nMaPM << endl;
	cout << "Ma sach: " << this->xSach.getMaSach() << endl;
	cout << "Ma ban doc: " << this->xBanDoc.getMaBD() << endl;
	cout << "Ngay muon: "; this->xNgayMuon.xuat(); cout << endl;
	cout << "Ngay tra: "; this->xNgayTra.xuat(); cout << endl;
	cout << "Tinh trang: " << this->nTrangThai << endl;
}
int PhieuMuon::getTongPM()
{
	return this->nTongPM;
}
BanDoc PhieuMuon::getBanDoc()
{
	return this->xBanDoc;
}
Sach PhieuMuon::getSach()
{
	return this->xSach.getMaSach();
}
ThoiGian PhieuMuon::getNgayMuon()
{
	return this->xNgayMuon;
}
ThoiGian PhieuMuon::getNgayTra()
{
	return this->xNgayTra;
}
int PhieuMuon::getMaPM()
{
	return this->nMaPM;
}
int PhieuMuon::getTrangThai()
{
	return this->nTrangThai;
}
void PhieuMuon::setTrangThai(int nTT)
{
	this->nTrangThai = nTT;
}
void PhieuMuon::setSach(Sach xS)
{
	this->xSach = xS;
}
void PhieuMuon::setBanDoc(BanDoc xBD)
{
	this->xBanDoc = xBD;
}
