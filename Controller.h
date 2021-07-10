#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "FileIO.h"

// ------------------------ LOP -------------------------------------------
/*void ClassAdd(ClassList &ds_l);
int ClassIsExist(string a, ClassList ds_l);
void ClassDelete(ClassList &ds_l);
int ClassIsClassHasStudent(ClassList ds_l,string a);
void ClassUpdate(ClassList &ds_l);
void ClassPrintList(ClassList ds_l);
void ClassFree(ClassList &ds_l);
Class *ClassReturnClass(ClassList ds_l, string ma);*/
//---------------------------------- SV ------------------------------------
bool StudentIsIDExist(Student *pHead, string ma);
Class *ClassReturnClass(ClassList ds_l, string ma);
Student* StudentNodeInitialize();
void StudentAdd(Student *&p_head, Student *p);
void StudentFillInfo(ClassList &ds_l,StudentList &ds_sv);
void StudentDelete(ClassList &ds_l);
void StudentFree(StudentList &ds_sv);
void StudentPrintList(StudentList ds_sv, ClassList ds_l);
int StudentIsExist(ClassList ds_l, string ma);

// -----------------------------MON ----------------------------------------------
void SubjectAdd(SubjectList &ds_mon);
void SubjectSort(SubjectList ds_mon);
int SubjectIsExist(string a, SubjectList ds_mon);
int SubjectList_CheckExistID(string a, SubjectList ds_mon);
string SubjectList_ReturnNameOfSubject(SubjectList listToCheck, string subject_ID_ToCheck);
string SubjectList_ReturnExistedID(SubjectList ds_mon);
void SubjectDelete(SubjectList &ds_mon);
void SubjectUpdate(SubjectList &ds_mon);
void SubjectPrintList(SubjectList ds_mon);
void SubjectFree(SubjectList &ds_mon);

//---------------------------- CAU HOI THI ------------------------------
void SubjectFileOutput(SubjectList &ds_mon);
void QuestionnaireTransferTreeToArray(tree t, Questionnaire *arrayListOfQuestion[], int &currentIndex);
void QuestionnairePrintArray(Questionnaire *arrayListOfQuestion[], int numberOfElements);
void QuestionnaireFreeArray(Questionnaire *ds[], int &nds);
void QuestionnaireFillInfo(QuestionnaireList &ds_cau, SubjectList &ds_mon);
void QuestionnaireBalanceTree(Questionnaire *&t, int ID_To_Delete);
void QuestionnaireFree(Questionnaire *nodeToChange);
Questionnaire *QuestionnaireDelete(Questionnaire *nodeToDelete, int question_ID_ToDelete);
void QuestionnaireSwap(Questionnaire *a, Questionnaire *b);
void QuestionnaireUpdate(tree t, int IDQuestionToCheck);
void QuestionnaireExecuteFoundDelete(QuestionnaireList &ds_cau, bool &checkID, bool &keyFlag);
void QuestionnaireExecuteFoundUpdate(QuestionnaireList &ds_cau, bool &checkID, bool &keyFlag);
int QuestionnaireGetTotalQuestions(Questionnaire *listToCheck);
void QuestionnairePrintList(QuestionnaireList questionListToCheck, Questionnaire *ds[], SubjectList subjectListToCheck);
void QuestionnairePrintIDList(QuestionnaireList questionListToCheck, Questionnaire *arrayQuestions[], bool &keyFlag, int &currentTask);
int QuestionnaireTotalOfOneSubject(string a, Questionnaire *ds[], int &nds);
void QuestionnaireArrayShuffer(Questionnaire *ds[], int nds);
bool QuestionnaireIsIDExist(Questionnaire *currentQuestion, int questionnaireID);
int QuestionnaireRandomID(Questionnaire *t);
Questionnaire *QuestionnaireCreateNodeWithoutID();
Questionnaire *QuestionnaireCreateNode(tree treeCheckingExist);
int QuestionnaireGetHeight(tree currentNode);
int QuestionnaireGetBalanceFactor(tree currentNode);
int QuestionnaireReturnMaxNumber(int a, int b);
Questionnaire *QuestionnaireLeftRotation(Questionnaire *&currentNode);
Questionnaire *QuestionnaireRightRotation(Questionnaire *&currentNode);
Questionnaire *QuestionnaireAdd(tree &t, Questionnaire *p);
void QuestionnaireAcceptAnswer(Questionnaire *&p);

// ------------------------ THI ----------------------------
void menu_thi_thu(SubjectList &ds_mon, Questionnaire *ds[], int &nds);
void bo_de(Questionnaire *ds[], int &nds, string a, int n);
void thi(string ma_sv,ClassList ds_l, SubjectList &ds_mon, Questionnaire *ds[], int &nds);
void bo_de_sv(ClassList &ds_l,string ma_sv,Questionnaire *ds[], int &nds, string ma_mh, int n);
// void bo_de_sv(DS_LOP &ds_l, string ma_sv, cau_hoi_thi *ds[], int &nds, string ma_mh, int n, int hour, int minute, int second);
// void thi(string ma_sv, DS_LOP ds_l, DS_MON_HOC &ds_mon, cau_hoi_thi *ds[], int &nds);


//===================lop=====================
string ClassReturnClassID(ClassID class_ID_ToChange){
	string class_ID_Return = "";
	class_ID_Return = "D" + class_ID_ToChange.classYear + "CQ"+
						class_ID_ToChange.major + class_ID_ToChange.numClass + "-"; 
	class_ID_Return.push_back(class_ID_ToChange.northOrSouth);
	return class_ID_Return;
}
//============================ Them lop =========================


string ClassReturnMajorIDMenu(){
	string majorIDReturn = "";
	bool stopFlag = false;
		int selection = 0;
		Normal();
		for (int i = 0; i < MAJOR_NUMBER; i++)
		{
			gotoxy(89, 19 + i);
			cout << MAJOR_ARRAY[i];
		}
		HighLight();
		gotoxy(89, 19 + selection);			//go to the first line after finish print list
		cout << MAJOR_ARRAY[selection];
		char arrowCatch;
		while (stopFlag == false){
			arrowCatch = _getch();
			switch (arrowCatch)
			{
			case UP:
			{
				if (selection > 0)
				{
					Normal();
					gotoxy(89, 19 + selection); // line before
					cout << MAJOR_ARRAY[selection];
					selection--;
					HighLight();			
					gotoxy(89, 19 + selection); // current line
					cout << MAJOR_ARRAY[selection];
				}else{
					Normal();
					gotoxy(89, 19);				//first Line
					cout << MAJOR_ARRAY[selection];
					selection = MAJOR_NUMBER - 1;
					HighLight();
					gotoxy(89, 19 + selection); //last line
					cout << MAJOR_ARRAY[selection];
				}
				break;
			}
			case DOWN:
			{
				if (selection + 1 < MAJOR_NUMBER)
				{
					Normal();
					gotoxy(89, 19 + selection);
					cout << MAJOR_ARRAY[selection];
					selection++;
					HighLight();
					gotoxy(89, 19 + selection);
					cout << MAJOR_ARRAY[selection];
				}else{
					Normal();
					gotoxy(89, 19 + selection);		//last line
					cout << MAJOR_ARRAY[selection];
					selection = 0;
					HighLight();
					gotoxy(89, 19 + selection); 	//first line
					cout << MAJOR_ARRAY[selection];
				}
				break;
			}
			case ENTER:
			{
				 majorIDReturn = MAJOR_ARRAY[selection];
				 stopFlag = true;
				 break;
			}
			}
		}
		return majorIDReturn;
}

