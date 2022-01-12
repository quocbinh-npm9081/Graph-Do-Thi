
struct Node {
	int dinhKe;
	int trongSo;
	Node* link;
};
struct DanhSachDinh {//danhsachdinh
	int dsd[MAX_D];
	int n;
};
struct MaTrix {
	int mt[MAX_D][MAX_D];
	int n;
};


void xuatDinh_maTranKe(int v);
void xuatCanhE_maTranKe(Canh e);
void xuatTatCaCacDinh_maTranKe(DanhSachDinh v);

void xuatTatCaCacCanh_maTranKe(DanhSachCanh e);
//DOC FILE
int docFile_maTranKe(const char* tenFile, MaTrix& x);
//GHI  FILE
int ghiFile_maTranKe(const char* tenFile, MaTrix& x);
//XUAT FILE
void xuatMaTranKe(MaTrix x);
//TINH BAC VAO CUA DO THI CO HUONG
int bacVaoCua_1_dinh_maTranKe(MaTrix x, int dinh);
//DUYET DO THI THEO CHIEU SAU DFS (SU DUNG MA TRAN KE)
int bacCua1_dinh_maTranKe(MaTrix x, int dinh);
//XUAT CANH CUA DO THI
DanhSachCanh xuatTapCanh_maTranKe(MaTrix x);
//XUAT CAC DINH KE( SU DUNG MA TRAN KE)
DanhSachDinh xuatDinhKe_maTranKe(MaTrix x, int dinh);
void menu_maTranKe();