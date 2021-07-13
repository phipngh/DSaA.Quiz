#ifndef FILEIO_H
#define FILEIO_H
#include "Controller.h"
#include "Graphic.h"
//===================== doc file danh sach lop =======================
void ClassAssignStructClass_ID_FromString(string class_ID_Get, ClassID &class_ID_ToAssign){
	string getClassYear = class_ID_Get.substr(1, 2);
	string getMajor = class_ID_Get.substr(5, 2);
	string getNumClass = class_ID_Get.substr(7,2);
	char getNorthOrSouth = class_ID_Get[10];
	class_ID_ToAssign.classYear = getClassYear;
	class_ID_ToAssign.major = getMajor;
	class_ID_ToAssign.numClass = getNumClass;
	class_ID_ToAssign.northOrSouth = getNorthOrSouth;
}

void ClassFileInput(ClassList &ds_l)
{
ifstream filein("lop.txt", ios_base::in);
	//	filein.open("lop.txt",ios_base::in);
	string line = "";
	while (getline(filein, line))
	{
		ds_l.classList[ds_l.index] = new Class;
		string foundtext = line.substr(0, line.find(','));
		ClassAssignStructClass_ID_FromString(foundtext, ds_l.classList[ds_l.index]->classID);
		string foundtext2 = line.substr(line.find(",") + 1);
		ds_l.classList[ds_l.index]->className = foundtext2;
		ds_l.index++;
	}
	filein.close();
}

//===================== doc file danh sach mon =======================
void SubjectFileInput(SubjectList& ds_mon)
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
StudentID StudentAssignStructClass_ID_FromString(string student_ID_Get){
	StudentID studentIDReturn;
	string getClassYear = student_ID_Get.substr(1, 2);
	string getMajor = student_ID_Get.substr(5, 2);
	string getNumClass = student_ID_Get.substr(7,3);
	studentIDReturn.classYear = getClassYear;
	studentIDReturn.studentMajor = getMajor;
	studentIDReturn.numID = getNumClass;
	return studentIDReturn;
}

Student* StudentNodeInitTemp()
{
	Student* p = new Student;
	if (p == NULL)
	{
		cout << "NOT ENOUGH STORAGE";
		return NULL;
	}
	p->pNext = NULL;
	return p;
}

ClassID ClassGetClassID_StructFromStringTemp(string classID_String){
	ClassID classID_StructReturn;

	classID_StructReturn.classYear = classID_String.substr(1, 2);
	classID_StructReturn.major = classID_String.substr(5, 2);
	classID_StructReturn.numClass = classID_String.substr(7, 2);
	classID_StructReturn.northOrSouth = classID_String[10];
	return classID_StructReturn;
}

int ClassReturnClassIndexTemp(ClassList classListToCheck, ClassID classToCheck) {
	for (int i = 0; i < classListToCheck.index; i++) {
		if (classListToCheck.classList[i]->classID.classYear == classToCheck.classYear &&
			classListToCheck.classList[i]->classID.major == classToCheck.major && 
			classListToCheck.classList[i]->classID.northOrSouth == classToCheck.northOrSouth &&
			classListToCheck.classList[i]->classID.numClass == classToCheck.numClass) {
			return i;
		}
	}
	return -1;
}

string StudentReturnStudentID_Temp(StudentID studentID_ToReturn) {
	string studentID_Return = "";
	studentID_Return = "N" + studentID_ToReturn.classYear + "DC" +
		studentID_ToReturn.studentMajor + studentID_ToReturn.numID;
	return studentID_Return;

}

bool StudentIsFirstNodeID_LargerThanSecondNodeID_Temp(string firstNodeID, string secondNodeID) {
	if (firstNodeID > secondNodeID) return true;
	return false;
}


void StudentAddNodeToListTemp(Student*& pHead, Student* p)
{
	string traverseNodeID = "";
	string currentNodeID = "";
	if (pHead == NULL) {
		pHead = p;
		return;
	}
	Student* preNode = NULL;
	Student* traverseNode = pHead;
	currentNodeID = StudentReturnStudentID_Temp(p->studentID);
	while (traverseNode != NULL) {
		traverseNodeID = StudentReturnStudentID_Temp(traverseNode->studentID);
	//cout << currentNodeID;
	//cout << traverseNodeID;
	//system("pause");
		if (StudentIsFirstNodeID_LargerThanSecondNodeID_Temp(traverseNodeID, currentNodeID)) {
			if (preNode == NULL) {
				p->pNext = pHead;
				pHead = p;
			}
			else {
				p->pNext = traverseNode;
				preNode->pNext = p;
			}
			return;
		}
		preNode = traverseNode;
		traverseNode = traverseNode->pNext;
	}
	preNode->pNext = p;
}

