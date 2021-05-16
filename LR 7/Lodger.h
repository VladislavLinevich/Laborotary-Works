//---------------------------------------------------------------------------

#ifndef LodgerH
#define LodgerH
//---------------------------------------------------------------------------
#endif
#include <vcl.h>

class Lodger//Посетитель
{
    public:
	String FullName;
	int PassportNumber;
	String RoomNumber;
	String DateIn;
	String DateOut;

	Lodger *next;
	Lodger *prev;
};

class DoubleListLodger//Ñïèñîê ïîñåòèòåëåé
{
	private:
	Lodger *head;
	Lodger *tail;

	public:

	DoubleListLodger()
	{
		head = NULL;
		tail = NULL;
	}

	void CreateNode(String fullName, int passportNumber, String roomNumber, String dateIn, String dateOut)//Äîáàâëåíèå â ñïèñîê
	{
		Lodger *temp = new Lodger;

		temp->FullName = fullName;
		temp->PassportNumber = passportNumber;
		temp->RoomNumber = roomNumber;
		temp->DateIn = dateIn;
		temp->DateOut = dateOut;
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

	void reg()//Ôóíêöèÿ ðåãèñòðàöèè
	{
		Lodger *temp = new Lodger;

		temp = head;
		while (temp->FullName != Form1->ComboBox1->Text)//Èùåì ýëåìåíò ñïèñêà ñ èìåíåì âûáðàííûì â ComboBox1
		{
			temp = temp->next;
			if (temp == NULL) {
				return;
			}
		}
		temp->RoomNumber = Form1->ComboBox2->Text;//Ïðèñâàåâàåì åìó íîìåð, òåì ñàìûì óäàëÿåì ñîîòâåòñòâóþùèé ýëåìåíò èç ComboBox
		Form1->ComboBox1->DeleteSelected();
		Form1->ComboBox1->Text = "Lodgers";
	}

	void Print()//Ôóíêöèÿ âûâîäà ñïèñêà
	{
		Lodger *temp = new Lodger;

		temp = head;
		while (temp != NULL)
		{
			Form1->Memo2->Lines->Add(temp->FullName);
			Form1->Memo2->Lines->Add(IntToStr(temp->PassportNumber));
			Form1->Memo2->Lines->Add(temp->RoomNumber);
			Form1->Memo2->Lines->Add(temp->DateIn);
			Form1->Memo2->Lines->Add(temp->DateOut);
			temp = temp->next;
		}

	}

	void Departure(int &k)//Ôóíêöèÿ âûñåëåíèÿ
	{
		Lodger *temp = new Lodger;

		temp = head;
		while ( temp->DateOut != "13.05.21" || temp->RoomNumber == "No")//Èùåì ýëåìåíò ñ ñåãîäíÿøíåé äàòîé âûåçäà è ñ íîìåðîì
		{
			temp = temp->next;
			if (temp == NULL) {
				return;
			}
		}

		k = StrToInt(temp->RoomNumber);//Ïåðåìåííîé k ïðèñâàåâàåì íîìåð êîòîðûé îñâîáîäèòñÿ
		if (temp == head) {//Óäàëÿåì ñîîòâåòñâóþùèé ýëåìåíò
			head = head->next;
			delete temp;
		} else {
			if (temp == tail) {
				tail = tail->prev;
				tail->next = NULL;
				delete temp;
			} else {
				Lodger *previous = new Lodger;
				Lodger *Next = new Lodger;
				previous = temp->prev;
				Next = temp->next;
				Next->prev = previous;
				previous->next = Next;
				delete temp;
			}
		}
	}

	int GetSize()//Ðàçìåð ñïèñêà
	{
		Lodger *temp = new Lodger;
		int k;

		k = 0;
		temp = head;
		while (temp != NULL)
		{
			k++;
			temp = temp->next;
		}
		return k;
	}

	void find()//ôóíêöèÿ ïîèñêà ëþäåé ïî çàäàííûì êðèòåðèÿì
	{
		Lodger *temp = new Lodger;
		int k;//Êîëè÷åñòâî ââåäåííûõ êðèòåðèåâ

		temp = head;
		k = 0;

		if (Form1->Edit1->Text != "") {
			k++;
		}
		if (Form1->Edit2->Text != "") {
			k++;
		}
		if (Form1->Edit3->Text != "") {
			k++;
		}
		if (Form1->Edit4->Text != "") {
			k++;
		}
		if (Form1->Edit5->Text != "") {
			k++;
		}

		while (temp != NULL)
		{
			if (k == 5) {//Åñëè êðèòåðèåâ 5 òî ïðîâåðÿåì ýëåìåíò ñïèñêà íà âñå êðèòåðèè è ò.ä.
				if (temp->FullName == Form1->Edit1->Text && IntToStr(temp->PassportNumber) == Form1->Edit2->Text && temp->RoomNumber == Form1->Edit3->Text && temp->DateIn == Form1->Edit4->Text && temp->DateOut == Form1->Edit5->Text) {
					Form1->Memo3->Lines->Add(temp->FullName);
					Form1->Memo3->Lines->Add(IntToStr(temp->PassportNumber));
					Form1->Memo3->Lines->Add(temp->RoomNumber);
					Form1->Memo3->Lines->Add(temp->DateIn);
					Form1->Memo3->Lines->Add(temp->DateOut);
					temp = temp->next;
					continue;
				}
			}

			//_________________________________________________

			if (k == 4) {
				if (temp->FullName == Form1->Edit1->Text && IntToStr(temp->PassportNumber) == Form1->Edit2->Text && temp->RoomNumber == Form1->Edit3->Text && temp->DateIn == Form1->Edit4->Text) {
					Form1->Memo3->Lines->Add(temp->FullName);
					Form1->Memo3->Lines->Add(IntToStr(temp->PassportNumber));
					Form1->Memo3->Lines->Add(temp->RoomNumber);
					Form1->Memo3->Lines->Add(temp->DateIn);
					Form1->Memo3->Lines->Add(temp->DateOut);
					temp = temp->next;
					continue;
				}
				if (temp->FullName == Form1->Edit1->Text && IntToStr(temp->PassportNumber) == Form1->Edit2->Text && temp->RoomNumber == Form1->Edit3->Text &&temp->DateOut == Form1->Edit5->Text) {
					Form1->Memo3->Lines->Add(temp->FullName);
					Form1->Memo3->Lines->Add(IntToStr(temp->PassportNumber));
					Form1->Memo3->Lines->Add(temp->RoomNumber);
					Form1->Memo3->Lines->Add(temp->DateIn);
					Form1->Memo3->Lines->Add(temp->DateOut);
					temp = temp->next;
					continue;
				}
				if (temp->FullName == Form1->Edit1->Text && IntToStr(temp->PassportNumber) == Form1->Edit2->Text && temp->DateIn == Form1->Edit4->Text && temp->DateOut == Form1->Edit5->Text) {
					Form1->Memo3->Lines->Add(temp->FullName);
					Form1->Memo3->Lines->Add(IntToStr(temp->PassportNumber));
					Form1->Memo3->Lines->Add(temp->RoomNumber);
					Form1->Memo3->Lines->Add(temp->DateIn);
					Form1->Memo3->Lines->Add(temp->DateOut);
					temp = temp->next;
					continue;
				}
				if (temp->FullName == Form1->Edit1->Text && temp->RoomNumber == Form1->Edit3->Text && temp->DateIn == Form1->Edit4->Text && temp->DateOut == Form1->Edit5->Text) {
					Form1->Memo3->Lines->Add(temp->FullName);
					Form1->Memo3->Lines->Add(IntToStr(temp->PassportNumber));
					Form1->Memo3->Lines->Add(temp->RoomNumber);
					Form1->Memo3->Lines->Add(temp->DateIn);
					Form1->Memo3->Lines->Add(temp->DateOut);
					temp = temp->next;
					continue;
				}
				if (IntToStr(temp->PassportNumber) == Form1->Edit2->Text && temp->RoomNumber == Form1->Edit3->Text && temp->DateIn == Form1->Edit4->Text && temp->DateOut == Form1->Edit5->Text) {
					Form1->Memo3->Lines->Add(temp->FullName);
					Form1->Memo3->Lines->Add(IntToStr(temp->PassportNumber));
					Form1->Memo3->Lines->Add(temp->RoomNumber);
					Form1->Memo3->Lines->Add(temp->DateIn);
					Form1->Memo3->Lines->Add(temp->DateOut);
					temp = temp->next;
					continue;
				}
			}

			//____________________________________________________

			if (k == 3) {
				if (temp->RoomNumber == Form1->Edit3->Text && temp->DateIn == Form1->Edit4->Text && temp->DateOut == Form1->Edit5->Text) {
					Form1->Memo3->Lines->Add(temp->FullName);
					Form1->Memo3->Lines->Add(IntToStr(temp->PassportNumber));
					Form1->Memo3->Lines->Add(temp->RoomNumber);
					Form1->Memo3->Lines->Add(temp->DateIn);
					Form1->Memo3->Lines->Add(temp->DateOut);
					temp = temp->next;
					continue;
				}
				if (IntToStr(temp->PassportNumber) == Form1->Edit2->Text &&temp->DateIn == Form1->Edit4->Text && temp->DateOut == Form1->Edit5->Text) {
					Form1->Memo3->Lines->Add(temp->FullName);
					Form1->Memo3->Lines->Add(IntToStr(temp->PassportNumber));
					Form1->Memo3->Lines->Add(temp->RoomNumber);
					Form1->Memo3->Lines->Add(temp->DateIn);
					Form1->Memo3->Lines->Add(temp->DateOut);
					temp = temp->next;
					continue;
				}
				if (IntToStr(temp->PassportNumber) == Form1->Edit2->Text && temp->RoomNumber == Form1->Edit3->Text && temp->DateOut == Form1->Edit5->Text) {
					Form1->Memo3->Lines->Add(temp->FullName);
					Form1->Memo3->Lines->Add(IntToStr(temp->PassportNumber));
					Form1->Memo3->Lines->Add(temp->RoomNumber);
					Form1->Memo3->Lines->Add(temp->DateIn);
					Form1->Memo3->Lines->Add(temp->DateOut);
					temp = temp->next;
					continue;
				}
				if (IntToStr(temp->PassportNumber) == Form1->Edit2->Text && temp->RoomNumber == Form1->Edit3->Text && temp->DateIn == Form1->Edit4->Text) {
					Form1->Memo3->Lines->Add(temp->FullName);
					Form1->Memo3->Lines->Add(IntToStr(temp->PassportNumber));
					Form1->Memo3->Lines->Add(temp->RoomNumber);
					Form1->Memo3->Lines->Add(temp->DateIn);
					Form1->Memo3->Lines->Add(temp->DateOut);
					temp = temp->next;
					continue;
				}
				if (temp->FullName == Form1->Edit1->Text && temp->DateIn == Form1->Edit4->Text && temp->DateOut == Form1->Edit5->Text) {
					Form1->Memo3->Lines->Add(temp->FullName);
					Form1->Memo3->Lines->Add(IntToStr(temp->PassportNumber));
					Form1->Memo3->Lines->Add(temp->RoomNumber);
					Form1->Memo3->Lines->Add(temp->DateIn);
					Form1->Memo3->Lines->Add(temp->DateOut);
					temp = temp->next;
					continue;
				}
				if (temp->FullName == Form1->Edit1->Text && temp->RoomNumber == Form1->Edit3->Text && temp->DateOut == Form1->Edit5->Text) {
					Form1->Memo3->Lines->Add(temp->FullName);
					Form1->Memo3->Lines->Add(IntToStr(temp->PassportNumber));
					Form1->Memo3->Lines->Add(temp->RoomNumber);
					Form1->Memo3->Lines->Add(temp->DateIn);
					Form1->Memo3->Lines->Add(temp->DateOut);
					temp = temp->next;
					continue;
				}
				if (temp->FullName == Form1->Edit1->Text && temp->RoomNumber == Form1->Edit3->Text && temp->DateIn == Form1->Edit4->Text) {
					Form1->Memo3->Lines->Add(temp->FullName);
					Form1->Memo3->Lines->Add(IntToStr(temp->PassportNumber));
					Form1->Memo3->Lines->Add(temp->RoomNumber);
					Form1->Memo3->Lines->Add(temp->DateIn);
					Form1->Memo3->Lines->Add(temp->DateOut);
					temp = temp->next;
					continue;
				}
				if (temp->FullName == Form1->Edit1->Text && IntToStr(temp->PassportNumber) == Form1->Edit2->Text && temp->DateOut == Form1->Edit5->Text) {
					Form1->Memo3->Lines->Add(temp->FullName);
					Form1->Memo3->Lines->Add(IntToStr(temp->PassportNumber));
					Form1->Memo3->Lines->Add(temp->RoomNumber);
					Form1->Memo3->Lines->Add(temp->DateIn);
					Form1->Memo3->Lines->Add(temp->DateOut);
					temp = temp->next;
					continue;
				}
				if (temp->FullName == Form1->Edit1->Text && IntToStr(temp->PassportNumber) == Form1->Edit2->Text && temp->DateIn == Form1->Edit4->Text) {
					Form1->Memo3->Lines->Add(temp->FullName);
					Form1->Memo3->Lines->Add(IntToStr(temp->PassportNumber));
					Form1->Memo3->Lines->Add(temp->RoomNumber);
					Form1->Memo3->Lines->Add(temp->DateIn);
					Form1->Memo3->Lines->Add(temp->DateOut);
					temp = temp->next;
					continue;
				}
				if (temp->FullName == Form1->Edit1->Text && IntToStr(temp->PassportNumber) == Form1->Edit2->Text && temp->RoomNumber == Form1->Edit3->Text) {
					Form1->Memo3->Lines->Add(temp->FullName);
					Form1->Memo3->Lines->Add(IntToStr(temp->PassportNumber));
					Form1->Memo3->Lines->Add(temp->RoomNumber);
					Form1->Memo3->Lines->Add(temp->DateIn);
					Form1->Memo3->Lines->Add(temp->DateOut);
					temp = temp->next;
					continue;
				}
			}


			//____________________________________________________
			if (k == 2) {
				if (temp->FullName == Form1->Edit1->Text && IntToStr(temp->PassportNumber) == Form1->Edit2->Text) {
					Form1->Memo3->Lines->Add(temp->FullName);
					Form1->Memo3->Lines->Add(IntToStr(temp->PassportNumber));
					Form1->Memo3->Lines->Add(temp->RoomNumber);
					Form1->Memo3->Lines->Add(temp->DateIn);
					Form1->Memo3->Lines->Add(temp->DateOut);
					temp = temp->next;
					continue;
				}
				if (temp->FullName == Form1->Edit1->Text && temp->RoomNumber == Form1->Edit3->Text) {
					Form1->Memo3->Lines->Add(temp->FullName);
					Form1->Memo3->Lines->Add(IntToStr(temp->PassportNumber));
					Form1->Memo3->Lines->Add(temp->RoomNumber);
					Form1->Memo3->Lines->Add(temp->DateIn);
					Form1->Memo3->Lines->Add(temp->DateOut);
					temp = temp->next;
					continue;
				}
				if (temp->FullName == Form1->Edit1->Text && temp->DateIn == Form1->Edit4->Text) {
					Form1->Memo3->Lines->Add(temp->FullName);
					Form1->Memo3->Lines->Add(IntToStr(temp->PassportNumber));
					Form1->Memo3->Lines->Add(temp->RoomNumber);
					Form1->Memo3->Lines->Add(temp->DateIn);
					Form1->Memo3->Lines->Add(temp->DateOut);
					temp = temp->next;
					continue;
				}
				if (temp->FullName == Form1->Edit1->Text && temp->DateOut == Form1->Edit5->Text) {
					Form1->Memo3->Lines->Add(temp->FullName);
					Form1->Memo3->Lines->Add(IntToStr(temp->PassportNumber));
					Form1->Memo3->Lines->Add(temp->RoomNumber);
					Form1->Memo3->Lines->Add(temp->DateIn);
					Form1->Memo3->Lines->Add(temp->DateOut);
					temp = temp->next;
					continue;
				}
				if (IntToStr(temp->PassportNumber) == Form1->Edit2->Text && temp->RoomNumber == Form1->Edit3->Text) {
					Form1->Memo3->Lines->Add(temp->FullName);
					Form1->Memo3->Lines->Add(IntToStr(temp->PassportNumber));
					Form1->Memo3->Lines->Add(temp->RoomNumber);
					Form1->Memo3->Lines->Add(temp->DateIn);
					Form1->Memo3->Lines->Add(temp->DateOut);
					temp = temp->next;
					continue;
				}
				if (IntToStr(temp->PassportNumber) == Form1->Edit2->Text && temp->DateIn == Form1->Edit4->Text) {
					Form1->Memo3->Lines->Add(temp->FullName);
					Form1->Memo3->Lines->Add(IntToStr(temp->PassportNumber));
					Form1->Memo3->Lines->Add(temp->RoomNumber);
					Form1->Memo3->Lines->Add(temp->DateIn);
					Form1->Memo3->Lines->Add(temp->DateOut);
					temp = temp->next;
					continue;
				}
				if (IntToStr(temp->PassportNumber) == Form1->Edit2->Text && temp->DateOut == Form1->Edit5->Text) {
					Form1->Memo3->Lines->Add(temp->FullName);
					Form1->Memo3->Lines->Add(IntToStr(temp->PassportNumber));
					Form1->Memo3->Lines->Add(temp->RoomNumber);
					Form1->Memo3->Lines->Add(temp->DateIn);
					Form1->Memo3->Lines->Add(temp->DateOut);
					temp = temp->next;
					continue;
				}
				if (temp->RoomNumber == Form1->Edit3->Text && temp->DateIn == Form1->Edit4->Text) {
					Form1->Memo3->Lines->Add(temp->FullName);
					Form1->Memo3->Lines->Add(IntToStr(temp->PassportNumber));
					Form1->Memo3->Lines->Add(temp->RoomNumber);
					Form1->Memo3->Lines->Add(temp->DateIn);
					Form1->Memo3->Lines->Add(temp->DateOut);
					temp = temp->next;
					continue;
				}
				if (temp->RoomNumber == Form1->Edit3->Text && temp->DateOut == Form1->Edit5->Text) {
					Form1->Memo3->Lines->Add(temp->FullName);
					Form1->Memo3->Lines->Add(IntToStr(temp->PassportNumber));
					Form1->Memo3->Lines->Add(temp->RoomNumber);
					Form1->Memo3->Lines->Add(temp->DateIn);
					Form1->Memo3->Lines->Add(temp->DateOut);
					temp = temp->next;
					continue;
				}
				if (temp->DateIn == Form1->Edit4->Text && temp->DateOut == Form1->Edit5->Text) {
					Form1->Memo3->Lines->Add(temp->FullName);
					Form1->Memo3->Lines->Add(IntToStr(temp->PassportNumber));
					Form1->Memo3->Lines->Add(temp->RoomNumber);
					Form1->Memo3->Lines->Add(temp->DateIn);
					Form1->Memo3->Lines->Add(temp->DateOut);
					temp = temp->next;
					continue;
				}
			}

			//_________________________________________

			if (k == 1) {
				if (temp->FullName == Form1->Edit1->Text) {
					Form1->Memo3->Lines->Add(temp->FullName);
					Form1->Memo3->Lines->Add(IntToStr(temp->PassportNumber));
					Form1->Memo3->Lines->Add(temp->RoomNumber);
					Form1->Memo3->Lines->Add(temp->DateIn);
					Form1->Memo3->Lines->Add(temp->DateOut);
					temp = temp->next;
					continue;
				}
				if (IntToStr(temp->PassportNumber) == Form1->Edit2->Text) {
					Form1->Memo3->Lines->Add(temp->FullName);
					Form1->Memo3->Lines->Add(IntToStr(temp->PassportNumber));
					Form1->Memo3->Lines->Add(temp->RoomNumber);
					Form1->Memo3->Lines->Add(temp->DateIn);
					Form1->Memo3->Lines->Add(temp->DateOut);
					temp = temp->next;
					continue;
				}
				if (temp->RoomNumber == Form1->Edit3->Text) {
					Form1->Memo3->Lines->Add(temp->FullName);
					Form1->Memo3->Lines->Add(IntToStr(temp->PassportNumber));
					Form1->Memo3->Lines->Add(temp->RoomNumber);
					Form1->Memo3->Lines->Add(temp->DateIn);
					Form1->Memo3->Lines->Add(temp->DateOut);
					temp = temp->next;
					continue;
				}
				if (temp->DateIn == Form1->Edit4->Text) {
					Form1->Memo3->Lines->Add(temp->FullName);
					Form1->Memo3->Lines->Add(IntToStr(temp->PassportNumber));
					Form1->Memo3->Lines->Add(temp->RoomNumber);
					Form1->Memo3->Lines->Add(temp->DateIn);
					Form1->Memo3->Lines->Add(temp->DateOut);
					temp = temp->next;
					continue;
				}
				if (temp->DateOut == Form1->Edit5->Text) {
					Form1->Memo3->Lines->Add(temp->FullName);
					Form1->Memo3->Lines->Add(IntToStr(temp->PassportNumber));
					Form1->Memo3->Lines->Add(temp->RoomNumber);
					Form1->Memo3->Lines->Add(temp->DateIn);
					Form1->Memo3->Lines->Add(temp->DateOut);
					temp = temp->next;
					continue;
				}
			}

			//__________________________________________

			temp = temp->next;
			if (temp == NULL) {
				return;
			}
		}
	}
};