bool isCorrectNumClass(int numberToCheck){
	bool isCorrect = false;
	if(numberToCheck > 1 && numberToCheck < 10){
		isCorrect = true;
	} 
	return isCorrect;
}

bool ClassIsCorrectNumberStringTypeInput(string inputNumber){
	bool isValid = true;
	int ASCII_Zero = 48;
	int subtraction = 0;
	for(unsigned int i = 0; i < inputNumber.length(); i++){
		subtraction = inputNumber[i] - ASCII_Zero;
		if(subtraction < 0 || subtraction > 9){
			isValid = false;
			break;
		}
	}
	if(inputNumber.length() != 2) isValid = false;
	return isValid;
}



string ClassReturnClassID_String(ClassID class_ID_ToChange){
	string class_ID_Return = "";
	class_ID_Return = "D" + class_ID_ToChange.classYear + "CQ"+
						class_ID_ToChange.major + class_ID_ToChange.numClass + "-"; 
	class_ID_Return.push_back(class_ID_ToChange.northOrSouth);
	return class_ID_Return;
}

string ClassReturnClassName(ClassID classID_ToCheck){
	string classNameReturn = "";
	string majorCode = classID_ToCheck.major;
	int getIndex = 0;
	for(unsigned int i = 0; i < MAJOR_NUMBER; i++){
		if(majorCode == MAJOR_ARRAY[i]){
			getIndex = i;
			break;
		}
	}
	classNameReturn = MAJOR_ARRAY_NAME[getIndex];
	return classNameReturn;
}
void ClassAdd(ClassList &ds_l, ClassID classID_ToAdd, string className)
{
	Class *p = new Class;
	p->classID = classID_ToAdd;
	p->className = className;

	ds_l.classList[ds_l.index] = p;
	ds_l.index++;
	string class_ID_Print = ClassReturnClassID(p->classID);
	ClearBackground();
	gotoxy(70, 24);
	cout << "ADD COMPLETED CLASS ID: " << class_ID_Print;
}


//====== ktra co trung lop hay chua =========================
int ClassCheckExistID(string classID_ToCheck, ClassList ds_l)
{
	string classID = "";
	for (int i = 0; i < ds_l.index; i++)
	{
		classID = ClassReturnClassID(ds_l.classList[i]->classID);
		if (classID == classID_ToCheck)
		{
			return i;
		}
	}
	return -1;
}

//============= xoa lop =====================================
void ClassPrintMajorList(){
	gotoxy(77, 14);
	cout<<"MAJOR LIST";
	int firstColumnIndex = MAJOR_NUMBER/2;
	int secondColumnIndex = 0;
	for(int i = 0; i < MAJOR_NUMBER; i++){
		if(i <= firstColumnIndex)	gotoxy(50, 18 + 2*i);
		else{
			gotoxy(90, 18 + 2*secondColumnIndex);
			secondColumnIndex++;
		}
		cout<<MAJOR_ARRAY[i] << ":	"<<MAJOR_ARRAY_NAME[i];		 
	}
	
}

void ClassReturnClass_ID_ArrayByMajorID(ClassList classListToCheck, string classID_Array[], int &numberClassID,  string majorID){
	
	for(int i  = 0; i < classListToCheck.index; i++){
		if(classListToCheck.classList[i]->classID.major == majorID){
			gotoxy(40, 10 + i);
			classID_Array[numberClassID] = ClassReturnClassID(classListToCheck.classList[i]->classID);
			numberClassID++;
		}
	} 
}

ClassID ClassCreateStructClassID(){
	ClearBackground();
	ClassID newClassID;
	string classYearInput(2, '\0');
	string numClassInput(2, '\0');
	char northOrSouthGet = '\0';
	do{
		gotoxy(75, 12);
		cout<< "INPUT CLASS ID";
		gotoxy(82,17);
		cout<<"YEAR";
		gotoxy(60,20);
		cout<<"EXAMPLE: D16CQPU01-N";
		gotoxy(80, 18);
		cout<<"D  ";	
		gotoxy(60, 16);
		cout<<"INPUT 2 DIGITS CLASS YEAR";
		gotoxy(82, 18);
		cout <<setw(2);
		getline(cin, classYearInput);
		if(ClassIsCorrectNumberStringTypeInput(classYearInput) == false){
			gotoxy(100, 16);
			cout<< "INVALID TYPO";
			Sleep(1000);
			ClearBackground();
		}
	}while(ClassIsCorrectNumberStringTypeInput(classYearInput) == false);
	ClearInstructionLine();
	
	newClassID.classYear = classYearInput;
	gotoxy(84, 18);
	cout<<" CQ  ";
	gotoxy(60, 16);
	cout<<"CHOOSE MAJOR";
	gotoxy(87,17);
	cout<<"MAJOR";
	newClassID.major = ClassReturnMajorIDMenu();
	ClearInstructionLine();

	do{
		for(int i = 91; i < 98; i++){
			gotoxy(i, 18);
				cout<<" ";
		}
		gotoxy(60, 16);
		cout<<"INPUT CLASS NUMBER";
		gotoxy(93,17);
		cout<<"NUM";
		gotoxy(93, 18);
		getline(cin, numClassInput);
		if(ClassIsCorrectNumberStringTypeInput(numClassInput) == false){
			gotoxy(80, 16);
			cout<< "INVALID TYPO";
			Sleep(1000);
			for(int i = 93; i < 130; i++){
				gotoxy(i, 18);
				cout<<" ";
			}
		}
	}while(ClassIsCorrectNumberStringTypeInput(numClassInput) == false);
	
	newClassID.numClass = numClassInput;
	ClearInstructionLine();
	gotoxy(95, 18);
	cout<<"  -  ";
	gotoxy(60, 16);
	cout<<"INPUT N/B";
	do{
		gotoxy(98,17);
		cout<<"N/B";
		gotoxy(98, 18);
		cout<<" ";
		gotoxy(98, 18);
		cin >> northOrSouthGet;
	}while(northOrSouthGet != 'n' && northOrSouthGet != 'N' && northOrSouthGet != 'B' && northOrSouthGet != 'b');
	if(northOrSouthGet == 'n' || northOrSouthGet == 'b') ToUpper(northOrSouthGet);
	newClassID.northOrSouth = northOrSouthGet;
	return newClassID;
}

bool ClassCheckExistMajorID(string majorID_ToCheck){
	bool isExist = false;
	for(unsigned int i  = 0; i < MAJOR_NUMBER; i++){
		if(majorID_ToCheck == MAJOR_ARRAY[i]){
			isExist = true;
			break;
		}
	}
	return isExist;
}

string ClassReturnMajorID(){
	string major_ID_Return = "";
	do{
			gotoxy(50, 10);
			cout<<"INPUT MAJOR ID: ";
			cin>> major_ID_Return;
			if(major_ID_Return.length() != 2){
				gotoxy(50, 11);
				cout<<"PLEASE INPUT 2 CHARACTERS";
			}
			if(ClassCheckExistMajorID(major_ID_Return) == false){
				gotoxy(80, 9);
				cout<<"MAJOR ID NOT FOUND";
			}
		
	}while(ClassCheckExistMajorID(major_ID_Return) ==  false);
	return major_ID_Return;
}

