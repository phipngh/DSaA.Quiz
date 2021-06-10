#include "do_hoa.h"

int main() {
	
 	StudentList ds_sv;
 	QuestionnaireList ds_cau;
 	SubjectList ds_mon;
 	ClassList ds_l;
 	Questionnaire *ds[1000];
 	int nds = 0;
 	
// 	doc_file_ds_cau(ds_cau);
//	doc_file_ds_lop(ds_l);
//	doc_file_ds_mon(ds_mon);
//	doc_file_ds_sv(ds_l);
	menu_tong(ds_l, ds_sv, ds_cau, ds_mon);	

	return 0;
}