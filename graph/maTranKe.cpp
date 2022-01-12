#include"Header.h"
#include"maTranKe.h"

void xuatDinh_maTranKe(int v) {
	cout << v;
}
void xuatCanhE_maTranKe(Canh e) {
	cout << e.dau << "-" << e.cuoi << endl;
}
void xuatTatCaCacDinh_maTranKe(DanhSachDinh v) {
	for (int i = 0; i < v.n; i++)
	{
		cout << "\t";
		xuatDinh_maTranKe(v.dsd[i]);
	}
}
void xuatTatCaCacCanh_maTranKe(DanhSachCanh e) {
	for (int j = 0; j < e.n; j++)
	{
		cout << "\t";
		xuatCanhE_maTranKe(e.dsc[j]);
	}
}

//DOC FILE
int docFile_maTranKe(const char* tenFile, MaTrix& x) {
	FILE* file;
	fopen_s(&file, tenFile, "r");
	if (file == NULL)
	{
		return 0;
	}
	fscanf_s(file, "%d", &x.n);
	for (int i = 0; i < x.n; i++)
	{
		for (int j = 0; j < x.n; j++)
		{
			fscanf_s(file, "%d", &x.mt[i][j]);
		}
	}
	fclose(file);
	return 1;
}
//GHI  FILE
int ghiFile_maTranKe(const char* tenFile, MaTrix& x) {
	FILE* f;
	fopen_s(&f, tenFile, "rt");
	if (f == NULL) return 0;
	fscanf_s(f, "%d", &x.n);
	for (int i = 0; i < x.n; i++)
		for (int j = 0; j < x.n; j++)
			fscanf_s(f, "%d", &x.mt[i][j]);
	fclose(f);
	return 1;

}
//XUAT FILE
void xuatMaTranKe(MaTrix x) {
	cout << "\nMa tran ke:" << endl;
	cout << x.n << endl;
	for (int i = 0; i < x.n; i++)
	{
		for (int j = 0; j < x.n; j++)
		{
			cout << x.mt[i][j] << "	";
		}
		cout << "\n";
	}
}
//TINH BAC VAO CUA DO THI CO HUONG
int bacVaoCua_1_dinh_maTranKe(MaTrix x, int dinh) {
	int dem = 0;
	for (int i = 0; i < x.n; i++) {
		if (x.mt[i][dinh] != 0) {
			dem++;
		}
	}
	return dem;
}
//DUYET DO THI THEO CHIEU SAU DFS (SU DUNG MA TRAN KE)
int bacCua1_dinh_maTranKe(MaTrix x, int dinh) {
	int dem = 0;
	for (int j = 0; j < x.n; j++)
	{
		if (x.mt[dinh][j] != 0) {
			dem++;
		}
	}
	return dem;
}
//XUAT CANH CUA DO THI
DanhSachCanh xuatTapCanh_maTranKe(MaTrix x) {
	DanhSachCanh tapCanh;
	tapCanh.n = 0;
	for (int i = 0; i < x.n; i++)
	{
		for (int j = 0; j < x.n; j++) {
			if (x.mt[i][j] != 0) {
				Canh e;
				e.dau = i;
				e.cuoi = j;
				e.trongSo = x.mt[i][j];
				tapCanh.n++;
				tapCanh.dsc[tapCanh.n++] = e;
			}
		}
	}
	return tapCanh;
}
//XUAT CAC DINH KE( SU DUNG MA TRAN KE)
DanhSachDinh xuatDinhKe_maTranKe(MaTrix x, int dinh) {
	DanhSachDinh dsDinh;
	dsDinh.n = 0;
	for (int j = 0; j < x.n; j++) {
		if (x.mt[dinh][j] != 0)
		{
			dsDinh.dsd[dsDinh.n] = j;
			dsDinh.n++;
		}
	}
	return dsDinh;
}

void menu_maTranKe() {
	int luaChon, dinh;
	MaTrix x;
	do {
		cout << "\n0. Thoat";
		cout << "\n1. Doc File khong trong so (su dung ma tran ke)";
		cout << "\n2. Doc File co trong so (su dung ma tran ke)";
		cout << "\n3. Ghi file (su dung ma tran ke)";
		cout << "\n4. Tim bac vao cua dinh( do thi co huong) ";
		cout << "\n5. Tim bac cua dinh( do thi vo huong)";
		cout << "\n6. Xuat canh cua do thi co huong";
		cout << "\n7. Xuat so ds dinh ke cu dinh";
		cout << "\n8. Luu File";
		cout << "\nNhap lua chon: ";
		cin >> luaChon;
		cin.ignore();
		switch (luaChon)
		{
		case 1:
			cout << "\nDoc File do thi (su dung ma tran ke)";
			docFile_maTranKe("doThi1_mtk.txt", x);
			xuatMaTranKe(x);
			break;
		case 2:
			cout << "\nDoc File do thi co trong so (su dung ma tran ke)";
			docFile_maTranKe("doThi2_mtk.txt", x);
			xuatMaTranKe(x);
			break;
		case 3:
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
			}
		default:
			cout << "\nNhap sai lua chon, xin hay nhap lai";
			break;
		}
	} while (luaChon != 0);
}