string ClassReturnMajor_ID_Interface(){
	string major_ID_Return = "";
	ClearBackground();
	ClassPrintMajorList();
	major_ID_Return =  ClassReturnMajorID();
	return major_ID_Return;
}

void ClassReturnClassID_ArrayByMajorID(ClassList classListToCheck, string classID_Array[], int &numberClassID,  string majorID){
	
	for(int i  = 0; i < classListToCheck.index; i++){
		if(classListToCheck.classList[i]->classID.major == majorID){
			gotoxy(40, 10 + i);
			classID_Array[numberClassID] = ClassReturnClassID(classListToCheck.classList[i]->classID);
			numberClassID++;
		}
	} 
}

string ClassReturnClass_ID_ByPrintAllClassesWithMajorID(ClassList classListToCheck, string majorID){
	ClearBackground();
	string class_ID_Return = "";
	int numberClassID = 0;
	string classID_Array[100];
	ClassReturnClassID_ArrayByMajorID(classListToCheck,classID_Array, numberClassID, majorID);
	gotoxy(75, 9);
	cout<< "CLASS LIST";
	if(numberClassID > 0){
			bool stopFlag = false;
		int selection = 0;
		Normal();
		for (int i = 0; i < numberClassID ; i++)
		{
			gotoxy(75, 15 + 2*i);
			cout << classID_Array[i];
		}
		HighLight();
		gotoxy(75, 15 + selection);			//go to the first line after finish print list
		cout << classID_Array[selection];
		char arrowCatch;
		while (stopFlag == false){
			arrowCatch = _getch();
			switch (arrowCatch)
			{
			case UP:
			{
				if (selection > 0)
				{
					Normal();
					gotoxy(75, 15 + 2*selection); // line before
					cout << classID_Array[selection];
					selection--;
					HighLight();			
					gotoxy(75, 15 + 2*selection); // current line
					cout << classID_Array[selection];
				}else{
					Normal();
					gotoxy(75, 15);				//first Line
					cout << classID_Array[selection];
					selection = numberClassID - 1;
					HighLight();
					gotoxy(75, 15 + 2*selection); //last line
					cout << classID_Array[selection];
				}
				break;
			}
			case DOWN:
			{
				if (selection + 1 < numberClassID)
				{
					Normal();
					gotoxy(75, 15 + 2*selection);
					cout << classID_Array[selection];
					selection++;
					HighLight();
					gotoxy(75, 15 + 2*selection);
					cout << classID_Array[selection];
				}else{
					Normal();
					gotoxy(75, 15 + 2*selection);		//last line
					cout << classID_Array[selection];
					selection = 0;
					HighLight();
					gotoxy(75, 15 + 2*selection); 	//first line
					cout << classID_Array[selection];
				}
				break;
			}
			case ENTER:
			{
				 class_ID_Return = classID_Array[selection];
				 stopFlag = true;
				 break;
			}
			}
		}
	}else{
			gotoxy(70, 17);
			cout<< "THERE IS NO \""<< majorID <<"\" ID CLASS ";
		}
	
	return class_ID_Return;
}

ClassID ClassGetClassID_StructFromString(string classID_String){
	ClassID classID_StructReturn;
	classID_StructReturn.classYear = classID_String.substr(1, 2);
	classID_StructReturn.major = classID_String.substr(5, 2);
	classID_StructReturn.numClass = classID_String.substr(7, 2);
	classID_StructReturn.northOrSouth = classID_String[10];
	return classID_StructReturn;
}

int ClassListIsClassHasStudent(ClassList classListToCheck, ClassID classID_ToCheck){
	string classID_StringToCheck = ClassReturnClassID(classID_ToCheck);
	string classID_StringIteration = "";
	for (int i = 0; i < classListToCheck.index; i++)
	{
		classID_StringIteration = ClassReturnClassID(classListToCheck.classList[i]->classID);
		if (classID_StringIteration == classID_StringToCheck)
		{
			if(classListToCheck.classList[i]->studentList.pHead == NULL) return i;
		}
	}
	return -1;
}


//================ hieu chinh lop =====================
void ClassDelete(ClassList &ds_l,ClassID classID_ToDelete)
{
			char confirm = '\0';
/*if (ClassListIsClassHasStudent(ds_l, classID_ToDelete) == -1)
		{
			HighLight();
			gotoxy(60, 10);
			cout << "CLASS HAS STUDENTS, CANNOT DELETE!!";
			return;
		}
		else
		{*/
			string classID_StringToDelete =  ClassReturnClassID(classID_ToDelete);
			
			gotoxy(60, 10);
			cout<<"DO YOU WISH TO DELETE " << classID_StringToDelete <<"	 Y/N";
			gotoxy(110, 10);
			cin>>confirm;
			if(confirm == 'y' || confirm == 'Y'){
				int indexToDelete = ClassCheckExistID(classID_StringToDelete, ds_l);
			for (int i = indexToDelete ; i < ds_l.index - 1; i++)
			{
				ds_l.classList[i]->classID = ds_l.classList[i + 1]->classID;
				ds_l.classList[i]->className = ds_l.classList[i + 1]->className;
			}
			Class *tam = ds_l.classList[ds_l.index - 1];
			delete tam;
			ds_l.index--;
			gotoxy(60, 10);
			cout << "DELETE COMPLETED CLASS ID: "<< classID_StringToDelete;
			}else{
				return;
			}
			
//		}	
}

void ClassUpdate(ClassList &ds_l,string classID_ToUpdate)
{	
	int indexToUpdate = ClassCheckExistID(classID_ToUpdate, ds_l);
		ClassID tempClassID;
		string class_ID_UpdateString = "";
				do{
					tempClassID = ClassCreateStructClassID();
					class_ID_UpdateString= ClassReturnClassID(tempClassID);
					if(ClassCheckExistID(class_ID_UpdateString, ds_l) != -1){
						gotoxy(70, 30);
						cout << "DUPLICATE ID, PLEASE TRY AGAIN!";
						Sleep(1000);
						cin.ignore();
					}
				}while(ClassCheckExistID(class_ID_UpdateString, ds_l) != -1);
				string className = ClassReturnClassName(tempClassID);
				cin.ignore();
				
				ds_l.classList[indexToUpdate]->classID = tempClassID;
				ds_l.classList[indexToUpdate]->className = className;
			gotoxy(60, 10);
			cout << "UPDATE COMPLETED CLASS ID: "<< className ;
}

Class* Class_GetClassFromClassID(ClassID classID_ToFind, ClassList classListToFind){
	Class* classReturn = new Class;
	for( int i = 0; i < classListToFind.index; i++){
		if(classListToFind.classList[i]->classID.classYear == classID_ToFind.classYear &&
		classListToFind.classList[i]->classID.major == classID_ToFind.major &&
		classListToFind.classList[i]->classID.northOrSouth == classID_ToFind.northOrSouth &&
		classListToFind.classList[i]->classID.numClass == classID_ToFind.numClass){
			classReturn = classListToFind.classList[i];
			break;
		}
	}
	return classReturn;
}

