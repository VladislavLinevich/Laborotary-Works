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
void __fastcall TForm1::Button1Click(TObject *Sender)//���������� ������� Button1
{
	if (FileOpenDialog1->Execute()) { //�������� �������� �����
		TFileStream *tfile = new TFileStream(FileOpenDialog1->FileName,fmOpenReadWrite);//�������� ����
		TStringList *ts = new TStringList();//������� ������ �����
		ts->LoadFromStream(tfile);
		for (int i = 0, j = 0; j < (ts->Count)/4; i+=4, j++) {
			AllNumbers.CreateNode(ts->Strings[i], StrToInt(ts->Strings[i + 1]), ts->Strings[i + 2], ts->Strings[i + 3]); //��������� � ������
			if (ts->Strings[i + 3] == "Free") {
				FreeNumbers.CreateNode(ts->Strings[i], StrToInt(ts->Strings[i + 1]), ts->Strings[i + 2], ts->Strings[i + 3]);//��������� ������ ������
				Form1->ComboBox2->Items->Add(ts->Strings[i + 2]);//��������� � ComboBox
			} else {
				NotFreeNumbers.CreateNode(ts->Strings[i], StrToInt(ts->Strings[i + 1]), ts->Strings[i + 2], ts->Strings[i + 3]);//��������� ������� ������
			}
			Memo1->Lines->Add(ts->Strings[i]);//������� � Memo
			Memo1->Lines->Add(ts->Strings[i + 1]);
			Memo1->Lines->Add(ts->Strings[i + 2]);
			Memo1->Lines->Add(ts->Strings[i + 3]);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)//���������� ������� Button3
{
	Memo1->Clear();
	FreeNumbers.Print();//����� ������ ������ �������
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)//���������� ������� Button4
{
	Memo1->Clear();
	NotFreeNumbers.Print();//����� ������ ������� �������
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)//���������� ������� Button5
{
    Memo1->Clear();
	AllNumbers.Print();//����� ������ ���� �������
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)//���������� ������� Button6
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
void __fastcall TForm1::Button8Click(TObject *Sender)//���������� ������� Button8
{
	Lodgers.reg();//���������� ������� ����������� ����������
	AllNumbers.reg();
	Memo2->Clear();
	Lodgers.Print();
	Memo1->Clear();
	AllNumbers.Print();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)//���������� ������� Button9
{
	int k;//��� ����������� ����� ����� �����������
	for (int i = 0; i < Lodgers.GetSize(); i++) {
		Lodgers.Departure(k);//���������� ������� ��������� ����������
		AllNumbers.Departure(k);
        k = 0;
	}
	Memo2->Clear();
	Lodgers.Print();
    Memo1->Clear();
	AllNumbers.Print();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)//���������� ������� Button10
{
	Memo3->Clear();
	Lodgers.find();//���� ����� �� �������� ���������
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)//���������� ������� Button2
{
	if (FileSaveDialog1->Execute()) {
		Memo1->Lines->SaveToFile(FileSaveDialog1->FileName);//���������� � ����
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)//���������� ������� Button7
{
	if (FileSaveDialog1->Execute()) {
		Memo2->Lines->SaveToFile(FileSaveDialog1->FileName);//���������� � ����
	}
}
//---------------------------------------------------------------------------

