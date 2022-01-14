#include <conio.h>  	//для getch и других функций
#include "iostream"		//русский язык
#include "stdio.h"		//ввод-вывод
#include <Windows.h>	//русский язык
#include <stdlib.h> 	//для выделения памяти и других функций
#include <math.h>   	//математика
#include <string.h>		//функции для работы со строками


typedef struct subject							//структура
{
    	char name[50]; 							//название
    	int year; 								//год
    	char faculty[50]; 						//факультет
    	char cathedra[50]; 						//кафедра
    	int hours; 								//часы
    	
		struct subject *next;					//следующий элемент
		struct subject *prev;					//предыдущий элемент
} typeSubject;



//основные функции
typeSubject* createMemory(typeSubject* head, int* sizeSubject);					//выделение памяти
typeSubject* inputKeyboard(typeSubject* head, int sizeSubject);					//ввод с клавиатуры
void searchLocationElement(typeSubject* head, int sizeSubject);					//поиск элемента
typeSubject* sortArray(typeSubject* head, int sizeSubject);						//сортировка
typeSubject* editElem(typeSubject* head, int sizeSubject);						//редактирование
typeSubject* exchangeElem(typeSubject* head, int sizeSubject);					//обмен
typeSubject* addElem(typeSubject* head, int* sizeSubject);						//добавление нового элемента
typeSubject* deleteTargetElem(typeSubject* head, int* sizeSubject);				//удаление элемента
typeSubject* addNewElem(typeSubject* head, int* sizeSubject);					//вставка элемента
void addressLast(typeSubject* head, int sizeSubject);							//определение адреса последнего элемента
int length(typeSubject* head);													//длина списка
//разделить список
void split(typeSubject*& head, typeSubject*& head1, typeSubject*& head2, int* sizeSubject, int* sizeSubject1, int* sizeSubject2);
//объединить список	
void unite(typeSubject*& head, typeSubject*& head1, typeSubject*& head2, int* sizeSubject, int* sizeSubject1, int* sizeSubject2);
void writeFile(typeSubject* head, int sizeSubject);								//запись в файл
void readFile(typeSubject* head, int sizeSubject);								//читать файл
typeSubject* readDateFromFile(typeSubject* head, int* sizeSubject);				//записать данные из файла в список
//вывод на экран
void subjectPrintMain(typeSubject* head, typeSubject* head1, typeSubject* head2, int sizeSubject, int sizeSubject1, int sizeSubject2);						
void freeMemory(typeSubject*& head, typeSubject*& head1, typeSubject*& head2);	//освобождение памяти


//вспомогательные функции
void subjectPrint(typeSubject* head, int sizeSubject, int sortNumber);			//вывод одного из списков
void print (typeSubject *node, int position);									//вывод определенного элемента
void sortAscendingName(typeSubject*& head);										//сортировка названий по возрастанию
void sortAscendingYear(typeSubject*& head);										//сортировка годов по возрастанию
void sortAscendingFaculty(typeSubject*& head);									//сортировка факультетов по возрастанию
void sortAscendingCathedra(typeSubject*& head);									//сортировка кафедр по возрастанию
void sortAscendingHours(typeSubject*& head);									//сортировка часов по возрастанию
void sortDescendingName(typeSubject*& head);									//сортировка названий по убыванию
void sortDescendingYear(typeSubject*& head);									//сортировка годов по убыванию
void sortDescendingFaculty(typeSubject*& head);									//сортировка факультетов по убыванию
void sortDescendingCathedra(typeSubject*& head);								//сортировка кафедр по убыванию
void sortDescendingHours(typeSubject*& head);									//сортировка часов по убыванию
void swap(typeSubject*& head, typeSubject* firstElem, typeSubject* secondElem); //меняет местами элементы
typeSubject* miniAddElem(int position, typeSubject* head, int* sizeSubject); 	//добавление элемента
