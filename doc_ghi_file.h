#ifndef DOC_GHI_FILE_H
#define	DOC_GHI_FILE_H

#include "xu_li.h"
//===================== doc file danh sach lop =======================
void doc_file_ds_lop(ClassList &ds_l)
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

void doc_file_ds_mon(SubjectList &ds_mon)
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

void doc_file_ds_cau(QuestionnaireList &ds_cau)
{
	ifstream filein;
	filein.open("cauhoi.txt", ios_base::in);
	while (filein.eof() != true)
	{
		Questionnaire *x = khoi_tao_node_cau_hoi();
		filein >> x->questionnaireID;
		filein.ignore();
		getline(filein, x->subjectID);
		getline(filein, x->content);
		getline(filein, x->A);
		getline(filein, x->B);
		getline(filein, x->C);
		getline(filein, x->D);
		filein >> x->correct;
		chuan_hoa_chu(x->subjectID);
		chuan_hoa_chu(x->content);
		chuan_hoa_chu(x->A);
		chuan_hoa_chu(x->B);
		chuan_hoa_chu(x->C);
		chuan_hoa_chu(x->D);
		up_case_char(x->correct);
		xu_li_dap_an(x);
		them_1_cau_hoi(ds_cau.TREE, x);
		filein.ignore();
		ds_cau.index++;
	}
	filein.close();
}

void doc_file_ds_sv(ClassList &ds_l)
{
	ifstream filein;
	filein.open("sinhvien.txt", ios_base::in);
	for (int i = 0; i < ds_l.index; i++)
	{
		filein >> ds_l.classList[i]->studentList.index;
		filein.ignore();
		for (int j=0;j< ds_l.classList[i]->studentList.index; j++)
		{
			Student *p = khoi_tao_node_sv();
			getline(filein, p->studentID, ',');
			getline(filein, p->studentLastName, ',');
			getline(filein, p->studentFirstName, ',');
			getline(filein, p->gender, ',');
			getline(filein, p->password);
			chuan_hoa_chu(p->studentID);
			chuan_hoa_chu(p->studentLastName);
			chuan_hoa_chu(p->studentFirstName);
			chuan_hoa_chu(p->gender);
			//chuan_hoa_chu(p->password);
			them_1_sinh_vien(ds_l.classList[i]->studentList.pHead, p);
		}
	}
	filein.close();
}


// =============== GHI FILE =======================

void ghi_file_lop(ClassList &ds_l)
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

void ghi_file_mon(SubjectList &ds_mon)
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

void ghi_file_sv(ClassList &ds_l)
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

void ghi_file_cau(Questionnaire *ds[],int &nds)
{
	ofstream fileout;
	fileout.open("cauhoi.txt", ios_base::out);
	for (int i = 0; i < nds; i++)
	{
		fileout << ds[i]->questionnaireID<< endl;
		fileout << ds[i]->subjectID << endl;
		fileout << ds[i]->content << endl;
		fileout << ds[i]->A << endl;
		fileout << ds[i]->B << endl;
		fileout << ds[i]->C << endl;
		fileout << ds[i]->D << endl;
		fileout << ds[i]->correct;
		if (i != nds)
		{
			fileout << "\n";
		}
	}
	fileout.close();
}

#endif
