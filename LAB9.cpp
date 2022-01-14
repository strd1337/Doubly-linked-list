#include "LAB9.h"		//функции для структуры

typeSubject *head;      		//указатель на начало памяти, которая будет выделена под структуру
typeSubject *node;              //текущий элемент
bool memoryAllocate = false; 	//проверка: была ли выделена память
bool arrayExist = false;		//проверка: в списке не мусор
bool arrayExist1 = false;		//проверка: в списке не мусор
bool arrayExist2 = false;		//проверка: в списке не мусор


//Основные функции

//выделение памяти
typeSubject* createMemory(typeSubject *head, int *sizeSubject)              
{	
	if (memoryAllocate)		//проверяем выделена память, если нет, то выделяем
    	printf("\nПамять уже выделена.\n");
	else {
		printf("\nВы выбрали: динамическое выделение памяти.\n");
		
		printf("\nВведите количество предметов: ");
    	//не ставим "&", т.к. функция принимает указатель
   		scanf("%d", sizeSubject);
		
		//создаем голову
    	head = new typeSubject;
		head->next = NULL;
		head->prev = NULL;
		
		//создаем узлы
		typeSubject *temp;
		node = head;
    	for (int i = 0; i < *sizeSubject - 1; i++)
	 	{
	 		temp = node;
	 		node->next = new typeSubject;
	 		node = node->next;
	 		node->prev = temp;
	 		node->next = NULL;
	 	}
		
    	memoryAllocate = true;			//память выделена			
    	printf ("\nЗавершено!\n");
	}
	
	return head;
}


//ввод с клавиатуры
typeSubject* inputKeyboard(typeSubject *head, int sizeSubject)     
{
	//проверяем выделена память, если нет,
	//то просим выделить и возвращаем массив
	if (memoryAllocate && !arrayExist1) { 
	    printf("\nВы выбрали: ввод элементов с клавиатуры.\n");
		printf("\nВвод данных:\n");

		node = head;
		//для каждого предмета вводим данные
	  	for (int i = 0; i < sizeSubject; i++)
	 	{	
		   	printf("Название %d предмета: ", i + 1);
		   	scanf("%s", node->name);
		
		   	printf("Год %d предмета: ", i + 1);
		   	scanf("%d", &node->year);
		    	
		   	printf("Факультет %d предмета: ", i + 1);
		   	scanf("%s", node->faculty);
		    	
		   	printf("Кафедра %d предмета: ", i + 1);
		   	scanf("%s", node->cathedra);
		    	
		   	printf("Количество часов %d предмета: ", i + 1);
		   	scanf("%d", &node->hours);
		   	
			node = node->next;
		   	printf("\n");
		}
		
		arrayExist = true;		//массив создан
	} else 
		printf("\nОшибка. Память не выделена или объедините списки.\n");
	
	return head;
}


//нахождение предмета в зависимости от критерия
void searchLocationElement(typeSubject* head, int sizeSubject)
{
	//проверяем существует ли массив, если нет, то просим ввести с клавиатуры
	//и выводим сообщение об ошибке
	if (arrayExist) {			
		int searchChoice;         		//выбор пользователя
		char locationChar[30]; 			//что ищем(строка)
		int locationInt; 				//что щем(число)
		int position;					//позиция элемента, который выводим
		
		printf("\nВы выбрали: поиск элемента.\n");
		
		//пока пользователь не захочет выйти в главное меню
		//будет выскакивать меню
		do
		{	
			int f = 0; 	//флажок для нахождения хотя бы одного совпадения
			
			//меню
			printf("1.Искать имя;\n");
			printf("2.Искать год;\n");
			printf("3.Искать факультет;\n");
			printf("4.Искать кафедру;\n");
			printf("5.Искать количество часов;\n");
			printf("6.Выйти в главное меню.\n");
			
			//ввод выбора пользователя
			printf("\nВведите номер для поиска: ");		
			scanf("%d", &searchChoice);
			
			//От выбора пользователя будет зависить дальнейший ход
			//С помощью функции strcmp ищем схожие строки
			//С помощью функции getchar считываем символ из стандартного потока ввода
			//С помощью функции print распечатываем сразу информацию о предмете,
			//который мы нашли
			switch(searchChoice)
			{
				case 1: //ищем по названию
					//просим пользователя ввести, что он хочет найти
					printf("\nВведите название для поиска: ");
					scanf("%s", locationChar);
					getchar();
					
					//идём по узлам, если находим сходство с тем,
					//что ввел пользователь, распечатываем информацию
					node = head;
					position = 1;
					do
					{
						if (strcmp(node->name, locationChar) == 0) {
							print(node, position);
							f = 1;	
						}					
						node = node->next;
						position++;
						
					} while (node != NULL);	
				
					//если f = 0, выводим, что ничего не нашли
					if (!f)
						printf("\nТакое название не найдено.\n\n");
						
					break;
				case 2: //ищем по году
					//делает все тоже самое, что в case 1
					printf("\nВведите год для поиска: ");
					scanf("%d", &locationInt);
					
					node = head;
					position = 1;
					do
					{
						if (node->year == locationInt) {
							print(node, position);
							f = 1;	
						}					
						node = node->next;
						position++;
						
					} while (node != NULL);		
					
					if (!f)
						printf("\nТакой год не найден.\n\n");
						
					break;
				case 3: //ищем по факультету
					//делает все тоже самое, что в case 1
					printf("\nВведите факультет для поиска: ");
					scanf("%s", locationChar);
					getchar();
					
					node = head;
					position = 1;
					do
					{
						if (strcmp(node->faculty, locationChar) == 0) {
							print(node, position);
							f = 1;	
						}					
						node = node->next;
						position++;
						
					} while (node != NULL);	
					
					if (!f)
						printf("\nТакой факультет не найден.\n\n");
						
					break;
				case 4:
					//делает все тоже самое, что в case 1
					printf("\nВведите кафедру для поиска: ");
					scanf("%s", locationChar);
					getchar();
					
					node = head;
					position = 1;
					do
					{
						if (strcmp(node->cathedra, locationChar) == 0) {
							print(node, position);
							f = 1;	
						}					
						node = node->next;
						position++;
						
					} while (node != NULL);	
					
					if (!f)
						printf("\nТакая кафедра не найдена.\n\n");
						
					break;
				case 5:
					//делает все тоже самое, что в case 1
					printf("\nВведите количество часов для поиска: ");
					scanf("%d", &locationInt);
					
					node = head;
					position = 1;
					do
					{
						if (node->hours == locationInt) {
							print(node, position);
							f = 1;	
						}					
						node = node->next;
						position++;
						
					} while (node != NULL);	
					
					if (!f)
						printf("\nТакое количество часов не найдено.\n\n");
						
					break;
				case 6:
					printf("\nВыйти в главное меню.\n");
					break;
				default:
					//если пользователь ввел число не из меню,
					//то выводим сообщение об ошибке
					printf("\nНеправильный ввод. Пожалуйста, введите номер из меню.\n\n");
					break;
			}
	
		} while (searchChoice != 6);		
		printf("\nЗавершено!\n");
	} else 
		printf("\nОшибка. Список не существует. Введите список с клавиатуры.\n");
}


