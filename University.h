#pragma 
struct STUDENT
{
	char* fio;// ������� 
	char* init; //��������
	int number;		// ����� ������
	int perform[5];		// ������������ 

};
class University
{
	STUDENT data[300];
	int quan = 0;
public:
	void add();
	void Edit();
	void Delete();
	STUDENT* Search();
	void sort();
	void addfail();
	void aversear();
	void output();
	double srscore(int perf[5]);
};