//============ in ds lop==================
void ClassPrint(ClassList ds_l)
{
	HighLight();
	gotoxy(51, 10);
	cout << " CLASS LIST ";
	gotoxy(50, 11);
	cout << "=======================================";
	for (int i = 0; i < ds_l.index; i++)
	{
		gotoxy(50, 12 + 3 * i);
		cout << "|";
		gotoxy(88, 12 + 3 * i);
		cout << "|";
		gotoxy(51, 12 + 3 * i);
		cout << " CLASS ID     :   " << ClassReturnClassID(ds_l.classList[i]->classID); gotoxy(50, 13 + 3 * i); cout << "|";
		gotoxy(88, 13 + 3 * i);
		cout << "|";
		gotoxy(51, 13 + 3 * i);
		cout << " CLASS NAME   :   " << ds_l.classList[i]->className;
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

//======================Student======
string StudentReturnStudentID(StudentID studentID_ToReturn){
	string studentID_Return = "";
	studentID_Return = "N" + studentID_ToReturn.classYear + "DC"+
						studentID_ToReturn.studentMajor + studentID_ToReturn.numID;
	return studentID_Return;
}
/*void StudentFillInfo(ClassList &ds_l,StudentList &ds_sv)
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
	StringFormat(a);
	Class *tam = ClassReturnClass(ds_l, a);
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
			ClearBackground();
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
				StudentFillInfo(ds_l, ds_sv);
				break;
			}
			case 2:
			{
				ClearBackground();
				cin.ignore();
				ClassAdd(ds_l);
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
			Student *p = StudentNodeInitialize();
			// =============== them sinh vien vao ds sinh vien ====================
			FrameStudentAdd();
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
			StringFormat(ma_sv);
			while (StudentIsIDExist(ds_sv.pHead, ma_sv) == true)
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
			StringFormat(p->studentLastName);
			StringFormat(p->studentFirstName);
			StringFormat(p->gender);
			//StringFormat(p->password);
			StudentAdd(tam->studentList.pHead, p);
			tam->studentList.index++;
			ds_sv.index++;
			gotoxy(70, 30);
			cout << "                             ";
			gotoxy(70, 30);
			cout << "THEM SINH VIEN THANH CONG!";
			gotoxy(60, 35);
			system("pause");
			StudentFileOutput(ds_l);
			
		}
		}		
}*/

/*int StudentIsExist(ClassList ds_l, string ma)
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
}*/

/*void StudentDelete(ClassList &ds_l) // HAM XOA SV
{
	string ma_sv;
	cout << "NHAP MA SV CAN XOA: ";
	getline(cin, ma_sv);
	if (StudentIsExist(ds_l, ma_sv) < 0)
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

void StudentPrintList(StudentList ds_sv, ClassList ds_l)
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

void StudentFree(StudentList &ds_sv)
{
	for (Student *k = ds_sv.pHead; k != NULL; k = k->pNext)
	{
		delete k;
	}
}

bool StudentIsIDExist(Student *pHead, string ma)
{
	for (Student *k = pHead; k != NULL; k = k->pNext)
	{
		if (k->studentID == ma)
		{
			return true;
		}
	}
	return false;
}*/

//============================ Them mon =========================
void SubjectAdd(SubjectList &ds_mon)
{
	Subject p;
	gotoxy(45, 8);
	cout << "** NOTE: MA MH TOI DA 15 KTU, TEN MH TOI DA 50 KTU";
	FrameSubjectAdd();
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
		StringFormat(p.subjectID);
		gotoxy(68, 24);
		cout << "                                   ";
		if (p.subjectID.length() > 15)
		{
			gotoxy(68, 24);
			cout << "Do dai vuot qua 15 ki tu, nhap lai!";
			
			gotoxy(80, 18);
			cout << "                              ";
		}
		while (SubjectIsExist(p.subjectID, ds_mon) >= 0)
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
		StringFormat(p.subjectName);
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
void SubjectSort(SubjectList ds_mon) // insertionSort();
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
int SubjectIsExist(string a, SubjectList ds_mon)
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

int SubjectList_CheckExistID(string a, SubjectList ds_mon)
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

string SubjectList_ReturnNameOfSubject(SubjectList listToCheck, string subject_ID_ToCheck)
{
	StringFormat(subject_ID_ToCheck);
	for (int i = 0; i <= listToCheck.index; i++)
	{
		if (subject_ID_ToCheck == listToCheck.subjectList[i].subjectID)
		{
			return listToCheck.subjectList[i].subjectName;
		}
	}
	return "";
}

string SubjectList_ReturnExistedID(SubjectList ds_mon)
{
	string subjectID = "";
	FrameQuestionnaire();
	HighLight();
	gotoxy(70, 8);
	cout << "====== NHAP CAU HOI ======";
	gotoxy(50, 10);
	gotoxy(80, 10);
	cout << "MA MH: ";
	getline(cin, subjectID);
	StringFormat(subjectID);
	while (SubjectList_CheckExistID(subjectID, ds_mon) == -1)
	{
		gotoxy(68, 13);
		cout << "                                   ";
		gotoxy(68, 13);
		cout << "MA MON KHONG TON TAI! ";

		gotoxy(87, 10);
		cout << "                              ";
		gotoxy(87, 10);
		getline(cin, subjectID);
		StringFormat(subjectID);
	}
	return subjectID;
}

//========================== Xoa mon hoc ==================
void SubjectDelete(SubjectList &ds_mon)
{
	string a;
	Normal();
	gotoxy(50, 8);
	cout << "NHAP MA MON HOC BAN MUON XOA: ";
	getline(cin, a);
	StringFormat(a);
	//===========ktra mon hoc da ton tai hay chua ================
	int ktra_a = SubjectIsExist(a, ds_mon);
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
		SubjectFileOutput(ds_mon);
		gotoxy(60, 10);
		cout << "XOA THANH CONG!";
	}
}
//========================= Hieu chinh mon hoc ===================
void SubjectUpdate(SubjectList &ds_mon)
{
	string a;
	Normal();
	gotoxy(50, 8);
	cout << "NHAP MA MON BAN CAN HIEU CHINH: ";
	getline(cin, a);
	StringFormat(a);
	int ktra = SubjectIsExist(a, ds_mon);
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
		StringFormat(ds_mon.subjectList[ktra].subjectID);
		StringFormat(ds_mon.subjectList[ktra].subjectName);
		gotoxy(65, 13); HighLight();
		cout << "DA~ THAY DOI THONG TIN MON HOC.";
		SubjectSort(ds_mon);
		SubjectFileOutput(ds_mon);
	}
}
//========================== xuat ds lop =========================
void SubjectPrintList(SubjectList ds_mon)
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
//void SubjectFree(SubjectList &ds_mon)
//{
//	for (int i = 0; i < ds_mon.index; i++)
//	{
//		delete ds_mon.subjectList[i];
//	}
//}

// ================= nhập câu hỏi =====================
void QuestionnaireTransferTreeToArray(tree t, Questionnaire *arrayListOfQuestion[], int &currentIndex)
{
	if (t != NULL)
	{
		arrayListOfQuestion[currentIndex] = new Questionnaire;
		arrayListOfQuestion[currentIndex]->questionnaireID = t->questionnaireID;
		arrayListOfQuestion[currentIndex]->subjectID = t->subjectID;
		arrayListOfQuestion[currentIndex]->height = t->height;
		arrayListOfQuestion[currentIndex]->content = t->content;
		arrayListOfQuestion[currentIndex]->A = t->A;
		arrayListOfQuestion[currentIndex]->B = t->B;
		arrayListOfQuestion[currentIndex]->C = t->C;
		arrayListOfQuestion[currentIndex]->D = t->D;
		arrayListOfQuestion[currentIndex]->correct = t->correct;
		arrayListOfQuestion[currentIndex]->answerCorrect = t->answerCorrect;
		currentIndex++;
		QuestionnaireTransferTreeToArray(t->pLeft, arrayListOfQuestion, currentIndex);
		QuestionnaireTransferTreeToArray(t->pRight, arrayListOfQuestion, currentIndex);
	}
}

void QuestionnairePrintArray(Questionnaire *arrayListOfQuestion[], int numberOfElements)
{
	for (int currentIndex = 0; currentIndex < numberOfElements; currentIndex++)
	{
		cout << "\nID: " << arrayListOfQuestion[currentIndex]->questionnaireID;
		cout << "\n subjectID: " << arrayListOfQuestion[currentIndex]->subjectID;
		cout << "\n height: " << arrayListOfQuestion[currentIndex]->height;
		cout << "\n content: " << arrayListOfQuestion[currentIndex]->content;
		cout << "\n A: " << arrayListOfQuestion[currentIndex]->A;
		cout << "\n B: " << arrayListOfQuestion[currentIndex]->B;
		cout << "\n C: " << arrayListOfQuestion[currentIndex]->C;
		cout << "\n D: " << arrayListOfQuestion[currentIndex]->D;
		cout << "\n correct: " << arrayListOfQuestion[currentIndex]->correct;
		cout << "\n answerCorrect: " << arrayListOfQuestion[currentIndex]->answerCorrect;
		cout << "\n==================================";
	}
}

void QuestionnaireFreeArray(Questionnaire *ds[], int &nds)
{
	for (int i = 0; i < nds; i++)
	{
		delete ds[i];
	}
	nds = 0;
}

void QuestionnaireFillInfo(QuestionnaireList &ds_cau, SubjectList &ds_mon)
{
	Questionnaire *p = QuestionnaireCreateNode(ds_cau.questionList);
	p->subjectID = SubjectList_ReturnExistedID(ds_mon);
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
		StringFormat(p->content);
		StringFormat(p->A);
		StringFormat(p->B);
		StringFormat(p->C);
		StringFormat(p->D);
		do
		{
			gotoxy(85, 27);
			cout << "    ";
			gotoxy(85, 27);
			cin >> p->correct;
			ToUpper(p->correct);
			if (p->correct != 'A' && p->correct != 'B' && p->correct != 'C' && p->correct != 'D')
			{
				gotoxy(65, 30);
				cout << "INCORRECT INPUT!, PLEASE TRY AGAIN!";
			}
			if (p->A == p->B || p->A == p->C || p->A == p->D || p->B == p->C || p->B == p->D || p->C == p->D)
			{
				gotoxy(65, 30);
				cout << "                                           ";
				gotoxy(65, 30);
				cout << "DUPLICATE ANSWER!, PLEASE TRY AGAIN";
			}
		} while (p->correct != 'A' && p->correct != 'B' && p->correct != 'C' && p->correct != 'D');
	} while (p->A == p->B || p->A == p->C || p->A == p->D || p->B == p->C || p->B == p->D || p->C == p->D);

	gotoxy(65, 30);
	cout << "                                           ";
	gotoxy(77, 30);
	cout << "ADD COMPLETED!";
	QuestionnaireAcceptAnswer(p);
	ds_cau.questionList = QuestionnaireAdd(ds_cau.questionList, p);
	cin.ignore();
}

