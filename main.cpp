#include "UserInterface.h"

int main()
{

	StudentList ds_sv;
	QuestionnaireList ds_cau;
	SubjectList ds_mon;
	ClassList ds_l;
	//Questionnaire *ds[1000];
	//int nds = 0;

	ClassFileInput(ds_l);				// work well
	SubjectFileInput(ds_mon);			//work well
	StudentFileInput(ds_l);				//work well
	QuestionnaireFileInput(ds_cau); // work well
	menu_tong(ds_l, ds_sv, ds_cau, ds_mon);
	return 0;
}
