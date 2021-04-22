#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>

typedef struct _node {  //Узел двусвязного списка
	char letter;
	struct _node *next;
	struct _node *prev;
} node;

typedef struct  {  //список
	 int size;
	 node *head;
	 node *tail;
} List;

List* CreateList(){  //Создание списка
	List *temp;
	temp = (List*)malloc(sizeof(List));
	if (temp == NULL){
		printf("Memory not allocated");
		exit(1);
	}

	temp->size = 0;
	temp->head = NULL;
	temp->tail = NULL;

    return temp;
}

void DeleteList(List **list){//Очистка списка
	node *delete = (*list)->head;
	node *temp = NULL;
	while (delete){
		temp = delete->next;
		free(delete);
		delete = temp;
	}
	free (*list);
	(*list) = NULL;
}
void CreateNode(List *list, char a) //Создание нового узла списка
{
	node *temp;
	temp = (node*)malloc(sizeof(node));
	if (temp == NULL){
		printf("Memory not allocated");
		exit(1);
	}

	temp->letter = a;
	temp->next = NULL;
    if (list->head == NULL) {
		list->head = temp;
		list->tail = temp;
		temp = NULL;
	}
	else {
		temp->prev = list->tail;
		list->tail->next = temp;
		list->tail = temp;
	}
	list->size++;
}

void Palindrome(List *list){   // проверка является ли слово палиндромом
	node *temp1;
	temp1 = (node*)malloc(sizeof(node));
	if (temp1 == NULL){
		printf("Memory not allocated");
		exit(1);
	}
	node *temp2;
	temp2 = (node*)malloc(sizeof(node));
	if (temp2 == NULL){
		printf("Memory not allocated");
		exit(1);
	}

	temp1 = list->head;
	temp2 = list->tail;
	for (int i = 0; i < list->size / 2; i++) { //проходим список с двух сторон и проверяем на равенство букв
		if (temp1->letter != temp2->letter) {
			printf("Not palindrome");
			return;
		}
		temp1 = temp1->next;
		temp2 = temp2->prev;
	}
	printf("Palindrome");
}

int main()
{
	List *list = CreateList();
	char a[100];

	fgets(a, 100, stdin);
	for (int i = 0; i < strlen(a)-1; i++) { //заностм нужные элементы в список
		if (isalpha(a[i])) {
			CreateNode(list, a[i]);
		}
	}
	Palindrome(list);
	DeleteList(&list);

	getch();
	return 0;
}