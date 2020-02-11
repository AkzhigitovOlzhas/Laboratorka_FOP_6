#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<iomanip>
#include <algorithm>
#include <math.h>

using namespace std;

//1. Записать в двумерный массив размера 8Х8 случайные вещественные
//числа, значения которых от 0 до 100. Вывести полученный массив на экран и
//записать в файл в виде выровненной матрицы с двумя знаками после запятой.
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
//2. В файле есть сведения об автомобилях : марка автомобиля, номер и
//фамилия владельца.
//а) Вывести сведения о владельцах и номерах автомобилей каждой
//марки автомобиля.
//б) Подсчитать количество автомобилей каждой марки.
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
		cout << "Марка: " << avto << "\nНомер машины: " << number << "\nФамилия:" << surname << "\nИмя: " << name << endl << endl;
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
	cout << "Кол-во машин марки Audi: " << audi << endl;
	cout << "Кол-во машин марки Tayota: " << Tayota << endl;
	cout << "Кол-во машин марки Honda: " << Honda << endl;
	cout << "Кол-во машин марки BMW: " << BMW << endl;
	cout << "Кол-во машин марки Moskvich: " << Moskv << endl;
	cout << "Кол-во машин: " << mashine << endl;
}
//3. Текст записан одной длинной строкой.Признаком красной строки
//служит символ $.Переформатировать текст в 60 - символьные строки,
//формируя абзацы.Исходный текст должен быть взят из файла, название
//которого будет введено с клавиатуры, а результирующий текст должен быть
//выведен в файл «Result_file.txt».
void task3() { 
	fstream fol;
	fstream result;
	string fname;
	string line;
	int c = 0;
	cout << "Введите имя файла для считывания: "; cin>>fname;//   <----  Акбеков Талгат вводите f.txt я специально уже создал файл с текстом чтобы вы могли проверить
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
//4. Текст, не содержащий собственных имён и сокращений, набран
//полностью прописными буквами.Заменить все прописные буквы, кроме букв,
//стоящих после точки, строчными буквами.Исходный текст должен быть взят
//из файла, название которого будет введено с клавиатуры, а результирующий
//текст должен быть выведен в файл «Result_file.txt».
void task4() {
	fstream f1; //Файл для считывания
	fstream f2; //Файл для записи
	string filname;
	string line;
	cout << "Введите имя файла для считывания: "; cin >> filname;//   <----  Акбеков Талгат вводите task4.txt я специально уже создал файл с текстом чтобы вы могли проверить
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

//5. За стоянку до трех часов парковочный гараж запрашивает плату
//минимум $2.00.В случае стоянки более трех часов гараж дополнительно
//запрашивает $0.50 за каждый полный или неполный час сверх трех часов.
//Максимальная плата за сутки составляет $10.00.Допустим, что никто не
//паркуется более, чем на сутки за раз.Напишите про грамму расчета и
//печати оплаты за парковку для каждого из трех
//клиентов, которые парковали свои автомобили вчера в этом гараже.Вы
//должны вводить длительность парковки для каждого клиента.Ваша
//программа должна печатать результаты в аккуратном табулированном
//формате и должна рассчитывать и печатать общий вчерашний доход.
//Программа должна использовать функцию calculateCharges, чтобы оп -
//ределять плату для каждого клиента.Результаты работы должны пред -
//ставляться в следующем формате :
//Автомобиль Часы Плата
//	1	   1.5	 2.00
//	2	   4.0   2.50
//	3	   24.0  10.00
//Итого 29.5 14.50
double calculateCharges(double);
void task5() {
	double time1, time2, time3, totalTime;
	double sum1, sum2, sum3, totalSum;
	for (;;)
	{
		cout << "Введите время стоянки: " << endl;
		cin >> time1 >> time2 >> time3;
		if (time1 < 0 || time1 > 24 || time2 < 0 || time2 > 24 || time3 < 0 || time3 > 24)
		{
			cout << "Ошибка повторите ввод!" << endl;
			continue;
		}
		break;
	}
	totalTime = time1 + time2 + time3;
	sum1 = calculateCharges(time1);
	sum2 = calculateCharges(time2);
	sum3 = calculateCharges(time3);
	totalSum = sum1 + sum2 + sum3;
	//Вывод результата
	cout << setw(10) << "Автомобиль" << setw(10) << "Часы" << setw(10) << "Плата" << endl;
	cout << setw(10) << "1" << setw(10) << time1 << setw(10) << sum1 << endl;
	cout << setw(10) << "2" << setw(10) << time2 << setw(10) << sum2 << endl;
	cout << setw(10) << "3" << setw(10) << time3 << setw(10) << sum3 << endl;
	cout << setw(10) << "Итого: " << setw(10) << totalTime << setw(10) << totalSum << endl;
}
int main() { 
	setlocale(LC_ALL, "rus");
	//task1(); // <------- Чтобы проверыть задания просто раскоминтируйте нужную функцию)) 
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