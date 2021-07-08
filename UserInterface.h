#ifndef USERINTERFACE_H
#define	USERINTERFACE_H

#include "Controller.h"

using namespace std;

#define width 1300
#define height 800

const int so_item 	 = 22;
const int so_item_sv = 3;
const int dong		 = 9;
const int cot 		 = 5;

const int superTest = 30;
//int menu_tong(ClassList &ds_l, StudentList &ds_sv, QuestionnaireList &ds_cau, SubjectList &ds_mon);
//int menu_tong_sv(DS_LOP &ds_l, DS_SINH_VIEN &ds_sv, DS_CAU_HOI_THI &ds_cau, DS_MON_HOC &ds_mon);
int menu_gv();
//int menu_sv();
void ke_khung_doc_1();
void ke_khung_doc_2();
void ke_khung_doc_3();
void ke_khung_ngang_1();
void ke_khung_ngang_2();
void ke_khung_ngang_3();

// void khung_menu();
// void khung_login();
// void khung_login_mini();

//int login();

void menu_tong(ClassList &ds_l, StudentList &ds_sv, QuestionnaireList &ds_cau, SubjectList &ds_mon)
{

	system("cls");
	Questionnaire *binaryTreeToArrayQuestionnaire[1000];
	int nds = 0;
	ofstream fileout;
	int chon;
	bool kt = true;
	while (kt)
	{
		chon = menu_gv();
		switch (chon)
		{
		case 2: // them lop
		{
			if (ds_l.index >= 500)
			{
				gotoxy(60, 8);
				cout << "Them khong thanh cong vi vuot qua so lop cho phep!";
			}
			else
			{
				khung_them_lop();
				them_lop(ds_l);
				ghi_file_lop(ds_l);
			}
			gotoxy(60, 35);
			system("pause");
			break;
		}
		case 3:	// xoa lop
		{
			if (ds_l.index == 0)
			{
				gotoxy(50, 8);
				cout << "Chua co lop nao de xoa ca!";
			}
			else
			{
				xoa_lop(ds_l);
				ghi_file_lop(ds_l);
			}
			gotoxy(60, 35);
			system("pause");
			break;
		}
		case 4:// chinh lop
		{
			if (ds_l.index == 0)
			{
				gotoxy(50, 8);
				cout << "DATA RONG~~";
			}
			else
			{
				hieu_chinh_lop(ds_l);
				ghi_file_lop(ds_l);
			}
			gotoxy(60, 35);
			system("pause");
			break;
		}
		case 5: // in ds lop theo nien khoa
		{
			if (ds_l.index == 0)
			{
				gotoxy(50, 8);
				cout << "KHONG CO LOP NAO DE IN CA";
				gotoxy(60, 35);
				system("pause");
			}
			else
			{
				in_ds_lop(ds_l);
				gotoxy(60, 35);
				system("pause");
			}

			break;
		}
		case 7:
		{
			nhap_sinh_vien(ds_l, ds_sv);
			gotoxy(60, 35);
			system("pause");
			break;
		}
		case 8:
		{
			//in_ds_sv(ds_l, ds_sv);
			in_ds_sv(ds_sv, ds_l);
			gotoxy(60, 35);
			system("pause");
			break;
		}
		case 10:
		{
			if (ds_mon.index >= 300)
			{
				gotoxy(50, 8);
				cout << "SO LUONG MON HOC VUOT QUA 300, XOA TRC KHI THEM";
				gotoxy(60, 35);
				system("pause");
			}
			else
			{				
				them_mon(ds_mon);
				sap_xep_chen(ds_mon);
				ghi_file_mon(ds_mon);
				gotoxy(60, 35);
				system("pause");
			} 
			break;
		}
		case 11:
		{
			xoa_mon(ds_mon);
			ghi_file_mon(ds_mon);
			gotoxy(60, 35);
			system("pause");
			break;
		}
		case 12:
		{
			hieu_chinh_mon(ds_mon);
			ghi_file_mon(ds_mon);
			gotoxy(60, 35);
			system("pause");
			break;
		}
		case 13:
		{
			xuat_mon(ds_mon);
			gotoxy(60, 35);
			system("pause");
			break;
		}
		case 15:
		{
			Questionnaire_InputQuestion(ds_cau, ds_mon);
			fileout.open("questionnaireTest.txt", ios_base::out);
			QuestionnaireList_WriteFile(ds_cau.questionList, fileout);
			fileout.close();
			Normal();
			gotoxy(60, 35);
			system("pause");
			//Sleep(2000);
			break;
		}
		case 16:
		{
			int currentTask = 2;
			bool keyFlag = false;
			while (currentTask == 1 || currentTask == 2)
			{
				if (keyFlag)
					currentTask = 1;
				else
					currentTask = 2;
				if (currentTask == 2)
				{
					QuestionnaireList_TransferTreeToArray(ds_cau.questionList, binaryTreeToArrayQuestionnaire, nds);
					QuestionnaireList_Print_ID_List(ds_cau, binaryTreeToArrayQuestionnaire, keyFlag, currentTask);
				}
				else if (currentTask == 1 && ds_cau.questionList != NULL)
				{
					bool checkID = false;
					QuestionnaireList_ExecuteFoundDeleteID(ds_cau, checkID, keyFlag);
					if (checkID)
					{
						ofstream fileout;
						fileout.open("questionnaireTest.txt", ios_base::out);
						QuestionnaireList_WriteFile(ds_cau.questionList, fileout);
						fileout.close();
						gotoxy(75, 23);
						cout << "DELETE COMPLETED!!!";
						currentTask = 0;
					}
				}
			}
			QuestionnaireList_FreeAllocateArray(binaryTreeToArrayQuestionnaire, nds);
			break;
		}
		case 17:
		{
			int currentTask = 2;
			bool keyFlag = false;
			while (currentTask == 1 || currentTask == 2)
			{
				if (keyFlag)
					currentTask = 1;
				else
					currentTask = 2;
				if (currentTask == 2)
				{
					QuestionnaireList_TransferTreeToArray(ds_cau.questionList, binaryTreeToArrayQuestionnaire, nds);
					QuestionnaireList_Print_ID_List(ds_cau, binaryTreeToArrayQuestionnaire, keyFlag, currentTask);
					if (ds_cau.questionList != NULL)
					{
						gotoxy(73, 12);
						cout << "PRESS UP TO INPUT ID";
					}
				}
				else if (currentTask == 1 && ds_cau.questionList != NULL)
				{

					bool checkID = false;
					QuestionnaireList_ExecuteFoundUpdateID(ds_cau, checkID, keyFlag);
					if (checkID)
					{
						ofstream fileout;
						fileout.open("questionnaireTest2.txt", ios_base::out);
						QuestionnaireList_WriteFile(ds_cau.questionList, fileout);
						fileout.close();
						QuestionnaireList_CopyOneFileToAnother();
						currentTask = 0;
					}
				}
			}
			QuestionnaireList_FreeAllocateArray(binaryTreeToArrayQuestionnaire, nds);

			break;
		}
		case 18:
		{
			//	string subject_ID_Return = SubjectList_ReturnExistedID(ds_mon);
			QuestionnaireList_TransferTreeToArray(ds_cau.questionList, binaryTreeToArrayQuestionnaire, nds);
			//QuestionnaireList_PrintArray(binaryTreeToArrayQuestionnaire, nds);
			QuestionnaireList_PrintListOfQuestions(ds_cau, binaryTreeToArrayQuestionnaire, ds_mon);
			QuestionnaireList_FreeAllocateArray(binaryTreeToArrayQuestionnaire, nds);
			break;
		}
		case 19:
		{			
			QuestionnaireList_TransferTreeToArray(ds_cau.questionList, binaryTreeToArrayQuestionnaire, nds);
			menu_thi_thu(ds_mon, binaryTreeToArrayQuestionnaire, nds);
			QuestionnaireList_FreeAllocateArray(binaryTreeToArrayQuestionnaire, nds);
			gotoxy(60, 35);
			system("pause");
			//giai phong 
			break;
		}
		case 20:
		{
			
			break;
		}
		case 21:
		{
			// in_ds_diem_thi_lop(ds_l);
			// break;
		}
		case so_item:
		{
			 HighLight();
			gotoxy(60, 20);
			cout << "DANG TAT CHUONG TRINH! ";
			gotoxy(60, 21);
			system("pause");
			kt = false;
		}
		case 27:
		{
			// HighLight();
			// gotoxy(60, 20);
			// cout << "DANG TAT CHUONG TRINH! ";
			// gotoxy(60, 21);
			// system("pause");
			// return 0;
		}
			
		}
		
	}
}