//сортировка массива
typeSubject* sortArray(typeSubject* head, int sizeSubject)
{	
	//если массив существует и элементов массива > 1
	//то заходим в тело if
	//если массив не существует или элементов массива <= 1
	//то выдаем ошибку и возвращаем массив
	if (sizeSubject > 1 && arrayExist == true) {
		int sortChoice;		//выбор пользователя: параметр
		int sortChoiceTwo;	//выбор пользователя: убывание/возрастание
	   	
	   	printf("\nВы выбрали: сортировка элементов.\n");
	   	
	   	start:
	   	
	   	//пока пользователь не захочет выйти в главное меню
		//будет выскакивать меню
		do
	   	{
	   		//меню
	   		printf("\n1.Сортировка имён;\n");
			printf("2.Сортировка годов;\n");
			printf("3.Сортировка факультетов;\n");
			printf("4.Сортировка кафедр;\n");
			printf("5.Сортировка часов;\n");
			printf("6.Вывод элементов на экран.\n");
			printf("7.Выйти в главное меню.\n");
	   		
	   		//ввод выбора пользователя
	   		printf("\nВыберите номер: ");		
			scanf("%d", &sortChoice);
			
			//если пользователь ввел 7
			//то выходим в главное меню
			//и возвращаем массив
			if (sortChoice == 7)
			{
				printf("\nВыходим в главное меню...\n");
				printf("\nЗавершено!\n");
				return head;
			} 
			//если пользователь ввел число не из меню,
			//то вывводим сообщение об ошибке
	   		else if ((sortChoice < 1) || (sortChoice > 7))
				printf("\nНеправильный ввод. Пожалуйста, введите номер из меню.\n");
			//если введено 6, то выводим массив на экран
			//и возвращаемся в начало, т.е. опять показываем меню
			else if (sortChoice == 6) {
				printf("\n");
				subjectPrint(head, sizeSubject, 1);
				goto start;
			}	
			
		} while ((sortChoice < 1) || (sortChoice > 7));
		
		//если пользователь выбрал, по какому параметру
	   	//он хочет сортировать предметы,
	   	//то выводим вид сортировок
		do
		{
			//меню
			printf("\n1.Сортировка по убыванию;\n");
			printf("2.Сортировка по возрастанию;\n");
			printf("3.Назад;\n");
			printf("4.Выйти в главное меню.\n");	
			
			//ввод выбора пользователя
			printf("\nВведите номер: ");		
			scanf("%d", &sortChoiceTwo);
				
			//если пользователь ввел 4
			//то выходим в главное меню
			//и возвращаем массив
			//если ввел 3, то возвращаемся к start'y,
			//т.е. возвращаемся назад к предыдущему меню
			if (sortChoiceTwo == 4)
			{
				printf("\nВыходим в главное меню...\n");
				printf("\nЗавершено!\n");
				return head;
			} else if (sortChoiceTwo == 3)
				goto start;
			//если пользователь ввел число не из меню,
			//то вывводим сообщение об ошибке
			else if ((sortChoiceTwo < 1) || (sortChoiceTwo > 4))
				printf("\nНеправильный ввод. Пожалуйста, введите номер из меню.\n");
				
		} while ((sortChoiceTwo < 1) || (sortChoiceTwo > 4));
		
		//в завимимости по какому параметру
		//пользователь хочет сортировать массив
		switch(sortChoice)
		{
			case 1: //сортировка имён
				//если пользователь ввел 1,
				//т.е. сортировка по убыванию, то
				//вызывается функция сортировки по убыванию
				//если пользователь ввел 0, то
				//идем на else и вызываем
				//функцию сортировки по возрастанию
				//после того, как массив отсортировался
				//сразу же выводим его на экран
				if (sortChoiceTwo == 1) {
					sortDescendingName(head);
					printf("\n");
					subjectPrint(head, sizeSubject, 1);
				} else {
					sortAscendingName(head);
					printf("\n");
					subjectPrint(head, sizeSubject, 1);
				}
				break;
			case 2: //сортировка годов
				//делает тоже самое, что и в case 1
				if (sortChoiceTwo == 1) {
					sortDescendingYear(head);
					printf("\n");
					subjectPrint(head, sizeSubject, 1);
				} else {
					sortAscendingYear(head);
					printf("\n");
					subjectPrint(head, sizeSubject, 1);
				}
				break;
			case 3: //сортировка факультетов
				//делает тоже самое, что и в case 1
				if (sortChoiceTwo == 1) {
					sortDescendingFaculty(head);
					printf("\n");
					subjectPrint(head, sizeSubject, 1);
				} else {
					sortAscendingFaculty(head);
					printf("\n");
					subjectPrint(head, sizeSubject, 1);
				}
				break;
			case 4:	//сортировка кафедр
				//делает тоже самое, что и в case 1
				if (sortChoiceTwo == 1) {
					sortDescendingCathedra(head);
					printf("\n");
					subjectPrint(head, sizeSubject, 1);
				} else {
					sortAscendingCathedra(head);
					printf("\n");
					subjectPrint(head, sizeSubject, 1);
				}
				break;
			case 5: //сортировка по часам
				//делает тоже самое, что и в case 1
				if (sortChoiceTwo == 1) {
					sortDescendingHours(head);
					printf("\n");
					subjectPrint(head, sizeSubject, 1);
				} else {
					sortAscendingHours(head);
					printf("\n");
					subjectPrint(head, sizeSubject, 1);
				}
				break;						
		}
		
		//когда массив отсортировался и был выведен на экран,
		//возвращаемся к началу	
		goto start;
	} else {
		printf("\nОшибка. Слишком мало предметов или список не существует.\n");
		printf("Сортировку можно использовать, если предметов больше одного.\n");
	}
	
	return head;
}


