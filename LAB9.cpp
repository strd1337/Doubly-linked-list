#include "LAB9.h"		//������� ��� ���������

typeSubject *head;      		//��������� �� ������ ������, ������� ����� �������� ��� ���������
typeSubject *node;              //������� �������
bool memoryAllocate = false; 	//��������: ���� �� �������� ������
bool arrayExist = false;		//��������: � ������ �� �����
bool arrayExist1 = false;		//��������: � ������ �� �����
bool arrayExist2 = false;		//��������: � ������ �� �����


//�������� �������

//��������� ������
typeSubject* createMemory(typeSubject *head, int *sizeSubject)              
{	
	if (memoryAllocate)		//��������� �������� ������, ���� ���, �� ��������
    	printf("\n������ ��� ��������.\n");
	else {
		printf("\n�� �������: ������������ ��������� ������.\n");
		
		printf("\n������� ���������� ���������: ");
    	//�� ������ "&", �.�. ������� ��������� ���������
   		scanf("%d", sizeSubject);
		
		//������� ������
    	head = new typeSubject;
		head->next = NULL;
		head->prev = NULL;
		
		//������� ����
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
		
    	memoryAllocate = true;			//������ ��������			
    	printf ("\n���������!\n");
	}
	
	return head;
}


//���� � ����������
typeSubject* inputKeyboard(typeSubject *head, int sizeSubject)     
{
	//��������� �������� ������, ���� ���,
	//�� ������ �������� � ���������� ������
	if (memoryAllocate && !arrayExist1) { 
	    printf("\n�� �������: ���� ��������� � ����������.\n");
		printf("\n���� ������:\n");

		node = head;
		//��� ������� �������� ������ ������
	  	for (int i = 0; i < sizeSubject; i++)
	 	{	
		   	printf("�������� %d ��������: ", i + 1);
		   	scanf("%s", node->name);
		
		   	printf("��� %d ��������: ", i + 1);
		   	scanf("%d", &node->year);
		    	
		   	printf("��������� %d ��������: ", i + 1);
		   	scanf("%s", node->faculty);
		    	
		   	printf("������� %d ��������: ", i + 1);
		   	scanf("%s", node->cathedra);
		    	
		   	printf("���������� ����� %d ��������: ", i + 1);
		   	scanf("%d", &node->hours);
		   	
			node = node->next;
		   	printf("\n");
		}
		
		arrayExist = true;		//������ ������
	} else 
		printf("\n������. ������ �� �������� ��� ���������� ������.\n");
	
	return head;
}


//���������� �������� � ����������� �� ��������
void searchLocationElement(typeSubject* head, int sizeSubject)
{
	//��������� ���������� �� ������, ���� ���, �� ������ ������ � ����������
	//� ������� ��������� �� ������
	if (arrayExist) {			
		int searchChoice;         		//����� ������������
		char locationChar[30]; 			//��� ����(������)
		int locationInt; 				//��� ���(�����)
		int position;					//������� ��������, ������� �������
		
		printf("\n�� �������: ����� ��������.\n");
		
		//���� ������������ �� ������� ����� � ������� ����
		//����� ����������� ����
		do
		{	
			int f = 0; 	//������ ��� ���������� ���� �� ������ ����������
			
			//����
			printf("1.������ ���;\n");
			printf("2.������ ���;\n");
			printf("3.������ ���������;\n");
			printf("4.������ �������;\n");
			printf("5.������ ���������� �����;\n");
			printf("6.����� � ������� ����.\n");
			
			//���� ������ ������������
			printf("\n������� ����� ��� ������: ");		
			scanf("%d", &searchChoice);
			
			//�� ������ ������������ ����� �������� ���������� ���
			//� ������� ������� strcmp ���� ������ ������
			//� ������� ������� getchar ��������� ������ �� ������������ ������ �����
			//� ������� ������� print ������������� ����� ���������� � ��������,
			//������� �� �����
			switch(searchChoice)
			{
				case 1: //���� �� ��������
					//������ ������������ ������, ��� �� ����� �����
					printf("\n������� �������� ��� ������: ");
					scanf("%s", locationChar);
					getchar();
					
					//��� �� �����, ���� ������� �������� � ���,
					//��� ���� ������������, ������������� ����������
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
				
					//���� f = 0, �������, ��� ������ �� �����
					if (!f)
						printf("\n����� �������� �� �������.\n\n");
						
					break;
				case 2: //���� �� ����
					//������ ��� ���� �����, ��� � case 1
					printf("\n������� ��� ��� ������: ");
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
						printf("\n����� ��� �� ������.\n\n");
						
					break;
				case 3: //���� �� ����������
					//������ ��� ���� �����, ��� � case 1
					printf("\n������� ��������� ��� ������: ");
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
						printf("\n����� ��������� �� ������.\n\n");
						
					break;
				case 4:
					//������ ��� ���� �����, ��� � case 1
					printf("\n������� ������� ��� ������: ");
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
						printf("\n����� ������� �� �������.\n\n");
						
					break;
				case 5:
					//������ ��� ���� �����, ��� � case 1
					printf("\n������� ���������� ����� ��� ������: ");
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
						printf("\n����� ���������� ����� �� �������.\n\n");
						
					break;
				case 6:
					printf("\n����� � ������� ����.\n");
					break;
				default:
					//���� ������������ ���� ����� �� �� ����,
					//�� ������� ��������� �� ������
					printf("\n������������ ����. ����������, ������� ����� �� ����.\n\n");
					break;
			}
	
		} while (searchChoice != 6);		
		printf("\n���������!\n");
	} else 
		printf("\n������. ������ �� ����������. ������� ������ � ����������.\n");
}


