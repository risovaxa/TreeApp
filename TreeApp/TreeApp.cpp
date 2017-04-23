// TreeApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> // cin, cout;
#include <fstream>  // ifstream, ofstream;
#include <cstring>  // string;
#include <sstream>  // file1 '>>' str; file2 '<<' str;

using namespace std;

struct Tree
{
	string data;					//Информационное поле
	Tree *l, *r;				//Левая и Правая часть дерева
};

Tree *tree = NULL;				//Объявляем переменную, тип которой структура Дерево

								/*ФУНКЦИЯ ЗАПИСИ ЭЛЕМЕНТА В БИНАРНОЕ ДЕРЕВО*/
void push(string a, Tree **t)
{
	if ((*t) == NULL)				//Если дерева не существует
	{
		(*t) = new Tree;			//Выделяем память
		(*t)->data = a;			//Кладем в выделенное место аргумент a
		(*t)->l = (*t)->r = NULL;	//Очищаем память для следующего роста
		return;						//Заложили семечко, выходим
	}
	//Дерево есть
	if (a > (*t)->data)
		push(a, &(*t)->r);		//Если аргумент а больше чем текущий элемент, кладем его вправо
	else
		push(a, &(*t)->l);		//Иначе кладем его влево
}

/*ФУНКЦИЯ ОТОБРАЖЕНИЯ ДЕРЕВА НА ЭКРАНЕ*/
void print(Tree *t, unsigned k = 0)
{
	if (t != NULL)
	{
		print(t->l, k + 3);

		for (unsigned i = 0; i < k; i++)
		{
			cout << "  ";
		}
		cout << t->data << endl;
		print(t->r, k + 3);
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	ifstream p("..\\Data\\tree.txt");

	int i = 0;
	string str;

	while (!p.eof())
	{
		p >> str;				//заносим одно слово из файла в стринг
		cout << str << endl;	//выводим этот стринг
		push(str, &tree);		//заносим наше слово в дерево, при чём оно у нас являеться бинарным
		i++;					//счетчик
	}

	//print(tree);
	cout << i << endl;
	p.close();

	cout << endl;
	system("pause");
	return 0;
}
