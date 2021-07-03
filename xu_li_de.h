#ifndef XU_LI_DE_h
#define	XU_LI_DE_h

#include "doc_ghi_file.h"

//============ Login ==========================
//void login();
/*if (user la : ma_sv; pass true)
{
	duoc thi;
	xem ket qua thi;
}
else if (user la GV, pass la GV)
{
	1. nhap lop (them, xoa. hieu chinh)
	2. Nhap sinh vien cua lop: nhap ma lop truoc, nhap sinh vien vao lop sau
	3. Nhap mon hoc: them, xoa, hieu chinh
	4. nhap cau hoi ( tu tao ra ID ngau nhien)
	5. Thi: mon thi -> so cau hoi -> time (phut) -> lay ngau nhien cau hoi
	6. In chi tiet cau hoi thi cua 1 sinh: nhap ma SV -> in ra cau hoi thi, diem
	7. In bang diem thi cua 1 lop: nhap ma lop -> in ra ds sinh vien da~ thi va chua thi
}*/

// ------------------------ LỚP -------------------------------------------
void them_lop(ClassList &ds_l);
int ktra_trung_lop(string a, ClassList ds_l);
int check_lop(ClassList ds_l,string a);
void xoa_lop(ClassList &ds_l);
void in_ds_lop(ClassList ds_l);
//int ktra_nien_khoa(string a, DS_LOP ds_l);
void hieu_chinh_lop(ClassList &ds_l);
void giai_phong_bo_nho_lop(ClassList &ds_l);

//---------------------------------- SINH VIÊN ------------------------------------
bool ktra_trung_ma_sv(Student *pHead, string ma);
Class *kt_ma_lop(ClassList ds_l, string ma);
Student* khoi_tao_node_sv();
void them_1_sinh_vien(Student *&p_head, Student *p);
void nhap_sinh_vien(ClassList &ds_l,StudentList &ds_sv);
void xoa_sv(ClassList &ds_l);
void giai_phong_ds_sv(StudentList &ds_sv);
void in_ds_sv(StudentList ds_sv, ClassList ds_l);
int check_ma_sv(ClassList ds_l, string ma);

// ----------------------------- MÔN ----------------------------------------------
void them_mon(SubjectList &ds_mon);
void sap_xep_chen(SubjectList ds_mon);
int ktra_trung_mon(string a, SubjectList ds_mon);
void xoa_mon(SubjectList &ds_mon);
void hieu_chinh_mon(SubjectList &ds_mon);
void xuat_mon(SubjectList ds_mon);
void giai_phong_bo_nho_mon(SubjectList &ds_mon);

//---------------------------- CÂU HỎI THI ------------------------------
void nhap_cau_hoi(QuestionnaireList &ds_cau, SubjectList &ds_mon);
Questionnaire *khoi_tao_node_cau_hoi();
void xu_li_dap_an(Questionnaire *p);
bool ktra_trung_id(tree t, int id_cau);
int tao_id_cau_hoi(tree t);
void them_1_cau_hoi(tree &t, Questionnaire *p);
void chuyen_cay_sang_mang(tree t, Questionnaire *ds[], int &nds);
void in_ds_cau_hoi( Questionnaire *ds[], int &nds);
void giai_phong_ds_cau(Questionnaire *ds[], int &nds);
void hoan_vi_2_cau(Questionnaire *a, Questionnaire *b);
void xoa_cau(QuestionnaireList &ds_cau);
void xoa_1_cau(tree &t, int id_cau);
void node_the_mang(tree &t, Questionnaire *x);
void hieu_chinh_1_cau(tree t, int id_cau, SubjectList &ds_mon);
void hieu_chinh_cau(QuestionnaireList &ds_cau, SubjectList &ds_mon);
int dem_sl_cau(string a, Questionnaire *ds[], int &nds);
void shuffle_array(Questionnaire *ds[], int nds);

// ------------------------ THI ----------------------------
// void shuffle_array(cau_hoi_thi *ds[], int nds); // xao tron bo cau hoi truoc khi phat de
// void menu_thi_thu(ds_mon_hoc &ds_mon, cau_hoi_thi *ds[], int &nds);
// void bo_de(cau_hoi_thi *ds[], int &nds,string a,int n,int hour, int minute, int second);
// void bo_de_sv(DS_LOP &ds_l, string ma_sv, cau_hoi_thi *ds[], int &nds, string ma_mh, int n, int hour, int minute, int second);
// void thi(string ma_sv, DS_LOP ds_l, DS_MON_HOC &ds_mon, cau_hoi_thi *ds[], int &nds);

// --------------------- DIEM THI --------------------------------
// void them_diem_thi(DS_LOP &ds_l, float &diem, string ma_sv, string ma_mh);
// lop *lay_node_sv(DS_LOP ds_l, string ma_sv);

// ==================== MENU TINH ===============================
//=================================== Menu chinh =========================
//void menu_lop(DS_LOP &ds_l);
//void menu_sinh_vien(DS_LOP &ds_l, DS_SINH_VIEN &ds_sv);
//void menu_mon_hoc(DS_MON_HOC &ds_mon);
//void menu_de_thi(DS_CAU_HOI_THI &ds_cau, DS_MON_HOC &ds_mon);
//void menu_thi(DS_MON_HOC &ds_mon, cau_hoi_thi *ds[], int &nds);
//void menu_thi(cau_hoi_thi *ds[], int &nds, string a, int n);
//void menu_sv();
//void menu_gv();
//=================== Login ======================
//void menu_sv()
//{
//	// =============== khai bao bien =================
//	DS_SINH_VIEN ds_sv;
//	DS_CAU_HOI_THI ds_cau;
//	DS_MON_HOC ds_mon;
//	DS_LOP ds_l;
//	bool kt = true;
//	// ============ load file ==================
//	doc_file_ds_cau(ds_cau);	
//	//===============Login=========================
//	// ============= xu li menu =====================
//	while (kt = true)
//	{
//		int lua_chon;
//		system("cls");
//		cout << "1. Thi thu" << endl;
//		cout << "2. Ket qua thi thu" << endl;
//		cout << "3. In chi tiet bai lam cua 1 sinh vien." << endl;
//		cout << "0. Thoat." << endl;
//
//		cout << "Nhap lua chon: ";
//		cin >> lua_chon;
//
//		switch (lua_chon)
//		{
//		case 1:
//		{
//			system("cls");
//			menu_lop();
//			break;
//		}
//		case 2:
//		{
//			system("cls");
//			/*nhap_sinh_vien(ds_l, ds_sv);*/
//			system("pause");
//			break;
//		}
//		case 3:
//		{
//			system("cls");
//			menu_mon_hoc();
//		}
//		case 4:
//		{
//			system("cls");
//			menu_de_thi();
//			break;
//		}
//		case 0:
//		{
//			giai_phong_bo_nho_lop(ds_l);
//			giai_phong_bo_nho_mon(ds_mon);
//			kt = false;
//			break;
//		}
//		}
//	}
//}

