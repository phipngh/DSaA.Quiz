#ifndef GRAPHIC_H
#define	GRAPHIC_H

#include "CommonTrait.h"

void ColorFrame()
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

void ClearBackground()
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

void ClearInputID()
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

void ClearPrintIDList()
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

void ClearQuestionInputNumber()
{
	int x = 50, y = 9;
	while(y < 13)
	{
		gotoxy(x,y);
		for (int i = 0; i < 60; i++)
			cout<<" ";
		y++;
	}
}

void FrameClassAdd()
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
	ColorFrame();
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

void FrameStudentAdd()
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
	ColorFrame();
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

void FrameSubjectAdd()
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
	int x2 = 60, y2 = 19;
	while (x2 < 110)
	{
		gotoxy(x2, y2);
		cout << "_";
		x2++;
	}
	int x3 = 60, y3 = 22;
	while (x3 < 110)
	{
		gotoxy(x3, y3);
		cout << "_";
		x3++;
	}
	// ke thanh doc
	ColorFrame();
	int x4 = 60, y4 = 17;
	while (y4 < 23)
	{
		gotoxy(x4, y4);
		cout << "|";
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

void FrameQuestionnaire()
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
	ColorFrame();
	int x5= 45, y5 = 12;
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

void VerticalLine1()
{
	int x = 2, y = 2;
	while (y < 36)
	{
		gotoxy(x, y);
		cout << "  ";
		y++;
	}
}
void VerticalLine2()
{
	int x = 40, y = 2;
	while (y < 36)
	{
		gotoxy(x, y);
		cout << "  ";
		y++;
	}
}
void VerticalLine3()
{
	int x = 123, y = 2;
	while (y < 36)
	{
		gotoxy(x, y);
		cout << "  ";
		y++;
	}
}
void HorizontalLine1()
{
	int x = 2, y = 1;
	while (x < 125)
	{
		gotoxy(x, y);
		cout << " ";
		x++;
	}
}
void HorizontalLine2()
{
	int x = 2, y = 36;
	while (x < 125)
	{
		gotoxy(x, y);
		cout << " ";
		x++;
	}
}
void HorizontalLine3()
{
	int x = 3, y = 7;
	while (x < 40)
	{
		gotoxy(x, y);
		cout << " ";
		x++;
	}
}
void HorizontalLine4()
{
	int x = 42, y = 5;
	while (x < 125)
	{
		gotoxy(x, y);
		cout << "_";
		x++;
	}
}
void FrameLogin()
{
	int x = 43, y = 22;
	while (x < 80)
	{
		gotoxy(x, y);
		cout << "_";
		x++;
	}

	int a = 43, b = 27;
	while (a < 80)
	{
		gotoxy(a, b);
		cout << "_";
		a++;
	}
	int e = 43, f = 25;
	while (e < 80)
	{
		gotoxy(e, f);
		cout << "-";
		e++;
	}
	ColorFrame();
	int c = 43, d = 23;
	while (d < 28)
	{

		gotoxy(c, d);
		cout << "|";
		d++;
	}
	int m = 80, n = 23;
	while (n < 28)
	{

		gotoxy(m, n);
		cout << "|";
		n++;
	}
}
void FrameMenu()
{
	ColorFrame();
	VerticalLine1();
	VerticalLine2();
	VerticalLine3();
	HorizontalLine1();
	HorizontalLine2();
	HorizontalLine3();
	HorizontalLine4();
}
void ViewLogin()
{
	ColorFrame();
	VerticalLine1();
	VerticalLine3();
	HorizontalLine1();
	HorizontalLine2();
	HighLight();
	FrameLogin();
}

void ClearInstructionLine(){
	int x = 60, y = 16 ;
	while (x < 100)
	{
		gotoxy(x, y);
			cout << " ";
		x++;
	}
}	
#endif
