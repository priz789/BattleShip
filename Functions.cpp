#include"Prototype.h"

void DrawMainMenu()
{
	cout << "\tГлавное меню." << endl;
	cout << endl;
	cout << "\t1. Начать новую игру." << endl;
	cout << "\t2. Загрузить игру." << endl;
	cout << "\t3. Показать таблицу очков." << endl;
	cout << "\t4. Выход." << endl;
	cout << endl;
}

void ClearBuffer()
{
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
}

player * CreatePlayer(player* p1)
{
	cout << "Введите имя нового игрока: ";
	ClearBuffer();
	cin.getline(p1->name, 20);
	ClearBuffer();
	cout << endl;
	return p1;
}

void SaveGameToFile(game*currentGame)
{
	if (currentGame != nullptr)
	{
		cout << endl;
		cout << "Введите имя файла для сохранения: ";
		char filename[MAX_PATH];
		gets_s(filename, MAX_PATH);
		FILE * savedGame = fopen(filename, "wb");
		if (savedGame)
		{
			fseek(savedGame, 0, SEEK_END);
			fwrite(currentGame, sizeof(game), 1, savedGame);
			cout << "Файл сохранения успешно создан." << endl;
			fclose(savedGame);
		}
		else
		{
			cout << "Не удалось создать сохранение!" << endl;
			cout << "Ошибка #" << errno << endl;	// Макрос errno (заголовочный файл errno.h) вызывает функцию _errno: http://www.cplusplus.com/reference/cerrno/errno/
			perror("Ошибка: "); // Функция печатает текст ошибки, который определен операционной системой
		}
	}
	else
	{
		cout << endl;
		cout << "Не удалось сохранить игру!" << endl;
		cout << endl;
	}
	return;
}

game* LoadGame()
{
	cout << endl;
	cout << "Введите имя файла для загрузки: ";
	char filename[MAX_PATH];
	gets_s(filename, MAX_PATH);
	FILE * loadgame = fopen(filename, "rb");
	if (loadgame)
	{
		fseek(loadgame, 0, SEEK_SET);
		int length = _filelength(_fileno(loadgame));
		game * newGame = new game;
		fread(newGame, sizeof(game), 1, loadgame);
		fclose(loadgame);
		cout << "Игра успешно загружена." << endl;
		system("pause");
		return newGame;
	}
	else
	{
		perror("Ошибка: ");
		system("pause");
		return nullptr;
	}
}

void GameStart(game*currentGame)
{
	if (currentGame==nullptr)
	{
		game *newGame = new game;
		memset(newGame,0,sizeof(game));
		for (int i = 0; i < 100; i++)
		{
			newGame->field1[i]->status = 1;
			newGame->field2[i]->status = 1;
		}
		newGame->player1 = CreatePlayer(newGame->player1);
		newGame->player2 = CreatePlayer(newGame->player2);
		currentGame = newGame;
	}
	GameTurn(currentGame);
}

void GameTurn(game*currentGame)
{
	bool gameIsOn = 1;
	int choice;
	while (gameIsOn)
	{
		DrawGameField(currentGame);
		ClearBuffer();
		choice = _getch();
		switch (choice)
			case 1:

	}
}

void DrawGameField(game*currentGame)
{
	system("cls");
	return;
}

void ShowScoreTable()
{
	return;
}