void StudentFileInput(ClassList &ds_l)
{
ifstream filein;
int currentStatus = 1;
int currentData = 1;
int numberOfStudent = 1;
int index = 0;

int numberOfStudentLine = 0; Student* p = StudentNodeInitTemp();
	filein.open("sinhvien.txt", ios_base::in);
	string currentLine = "";
	while (getline(filein, currentLine)) {
		if (currentStatus == 1) {
			ClassID classIDReceive = ClassGetClassID_StructFromStringTemp(currentLine);
			index = ClassReturnClassIndexTemp(ds_l, classIDReceive);
			currentStatus++;
			continue;
		}if (currentStatus == 2) {
			ds_l.classList[index]->studentList.index = stoi(currentLine);
			numberOfStudentLine = stoi(currentLine);
			currentStatus++;
			continue;
		}if (currentStatus == 3) {
			 string tempStudentID = "";
			 Student* p = new Student;
			 stringstream stringInput(currentLine);
			 while (getline(stringInput, tempStudentID, ',')) {
				 if (currentData == 1) {
					 p->studentID = StudentAssignStructClass_ID_FromString(tempStudentID);
					 currentData++;
					 continue;
				 }if (currentData == 2) {
					 p->studentLastName = tempStudentID;
					 currentData++;
						continue;
					}if (currentData == 3) {
						p->studentFirstName = tempStudentID;
											currentData++;
						continue;
					}if (currentData == 4) {
						p->gender = tempStudentID;
											currentData++;
						continue;
					}if (currentData == 5) {
						p->password = tempStudentID;
						StudentAddNodeToListTemp(ds_l.classList[index]->studentList.pHead, p);
						numberOfStudent++;
						currentData = 1;
						if (numberOfStudent > numberOfStudentLine) {
						currentStatus = 1;
						}
					}
				}
		}
		continue;
	}
	filein.close();
}
//===================== doc file danh sach cau hoi =======================
void QuestionnaireFileInput(QuestionnaireList& ds_cau)
{
	ifstream filein;
	filein.open("questionnaireTest.txt", ios_base::in);
	stringstream ss;
	string currentLine = "";
	while (filein.eof() != true)
	{
		Questionnaire* x = QuestionnaireCreateNodeWithoutID();
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
string ClassReturnClassIDTemp(ClassID class_ID_ToChange){
	string class_ID_Return = "";
	class_ID_Return = "D" + class_ID_ToChange.classYear + "CQ"+
						class_ID_ToChange.major + class_ID_ToChange.numClass + "-"; 
	class_ID_Return.push_back(class_ID_ToChange.northOrSouth);
	return class_ID_Return;
}

void ClassFileOutput(ClassList &ds_l)
{
ofstream fileout;
	fileout.open("lop.txt", ios_base::trunc);
	for (int i = 0; i < ds_l.index; i++)
	{
		fileout << ClassReturnClassIDTemp(ds_l.classList[i]->classID) << ",";
		fileout << ds_l.classList[i]->className;
		if (i != ds_l.index - 1)
		{
			fileout << "\n";
		}
	}
	fileout.close();
}
//===================== doc file danh sach mon =======================
void SubjectFileOutput(SubjectList& ds_mon)
{
	ofstream fileout;
	fileout.open("mon.txt", ios_base::trunc);
	for (int i = 0; i < ds_mon.index; i++)
	{
		fileout << ds_mon.subjectList[i].subjectID << ",";
		fileout << ds_mon.subjectList[i].subjectName;
		if (i != ds_mon.index - 1)
		{
			fileout << "\n";
		}
	}
	fileout.close();
}

//===================== doc file danh sach sv =======================



void StudentFileOutput(ClassList& ds_l)
{
	ofstream fileout;
	fileout.open("sinhvien.txt", ios_base::out);
	for (int i = 0; i < ds_l.index; i++)
	{
		fileout << ClassReturnClassIDTemp(ds_l.classList[i]->classID) ;
		fileout << "\n";
		fileout << ds_l.classList[i]->studentList.index;
		fileout << "\n";
		for (Student* k = ds_l.classList[i]->studentList.pHead; k != NULL; k = k->pNext)
		{
			fileout << StudentReturnStudentID_Temp(k->studentID) << ",";
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
void QuestionnaireWriteCurrentQuestion(Questionnaire* questionListToText, ofstream& fileout)
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

void QuestionnaireFileOutput(Questionnaire*& questionListToText, ofstream& fileout)
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
