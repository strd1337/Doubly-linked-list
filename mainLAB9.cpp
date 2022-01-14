#include "LAB9.cpp"

int main(void)
{
  	int choice; 					//выбор пользователя
  	int sizeSubject;				//кол-во предметов списка
  	int sizeSubject1;				//кол-во предметов 1 списка
  	int sizeSubject2;				//кол-во предметов 2 списка
  	typeSubject* head = NULL;		//начало списка
  	typeSubject* head1 = NULL;		//начало 1 списка
  	typeSubject* head2 = NULL;		//начало 2 списка
  	
  	//кириллица
  	SetConsoleCP(1251);				
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	
	do
  	{ 
  		//Меню
  		printf ("\nМеню:\n");
  		printf ("1.Динамическое выделение памяти;\n");
  		printf ("2.Ввод элементов с клавиатуры;\n");
  		printf ("3.Поиск элемента;\n");
  		printf ("4.Сортировка;\n");
  		printf ("5.Редактирование элемента;\n");
  		printf ("6.Обмен двух элементов;\n");
  		printf ("7.Добавление нового элемента в конец;\n");
  		printf ("8.Удаление элемента;\n");
  		printf ("9.Вставка элемента;\n");
  		printf ("10.Определение адреса последнего элемента;\n");
  		printf ("11.Определение длины списка;\n");
  		printf ("12.Разделение списка на два;\n");
  		printf ("13.Слияние двух списков;\n");
  		printf ("14.Запись в файл;\n");
  		printf ("15.Считывание из файла;\n");
  		printf ("16.Записать данные из файла в список.\n");
  		printf ("17.Вывод элементов на экран;\n");
  		printf ("18.Освобождение памяти;\n");
  		printf ("19.Окончание работы программы.\n");
  	
  		
  		//ввод числа пользователем
    	printf ("\n\nВыберите номер из меню: ");
    	scanf ("%d", &choice);
    	
    		
    	//проверка: была ли выделена память
    	//от введённого числа зависит, что будет выполняться	
		switch(choice)
    	{
    		case 1:		//выделение памяти
   				head = createMemory(head, &sizeSubject);					
				break;
        	case 2:		//ввод с помощью клавиатуры
        		head = inputKeyboard(head, sizeSubject);				
        		break;
        	case 3:		//поиск элемента
        		searchLocationElement(head, sizeSubject);
				break;
			case 4:		//сортировка
				head = sortArray(head, sizeSubject);
				break;
			case 5:		//редактирование элемента
				head = editElem(head, sizeSubject);		
				break;
			case 6:		//обмен элементов
				head = exchangeElem(head, sizeSubject);		
				break;
			case 7:		//добавление элемента
				head = addElem(head, &sizeSubject);		
				break;
			case 8:		//удаление элемента
				head = deleteTargetElem(head, &sizeSubject);	
				break;
			case 9:		//вставка элемента
				head = addNewElem(head, &sizeSubject);	
				break;
			case 10: 	//определение адреса последнего элемента
				addressLast(head, sizeSubject);
				break;
			case 11:	//длина списка
				printf("\nВы выбрали: определение длины списка.\n\n");
				printf ("Длина основного списка = %d\n", length(head));
				printf ("Длина 1-го списка = %d\n", length(head1));
				printf ("Длина 2-го списка = %d\n", length(head2));	
				break;
			case 12:	//разделение списка на два
				split(head, head1, head2, &sizeSubject, &sizeSubject1, &sizeSubject2);
				break;
			case 13:	//слияние двух списков
				unite(head, head1, head2, &sizeSubject, &sizeSubject1, &sizeSubject2);
				break;
			case 14:	//запись в файл
				writeFile(head, sizeSubject);
				break;
			case 15:	//чтение файла
				readFile(head, sizeSubject);
				break;
			case 16:	//запись данных из файла в список	
				head = readDateFromFile(head, &sizeSubject);
				break;
			case 17:	//вывод на экран элементов
				subjectPrintMain(head, head1, head2, sizeSubject, sizeSubject1, sizeSubject2);
				break;
			case 18:	//освобождение памяти
				freeMemory(head, head1, head2);
				break;
			case 19: 	//завершение программы
        		if (head != NULL || head1 != NULL)
        			freeMemory(head, head1, head2);
        		printf("\nВы выбрали: окончание работы программы.\n");
        		printf("\nBye, bye\n");
        		break;	
        	default:
        		printf("\nОшибка. Вы не ввели номер из меню.\n");
        		break;
    	} 
		 	 
  	} while (choice != 19);
  	
  	getch();
  	return 0;
}
