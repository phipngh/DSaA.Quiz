#ifndef STRUCT_H
#define	STRUCT_H

#include "mylib.h"

using namespace std;

const int MAX_SUBJECT_ID_LENGTH = 15;
const int MAX_SUBJECT = 300;
const int MAX_CLASS = 500;
const int MAJOR_NUMBER = 11;
const int STUDENT_MAJOR_NUMBER = 9;
const string MAJOR_ARRAY[MAJOR_NUMBER] = { "AT", "MT", "CN", "DT", "PU",
								"TK", "KD", "KT", "QT", "VT",
								"MR" };
const string MAJOR_ARRAY_NAME[MAJOR_NUMBER] = { "AN TOAN THONG TIN", "MANG MAY TINH", "CONG NGHE THONG TIN",
												"DIEN DIEN TU", "PHAT TRIEN UNG DUNG", "THIET KE",
												"QUAN TRI KINH DOANH", "KE TOAN", "QUAN TRI",
												"VIEN THONG", "MARKETING" };
const int MAX_LENGTH_CLASS_ID = 11;
const string STUDENT_MAJOR[STUDENT_MAJOR_NUMBER] = { "AT", "CN", "DT","PT", "DT",
													"KT", "QT", "VT", "MR" };
const string DEFAULT_PASSWORD = "123456";

//============Subject============
struct Subject
{
	string subjectID;
	string subjectName;
};

struct SubjectList
{
	Subject subjectList[MAX_SUBJECT];
	int index = 0;
};

//============Score=============
struct Score
{
	string subjectID;
	float score;
	bool status;
	Score* pNext;
};

struct ScoreList
{
	Score* pHead = NULL;
	int index = 0;
};

//============Student============
struct StudentID {
	string classYear;
	string studentMajor;
	string numID;
};

struct Student
{
	StudentID studentID;
	string studentLastName;
	string studentFirstName;
	string gender;
	string password;
	ScoreList scoreList;
	Student* pNext = NULL;
};

struct StudentList
{
	Student* pHead = NULL;
	int index = 0;
};

//============Class============
struct ClassID {
	string classYear;
	string major;
	string numClass;
	char northOrSouth = '\0';
};

struct Class
{
	ClassID classID;
	string className;
	StudentList studentList;
};

struct ClassList
{
	Class* classList[MAX_CLASS];
	int index = 0;
};

//============Questionnaire============
struct Questionnaire
{
	int questionnaireID;
	string subjectID;
	string content;
	int height = 1;
	string A;
	string B;
	string C;
	string D;
	char correct;
	string answerCorrect;
	Questionnaire* pLeft = NULL;
	Questionnaire* pRight = NULL;
};
typedef struct Questionnaire* tree;

struct QuestionnaireList
{
	tree questionList = NULL;
	int index = 0;
};

#endif