//редактирование массива
typeSubject* editElem(typeSubject* head, int sizeSubject)
{
	//проверяем существует ли массив,
	//если да, то заходим в тело if'a
	//если нет, то выдаем сообщение об ошибке
	//и возвращаем массив
	if (arrayExist) {
		int editChoice; 		//выбор пользователя: параметр
		int editChoiceTwo;  	//выбор пользователя: элемент
	         
		printf("\nВы выбрали: редактирование элемента.\n");  
			
	   	start:
		
		//пока пользователь не захочет выйти в главное меню
		//будет выскакивать меню
	   	do
	   	{
	   		//меню
	   		printf("\n1.Редактирование имени;\n");
			printf("2.Редактирование года;\n");
			printf("3.Редактирование факультета;\n");
			printf("4.Редактирование кафедры;\n");
			printf("5.Редактирование количества часов;\n");
			printf("6.Вывод элементов на экран;\n");
	   		printf("7.Выход в главное меню.\n");
	   		
	   		//ввод выбора пользователя
	   		printf("\nВведите номер: ");		
			scanf("%d", &editChoice);
			
			//если введено 7, то выходим в главное меню
			//и возвращаем массив
			if (editChoice == 7) {
				printf("\nВыходим в главное меню...\n");
				printf("\nЗавершено!\n");
				return head;
			//если введено 6, то выводим массив на экран
			//и возвращаемся в начало, т.е. опять показываем меню
			} else if (editChoice == 6) {
				printf("\n");
				subjectPrint(head, sizeSubject, 1);
				goto start;
			}
			//если пользователь ввел число не из меню,
			//то вывводим сообщение об ошибке
	   		else if ((editChoice < 1) || (editChoice > 7))
				printf("\nНеправильный ввод. Пожалуйста, введите номер из меню.\n");

		} while ((editChoice < 1) || (editChoice > 7));
		
		
		//пока пользователь не захочет выйти в главное меню
		//или вернуться назад в предыдущее меню,
		//будет выскакивать меню
		do
	   	{
	   		//меню
			printf("\nВыберите номер элемента, который вы хотите редактировать.");
			printf("Всего %d предмет(ов):\n", sizeSubject);
			
			//выводит меню с соответствии сколько существует предметов
			for (int i = 0; i < sizeSubject; i++)
				printf("%d.%d элемент;\n", i, i + 1);
				
			printf("%d.Назад;\n", sizeSubject);
			printf("%d.Выйти в главное меню.\n", sizeSubject + 1);
			
			//ввод выбора пользователя
			printf("\nВведите номер: ");		
			scanf("%d", &editChoiceTwo);
			
			//если пользователя ввел число, которое больше 
			//количества предметов на два, то
			//выходим в главное меню и возвращаем массив
			if (editChoiceTwo == sizeSubject + 1)
			{
				printf("\nВыходим в главное меню...\n");
				printf("\nЗавершено!\n");
				return head;
			//если пользователя ввел число равное количеству предметов на единицу,
			//то возвращаемся к началу, т.е. показываем первое меню
			} else if (editChoiceTwo == sizeSubject)
				goto start;
			//если пользователь ввел число не из меню,
			//то вывводим сообщение об ошибке
			else if ((editChoiceTwo < 0) || (editChoiceTwo > sizeSubject + 1))
				printf("\nНеправильный ввод. Пожалуйста, введите номер из меню.\n");
				
		} while ((editChoiceTwo < 0) || (editChoiceTwo > sizeSubject + 1));
	
		//если пользователь ввел какой параметр и номер элемента,
		//то в соответствии от ввода, выполняются case'ы
		switch(editChoice)
		{
			case 1: 	//редактирование названия
				//доходим до нужного элемента
				node = head;
				for (int i = 0; i < editChoiceTwo; i++)
					node = node->next;
				printf("Название %d предмета: %s\n", editChoiceTwo + 1, node->name);
				
				//просим ввести новое значение
				//новое значение заменяет старое
				printf("Введите название предмета: ");
				scanf("%s", node->name);
				break;
			case 2: 	//редактирование года
				//делаем тоже самое,что в case 1
				node = head;
				for (int i = 0; i < editChoiceTwo; i++)
					node = node->next;
				printf("Год %d предмета: %d\n", editChoiceTwo + 1, node->year);
				printf("Введите новый год: ");
				scanf("%d", &node->year);
				break;
			case 3: 	//редактирование факультета
				//делаем тоже самое,что в case 1
				node = head;
				for (int i = 0; i < editChoiceTwo; i++)
					node = node->next;
				printf("Факультет %d предмета: %s\n", editChoiceTwo + 1, node->faculty);
				printf("Введите новое название факультета: ");
				scanf("%s", node->faculty);
				break;
			case 4:		//редактирование кафедры
				//делаем тоже самое,что в case 1
				node = head;
				for (int i = 0; i < editChoiceTwo; i++)
					node = node->next;
				printf("Кафедра %d предмета: %s\n", editChoiceTwo + 1, node->cathedra);
				printf("Введите новое назавние кафедры: ");
				scanf("%s", node->cathedra);
				break;
			case 5:		//редактирование часов
				//делаем тоже самое,что в case 1
				node = head;
				for (int i = 0; i < editChoiceTwo; i++)
					node = node->next;
				printf("Количество часов %d предмета: %d\n", editChoiceTwo + 1, node->hours);
				printf("Введите новое количество часов: ");
				scanf("%d", &node->hours);
				break;
		}
		
		//значение изменилось, поэтому возвращаемся к 1 меню
		goto start;
	} else 
		printf("\nОшибка. Список не существует. Введите cписок с клавиатуры.\n");
		
	return head;
}


//обмен узлами
typeSubject* exchangeElem(typeSubject *head, int sizeSubject)
{
	//проверяем существует ли массив,
	//если да, то заходим в тело if'a
	//если нет, то выдаем сообщение об ошибке
	//и возвращаем массив
	if (arrayExist) {
	    
		printf("\nВы выбрали: обмен элементов.\n");  
			  		
		int exchangeChoice; 							//выбор пользователя: 1 элемент
		int exchangeChoiceTwo;  						//выбор пользователя: 2 элемент
	    typeSubject *firstElem, *secondElem;			//временная переменная, 1 и 2 элементы	
		
	   	start:

		//пока пользователь не захочет выйти в главное меню
		//будет выскакивать меню
	   	do
	   	{
	   		//меню
	   		printf("\nВыберите номер элемента, который вы хотите обменять.");
	   		printf("Всего %d предмет(ов):\n", sizeSubject);
	   		
	   		for (int i = 0; i < sizeSubject; i++)
				printf("%d.%d элемент;\n", i, i + 1);
	
			printf("%d.Вывод элементов на экран.\n", sizeSubject);
			printf("%d.Выйти в главное меню.\n", sizeSubject + 1);
	   		
	   		//ввод выбора пользователя
	   		printf("\nВведите номер: ");		
			scanf("%d", &exchangeChoice);
			
			//если пользователя ввел число, которое больше 
			//количества предметов на два, то
			//выходим в главное меню и возвращаем массив
			if (exchangeChoice == sizeSubject + 1)
			{
				printf("\nВыходим в главное меню...\n");
				printf("\nЗавершено!\n");
				return head;
			}
			//если пользователя ввел число, которое больше 
			//количества предметов на единицу, то
			//печатаем массив и показываем меню
			else if (exchangeChoice == sizeSubject) {
				printf("\n");
				subjectPrint(head, sizeSubject, 1);
				goto start;
			}
			//если пользователь ввел число не из меню,
			//то вывводим сообщение об ошибке
			else if ((exchangeChoice < 0) || (exchangeChoice > sizeSubject + 1))
				printf("\nНеправильный ввод. Пожалуйста, введите номер из меню.\n");
				
		} while ((exchangeChoice < 0) || (exchangeChoice > sizeSubject + 1));
		
		middle:
		
		//пока пользователь не захочет выйти в главное меню
		//будет выскакивать меню
	   	do
	   	{
	   		//меню
	   		printf("\nВыберите номер элемента c которым вы хотите совершить обмен.");	
			printf("Всего %d предмет(ов):\n", sizeSubject);
			
	   		for (int i = 0; i < sizeSubject; i++)
				printf("%d.%d элемент;\n", i, i + 1);
			
			printf("%d.Вывод элементов на экран.\n", sizeSubject);
			printf("%d.Назад\n", sizeSubject + 1);
			printf("%d.Выйти в главное меню.\n", sizeSubject + 2);
			
	   		//ввод выбора пользователя
	   		printf("\nВведите номер: ");		
			scanf("%d", &exchangeChoiceTwo);
			
			//если пользователя ввел число, которое больше 
			//количества предметов на три, то
			//выходим в главное меню и возвращаем массив
			if (exchangeChoiceTwo == sizeSubject + 2) {
				printf("\nВыходим в главное меню...\n");
				printf("\nЗавершено!\n");
				return head;
			}
			//если пользователя ввел число, которое больше 
			//количества предметов на два, то
			//то возвращаемся к началу, т.е. показываем первое меню
			else if (exchangeChoiceTwo == sizeSubject + 1)
				goto start;		
			//если пользователя ввел число, которое больше 
			//количества предметов на единицу, то
			//печатаем массив и показываем меню
			else if (exchangeChoiceTwo == sizeSubject) {
				printf("\n");
				subjectPrint(head, sizeSubject, 1);
				goto middle;
			} //если пользователь ввел число не из меню,
			//то вывводим сообщение об ошибке
			else if ((exchangeChoiceTwo < 0) || (exchangeChoiceTwo > sizeSubject + 2))
				printf("\nНеправильный ввод. Пожалуйста, введите номер из меню.\n");
			
		} while ((exchangeChoiceTwo < 0) || (exchangeChoiceTwo > sizeSubject + 2));
		
		//если один элемент в массиве или ввели номера
		//одинаковых элементы, то ничего не делаем
		if (exchangeChoiceTwo == exchangeChoice) {
			printf("\nОшибка. Одинаковые элементы нельзя менять или у вас в списоке всего один элемент.\n");
			goto start;
		} 
		
		firstElem = head;
		secondElem = head;
		
		for (int i = 0; i < exchangeChoice; i++)
			firstElem = firstElem->next;
			
		for (int i = 0; i < exchangeChoiceTwo; i++)
			secondElem = secondElem->next;
			
		swap(head, firstElem, secondElem);
		
		printf("\nОбмен совершен.\n");
		
		goto start;
	} else
		printf("\nОшибка. Список не существует. Введите список с клавиатуры.\n");
		
	return head;
}