void QuestionnaireBalanceTree(Questionnaire *&t, int ID_To_Delete)
{
	t->height = QuestionnaireReturnMaxNumber(QuestionnaireGetHeight(t->pLeft), QuestionnaireGetHeight(t->pRight)) + 1;
	int balance = QuestionnaireGetBalanceFactor(t);
	if (balance > 1)
	{ // left tree has more node
		if (ID_To_Delete > t->pLeft->questionnaireID)
		{

			t = QuestionnaireLeftRotation(t->pLeft);
		}
		t = QuestionnaireRightRotation(t);
	}
	else if (balance < -1)
	{
		if (ID_To_Delete < t->pRight->questionnaireID)
		{
			t = QuestionnaireRightRotation(t->pRight);
		}
		t = QuestionnaireLeftRotation(t);
	}
}

void QuestionnaireFree(Questionnaire *nodeToChange)
{
	if (nodeToChange == NULL)
		return;
	QuestionnaireFree(nodeToChange->pLeft);
	QuestionnaireFree(nodeToChange->pRight);
	QuestionnaireFree(nodeToChange);
}

// =============== xoa cau hoi =======================
Questionnaire *QuestionnaireDelete(Questionnaire *nodeToDelete, int question_ID_ToDelete)
{
	if (nodeToDelete == NULL)
		return NULL;
	if (question_ID_ToDelete == nodeToDelete->questionnaireID)
	{
		if (nodeToDelete->pLeft == NULL)
		{
			return nodeToDelete->pRight;
		}
		Questionnaire *maxNode = nodeToDelete->pLeft;
		Questionnaire *preNode = maxNode;
		while (maxNode->pRight != NULL)
		{
			preNode = maxNode;
			maxNode = maxNode->pRight;
		}
		maxNode->pRight = nodeToDelete->pRight;
		if (maxNode != nodeToDelete->pLeft)
		{
			preNode->pRight = maxNode->pLeft;
			maxNode->pLeft = nodeToDelete->pLeft;
		}

		return maxNode;
	}
	if (question_ID_ToDelete < nodeToDelete->questionnaireID)
		nodeToDelete->pLeft = QuestionnaireDelete(nodeToDelete->pLeft, question_ID_ToDelete);
	else
		nodeToDelete->pRight = QuestionnaireDelete(nodeToDelete->pRight, question_ID_ToDelete);

	QuestionnaireBalanceTree(nodeToDelete, question_ID_ToDelete);
	return nodeToDelete;
}

void QuestionnaireSwap(Questionnaire *a, Questionnaire *b)
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

//============= hieu chinh cau hoi ==========
void QuestionnaireUpdate(tree t, int IDQuestionToCheck)
{
	if (t != NULL)
	{
		if (t->questionnaireID == IDQuestionToCheck)
		{
			string subjectID;
			FrameQuestionnaire();
			HighLight();
			gotoxy(70, 8);
			cout << "==== FIX QUESTION ====";
			gotoxy(50, 10);
			cout << "ID QUESTION: " << t->questionnaireID;
			do
			{
				gotoxy(47, 13);
				cout << "CONTENT: ";
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
				cout << "ANSWER: ";
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
				StringFormat(t->content);
				StringFormat(t->A);
				StringFormat(t->B);
				StringFormat(t->C);
				StringFormat(t->D);

				do
				{
					gotoxy(85, 27);
					cout << "    ";
					gotoxy(85, 27);
					cin >> t->correct;
					ToUpper(t->correct);
					if (t->correct != 'A' && t->correct != 'B' && t->correct != 'C' && t->correct != 'D')
					{
						gotoxy(65, 30);
						cout << "INCORRECT INPUT!, PLEASE TRY AGAIN!";
					}
					if (t->A == t->B || t->A == t->C || t->A == t->D || t->B == t->C || t->B == t->D || t->C == t->D)
					{
						gotoxy(65, 30);
						cout << "                                           ";
						gotoxy(65, 30);
						cout << "DUPLICATE ANSWER!, PLEASE TRY AGAIN";
					}
				} while (t->correct != 'A' && t->correct != 'B' && t->correct != 'C' && t->correct != 'D');
			} while (t->A == t->B || t->A == t->C || t->A == t->D || t->B == t->C || t->B == t->D || t->C == t->D);
			gotoxy(65, 30);
			cout << "                                           ";
			gotoxy(77, 30);
			cout << "UPDATE COMPLETE!";
			QuestionnaireAcceptAnswer(t);
		}
		else if (t->questionnaireID > IDQuestionToCheck)
		{
			QuestionnaireUpdate(t->pLeft, IDQuestionToCheck);
		}
		else if (t->questionnaireID < IDQuestionToCheck)
		{
			QuestionnaireUpdate(t->pRight, IDQuestionToCheck);
		}
	}
}