// int menu_tong_sv(string ma_sv,string ho, string ten, DS_LOP &ds_l, DS_SINH_VIEN &ds_sv, DS_CAU_HOI_THI &ds_cau, DS_MON_HOC &ds_mon)
// {
// 	system("cls");
// 	gotoxy(43, 3);
// 	cout << "                                                                                 ";
// 	gotoxy(55, 3);
// 	cout << "ID: " << ma_sv << "                NAME: " << ho << " " << ten;
// 	cau_hoi_thi *ds[1000];
// 	int nds = 0;
// 	int chon;
// 	while (true)
// 	{
// 		chon = menu_sv();
// 		switch (chon)
// 		{
// 		case 1: 
// 		{
// 			chuyen_cay_sang_mang(ds_cau.TREE, ds, nds);
// 			thi(ma_sv, ds_l, ds_mon, ds, nds);
// 			giai_phong_ds_cau(ds, nds);
// 			gotoxy(60, 35);
// 			system("pause");
// 			break;
// 		}
// 		case 2:	
// 		{
// 			break;
// 		}
// 		case so_item_sv:
// 			HighLight();
// 			gotoxy(60, 20);
// 			cout << "DANG TAT CHUONG TRINH! ";
// 			gotoxy(60, 21);
// 			system("pause");
// 			exit(0);
// 			return 0;
// 		case 27:
// 			HighLight();
// 			gotoxy(60, 20);
// 			cout << "DANG TAT CHUONG TRINH! ";
// 			gotoxy(60, 21);
// 			system("pause");
// 			return 0;
// 		}
// 	}
// }

