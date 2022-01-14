#include "LAB9.cpp"

int main(void)
{
  	int choice; 					//����� ������������
  	int sizeSubject;				//���-�� ��������� ������
  	int sizeSubject1;				//���-�� ��������� 1 ������
  	int sizeSubject2;				//���-�� ��������� 2 ������
  	typeSubject* head = NULL;		//������ ������
  	typeSubject* head1 = NULL;		//������ 1 ������
  	typeSubject* head2 = NULL;		//������ 2 ������
  	
  	//���������
  	SetConsoleCP(1251);				
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	
	do
  	{ 
  		//����
  		printf ("\n����:\n");
  		printf ("1.������������ ��������� ������;\n");
  		printf ("2.���� ��������� � ����������;\n");
  		printf ("3.����� ��������;\n");
  		printf ("4.����������;\n");
  		printf ("5.�������������� ��������;\n");
  		printf ("6.����� ���� ���������;\n");
  		printf ("7.���������� ������ �������� � �����;\n");
  		printf ("8.�������� ��������;\n");
  		printf ("9.������� ��������;\n");
  		printf ("10.����������� ������ ���������� ��������;\n");
  		printf ("11.����������� ����� ������;\n");
  		printf ("12.���������� ������ �� ���;\n");
  		printf ("13.������� ���� �������;\n");
  		printf ("14.������ � ����;\n");
  		printf ("15.���������� �� �����;\n");
  		printf ("16.�������� ������ �� ����� � ������.\n");
  		printf ("17.����� ��������� �� �����;\n");
  		printf ("18.������������ ������;\n");
  		printf ("19.��������� ������ ���������.\n");
  	
  		
  		//���� ����� �������������
    	printf ("\n\n�������� ����� �� ����: ");
    	scanf ("%d", &choice);
    	
    		
    	//��������: ���� �� �������� ������
    	//�� ��������� ����� �������, ��� ����� �����������	
		switch(choice)
    	{
    		case 1:		//��������� ������
   				head = createMemory(head, &sizeSubject);					
				break;
        	case 2:		//���� � ������� ����������
        		head = inputKeyboard(head, sizeSubject);				
        		break;
        	case 3:		//����� ��������
        		searchLocationElement(head, sizeSubject);
				break;
			case 4:		//����������
				head = sortArray(head, sizeSubject);
				break;
			case 5:		//�������������� ��������
				head = editElem(head, sizeSubject);		
				break;
			case 6:		//����� ���������
				head = exchangeElem(head, sizeSubject);		
				break;
			case 7:		//���������� ��������
				head = addElem(head, &sizeSubject);		
				break;
			case 8:		//�������� ��������
				head = deleteTargetElem(head, &sizeSubject);	
				break;
			case 9:		//������� ��������
				head = addNewElem(head, &sizeSubject);	
				break;
			case 10: 	//����������� ������ ���������� ��������
				addressLast(head, sizeSubject);
				break;
			case 11:	//����� ������
				printf("\n�� �������: ����������� ����� ������.\n\n");
				printf ("����� ��������� ������ = %d\n", length(head));
				printf ("����� 1-�� ������ = %d\n", length(head1));
				printf ("����� 2-�� ������ = %d\n", length(head2));	
				break;
			case 12:	//���������� ������ �� ���
				split(head, head1, head2, &sizeSubject, &sizeSubject1, &sizeSubject2);
				break;
			case 13:	//������� ���� �������
				unite(head, head1, head2, &sizeSubject, &sizeSubject1, &sizeSubject2);
				break;
			case 14:	//������ � ����
				writeFile(head, sizeSubject);
				break;
			case 15:	//������ �����
				readFile(head, sizeSubject);
				break;
			case 16:	//������ ������ �� ����� � ������	
				head = readDateFromFile(head, &sizeSubject);
				break;
			case 17:	//����� �� ����� ���������
				subjectPrintMain(head, head1, head2, sizeSubject, sizeSubject1, sizeSubject2);
				break;
			case 18:	//������������ ������
				freeMemory(head, head1, head2);
				break;
			case 19: 	//���������� ���������
        		if (head != NULL || head1 != NULL)
        			freeMemory(head, head1, head2);
        		printf("\n�� �������: ��������� ������ ���������.\n");
        		printf("\nBye, bye\n");
        		break;	
        	default:
        		printf("\n������. �� �� ����� ����� �� ����.\n");
        		break;
    	} 
		 	 
  	} while (choice != 19);
  	
  	getch();
  	return 0;
}