void QuestionnaireExecuteFoundDelete(QuestionnaireList &ds_cau, bool &checkID, bool &keyFlag)
{

	int a = -1;
	gotoxy(80, 9);
	cout << "PRESS 0 TO CHECK THE LIST AGAIN";
	gotoxy(50, 9);
	cout << "INPUT ID: ";
	cin >> a;
	if (a == 0)
	{
		keyFlag = 0;
		return;
	}
	else
	{
		bool kt = QuestionnaireIsIDExist(ds_cau.questionList, a);
		if (kt == true)
		{
			char confirm;

			gotoxy(50, 11);
			cout << "                 ";
			cin.ignore();
			gotoxy(50, 11);
			cout << "DO YOU WISH TO DELETE QUESTION ID " << a << " ? Y/N";
			cin >> confirm;
			if (confirm == 'y' || confirm == 'Y')
			{
				ClearBackground();
				ds_cau.questionList = QuestionnaireDelete(ds_cau.questionList, a);
				checkID = true;
			}
			else
			{
				keyFlag = 0;
			}
		}
		else
		{
			gotoxy(50, 11);
			cout << "ID NOT FOUND!";
			Sleep(1000);
			ClearInputID();
		}
	}
}

void QuestionnaireExecuteFoundUpdate(QuestionnaireList &ds_cau, bool &checkID, bool &keyFlag)
{
input:
	int a = -1;
	gotoxy(80, 9);
	cout << "PRESS 0 TO CHECK THE LIST AGAIN";
	gotoxy(50, 9);
	cout << "INPUT ID: ";
	cin >> a;
	if (a == 0)
	{
		keyFlag = 0;
		return;
	}
	else
	{
		bool kt = QuestionnaireIsIDExist(ds_cau.questionList, a);
		if (kt == true)
		{
			checkID = true;
			gotoxy(50, 11);
			cout << "                 ";
			cin.ignore();
			ClearBackground();
			QuestionnaireUpdate(ds_cau.questionList, a);
		}
		else
		{
			gotoxy(50, 11);
			cout << "ID NOT FOUND!";
			Sleep(1000);
			ClearInputID();
			goto input;
		}
	}
}

int QuestionnaireGetTotalQuestions(Questionnaire *listToCheck)
{
	int numberOfQuestions = 1; //current node is one element
	if (listToCheck == NULL)
	{
		return 0;
	}
	else
	{
		numberOfQuestions += QuestionnaireGetTotalQuestions(listToCheck->pLeft);
		numberOfQuestions += QuestionnaireGetTotalQuestions(listToCheck->pRight);
	}
	return numberOfQuestions;
}

void QuestionnairePrintList(QuestionnaireList questionListToCheck, Questionnaire *ds[], SubjectList subjectListToCheck)
{
	bool stopFlag = false;
	int numberOfQuestions = QuestionnaireGetTotalQuestions(questionListToCheck.questionList);
	int numberOfPageShow_3_Questions = numberOfQuestions / 3;
	int totalPages = 0;
	(numberOfQuestions % 3 == 0) ? (totalPages = numberOfPageShow_3_Questions) : (totalPages = numberOfPageShow_3_Questions + 1);
	int currentPage = 1;
	int startMultiply = 0;
	while (stopFlag != true)
	{
		ClearBackground();
		if (questionListToCheck.questionList == NULL)
		{
			gotoxy(80, 20);
			cout << "EMPTY LIST !!!";
			stopFlag = true;
		}
		char key;
		int m = 0;
		for (int indexCurrentQuestion = 3 * startMultiply; indexCurrentQuestion < 3 * startMultiply + 3; indexCurrentQuestion++)
		{
			if (indexCurrentQuestion == numberOfQuestions)
				break;
			gotoxy(105, 35);
			cout << "Page " << currentPage << "/" << totalPages;
			gotoxy(50, 6);
			cout << "PRESS LEFT TO GO BACK, RIGHT TO GO FORWARD";
			gotoxy(50, 7 + 9 * m);
			cout << "======== Number #" << indexCurrentQuestion + 1 << "==========";
			gotoxy(50, 8 + 9 * m);
			cout << "QuestionID: " << ds[indexCurrentQuestion]->questionnaireID;
			gotoxy(50, 9 + 9 * m);
			cout << "Name Of Subject: " << SubjectList_ReturnNameOfSubject(subjectListToCheck, ds[indexCurrentQuestion]->subjectID);
			gotoxy(50, 10 + 9 * m);
			cout << "Question: " << ds[indexCurrentQuestion]->content;
			gotoxy(50, 11 + 9 * m);
			cout << "A Answer: " << ds[indexCurrentQuestion]->A;
			gotoxy(50, 12 + 9 * m);
			cout << "B Answer: " << ds[indexCurrentQuestion]->B;
			gotoxy(50, 13 + 9 * m);
			cout << "C Answer: " << ds[indexCurrentQuestion]->C;
			gotoxy(50, 14 + 9 * m);
			cout << "D Answer: " << ds[indexCurrentQuestion]->D;
			gotoxy(50, 15 + 9 * m);
			cout << "Correct Answer: " << ds[indexCurrentQuestion]->correct << ". " << ds[indexCurrentQuestion]->answerCorrect;
			m++;
		}
		key = _getch();
		if (key == RIGHT)
		{
			if ((3 * startMultiply + 3) > numberOfQuestions)
			{
				startMultiply = 0;
			}
			else
				startMultiply++;
			if (currentPage < totalPages)
				currentPage++;
			else
				currentPage = 1;
			continue; // back to top of while loop
		}
		if (key == LEFT)
		{
			currentPage--;
			if (currentPage == 1 || currentPage == 0)
			{
				startMultiply = 0;
				currentPage = 1;
			}
			else
				startMultiply--;
			continue;
		}
		if (key == 27)
		{
			stopFlag = true;
		}
	}
}
void QuestionnairePrintSubjectIDList(SubjectList ds_mon, bool &keyFlag, int &currentTask)
{
	bool stopFlag = false;
	int numberOfQuestions = ds_mon.index;
	int numberOfPageShow_6_Questions = numberOfQuestions / 6;
	int totalPages = 0;
	(numberOfQuestions % 6 == 0) ? (totalPages = numberOfPageShow_6_Questions) : (totalPages = numberOfPageShow_6_Questions + 1);
	int currentPage = 1;
	int startMultiply = 0;
	ClearBackground();
	if (ds_mon.index > 0)
	{
		gotoxy(73, 14);
		cout << "PRESS UP TO INPUT ID";
	}
	gotoxy(75, 15);
	cout << "LIST OF SUBJECT";
	gotoxy(60, 16);
	cout << "============================================";
	gotoxy(60, 17);
	cout << "| #  |   ID   | SUBJECT NAME               |";
	gotoxy(60, 18);
	cout << "============================================";
	while (stopFlag != true)
	{
		ClearPrintIDList();
		if (ds_mon.index == 0)
		{
			gotoxy(75, 23);
			cout << "EMPTY LIST !!!";
			stopFlag = true;
		}
		char key;
		int i = 0;
		for (int indexCurrentQuestion = 6 * startMultiply; indexCurrentQuestion < 6 * startMultiply + 6; indexCurrentQuestion++)
		{
			if (indexCurrentQuestion == numberOfQuestions)
				break;
			gotoxy(60, 19 + 2 * i);
			cout << "|  " << i + 1;
			gotoxy(66, 19 + 2 * i);
			cout << "| " << ds_mon.subjectList[indexCurrentQuestion].subjectID;
			gotoxy(73, 19 + 2 * i);
			cout << "|  " << ds_mon.subjectList[indexCurrentQuestion].subjectName; // #TODO: catch error when reach more than 40 characters
			gotoxy(103, 19 + 2 * i);
			cout << "|";

			if (i > 5)
				i = 0;
			else
				i++;
			gotoxy(105, 33);
			cout << "Page " << currentPage << "/" << totalPages;
			gotoxy(50, 31);
			cout << "PRESS LEFT TO GO BACK, RIGHT TO GO FORWARD";
		}
		
		key = _getch();
		if (key == RIGHT)
		{
			if ((6 * startMultiply + 6) > numberOfQuestions - 1)
			{
				startMultiply = 0;
			}
			else
				startMultiply++;
			if (currentPage < totalPages)
				currentPage++;
			else
				currentPage = 1;
			continue; // back to top of while loop
		}
		if (key == LEFT)
		{
			currentPage--;
			if (currentPage == 1 || currentPage == 0)
			{
				startMultiply = 0;
				currentPage = 1;
			}
			else
				startMultiply--;
			continue;
		}
		if (key == UP && ds_mon.index > 0)
		{
			stopFlag = true;
			keyFlag = true;
		}
		if (key == ESC)
		{
			stopFlag = true;
			currentTask = 0;
		}
	}
}