// ===================== MENU ========================
//void menu_gv()
//{
//	// =============== khai bao bien =================
//	DS_SINH_VIEN ds_sv;
//	DS_CAU_HOI_THI ds_cau;
//	DS_MON_HOC ds_mon;
//	DS_LOP ds_l;
//	cau_hoi_thi *ds[200];
//	int nds = 0;
//	bool kt = true;
//	// ============ load file ==================
//	doc_file_ds_cau(ds_cau);
//	doc_file_ds_lop(ds_l);
//	doc_file_ds_mon(ds_mon);
//	doc_file_ds_sv(ds_sv);
//	//===============Login=========================
//	// ============= xu li menu =====================
//	while (kt = true)
//	{
//		int lua_chon;
//		system("cls");
//		cout << "1. Lop hoc cua truong " << endl;
//		cout << "2. Sinh vien cua truong." << endl;
//		cout << "3. Mon hoc." << endl;
//		cout << "4. He thong cau hoi." << endl;
//		cout << "5. Thi thu" << endl;
//		cout << "6. Ket qua thi thu" << endl;
//		cout << "7. In chi tiet bai lam cua 1 sinh vien." << endl;
//		cout << "8. In bang diem cua lop." << endl;
//		cout << "0. Thoat." << endl;	
//		cout << "Nhap lua chon: ";
//		cin >> lua_chon;		
//		switch (lua_chon)
//		{
//			case 1:
//			{
//				system("cls");
//				menu_lop(ds_l);
//				break;
//			}
//			case 2:
//			{
//				system("cls");
//				menu_sinh_vien(ds_l, ds_sv);
//				/*system("pause");*/
//				break;
//			}
//			case 3:
//			{
//				system("cls");
//				menu_mon_hoc(ds_mon);
//				break;
//			}
//			case 4:
//			{
//				system("cls");
//				menu_de_thi(ds_cau, ds_mon);
//				break;
//			}
//			case 5:
//			{
//				system("cls");
//				chuyen_cay_sang_mang(ds_cau.TREE, ds, nds);
//				menu_thi(ds_mon, ds, nds);
//				system("pause");
//				break;
//			}
//			case 0:
//			{
//				kt = false;
//				
//				break;
//			}
//		}
//	}
//}
////=========================== Menu Lop ==============================
//void menu_lop(DS_LOP &ds_l)
//{	
//	// ======================= khai bao bien ====================
//	/*DS_LOP ds_l;
//	DS_SINH_VIEN ds_sv;*/
//	bool kt = true;
//	// ======================= load file ===================
//	/*doc_file_ds_lop(ds_l);*/
//	// ======================= xu li file =========================
//	while (kt == true)
//	{
//		int lua_chon;
//		system("cls");
//		cout << "1. Them lop." << endl;
//		cout << "2. Xoa lop." << endl;
//		cout << "3. Hieu chinh lop." << endl;
//		cout << "4. In danh sach lop theo khoa." << endl;
//		cout << "0. Thoat!" << endl;
//		cout << "Nhap lua chon: ";
//		cin >> lua_chon;
//		switch (lua_chon)
//		{
//			case 1:
//			{
//				if (ds_l.sl >= 500)
//				{
//					cout << "Them khong thanh cong vi vuot qua so lop cho phep!" << endl;
//					system("pause");
//				}
//				else
//				{
//					them_lop(ds_l);
//					cout << "Them thanh cong!" << endl;
//					system("pause");
//				}					
//				break;
//				}
//				case 2:
//				{
//					if (ds_l.sl == 0)
//					{
//						cout << "Chua co lop nao de xoa ca!" << endl;
//						system("pause");
//					}
//					else
//					{
//						xoa_lop(ds_l);
//					}
//					break;
//			}
//			case 3:
//			{
//				if (ds_l.sl == 0)
//				{
//					cout << "Data rong~ !" << endl;
//					system("pause");
//				}
//				else
//				{
//					hieu_chinh_lop(ds_l);
//					system("pause");
//				}
//				break;
//			}
//			case 4:
//			{
//				if (ds_l.sl == 0)
//				{
//					cout << "Khong co lop nao de in ca!" << endl;
//					system("pause");
//				}
//				else
//				{
//					in_ds_lop(ds_l);
//					system("pause");
//				}
//				break;
//			}
//			
//			case 0:
//			{
//				kt = false;
//				break;
//			}
//		}
//	}
//}
//void menu_sinh_vien(DS_LOP &ds_l, DS_SINH_VIEN &ds_sv)
//{
//	bool kt = true;
//	while (kt == true)
//	{
//		int lua_chon;
//		system("cls");
//		cout << "1. Them 1 sinh vien." << endl;
//		cout << "2. In danh sach sinh vien." << endl;
//		cout << "0. Thoat." << endl;
//		cout << "Nhap lua chon: ";
//		cin >> lua_chon;
//		switch (lua_chon)
//		{
//		case 1:
//		{
//			nhap_sinh_vien(ds_l, ds_sv);
//			break;
//		}
//		case 2:
//		{
//			in_ds_sv(ds_sv);
//			system("pause");
//			break;
//		}
//		case 0:
//		{
//			kt = false;
//			break;
//		}
//		}
//	}
//}
//void menu_mon_hoc(DS_MON_HOC &ds_mon)
//{
//	bool kt = true;
//	while (kt == true)
//	{
//		int lua_chon;
//		system("cls");
//		cout << "1. Them mon hoc. " << endl;
//		cout << "2. Xoa mon hoc." << endl;
//		cout << "3. Hieu chinh mon hoc." << endl;
//		cout << "4. Xuat danh sach mon hoc." << endl;
//		cout << "0. Thoat." << endl;
//		cout << "Nhap lua chon: ";
//		cin >> lua_chon;
//		switch (lua_chon)
//		{
//		case 1:
//		{
//			if (ds_mon.sl >= 300)
//			{
//				cout << "So luong mon hoc vuot qua so luong cko phep (300), hay xoa bot truoc khi them vao!";
//				system("pause");
//			}
//			else
//			{
//				system("cls");
//				them_mon(ds_mon);
//				sap_xep_chen(ds_mon); // sắp xếp mã môn học ngay sau khi nhập 
//				system("pause");
//			} 
//			break;
//		}
//		case 2:
//		{
//			system("cls");
//			xoa_mon(ds_mon);
//			system("pause");
//			break;
//		}
//		case 3:
//		{
//			system("cls");
//			hieu_chinh_mon(ds_mon);
//			system("pause");
//			break;
//		}
//		case 4:
//		{
//			system("cls");
//			xuat_mon(ds_mon);
//			system("pause");
//			break;
//		}
//		case 0:
//		{
//			kt = false;
//			break;
//		}
//		}
//	}
//}
//void menu_de_thi(DS_CAU_HOI_THI &ds_cau,DS_MON_HOC &ds_mon)
//{
//	cau_hoi_thi *ds[200];
//	int nds = 0;
//	
//	tree *t = NULL;
//	bool kt = true;
//	// ======================= load file ===================
//	//doc_file_ds_cau(ds_cau);
//	while (kt == true)
//	{
//		system("cls");
//		cout << "1. Them cau hoi thi" << endl;
//		cout << "2. In ds cau hoi thi" << endl;
//		cout << "3. Xoa cau hoi thi" << endl;
//		cout << "4. Chinh sua cau hoi thi" << endl;
//		cout << "0. Thoat!" << endl;
//		cout << "Nhap lua chon: ";
//		int luachon;
//		cin >> luachon;
//		switch (luachon)
//		{
//		case 1:
//		{
//			system("cls");
//			nhap_cau_hoi(ds_cau);
//			cout << "Them thanh cong!" << endl;
//			system("pause");
//			break;
//		}
//		case 2:
//		{
//			system("cls");	
//			chuyen_cay_sang_mang(ds_cau.TREE, ds, nds);
//			
//			in_ds_cau_hoi(ds, nds);
//			system("pause");
//			break;
//		}
//		case 3:
//		{
//			system("cls");
//			xoa_cau(ds_cau);
//			system("pause");
//			break;
//		}
//		case 4:
//		{
//			system("cls");
//			hieu_chinh_cau(ds_cau);
//			system("pause");
//			break;
//		}
//		case 0:
//		{
//			kt = false;
//			break;
//		}
//		}	
//	}	
//}
// =============================================================

//============================ Them lop =========================
void them_lop(ClassList &ds_l)
{
	Class *p = new Class;
	
	gotoxy(70, 13);
	HighLight();
	cout << "NHAP THONG TIN LOP VAO BANG";
	HighLight();
	khung_them_lop();
	Normal();
	gotoxy(62, 18);
	cout << "MA LOP     :";
	gotoxy(62, 21);
	cout << "TEN LOP    :";
	gotoxy(80, 18);
	getline(cin, p->classID);
	chuan_hoa_chu(p->classID);
	while (ktra_trung_lop(p->classID, ds_l) >= 0)
	{
		gotoxy(70, 27);
		cout << "MA BI TRUNG, NHAP LAI MA MOI!";
		gotoxy(80, 18);
		cout << "                         ";	
		gotoxy(80, 18);
		getline(cin, p->classID);
		chuan_hoa_chu(p->classID);
		gotoxy(70, 27);
		cout << "                                       ";
	}	
	gotoxy(80, 21);
	getline(cin, p->className);
	chuan_hoa_chu(p->className);
	gotoxy(75, 27);
	cout << "THEM THANH CONG!";
	ds_l.classList[ds_l.index] = p;
	ds_l.index++;	
	ghi_file_lop(ds_l);
}

//====== ktra co trung lop hay chua =========================
int ktra_trung_lop(string a, ClassList ds_l)
{
	for (int i = 0; i < ds_l.index; i++)
	{
		if (ds_l.classList[i]->classID == a)
		{
			return i;
		}
	}
	return -1;
}

//============= xoa lop =====================================
void xoa_lop(ClassList &ds_l)
{
	string a;
	Normal();
	gotoxy(50, 8);
	cout << "NHAP MA LOP BAN MUON XOA: ";
	getline(cin, a);
	chuan_hoa_chu(a);
	//================= ktra lop da co ton tai hay chua ============
	int ktra_a = ktra_trung_lop(a, ds_l);
	if (ktra_a < 0)
	{
		HighLight();
		gotoxy(60, 10);
		cout << "MA LOP KHONG TON TAI!";
	}
	else
	{
		if (check_lop(ds_l, a) < 0)
		{
			HighLight();
			gotoxy(60, 10);
			cout << "LOP DANG CHUA SV, KHONG XOA DUOC!";
		}
		else
		{
			gotoxy(60, 10);
			cout << "                     ";

			for (int i = ktra_a; i < ds_l.index - 1; i++)
			{
				ds_l.classList[i]->classID = ds_l.classList[i + 1]->classID;
				ds_l.classList[i]->className = ds_l.classList[i + 1]->className;
			}
			Class *tam = ds_l.classList[ds_l.index - 1];
			delete tam;
			ds_l.index--;
			gotoxy(60, 10);
			cout << "XOA THANH CONG!";
		}	
	}
}

