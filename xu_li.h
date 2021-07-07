
#ifndef XU_LY_H
#define XU_LY_H

#include "ctdl.h"

void Normal();
void HighLight();
void color_khung();

void standardizeSentence(string &a)
{
	while (a[0] == ' ')
	{
		a.erase(a.begin() + 0);
	}

	if (a[a.length() > 1])
	{
		while (a[a.length() - 1] == ' ')
		{
			a.erase(a.begin() + a.length() - 1);
		}
	}

	for (size_t i = 0; i < a.length(); i++)
	{
		if (a[i] == ' ' && a[i + 1] == ' ')
		{
			a.erase(a.begin() + i + 1);
			i--;
		}
	}
}

void standardizeID(string &a)
{
	while (a[0] == ' ')
	{
		a.erase(a.begin() + 0);
	}

	if (a[a.length() > 1])
	{
		while (a[a.length() - 1] == ' ')
		{
			a.erase(a.begin() + a.length() - 1);
		}
	}

	for (unsigned int i = 0; i < a.length(); i++)
	{
		if (a[i] == ' ' && a[i + 1] == ' ')
		{
			a.erase(a.begin() + i + 1);
			i--;
		}
	}

	for (size_t i = 0; i < a.length(); i++)
	{
		if (a[i] >= 97 && a[i] <= 122)
		{
			a[i] -= 32;
		}
	}
}

void uppercaseLetter(char &a)
{
	if (a >= 97 && a <= 122)
	{
		a -= 32;
	}
}

// ============ x? lí câu h?i ===================

bool QuestionnaireList_CheckExistID(Questionnaire *currentQuestion, int questionnaireID)
{
	if (currentQuestion == NULL)
	{
		return false;
	}
	else
	{
		if (currentQuestion->questionnaireID == questionnaireID)
		{
			return true;
		}
		else if (currentQuestion->questionnaireID < questionnaireID)
		{
			QuestionnaireList_CheckExistID(currentQuestion->pRight, questionnaireID);
		}
		else
		{
			QuestionnaireList_CheckExistID(currentQuestion->pLeft, questionnaireID);
		}
	}
}

int Questionnaire_CreateRandomID(Questionnaire *t)
{
	int cauHoiID; // 000->999;
	srand(time(NULL));
	do
	{
		cauHoiID = rand() % (1000 - 1 + 1) + 1;
	} while (QuestionnaireList_CheckExistID(t, cauHoiID));
	return cauHoiID;
}

Questionnaire *Questionnaire_CreateNodeWithoutID()
{
	Questionnaire *questionnaireReturn = new Questionnaire;
	questionnaireReturn->height = 1;
	questionnaireReturn->pLeft = NULL;
	questionnaireReturn->pRight = NULL;
	return questionnaireReturn;
}

Questionnaire *Questionnaire_CreateNode(tree treeCheckingExist)
{
	Questionnaire *p = new Questionnaire;
	p->questionnaireID = Questionnaire_CreateRandomID(treeCheckingExist);
	p->height = 1;
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}

int Questionnaire_GetHeight(tree currentNode)
{
	if (currentNode == NULL)
		return 0;
	return currentNode->height;
}

int Questionnaire_GetBalanceFactor(tree currentNode)
{
	if (currentNode == NULL)
		return 0;
	return Questionnaire_GetHeight(currentNode->pLeft) - Questionnaire_GetHeight(currentNode->pRight);
}

int returnMaxNumber(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	return b;
}

Questionnaire *QuestionnaireList_LeftRotation(Questionnaire *&currentNode)
{
	if (currentNode == NULL)
		return NULL;
	Questionnaire *nodeToRotate = currentNode->pRight;
	currentNode->pRight = nodeToRotate->pLeft;
	nodeToRotate->pLeft = currentNode;
	currentNode->height = returnMaxNumber(Questionnaire_GetHeight(currentNode->pLeft), Questionnaire_GetHeight(currentNode->pRight)) + 1;
	nodeToRotate->height = returnMaxNumber(Questionnaire_GetHeight(nodeToRotate->pLeft), Questionnaire_GetHeight(nodeToRotate->pRight)) + 1;
	return nodeToRotate;
}

