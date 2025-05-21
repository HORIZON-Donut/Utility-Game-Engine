#include "Log.h"

void on_pass_test();
void on_fail_test();
void on_inva_test();

int main()
{
	on_pass_test();
	on_fail_test();
	on_inva_test();

	return 0;
}

void on_pass_test()
{
	ReportTest("This test should return as PASS", 0);
}

void on_fail_test()
{
	ReportTest("This test should return as FAIL", 1);
}

void on_inva_test()
{
	ReportTest("This test should return as INVA", 2);
}