int check_lop(ClassList ds_l,string a)
{
	for (int i = 0; i < ds_l.index; i++)
	{
		if (ds_l.classList[i]->classID == a)
		{
			if(ds_l.classList[i]->studentList.pHead == NULL)return i;
		}
	}
	return -1;
}

//================ hieu chinh lop =====================
void hieu_chinh_lop(ClassList &ds_l)
{
	string a;
	Normal();
	gotoxy(50, 8);
	cout << "NHAP MA LOP BAN CAN HIEU CHINH: ";
	getline(cin, a);
	chuan_hoa_chu(a);
	int ktra = ktra_trung_lop(a, ds_l);
	if (ktra < 0)
	{
		HighLight();
		gotoxy(65, 10);
		cout << "MA LOP KHONG TON TAI";
	}
	else
	{
		//============= hieu chinh ==========
		Normal();
		gotoxy(60, 10);
		cout << "Nhap ten lop      : ";
		gotoxy(60, 11);
		cout << "Nhap nien khoa    : ";
		HighLight();
		gotoxy(80, 10);
		getline(cin, ds_l.classList[ktra]->className);
		chuan_hoa_chu(ds_l.classList[ktra]->className);
		gotoxy(65, 13);
		cout << "DA~ THAY DOI THONG TIN LOP!";
	}
}

//============== In danh sach lop theo nien khoa ==========================
void in_ds_lop(ClassList ds_l)
{
		HighLight();
		gotoxy(51, 10);
		cout << "DANH SACH LOP ";
		gotoxy(50, 11);
		cout << "=======================================";
		for (int i = 0; i < ds_l.index; i++)
		{
			gotoxy(50, 12 + 3 * i); cout << "|";
			gotoxy(88, 12 + 3 * i); cout << "|";
			gotoxy(51, 12 + 3 * i);
			cout << " MA LOP    :   " << ds_l.classList[i]->classID;
			gotoxy(50, 13 + 3 * i); cout << "|";
			gotoxy(88, 13 + 3 * i); cout << "|";
			gotoxy(51, 13 + 3 * i);
			cout << " TEN LOP   :   " << ds_l.classList[i]->className;
			gotoxy(50, 14 + 3 * i);
			cout << "---------------------------------------";
		}
}
void giai_phong_bo_nho_lop(ClassList &ds_l)
{
	for (int i = 0; i < ds_l.index; i++)
	{
		delete ds_l.classList[i];
	}
}

//=============== lập ds sinh viên =====================
Class *kt_ma_lop(ClassList ds_l, string ma)
{
	for (int i = 0; i < ds_l.index; i++)
	{
		if (ds_l.classList[i]->classID == ma)
		{
			return ds_l.classList[i];
		}
	}
	return NULL;
}

void nhap_sinh_vien(ClassList &ds_l,StudentList &ds_sv)
{
	string a;
	gotoxy(55, 11);
	cout << "                     ";
	gotoxy(55, 12);
	cout << "                     ";
	gotoxy(55, 13);
	cout << "                     ";
	gotoxy(55, 14);
	cout << "                     ";
	gotoxy(66, 14);
	cout << "     ";
	gotoxy(87, 8);
	cout << "                     ";
	gotoxy(50, 10);
	cout << "                                                                ";
	gotoxy(50, 8);
	cout << "NHAP MA LOP BAN MUON THEM SINH VIEN: ";	
	getline(cin, a);
	chuan_hoa_chu(a);
	Class *tam = kt_ma_lop(ds_l, a);
	if (tam == NULL)
	{
		gotoxy(50, 10);
		cout << "MA LOP KHONG TON TAI, YEU CAU NHAP LAI HOAC TAO MA MOI! ";
		gotoxy(60, 35);
		system("pause");
		int ktra = true;
		while (ktra)
		{
			int chon;
			xoa_nen();
			gotoxy(55, 11);
			cout << "1. NHAP LAI MA LOP." ;
			gotoxy(55, 12);
			cout << "2. TAO MA LOP.";
			gotoxy(55, 13);
			cout << "0. THOAT!";
			gotoxy(55, 14);
			cout << "BAN CHON: ";
			gotoxy(66, 14);
			cin >> chon;
			gotoxy(55, 15);
			cout << "                    ";
			switch (chon)
			{
			case 1:
			{
				cin.ignore();
				nhap_sinh_vien(ds_l, ds_sv);
				break;
			}
			case 2:
			{
				xoa_nen();
				cin.ignore();
				them_lop(ds_l);
				break;
			}
			case 0:
			{
				cin.ignore();
				ktra = false;
				break;
			}
			}
		}

	}
	else
	{
		bool kt = true;
		while (kt == true)
		{
			gotoxy(55, 11);
			cout << "                  ";
			gotoxy(55, 12);
			cout << "                  ";
			gotoxy(55, 13);
			cout << "                  ";
			gotoxy(55, 14);
			cout << "                  ";
			Student *p = khoi_tao_node_sv();
			// =============== them sinh vien vao ds sinh vien ====================
			khung_them_sv();
			HighLight();
			gotoxy(50, 10);
			cout << "***Luu y: Ma sinh vien la duy nhat va cung la id de dang nhap.";
			Normal();
			gotoxy(62, 15);
			cout << "MA SV      :";
			gotoxy(62, 18);
			cout << "HO SV      :";
			gotoxy(62, 21);
			cout << "TEN SV     :";
			gotoxy(62, 24);
			cout << "PHAI       :";
			gotoxy(62, 27);
			cout << "PASSWORD   :";
			string ma_sv;
		tao_ma_hd:
			gotoxy(80, 15);
			cout << "                         ";
			gotoxy(80, 18);
			cout << "                         ";
			gotoxy(80, 21);
			cout << "                         ";
			gotoxy(80, 24);
			cout << "                         ";
			gotoxy(80, 27);
			cout << "                         ";
			gotoxy(80, 15);
			getline(cin, ma_sv);
			if (ma_sv == "0")
			{
				kt = false;
				break;
			}
			chuan_hoa_chu(ma_sv);
			while (ktra_trung_ma_sv(ds_sv.pHead, ma_sv) == true)
			{
				HighLight();
				gotoxy(70, 30);
				cout << "MA BI TRUNG, NHAP LAI MA MOI!";
				gotoxy(60, 35);
				system("pause");
				goto tao_ma_hd;
			}
			p->studentID = ma_sv;
			gotoxy(80, 18);
			getline(cin, p->studentLastName);
			if (p->studentLastName == "0")
			{
				kt = false;
				break;
			}
			gotoxy(80, 21);
			getline(cin, p->studentFirstName);
			if (p->studentFirstName == "0")
			{
				kt = false;
				break;
			}
			gotoxy(80, 24);
			getline(cin, p->gender);
			if (p->gender == "0")
			{
				kt = false;
				break;
			}
			gotoxy(80, 27);
			getline(cin, p->password);
			if (p->password == "0")
			{
				kt = false;
				break;
			}
			chuan_hoa_chu(p->studentLastName);
			chuan_hoa_chu(p->studentFirstName);
			chuan_hoa_chu(p->gender);
			//chuan_hoa_chu(p->password);
			them_1_sinh_vien(tam->studentList.pHead, p);
			tam->studentList.index++;
			ds_sv.index++;
			gotoxy(70, 30);
			cout << "                             ";
			gotoxy(70, 30);
			cout << "THEM SINH VIEN THANH CONG!";
			gotoxy(60, 35);
			system("pause");
			ghi_file_sv(ds_l);
			
		}
		}		
}

int check_ma_sv(ClassList ds_l, string ma)
{
	for (int i = 0; i < ds_l.index; i++)
	{
		if (ds_l.classList[i]->studentList.pHead == NULL)
		{
			return -1;
		}
		for (Student *k = ds_l.classList[i]->studentList.pHead; k != NULL; k = k->pNext)
		{
			if (k->studentID == ma)
			{
				return i;
			}
		}
	}
	return -1;
}

