//---------------------------------------------------------------------------

#ifndef NumberH
#define NumberH
//---------------------------------------------------------------------------
#endif

#include <vcl.h>

class Number// Номер
{
	public:
	String ClassN;
	int Places;
	String RoomNumber;
	String Type;

	Number *next;
	Number *prev;
};



class DoubleListNumber//Список номеров
{
	private:
	Number *head;
	Number *tail;

	public:

	DoubleListNumber()
	{
		head = NULL;
		tail = NULL;
	}

	void CreateNode(String classN, int places, String roomNumber, String type)//Добавление в список
	{
		Number *temp = new Number;

		temp->ClassN = classN;
		temp->Places = places;
		temp->RoomNumber = roomNumber;
		temp->Type = type;
		temp->next = NULL;
		if (head == NULL) {
			head = temp;
			tail = temp;
			temp = NULL;
		}
		else {
			temp->prev = tail;
			tail->next = temp;
			tail = temp;
		}
	}

	void Print()//Вывод списка
	{
		Number *temp = new Number;

		temp = head;
		while (temp != NULL)
		{
			Form1->Memo1->Lines->Add(temp->ClassN);
			Form1->Memo1->Lines->Add(IntToStr(temp->Places));
			Form1->Memo1->Lines->Add(temp->RoomNumber);
			Form1->Memo1->Lines->Add(temp->Type);
			temp = temp->next;
		}

	}

	void reg()//Функция регистрации
	{
		Number *temp = new Number;

		temp = head;
		while (temp->RoomNumber != Form1->ComboBox2->Text)//Ищем элемент списка с номером выбранным в ComboBox2
		{
			temp = temp->next;
			if (temp == NULL) {
				return;
			}
		}
		temp->Type = "Not free";//Делаем в элементе номер занятым, тем самым удаляем соответствующий элемент из ComboBox
		Form1->ComboBox2->DeleteSelected();
		Form1->ComboBox2->Text = "Free numbers";
	}

	void Departure(int k)//Функция выселения
	{
		Number *temp = new Number;

		temp = head;
		while (StrToInt(temp->RoomNumber) != k)//Ищем в списке элемнт с номером k
		{
			temp = temp->next;
			if (temp == NULL) {
				return;
			}
		}

		temp->Type = "Free";//Делаем в элементе номер свободным, тем самым добавляем соответствующий элемент в ComboBox
		Form1->ComboBox2->Items->Add(temp->RoomNumber);
    }
};


