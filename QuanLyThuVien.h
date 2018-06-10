#pragma once
#include <iostream>
#include <string>
using namespace std;
class QuanLyThuVien
{
private:
	string sID;
	string sPass;
public:
	string getID ();
	string getPass ();
	void setID (string sID);
	void setPass (string sPass);
	QuanLyThuVien(string sID = "", string sPass = "")
	{
		this->sID = sID;
		this->sPass = sPass;
	}
	~QuanLyThuVien(void){};
};


