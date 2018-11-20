#include"Prototype.h"

void DrawMainMenu()
{
	cout << "\t������� ����." << endl;
	cout << endl;
	cout << "\t1. ������ ����� ����." << endl;
	cout << "\t2. ��������� ����." << endl;
	cout << "\t3. �������� ������� �����." << endl;
	cout << "\t4. �����." << endl;
	cout << endl;
}

void ClearBuffer()
{
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
}

player * CreatePlayer(player* p)
{
	int choice;
	cout << "�������� ��� ������ ������(1 - �������, 2 - ���): ";
	ClearBuffer();
	cin >> choice;
	if (choice == 1)
	{
		cout << endl;
		cout << "������� ��� ������ ������: ";
		ClearBuffer();
		cin.getline(p->name, 20);
		ClearBuffer();
	}
	cout << endl;
	return p;
}

void SaveGameToFile(game*currentGame)
{
	if (currentGame != nullptr)
	{
		cout << endl;
		cout << "������� ��� ����� ��� ����������: ";
		char filename[MAX_PATH];
		gets_s(filename, MAX_PATH);
		FILE * savedGame = fopen(filename, "wb");
		if (savedGame)
		{
			fseek(savedGame, 0, SEEK_END);
			fwrite(currentGame, sizeof(game), 1, savedGame);
			cout << "���� ���������� ������� ������." << endl;
			fclose(savedGame);
		}
		else
		{
			cout << "�� ������� ������� ����������!" << endl;
			cout << "������ #" << errno << endl;	// ������ errno (������������ ���� errno.h) �������� ������� _errno: http://www.cplusplus.com/reference/cerrno/errno/
			perror("������: "); // ������� �������� ����� ������, ������� ��������� ������������ ��������
		}
	}
	else
	{
		cout << endl;
		cout << "�� ������� ��������� ����!" << endl;
		cout << endl;
	}
	return;
}

game* LoadGame()
{
	cout << endl;
	cout << "������� ��� ����� ��� ��������: ";
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
		cout << "���� ������� ���������." << endl;
		system("pause");
		return newGame;
	}
	else
	{
		perror("������: ");
		system("pause");
		return nullptr;
	}
}

void GameStart(game*currentGame)
{
	if (currentGame==nullptr)
	{
		game *newGame = CreateNewGame();
		currentGame = newGame;
		for (int i = 0; i < 100; i++)
		{
			currentGame->field1[i]->status = 1;
			currentGame->field2[i]->status = 1;
		}
		currentGame->player1 = CreatePlayer(currentGame->player1);
		currentGame->player2 = CreatePlayer(currentGame->player2);
	}
	GameTurn(currentGame);
}

game* CreateNewGame()
{
	game*newGame = new game;
	for (int  i = 0; i < 100; i++)
	{
		newGame->field1[i] = new cell;
		newGame->field2[i] = new cell;
	}
	newGame->player1 = new player;
	newGame->player2 = new player;
	return newGame;
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
		{
		case 1:
			cout << endl;
			Attack(currentGame);
			break;
		case 2:
			cout << endl;
			cout << "����������� ����������." << endl;
			SaveGameToFile(currentGame);
			break;
		case 3:
			cout << endl;
			cout << "����������� ����� � ������� ����." << endl;
			break;
		default:
			break;
		}

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

void Attack(game*currentGame)
{
	if (currentGame != nullptr)
	{
		int x;
		int y;
		int index;
		cout << "������� ���������� ��� �����: ";
		ClearBuffer();
		cin >> x;
		ClearBuffer();
		cin >> y;
		index = (y * 10 + x) - 1;
		if (currentGame->field1[index]->status != 0)
		{
			currentGame->field1[index]->status = 0;
		}
		else
		{
			cout << "������ ������ ��� �� �������!" << endl;
		}
	}
	return;
}