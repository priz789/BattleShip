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

// глобальное объ€вление структуры "player"

struct player
{
	char name[20]; // им€
	int gameCounter; // cчетчик игр
	int score;// счет
	int four_deck; // количество 4-палубликов в строю
	int three_deck; // количество 3-палубников в строю
	int two_deck; // количество 2-палубников в строю
	int one_deck; // количество 1-палубников в строю
};

// √лобальное объ€вление структуры "cell"

struct cell
{
	char column; //абсцисса - "колонка"
	int row; //ордината - "строчка"
	int status; //состо€ние клетки
};

// √лобальное объ€вление структуры "game"

struct game
{
	cell*field1[100];
	cell*field2[100];
	player*player1;
	player*player2;
};

void MainMenu();
void DrawMainMenu();
void SaveGameToFile(game*);
game* LoadGame();
void ClearBuffer();
void GameStart(game*);
void ShowScoreTable();
void DrawGameField(game*);



