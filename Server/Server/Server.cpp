#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

int numberOfSubjects = 4;

struct Student
{
	char nameStudent[30];
	int studentGrades[4];

}studentsList;

int grantOrNot() {
	for (int i = 0; i < numberOfSubjects; i++)
		if (studentsList.studentGrades[i] <= 3)
			return 0;
	for (int i = 0; i < numberOfSubjects; i++)
		if (studentsList.studentGrades[i] == 4)
			return 1;
	return 2;
}

int getFileSize() {
	ifstream file1("C:\\Users\\petra\\source\\repos\\ProjectNetwork\\Client\\Client\\File1.txt", ios::binary | ios::in);
	//октрываем файл клиента для чтения 
	file1.seekg(0, ios::end);  // Мы перемещаемся в конец файла и спрашиваем какой сейчас  
	return file1.tellg();	   // отступ (от начала),т.е. спрашиваем размер файла
}

void isFileGotBigger(int currentFileSize) {
	while (true) {
		int newFileSize = getFileSize();
		if (newFileSize > currentFileSize)
			return;
	}
}

void readingStudentData(int fileSize) {
	ifstream file2("C:\\Users\\petra\\source\\repos\\ProjectNetwork\\Client\\Client\\File1.txt", ios::binary | ios::in);
	file2.seekg(fileSize, ios::beg);
	file2.read((char*)&studentsList, sizeof(studentsList));//считали данные о студенте в переменную studentsList
    //записанные клиентом
}

void writeStudentGrade() {
	ofstream file("File2.txt", ios::binary | ios::app);//Открытие файла для двоичных операций ввода-вывода
	//Добавление всех выводимых данных в конец заданного файла
	int studentGrade = grantOrNot();
	file.write((char*)&studentGrade, sizeof(studentGrade));//записали информацию о стипендии студента
	file.close();
}

int main()
{
	while (true) {
		cout << "I am tyt";
		int currentFileSize = getFileSize();
		isFileGotBigger(currentFileSize);
		readingStudentData(currentFileSize); //От старого размера файла считываем студентов
		writeStudentGrade();
	}
}