typeSubject* addElem(typeSubject* head, int* sizeSubject)
{
	//проверяем существует ли массив,
	//если да, то заходим в тело if'a
	//если нет, то выдаем сообщение об ошибке
	//и возвращаем массив
	if (arrayExist) {
		int addChoice; 	//выбор пользователя
		
		printf("\nВы выбрали: добавление нового элемента в конец.\n");
			 	
		start:
		
		//пока пользователь не захочет выйти в главное меню
		//будет выскакивать меню
		do
		{
		   	//меню
		   	printf("\n1.Продолжить;\n");
		   	printf("2.Вывод элементов на экран;\n");
		   	printf("3.Выход в главное меню.\n");
	
		   	printf("\nВведите номер: ");		
			scanf("%d", &addChoice);
			
			//если пользовател
			if (addChoice == 3)
			{
				printf("\nВыходим в главное меню...\n");
				printf("\nЗавершено!\n");
				return head;
			} else if ((addChoice < 1) || (addChoice > 3)) {
				printf("\nНеправильный ввод. Пожалуйста, введите номер из меню.\n");
				goto start;
			} else if (addChoice == 2) {
				printf("\n");
				subjectPrint(head, *sizeSubject, 1);
				goto start;
			}
				
			head = miniAddElem(*sizeSubject, head, sizeSubject); 	//функция добавления элемента
			
		} while ((addChoice < 1) || (addChoice > 3));
			
		printf("\nЭлемент был успешно добавлен!\n");
		
		//добавили предмет и возвращаемся в меню
		goto start;
	} else 
		printf("\nОшибка. Массив не существует. Введите список с клавиатуры.\n");
	
	return head;
}


typeSubject* deleteTargetElem(typeSubject* head, int* sizeSubject)
{
	//если массив существует, то выводим на экран
	//если нет, то выдаем сообщение об ошибке
	//и возвращаем массив
	if (arrayExist) {
	
	   	printf("\nВы выбрали: удаление указанного элемента.\n");
	   	
	   	int deleteChoice; 			//выбор пользователя
	   	typeSubject* target;		//нужный элемент
	   	
	   	start:
		
		//если количество предметов равно 0,
		//то сразу выходим в главное меню
		if (*sizeSubject == 0) {
			printf("\nВ списоке больше нет элементов, поэтому мы перенесем вас в главное меню.\n");
			printf("\nВыходим в главное меню...\n");
			arrayExist = false;
			memoryAllocate = false;
			delete head;
			head = NULL;
			return head;
		}
		
		//пока пользователь не захочет выйти в главное меню
		//будет выскакивать меню
		do
	   	{
	   		//меню
	   		printf("\n1.Продолжить;\n");
	   		printf("2.Вывод элементов на экран;\n");
	   		printf("3.Выход в главное меню.\n");
	   		
	   		//ввод выбора пользователя
	   		printf("\nВведите номер: ");		
			scanf("%d", &deleteChoice);
			
			//если введено 3, то выходим в главное меню 
			//и возвращаем массив
			if (deleteChoice == 3)
			{
				printf("\nВыходим в главное меню...\n");
				printf("\nЗавершено!\n");
				return head;
			//если введено цифра не из меню, 
			//то выдаем сообщение об ошибке
			//и снова показываем меню
			} else if ((deleteChoice < 1) || (deleteChoice > 3)) {
				printf("\nНеправильный ввод. Пожалуйста, введите номер из меню.\n");
				goto start;
			//если введено 2, то печатаем массив на экране
			//и снова показываем меню
			} else if (deleteChoice == 2) {
				printf("\n");
				subjectPrint(head, *sizeSubject, 1);
				goto start;
			}
			
		} while ((deleteChoice < 1) || (deleteChoice > 3));
		
		//пока пользователь не захочет выйти в главное меню
		//будет выскакивать меню
		do
	   	{	   		
	   		//меню
			printf("\nВыберите номер элемента, который хотите удалить.");
			printf("Всего %d предмет(ов):\n", *sizeSubject);
			
			//выводит меню с соответствии сколько существует предметов
			for (int i = 0; i < *sizeSubject; i++)
				printf("%d.%d элемент;\n", i, i + 1);
					
			printf("%d.Назад;\n", *sizeSubject);
			printf("%d.Выйти в главное меню.\n", *sizeSubject + 1);
				
			printf("\nВведите номер: ");		
			scanf("%d", &deleteChoice);
			
			//если пользователь ввел число не из меню,
			//то вывводим сообщение об ошибке	
			if ((deleteChoice < 0) || (deleteChoice > *sizeSubject + 1))
				printf("\nНеправильный ввод. Пожалуйста, введите номер из меню.\n");
			//если пользователь ввел число, которое больше 
			//количества предметов на единицу, то
			//выходим в главное меню и возвращаем массив
			else if (deleteChoice == *sizeSubject + 1)
			{
				printf("\nВыходим в главное меню...\n");
				printf("\nЗавершено!\n");
				return head;
			//если пользователь ввел число равное количеству предметов,
			//то возвращаемся к началу, т.е. показываем первое меню
			} else if (deleteChoice == *sizeSubject)
				goto start;
				   		
		} while ((deleteChoice < 0) || (deleteChoice > *sizeSubject + 1));
		
		node = head;
		target = head;
		for (int i = 0; i < deleteChoice; i++)
			target = target->next;
		
		if (target == head) {
			head = target->next;
			target->next->prev = NULL;
			goto end;
		}
		
		while (node->next != target)
			node = node->next;
		
		if (target == NULL) {
			node->next = NULL;
			goto end;
		}
		
		node->next = target->next;
		target->next->prev = node;
		
		end:
			
		delete target;
		--*sizeSubject;
		
		printf("\nЭлемент был успешно удален!\n");
		
		//удалили элемент и показываем первое меню
		goto start;
	} else 
		printf("\nОшибка. Список не существует. Введите список с клавиатуры.\n");
		
	return head;
}