void xoa_sv(ClassList &ds_l) // HAM XOA SV
{
	string ma_sv;
	cout << "NHAP MA SV CAN XOA: ";
	getline(cin, ma_sv);
	if (check_ma_sv(ds_l, ma_sv) < 0)
	{
		cout << "MA SV KHONG TON TAI!";
	}
	else
	{
		Student* g = new Student;// node g là node trỏ đến node nằm trước node cần xoá
		for (int i = 0; i < ds_l.index; i++)
		{
			for (Student *k = ds_l.classList[i]->studentList.pHead; k != NULL; k = k->pNext)
			{
				if (k->studentID == ma_sv)
				{
					g->pNext = k->pNext;
					delete k;
					return;
				}
				g = k;
			}
		}
	}
}

void in_ds_sv(StudentList ds_sv, ClassList ds_l)
{
	gotoxy(60, 8);
	cout << "============ DANH SACH SINH VIEN =============";
	gotoxy(45, 9); cout << "----------------------------------------------------------------------------";
	gotoxy(45, 10); cout << "|   MA LOP";
	gotoxy(60, 10); cout << "|     MSSV";
	gotoxy(75, 10); cout << "|           NAME";
	gotoxy(100, 10); cout << "| PHAI";
	gotoxy(108, 10); cout << "|   PASS";
	gotoxy(120, 10); cout << "| ";
	gotoxy(45, 11); cout << "----------------------------------------------------------------------------";
	int j = 0;
	for (int i = 0; i < ds_l.index; i++)
	{
		for (Student *k = ds_l.classList[i]->studentList.pHead; k != NULL; k = k->pNext)
		{
			gotoxy(45, 12 + 1 * j); cout << "| " << ds_l.classList[i]->classID;
			gotoxy(60, 12 + 1 * j); cout << "| " << k->studentID;
			gotoxy(75, 12 + 1 * j); cout << "| " << k->studentLastName << " " << k->studentFirstName;
			gotoxy(100, 12 + 1 * j); cout << "| " << k->gender;
			gotoxy(108, 12 + 1 * j); cout << "| " << k->password;
			gotoxy(120, 12 + 1 * j); cout << "| ";
			j++;
		}
	}
	gotoxy(60, 7); cout << "SL: " << j;
}

void giai_phong_ds_sv(StudentList &ds_sv)
{
	for (Student *k = ds_sv.pHead; k != NULL; k = k->pNext)
	{
		delete k;
	}
}

bool ktra_trung_ma_sv(Student *pHead, string ma)
{
	for (Student *k = pHead; k != NULL; k = k->pNext)
	{
		if (k->studentID == ma)
		{
			return true;
		}
	}
	return false;
}

//============================ Them mon =========================
void them_mon(SubjectList &ds_mon)
{
	Subject p;
	gotoxy(45, 8);
	cout << "** NOTE: MA MH TOI DA 15 KTU, TEN MH TOI DA 50 KTU";
	khung_them_mon();
	gotoxy(73, 14);	
	HighLight();
	cout << "NHAP THONG TIN MON HOC";
	string ma_mh;
	gotoxy(62, 18);
	cout << "MA MON     :";
	gotoxy(62, 21);
	cout << "TEN MON    :";
	do
	{
		gotoxy(80, 18);
		getline(cin, p.subjectID);
		chuan_hoa_chu(p.subjectID);
		gotoxy(68, 24);
		cout << "                                   ";
		if (p.subjectID.length() > 15)
		{
			gotoxy(68, 24);
			cout << "Do dai vuot qua 15 ki tu, nhap lai!";
			
			gotoxy(80, 18);
			cout << "                              ";
		}
		while (ktra_trung_mon(p.subjectID, ds_mon) >= 0)
		{
			gotoxy(68, 24);
			cout << "                                   ";
			gotoxy(68, 24);
			cout << "Ma mon bi trung, yeu cau ma moi ";
			gotoxy(80, 18);
			cout << "                              ";
			gotoxy(80, 18);
			getline(cin,p.subjectID);
		}
	} while (p.subjectID.length() > 15);
	//p->ma_mh = ma_mh;
	do
	{	
		gotoxy(80, 21);
		getline(cin, p.subjectName);
		chuan_hoa_chu(p.subjectName);
		if (p.subjectName.length() > 50)
		{
			gotoxy(68, 24);
			cout << "                                        ";
			gotoxy(50, 24);
			cout << "Do dai vuot qua 50 ki tu, nhap lai!";
			gotoxy(80, 21);
			cout << "                              ";
		}
	} while (p.subjectName.length() > 50);
	gotoxy(68, 24);
	cout << "                                   ";
	gotoxy(75, 24);
	cout << "NHAP THANH CONG!";
	
	ds_mon.subjectList[ds_mon.index] = p;
	ds_mon.index++;
}

//============= săp xếp chèn môn học ===================
void sap_xep_chen(SubjectList ds_mon) // insertionSort();
{
	int index;
	string value_ma, value_ten;
	for (int i = 1; i < ds_mon.index; i++)
	{
		index = i;
		value_ma = ds_mon.subjectList[i].subjectID;
		value_ten = ds_mon.subjectList[i].subjectName;
		while (index > 0 && ds_mon.subjectList[index - 1].subjectID > value_ma)
		{
			ds_mon.subjectList[index].subjectID = ds_mon.subjectList[index - 1].subjectID;
			ds_mon.subjectList[index].subjectName = ds_mon.subjectList[index - 1].subjectName;
			index--;
		}
		ds_mon.subjectList[index].subjectID = value_ma;
		ds_mon.subjectList[index].subjectName = value_ten;
	}
}

//========================= ktra mon da duoc lap hay chua ===============
int ktra_trung_mon(string a, SubjectList ds_mon)
{
	for (int i = 0; i < ds_mon.index; i++)
	{
		if (ds_mon.subjectList[i].subjectID == a)
		{
			return i;
		}
	}
	return -1;
}

//========================== Xoa mon hoc ==================
void xoa_mon(SubjectList &ds_mon)
{
	string a;
	Normal();
	gotoxy(50, 8);
	cout << "NHAP MA MON HOC BAN MUON XOA: ";
	getline(cin, a);
	chuan_hoa_chu(a);
	//===========ktra mon hoc da ton tai hay chua ================
	int ktra_a = ktra_trung_mon(a, ds_mon);
	if (ktra_a < 0)
	{
		HighLight();
		gotoxy(60, 10);
		cout << "Ma mon khong ton tai";
	}
	else
	{
		gotoxy(60, 10);
		cout << "                     ";
		for (int i = ktra_a; i < ds_mon.index - 1; i++)
		{
			ds_mon.subjectList[i].subjectID = ds_mon.subjectList[i + 1].subjectID;
			ds_mon.subjectList[i].subjectName = ds_mon.subjectList[i + 1].subjectName;
		}
//		Subject tam = ds_mon.subjectList[ds_mon.index - 1];
		ds_mon.index--;
//		delete tam;
		ghi_file_mon(ds_mon);
		gotoxy(60, 10);
		cout << "XOA THANH CONG!";
	}
}
//========================= Hieu chinh mon hoc ===================
void hieu_chinh_mon(SubjectList &ds_mon)
{
	string a;
	Normal();
	gotoxy(50, 8);
	cout << "NHAP MA MON BAN CAN HIEU CHINH: ";
	getline(cin, a);
	chuan_hoa_chu(a);
	int ktra = ktra_trung_mon(a, ds_mon);
	if (ktra < 0)
	{
		HighLight();
		gotoxy(60, 10);
		cout << "MA MON KHONG TON TAI!"<< endl;
	}
	else
	{
		// ============== hieu chinh =================
		Normal();
		gotoxy(60, 10);
		cout << "NHAP TEN MON: "; 
		gotoxy(80, 10);
		getline(cin, ds_mon.subjectList[ktra].subjectName);
		chuan_hoa_chu(ds_mon.subjectList[ktra].subjectID);
		chuan_hoa_chu(ds_mon.subjectList[ktra].subjectName);
		gotoxy(65, 13); HighLight();
		cout << "DA~ THAY DOI THONG TIN MON HOC.";
		sap_xep_chen(ds_mon);
		ghi_file_mon(ds_mon);
	}
}
//========================== xuat ds lop =========================
void xuat_mon(SubjectList ds_mon)
{
	HighLight();
	gotoxy(60, 10);
	cout << "DANH SACH MON HOC";
	gotoxy(50, 11);
	cout << "=======================================";
	for (int i = 0; i < ds_mon.index; i++)
	{
		gotoxy(50, 12 + 3 * i); cout << "|";
		gotoxy(88, 12 + 3 * i); cout << "|";
		gotoxy(51, 12 + 3 * i);
		cout << " MA MON   :   " << ds_mon.subjectList[i].subjectID;
		gotoxy(50, 13 + 3 * i); cout << "|";
		gotoxy(88, 13 + 3 * i); cout << "|";
		gotoxy(51, 13 + 3 * i);
		cout << " TEN MON  :   " << ds_mon.subjectList[i].subjectName;
		gotoxy(50, 14 + 3 * i);
		cout << "---------------------------------------";
	}
}

