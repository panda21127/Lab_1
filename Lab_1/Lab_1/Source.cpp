#include <iostream>
#include <windows.h>
#include <string.h>
#include<algorithm>
#include <fstream>
#include <string>
using namespace std;
int onlyNumbers()
{
	int flag = 1;
	while (flag == 1)
	{
		int number;
		cin >> number;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(cin.rdbuf() -> in_avail());
			cout << "-_-" << endl << "Enter a number" << endl;
		}
		else
		{
			return number;
		}
	}

}
double doubleNumbers()
{
	int flag = 1;
	while (flag == 1)
	{
		double number;
		cin >> number;
		cout << endl;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "-_-" << endl << "Enter a number" << endl;
		}
		else
		{
			return number;
		}
	}

}
struct worker
{
	string fam;
	string name;
	int department;
	double salary;
};
int add(string path,worker* workers, int count, int count_1[])
{
	path = "myFile.txt";
	ofstream fout;
	ifstream fin;
	fin.open(path);

	if (!fin.is_open())
	{
		cout << "File opening error" << endl;
	}
	else
	{
		fout.open(path, ofstream::app);
		string str;
		while (!fin.eof())
		{
			str = "";
			getline(fin, str);
			count_1[1]++;
		}
		count_1[0] = +count_1[1] - 1;
		cout << "How many passengers" << '\n';
		count = onlyNumbers();
		while (count <= 0)
		{
			cout << " -_- " << endl;
			cout << "Enter a number from the list " << endl;
			count = onlyNumbers();
			while (((count <= 0) && (count >= 0)))
			{
				if (((count <= 0) && (count >= 0)))
				{
					count = 0;
					cout << "Prover";
					count = onlyNumbers();
				}
			}
		}
		count += count_1[0];
		for (int i = count_1[0]; i < count; i++)
		{
			cout << "Enter the data" << endl << endl;
			cout << "Worker's last name: ";
			string fam;
			cin >> workers[i].fam;
			cout << "Worker's name: ";
			string name;
			cin >> workers[i].name;
			cout << "Department: ";                         workers[i].department = onlyNumbers();
			while (workers[i].department <= 0)
			{
				cout << " -_- " << endl;
				cout << "Enter a number from the list " << endl;
				workers[i].department = onlyNumbers();
				while (((workers[i].department <= 0) && (workers[i].department >= 0)))
				{
					if (((workers[i].department <= 0) && (workers[i].department >= 0)))
					{
						workers[i].department = 0;
						cout << "Prover";
						workers[i].department = onlyNumbers();
					}
				}
			}
			cout << "Salary: ";                   workers[i].salary = doubleNumbers();
			while (workers[i].salary <= 0)
			{
				cout << " -_- " << endl;
				cout << "Enter a number from the list " << endl;
				workers[i].salary = doubleNumbers();
				while (((workers[i].salary <= 0) && (workers[i].salary >= 0)))
				{
					if (((workers[i].salary <= 0) && (workers[i].salary >= 0)))
					{
						workers[i].salary = 0;
						cout << "Prover";
						workers[i].salary = doubleNumbers();
					}
				}
			}
			cout << "________________________________" << endl;
			fout << workers[i].fam << "   " << workers[i].name << "   " << workers[i].department << "   " << workers[i].salary <<endl;
		}
	}
	count_1[0] = count;
	fin.close();
	return count;
}
int empty_file(string path,worker* workers, int count, int count_1[])
{
	setlocale(LC_ALL, "ru");
	path = "myFile.txt";

	ofstream fout;
	ifstream fin;
	fin.open(path);

	if (!fin.is_open())
	{
		cout << "File opening error" << endl;
		fout.open(path, ofstream::app);
		add(path, workers, count, count_1);
		fin.close();
	}
	else
	{
		cout << "The file is open" << endl;
	}
	fin.close();
	return 0;
}
void perevod(string path, worker* workers, int count_1[])
{
	path = "myFile.txt";
	ofstream fout;
	ifstream fin;
	fin.open(path);
	count_1[1] = 0;
	char a = 0;
	int  i = 0;
	if (!fin.is_open())
	{
		cout << "File opening error" << endl;
	}
	else
	{
		while (!fin.eof())
		{
			if (a % 4 == 0)
			{
				fin >> workers[i].fam;
				a++;
			}
			else
			{
				if (a % 4 == 1)
				{
					fin >> workers[i].name;
					a++;
				}
				else
				{
					if (a % 4 == 2)
					{
						fin >> workers[i].department;
						a++;
					}
					else
					{
						if (a % 4 == 3)
						{
							fin >> workers[i].salary;
							a++;
							i++;
						}
					}
				}
			}

		}
	}
	count_1[0] = i;
}
void naity_fam(string path, worker* workers, int count_1[])
{
	string find;
	perevod(path, workers, count_1);
	cout << "Enter the worker's last names";
	cout << endl;
	cin >> find;
	cout << endl;
	string* finding_workers = new string[count_1[0]];
	int* finding_workers_department = new int[count_1[0]];
	double* finding_workers_salary = new double[count_1[0]];
	cout << endl;
	int cheking = 0;
	cout << "-----Finding-----Worker's last names-----";
	for (int i = 0; i < count_1[0]; i++)
	{
		if (workers[i].fam == find)
		{
			finding_workers[cheking] = workers[i].fam + ' ' + workers[i].name;
			finding_workers_department[cheking] = workers[i].department;
			finding_workers_salary[cheking] = workers[i].salary;
			cheking++;
		}
	}
	if (cheking == 0)
	{
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout << "Not founded";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << endl;
	}
	else
	{
		cout << endl;
		sort(finding_workers, finding_workers + cheking);
		for (int i = 0; i < cheking; i++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			cout << "Names and last names  " << finding_workers[i] << endl << "Department  " << finding_workers_department[i] << endl << "Salary  " << finding_workers_salary[i] << endl << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
	}
}
void naity_department(string path, worker* workers, int count_1[])
{
	int find;
	perevod(path, workers, count_1);
	cout << "Enter the Department";
	cout << endl;
	cin >> find;
	cout << endl;
	string* finding_workers = new string[count_1[0]];
	int* finding_workers_department = new int[count_1[0]];
	double* finding_workers_salary = new double[count_1[0]];
	cout << endl;
	int cheking = 0;
	cout << "-----Finding-----Department-----";
	for (int i = 0; i < count_1[0]; i++)
	{
		if (workers[i].department == find)
		{
			finding_workers[cheking] = workers[i].fam + ' ' + workers[i].name;
			finding_workers_department[cheking] = workers[i].department;
			finding_workers_salary[cheking] = workers[i].salary;
			cheking++;
		}
	}
	if (cheking == 0)
	{
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout << "Not founded";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << endl;
	}
	else
	{
		cout << endl;
		sort(finding_workers, finding_workers + cheking);
		for (int i = 0; i < cheking; i++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			cout << "Department  " << finding_workers_department[i] << endl << "Names and last names  " << finding_workers[i] << endl  << "Salary  " << finding_workers_salary[i] << endl << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
	}
}
void sort_salary(string path, worker* workers, int count_1[])
{
	perevod(path, workers, count_1);
	cout << endl;
	string* finding_workers = new string[count_1[0]];
	int* finding_workers_department = new int[count_1[0]];
	double* finding_workers_salary = new double[count_1[0]];
	cout << endl;
	int cheking = 0;
	cout << "-----Finding-----Department-----";
	for (int i = 0; i < count_1[0]; i++)
	{
			finding_workers[cheking] = workers[i].fam + ' ' + workers[i].name;
			finding_workers_department[cheking] = workers[i].department;
			finding_workers_salary[cheking] = workers[i].salary;
			cheking++;
	}
	if (cheking == 0)
	{
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout << "Not founded";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << endl;
	}
	else
	{
		cout << endl;
		sort(finding_workers_salary, finding_workers_salary + cheking);
		for (int i = 0; i < cheking; i++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			cout << "Salary  " << finding_workers_salary[i] << endl << "Names and last names  " << finding_workers[i] << endl << "Department  " << finding_workers_department[i] << endl   << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
	}
}
int main()
{
	setlocale(LC_ALL, "ru");
	int count = 100000;
	int count_1[2];
	count_1[0] = 0;
	count_1[1] = 0;
	worker* workers = new worker[count];
	int n = 256;
	int number;
	int flag = 1;
	string path = "myFile.txt";
	empty_file(path, workers, count, count_1);
	Sleep(500);
	system("cls");
	while (flag != 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "-----------------------MENU------------------" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);

		cout << "    --   --      |-------  |    |  |       |        " << endl;
		cout << "   /  \\ /  \\     |         |\\   |  |       |     " << endl;
		cout << "  /    |    \\    |_______  | \\  |  |       |      " << endl;
		cout << " /           \\   |         |  \\ |  |       |      " << endl;
		cout << "/             \\  |_______  |   \\|  |_______|      " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << "Enter 1 to add a passenger                          " << endl;
		cout << "Enter 2 to find passengers by worker's last names   " << endl;
		cout << "Enter 3 to find passengers by department            " << endl;
		cout << "Enter 4 to sort by salary                           " << endl;
		cout << "Enter 5 to exit                                     " << endl;
		cout << "Input:     ";
		number = onlyNumbers();
		switch (number)
		{
		case 1:
			system("cls");
			add(path, workers, count, count_1);
			break;
		case 2:
			system("cls");
			naity_fam(path, workers, count_1);
			break;
		case 3:
			system("cls");
			naity_department(path, workers, count_1);
			break;
		case 4:
			system("cls");
			sort_salary(path, workers, count_1);
			break;
		case 5:
			flag = 0;
			break;
		default:
			cout << " -_- " << endl;
			cout << "Enter a number from the list " << endl;
			break;
		}
		system("pause");
		system("cls");
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	return 0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}