//вставка элемента
typeSubject* addNewElem(typeSubject* head, int* sizeSubject)
{
	//если массив существует, то выводим на экран
	//если нет, то выдаем сообщение об ошибке
	//и возвращаем массив
	if (arrayExist) {
	  	int addNewChoice; 		//выбор пользователя: способ
		int addNewChoiceTwo; 	//выбор пользователя: позиция
	   	
	   	printf("\nВы выбрали: вставка элемента.\n");
	   	
	   	start:
		
		//пока пользователь не захочет выйти в главное меню
		//будет выскакивать меню
		do
	   	{
	   		//меню
	   		printf("\n1.Перед каким-либо элементом;\n");
	   		printf("2.После какого-либо элемента;\n");
	   		printf("3.В начало.\n");
	   		printf("4.В конец.\n");
	   		printf("5.Вывод элементов на экран.\n");
	   		printf("6.Выйти в главное меню.\n");
	   		
	   		//ввод выбора пользователя
	   		printf("\nВведите номер: ");		
			scanf("%d", &addNewChoice);
			
			//если пользователь ввел 6, то
			//выходим в главное меню и возвращаем массив
			if (addNewChoice == 6) {
				printf("\nВыходим в главное меню...\n");
				printf("\nЗавершено!\n");
				return head;
			//если пользователь ввел 5,
			//то печатаем массив и показываем меню
			} else if (addNewChoice == 5) {
				printf("\n");
				subjectPrint(head, *sizeSubject, 1);
				goto start;
			//если пользователь ввел число не из меню,
			//то вывводим сообщение об ошибке	
			} else if ((addNewChoice < 1) || (addNewChoice > 6)) {
				printf("\nНеправильный ввод. Пожалуйста, введите номер из меню.\n");
				goto start;
			} 
				
		} while ((addNewChoice < 1) || (addNewChoice > 6));
	
		//если ввел 3, то вызываем функцию 
		//и добавляем в начало
		if (addNewChoice == 3) {
			head = miniAddElem(0, head, sizeSubject);	
			goto end;
		//если ввел 4, то вызываем функцию 
		//и добавляем в конец
		} else if (addNewChoice == 4) {
			head = miniAddElem(*sizeSubject, head, sizeSubject);	
			goto end;
		}
		
		middle:
		
		//пока пользователь не захочет выйти в главное меню
		//будет выскакивать меню	
		do
	   	{
	   		//меню
	   		printf("\nВыберите номер элемента, после которого хотите вставить новый элемент.");
			printf("Всего %d предмет(ов):\n", *sizeSubject);
			
			//выводит меню с соответствии сколько существует предметов
			for (int i = 0; i < *sizeSubject; i++)
				printf("%d.%d элемент;\n", i, i + 1);
				
			printf("%d.Назад;\n", *sizeSubject);
			printf("%d.Выйти в главное меню.\n", *sizeSubject + 1);
	   		
	   		//ввод выбора пользователя
	   		printf("\nВведите номер: ");		
			scanf("%d", &addNewChoiceTwo);
			
			//если пользователь ввел число, которое больше 
			//количества предметов на единицу, то
			//выходим в главное меню и возвращаем массив
			if (addNewChoiceTwo == *sizeSubject + 1) {
				printf("\nВыходим в главное меню...\n");
				printf("\nЗавершено!\n");
				return head;		
			//если пользователь ввел число не из меню,
			//то вывводим сообщение об ошибке и показываем заново меню
			} else if ((addNewChoiceTwo < 0) || (addNewChoiceTwo > *sizeSubject + 1)) {
				printf("\nНеправильный ввод. Пожалуйста, введите номер из меню.\n");
				goto middle;
			//если пользователь ввел число равное количеству предметов,
			//то возвращаемся к началу, т.е. показываем первое меню
			} else if (addNewChoiceTwo == *sizeSubject) 
				goto start;
			
		} while ((addNewChoiceTwo < 0) || (addNewChoiceTwo > *sizeSubject + 1));
		
		//от выбора метода зависит дальшейний исход
		switch(addNewChoice)
		{
			case 1: 	//добавление перед каким-либо элементом
				head = miniAddElem(addNewChoiceTwo, head, sizeSubject);
				break;
			case 2:		//добавление после какого-либо элемента
				head = miniAddElem(addNewChoiceTwo + 1, head, sizeSubject);
				break;
		}
		
		end:
			
		printf("\nЭлемент был успешно добавлен!\n");
		
		//добавили элемент и показываем первое меню
		goto start;	
	} else
		printf("\nОшибка. Список не существует. Введите список с клавиатуры.\n");
	
	return head;
}


void addressLast(typeSubject* head, int sizeSubject)
{
	if (arrayExist) {
		printf("\nВы выбрали: определение адреса последнего элемента.\n\n");
		
		node = head;
		
		for (int i = 0; i < sizeSubject - 1; i++) 
			node = node->next;
	
		printf ("Адреса последнего элемента = %p\n", node);
	} else
		printf("\nОшибка. Список не существует. Введите список с клавиатуры.\n");
}


//длина списка
int length(typeSubject* head) 
{
    typeSubject* current = head;
    int count = 0;
    while (current != NULL) 
    {
            count++;
            current = current->next;
    }
    return count;
}


void split(typeSubject*& head, typeSubject*& head1, typeSubject*& head2, int* sizeSubject, int* sizeSubject1, int* sizeSubject2)
{
	if (arrayExist) {
		int splitChoice; 		//выбор пользователя: способ
		int splitChoiceTwo; 	//выбор пользователя: позиция
	   	typeSubject *nextSecList, *node2;
	   	
	   	printf("\nВы выбрали: разделение списка на два.\n");
	   	
	   	start:
		
		//пока пользователь не захочет выйти в главное меню
		//будет выскакивать меню
		do
	   	{
	   		//меню
	   		printf("\n1.Продолжить;\n");
	   		printf("2.Вывод элементов на экран общего списка.\n");
	   		printf("3.Вывод элементов на экран 1-го списка.\n");
	   		printf("4.Вывод элементов на экран 2-го списка.\n");
	   		printf("5.Выйти в главное меню.\n");
	   		
	   		//ввод выбора пользователя
	   		printf("\nВведите номер: ");		
			scanf("%d", &splitChoice);
			
			//если пользователь ввел 5, то
			//выходим в главное меню и возвращаем массив
			if (splitChoice == 5) {
				printf("\nВыходим в главное меню...\n");
				printf("\nЗавершено!\n");
				return;
			//если пользователь ввел 2,
			//то печатаем массив и показываем меню
			} else if (splitChoice == 2 && arrayExist == true) {
				printf("\n");
				subjectPrint(head, *sizeSubject, 0);
				goto start;
			//если пользователь ввел 3,
			//то печатаем массив и показываем меню
			} else if (splitChoice == 3 && arrayExist1 == true) {
				printf("\n");
				subjectPrint(head1, *sizeSubject1, 0);
				goto start;
			//если пользователь ввел число не из меню,
			//то вывводим сообщение об ошибке	
			} else if ((splitChoice < 1) || (splitChoice > 5)) {
				printf("\nНеправильный ввод. Пожалуйста, введите номер из меню.\n");
				goto start;
			} 
			//если пользователь ввел 4,
			//то печатаем массив и показываем меню
			else if (splitChoice == 4 && arrayExist2 == true) {
				printf("\n");
				subjectPrint(head2, *sizeSubject2, 0);
				goto start;
			} else if (splitChoice == 1)
				goto middle;
			else {
				printf("\nОшибка. Список не существует. \n");
				goto start;
			}
				
		} while ((splitChoice < 1) || (splitChoice > 4));
		
		middle: 
		
		printf("\nВведите номер элемента, который будет последним в 1-ом списке: ");
		scanf("%d", &splitChoice);
		
		if (splitChoice != *sizeSubject - 1) {
			node = head;
			head1 = head;
			for (int i = 0; i < splitChoice; i++)
				node = node->next;
			
			nextSecList = node->next;
			nextSecList->prev = NULL;
			node->next = NULL;
			
		
			node = head1;
			*sizeSubject1 = 0;
			while (node != NULL)
			{
				++*sizeSubject1;
				node = node->next;
			}
			arrayExist1 = true;
			
			head2 = nextSecList;
			node2 = head2;
			*sizeSubject2 = 0;
			while (node2 != NULL)
			{
				++*sizeSubject2;
				node2 = node2->next;
			}
			
			arrayExist2 = true;
			
			head = NULL;
			*sizeSubject = 0;
			arrayExist = false;
		} else {
			printf("\nОшибка. Последний элемент списка не может быть последним 1-го.\n");
			goto middle;
		}
		
		printf("\nЗавершено!\n");
	} else	{
		printf("\nОшибка. Список не существует, т.к. Вы его не ввели");
		printf("с клавиатуры или Вы его разделили.\n");
	}
		
}


