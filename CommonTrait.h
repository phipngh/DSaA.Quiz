#ifndef COMMONTRAIT_H
#define	COMMONTRAIT_H

#include "Struct.h"

void StringFormat(string& a)
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

	for (unsigned int i = 0; i < a.length(); i++)
	{
		if (a[i] >= 97 && a[i] <= 122)
		{
			a[i] -= 32;
		}
	}
}

void ToUpper(char& a)
{
	if (a >= 97 && a <= 122)
	{
		a -= 32;
	}
}

/*======================== For File W/R Only =========================*/

/*=== Student ===*/


void StudentAdd(Student*& pHead, Student* p)
{
	if (pHead == NULL)
	{
		pHead = p;
	}
	else
	{
		for (Student* k = pHead; k != NULL; k = k->pNext)
		{
			if (k->pNext == NULL)
			{
				k->pNext = p;
				break;
			}
		}
	}
}

/*=== Questionaire ===*/
Questionnaire* QuestionnaireCreateNodeWithoutID()
{
	Questionnaire* questionnaireReturn = new Questionnaire;
	questionnaireReturn->height = 1;
	questionnaireReturn->pLeft = NULL;
	questionnaireReturn->pRight = NULL;
	return questionnaireReturn;
}

void QuestionnaireAcceptAnswer(Questionnaire*& p)
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

int QuestionnaireGetHeight(tree currentNode)
{
	if (currentNode == NULL)
		return 0;
	return currentNode->height;
}

int QuestionnaireReturnMaxNumber(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	return b;
}

int QuestionnaireGetBalanceFactor(tree currentNode)
{
	if (currentNode == NULL)
		return 0;
	return QuestionnaireGetHeight(currentNode->pLeft) - QuestionnaireGetHeight(currentNode->pRight);
}

Questionnaire* QuestionnaireLeftRotation(Questionnaire*& currentNode)
{
	if (currentNode == NULL)
		return NULL;
	Questionnaire* nodeToRotate = currentNode->pRight;
	currentNode->pRight = nodeToRotate->pLeft;
	nodeToRotate->pLeft = currentNode;
	currentNode->height = QuestionnaireReturnMaxNumber(QuestionnaireGetHeight(currentNode->pLeft), QuestionnaireGetHeight(currentNode->pRight)) + 1;
	nodeToRotate->height = QuestionnaireReturnMaxNumber(QuestionnaireGetHeight(nodeToRotate->pLeft), QuestionnaireGetHeight(nodeToRotate->pRight)) + 1;
	return nodeToRotate;
}

Questionnaire* QuestionnaireRightRotation(Questionnaire*& currentNode)
{
	if (currentNode == NULL)
		return NULL;
	Questionnaire* nodeToRotate = currentNode->pLeft;
	currentNode->pLeft = nodeToRotate->pRight;
	nodeToRotate->pRight = currentNode;

	currentNode->height = QuestionnaireReturnMaxNumber(QuestionnaireGetHeight(currentNode->pLeft), QuestionnaireGetHeight(currentNode->pRight)) + 1;
	nodeToRotate->height = QuestionnaireReturnMaxNumber(QuestionnaireGetHeight(nodeToRotate->pLeft), QuestionnaireGetHeight(nodeToRotate->pRight)) + 1;
	return nodeToRotate;
}

Questionnaire* QuestionnaireAdd(tree& t, Questionnaire* p)
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
				t->pRight = QuestionnaireAdd(t->pRight, p);
			}
			else if (p->questionnaireID < t->questionnaireID)
			{
				t->pLeft = QuestionnaireAdd(t->pLeft, p);
			}
			t->height = QuestionnaireReturnMaxNumber(QuestionnaireGetHeight(t->pLeft), QuestionnaireGetHeight(t->pRight)) + 1;
			int balance = QuestionnaireGetBalanceFactor(t);
			if (balance > 1)
			{ // left tree has more node
				if (p->questionnaireID > t->pLeft->questionnaireID)
				{
					t->pLeft = QuestionnaireLeftRotation(t->pLeft);
				}
				return QuestionnaireRightRotation(t);
			}
			else if (balance < -1)
			{
				if (p->questionnaireID < t->pRight->questionnaireID)
				{
					t->pRight = QuestionnaireRightRotation(t->pRight);
				}
				return QuestionnaireLeftRotation(t);
			}
		}
	}
	return t;
}

#endif