Questionnaire *QuestionnaireList_RightRotation(Questionnaire *&currentNode)
{
	if (currentNode == NULL)
		return NULL;
	Questionnaire *nodeToRotate = currentNode->pLeft;
	currentNode->pLeft = nodeToRotate->pRight;
	nodeToRotate->pRight = currentNode;

	currentNode->height = returnMaxNumber(Questionnaire_GetHeight(currentNode->pLeft), Questionnaire_GetHeight(currentNode->pRight)) + 1;
	nodeToRotate->height = returnMaxNumber(Questionnaire_GetHeight(nodeToRotate->pLeft), Questionnaire_GetHeight(nodeToRotate->pRight)) + 1;
	return nodeToRotate;
}

Questionnaire *QuestionnaireList_Add(tree &t, Questionnaire *p)
{
	if (p->content != "")
	{
		if (t == NULL)
		{
			return p;
		}
		else
		{
			if (p->questionnaireID > t->questionnaireID)
			{
				t->pRight = QuestionnaireList_Add(t->pRight, p);
			}
			else if (p->questionnaireID < t->questionnaireID)
			{
				t->pLeft = QuestionnaireList_Add(t->pLeft, p);
			}
			t->height = returnMaxNumber(Questionnaire_GetHeight(t->pLeft), Questionnaire_GetHeight(t->pRight)) + 1;
			int balance = Questionnaire_GetBalanceFactor(t);
			if (balance > 1)
			{ // left tree has more node
				if (p->questionnaireID > t->pLeft->questionnaireID)
				{

					t->pLeft = QuestionnaireList_LeftRotation(t->pLeft);
				}
				return QuestionnaireList_RightRotation(t);
			}
			else if (balance < -1)
			{
				if (p->questionnaireID < t->pRight->questionnaireID)
				{
					t->pRight = QuestionnaireList_RightRotation(t->pRight);
				}
				return QuestionnaireList_LeftRotation(t);
			}
		}
	}
	return t;
}

void Questionnaire_AcceptAnswer(Questionnaire *&p)
{
	if (p->correct == 'A')
	{
		p->answerCorrect = p->A;
	}
	else if (p->correct == 'B')
	{
		p->answerCorrect = p->B;
	}
	else if (p->correct == 'C')
	{
		p->answerCorrect = p->C;
	}
	else if (p->correct == 'D')
	{
		p->answerCorrect = p->D;
	}
}

void them_1_sinh_vien(Student *&pHead, Student *p)
{
	if (pHead == NULL)
	{
		pHead = p;
	}
	else
	{
		for (Student *k = pHead; k != NULL; k = k->pNext)
		{
			if (k->pNext == NULL)
			{
				k->pNext = p;
				break;
			}
		}
	}
}

Student *khoi_tao_node_sv()
{
	Student *p = new Student;
	if (p == NULL)
	{
		cout << "Khong du bo nho de cap phat!";
		return NULL;
	}
	p->pNext = NULL;
	return p;
}

// void them_1_diem_thi(DIEM_THI *&p_head, DIEM_THI *p)
// {
// 	if (p_head == NULL)
// 	{
// 		p_head = p;
// 	}
// 	else
// 	{
// 		for (DIEM_THI *k = p_head; k != NULL; k = k->p_next)
// 		{
// 			if (k->p_next == NULL)
// 			{
// 				k->p_next = p;
// 				break;
// 			}
// 		}
// 	}
// }

// DIEM_THI* khoi_tao_node_diem()
// {
// 	DIEM_THI *p = new DIEM_THI;
// 	if (p == NULL)
// 	{
// 		cout << "KHONG DU BO NHO DE CAP PHAT!";
// 		return NULL;
// 	}
// 	p->p_next = NULL;
// 	return p;
// }

void color_khung()
{
	SetBGColor(11);
}

void Normal()
{
	SetColor(15);
	SetBGColor(0);
}

void HighLight()
{
	SetColor(11);
	SetBGColor(0);
}