void unite(typeSubject*& head, typeSubject*& head1, typeSubject*& head2, int* sizeSubject, int* sizeSubject1, int* sizeSubject2)
{
	if (arrayExist1) {
		int uniteChoice; 	//выбор пользователя
		typeSubject *node2;
		
		printf("\nВы выбрали: слияние двух списков.\n");
		
		start:
		
		//пока пользователь не захочет выйти в главное меню
		//будет выскакивать меню
		do
	   	{
	   		//меню
			printf("\n1.Продолжить.\n");
			printf("2.Вывод элементов на экран общего списка.\n");
			printf("3.Вывод элементов на экран 1-го списка.\n");
			printf("4.Вывод элементов на экран 2-го списка.\n");
			printf("5.Выйти в главное меню.\n");
			
			//ввод выбора пользователя
			printf("\nВведите номер: ");		
			scanf("%d", &uniteChoice);	
			
			//если пользователь ввел 5, то
			//выходим в главное меню и возвращаем массив
			if (uniteChoice == 5) {
				printf("\nВыходим в главное меню...\n");
				printf("\nЗавершено!\n");
				return;
			//если пользователь ввел 2,
			//то печатаем массив и показываем меню
			} else if (uniteChoice == 2 && arrayExist == true) {
				printf("\n");
				subjectPrint(head, *sizeSubject, 0);
				goto start;
			//если пользователь ввел 3,
			//то печатаем массив и показываем меню
			} else if (uniteChoice == 3 && arrayExist1 == true) {
				printf("\n");
				subjectPrint(head1, *sizeSubject1, 0);
				goto start;
			//если пользователь ввел число не из меню,
			//то вывводим сообщение об ошибке	
			} else if ((uniteChoice < 1) || (uniteChoice > 5)) {
				printf("\nНеправильный ввод. Пожалуйста, введите номер из меню.\n");
				goto start;
			} 
			//если пользователь ввел 4,
			//то печатаем массив и показываем меню
			else if (uniteChoice == 4 && arrayExist2 == true) {
				printf("\n");
				subjectPrint(head2, *sizeSubject2, 0);
				goto start;
			} else if (uniteChoice == 1)
				goto middle;
			else {
				printf("\nОшибка. Список не существует. \n");
				goto start;
			}
				
		} while ((uniteChoice < 1) || (uniteChoice > 4));
		
		middle:
		
		head = head1;
		for (int i = 0; i < *sizeSubject1 - 1; i++) 
			head1 = head1->next;

		head1->next = head2;
		head2->prev = head1;
		
		*sizeSubject = *sizeSubject1 + *sizeSubject2;
		*sizeSubject1 = 0;
		*sizeSubject2 = 0;
		
		head1 = NULL;
		head2 = NULL;
		
		arrayExist = true;
		arrayExist1 = false;
		arrayExist2 = false;
		
		printf("\nЗавершено!\n");	
	} else
		printf("\nОшибка. Разделите список.\n");
}


//запись в файл
void writeFile(typeSubject* head, int sizeSubject)
{
	//если массив существует, то выводим на экран
	//если нет, то выдаем сообщение об ошибке
	if (arrayExist) {
		//открываем файл
		FILE *fp = fopen("subjects_info2.txt", "w");
		
		printf("\nВы выбрали: запись элементов в файл.\n");
		
		fprintf(fp, "|------------------------------------------------------");
		fprintf(fp, "-----------------------------------------------|\n");
		fprintf(fp, "|\t\t\t\t       Общее количество предметов: %-35d", sizeSubject);
		fprintf(fp, "|\n");
		fprintf(fp, "|---------------------------------------------------");
		fprintf(fp, "--------------------------------------------------|\n");
		fprintf(fp, "|    №    | \tНазвание      |  Год   |");		
		fprintf(fp, "   \tФакультет       |          Кафедра          |  Часы   |\n");
		fprintf(fp, "|------------------------------------------------------");
		fprintf(fp, "-----------------------------------------------|\n");
			
		int i = 0;
		node = head;
		do
		{
			fprintf (fp, "| %-5d  ", i);
			fprintf (fp, " | %-17s ", node->name);
		   	fprintf (fp, "| %-6d ", node->year);
		   	fprintf (fp, "| %-22s ",  node->faculty);
		   	fprintf (fp, "| %-25s ",  node->cathedra);
		   	fprintf (fp, "| %-7d |\n", node->hours);
		   	fprintf(fp, "|------------------------------------------------------");
			fprintf(fp, "-----------------------------------------------|\n");
				
			i++;
			node = node->next;
		} while (node != NULL);
	
		fclose(fp);
	
		
		//открываем файл
		FILE *fp2 = fopen("subjects_info3.txt", "w");

		node = head;
			
		fprintf (fp2, "%d\n", sizeSubject);
		do
		{
			fprintf (fp2, "\n%s\n%d\n%s\n%s\n%d", node->name, node->year,
			node->faculty, node->cathedra, node->hours);
		    	
			node = node->next;
		} while (node != NULL);
	
		fclose(fp2);
			
		printf("\nЗавершено!\n");
				
	} else	
		printf("\nОшибка. Список не существует. Введите список с клавиатуры.\n");
}


//чтение из файла
void readFile(typeSubject* head, int sizeSubject)
{
	//если массив существует, то выводим на экран
	//если нет, то выдаем сообщение об ошибке
	int i;
	FILE *fp = fopen("subjects_info2.txt", "r");	//открываем файл
	char buffer[255];								//то куда будет переведены данные из файла
	 	
	printf("\nВы выбрали: считывание элементов из файла.\n");
	 	
	//Если файл пустой, то выдаем сообщение об ошибке и возвращаем массив
	if (fp == NULL) {
		printf("\nОшибка. Невозможно открыть файл.\n");
		return;
	} else {
		printf("\nСодержание файла:\n");
		
		//присваим посимвольно с помощью fgetc в buffer
		//как только наткнемся на символ перевода строки, то
		//переприсваимваем его на символ конца строки
		//обнуляем i и начинаем сначала
		//это будет продолжаться до тех пор, пока
		//fgetc не вернет EOF(число 1, конец файла)
		//EOF вернет 1, 1 != 1, это ложно
		//значит выходим и закрываем файл
		while ((buffer[i] = fgetc(fp)) != EOF)
		{
			if (buffer[i] == '\n') {
	           	buffer[i] = '\0';
	           	printf("%s\n", buffer);
	           	i = 0;
	       	} else i++;
		}
	}
	
	//закрываем файл
	fclose(fp);
	printf("\nЗавершено!\n");
}


