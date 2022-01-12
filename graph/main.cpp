#include"Header.h"
#include"maTranKe.h"
#include"danhSachKe.h"

int main() {
	MaTrix x;
	int choice;
	do {
		cout << "\n0.Thoat";
		cout << "\n1 Thao tac ma tran ke";
		cout << "\n2 Thao tac danh sach ke";
		cout << "\nNhao lua chon: ";
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 1:
			menu_maTranKe();
			break;
		case 2:
			menu_danhSachKe();
			break;

		default:
			break;
		}
	} while (choice != 0);


	
	
	return 0;
}