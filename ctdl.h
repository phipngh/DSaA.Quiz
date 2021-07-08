#ifndef CTDL_H
#define	CTDL_H

#include "mylib.h"

using namespace std;

const int MAX_SUBJECT_ID_LENGTH = 15;
const int MAX_SUBJECT = 300;
const int MAX_CLASS = 500;

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

//============Score============
struct Score
{
	string subjectID;
	float score;
	bool status;
	Score *pNext;
};

struct ScoreList
{
	Score *pHead = NULL;
	int index = 0;
};

//============Student============
struct Student
{
	string studentID;
	string studentLastName;
	string studentFirstName;
	string gender;
	string password;
	ScoreList scoreList;
	Student *pNext;
};

struct StudentList
{
	Student *pHead = NULL;
	int index = 0;
};

//============Class============
struct Class
{
	string classID;
	string className;
	StudentList studentList;
};

struct ClassList
{
	Class *classList[MAX_CLASS];
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
	Questionnaire *pLeft = NULL;
	Questionnaire *pRight = NULL;
};
typedef struct Questionnaire *tree;

struct QuestionnaireList
{
	tree questionList = NULL;
	int index = 0;
};

#endif
