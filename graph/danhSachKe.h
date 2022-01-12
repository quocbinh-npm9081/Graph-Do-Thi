
struct Node_dsk{
	int dinh;
	int trongSo;
	Node_dsk* link;
};
struct DanhSachKe {
	Node_dsk* dsk[MAX_D];
	int n;
};
int docFile_dsk(const char* tenFile, DanhSachKe& x, int flag);
void xuat_dsk(DanhSachKe x);
void menu_danhSachKe();