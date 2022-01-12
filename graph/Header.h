#include<iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

const int MAX_D = 20;
const int MAX_C = MAX_D * MAX_D;
struct Canh {
	int dau;
	int cuoi;
	int trongSo;
};
struct DanhSachCanh {
	Canh dsc[MAX_C];
	int n;
};
