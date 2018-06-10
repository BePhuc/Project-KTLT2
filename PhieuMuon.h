#pragma once
#include "ThoiGian.h"
#include "BanDoc.h"
#include "Sach.h"
#include <time.h>
class BanDoc;
class Sach;
class ThoiGian;
class PhieuMuon
{
private:
	BanDoc xBanDoc;
	Sach xSach;
	ThoiGian xNgayMuon, xNgayTra;
	static int nTongPM;
	int nMaPM;
	int nTrangThai;
public:
	int getTongPM();
	BanDoc getBanDoc();
	Sach getSach();
	ThoiGian getNgayMuon(); 
	ThoiGian getNgayTra();
	int getMaPM();
	int getTrangThai();
	void setTrangThai(int nTT);
	void setSach(Sach xS);
	void setBanDoc(BanDoc xBD);
	//
	void output();
	PhieuMuon(int nMaPM = 0, string sMaBD = "", string sMaSach = "",int nA = 0, int nB = 0, int nC = 0, int nD = 0, int nE = 0,int nF = 0,int nTrangThai = 0) : xBanDoc(sMaBD), xSach(sMaSach), xNgayMuon(nA,nB,nC), xNgayTra(nD,nE,nF)
	{
		this->nTongPM++;
		this->nMaPM = nTongPM;
		this->nTrangThai = nTrangThai;
	}
	PhieuMuon(string sMaBD = "",string sMaSach = ""): xBanDoc(sMaBD), xSach(sMaSach)
	{
		time_t t = time(0); 
		struct tm *Info =localtime(&t);
		xNgayMuon.setNgay(Info->tm_mday);
		xNgayMuon.setThang(Info->tm_mon + 1);
		xNgayMuon.setNam(Info->tm_year + 1900);

		xNgayTra.setNgay(Info->tm_mday + 7);
		xNgayTra.setThang(Info->tm_mon + 1);
		xNgayTra.setNam(Info->tm_year + 1900);
		
		this->nTongPM++;
		this->nMaPM = nTongPM;
		this->nTrangThai = 1;
	}
	friend BanDoc;
	friend Sach;
	friend ThoiGian;
	~PhieuMuon(void){};
};


