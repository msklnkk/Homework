//� ����� ���������� ������ � ����������� ����������� : 
//�������, ���������, ���� ��������(����, �����, ���), ���� ������, ��������. 
//��������� �������� �����������.������������������ ����� �������� � �������� ��������.
//������ ����� ������� �� ����� ������

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <Windows.h>
using namespace std;

ifstream in("input.txt");

struct date {	//����
	int dd, mm, yy;
};

struct people {	//������ � ��������
	string Surname;	//�������
	string Post;	//���������
	date DateOfBirth;	//���� ��������
	int WorkExp;	//���� ������
	int Salary;	//��������
};

date Str_to_Date(string str) {	//�� ������ � ����
	date x;
	string temp = str.substr(0, 2);	//����
	x.dd = atoi(temp.c_str());
	temp = str.substr(3, 2);	//�����
	x.mm = atoi(temp.c_str());
	temp = str.substr(6, 4);	//���
	x.yy = atoi(temp.c_str());
	return x;
}

vector <people> inFile() {	//���� �� �����
	vector <people> x;
	people temp;
	while (in.peek() != EOF) {
		in >> temp.Surname;	//�������
		in >> temp.Post;	//���������
		string tmp;	//���� ��������
		in >> tmp;
		temp.DateOfBirth = Str_to_Date(tmp);
		in >> temp.WorkExp;	//���� ������
		in >> temp.Salary;	//��������
		x.push_back(temp);
	}
	return x;
}

bool operator == (date a, date b) {	//��������������� ��������� == ��� �������� �� ��������� ���
	if (a.dd == b.dd && a.mm == b.mm && a.yy == b.yy)
		return true;
	return false;
}
bool operator == (people a, people b) {	//��������������� ��������� == ��� �������� �� ��������� �����������
	if ((a.DateOfBirth == b.DateOfBirth) && (a.WorkExp == b.WorkExp) && (a.Salary = b.Salary) && (a.Surname == b.Surname) && (a.Post == b.Post))
		return true;
	return false;
}

void print(people x) {	//����� �� �����
	cout << setw(15) << left << x.Surname;	//�� ������ ����, 25 ������� ��� �������
	cout << setw(15) << left << x.Post;	//���������
	if (x.DateOfBirth.dd < 10) cout << left << '0' << x.DateOfBirth.dd << '.';	//��������� 0 � �����
	else cout << left << x.DateOfBirth.dd << '.';
	if (x.DateOfBirth.mm < 10) cout << '0' << x.DateOfBirth.mm << '.';
	else cout << x.DateOfBirth.mm << '.';
	cout << left << setw(6) << x.DateOfBirth.yy;	//�� ��� 6 �������
	cout << left << setw(1) << x.WorkExp << endl;	//���� ������
	cout << left << setw(10) << x.Salary << endl;	//��������
}

people GetInfo(string x) {	//������� ��������� ���������� � ���������� �� ������
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