//========================= giai phong bo nho mon ================
//void giai_phong_bo_nho_mon(SubjectList &ds_mon)
//{
//	for (int i = 0; i < ds_mon.index; i++)
//	{
//		delete ds_mon.subjectList[i];
//	}
//}

// ================= nhập câu hỏi =====================

void nhap_cau_hoi(QuestionnaireList &ds_cau, SubjectList &ds_mon)
{
	Questionnaire *p = khoi_tao_node_cau_hoi();
	p->questionnaireID = tao_id_cau_hoi(ds_cau.TREE);
	string subjectID;
	khung_cau_hoi();
	HighLight();
	gotoxy(70, 8);
	cout << "====== NHAP CAU HOI ======";
	gotoxy(50, 10);
	cout << "ID: " << p->questionnaireID;
	gotoxy(80, 10);
	cout << "MA MH: "; getline(cin, subjectID);
	chuan_hoa_chu(subjectID);
	while (ktra_trung_mon(subjectID, ds_mon) < 0)
	{
		gotoxy(68, 13);
		cout << "                                   ";
		gotoxy(68, 13);
		cout << "MA MON KHONG TON TAI! ";
		
		gotoxy(87, 10);
		cout << "                              ";
		gotoxy(87, 10);
		getline(cin, subjectID);
		chuan_hoa_chu(subjectID);
	}
	p->subjectID = subjectID;
	do
	{
		gotoxy(47, 13);
		cout << "CAU HOI: ";
		gotoxy(68, 13);
		cout << "                                   ";
		gotoxy(50, 18);
		cout << "                                 ";
		gotoxy(88, 18);
		cout << "                                ";
		gotoxy(50, 22);
		cout << "                                 ";
		gotoxy(88, 22);
		cout << "                                ";
		gotoxy(47, 18);
		cout << "A.";
		gotoxy(85, 18);
		cout << "B.";
		gotoxy(47, 22);
		cout << "C.";
		gotoxy(85, 22);
		cout << "D.";
		gotoxy(77, 27);
		cout << "DAP AN: ";
		gotoxy(56, 13);
		getline(cin, p->content);
		gotoxy(50, 18);
		getline(cin, p->A);	
		gotoxy(88, 18);
		getline(cin, p->B);
		gotoxy(50, 22);
		getline(cin, p->C);
		gotoxy(88, 22);
		getline(cin, p->D);
		chuan_hoa_chu(p->content);
		chuan_hoa_chu(p->A);
		chuan_hoa_chu(p->B);
		chuan_hoa_chu(p->C);
		chuan_hoa_chu(p->D);
		do
		{
			gotoxy(85, 27);
			cout << "    ";
			gotoxy(85, 27);
			cin >> p->correct;
			up_case_char(p->correct);
			if (p->correct != 'A' && p->correct != 'B' && p->correct != 'C' && p->correct != 'D')
			{
				gotoxy(65, 30);
				cout << "NHAP DAP AN KHONG HOP LE, YEU CAU NHAP LAI!";
			}
			if (p->A == p->B || p->A == p->C || p->A == p->D || p->B == p->C || p->B == p->D || p->C == p->D)
			{
				gotoxy(65, 30);
				cout << "                                           ";
				gotoxy(65, 30);
				cout << "CAC CAU DAP AN KHONG DUOC TRUNG NHAU";
			}
		} while (p->correct != 'A' && p->correct != 'B' && p->correct != 'C' && p->correct != 'D');
	} while (p->A == p->B || p->A == p->C || p->A == p->D || p->B == p->C || p->B == p->D || p->C == p->D );
	
	gotoxy(65, 30);
	cout << "                                           ";
	gotoxy(77, 30);
	cout << "NHAP THANH CONG!";
	xu_li_dap_an(p);
	them_1_cau_hoi(ds_cau.TREE, p);
	ds_cau.index++;
}

int tao_id_cau_hoi(tree t)
{
	int id_cau;// 000->999;
	do
	{
		id_cau = rand() % (1000 - 1 + 1)  +1;
	} while (ktra_trung_id(t, id_cau)==true);
	return id_cau;
}

bool ktra_trung_id(tree t, int id_cau)
{
	if (t == NULL)
	{
		return false;
	}
	else
	{
		if (t->questionnaireID == id_cau)
		{
			return true;
		}
		else if (t->questionnaireID < id_cau)
		{
			ktra_trung_id(t->pRight, id_cau);
		}
		else
		{
			ktra_trung_id(t->pLeft, id_cau);
		}
	}
}

//============== chuyển cây sang mảng =====================
void chuyen_cay_sang_mang(tree t, Questionnaire *ds[], int &nds)
{	
	if (t != NULL)
	{		
		ds[nds] = new Questionnaire;
		ds[nds]->questionnaireID = t->questionnaireID;
		ds[nds]->subjectID = t->subjectID;
		ds[nds]->content = t->content;
		ds[nds]->A = t->A;
		ds[nds]->B = t->B;
		ds[nds]->C = t->C;
		ds[nds]->D = t->D;
		ds[nds]->correct = t->correct;
		ds[nds]->answerCorrect = t->answerCorrect;
		nds++;
		chuyen_cay_sang_mang(t->pLeft, ds, nds);
		chuyen_cay_sang_mang(t->pRight, ds, nds);
	}
	
}

//================= giai phong vung nho tree ===============
void giai_phong_ds_cau(Questionnaire *ds[], int &nds)
{
	for (int i = 0; i < nds; i++)
	{
		delete ds[i];
	}
	nds = 0;
}

// =============== xoa cau hoi =======================
void xoa_cau(QuestionnaireList &ds_cau)
{
	int a;
	gotoxy(50, 9);
	cout << "Nhap id cau hoi: ";
	cin >> a;
	bool kt = ktra_trung_id(ds_cau.TREE, a);
	if (kt == true)
	{
		gotoxy(50, 11);
		cout << "                         ";
		xoa_1_cau(ds_cau.TREE, a);
		ds_cau.index--;
		gotoxy(50, 11);
		cout << "Xoa thanh cong!" ;
	}
	else
	{
		gotoxy(50, 11);
		cout << "Id cau hoi khong ton tai!";
	}
}

void xoa_1_cau(tree &t, int id_cau)
{
	if (t != NULL)
	{
		if (t->questionnaireID == id_cau)
		{
			Questionnaire *x = t; // x se luu node can giai phong
			if (t->pLeft == NULL)
			{
				t = t->pRight;
			}
			else if (t->pRight == NULL)
			{
				t = t->pLeft;
			}
			else if (t->pLeft != NULL && t->pRight != NULL)
			{
				// tim node the mang: trái cùng, cây con phải 
				node_the_mang(t->pRight,x);
			}
			delete x;
		}
		else if (t->questionnaireID < id_cau)
		{
			xoa_1_cau(t->pRight, id_cau);
		}
		else if (t->questionnaireID > id_cau)
		{
			xoa_1_cau(t->pLeft, id_cau);
		}
	}
}
void hoan_vi_2_cau(Questionnaire *a, Questionnaire *b)
{
	Questionnaire *tam = new Questionnaire;
	tam->questionnaireID = a->questionnaireID;
	tam->content = a->content;
	tam->A = a->A;
	tam->B = a->B;
	tam->C = a->C;
	tam->D = a->D;
	tam->correct = a->correct;
	tam->answerCorrect = a->answerCorrect;
	//---------------
	a->questionnaireID = b->questionnaireID;
	a->content = b->content;
	a->A = b->A;
	a->B = b->B;
	a->C = b->C;
	a->D = b->D;
	a->correct = b->correct;
	a->answerCorrect = b->answerCorrect;
	//---------------------
	b->questionnaireID = tam->questionnaireID;
	b->content = tam->content;
	b->A = tam->A;
	b->B = tam->B;
	b->C = tam->C;
	b->D = tam->D;
	b->correct = tam->correct;
	b->answerCorrect = tam->answerCorrect;
	delete tam;
}

void node_the_mang(tree &t, Questionnaire *x)
{
	if (t->pLeft != NULL)
	{
		node_the_mang(t->pLeft,x);
	}
	else // trai cung
	{
		hoan_vi_2_cau(t, x);
		x = t; // x luu vi tri node nay de giai phong
		t = t->pRight;
	}
}

