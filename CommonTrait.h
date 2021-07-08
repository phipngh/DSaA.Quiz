#ifndef COMMONTRAIT_H
#define	COMMONTRAIT_H

#include "Struct.h"

void chuan_hoa_chu(string &a)
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

	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == ' '&& a[i + 1] == ' ')
		{
			a.erase(a.begin() + i + 1);
			i--;
		}
	}

	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] >= 97 && a[i] <= 122)
		{
			a[i] -= 32;
		}
	}
}

void up_case_char(char &a)
{
	if (a >= 97 && a <= 122)
	{
		a -= 32;
	}
}

Student* khoi_tao_node_sv()
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

Questionnaire *Questionnaire_CreateNodeWithoutID()
{
	Questionnaire *questionnaireReturn = new Questionnaire;
	questionnaireReturn->height = 1;
	questionnaireReturn->pLeft = NULL;
	questionnaireReturn->pRight = NULL;
	return questionnaireReturn;
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

int Questionnaire_GetHeight(tree currentNode)
{
	if (currentNode == NULL)
		return 0;
	return currentNode->height;
}

int returnMaxNumber(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	return b;
}

int Questionnaire_GetBalanceFactor(tree currentNode)
{
	if (currentNode == NULL)
		return 0;
	return Questionnaire_GetHeight(currentNode->pLeft) - Questionnaire_GetHeight(currentNode->pRight);
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



#endif
