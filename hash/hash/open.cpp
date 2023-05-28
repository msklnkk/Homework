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

bool operator == (date a, date b) {	//переобозначение оператора == для проверки на равенство дат
	if (a.dd == b.dd && a.mm == b.mm && a.yy == b.yy)
		return true;
	return false;
}
bool operator == (people a, people b) {	//переобозначение оператора == для проверки на равенство сотрудников
	if ((a.DateOfBirth == b.DateOfBirth) && (a.WorkExp == b.WorkExp) && (a.Salary = b.Salary) && (a.Surname == b.Surname) && (a.Post == b.Post))
		return true;
	return false;
}

void print(people x) {	//вывод из файла
	cout << setw(15) << left << x.Surname;	//по левому краю, 25 позиций для фамилии
	cout << setw(15) << left << x.Post;	//должность
	if (x.DateOfBirth.dd < 10) cout << left << '0' << x.DateOfBirth.dd << '.';	//добавляем 0 и точки
	else cout << left << x.DateOfBirth.dd << '.';
	if (x.DateOfBirth.mm < 10) cout << '0' << x.DateOfBirth.mm << '.';
	else cout << x.DateOfBirth.mm << '.';
	cout << left << setw(6) << x.DateOfBirth.yy;	//на год 6 позиций
	cout << left << setw(1) << x.WorkExp << endl;	//стаж работы
	cout << left << setw(10) << x.Salary << endl;	//зарплата
}

people GetInfo(string x) {	//функция получения информации о сотруднике из строки
	people person;
	int c;
	c = 0;
	while (x.size() > 0) {
		string t = x.substr(0, x.find_first_of(' '));
		x.erase(0, x.find_first_of(' ') + 1);
		if (c == 0) person.Surname = t;
		if (c == 1) person.Post = t;
		if (c == 2) person.DateOfBirth = Str_to_Date(t);
		if (c == 3) person.WorkExp = stoi(t);
		if (c == 4) {
			person.Salary = stoi(t);
			break;
		}
		c++;
	}
	return person;
}