//���������� �������
typeSubject* sortArray(typeSubject* head, int sizeSubject)
{	
	//���� ������ ���������� � ��������� ������� > 1
	//�� ������� � ���� if
	//���� ������ �� ���������� ��� ��������� ������� <= 1
	//�� ������ ������ � ���������� ������
	if (sizeSubject > 1 && arrayExist == true) {
		int sortChoice;		//����� ������������: ��������
		int sortChoiceTwo;	//����� ������������: ��������/�����������
	   	
	   	printf("\n�� �������: ���������� ���������.\n");
	   	
	   	start:
	   	
	   	//���� ������������ �� ������� ����� � ������� ����
		//����� ����������� ����
		do
	   	{
	   		//����
	   		printf("\n1.���������� ���;\n");
			printf("2.���������� �����;\n");
			printf("3.���������� �����������;\n");
			printf("4.���������� ������;\n");
			printf("5.���������� �����;\n");
			printf("6.����� ��������� �� �����.\n");
			printf("7.����� � ������� ����.\n");
	   		
	   		//���� ������ ������������
	   		printf("\n�������� �����: ");		
			scanf("%d", &sortChoice);
			
			//���� ������������ ���� 7
			//�� ������� � ������� ����
			//� ���������� ������
			if (sortChoice == 7)
			{
				printf("\n������� � ������� ����...\n");
				printf("\n���������!\n");
				return head;
			} 
			//���� ������������ ���� ����� �� �� ����,
			//�� �������� ��������� �� ������
	   		else if ((sortChoice < 1) || (sortChoice > 7))
				printf("\n������������ ����. ����������, ������� ����� �� ����.\n");
			//���� ������� 6, �� ������� ������ �� �����
			//� ������������ � ������, �.�. ����� ���������� ����
			else if (sortChoice == 6) {
				printf("\n");
				subjectPrint(head, sizeSubject, 1);
				goto start;
			}	
			
		} while ((sortChoice < 1) || (sortChoice > 7));
		
		//���� ������������ ������, �� ������ ���������
	   	//�� ����� ����������� ��������,
	   	//�� ������� ��� ����������
		do
		{
			//����
			printf("\n1.���������� �� ��������;\n");
			printf("2.���������� �� �����������;\n");
			printf("3.�����;\n");
			printf("4.����� � ������� ����.\n");	
			
			//���� ������ ������������
			printf("\n������� �����: ");		
			scanf("%d", &sortChoiceTwo);
				
			//���� ������������ ���� 4
			//�� ������� � ������� ����
			//� ���������� ������
			//���� ���� 3, �� ������������ � start'y,
			//�.�. ������������ ����� � ����������� ����
			if (sortChoiceTwo == 4)
			{
				printf("\n������� � ������� ����...\n");
				printf("\n���������!\n");
				return head;
			} else if (sortChoiceTwo == 3)
				goto start;
			//���� ������������ ���� ����� �� �� ����,
			//�� �������� ��������� �� ������
			else if ((sortChoiceTwo < 1) || (sortChoiceTwo > 4))
				printf("\n������������ ����. ����������, ������� ����� �� ����.\n");
				
		} while ((sortChoiceTwo < 1) || (sortChoiceTwo > 4));
		
		//� ����������� �� ������ ���������
		//������������ ����� ����������� ������
		switch(sortChoice)
		{
			case 1: //���������� ���
				//���� ������������ ���� 1,
				//�.�. ���������� �� ��������, ��
				//���������� ������� ���������� �� ��������
				//���� ������������ ���� 0, ��
				//���� �� else � ��������
				//������� ���������� �� �����������
				//����� ����, ��� ������ ��������������
				//����� �� ������� ��� �� �����
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
			case 2: //���������� �����
				//������ ���� �����, ��� � � case 1
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
			case 3: //���������� �����������
				//������ ���� �����, ��� � � case 1
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
			case 4:	//���������� ������
				//������ ���� �����, ��� � � case 1
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
			case 5: //���������� �� �����
				//������ ���� �����, ��� � � case 1
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
		
		//����� ������ �������������� � ��� ������� �� �����,
		//������������ � ������	
		goto start;
	} else {
		printf("\n������. ������� ���� ��������� ��� ������ �� ����������.\n");
		printf("���������� ����� ������������, ���� ��������� ������ ������.\n");
	}
	
	return head;
}


//�������������� �������
typeSubject* editElem(typeSubject* head, int sizeSubject)
{
	//��������� ���������� �� ������,
	//���� ��, �� ������� � ���� if'a
	//���� ���, �� ������ ��������� �� ������
	//� ���������� ������
	if (arrayExist) {
		int editChoice; 		//����� ������������: ��������
		int editChoiceTwo;  	//����� ������������: �������
	         
		printf("\n�� �������: �������������� ��������.\n");  
			
	   	start:
		
		//���� ������������ �� ������� ����� � ������� ����
		//����� ����������� ����
	   	do
	   	{
	   		//����
	   		printf("\n1.�������������� �����;\n");
			printf("2.�������������� ����;\n");
			printf("3.�������������� ����������;\n");
			printf("4.�������������� �������;\n");
			printf("5.�������������� ���������� �����;\n");
			printf("6.����� ��������� �� �����;\n");
	   		printf("7.����� � ������� ����.\n");
	   		
	   		//���� ������ ������������
	   		printf("\n������� �����: ");		
			scanf("%d", &editChoice);
			
			//���� ������� 7, �� ������� � ������� ����
			//� ���������� ������
			if (editChoice == 7) {
				printf("\n������� � ������� ����...\n");
				printf("\n���������!\n");
				return head;
			//���� ������� 6, �� ������� ������ �� �����
			//� ������������ � ������, �.�. ����� ���������� ����
			} else if (editChoice == 6) {
				printf("\n");
				subjectPrint(head, sizeSubject, 1);
				goto start;
			}
			//���� ������������ ���� ����� �� �� ����,
			//�� �������� ��������� �� ������
	   		else if ((editChoice < 1) || (editChoice > 7))
				printf("\n������������ ����. ����������, ������� ����� �� ����.\n");

		} while ((editChoice < 1) || (editChoice > 7));
		
		
		//���� ������������ �� ������� ����� � ������� ����
		//��� ��������� ����� � ���������� ����,
		//����� ����������� ����
		do
	   	{
	   		//����
			printf("\n�������� ����� ��������, ������� �� ������ �������������.");
			printf("����� %d �������(��):\n", sizeSubject);
			
			//������� ���� � ������������ ������� ���������� ���������
			for (int i = 0; i < sizeSubject; i++)
				printf("%d.%d �������;\n", i, i + 1);
				
			printf("%d.�����;\n", sizeSubject);
			printf("%d.����� � ������� ����.\n", sizeSubject + 1);
			
			//���� ������ ������������
			printf("\n������� �����: ");		
			scanf("%d", &editChoiceTwo);
			
			//���� ������������ ���� �����, ������� ������ 
			//���������� ��������� �� ���, ��
			//������� � ������� ���� � ���������� ������
			if (editChoiceTwo == sizeSubject + 1)
			{
				printf("\n������� � ������� ����...\n");
				printf("\n���������!\n");
				return head;
			//���� ������������ ���� ����� ������ ���������� ��������� �� �������,
			//�� ������������ � ������, �.�. ���������� ������ ����
			} else if (editChoiceTwo == sizeSubject)
				goto start;
			//���� ������������ ���� ����� �� �� ����,
			//�� �������� ��������� �� ������
			else if ((editChoiceTwo < 0) || (editChoiceTwo > sizeSubject + 1))
				printf("\n������������ ����. ����������, ������� ����� �� ����.\n");
				
		} while ((editChoiceTwo < 0) || (editChoiceTwo > sizeSubject + 1));
	
		//���� ������������ ���� ����� �������� � ����� ��������,
		//�� � ������������ �� �����, ����������� case'�
		switch(editChoice)
		{
			case 1: 	//�������������� ��������
				//������� �� ������� ��������
				node = head;
				for (int i = 0; i < editChoiceTwo; i++)
					node = node->next;
				printf("�������� %d ��������: %s\n", editChoiceTwo + 1, node->name);
				
				//������ ������ ����� ��������
				//����� �������� �������� ������
				printf("������� �������� ��������: ");
				scanf("%s", node->name);
				break;
			case 2: 	//�������������� ����
				//������ ���� �����,��� � case 1
				node = head;
				for (int i = 0; i < editChoiceTwo; i++)
					node = node->next;
				printf("��� %d ��������: %d\n", editChoiceTwo + 1, node->year);
				printf("������� ����� ���: ");
				scanf("%d", &node->year);
				break;
			case 3: 	//�������������� ����������
				//������ ���� �����,��� � case 1
				node = head;
				for (int i = 0; i < editChoiceTwo; i++)
					node = node->next;
				printf("��������� %d ��������: %s\n", editChoiceTwo + 1, node->faculty);
				printf("������� ����� �������� ����������: ");
				scanf("%s", node->faculty);
				break;
			case 4:		//�������������� �������
				//������ ���� �����,��� � case 1
				node = head;
				for (int i = 0; i < editChoiceTwo; i++)
					node = node->next;
				printf("������� %d ��������: %s\n", editChoiceTwo + 1, node->cathedra);
				printf("������� ����� �������� �������: ");
				scanf("%s", node->cathedra);
				break;
			case 5:		//�������������� �����
				//������ ���� �����,��� � case 1
				node = head;
				for (int i = 0; i < editChoiceTwo; i++)
					node = node->next;
				printf("���������� ����� %d ��������: %d\n", editChoiceTwo + 1, node->hours);
				printf("������� ����� ���������� �����: ");
				scanf("%d", &node->hours);
				break;
		}
		
		//�������� ����������, ������� ������������ � 1 ����
		goto start;
	} else 
		printf("\n������. ������ �� ����������. ������� c����� � ����������.\n");
		
	return head;
}


//����� ������
typeSubject* exchangeElem(typeSubject *head, int sizeSubject)
{
	//��������� ���������� �� ������,
	//���� ��, �� ������� � ���� if'a
	//���� ���, �� ������ ��������� �� ������
	//� ���������� ������
	if (arrayExist) {
	    
		printf("\n�� �������: ����� ���������.\n");  
			  		
		int exchangeChoice; 							//����� ������������: 1 �������
		int exchangeChoiceTwo;  						//����� ������������: 2 �������
	    typeSubject *firstElem, *secondElem;			//��������� ����������, 1 � 2 ��������	
		
	   	start:

		//���� ������������ �� ������� ����� � ������� ����
		//����� ����������� ����
	   	do
	   	{
	   		//����
	   		printf("\n�������� ����� ��������, ������� �� ������ ��������.");
	   		printf("����� %d �������(��):\n", sizeSubject);
	   		
	   		for (int i = 0; i < sizeSubject; i++)
				printf("%d.%d �������;\n", i, i + 1);
	
			printf("%d.����� ��������� �� �����.\n", sizeSubject);
			printf("%d.����� � ������� ����.\n", sizeSubject + 1);
	   		
	   		//���� ������ ������������
	   		printf("\n������� �����: ");		
			scanf("%d", &exchangeChoice);
			
			//���� ������������ ���� �����, ������� ������ 
			//���������� ��������� �� ���, ��
			//������� � ������� ���� � ���������� ������
			if (exchangeChoice == sizeSubject + 1)
			{
				printf("\n������� � ������� ����...\n");
				printf("\n���������!\n");
				return head;
			}
			//���� ������������ ���� �����, ������� ������ 
			//���������� ��������� �� �������, ��
			//�������� ������ � ���������� ����
			else if (exchangeChoice == sizeSubject) {
				printf("\n");
				subjectPrint(head, sizeSubject, 1);
				goto start;
			}
			//���� ������������ ���� ����� �� �� ����,
			//�� �������� ��������� �� ������
			else if ((exchangeChoice < 0) || (exchangeChoice > sizeSubject + 1))
				printf("\n������������ ����. ����������, ������� ����� �� ����.\n");
				
		} while ((exchangeChoice < 0) || (exchangeChoice > sizeSubject + 1));
		
		middle:
		
		//���� ������������ �� ������� ����� � ������� ����
		//����� ����������� ����
	   	do
	   	{
	   		//����
	   		printf("\n�������� ����� �������� c ������� �� ������ ��������� �����.");	
			printf("����� %d �������(��):\n", sizeSubject);
			
	   		for (int i = 0; i < sizeSubject; i++)
				printf("%d.%d �������;\n", i, i + 1);
			
			printf("%d.����� ��������� �� �����.\n", sizeSubject);
			printf("%d.�����\n", sizeSubject + 1);
			printf("%d.����� � ������� ����.\n", sizeSubject + 2);
			
	   		//���� ������ ������������
	   		printf("\n������� �����: ");		
			scanf("%d", &exchangeChoiceTwo);
			
			//���� ������������ ���� �����, ������� ������ 
			//���������� ��������� �� ���, ��
			//������� � ������� ���� � ���������� ������
			if (exchangeChoiceTwo == sizeSubject + 2) {
				printf("\n������� � ������� ����...\n");
				printf("\n���������!\n");
				return head;
			}
			//���� ������������ ���� �����, ������� ������ 
			//���������� ��������� �� ���, ��
			//�� ������������ � ������, �.�. ���������� ������ ����
			else if (exchangeChoiceTwo == sizeSubject + 1)
				goto start;		
			//���� ������������ ���� �����, ������� ������ 
			//���������� ��������� �� �������, ��
			//�������� ������ � ���������� ����
			else if (exchangeChoiceTwo == sizeSubject) {
				printf("\n");
				subjectPrint(head, sizeSubject, 1);
				goto middle;
			} //���� ������������ ���� ����� �� �� ����,
			//�� �������� ��������� �� ������
			else if ((exchangeChoiceTwo < 0) || (exchangeChoiceTwo > sizeSubject + 2))
				printf("\n������������ ����. ����������, ������� ����� �� ����.\n");
			
		} while ((exchangeChoiceTwo < 0) || (exchangeChoiceTwo > sizeSubject + 2));
		
		//���� ���� ������� � ������� ��� ����� ������
		//���������� ��������, �� ������ �� ������
		if (exchangeChoiceTwo == exchangeChoice) {
			printf("\n������. ���������� �������� ������ ������ ��� � ��� � ������� ����� ���� �������.\n");
			goto start;
		} 
		
		firstElem = head;
		secondElem = head;
		
		for (int i = 0; i < exchangeChoice; i++)
			firstElem = firstElem->next;
			
		for (int i = 0; i < exchangeChoiceTwo; i++)
			secondElem = secondElem->next;
			
		swap(head, firstElem, secondElem);
		
		printf("\n����� ��������.\n");
		
		goto start;
	} else
		printf("\n������. ������ �� ����������. ������� ������ � ����������.\n");
		
	return head;
}


typeSubject* addElem(typeSubject* head, int* sizeSubject)
{
	//��������� ���������� �� ������,
	//���� ��, �� ������� � ���� if'a
	//���� ���, �� ������ ��������� �� ������
	//� ���������� ������
	if (arrayExist) {
		int addChoice; 	//����� ������������
		
		printf("\n�� �������: ���������� ������ �������� � �����.\n");
			 	
		start:
		
		//���� ������������ �� ������� ����� � ������� ����
		//����� ����������� ����
		do
		{
		   	//����
		   	printf("\n1.����������;\n");
		   	printf("2.����� ��������� �� �����;\n");
		   	printf("3.����� � ������� ����.\n");
	
		   	printf("\n������� �����: ");		
			scanf("%d", &addChoice);
			
			//���� �����������
			if (addChoice == 3)
			{
				printf("\n������� � ������� ����...\n");
				printf("\n���������!\n");
				return head;
			} else if ((addChoice < 1) || (addChoice > 3)) {
				printf("\n������������ ����. ����������, ������� ����� �� ����.\n");
				goto start;
			} else if (addChoice == 2) {
				printf("\n");
				subjectPrint(head, *sizeSubject, 1);
				goto start;
			}
				
			head = miniAddElem(*sizeSubject, head, sizeSubject); 	//������� ���������� ��������
			
		} while ((addChoice < 1) || (addChoice > 3));
			
		printf("\n������� ��� ������� ��������!\n");
		
		//�������� ������� � ������������ � ����
		goto start;
	} else 
		printf("\n������. ������ �� ����������. ������� ������ � ����������.\n");
	
	return head;
}


typeSubject* deleteTargetElem(typeSubject* head, int* sizeSubject)
{
	//���� ������ ����������, �� ������� �� �����
	//���� ���, �� ������ ��������� �� ������
	//� ���������� ������
	if (arrayExist) {
	
	   	printf("\n�� �������: �������� ���������� ��������.\n");
	   	
	   	int deleteChoice; 			//����� ������������
	   	typeSubject* target;		//������ �������
	   	
	   	start:
		
		//���� ���������� ��������� ����� 0,
		//�� ����� ������� � ������� ����
		if (*sizeSubject == 0) {
			printf("\n� ������� ������ ��� ���������, ������� �� ��������� ��� � ������� ����.\n");
			printf("\n������� � ������� ����...\n");
			arrayExist = false;
			memoryAllocate = false;
			delete head;
			head = NULL;
			return head;
		}
		
		//���� ������������ �� ������� ����� � ������� ����
		//����� ����������� ����
		do
	   	{
	   		//����
	   		printf("\n1.����������;\n");
	   		printf("2.����� ��������� �� �����;\n");
	   		printf("3.����� � ������� ����.\n");
	   		
	   		//���� ������ ������������
	   		printf("\n������� �����: ");		
			scanf("%d", &deleteChoice);
			
			//���� ������� 3, �� ������� � ������� ���� 
			//� ���������� ������
			if (deleteChoice == 3)
			{
				printf("\n������� � ������� ����...\n");
				printf("\n���������!\n");
				return head;
			//���� ������� ����� �� �� ����, 
			//�� ������ ��������� �� ������
			//� ����� ���������� ����
			} else if ((deleteChoice < 1) || (deleteChoice > 3)) {
				printf("\n������������ ����. ����������, ������� ����� �� ����.\n");
				goto start;
			//���� ������� 2, �� �������� ������ �� ������
			//� ����� ���������� ����
			} else if (deleteChoice == 2) {
				printf("\n");
				subjectPrint(head, *sizeSubject, 1);
				goto start;
			}
			
		} while ((deleteChoice < 1) || (deleteChoice > 3));
		
		//���� ������������ �� ������� ����� � ������� ����
		//����� ����������� ����
		do
	   	{	   		
	   		//����
			printf("\n�������� ����� ��������, ������� ������ �������.");
			printf("����� %d �������(��):\n", *sizeSubject);
			
			//������� ���� � ������������ ������� ���������� ���������
			for (int i = 0; i < *sizeSubject; i++)
				printf("%d.%d �������;\n", i, i + 1);
					
			printf("%d.�����;\n", *sizeSubject);
			printf("%d.����� � ������� ����.\n", *sizeSubject + 1);
				
			printf("\n������� �����: ");		
			scanf("%d", &deleteChoice);
			
			//���� ������������ ���� ����� �� �� ����,
			//�� �������� ��������� �� ������	
			if ((deleteChoice < 0) || (deleteChoice > *sizeSubject + 1))
				printf("\n������������ ����. ����������, ������� ����� �� ����.\n");
			//���� ������������ ���� �����, ������� ������ 
			//���������� ��������� �� �������, ��
			//������� � ������� ���� � ���������� ������
			else if (deleteChoice == *sizeSubject + 1)
			{
				printf("\n������� � ������� ����...\n");
				printf("\n���������!\n");
				return head;
			//���� ������������ ���� ����� ������ ���������� ���������,
			//�� ������������ � ������, �.�. ���������� ������ ����
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
		
		printf("\n������� ��� ������� ������!\n");
		
		//������� ������� � ���������� ������ ����
		goto start;
	} else 
		printf("\n������. ������ �� ����������. ������� ������ � ����������.\n");
		
	return head;
}


//������� ��������
typeSubject* addNewElem(typeSubject* head, int* sizeSubject)
{
	//���� ������ ����������, �� ������� �� �����
	//���� ���, �� ������ ��������� �� ������
	//� ���������� ������
	if (arrayExist) {
	  	int addNewChoice; 		//����� ������������: ������
		int addNewChoiceTwo; 	//����� ������������: �������
	   	
	   	printf("\n�� �������: ������� ��������.\n");
	   	
	   	start:
		
		//���� ������������ �� ������� ����� � ������� ����
		//����� ����������� ����
		do
	   	{
	   		//����
	   		printf("\n1.����� �����-���� ���������;\n");
	   		printf("2.����� ������-���� ��������;\n");
	   		printf("3.� ������.\n");
	   		printf("4.� �����.\n");
	   		printf("5.����� ��������� �� �����.\n");
	   		printf("6.����� � ������� ����.\n");
	   		
	   		//���� ������ ������������
	   		printf("\n������� �����: ");		
			scanf("%d", &addNewChoice);
			
			//���� ������������ ���� 6, ��
			//������� � ������� ���� � ���������� ������
			if (addNewChoice == 6) {
				printf("\n������� � ������� ����...\n");
				printf("\n���������!\n");
				return head;
			//���� ������������ ���� 5,
			//�� �������� ������ � ���������� ����
			} else if (addNewChoice == 5) {
				printf("\n");
				subjectPrint(head, *sizeSubject, 1);
				goto start;
			//���� ������������ ���� ����� �� �� ����,
			//�� �������� ��������� �� ������	
			} else if ((addNewChoice < 1) || (addNewChoice > 6)) {
				printf("\n������������ ����. ����������, ������� ����� �� ����.\n");
				goto start;
			} 
				
		} while ((addNewChoice < 1) || (addNewChoice > 6));
	
		//���� ���� 3, �� �������� ������� 
		//� ��������� � ������
		if (addNewChoice == 3) {
			head = miniAddElem(0, head, sizeSubject);	
			goto end;
		//���� ���� 4, �� �������� ������� 
		//� ��������� � �����
		} else if (addNewChoice == 4) {
			head = miniAddElem(*sizeSubject, head, sizeSubject);	
			goto end;
		}
		
		middle:
		
		//���� ������������ �� ������� ����� � ������� ����
		//����� ����������� ����	
		do
	   	{
	   		//����
	   		printf("\n�������� ����� ��������, ����� �������� ������ �������� ����� �������.");
			printf("����� %d �������(��):\n", *sizeSubject);
			
			//������� ���� � ������������ ������� ���������� ���������
			for (int i = 0; i < *sizeSubject; i++)
				printf("%d.%d �������;\n", i, i + 1);
				
			printf("%d.�����;\n", *sizeSubject);
			printf("%d.����� � ������� ����.\n", *sizeSubject + 1);
	   		
	   		//���� ������ ������������
	   		printf("\n������� �����: ");		
			scanf("%d", &addNewChoiceTwo);
			
			//���� ������������ ���� �����, ������� ������ 
			//���������� ��������� �� �������, ��
			//������� � ������� ���� � ���������� ������
			if (addNewChoiceTwo == *sizeSubject + 1) {
				printf("\n������� � ������� ����...\n");
				printf("\n���������!\n");
				return head;		
			//���� ������������ ���� ����� �� �� ����,
			//�� �������� ��������� �� ������ � ���������� ������ ����
			} else if ((addNewChoiceTwo < 0) || (addNewChoiceTwo > *sizeSubject + 1)) {
				printf("\n������������ ����. ����������, ������� ����� �� ����.\n");
				goto middle;
			//���� ������������ ���� ����� ������ ���������� ���������,
			//�� ������������ � ������, �.�. ���������� ������ ����
			} else if (addNewChoiceTwo == *sizeSubject) 
				goto start;
			
		} while ((addNewChoiceTwo < 0) || (addNewChoiceTwo > *sizeSubject + 1));
		
		//�� ������ ������ ������� ���������� �����
		switch(addNewChoice)
		{
			case 1: 	//���������� ����� �����-���� ���������
				head = miniAddElem(addNewChoiceTwo, head, sizeSubject);
				break;
			case 2:		//���������� ����� ������-���� ��������
				head = miniAddElem(addNewChoiceTwo + 1, head, sizeSubject);
				break;
		}
		
		end:
			
		printf("\n������� ��� ������� ��������!\n");
		
		//�������� ������� � ���������� ������ ����
		goto start;	
	} else
		printf("\n������. ������ �� ����������. ������� ������ � ����������.\n");
	
	return head;
}


void addressLast(typeSubject* head, int sizeSubject)
{
	if (arrayExist) {
		printf("\n�� �������: ����������� ������ ���������� ��������.\n\n");
		
		node = head;
		
		for (int i = 0; i < sizeSubject - 1; i++) 
			node = node->next;
	
		printf ("������ ���������� �������� = %p\n", node);
	} else
		printf("\n������. ������ �� ����������. ������� ������ � ����������.\n");
}


//����� ������
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
		int splitChoice; 		//����� ������������: ������
		int splitChoiceTwo; 	//����� ������������: �������
	   	typeSubject *nextSecList, *node2;
	   	
	   	printf("\n�� �������: ���������� ������ �� ���.\n");
	   	
	   	start:
		
		//���� ������������ �� ������� ����� � ������� ����
		//����� ����������� ����
		do
	   	{
	   		//����
	   		printf("\n1.����������;\n");
	   		printf("2.����� ��������� �� ����� ������ ������.\n");
	   		printf("3.����� ��������� �� ����� 1-�� ������.\n");
	   		printf("4.����� ��������� �� ����� 2-�� ������.\n");
	   		printf("5.����� � ������� ����.\n");
	   		
	   		//���� ������ ������������
	   		printf("\n������� �����: ");		
			scanf("%d", &splitChoice);
			
			//���� ������������ ���� 5, ��
			//������� � ������� ���� � ���������� ������
			if (splitChoice == 5) {
				printf("\n������� � ������� ����...\n");
				printf("\n���������!\n");
				return;
			//���� ������������ ���� 2,
			//�� �������� ������ � ���������� ����
			} else if (splitChoice == 2 && arrayExist == true) {
				printf("\n");
				subjectPrint(head, *sizeSubject, 0);
				goto start;
			//���� ������������ ���� 3,
			//�� �������� ������ � ���������� ����
			} else if (splitChoice == 3 && arrayExist1 == true) {
				printf("\n");
				subjectPrint(head1, *sizeSubject1, 0);
				goto start;
			//���� ������������ ���� ����� �� �� ����,
			//�� �������� ��������� �� ������	
			} else if ((splitChoice < 1) || (splitChoice > 5)) {
				printf("\n������������ ����. ����������, ������� ����� �� ����.\n");
				goto start;
			} 
			//���� ������������ ���� 4,
			//�� �������� ������ � ���������� ����
			else if (splitChoice == 4 && arrayExist2 == true) {
				printf("\n");
				subjectPrint(head2, *sizeSubject2, 0);
				goto start;
			} else if (splitChoice == 1)
				goto middle;
			else {
				printf("\n������. ������ �� ����������. \n");
				goto start;
			}
				
		} while ((splitChoice < 1) || (splitChoice > 4));
		
		middle: 
		
		printf("\n������� ����� ��������, ������� ����� ��������� � 1-�� ������: ");
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
			printf("\n������. ��������� ������� ������ �� ����� ���� ��������� 1-��.\n");
			goto middle;
		}
		
		printf("\n���������!\n");
	} else	{
		printf("\n������. ������ �� ����������, �.�. �� ��� �� �����");
		printf("� ���������� ��� �� ��� ���������.\n");
	}
		
}