void QuestionnairePrintIDList(QuestionnaireList questionListToCheck, Questionnaire *arrayQuestions[], bool &keyFlag, int &currentTask)
{
	bool stopFlag = false;
	int numberOfQuestions = QuestionnaireGetTotalQuestions(questionListToCheck.questionList);
	int numberOfPageShow_6_Questions = numberOfQuestions / 6;
	int totalPages = 0;
	(numberOfQuestions % 6 == 0) ? (totalPages = numberOfPageShow_6_Questions) : (totalPages = numberOfPageShow_6_Questions + 1);
	int currentPage = 1;
	int startMultiply = 0;
	ClearBackground();
	if (questionListToCheck.questionList != NULL)
	{
		gotoxy(73, 12);
		cout << "PRESS UP TO INPUT ID";
	}
	gotoxy(75, 14);
	cout << "LIST OF QUESTIONS";
	gotoxy(50, 16);
	cout << "==================================================================";
	gotoxy(50, 17);
	cout << "| #  |   ID   | SUB ID |             CONTENT                     |";
	gotoxy(50, 18);
	cout << "==================================================================";
	while (stopFlag != true)
	{
		ClearPrintIDList();
		if (questionListToCheck.questionList == NULL)
		{
			gotoxy(75, 23);
			cout << "EMPTY LIST !!!";
			stopFlag = true;
		}
		char key;
		int i = 0;
		for (int indexCurrentQuestion = 6 * startMultiply; indexCurrentQuestion < 6 * startMultiply + 6; indexCurrentQuestion++)
		{
			if (indexCurrentQuestion == numberOfQuestions)
				break;
			gotoxy(50, 19 + 2 * i);
			cout << "|  " << i + 1;
			gotoxy(56, 19 + 2 * i);
			cout << "| " << arrayQuestions[indexCurrentQuestion]->questionnaireID;
			gotoxy(63, 19 + 2 * i);
			cout << "|  " << arrayQuestions[indexCurrentQuestion]->subjectID; // #TODO: catch error when reach more than 40 characters
			gotoxy(72, 19 + 2 * i);
			if (arrayQuestions[indexCurrentQuestion]->content.length() > 35)
				cout << "| " << arrayQuestions[indexCurrentQuestion]->content.substr (0,35)<<"...";
			else
				cout << "|  " << arrayQuestions[indexCurrentQuestion]->content;
			gotoxy(115, 19 + 2 * i);
			cout << "|";
			if (i > 5)
				i = 0;
			else
				i++;
			gotoxy(105, 33);
			cout << "Page " << currentPage << "/" << totalPages;
			gotoxy(50, 31);
			cout << "PRESS LEFT TO GO BACK, RIGHT TO GO FORWARD";
		}
		key = _getch();
		if (key == RIGHT)
		{
			if ((6 * startMultiply + 6) > numberOfQuestions - 1)
			{
				startMultiply = 0;
			}
			else
				startMultiply++;
			if (currentPage < totalPages)
				currentPage++;
			else
				currentPage = 1;
			continue; // back to top of while loop
		}
		if (key == LEFT)
		{
			currentPage--;
			if (currentPage == 1 || currentPage == 0)
			{
				startMultiply = 0;
				currentPage = 1;
			}
			else
				startMultiply--;
			continue;
		}
		if (key == UP && questionListToCheck.questionList != NULL)
		{
			stopFlag = true;
			keyFlag = true;
		}
		if (key == ESC)
		{
			stopFlag = true;
			currentTask = 0;
		}
	}
}

int QuestionnaireTotalOfOneSubject(string a, Questionnaire *ds[], int &nds)
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
void QuestionnaireArrayShuffer(Questionnaire *ds[], int nds)
{
	int min_position;
	int max_position = nds - 1;
	int swap_position;
	int i = 0;
	while (i < nds - 1)
	{
		min_position = i + 1;
		swap_position = rand() % (max_position - min_position + 1) + min_position;
		QuestionnaireSwap(ds[i], ds[swap_position]);
		i++;
	}
}

void QuestionnaireArrayShuffer2 (Questionnaire *ds[], int n)
{
    srand (time(NULL));
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        // swap(&arr[i], &arr[j]);
		QuestionnaireSwap(ds[i], ds[j]);
    }
}

bool QuestionnaireIsIDExist(Questionnaire *currentQuestion, int questionnaireID)
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
			QuestionnaireIsIDExist(currentQuestion->pRight, questionnaireID);
		}
		else
		{
			QuestionnaireIsIDExist(currentQuestion->pLeft, questionnaireID);
		}
	}
}

int QuestionnaireRandomID(Questionnaire *t)
{
	int cauHoiID; // 000->999;
	srand(time(NULL));
	do
	{
		cauHoiID = rand() % (1000 - 1 + 1) + 1;
	} while (QuestionnaireIsIDExist(t, cauHoiID));
	return cauHoiID;
}

Questionnaire *QuestionnaireCreateNode(tree treeCheckingExist)
{
	Questionnaire *p = new Questionnaire;
	p->questionnaireID = QuestionnaireRandomID(treeCheckingExist);
	p->height = 1;
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}

//=================================Thi Thu==============================

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

	if (a.compare("0") == 0)
	{
		return;
	}

	StringFormat(a);
	
	if (SubjectIsExist(a, ds_mon) < 0)
	{
		gotoxy(50, 10);
		cout << "MON HOC KHONG TON TAI!";
		gotoxy(60, 35);
		system("pause");
		goto check_mon;
	}

	int chon;	
	int sl_cau = QuestionnaireTotalOfOneSubject(a, ds, nds);
	bool kt = true;
	//while (kt == true)
	//{