//============= hieu chinh cau hoi ==========
void hieu_chinh_cau(QuestionnaireList &ds_cau, SubjectList &ds_mon)
{
	int a;
	gotoxy(50, 9);
	cout << "Nhap ID cau hoi can hieu chinh: "; cin >> a;
	bool kt = ktra_trung_id(ds_cau.TREE, a);
	if (kt == true)
	{
		gotoxy(50, 11);
		cout << "                 ";
		cin.ignore();
		hieu_chinh_1_cau(ds_cau.TREE, a,ds_mon);
	}
	else
	{
		gotoxy(50, 11);
		cout << "ID KHONG TON TAI!" ;
	}
	
}
void hieu_chinh_1_cau(tree t, int id_cau, SubjectList &ds_mon)
{
	if (t != NULL)
	{
		if (t->questionnaireID == id_cau)
		{
			string subjectID;
			khung_cau_hoi();
			HighLight();
			gotoxy(70, 8);
			cout << "==== CHINH SUA CAU HOI ====";
			gotoxy(50, 10);
			cout << "ID DUOC CHINH: " << t->questionnaireID;
			gotoxy(80, 10);
			cout << "MA MH: "; getline(cin, subjectID);
			chuan_hoa_chu(subjectID);
			gotoxy(90, 10); cout << subjectID;
			while (ktra_trung_mon(subjectID, ds_mon) < 0)
			{
				gotoxy(68, 13);
				cout << "                                   ";
				gotoxy(68, 13);
				cout << "MA MON KHONG TON TAI! ";
				gotoxy(87, 10);
				cout << "                              ";
				gotoxy(87, 10);
				getline(cin, subjectID);
				chuan_hoa_chu(subjectID);
			}
			t->subjectID = subjectID;
			do
			{
				gotoxy(47, 13);
				cout << "CAU HOI: ";
				gotoxy(68, 13);
				cout << "                                   ";
				gotoxy(50, 18);
				cout << "                                 ";
				gotoxy(88, 18);
				cout << "                                ";
				gotoxy(50, 22);
				cout << "                                 ";
				gotoxy(88, 22);
				cout << "                                ";
				gotoxy(47, 18);
				cout << "A.";
				gotoxy(85, 18);
				cout << "B.";
				gotoxy(47, 22);
				cout << "C.";
				gotoxy(85, 22);
				cout << "D.";
				gotoxy(77, 27);
				cout << "DAP AN: ";
				gotoxy(56, 13);
				getline(cin, t->content);
				gotoxy(50, 18);
				getline(cin, t->A);
				gotoxy(88, 18);
				getline(cin, t->B);
				gotoxy(50, 22);
				getline(cin, t->C);
				gotoxy(88, 22);
				getline(cin, t->D);
				chuan_hoa_chu(t->content);
				chuan_hoa_chu(t->A);
				chuan_hoa_chu(t->B);
				chuan_hoa_chu(t->C);
				chuan_hoa_chu(t->D);
				do
				{
					gotoxy(85, 27);
					cout << "    ";
					gotoxy(85, 27);
					cin >> t->correct;
					up_case_char(t->correct);
					if (t->correct != 'A' && t->correct != 'B' && t->correct != 'C' && t->correct != 'D')
					{
						gotoxy(65, 30);
						cout << "NHAP DAP AN KHONG HOP LE, YEU CAU NHAP LAI!";
					}
					if (t->A == t->B || t->A == t->C || t->A == t->D || t->B == t->C || t->B == t->D || t->C == t->D)
					{
						gotoxy(65, 30);
						cout << "                                           ";
						gotoxy(65, 30);
						cout << "CAC CAU DAP AN KHONG DUOC TRUNG NHAU";
					}
				} while (t->correct != 'A' && t->correct != 'B' && t->correct != 'C' && t->correct != 'D');
			} while (t->A == t->B || t->A == t->C || t->A == t->D || t->B == t->C || t->B == t->D || t->C == t->D);			
			gotoxy(65, 30);
			cout << "                                           ";
			gotoxy(77, 30);			
			cout << "SUA? THANH CONG!";
			xu_li_dap_an(t);
		}
		else if (t->questionnaireID > id_cau)
		{
			hieu_chinh_1_cau(t->pLeft, id_cau,ds_mon);
		}
		else if (t->questionnaireID < id_cau)
		{
			hieu_chinh_1_cau(t->pRight, id_cau,ds_mon);
		}
	}
}

void in_ds_cau_hoi( Questionnaire *ds[], int &nds)
{
	int a = nds /3;	
	int b;
	if (nds % 3 == 0) b = a;
	else b = a + 1;	
	while (true)
	{
		for (int j = 0; j < a;)
		{
			xoa_nen();
			char key;
			
			int m = 0;
			if (m == 2) m = 0;
			for (int i = 3 * j; i < 3 * j + 3; i++)
			{
				gotoxy(105, 35);
				cout << "Page " << j + 1 << "/" << b;
				gotoxy(50, 7 + 9 * m);
				cout << "======== Cau " << i + 1 << "==========";
				gotoxy(50, 8 + 9 * m);
				cout << "ID: " << ds[i]->questionnaireID;
				gotoxy(50, 9 + 9 * m);
				cout << "Ma: " << ds[i]->subjectID;
				gotoxy(50, 10 + 9 * m);
				cout << "Cau hoi: " << ds[i]->content;
				gotoxy(50, 11 + 9 * m);
				cout << "Cau A: " << ds[i]->A;
				gotoxy(50, 12 + 9 * m);
				cout << "Cau B: " << ds[i]->B;
				gotoxy(50, 13 + 9 * m);
				cout << "Cau C: " << ds[i]->C;
				gotoxy(50, 14 + 9 * m);
				cout << "Cau D: " << ds[i]->D;
				gotoxy(50, 15 + 9 * m);
				cout << "Dap an la: " << ds[i]->correct << ". " << ds[i]->answerCorrect;
				m++;
			}	
			key = _getch();
			if (key == 77)
			{
				if (j < a) j++;
				else if (j == a) goto page_last;
			}
			if (key == 75 && j > 0) j--;
			if (key == 27) break;
		}
		page_last:
		xoa_nen();
		int n = 0;
		for (int i = 3 * a; i < 3 * a + (nds % 3); i++)
		{
			gotoxy(105, 35);
			cout << "Page " << a + 1 << "/" << b;
			gotoxy(50, 7 + 9 * n);
			cout << "======== Cau " << i + 1 << "==========";
			gotoxy(50, 8 + 9 * n);
			cout << "ID: " << ds[i]->questionnaireID;
			gotoxy(50, 9 + 9 * n);
			cout << "Ma: " << ds[i]->subjectID;
			gotoxy(50, 10 + 9 * n);
			cout << "Cau hoi: " << ds[i]->content;
			gotoxy(50, 11 + 9 * n);
			cout << "Cau A: " << ds[i]->A;
			gotoxy(50, 12 + 9 * n);
			cout << "Cau B: " << ds[i]->B;
			gotoxy(50, 13 + 9 * n);
			cout << "Cau C: " << ds[i]->C;
			gotoxy(50, 14 + 9 * n);
			cout << "Cau D: " << ds[i]->D;
			gotoxy(50, 15 + 9 * n);
			cout << "Dap an la: " << ds[i]->correct << ". " << ds[i]->answerCorrect;
			n++;
		}		
		break;
		gotoxy(60, 35);
		system("pause");

	}
}

int dem_sl_cau(string a, Questionnaire *ds[], int &nds)
{
	int sl_cau = 0;
	for (int i = 0; i < nds; i++)
	{
		if(ds[i]->subjectID == a)
			sl_cau++;		
	}
	return sl_cau;
}

// ====== hoán đổi câu hỏi =============
void shuffle_array(Questionnaire *ds[], int nds)
{
	int min_position;
	int max_position = nds - 1;
	int swap_position;
	int i = 0;
	while (i < nds - 1)
	{
		min_position = i + 1;
		swap_position = rand() % (max_position - min_position + 1) + min_position;
		hoan_vi_2_cau(ds[i], ds[swap_position]);
		i++;
	}
}

