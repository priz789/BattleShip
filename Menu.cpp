#include "Prototype.h"

void MainMenu()
{
	game* currentGame = nullptr;
	int choice;
	while (true)
	{
		system("cls");
		ClearBuffer();
		DrawMainMenu();
		choice = _getch();
		switch (choice)
		{
		case '1':
			cout << "Начать новую игру." << endl;
			GameStart(currentGame);
			break;
		case '2':
			cout << "Загрузить игру." << endl;
			GameStart(LoadGame());
			break;
		case '3':
			cout << "Посмотреть турнирную таблицу." << endl;
			ShowScoreTable();
			break;
		case '4':
			cout << "Выход." << endl;
			return;
			break;
		/*case 27:
			return;
			break;*/
		/*default:
			break;*/
		}
	}
}
