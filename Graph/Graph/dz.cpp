//Дан неориентированный граф. 
//Вывести Эйлеров путь или Эйлеров цикл, если он существует.
//Реализовать топологическую сортировку

#include <iostream>
#include <fstream>
#include <list>
#include <map>
#include <vector>
using namespace std;

ifstream in("list.txt");

int main() {
	setlocale(LC_ALL, "RUS");
	int x, y;
	map<int, list<int>> Gr;

	while (in.peek() != EOF) {
		in >> x >> y;
		auto it_x = Gr.find(x);
		bool fl = true;
		if (it_x != Gr.end()) {
			list<int> a = it_x->second;
			for (auto it_y = a.begin(); it_y != a.end(); it_y++)
				if (*it_y == y) {
					fl = false;
					break;
				}
		}
		if (fl) {
			Gr[x].push_back(y);
			if (Gr.find(y) == Gr.end()) {
				Gr[y].push_back(0);
				auto it = Gr.find(y);
				it->second.erase(it->second.begin());
			}
		}
	}

	return 0;
}