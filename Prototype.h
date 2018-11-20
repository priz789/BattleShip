#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<errno.h>
#include<iostream>
#include<ctime>
#include<windows.h>
#include<conio.h>
#include<cstdio>
#include<cstdlib>
#include<io.h>	

using namespace std;

// ���������� ���������� ��������� "player"

struct player
{
	char name[20]; // ���
	int gameCounter; // c������ ���
	int score;// ����
	int four_deck; // ���������� 4-���������� � �����
	int three_deck; // ���������� 3-���������� � �����
	int two_deck; // ���������� 2-���������� � �����
	int one_deck; // ���������� 1-���������� � �����
};

// ���������� ���������� ��������� "cell"

struct cell
{
	int column; //�������� - "�������"
	int row; //�������� - "�������"
	int status; //��������� ������
};

// ���������� ���������� ��������� "game"

struct game
{
	cell*field1[100]; // ������ ���� ������ 1
	cell*field2[100]; // ������ ���� ������ 2
	player*player1; // ������ ������ 1
	player*player2; // ������ ������ 2
};

void MainMenu();
void DrawMainMenu();
void SaveGameToFile(game*);
game* LoadGame();
void ClearBuffer();
void GameStart(game*);
void ShowScoreTable();
void DrawGameField(game*);
void GameTurn(game*);
void Attack(game*);
game* CreateNewGame();


