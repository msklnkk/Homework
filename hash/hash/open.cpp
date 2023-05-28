//В файле содержатся данные о сотрудниках предприятия : 
//фамилия, должность, дата рождения(день, месяц, год), стаж работы, зарплата. 
//Выполнить открытое хэширование.Продемонстрировать поиск элемента и удаление элемента.
//Выбран метод деления по стажу работы

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <Windows.h>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

struct date {	//дата
	int dd, mm, yy;
};

struct people {	//данные о человеке
	string Surname;	//фамилия
	string Post;	//должность
	date DateOfBirth;	//дата рождения
	int WorkExp;	//стаж работы
	int Salary;	//зарплата
};

date Str_to_Date(string str) {	//из строки в дату
	date x;
	string temp = str.substr(0, 2);	//день
	x.dd = atoi(temp.c_str());
	temp = str.substr(3, 2);	//месяц
	x.mm = atoi(temp.c_str());
	temp = str.substr(6, 4);	//год
	x.yy = atoi(temp.c_str());
	return x;
}

vector <people> inFile() {	//ввод из файла
	vector <people> x;
	people temp;
	while (in.peek() != EOF) {
		in >> temp.Surname;	//фамилия
		in >> temp.Post;	//должность
		string tmp;	//дата рождения
		in >> tmp;
		temp.DateOfBirth = Str_to_Date(tmp);
		in >> temp.WorkExp;	//стаж работы
		in >> temp.Salary;	//зарплата
		x.push_back(temp);
	}
	return x;
}