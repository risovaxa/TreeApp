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
	string data;					//�������������� ����
	Tree *l, *r;				//����� � ������ ����� ������
};

Tree *tree = NULL;				//��������� ����������, ��� ������� ��������� ������

								/*������� ������ �������� � �������� ������*/
void push(string a, Tree **t)
{
	if ((*t) == NULL)				//���� ������ �� ����������
	{
		(*t) = new Tree;			//�������� ������
		(*t)->data = a;			//������ � ���������� ����� �������� a
		(*t)->l = (*t)->r = NULL;	//������� ������ ��� ���������� �����
		return;						//�������� �������, �������
	}
	//������ ����
	if (a > (*t)->data)
		push(a, &(*t)->r);		//���� �������� � ������ ��� ������� �������, ������ ��� ������
	else
		push(a, &(*t)->l);		//����� ������ ��� �����
}

/*������� ����������� ������ �� ������*/
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
		p >> str;				//������� ���� ����� �� ����� � ������
		cout << str << endl;	//������� ���� ������
		push(str, &tree);		//������� ���� ����� � ������, ��� ��� ��� � ��� ��������� ��������
		i++;					//�������
	}

	//print(tree);
	cout << i << endl;
	p.close();

	cout << endl;
	system("pause");
	return 0;
}