void unite(typeSubject*& head, typeSubject*& head1, typeSubject*& head2, int* sizeSubject, int* sizeSubject1, int* sizeSubject2)
{
	if (arrayExist1) {
		int uniteChoice; 	//����� ������������
		typeSubject *node2;
		
		printf("\n�� �������: ������� ���� �������.\n");
		
		start:
		
		//���� ������������ �� ������� ����� � ������� ����
		//����� ����������� ����
		do
	   	{
	   		//����
			printf("\n1.����������.\n");
			printf("2.����� ��������� �� ����� ������ ������.\n");
			printf("3.����� ��������� �� ����� 1-�� ������.\n");
			printf("4.����� ��������� �� ����� 2-�� ������.\n");
			printf("5.����� � ������� ����.\n");
			
			//���� ������ ������������
			printf("\n������� �����: ");		
			scanf("%d", &uniteChoice);	
			
			//���� ������������ ���� 5, ��
			//������� � ������� ���� � ���������� ������
			if (uniteChoice == 5) {
				printf("\n������� � ������� ����...\n");
				printf("\n���������!\n");
				return;
			//���� ������������ ���� 2,
			//�� �������� ������ � ���������� ����
			} else if (uniteChoice == 2 && arrayExist == true) {
				printf("\n");
				subjectPrint(head, *sizeSubject, 0);
				goto start;
			//���� ������������ ���� 3,
			//�� �������� ������ � ���������� ����
			} else if (uniteChoice == 3 && arrayExist1 == true) {
				printf("\n");
				subjectPrint(head1, *sizeSubject1, 0);
				goto start;
			//���� ������������ ���� ����� �� �� ����,
			//�� �������� ��������� �� ������	
			} else if ((uniteChoice < 1) || (uniteChoice > 5)) {
				printf("\n������������ ����. ����������, ������� ����� �� ����.\n");
				goto start;
			} 
			//���� ������������ ���� 4,
			//�� �������� ������ � ���������� ����
			else if (uniteChoice == 4 && arrayExist2 == true) {
				printf("\n");
				subjectPrint(head2, *sizeSubject2, 0);
				goto start;
			} else if (uniteChoice == 1)
				goto middle;
			else {
				printf("\n������. ������ �� ����������. \n");
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
		
		printf("\n���������!\n");	
	} else
		printf("\n������. ��������� ������.\n");
}


//������ � ����
void writeFile(typeSubject* head, int sizeSubject)
{
	//���� ������ ����������, �� ������� �� �����
	//���� ���, �� ������ ��������� �� ������
	if (arrayExist) {
		//��������� ����
		FILE *fp = fopen("subjects_info2.txt", "w");
		
		printf("\n�� �������: ������ ��������� � ����.\n");
		
		fprintf(fp, "|------------------------------------------------------");
		fprintf(fp, "-----------------------------------------------|\n");
		fprintf(fp, "|\t\t\t\t       ����� ���������� ���������: %-35d", sizeSubject);
		fprintf(fp, "|\n");
		fprintf(fp, "|---------------------------------------------------");
		fprintf(fp, "--------------------------------------------------|\n");
		fprintf(fp, "|    �    | \t��������      |  ���   |");		
		fprintf(fp, "   \t���������       |          �������          |  ����   |\n");
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
	
		
		//��������� ����
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
			
		printf("\n���������!\n");
				
	} else	
		printf("\n������. ������ �� ����������. ������� ������ � ����������.\n");
}


//������ �� �����
void readFile(typeSubject* head, int sizeSubject)
{
	//���� ������ ����������, �� ������� �� �����
	//���� ���, �� ������ ��������� �� ������
	int i;
	FILE *fp = fopen("subjects_info2.txt", "r");	//��������� ����
	char buffer[255];								//�� ���� ����� ���������� ������ �� �����
	 	
	printf("\n�� �������: ���������� ��������� �� �����.\n");
	 	
	//���� ���� ������, �� ������ ��������� �� ������ � ���������� ������
	if (fp == NULL) {
		printf("\n������. ���������� ������� ����.\n");
		return;
	} else {
		printf("\n���������� �����:\n");
		
		//�������� ����������� � ������� fgetc � buffer
		//��� ������ ��������� �� ������ �������� ������, ��
		//���������������� ��� �� ������ ����� ������
		//�������� i � �������� �������
		//��� ����� ������������ �� ��� ���, ����
		//fgetc �� ������ EOF(����� 1, ����� �����)
		//EOF ������ 1, 1 != 1, ��� �����
		//������ ������� � ��������� ����
		while ((buffer[i] = fgetc(fp)) != EOF)
		{
			if (buffer[i] == '\n') {
	           	buffer[i] = '\0';
	           	printf("%s\n", buffer);
	           	i = 0;
	       	} else i++;
		}
	}
	
	//��������� ����
	fclose(fp);
	printf("\n���������!\n");
}


typeSubject* readDateFromFile(typeSubject* head, int* sizeSubject)
{
	if (!arrayExist && !arrayExist1) {
		//���� ������ ����������, �� ������� �� �����
		//���� ���, �� ������ ��������� �� ������
		int i;
		FILE *fp = fopen("subjects_info3.txt", "r");	//��������� ����
		 	
		printf("\n�� �������: �������� ������ �� ����� � ������.\n");
		 	
		//���� ���� ������, �� ������ ��������� �� ������ � ���������� ������
		if (fp == NULL) {
			printf("\n������. ���������� ������� ����.\n");
			return head;
		} else {
			fscanf(fp, "%d\n", sizeSubject);
			
			//������� ������
	    	head = new typeSubject;
			head->next = NULL;
			head->prev = NULL;
			
			//������� ����
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
			
			printf("\n���������!\n");
		}
		
		//��������� ����
		fclose(fp);
	} else
		printf("\n������. ������ ��� ���������� ��� �� ��������� ������.\n");
		
	return head;	
}


//����� �� �����
void subjectPrintMain(typeSubject* head, typeSubject* head1, typeSubject* head2, int sizeSubject, int sizeSubject1, int sizeSubject2)
{	
	int printChoice; 	//����� ������������
	
	printf("\n�� �������: ����� ��������� �� �����.\n");
	
	start:
		
	//����
	printf("\n1.����� ��������� �� ����� ������ ������.\n");
	printf("2.����� ��������� �� ����� 1-�� ������.\n");
	printf("3.����� ��������� �� ����� 2-�� ������.\n");
	printf("4.����� � ������� ����.\n");
	
	//���� ������ ������������
	printf("\n������� �����: ");		
	scanf("%d", &printChoice);
	
	switch(printChoice)
	{
		case 1:
			if (arrayExist) 	
			    subjectPrint(head, sizeSubject, 0);
		    else {
		    	printf("\n������. ������ �� ����������. �������� ������, ������� ������ � ���������� ��� ");
				printf("�������� ������� 1-�� � 2-�� �������.\n");
			}
			goto start;
		case 2:
			if (arrayExist1) 	
			    subjectPrint(head1, sizeSubject1, 0);
			else
				printf("\n������. ������ �� ����������. ��������� ������.\n");
			goto start;
		case 3:
			if (arrayExist2) 	
			    subjectPrint(head2, sizeSubject2, 0);
		    else
				printf("\n������. ������ �� ����������. ��������� ������.\n");
			goto start;
		case 4:
			printf("\n������� � ������� ����...\n");
			printf("\n���������!\n");
			break;
		default:
			printf("\n������. �� �� ����� ����� �� ����.\n");
			goto start;
	}
}


//������������ ������
void freeMemory(typeSubject*& head, typeSubject*& head1, typeSubject*& head2)
{
	//���� ������ ��������, �� �����������
	//���� ���, �� ������ ��������� �� ������
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
		printf("\n������ �����������.\n");
	} else 
		printf("\n������. ������ �� ���� ��������.\n");
}


//��������������� �������


void subjectPrint(typeSubject* head, int sizeSubject, int sortNumber)
{
	int printChoice;
	
	if (sortNumber)
		goto output;
		
	do
	{
		//����
		printf("1.������ ����;\n");
		printf("2.����� �����.\n");
		printf("3.�����.\n");
		
		//���� ������ ������������
		printf("\n������� �����: ");		
		scanf("%d", &printChoice);
		
		if ((printChoice < 1) || (printChoice > 3))
			printf("\n������������ ����. ����������, ������� ����� �� ����.\n\n");
		else if (printChoice == 3)
			return;
		
	} while ((printChoice < 1) || (printChoice > 3));
	
	output:
		
	printf("|------------------------------------------------------");
	printf("-----------------------------------------------|\n");
	printf("|\t\t\t\t       ����� ���������� ���������: %-35d", sizeSubject);
	printf("|\n");
	printf("|---------------------------------------------------");
	printf("--------------------------------------------------|\n");
	printf("|    �    | \t��������      |  ���   |");		
	printf("   \t���������       |          �������          |  ����   |\n");
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
	
	printf("\n���������!\n");
}


//����� ������������� ��������
void print (typeSubject *node, int position)
{
	printf("\n����� �������� �������.\n");
	printf("��� ������� �%d. ���������� � ���:\n\n", position - 1);
	printf("|---------------------------------------------------");
	printf("--------------------------------------------------|\n");
	printf("|    �    | \t��������      |  ���   |");		
	printf("   \t���������       |          �������          |  ����   |\n");
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


//���������� ��������
typeSubject* miniAddElem(int position, typeSubject* head, int* sizeSubject)
{
	typeSubject *newElem, *nextNewElem, *nextNode;
		
	newElem = new typeSubject;
	
	printf("�������� %d ��������: ", position + 1);
	scanf("%s", newElem->name);
		
	printf("��� %d ��������: ", position + 1);
	scanf("%d", &newElem->year);
		    	
	printf("��������� %d ��������: ", position + 1);
	scanf("%s", newElem->faculty);
		    	
	printf("������� %d ��������: ", position + 1);
	scanf("%s", newElem->cathedra);
		    	
	printf("���������� ����� %d ��������: ", position + 1);
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


//���������� �� ���������� ��������
void sortAscendingName(typeSubject*& head)
{
	typeSubject	*current;			//������� �������
	
	//����� ��������
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


//���������� �� ���������� �����
void sortAscendingYear(typeSubject*& head)
{
	typeSubject	*current;			//������� �������
	
	//����� ��������
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


//���������� �� ���������� �����������
void sortAscendingFaculty(typeSubject*& head)
{
	typeSubject	*current;			//������� �������
	
	//����� ��������
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



//���������� �� ���������� ������
void sortAscendingCathedra(typeSubject*& head)
{
	typeSubject	*current;			//������� �������
	
	//����� ��������
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


//���������� �� ���������� �����
void sortAscendingHours(typeSubject*& head)
{
	typeSubject	*current;			//������� �������
	
	//����� ��������
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


//���������� �� ���������� ��������
void sortDescendingName(typeSubject*& head)
{
	typeSubject	*current;			//������� �������
	
	//����� ��������
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


//���������� �� ���������� �����
void sortDescendingYear(typeSubject*& head)
{
	typeSubject	*current;			//������� �������
	
	//����� ��������
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


//���������� �� ���������� �����������
void sortDescendingFaculty(typeSubject*& head)
{
	typeSubject	*current;			//������� �������
	
	//����� ��������
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



//���������� �� ���������� ������
void sortDescendingCathedra(typeSubject*& head)
{
	typeSubject	*current;			//������� �������
	
	//����� ��������
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


//���������� �� ���������� �����
void sortDescendingHours(typeSubject*& head)
{
	typeSubject	*current;			//������� �������
	
	//����� ��������
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


//������ ������� ��������
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