// int menu_sv()
// {
// 	while (true)
// 	{
// 		khung_menu();
// 		HighLight();
// 		gotoxy(5, 3);
// 		cout << "HUONG DAN:";
// 		gotoxy(5, 4);
// 		cout << "SU DUNG PHIM LEN XUONG DE MOVE";
// 		gotoxy(5, 5);
// 		cout << "ESC: THOAT";
// 		gotoxy(25, 5);
// 		cout << "ENTER: CHON";
// 		int chon = 0;

// 		Normal();
// 		char thucdon_sv[so_item_sv][35] = {" + THI THU                        ",
// 										" + XEM LAI BAI LAM                ",
// 										" + EXIT                           " };
// 		for (int i = 0; i < so_item_sv; i++)
// 		{
// 			gotoxy(cot, dong + i);
// 			cout << thucdon_sv[i];
// 		}
// 		HighLight();
// 		gotoxy(cot, dong + chon);
// 		cout << thucdon_sv[chon];
// 		char kytu;
// 		xoa_nen();
// 		do
// 		{
// 			kytu = _getch();
// 			if (kytu == -32) kytu = _getch();
// 			if (kytu == 8) kytu != _getch();
// 			switch (kytu)
// 			{
// 			case Up:
// 			{
// 				if (chon > 0)
// 				{
// 					Normal();
// 					gotoxy(cot, dong + chon); cout << thucdon_sv[chon];
// 					chon--;
// 					HighLight();
// 					gotoxy(cot, dong + chon); 	cout << thucdon_sv[chon];
// 				}
// 				break;
// 			}
// 			case Down:
// 			{
// 				if (chon + 1 < so_item_sv)
// 				{
// 					Normal();
// 					gotoxy(cot, dong + chon);	cout << thucdon_sv[chon];
// 					chon++;
// 					HighLight();
// 					gotoxy(cot, dong + chon); 	cout << thucdon_sv[chon];
// 				}
// 				break;
// 			}
// 			case ESC:
// 			{
// 				return so_item_sv;
// 			}
// 			case 13:
// 			{
// 				return chon + 1;
// 			}
// 			}
// 		} while (true);
// 	}
// }