typeSubject* readDateFromFile(typeSubject* head, int* sizeSubject)
{
	if (!arrayExist && !arrayExist1) {
		//если массив существует, то выводим на экран
		//если нет, то выдаем сообщение об ошибке
		int i;
		FILE *fp = fopen("subjects_info3.txt", "r");	//открываем файл
		 	
		printf("\nВы выбрали: записать данные из файла в список.\n");
		 	
		//Если файл пустой, то выдаем сообщение об ошибке и возвращаем массив
		if (fp == NULL) {
			printf("\nОшибка. Невозможно открыть файл.\n");
			return head;
		} else {
			fscanf(fp, "%d\n", sizeSubject);
			
			//создаем голову
	    	head = new typeSubject;
			head->next = NULL;
			head->prev = NULL;
			
			//создаем узлы
			typeSubject *temp;
			node = head;
	    	for (int i = 0; i < *sizeSubject - 1; i++)
		 	{
		 		temp = node;
		 		node->next = new typeSubject;
		 		node = node->next;
		 		node->prev = temp;
		 		node->next = NULL;
		 	}
		 	
		 	node = head;
		 	
		 	while (fscanf(fp, "\n%s\n%d\n%s\n%s\n%d", node->name, &node->year, 
		        node->faculty, node->cathedra, &node->hours) != EOF) 
		        	node = node->next;

			memoryAllocate = true;
			arrayExist = true;
			
			printf("\nЗавершено!\n");
		}
		
		//закрываем файл
		fclose(fp);
	} else
		printf("\nОшибка. Список уже существует или вы разделили список.\n");
		
	return head;	
}


//вывод на экран
void subjectPrintMain(typeSubject* head, typeSubject* head1, typeSubject* head2, int sizeSubject, int sizeSubject1, int sizeSubject2)
{	
	int printChoice; 	//выбор пользователя
	
	printf("\nВы выбрали: вывод элементов на экран.\n");
	
	start:
		
	//меню
	printf("\n1.Вывод элементов на экран общего списка.\n");
	printf("2.Вывод элементов на экран 1-го списка.\n");
	printf("3.Вывод элементов на экран 2-го списка.\n");
	printf("4.Выйти в главное меню.\n");
	
	//ввод выбора пользователя
	printf("\nВведите номер: ");		
	scanf("%d", &printChoice);
	
	switch(printChoice)
	{
		case 1:
			if (arrayExist) 	
			    subjectPrint(head, sizeSubject, 0);
		    else {
		    	printf("\nОшибка. Список не существует. Выделите память, введите список с клавиатуры или ");
				printf("сделайте слияние 1-го и 2-го списков.\n");
			}
			goto start;
		case 2:
			if (arrayExist1) 	
			    subjectPrint(head1, sizeSubject1, 0);
			else
				printf("\nОшибка. Список не существует. Разделите список.\n");
			goto start;
		case 3:
			if (arrayExist2) 	
			    subjectPrint(head2, sizeSubject2, 0);
		    else
				printf("\nОшибка. Список не существует. Разделите список.\n");
			goto start;
		case 4:
			printf("\nВыходим в главное меню...\n");
			printf("\nЗавершено!\n");
			break;
		default:
			printf("\nОшибка. Вы не ввели номер из меню.\n");
			goto start;
	}
}


//освобождение памяти
void freeMemory(typeSubject*& head, typeSubject*& head1, typeSubject*& head2)
{
	//если память выделена, то освобождаем
	//если нет, то выдаем сообщение об ошибке
	if (memoryAllocate == true) {
		if (arrayExist) {
			while (head != NULL)
			{
				node = head;
				head = head->next;
				delete node;
				if (head != NULL)
					head->prev = NULL;		
			}
			head = NULL;
			arrayExist = false;
		}
		else {
			while (head1 != NULL)
			{
				node = head1;
				head1 = head1->next;
				delete node;
				if (head1 != NULL)
					head1->prev = NULL;	
			}
			head1 = NULL;
			
			while (head2 != NULL)
			{
				node = head2;
				head2 = head2->next;
				delete node;
				if (head2 != NULL)
					head2->prev = NULL;
			}
			head2 = NULL;
			
			arrayExist1 = false;
			arrayExist2 = false;
		}
		
		memoryAllocate = false;
		printf("\nПамять освобождена.\n");
	} else 
		printf("\nОшибка. Память не была выделена.\n");
}


//вспомогательные функции


void subjectPrint(typeSubject* head, int sizeSubject, int sortNumber)
{
	int printChoice;
	
	if (sortNumber)
		goto output;
		
	do
	{
		//меню
		printf("1.Сверху вниз;\n");
		printf("2.Снизу вверх.\n");
		printf("3.Назад.\n");
		
		//ввод выбора пользователя
		printf("\nВведите номер: ");		
		scanf("%d", &printChoice);
		
		if ((printChoice < 1) || (printChoice > 3))
			printf("\nНеправильный ввод. Пожалуйста, введите номер из меню.\n\n");
		else if (printChoice == 3)
			return;
		
	} while ((printChoice < 1) || (printChoice > 3));
	
	output:
		
	printf("|------------------------------------------------------");
	printf("-----------------------------------------------|\n");
	printf("|\t\t\t\t       Общее количество предметов: %-35d", sizeSubject);
	printf("|\n");
	printf("|---------------------------------------------------");
	printf("--------------------------------------------------|\n");
	printf("|    №    | \tНазвание      |  Год   |");		
	printf("   \tФакультет       |          Кафедра          |  Часы   |\n");
	printf("|------------------------------------------------------");
	printf("-----------------------------------------------|\n");
				
	int i = 0;
	node = head;
	
	if (sortNumber)
		goto output2;
	
	switch(printChoice)
	{
		case 1:
			output2:
				
			do
			{		
				printf ("| %-5d  ", i);
				printf (" | %-17s ", node->name);
			  	printf ("| %-6d ", node->year);
			   	printf ("| %-22s ",  node->faculty);
			   	printf ("| %-25s ",  node->cathedra);
			   	printf ("| %-7d |\n", node->hours);
				printf("|------------------------------------------------------");
				printf("-----------------------------------------------|\n");
				
				i++;
				node = node->next;
			} while (node != NULL);
			
			break;
		case 2:
			while (node->next != NULL)
		    	node = node->next;
				  
		  	do {
		    	printf ("| %-5d  ", i);
				printf (" | %-17s ", node->name);
			  	printf ("| %-6d ", node->year);
			   	printf ("| %-22s ",  node->faculty);
			   	printf ("| %-25s ",  node->cathedra);
			   	printf ("| %-7d |\n", node->hours);
				printf("|------------------------------------------------------");
				printf("-----------------------------------------------|\n");
				
				i++;
		    	node = node->prev; 
		    } while (node != NULL); 		
	}
	
	printf("\nЗавершено!\n");
}


//вывод определенного элемента
void print (typeSubject *node, int position)
{
	printf("\nТакое название найдено.\n");
	printf("Это предмет №%d. Информация о нем:\n\n", position - 1);
	printf("|---------------------------------------------------");
	printf("--------------------------------------------------|\n");
	printf("|    №    | \tНазвание      |  Год   |");		
	printf("   \tФакультет       |          Кафедра          |  Часы   |\n");
	printf("|------------------------------------------------------");
	printf("-----------------------------------------------|\n");
	printf ("| %-5d  ", position - 1);
	printf (" | %-17s ", node->name);
	printf ("| %-6d ", node->year);
	printf ("| %-22s ",  node->faculty);
	printf ("| %-25s ",  node->cathedra);
	printf ("| %-7d |\n", node->hours);
	printf("|------------------------------------------------------");
	printf("-----------------------------------------------|\n");
	printf("\n");	
}


