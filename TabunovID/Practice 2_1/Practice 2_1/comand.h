// ���������� �������.���������� ������� ��������������� ���������, �������,
// �� ������� ������, ����������� ��������� ���, ����������� �����, 
// ����������� �������.����� ��������� ���������� ������ ���������� �������,
// ������� ����� ������������ ���������� �����.

#pragma once
typedef struct comand{
	char* Name;
	char* City;
	int Games;
	int Points;
	int Players;
} Scommand;
typedef struct commandbook {
	Scommand* comands;
	size_t length;
} Scommandbook;