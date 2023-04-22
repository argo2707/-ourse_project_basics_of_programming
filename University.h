#pragma 
struct STUDENT
{
	char* fio;// фамили€ 
	char* init; //инициалы
	int number;		// номер группы
	int perform[5];		// успеваемость 

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

