//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Number.h"
#include "Lodger.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

DoubleListNumber AllNumbers;
DoubleListNumber FreeNumbers;
DoubleListNumber NotFreeNumbers;

DoubleListLodger Lodgers;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)//Обработчик событий Button1
{
	if (FileOpenDialog1->Execute()) { //Проверка открытия файла
		TFileStream *tfile = new TFileStream(FileOpenDialog1->FileName,fmOpenReadWrite);//Считывем файл
		TStringList *ts = new TStringList();//Создаем массив строк
		ts->LoadFromStream(tfile);
		for (int i = 0, j = 0; j < (ts->Count)/4; i+=4, j++) {
			AllNumbers.CreateNode(ts->Strings[i], StrToInt(ts->Strings[i + 1]), ts->Strings[i + 2], ts->Strings[i + 3]); //Добавляем в список
			if (ts->Strings[i + 3] == "Free") {
				FreeNumbers.CreateNode(ts->Strings[i], StrToInt(ts->Strings[i + 1]), ts->Strings[i + 2], ts->Strings[i + 3]);//Добавляем пустые номера
				Form1->ComboBox2->Items->Add(ts->Strings[i + 2]);//Добавдяем в ComboBox
			} else {
				NotFreeNumbers.CreateNode(ts->Strings[i], StrToInt(ts->Strings[i + 1]), ts->Strings[i + 2], ts->Strings[i + 3]);//Добавляем занятые номера
			}
			Memo1->Lines->Add(ts->Strings[i]);//Выводим в Memo
			Memo1->Lines->Add(ts->Strings[i + 1]);
			Memo1->Lines->Add(ts->Strings[i + 2]);
			Memo1->Lines->Add(ts->Strings[i + 3]);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)//Обработчик событий Button3
{
	Memo1->Clear();
	FreeNumbers.Print();//Вывод списка пустых номеров
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)//Обработчик событий Button4
{
	Memo1->Clear();
	NotFreeNumbers.Print();//Вывод списка занятых номеров
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)//Обработчик событий Button5
{
    Memo1->Clear();
	AllNumbers.Print();//Вывод списка всех номеров
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)//Обработчик событий Button6
{
	if (FileOpenDialog1->Execute()){
		TFileStream *tfile = new TFileStream(FileOpenDialog1->FileName,fmOpenReadWrite);
		TStringList *ts = new TStringList();
		ts->LoadFromStream(tfile);
		for (int i = 0, j = 0; j < (ts->Count)/5; i+=5, j++) {
			Lodgers.CreateNode(ts->Strings[i], StrToInt(ts->Strings[i + 1]), ts->Strings[i + 2], ts->Strings[i + 3], ts->Strings[i + 4]);
			if (ts->Strings[i + 2] == "No") {
				Form1->ComboBox1->Items->Add(ts->Strings[i]);
			}
			Memo2->Lines->Add(ts->Strings[i]);
			Memo2->Lines->Add(ts->Strings[i + 1]);
			Memo2->Lines->Add(ts->Strings[i + 2]);
			Memo2->Lines->Add(ts->Strings[i + 3]);
			Memo2->Lines->Add(ts->Strings[i + 4]);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)//Обработчик событий Button8
{
	Lodgers.reg();//Используем функции регистрации посетителя
	AllNumbers.reg();
	Memo2->Clear();
	Lodgers.Print();
	Memo1->Clear();
	AllNumbers.Print();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)//Обработчик событий Button9
{
	int k;//Для запрминания какой номер освободился
	for (int i = 0; i < Lodgers.GetSize(); i++) {
		Lodgers.Departure(k);//Используем функции выселения посетителя
		AllNumbers.Departure(k);
        k = 0;
	}
	Memo2->Clear();
	Lodgers.Print();
    Memo1->Clear();
	AllNumbers.Print();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)//Обработчик событий Button10
{
	Memo3->Clear();
	Lodgers.find();//Ищем людей по заданным критериям
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)//Обработчик событий Button2
{
	if (FileSaveDialog1->Execute()) {
		Memo1->Lines->SaveToFile(FileSaveDialog1->FileName);//Сохранение в файл
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)//Обработчик событий Button7
{
	if (FileSaveDialog1->Execute()) {
		Memo2->Lines->SaveToFile(FileSaveDialog1->FileName);//Сохранение в файл
	}
}
//---------------------------------------------------------------------------