int menu_gv()
{
	while (true)
	{		
		khung_menu();
		HighLight();
		gotoxy(5, 3);
		cout << "HUONG DAN:";
		gotoxy(5, 4);
		cout << "SU DUNG PHIM LEN XUONG DE MOVE";
		gotoxy(5, 5);
		cout << "ESC: THOAT";
		gotoxy(25, 5);
		cout << "ENTER: CHON";
		gotoxy(43, 3);
		cout << "                                                                               ";
		gotoxy(50, 3);
		cout << "ID: GIAO VIEN";

		int chon = 0;
		Normal();
		char thucdon[so_item][50] = {" + LOP                            ",
									 "   - THEM LOP                     ",
									 "   - XOA LOP                      ",
									 "   - HIEU CHINH LOP               ",
									 "   - IN DANH SACH LOP             ",
									 " + SINH VIEN                      ",
									 "   - THEM SINH VIEN               ",
									 "   - IN DANH SACH SINH VIEN       ",
									 " + MON HOC                        ",
									 "   - THEM MON HOC                 ",
									 "   - XOA MON HOC                  ",
									 "   - HIEU CHINH MON               ",
									 "   - IN DANH SACH MON             ",
									 " + QUESTIONNAIRE                  ",
									 "   - ADD                 ",	  //15
									 "   - DELETE                  ", //16
									 "   - UPDATE           ",
									 "   - PRINT QUESTION         ", //17
									 " + THI THU                        ",
									 " + IN BAI THI CUA SINH VIEN       ",
									 " + IN KET QUA THI CUA 1 LOP       ",
									 " + EXIT                           "};
		for (int i = 0; i < so_item; i++)
		{
			gotoxy(cot, dong + i);
			cout << thucdon[i];
		}
		HighLight();
		gotoxy(cot, dong + chon);
		cout << thucdon[chon];
		char kytu;
		xoa_nen();
		do
		{
			kytu = _getch();
			if (kytu == -32)
				kytu = _getch();
			if (kytu == 8)
				kytu != _getch();
			switch (kytu)
			{
			case UP:
			{
				if (chon > 0)
				{
					Normal();
					gotoxy(cot, dong + chon); cout << thucdon[chon];
					chon--;
					HighLight();
					gotoxy(cot, dong + chon); 	cout << thucdon[chon];
				}
				break;
			}
			case DOWN:
			{
				if (chon + 1 < so_item)
				{
					Normal();
					gotoxy(cot, dong + chon);	cout << thucdon[chon];
					chon++;
					HighLight();
					gotoxy(cot, dong + chon); 	cout << thucdon[chon];
				}
				break;
			}
			case ESC:
			{
				return so_item;
			}
			case 13:
			{
				return chon + 1;
			}
			}
		} while (true);
		
	}	
}

