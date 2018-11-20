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

// глобальное объявление структуры "player"

struct player
{
	char name[20]; // имя
	int gameCounter; // cчетчик игр
	int score;// счет
	int four_deck; // количество 4-палубликов в строю
	int three_deck; // количество 3-палубников в строю
	int two_deck; // количество 2-палубников в строю
	int one_deck; // количество 1-палубников в строю
};

// Глобальное объявление структуры "cell"

struct cell
{
	int column; //абсцисса - "колонка"
	int row; //ордината - "строчка"
	int status; //состояние клетки
};

// Глобальное объявление структуры "game"

struct game
{
	cell*field1[100]; // Массив поля игрока 1
	cell*field2[100]; // Массив поля игрока 2
	player*player1; // Данные игрока 1
	player*player2; // Данные игрока 2
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


