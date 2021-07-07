#ifndef CTDL_H
#define CTDL_H

#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <ctime>
//#include <cstdlib>
#include <windows.h>
//#include <thread>
#include <direct.h>
#include <sstream>
#include "mylib.h"

using namespace std;

const int MAX_SUBJECT_ID_LENGTH = 15;
const int MAX_SUBJECT = 300;
const int MAX_CLASS = 500;

//============Subject============
struct Subject
{
	string subjectID; //key // only 15 characters
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
	string subjectID; //key
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
	string studentID; //key
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
	string classID; //key
	string className;
	StudentList studentList; // struct already has pointer
};

struct ClassList
{
	Class *classList[MAX_CLASS];
	int currentNumberOfClass = 0;
	int a = 5;
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