slcauhoi:	
		ClearQuestionInputNumber();
		int so_cau;
		gotoxy(50, 9);
		cout << "NHAP SO LUONG CAU HOI : ";	
		gotoxy(76, 9);
		cin >> so_cau;
		if (so_cau == 0)
		{
			return;
		}

		if (sl_cau < so_cau)
		{
			gotoxy(55, 12);
			cout << "KHONG DU SO LUONG CAU CUA MON " << a << " DE THI, THIEU: " << so_cau-sl_cau;
			gotoxy(60, 35);
			system("pause");
			goto slcauhoi;
		}	
		else
		{
			bo_de(ds, nds, a, so_cau);	
		}
}

void bo_de(Questionnaire *ds[], int &nds, string a, int n)
{
	ClearBackground();
	FrameQuestionnaire();
	cin.ignore();
	Questionnaire *ds_luu[1000];
	char tl[1000];
	int point = 0;
	Questionnaire *monthi[n];
	int demmon = 0;
	for(int i = 0 ; i<nds; i++){
		if(ds[i]->subjectID == a){
			monthi[demmon] = ds[i];
			demmon++;
		}
		if(demmon == n){
				break;
			}
	}
	//QuestionnaireArrayShuffer(ds, nds);
	QuestionnaireArrayShuffer2(monthi, n);
	FrameQuestionnaire();
	HighLight();
	gotoxy(70, 8);
	//create a array of question for the chosen subject
	cout << "====== DE THI ======";
	for (int i = 0; i < n; i++)
	{
//		if (monthi[i]->subjectID == a)
//		{
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
			cout << "Cau hoi: " << monthi[i]->content;
			gotoxy(47, 18);
			cout << "A. " << monthi[i]->A;
			gotoxy(85, 18);
			cout << "B. " << monthi[i]->B;
			gotoxy(47, 22);
			cout << "C. " << monthi[i]->C;
			gotoxy(85, 22);
			cout << "D. " << monthi[i]->D;
		check_tl:
			gotoxy(77, 27);
			cout << "DAP AN: ";
			gotoxy(85, 27);
			cout << "    ";
			gotoxy(85, 27);
			cin >> tl[i];
			ToUpper(tl[i]);
			string cau_tl;
			if (tl[i] == 'A')
			{
				cau_tl = monthi[i]->A;
			}
			else if (tl[i] == 'B')
			{
				cau_tl = monthi[i]->B;
			}
			else if (tl[i] == 'C')
			{
				cau_tl = monthi[i]->C;
			}
			else if (tl[i] == 'D')
			{
				cau_tl = monthi[i]->D;
			}
			else
			{
				gotoxy(65, 30);
				cout << "NHAP DAP AN KHONG HOP LE, YEU CAU NHAP LAI!";
				goto check_tl;
			}
			ds_luu[i] = new Questionnaire;
			ds_luu[i]->questionnaireID = monthi[i]->questionnaireID;
			ds_luu[i]->content = monthi[i]->content;
			ds_luu[i]->A = monthi[i]->A;
			ds_luu[i]->B = monthi[i]->B;
			ds_luu[i]->C = monthi[i]->C;
			ds_luu[i]->D = monthi[i]->D;
			ds_luu[i]->correct = monthi[i]->correct;
			ds_luu[i]->answerCorrect = monthi[i]->answerCorrect;
			if (cau_tl == monthi[i]->answerCorrect)
			{
				point++;
			}
//		}
	}
//	stop = 0;
	ClearBackground();
	
	bool kt = true;
	while (kt == true)
	{
		ClearBackground();
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
			ClearBackground();
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
			kt = false;
			break;	
		}
		case 0:
		{
			cin.ignore();
			kt = false;
			break;
		}
		break;
		}
	//	break;
	}
	
//	delete [] ds_luu;
//	delete [] monthi;
}


void thi(string ma_sv,ClassList ds_l, SubjectList &ds_mon, Questionnaire *ds[], int &nds)
{
	bool kt = true;
	int so_cau;
check_mon:
	string a;
	gotoxy(50, 10);
	cout << "                      ";
	gotoxy(76, 8);
	cout << "                      ";
	gotoxy(50, 8);
	cout << "NHAP MA MON BAN MUON THI: ";
	getline(cin, a);
	StringFormat(a);
	if (SubjectIsExist(a, ds_mon) < 0)
	{
		gotoxy(50, 10);
		cout << "MON HOC KHONG TON TAI!";
		gotoxy(60, 35);
		system("pause");
		goto check_mon;
	}
	gotoxy(55, 17);
	cout << "                                          ";
	gotoxy(57, 15);
	cout << "    ";
	gotoxy(50, 9);
	cout << "NHAP SO LUONG CAU HOI : ";
	gotoxy(76, 9);
	cin >> so_cau;
	int sl_cau = QuestionnaireTotalOfOneSubject(a, ds, nds);
	if (sl_cau < so_cau)
	{
		gotoxy(55, 17);
		cout << "KHONG DU SO LUONG CAU CUA MON " << a << " DE THI, THIEU: " << so_cau - sl_cau;
		gotoxy(60, 35);
		system("pause");
	}
	else
	{
		bo_de_sv(ds_l, ma_sv, ds, nds, a, so_cau);
	}
}

void bo_de_sv(ClassList &ds_l,string ma_sv,Questionnaire *ds[], int &nds, string ma_mh, int n)
{

	ClearBackground();
	FrameQuestionnaire();
	cin.ignore();
	Questionnaire *ds_luu[1000];
	char tl[1000];
	int point = 0;
	Questionnaire *monthi[n];
	int demmon = 0;
	for(int i = 0 ; i<nds; i++){
		if(ds[i]->subjectID == ma_mh){
			monthi[demmon] = ds[i];
			demmon++;
		}
		if(demmon == n){
				break;
			}
	}
	QuestionnaireArrayShuffer(monthi, n);
	FrameQuestionnaire();
	HighLight();		
	gotoxy(70, 8);
	cout << "====== DE THI ======";
	int i = 0;
	for (i = 0; i < n; i++)
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
		cout << "Cau so " << i + 1 << "/" << n;
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
		ToUpper(tl[i]);
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
		ds_luu[i]->questionnaireID = monthi[i]->questionnaireID;
		ds_luu[i]->content = monthi[i]->content;
		ds_luu[i]->A = monthi[i]->A;
		ds_luu[i]->B = monthi[i]->B;
		ds_luu[i]->C = monthi[i]->C;
		ds_luu[i]->D = monthi[i]->D;
		ds_luu[i]->correct = monthi[i]->correct;
		ds_luu[i]->answerCorrect = monthi[i]->answerCorrect;
		if (cau_tl == monthi[i]->answerCorrect)
		{
			point++;
		}
	
	}



	ClearBackground();
	float diem = (float(point) / float(n)) * 10;
	bool kt = true;
	while (kt == true)
	{
		ClearBackground();
		gotoxy(50, 9);
		cout << "SO DIEM BAN DAT DUOC LA: " << diem << "(" << point << "/" << n << ").";
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
			ClearBackground();
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
				gotoxy(54, 11 + i); cout << "| " << ds_luu[i]->questionnaireID;
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
			kt = false;
			break;
		}
		}
	}
}


#endif
