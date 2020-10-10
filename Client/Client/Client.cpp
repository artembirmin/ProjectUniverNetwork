#include <iostream>
#include <fstream>
#include<Windows.h>
using namespace std;

int numberOfSubjects = 4;

struct Student
{
	char nameStudent[30];
	int studentGrades[4];

}studentsList;

void inputtingDataAboutStudent() {

	cout << "Enter student name\n";
	cin >> studentsList.nameStudent;
	cout << "Enter student grade in 4 subjects\n";
	for (int i = 0; i < numberOfSubjects; i++)
		cin >> studentsList.studentGrades[i];
}

int getFileSize() {
	ifstream file2("C:\\Users\\petra\\source\\repos\\ProjectNetwork\\Server\\Server\\File2.txt", ios::binary | ios::in);
	//Открыли файл
	file2.seekg(0, ios::end);//Поставили курсор в конец
	return file2.tellg(); //Количество пройденных байтов (курсор)
}

void isFileGotBigger(int currentFileSize) {
	while (true) {
		int newFileSize = getFileSize();
		if (newFileSize > currentFileSize)
			return;//выйдем из функции только когда размер файла увеличится
		//Sleep(7000);для нескольких структур
	}
}

void writingDataAboutStudent() {
	ofstream file("File1.txt", ios::binary | ios::app/* Открыли для записи в конец файла*/);
	//Открытие файла для двоичных операций ввода-вывода 
	//Добавление всех выводимых данных в конец заданного файла
	if (!file) {
		cout << "file isn't open!";
		exit(1);//Выход из проги
	}
	else {
		file.write((char*)&studentsList/*Указатель на начало строки*/, sizeof(studentsList));//записываем в файл данные структуры
		file.close();
	}
}

int gettingInfoAboutGrant(int currentFileSize) {
	int studentGrade;
	ifstream file2("C:\\Users\\petra\\source\\repos\\ProjectNetwork\\Server\\Server\\File2.txt", ios::binary | ios::in);
	file2.seekg(currentFileSize, ios::beg);
	file2.read((char*)&studentGrade, sizeof(studentGrade));//считали данные с File2.txt(то,что вернула функция GrandOrNot)
	file2.close();
	return studentGrade;
}

void main() {
	while (true) {
		inputtingDataAboutStudent();
		int currentFileSize = getFileSize();
		writingDataAboutStudent();
		isFileGotBigger(currentFileSize); //если размер изменился(увеличился) - считываем данные с 
		switch (gettingInfoAboutGrant(currentFileSize))//"File2.txt" и по их результатам определяем cтипендию
		{
		case 0:
			cout << "\nno grant\n\n";
			break;
		case 1:
			cout << "\nOrdinary grant\n\n";
			break;
		case 2:
			cout << "\nIncreased  grant\n\n";
			break;
		}
	}
}