// int login()
// {
// 	// =============== khai bao bien =================
// 	DS_SINH_VIEN ds_sv;
// 	DS_CAU_HOI_THI ds_cau;
// 	DS_MON_HOC ds_mon;
// 	DS_LOP ds_l;
// 	cau_hoi_thi *ds[1000];
// 	int nds = 0;
// 	// ============ load file ==================
// 	doc_file_ds_cau(ds_cau);
// 	doc_file_ds_lop(ds_l);
// 	doc_file_ds_mon(ds_mon);
// 	doc_file_ds_sv(ds_l);
// 	//doc_file_diem__thi(ds_l);
// 	system("cls");
// 	khung_login();
// 	string id;
// 	int count = 0, ch;
// 	string pass = "";
// 	HighLight();
// 	gotoxy(42, 6);
// 	cout << "  ___  _   _         _   _   _     ___     ";
// 	gotoxy(42, 7);
// 	cout << " / _ \\| | | |  /\\   | \\ | | | |   | o |   ";
// 	gotoxy(42, 8);
// 	cout << "| | | | | | | /  \\  |  \\| | | |    | |    ";
// 	gotoxy(42, 9);
// 	cout << "| | | | | | |/ /\\ \\ | . ' | | |    | |    ";
// 	gotoxy(42, 10);
// 	cout << "| |_| | |_| / ____ \\| |\\  | | |___ | |    ";
// 	gotoxy(42, 11);
// 	cout << " \\__\\_\\\\___/_/    \\_\\_| \\_| |_____|___|   ";
// 	gotoxy(18, 13);
// 	cout << "  _______ _   _ ___    _______ _____           ___     _   _  ___  _   _ ___ _____  __    __   ";
// 	gotoxy(18, 14);
// 	cout << " |__   __| | | | o |  |__   __/  _  |   /\\    / _ \\   | \\ | |/ __\\| | | | o |  ___||  \\  /  |  ";
// 	gotoxy(18, 15);
// 	cout << "    | |  | |_| || |      | |  | | | |  /  \\  | / \\_\\  |  \\| | / __| |_| || || |___ | . \\/ . |  ";
// 	gotoxy(18, 16);
// 	cout << "    | |  |  _  || |      | |  | |/ /  / /\\ \\ | |  __  | . ' | |[_ ]  _  || ||  ___|| |\\  /| |  ";
// 	gotoxy(18, 17);
// 	cout << "    | |  | | | || |      | |  | | \\ \\/ ____ \\| \\_/ /  | |\\  | \\_/ / | | || || |___ | | \\/ | |  ";
// 	gotoxy(18, 18);
// 	cout << "    |_|  |_| |_|___|     |_|  |_|  \\/_/    \\_\\\\___/   |_| \\_|\\___/|_| |_|___|_____|___|  |___| ";
// wrong:
// 	HighLight();
// 	gotoxy(45, 24);
// 	cout << "NHAP ID	:";
// 	gotoxy(45, 26);
// 	cout << "NHAP PASS	:";
// 	gotoxy(60, 24);
// 	getline(cin, id);
// 	chuan_hoa_chu(id);
// 	gotoxy(60, 26);
// 	while (ch = _getch())
// 	{
// 		bool kt_break = false;
// 		if (ch == 80 || ch == 72 || ch == 77 || ch == 75) ch = _getch();
// 		else if(ch == 27) break;
// 		else
// 		{
// 			if (ch == 13)
// 			{
// 				if ((pass == "GV") && (id == "GV"))
// 				{
// 					gotoxy(52, 30);
// 					cout << "LOGIN SUCCESSFUL!";
// 					gotoxy(48, 35);
// 					system("pause");
// 					menu_tong(ds_l, ds_sv, ds_cau, ds_mon);
// 					kt_break = true;
// 					break;
// 				}
// 				for (int i = 0; i < ds_l.sl; i++)
// 				{
// 					for (SINH_VIEN *k = ds_l.ds[i]->danh_sach_sv.p_head; k != NULL; k = k->p_next)
// 					{
// 						if ((id == k->ma_sv) && (pass == k->password))
// 						{
// 							gotoxy(52, 30);
// 							cout << "LOGIN  SUCCESSFUL!";
// 							gotoxy(48, 35);
// 							system("pause");
// 							menu_tong_sv(k->ma_sv,k->ho,k->ten,ds_l, ds_sv, ds_cau, ds_mon);
// 							kt_break = true;
// 							break;
// 						}
// 					}
// 				}								
// 			gotoxy(55, 30);
// 			cout << "LOGIN FALSE!";
// 			pass = "";
// 			count++;
// 			if (count == 3)
// 			{
// 				cout << "YOU ENTER WRONG 3 TIMES, SYSTEM SUT DOWN AFTER 3 SECONDS!";
// 				return 0;
// 			}				
// 			gotoxy(60, 24);
// 			cout << "                    ";
// 			gotoxy(60, 26);
// 			cout << "                    ";
// 			goto wrong;
// 			}
// 			else if (ch == 8)
// 			{
// 				if (pass.length() > 0)
// 				{
// 					cout << "\b \b";
// 					pass.erase(pass.length() - 1);
// 				}
// 			}
// 			else
// 			{
// 				cout << "*";
// 				pass += ch;
// 				chuan_hoa_chu(pass);
// 			}
// 		}
// 		if (kt_break == true)
// 		{
// 			break;
// 		}
// 	}
// }

#endif
