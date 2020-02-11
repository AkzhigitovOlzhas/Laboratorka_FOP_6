#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<iomanip>
#include <algorithm>
#include <math.h>

using namespace std;

//1. �������� � ��������� ������ ������� 8�8 ��������� ������������
//�����, �������� ������� �� 0 �� 100. ������� ���������� ������ �� ����� �
//�������� � ���� � ���� ����������� ������� � ����� ������� ����� �������.
void task1() {
	fstream file;
	file.open("result1.txt", fstream::out | fstream::in | fstream::trunc);
	if (!file.is_open()) {
		cout << "ERROR";
	}
	double array[8][8];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			array[i][j] = rand() / (double)RAND_MAX*(8.0 - 2.0) + 2.0;
			file << fixed;
			file.precision(2);
			file << setw(3) << array[i][j] << "\t";
		}
		file << endl;
	}
	file.close();
}
//2. � ����� ���� �������� �� ����������� : ����� ����������, ����� �
//������� ���������.
//�) ������� �������� � ���������� � ������� ����������� ������
//����� ����������.
//�) ���������� ���������� ����������� ������ �����.
void task2() {
	fstream f;
	f.open("task2.txt", fstream::in | fstream::out);
	string line;
	string name;
	string surname;
	int number;
	string avto;
	int audi = 0, Tayota = 0, Honda = 0, BMW = 0, Moskv = 0,mashine=0;
	while (getline(f, line)) {
		f >> avto >> number >> surname >> name;
		cout << "�����: " << avto << "\n����� ������: " << number << "\n�������:" << surname << "\n���: " << name << endl << endl;
		if (avto == "Audi") {
			audi += 1;
		}
		if (avto == "Tayota") {
			Tayota += 1;
		}
		if (avto == "Honda") {
			Honda += 1;
		}
		if (avto == "BMW") {
			BMW += 1;
		}if (avto == "Moskvich") {
			Moskv += 1;
		}
		mashine++;
	}
	cout << "���-�� ����� ����� Audi: " << audi << endl;
	cout << "���-�� ����� ����� Tayota: " << Tayota << endl;
	cout << "���-�� ����� ����� Honda: " << Honda << endl;
	cout << "���-�� ����� ����� BMW: " << BMW << endl;
	cout << "���-�� ����� ����� Moskvich: " << Moskv << endl;
	cout << "���-�� �����: " << mashine << endl;
}
//3. ����� ������� ����� ������� �������.��������� ������� ������
//������ ������ $.����������������� ����� � 60 - ���������� ������,
//�������� ������.�������� ����� ������ ���� ���� �� �����, ��������
//�������� ����� ������� � ����������, � �������������� ����� ������ ����
//������� � ���� �Result_file.txt�.
void task3() { 
	fstream fol;
	fstream result;
	string fname;
	string line;
	int c = 0;
	cout << "������� ��� ����� ��� ����������: "; cin>>fname;//   <----  ������� ������ ������� f.txt � ���������� ��� ������ ���� � ������� ����� �� ����� ���������
	fol.open(fname, fstream::in | fstream::out);
	result.open("Result_file.txt", fstream::in | fstream::out|fstream::trunc);
	getline(fol, line);
	for (int i = 0; i < size(line); i++)
	{
		c++;
		if (line[i] == '$') {
			result << endl;
			line[i] = '\t';

		}
		if (c > 60) {
			result << endl;
			c = 0;
		}
		else {
			result << line[i];
		}
	}
	fol.close();
	result.close();
}
//4. �����, �� ���������� ����������� ��� � ����������, ������
//��������� ���������� �������.�������� ��� ��������� �����, ����� ����,
//������� ����� �����, ��������� �������.�������� ����� ������ ���� ����
//�� �����, �������� �������� ����� ������� � ����������, � ��������������
//����� ������ ���� ������� � ���� �Result_file.txt�.
void task4() {
	fstream f1; //���� ��� ����������
	fstream f2; //���� ��� ������
	string filname;
	string line;
	cout << "������� ��� ����� ��� ����������: "; cin >> filname;//   <----  ������� ������ ������� task4.txt � ���������� ��� ������ ���� � ������� ����� �� ����� ���������
	f1.open(filname, fstream::in );
	f2.open("Result_file_task_4.txt", fstream::in | fstream::out | fstream::trunc);
	getline(f1, line);
	int i = 0;
	int s = line.size();
	while (i<s) {
		if(isalpha(line[i])) {
			line[i] = tolower(line[i]);
		}
		i++;
	}
	i = 0;
	while (i < s) {
		if (line[i] == '.') {
			line[i + 1] = toupper(line[i + 1]);
		}
		f2 << line[i];
		i++;
	}
	
	f1.close();
	f2.close();
}

//5. �� ������� �� ���� ����� ����������� ����� ����������� �����
//������� $2.00.� ������ ������� ����� ���� ����� ����� �������������
//����������� $0.50 �� ������ ������ ��� �������� ��� ����� ���� �����.
//������������ ����� �� ����� ���������� $10.00.��������, ��� ����� ��
//��������� �����, ��� �� ����� �� ���.�������� ��� ������ ������� �
//������ ������ �� �������� ��� ������� �� ����
//��������, ������� ��������� ���� ���������� ����� � ���� ������.��
//������ ������� ������������ �������� ��� ������� �������.����
//��������� ������ �������� ���������� � ���������� ��������������
//������� � ������ ������������ � �������� ����� ��������� �����.
//��������� ������ ������������ ������� calculateCharges, ����� �� -
//�������� ����� ��� ������� �������.���������� ������ ������ ���� -
//���������� � ��������� ������� :
//���������� ���� �����
//	1	   1.5	 2.00
//	2	   4.0   2.50
//	3	   24.0  10.00
//����� 29.5 14.50
double calculateCharges(double);
void task5() {
	double time1, time2, time3, totalTime;
	double sum1, sum2, sum3, totalSum;
	for (;;)
	{
		cout << "������� ����� �������: " << endl;
		cin >> time1 >> time2 >> time3;
		if (time1 < 0 || time1 > 24 || time2 < 0 || time2 > 24 || time3 < 0 || time3 > 24)
		{
			cout << "������ ��������� ����!" << endl;
			continue;
		}
		break;
	}
	totalTime = time1 + time2 + time3;
	sum1 = calculateCharges(time1);
	sum2 = calculateCharges(time2);
	sum3 = calculateCharges(time3);
	totalSum = sum1 + sum2 + sum3;
	//����� ����������
	cout << setw(10) << "����������" << setw(10) << "����" << setw(10) << "�����" << endl;
	cout << setw(10) << "1" << setw(10) << time1 << setw(10) << sum1 << endl;
	cout << setw(10) << "2" << setw(10) << time2 << setw(10) << sum2 << endl;
	cout << setw(10) << "3" << setw(10) << time3 << setw(10) << sum3 << endl;
	cout << setw(10) << "�����: " << setw(10) << totalTime << setw(10) << totalSum << endl;
}
int main() { 
	setlocale(LC_ALL, "rus");
	//task1(); // <------- ����� ��������� ������� ������ ��������������� ������ �������)) 
	//task2();
	//task3();
	//task4();
	//task5();
	system("pause");
	return 0;
}
double calculateCharges(double timeSt)
{
	double sum;
	if (timeSt > 0 && timeSt <= 3)
		sum = 2.00;
	else if (timeSt > 3 && timeSt < 24)
	{
		sum = ceil(timeSt - 3) * 0.50 + 2.00;
		if (sum > 10)
			sum = 10;
	}
	else if (timeSt == 24)
		sum = 10.00;
	else
		sum = 0;
	return sum;
}