void menu_thi_thu(SubjectList &ds_mon, Questionnaire *ds[], int &nds)
{
check_mon:
	string a;
	gotoxy(50, 10);
	cout << "                      ";
	gotoxy(76, 8);
	cout << "                      ";
	gotoxy(50, 8);
	cout << "NHAP MA MON BAN MUON THI: ";
	getline(cin, a);
	chuan_hoa_chu(a);
	if (ktra_trung_mon(a, ds_mon) < 0)
	{
		gotoxy(50, 10);
		cout << "MON HOC KHONG TON TAI!";
		gotoxy(60, 35);
		system("pause");
		goto check_mon;
	}
	int chon;	
	int sl_cau = dem_sl_cau(a, ds, nds);
	bool kt = true;
	//while (kt == true)
	//{
		int so_cau;
		// int hour = 00, minute = 00, second = 00;
		gotoxy(55, 17);
		cout << "                                          ";
		gotoxy(57, 15);
		cout << "    ";
		gotoxy(50, 9);
		cout << "NHAP SO LUONG CAU HOI : ";	
		gotoxy(76, 9);
		cin >> so_cau;
		if (sl_cau < so_cau)
		{
			gotoxy(55, 17);
			cout << "KHONG DU SO LUONG CAU CUA MON " << a << " DE THI, THIEU: " << so_cau-sl_cau;
			gotoxy(60, 35);
			system("pause");
		}	
		else
		{
		// 	gotoxy(50, 10);
		// 	cout << "NHAP TGIAN DE THI. TIME DINH DANG THEO KIEU: 00:00:00.";
		// 	gotoxy(70, 12);
		// 	cout << "  :"; 
		// 	gotoxy(73, 12);
		// 	cout << "  :"; 
		// 	gotoxy(76, 12);
		// 	cout << "  "; 
		// hour:
		// 	gotoxy(70, 12);
		// 	cin >> setw(2) >> right >> hour;
		// 	if (hour >= 10)
		// 	{
		// 		gotoxy(70, 12);
		// 		cout << "  :";
		// 		goto hour;
		// 	}
		// 	else if (hour == 0)
		// 	{
		// 	minute_1:
		// 		gotoxy(73, 12);
		// 		cin >> setw(2) >> right >> minute;
		// 		if (minute >= 100)
		// 		{
		// 			gotoxy(73, 12);
		// 			cout << "  :";
		// 			goto minute_1;
		// 		}
		// 	second_1:
		// 		gotoxy(76, 12);
		// 		cin >> setw(2) >> right >> second;
		// 		if (second >= 60)
		// 		{
		// 			gotoxy(76, 12);
		// 			cout << "  :";
		// 			goto second_1;
		// 		}
		// 	}
		// 	else
		// 	{
		// 	minute_2:
		// 		gotoxy(73, 12);
		// 		cin >> setw(2) >> right >> minute;
		// 		if (minute >= 60)
		// 		{
		// 			gotoxy(73, 12);
		// 			cout << "  :";
		// 			goto minute_2;
		// 		}
		// 	second_2:
		// 		gotoxy(76, 12);
		// 		cin >> setw(2) >> right >> second;
		// 		if (second >= 60)
		// 		{
		// 			gotoxy(76, 12);
		// 			cout << "  :";
		// 			goto second_2;
		// 		}
		// 	}		
			bo_de(ds, nds, a, so_cau);
			
		}
}

void bo_de(Questionnaire *ds[], int &nds, string a, int n)
{
	xoa_nen();
	khung_cau_hoi();
	cin.ignore();
	Questionnaire *ds_luu[1000];
	char tl[1000];
	int point = 0;
	shuffle_array(ds, nds);
	khung_cau_hoi();
	HighLight();
	gotoxy(70, 8);
	//create a array of question for the chosen subject
	cout << "====== DE THI ======";
	for (int i = 0; i < n; i++)
	{
		if (ds[i]->ma_mh == a)
		{
			gotoxy(47, 13);
			cout << "                                                                         ";
			gotoxy(68, 13);
			cout << "                                   ";
			gotoxy(50, 18);
			cout << "                                 ";
			gotoxy(88, 18);
			cout << "                                ";
			gotoxy(50, 22);
			cout << "                                 ";
			gotoxy(88, 22);
			cout << "                                ";
			gotoxy(50, 10);
			cout << "Cau so " << i + 1;
			gotoxy(47, 13);
			cout << "Cau hoi: " << ds[i]->content;
			gotoxy(47, 18);
			cout << "A. " << ds[i]->A;
			gotoxy(85, 18);
			cout << "B. " << ds[i]->B;
			gotoxy(47, 22);
			cout << "C. " << ds[i]->C;
			gotoxy(85, 22);
			cout << "D. " << ds[i]->D;
		check_tl:
			gotoxy(77, 27);
			cout << "DAP AN: ";
			gotoxy(85, 27);
			cout << "    ";
			gotoxy(85, 27);
			cin >> tl[i];
			up_case_char(tl[i]);
			string cau_tl;
			if (tl[i] == 'A')
			{
				cau_tl = ds[i]->A;
			}
			else if (tl[i] == 'B')
			{
				cau_tl = ds[i]->B;
			}
			else if (tl[i] == 'C')
			{
				cau_tl = ds[i]->C;
			}
			else if (tl[i] == 'D')
			{
				cau_tl = ds[i]->D;
			}
			else
			{
				gotoxy(65, 30);
				cout << "NHAP DAP AN KHONG HOP LE, YEU CAU NHAP LAI!";
				goto check_tl;
			}
			ds_luu[i] = new Questionnaire;
			ds_luu[i]->questionnaireID = ds[i]->questionnaireID;
			ds_luu[i]->content = ds[i]->content;
			ds_luu[i]->A = ds[i]->A;
			ds_luu[i]->B = ds[i]->B;
			ds_luu[i]->C = ds[i]->C;
			ds_luu[i]->D = ds[i]->D;
			ds_luu[i]->correct = ds[i]->correct;
			ds_luu[i]->answerCorrect = ds[i]->answerCorrect;
			if (cau_tl == ds[i]->answerCorrect)
			{
				point++;
			}
		}
	}
	stop = 0;
	xoa_nen();
	
	bool kt = true;
	while (kt == true)
	{
		xoa_nen();
		gotoxy(50, 9);
		cout << "SO DIEM BAN DAT DUOC LA: "<< point << "/" << n << ".";
		gotoxy(50, 10);
		cout << "BAN CO MUON IN RA KET QUA KHONG?";
		gotoxy(50, 11);
		cout << "1. Co.";
		gotoxy(50, 12);
		cout << "0. Khong.";
		gotoxy(50, 13);
		cout << "Ban chon: ";
		int xem_kq;
		cin >> xem_kq;
		switch (xem_kq)
		{
		case 1:
		{
			xoa_nen();
			gotoxy(50, 8);
			cout << "==================================================================";
			gotoxy(50, 9);
			cout << "|CAU| ID |         DAP AN DUNG                         |BAN CHON |";
			gotoxy(50, 10);
			cout << "==================================================================";
			int i = 0;
			for (i = 0; i < n; i++)
			{
				gotoxy(50, 11 + i); cout << "| " << i + 1;
				gotoxy(54, 11 + i); cout << "| " << ds_luu[i]->questionnaireID ;
				gotoxy(59, 11 + i); cout << "|";
				gotoxy(61, 11 + i); cout << ds_luu[i]->correct << ". " << ds_luu[i]->answerCorrect;
				gotoxy(105, 11 + i); cout << "|";
				gotoxy(110, 11 + i); cout << tl[i];
				gotoxy(115, 11 + i); cout << "|";	
			}
			gotoxy(50, 11 + i);
			cout << "------------------------------------------------------------------";
			cin.ignore();
			gotoxy(60, 35);
			system("pause");
			break;		
		}
		case 0:
		{
			cin.ignore();
			kt = false;
			break;
		}
		}
	}
}

// void thi(string ma_sv,DS_LOP ds_l, DS_MON_HOC &ds_mon, cau_hoi_thi *ds[], int &nds)
// {
// 	bool kt = true;
// 	int so_cau;
// 	int hour = 00, minute = 00, second = 00;
// check_mon:
// 	string a;
// 	gotoxy(50, 10);
// 	cout << "                      ";
// 	gotoxy(76, 8);
// 	cout << "                      ";
// 	gotoxy(50, 8);
// 	cout << "NHAP MA MON BAN MUON THI: ";
// 	getline(cin, a);
// 	chuan_hoa_chu(a);
// 	if (ktra_trung_mon(a, ds_mon) < 0)
// 	{
// 		gotoxy(50, 10);
// 		cout << "MON HOC KHONG TON TAI!";
// 		gotoxy(60, 35);
// 		system("pause");
// 		goto check_mon;
// 	}
// 	gotoxy(55, 17);
// 	cout << "                                          ";
// 	gotoxy(57, 15);
// 	cout << "    ";
// 	gotoxy(50, 9);
// 	cout << "NHAP SO LUONG CAU HOI : ";
// 	gotoxy(76, 9);
// 	cin >> so_cau;
// 	int sl_cau = dem_sl_cau(a, ds, nds);
// 	if (sl_cau < so_cau)
// 	{
// 		gotoxy(55, 17);
// 		cout << "KHONG DU SO LUONG CAU CUA MON " << a << " DE THI, THIEU: " << so_cau - sl_cau;
// 		gotoxy(60, 35);
// 		system("pause");
// 	}
// 	else
// 	{
// 		gotoxy(50, 10);
// 		cout << "NHAP TGIAN DE THI. TIME DINH DANG THEO KIEU: hh:mm:ss.";
// 		gotoxy(70, 12);
// 		cout << "  :";
// 		gotoxy(73, 12);
// 		cout << "  :";
// 		gotoxy(76, 12);
// 		cout << "  ";
// 	hour:
// 		gotoxy(70, 12);
// 		cin >> setw(2) >> right >> hour;
// 		if (hour >= 10)
// 		{
// 			gotoxy(70, 12);
// 			cout << "  :";
// 			goto hour;
// 		}
// 		else if (hour == 0)
// 		{
// 		minute_1:
// 			gotoxy(73, 12);
// 			cin >> setw(2) >> right >> minute;
// 			if (minute >= 100)
// 			{
// 				gotoxy(73, 12);
// 				cout << "  :";
// 				goto minute_1;
// 			}
// 		second_1:
// 			gotoxy(76, 12);
// 			cin >> setw(2) >> right >> second;
// 			if (second >= 60)
// 			{
// 				gotoxy(76, 12);
// 				cout << "  :";
// 				goto second_1;
// 			}
// 		}
// 		else
// 		{
// 		minute_2:
// 			gotoxy(73, 12);
// 			cin >> setw(2) >> right >> minute;
// 			if (minute >= 60)
// 			{
// 				gotoxy(73, 12);
// 				cout << "  :";
// 				goto minute_2;
// 			}
// 		second_2:
// 			gotoxy(76, 12);
// 			cin >> setw(2) >> right >> second;
// 			if (second >= 60)
// 			{
// 				gotoxy(76, 12);
// 				cout << "  :";
// 				goto second_2;
// 			}
// 		}
// 		bo_de_sv(ds_l, ma_sv, ds, nds, a, so_cau, hour, minute, second);
// 	}
// }