//добавление элемента
typeSubject* miniAddElem(int position, typeSubject* head, int* sizeSubject)
{
	typeSubject *newElem, *nextNewElem, *nextNode;
		
	newElem = new typeSubject;
	
	printf("Название %d предмета: ", position + 1);
	scanf("%s", newElem->name);
		
	printf("Год %d предмета: ", position + 1);
	scanf("%d", &newElem->year);
		    	
	printf("Факультет %d предмета: ", position + 1);
	scanf("%s", newElem->faculty);
		    	
	printf("Кафедра %d предмета: ", position + 1);
	scanf("%s", newElem->cathedra);
		    	
	printf("Количество часов %d предмета: ", position + 1);
	scanf("%d", &newElem->hours);
	
	node = head;
		
	if (position == 0) {
		head->prev = newElem;
		head = newElem;
		newElem->next = node;
		newElem->prev = NULL;
		goto end;
	}
	
	if (position == *sizeSubject) {
		for (int i = 0; i < position - 1; i++)
			node = node->next;
		
		newElem->next = NULL;
		newElem->prev = node;
		node->next = newElem;
		goto end;
	}
	
	for (int i = 0; i < position - 1; i++)
		node = node->next;
	
	nextNode = node->next;
	node->next = newElem;
	newElem->prev = node;
	nextNode->prev = newElem;
	newElem->next = nextNode;
	
	end:
		
	++*sizeSubject;
	
	return head;
}


//сортировка по возратанию названий
void sortAscendingName(typeSubject*& head)
{
	typeSubject	*current;			//текущий элемент
	
	//метод пузырька
    for (int i = 0; i < length(head) - 1; i++) 
	{
		current = head;
        for (int j = 0; j < length(head) - 1 - i; j++) 
		{
            if (strcmp(current->name, current->next->name) > 0) {
				swap(head, current, current->next);
			} else 
				current = current->next;
        }
    }
}


//сортировка по возратанию годов
void sortAscendingYear(typeSubject*& head)
{
	typeSubject	*current;			//текущий элемент
	
	//метод пузырька
    for (int i = 0; i < length(head) - 1; i++) 
	{
		current = head;
        for (int j = 0; j < length(head) - 1 - i; j++) 
		{
            if (current->year > current->next->year) {
				swap(head, current, current->next);
			} else 
				current = current->next;
        }
    }
}


//сортировка по возратанию факультетов
void sortAscendingFaculty(typeSubject*& head)
{
	typeSubject	*current;			//текущий элемент
	
	//метод пузырька
    for (int i = 0; i < length(head) - 1; i++) 
	{
		current = head;
        for (int j = 0; j < length(head) - 1 - i; j++) 
		{
            if (strcmp(current->faculty, current->next->faculty) > 0) {
				swap(head, current, current->next);
			} else 
				current = current->next;
        }
    }
}



//сортировка по возратанию кафедр
void sortAscendingCathedra(typeSubject*& head)
{
	typeSubject	*current;			//текущий элемент
	
	//метод пузырька
    for (int i = 0; i < length(head) - 1; i++) 
	{
		current = head;
        for (int j = 0; j < length(head) - 1 - i; j++) 
		{
            if (strcmp(current->cathedra, current->next->cathedra) > 0) {
				swap(head, current, current->next);
			} else 
				current = current->next;
        }
    }
}


//сортировка по возратанию часов
void sortAscendingHours(typeSubject*& head)
{
	typeSubject	*current;			//текущий элемент
	
	//метод пузырька
    for (int i = 0; i < length(head) - 1; i++) 
	{
		current = head;
        for (int j = 0; j < length(head) - 1 - i; j++) 
		{
            if (current->hours > current->next->hours) {
				swap(head, current, current->next);
			} else 
				current = current->next;
        }
    }
}


//сортировка по возратанию названий
void sortDescendingName(typeSubject*& head)
{
	typeSubject	*current;			//текущий элемент
	
	//метод пузырька
    for (int i = 0; i < length(head) - 1; i++) 
	{
		current = head;
        for (int j = 0; j < length(head) - 1 - i; j++) 
		{
            if (strcmp(current->name, current->next->name) < 0) {
				swap(head, current, current->next);
			} else 
				current = current->next;
        }
    }
}


//сортировка по возратанию годов
void sortDescendingYear(typeSubject*& head)
{
	typeSubject	*current;			//текущий элемент
	
	//метод пузырька
    for (int i = 0; i < length(head) - 1; i++) 
	{
		current = head;
        for (int j = 0; j < length(head) - 1 - i; j++) 
		{
            if (current->year < current->next->year) {
				swap(head, current, current->next);
			} else 
				current = current->next;
        }
    }
}


//сортировка по возратанию факультетов
void sortDescendingFaculty(typeSubject*& head)
{
	typeSubject	*current;			//текущий элемент
	
	//метод пузырька
    for (int i = 0; i < length(head) - 1; i++) 
	{
		current = head;
        for (int j = 0; j < length(head) - 1 - i; j++) 
		{
            if (strcmp(current->faculty, current->next->faculty) < 0) {
				swap(head, current, current->next);
			} else 
				current = current->next;
        }
    }
}



//сортировка по возратанию кафедр
void sortDescendingCathedra(typeSubject*& head)
{
	typeSubject	*current;			//текущий элемент
	
	//метод пузырька
    for (int i = 0; i < length(head) - 1; i++) 
	{
		current = head;
        for (int j = 0; j < length(head) - 1 - i; j++) 
		{
            if (strcmp(current->cathedra, current->next->cathedra) < 0) {
				swap(head, current, current->next);
			} else 
				current = current->next;
        }
    }
}


//сортировка по возратанию часов
void sortDescendingHours(typeSubject*& head)
{
	typeSubject	*current;			//текущий элемент
	
	//метод пузырька
    for (int i = 0; i < length(head) - 1; i++) 
	{
		current = head;
        for (int j = 0; j < length(head) - 1 - i; j++) 
		{
            if (current->hours < current->next->hours) {
				swap(head, current, current->next);
			} else 
				current = current->next;
        }
    }
}


//меняет местами элементы
void swap(typeSubject*& head, typeSubject* firstElem, typeSubject* secondElem)
{
	typeSubject *prevElem1 = firstElem->prev;
	typeSubject *prevElem2 = secondElem->prev;
	typeSubject	*nextElem1 = firstElem->next; 
	typeSubject	*nextElem2 = secondElem->next;
	
	if (secondElem == nextElem1) { 
		secondElem->next = firstElem; 
		firstElem->prev = secondElem;
		firstElem->next = nextElem2;
		nextElem1->prev = prevElem1;
		if (prevElem1 != NULL)  
			prevElem1->next = secondElem;  
		else  
			head = secondElem;  
	} else if (firstElem == nextElem2) { 
		firstElem->next = secondElem;
		secondElem->prev = firstElem; 
		secondElem->next = nextElem1; 
		nextElem2->prev = prevElem2;
		if (prevElem2 != NULL) 
			prevElem2->next = firstElem;  
		else 
			head = firstElem; 
	} else { 
		firstElem->next = nextElem2; 
		firstElem->prev = prevElem2;
		secondElem->next = nextElem1;
		
		if (prevElem1 != NULL) {
			prevElem1->next = secondElem;
			secondElem->prev = prevElem1;
		} else {
			head = secondElem; 
			secondElem->prev = NULL;
		} 
			
		if (nextElem1 != NULL)  
			nextElem1->prev = secondElem;  

		if (prevElem2 != NULL) {
			prevElem2->next = firstElem; 
			firstElem->prev = prevElem2;
		} else {
			head = firstElem;
			firstElem->prev = NULL;
		} 
		
		if (nextElem2 != NULL)  
			nextElem2->prev = firstElem; 
	}
}