void xoa_nen()
{
	int x = 42, y = 6;
	while (y < 36)
	{
		gotoxy(x, y);
		for (int i = 0; i < 81; i++) // 81 la so khoang trang de xoa nen ben canh
			cout << " ";
		y++;
	}
}

void clearInputID()
{
	int x = 50, y = 9;
	while (y <= 11)
	{
		gotoxy(x, y);
		for (int i = 0; i < 70; i++)
			cout << " ";
		y++;
	}
}

void clearPrint_ID_List()
{
	int x = 50, y = 19;
	while (y < 36)
	{
		gotoxy(x, y);
		for (int i = 0; i < 70; i++)
			cout << " ";
		y++;
	}
}

void khung_them_lop()
{
	HighLight();
	// ke thanh ngang

	int x1 = 60, y1 = 16;
	while (x1 < 110)
	{
		gotoxy(x1, y1);
		cout << "_";
		x1++;
	}
	int x3 = 60, y3 = 19;
	while (x3 < 110)
	{
		gotoxy(x3, y3);
		cout << "_";
		x3++;
	}
	int x2 = 60, y2 = 22;
	while (x2 < 110)
	{
		gotoxy(x2, y2);
		cout << "_";
		x2++;
	}
	int x6 = 60, y6 = 25;
	while (x6 < 110)
	{
		gotoxy(x6, y6);
		cout << "_";
		x6++;
	}
	// ke thanh doc
	color_khung();
	int x4 = 60, y4 = 17;
	while (y4 < 26)
	{
		gotoxy(x4, y4);
		cout << "|";
		y4++;
	}
	int x5 = 110, y5 = 17;
	while (y5 < 26)
	{
		gotoxy(x5, y5);
		cout << "|";
		y5++;
	}
}

void khung_them_sv()
{
	HighLight();
	int x7 = 60, y7 = 13;
	while (x7 < 110)
	{
		gotoxy(x7, y7);
		cout << "_";
		x7++;
	}
	int x1 = 60, y1 = 16;
	while (x1 < 110)
	{
		gotoxy(x1, y1);
		cout << "_";
		x1++;
	}
	int x3 = 60, y3 = 19;
	while (x3 < 110)
	{
		gotoxy(x3, y3);
		cout << "_";
		x3++;
	}
	int x2 = 60, y2 = 22;
	while (x2 < 110)
	{
		gotoxy(x2, y2);
		cout << "_";
		x2++;
	}
	int x6 = 60, y6 = 25;
	while (x6 < 110)
	{
		gotoxy(x6, y6);
		cout << "_";
		x6++;
	}
	int x8 = 60, y8 = 28;
	while (x8 < 110)
	{
		gotoxy(x8, y8);
		cout << "_";
		x8++;
	}
	// ke thanh doc
	color_khung();
	int x4 = 60, y4 = 14;
	while (y4 < 29)
	{
		gotoxy(x4, y4);
		cout << "|";
		y4++;
	}
	int x5 = 110, y5 = 14;
	while (y5 < 29)
	{
		gotoxy(x5, y5);
		cout << "|";
		y5++;
	}
}

void khung_them_mon()
{
	HighLight();
	// ke thanh ngang

	int x1 = 60, y1 = 16;
	while (x1 < 110)
	{
		gotoxy(x1, y1);
		cout << ">";
		x1++;
	}
	int x2 = 60, y2 = 19;
	while (x2 < 110)
	{
		gotoxy(x2, y2);
		cout << ">";
		x2++;
	}
	int x3 = 60, y3 = 22;
	while (x3 < 110)
	{
		gotoxy(x3, y3);
		cout << ">";
		x3++;
	}
	// ke thanh doc
	color_khung();
	int x4 = 60, y4 = 17;
	while (y4 < 23)
	{
		gotoxy(x4, y4);
		cout << "^";
		y4++;
	}
	int x5 = 110, y5 = 17;
	while (y5 < 23)
	{
		gotoxy(x5, y5);
		cout << "|";
		y5++;
	}
}