// void bo_de_sv(DS_LOP &ds_l,string ma_sv,cau_hoi_thi *ds[], int &nds, string ma_mh, int n, int hour, int minute, int second)
// {

// 	xoa_nen();
// 	khung_cau_hoi();
// 	cin.ignore();
// 	cau_hoi_thi *ds_luu[1000];
// 	char tl[1000];
// 	int point = 0;
// 	thread clock;
// 	shuffle_array(ds, nds);
// 	clock = thread(printClock, hour, minute, second);
// 	while (!_kbhit() && stop)
// 	{
// 		khung_cau_hoi();
// 		HighLight();		
// 		gotoxy(70, 8);
// 		cout << "====== DE THI ======";
// 		int i = 0;
// 		for (i = 0; i < n; i++)
// 		{
// 			if (ds[i]->ma_mh == ma_mh)
// 			{
// 				gotoxy(47, 13);
// 				cout << "                                                                         ";
// 				gotoxy(68, 13);
// 				cout << "                                   ";
// 				gotoxy(50, 18);
// 				cout << "                                 ";
// 				gotoxy(88, 18);
// 				cout << "                                ";
// 				gotoxy(50, 22);
// 				cout << "                                 ";
// 				gotoxy(88, 22);
// 				cout << "                                ";
// 				gotoxy(50, 10);
// 				cout << "Cau so " << i + 1 << "/" << n;
// 				gotoxy(47, 13);
// 				cout << "Cau hoi: " << ds[i]->cau_hoi;
// 				gotoxy(47, 18);
// 				cout << "A. " << ds[i]->A;
// 				gotoxy(85, 18);
// 				cout << "B. " << ds[i]->B;
// 				gotoxy(47, 22);
// 				cout << "C. " << ds[i]->C;
// 				gotoxy(85, 22);
// 				cout << "D. " << ds[i]->D;
// 			check_tl:
// 				gotoxy(77, 27);
// 				cout << "DAP AN: ";
// 				gotoxy(85, 27);
// 				cout << "    ";
// 				gotoxy(85, 27);
// 				cin >> tl[i];
// 				up_case_char(tl[i]);
// 				string cau_tl;
// 				if (tl[i] == 'A')
// 				{
// 					cau_tl = ds[i]->A;
// 				}
// 				else if (tl[i] == 'B')
// 				{
// 					cau_tl = ds[i]->B;
// 				}
// 				else if (tl[i] == 'C')
// 				{
// 					cau_tl = ds[i]->C;
// 				}
// 				else if (tl[i] == 'D')
// 				{
// 					cau_tl = ds[i]->D;
// 				}
// 				else
// 				{
// 					gotoxy(65, 30);
// 					cout << "NHAP DAP AN KHONG HOP LE, YEU CAU NHAP LAI!";
// 					goto check_tl;
// 				}
// 				ds_luu[i] = new cau_hoi_thi;
// 				ds_luu[i]->id = ds[i]->id;
// 				ds_luu[i]->cau_hoi = ds[i]->cau_hoi;
// 				ds_luu[i]->A = ds[i]->A;
// 				ds_luu[i]->B = ds[i]->B;
// 				ds_luu[i]->C = ds[i]->C;
// 				ds_luu[i]->D = ds[i]->D;
// 				ds_luu[i]->dap_an = ds[i]->dap_an;
// 				ds_luu[i]->cau_dap_an = ds[i]->cau_dap_an;
// 				if (cau_tl == ds[i]->cau_dap_an)
// 				{
// 					point++;
// 				}
// 			}
// 		}
// 	}
// 	stop = 0;
// 	clock.join();

// 	xoa_nen();
// 	float diem = (float(point) / float(n)) * 10;
// 	them_diem_thi(ds_l, diem, ma_sv, ma_mh);
// 	ghi_file_diem(ds_l);
// 	bool kt = true;
// 	while (kt == true)
// 	{
// 		xoa_nen();
// 		gotoxy(50, 9);
// 		cout << "SO DIEM BAN DAT DUOC LA: " << diem << "(" << point << "/" << n << ").";
// 		gotoxy(50, 10);
// 		cout << "BAN CO MUON IN RA KET QUA KHONG?";
// 		gotoxy(50, 11);
// 		cout << "1. Co.";
// 		gotoxy(50, 12);
// 		cout << "0. Khong.";
// 		gotoxy(50, 13);
// 		cout << "Ban chon: ";
// 		int xem_kq;
// 		cin >> xem_kq;
// 		switch (xem_kq)
// 		{
// 		case 1:
// 		{
// 			xoa_nen();
// 			gotoxy(50, 8);
// 			cout << "==================================================================";
// 			gotoxy(50, 9);
// 			cout << "|CAU| ID |         DAP AN DUNG                         |BAN CHON |";
// 			gotoxy(50, 10);
// 			cout << "==================================================================";
// 			int i = 0;
// 			for (i = 0; i < n; i++)
// 			{
// 				gotoxy(50, 11 + i); cout << "| " << i + 1;
// 				gotoxy(54, 11 + i); cout << "| " << ds_luu[i]->id;
// 				gotoxy(59, 11 + i); cout << "|";
// 				gotoxy(61, 11 + i); cout << ds_luu[i]->dap_an << ". " << ds_luu[i]->cau_dap_an;
// 				gotoxy(105, 11 + i); cout << "|";
// 				gotoxy(110, 11 + i); cout << tl[i];
// 				gotoxy(115, 11 + i); cout << "|";
// 			}
// 			gotoxy(50, 11 + i);
// 			cout << "------------------------------------------------------------------";
// 			cin.ignore();
// 			gotoxy(60, 35);
// 			system("pause");
// 			break;
// 		}
// 		case 0:
// 		{
// 			kt = false;
// 			break;
// 		}
// 		}
// 	}
// }

// ======================== DS DIEM THI ======================
// lop *lay_node_sv(DS_LOP ds_l, string ma_sv)
// {
// 	for (int i = 0; i < ds_l.sl; i++)
// 	{
// 		//if (ds_l.ds[i]->ma_lop == ma_l)
// 		//{
// 			for (SINH_VIEN *k = ds_l.ds[i]->danh_sach_sv.p_head; k != NULL; k = k->p_next)
// 			{
// 				if (k->ma_sv == ma_sv)
// 				{
// 					return ds_l.ds[i];
// 				}
// 			}
// 		//}	
// 	}
// 	return NULL;
// }

// void them_diem_thi(DS_LOP &ds_l, float &diem,string ma_sv, string ma_mh )
// {
// 	lop *tam = lay_node_sv(ds_l, ma_sv);
// 	DIEM_THI *p = khoi_tao_node_diem();
// 	p->ma_mh = ma_mh;
// 	p->diem = diem;
// 	them_1_diem_thi(tam->danh_sach_sv.p_head->danh_sach_diem.p_head, p);
// 	tam->danh_sach_sv.p_head->danh_sach_diem.sl++;
// }

// void in_ds_diem_thi_lop(DS_LOP ds_l)
// {
// 	for (int i = 0; i < ds_l.sl; i++)
// 	{
// 		for (SINH_VIEN *k = ds_l.ds[i]->danh_sach_sv.p_head; k != NULL; k = k->p_next)
// 		{
// 			for (DIEM_THI * p = k->danh_sach_diem.p_head; p != NULL; p = p->p_next)
// 			{
// 				cout << p->ma_mh << ":" << p->diem << endl;
// 			}
// 		}
// 	}
// 	system("pause");
// }

#endif