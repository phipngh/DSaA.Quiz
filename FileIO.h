#ifndef FILEIO_H
#define FILEIO_H

#include "Graphic.h"

//===================== doc file danh sach lop =======================
void ClassFileInput(ClassList &ds_l)
{
	ifstream filein;
	filein.open("lop.txt", ios_base ::in);
	while (filein.eof() != true)
	{
		ds_l.classList[ds_l.index] = new Class;		
		getline(filein, ds_l.classList[ds_l.index]->classID, ',');
		getline(filein, ds_l.classList[ds_l.index]->className);
		ds_l.index++;
	}
	filein.close();
}

//===================== doc file danh sach mon =======================
void SubjectFileInput(SubjectList &ds_mon)
{
	ifstream filein;
	filein.open("mon.txt", ios_base::in);
	while (filein.eof() != true)
	{
		getline(filein, ds_mon.subjectList[ds_mon.index].subjectID, ',');
		getline(filein, ds_mon.subjectList[ds_mon.index].subjectName);
		ds_mon.index++;
	}
	filein.close();
}

//===================== doc file danh sach sv =======================
void StudentFileInput(ClassList &ds_l)
{
	ifstream filein;
	filein.open("sinhvien.txt", ios_base::in);
	for (int i = 0; i < ds_l.index; i++)
	{
		filein >> ds_l.classList[i]->studentList.index;
		filein.ignore();
		for (int j=0;j< ds_l.classList[i]->studentList.index; j++)
		{
			Student *p = StudentNodeInitialize();
			getline(filein, p->studentID, ',');
			getline(filein, p->studentLastName, ',');
			getline(filein, p->studentFirstName, ',');
			getline(filein, p->gender, ',');
			getline(filein, p->password);
			StringFormat(p->studentID);
			StringFormat(p->studentLastName);
			StringFormat(p->studentFirstName);
			StringFormat(p->gender);
			//StringFormat(p->password);
			StudentAdd(ds_l.classList[i]->studentList.pHead, p);
		}
	}
	filein.close();
}

//===================== doc file danh sach cau hoi =======================
void QuestionnaireFileInput(QuestionnaireList &ds_cau)
{
	ifstream filein;
	filein.open("questionnaireTest.txt", ios_base::in);
	stringstream ss;
	string currentLine = "";
	while (filein.eof() != true)
	{
		Questionnaire *x = QuestionnaireCreateNodeWithoutID();
		filein >> x->questionnaireID;
		filein.ignore();
		getline(filein, x->subjectID);
		getline(filein, x->content);
		getline(filein, x->A);
		getline(filein, x->B);
		getline(filein, x->C);
		getline(filein, x->D);
		getline(filein, currentLine, '.');
		x->correct = currentLine[0];
		getline(filein, x->answerCorrect);
		StringFormat(x->subjectID);
		StringFormat(x->content);
		StringFormat(x->A);
		StringFormat(x->B);
		StringFormat(x->C);
		StringFormat(x->D);
		ToUpper(x->correct);
		QuestionnaireAcceptAnswer(x);
		ds_cau.questionList = QuestionnaireAdd(ds_cau.questionList, x);
	}
	filein.close();
}


//===================== doc file danh sach lop =======================
void ClassFileOutput(ClassList &ds_l)
{
	ofstream fileout;
	//fileout.open("lop.txt", ios_base::out);
	fileout.open("lop.txt", ios_base::trunc);
	for (int i = 0; i < ds_l.index; i++)
	{
		fileout << ds_l.classList[i]->classID << ",";
		fileout << ds_l.classList[i]->className;
		if (i != ds_l.index - 1)
		{
			fileout << "\n";
		}		
	}
	fileout.close();
}

//===================== doc file danh sach mon =======================
void SubjectFileOutput(SubjectList &ds_mon)
{
	ofstream fileout;
	fileout.open("mon.txt", ios_base::trunc);
	for (int i = 0; i < ds_mon.index; i++)
	{
		fileout << ds_mon.subjectList[i].subjectID <<",";
		fileout << ds_mon.subjectList[i].subjectName;
		if (i != ds_mon.index - 1)
		{
			fileout << "\n";
		}		
	}
	fileout.close();
}

//===================== doc file danh sach sv =======================
void StudentFileOutput(ClassList &ds_l)
{
	ofstream fileout;
	fileout.open("sinhvien.txt", ios_base::out);
	for (int i = 0; i < ds_l.index; i++)
	{
		fileout << ds_l.classList[i]->studentList.index;
		fileout << "\n";
		for (Student *k = ds_l.classList[i]->studentList.pHead; k!= NULL; k= k->pNext)
		{
			fileout << k->studentID << ",";
			fileout << k->studentLastName << ",";
			fileout << k->studentFirstName << ",";
			fileout << k->gender << ",";
			fileout << k->password;
			if (k->pNext != NULL)
			{
				fileout << "\n";
			}
		}
		if (i != ds_l.index - 1)
		{
			fileout << "\n";
		}
	}
	fileout.close();
}

//===================== doc file danh sach cau hoi =======================
void QuestionnaireWriteCurrentQuestion(Questionnaire *questionListToText, ofstream &fileout)
{
	fileout << questionListToText->questionnaireID << endl;
	fileout << questionListToText->subjectID << endl;
	fileout << questionListToText->content << endl;
	fileout << questionListToText->A << endl;
	fileout << questionListToText->B << endl;
	fileout << questionListToText->C << endl;
	fileout << questionListToText->D << endl;
	fileout << questionListToText->correct << "." << questionListToText->answerCorrect << endl;
}

void QuestionnaireFileOutput(Questionnaire *&questionListToText, ofstream &fileout)
{
	if (questionListToText == NULL)
	{
		return;
	}
	QuestionnaireWriteCurrentQuestion(questionListToText, fileout);
	QuestionnaireFileOutput(questionListToText->pLeft, fileout);
	QuestionnaireFileOutput(questionListToText->pRight, fileout);
}

void QuestionnaireCopyOneFileToAnother()
{
	string line = "";
	ifstream filein;
	ofstream fileout;
	filein.open("questionnaireTest2.txt", ios_base::in);
	fileout.open("questionnaireTest.txt", ios_base::out);
	if (filein && fileout)
	{
		while (getline(filein, line))
		{
			fileout << line << "\n";
		}
		gotoxy(60, 35);
		system("pause");
	}
	else
	{
		cout << "\nCannot read file";
		system("pause");
	}
	fileout.flush();
	filein.close();
	fileout.close();
}

#endif