void khung_cau_hoi()
{
	HighLight();
	//ke thanh ngang
	int x1 = 45, y1 = 11;
	while (x1 < 120)
	{
		gotoxy(x1, y1);
		cout << "_";
		x1++;
	}
	int x2 = 45, y2 = 16;
	while (x2 < 120)
	{
		gotoxy(x2, y2);
		cout << "_";
		x2++;
	}
	int x3 = 45, y3 = 20;
	while (x3 < 120)
	{
		gotoxy(x3, y3);
		cout << "_";
		x3++;
	}
	int x4 = 45, y4 = 24;
	while (x4 < 120)
	{
		gotoxy(x4, y4);
		cout << "_";
		x4++;
	}
	int x8 = 75, y8 = 28;
	while (x8 < 93)
	{
		gotoxy(x8, y8);
		cout << "_";
		x8++;
	}
	// ke thanh doc
	color_khung();
	int x5 = 45, y5 = 12;
	while (y5 < 25)
	{
		gotoxy(x5, y5);
		cout << "|";
		y5++;
	}
	int x6 = 120, y6 = 12;
	while (y6 < 25)
	{
		gotoxy(x6, y6);
		cout << "|";
		y6++;
	}
	int x7 = 83, y7 = 17;
	while (y7 < 25)
	{
		gotoxy(x7, y7);
		cout << "|";
		y7++;
	}
	int x9 = 75, y9 = 26;
	while (y9 < 29)
	{
		gotoxy(x9, y9);
		cout << "|";
		y9++;
	}
}

// ========== HAM IN TIME =================
/*
bool stop = 1;

struct Hour {
	int hour;
	int minute;
	int second;
};

char inToA(int k) {
	switch (k)
	{
	case 0:return '0';
	case 1:return '1';
	case 2:return '2';
	case 3:return '3';
	case 4:return '4';
	case 5:return '5';
	case 6:return '6';
	case 7:return '7';
	case 8:return '8';
	case 9:return '9';
	default:
		break;
	}
}

void insertarray(char *h, Hour *j) {
	int bait = 0;
	bait = j->second;
	h[7] = inToA(bait % 10);
	h[6] = inToA(bait /= 10);
	bait = j->minute;
	h[4] = inToA(bait % 10);
	h[3] = inToA(bait /= 10);
	bait = j->hour;
	h[1] = inToA(bait % 10);
	h[0] = inToA(bait /= 10);
}

bool changetime(Hour *h) {
	if (h->second > 0) --h->second;
	else if (h->minute > 0) {
		h->second = 59;
		--h->minute;
	}
	else if (h->hour > 0)
	{
		--h->hour;
		h->minute = 59;
		h->second = 59;
	}
	else return 0;
	return 1;
}

//dung de in ra mot chuoi thay the ham cout
void WriteBlockChar(char * Arraych,
	int row, int col,
	int x, int y,
	int color)
{
	CHAR_INFO *charater = new CHAR_INFO[row*col];
	for (int i = 0; i < row*col; i++) {
		charater[i].Attributes = color;
		charater[i].Char.AsciiChar = Arraych[i];
	}
	COORD sizebuff = { col,row };
	COORD pos = { 0,0 };
	SMALL_RECT earea = { x,y,x + col - 1,y + row - 1 };
	WriteConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), charater, sizebuff, pos, &earea);
	delete[] charater;
}DIEM_THI* khoi_tao_node_diem()
// {
// 	DIEM_THI *p = new DIEM_THI;
// 	if (p == NULL)
// 	{
// 		cout << "KHONG DU BO NHO DE CAP PHAT!";
// 		return NULL;
// 	}
// 	p->p_next = NULL;
// 	return p;
// }

void close(DWORD evt) {
	if (evt == CTRL_CLOSE_EVENT) stop = 0;
}

void printClock(int hour, int minute, int second )
{
	Hour h = { hour, minute, second };
	char a[8] = { '0','0',':','0','0',':','0','0' };
	while (stop)
	{
		if (!changetime(&h)) stop = 0;
		insertarray(a, &h);		
		WriteBlockChar(a, 1, 8, 90, 9, 0x007 | 0x015);
		Sleep(970);
	}
	return;
}

*/

#endif
