#include"Header.h"
#include"danhSachKe.h"
int docFile_dsk(const char* tenFile, DanhSachKe& x, int flag) {
	FILE *f;
	fopen_s( &f,tenFile, "rt");
	if (f == NULL) return 0;
	fscanf_s(f, "%d", &x.n);
	for (int i = 0; i < x.n; i++) {
		x.dsk[i] = NULL;
	}
	for (int i = 0; i < x.n; i++)
	{
		int m;
		fscanf_s(f, "%d", &m);
		for (int j = 0; j < m; j++)
		{
			Node_dsk* p = new Node_dsk;
			if (flag == 1) {// 1-co trong so
				fscanf_s(f, "%d%d", &p->dinh, &p->trongSo);
			}
			else { //!=1 do thi ko co trong so
				fscanf_s(f, "%d", &p->dinh);
			}
			p->link = x.dsk[i];
			x.dsk[i] = p;
		}
	}
	fclose(f); 
	return 1;
}
void xuat_dsk(DanhSachKe x) {
	cout << endl;
	cout << "\nDanh Sach Ke: " << endl;
	for (int i = 0; i < x.n; i++)
	{
		Node_dsk* p = x.dsk[i];
		cout << i << ": ";
		while (p != NULL)
		{
			cout << " (" << p->dinh << "," << p->trongSo << ")";
			p = p->link;
		}
		cout << endl;
	}
	
}
 

void menu_danhSachKe() {
	int luaChon, dinh;
	DanhSachKe x;
	do {
		cout << "\n0. Thoat";
		cout << "\n1. Doc File khong trong so (su dung danh sach ke)";
		cout << "\n2. Doc File co trong so (su dung danh sach ke)";
		cout << "\n3. Ghi file (su dung danh sach ke)";
		cout << "\n4. Tim bac vao cua dinh( do thi co huong) ";
		cout << "\n5. Tim bac cua dinh( do thi vo huong)";
		cout << "\n6. Xuat canh cua do thi co huong";
		cout << "\n7. Xuat so ds dinh ke cu dinh";
		cout << "\nNhap lua chon: ";
		cin >> luaChon;
		cin.ignore();
		switch (luaChon)
		{
		case 1:
			cout << "\nDoc File do thi (su dung ma tran ke)";
			docFile_dsk("doThi1_dsk.txt", x, 0);
			xuat_dsk(x);
			break;
		case 2:
			cout << "\nDoc File do thi co trong so (su dung ma tran ke)";
			docFile_dsk("doThi2_dsk.txt", x,1);
			xuat_dsk(x);
			break;
		/*case 3:
			cout << "\nGhi File do thi khong trong s (su dung ma tran ke)";
			ghiFile_maTranKe("dohi3.txt", x);
			if (ghiFile_maTranKe("doThi3_mtk.txt", x) == 1)
			{
				cout << "\nDa ghi file thanh cong";
			}
			break;
		case 4:
			cout << "\nNhap dinh: ";
			cin >> dinh;
			cout << "Bac vao cua dinh " << dinh << ": " << bacVaoCua_1_dinh_maTranKe(x, dinh);
			break;
		case 5:
			cout << "\nNhap dinh can tim bac:";
			cin >> dinh;
			cout << "\nBac cua dinh " << dinh << " la: " << bacCua1_dinh_maTranKe(x, dinh);
			break;
		case 6:
			DanhSachCanh c = xuatTapCanh_maTranKe(x);
			if (c.n == 0)
			{
				cout << "\nDo thi khong co canh nao ca";
			}
			else {
				cout << "\nTap canh cua do thi:" << endl;
				for (int i = 0; i < c.n; i++)
				{
					cout << c.dsc[i].dau << c.dsc[i].cuoi << "	";
				}
			}
			break;
		case 7:
			cout << "\nNhap dinh de tim dinh ke: ";
			cin >> dinh;
			DanhSachDinh dsd = xuatDinhKe_maTranKe(x, dinh);
			if (dsd.n == 0)
			{
				cout << "\nDinh " << dinh << " khong co dinh ke";
			}
			else {
				cout << "\nDinh ke cua" << dinh << " la: ";
				for (int i = 0; i < dsd.n; i++)
				{
					cout << dsd.dsd[i] << " ";
				}
			}*/
		default:
			cout << "\nNhap sai lua chon, xin hay nhap lai";
			break;
		}
	} while (luaChon != 0);
}