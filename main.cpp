#include "do_hoa.h"

int main()
{

	StudentList ds_sv;
	QuestionnaireList ds_cau;
	SubjectList ds_mon;
	ClassList ds_l;
	//Questionnaire *ds[1000];
	//int nds = 0;

	doc_file_ds_lop(ds_l);				// work well
	doc_file_ds_mon(ds_mon);			//work well
	doc_file_ds_sv(ds_l);				//work well
	QuestionnaireList_ReadFile(ds_cau); // work well
	menu_tong(ds_l, ds_sv, ds_cau, ds_mon);
	return 0;
}
