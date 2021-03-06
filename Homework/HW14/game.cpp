#include "game.h"

// ------------------- Метод вывода правил игры ---------------------------

void Game::instructions()
{
    cout << "Добро пожаловать на поле битвы!\n";
    cout << "Советую прочитать данные правила.\n";
    cout << "Выбранный ход вводится цифрами (0-8), в соответствии с полем, указанным ниже:\n\n";

    cout << "       0 | 1 | 2\n";
    cout << "       ---------\n";
    cout << "       3 | 4 | 5\n";
    cout << "       ---------\n";
    cout << "       6 | 7 | 8\n\n";

    cout << "Приготовься, человек, битва начинается!\n\n";
}

void Game::panelControl()
{
    cout << " ===============\n";
    cout << "Панель управления\n";
    cout << " ===============\n\n";
    cout << "       0 | 1 | 2\n";
    cout << "       ---------\n";
    cout << "       3 | 4 | 5\n";
    cout << "       ---------\n";
    cout << "       6 | 7 | 8\n\n";
}

// ---------------------------------------------------------------------------


// ------------------- Метод выбора режима игры ----------------------------
int Game::chooseMode()
{
    cout << "Выберите режим игры:\n";
    cout << "1. Против компьютера\n";
    cout << "2. 2 игрока\n";

    do
    {
        cout << "> ";
        cin >> mode;
    }

    while(mode > 2 || mode < 1);

    return mode;
}

// ---------------------------------------------------------------------------

// ------------------- Метод выбора первого игрока ---------------------------
char Game::askYesNo()
{
    do
    {
        cout << "Желаете ходить первым (y/n): ";
        cin >> response;
    } while (response != 'y' && response != 'n');

    return response;
}
// ---------------------------------------------------------------------------

// -------------------- Метод отрисовки игрового поля -------------------------
void Game::displayBoard()
{
    cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
    cout << "\n\t" << "---------";
    cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
    cout << "\n\t" << "---------";
    cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
    cout << "\n\n";
}
// ---------------------------------------------------------------------------

// ------------------------ Метод выбора хода --------------------------------
int Game::askNumber()
{
    do
    {
        cout << "Куда вы пойдете?" << endl;
        cin >> number;
    } while (number > 9 || number < 0);

    return number;
}
// ---------------------------------------------------------------------------

// ----------------- Метод определения первого игрока ------------------------
char Game::humanPiece()
{
    char go_first = askYesNo();

    if(go_first == 'y')
    {
        cout << "\nТогда ходи первым.  Видимо, тебе это нужно.\n";
        return 'X';
    }

    if(go_first == 'n')
    {
        cout << "\nА ты храбрый малый... Я пойду первым!\n";
        return 'O';
    }
}
// ---------------------------------------------------------------------------

// ----------------- Метод определения второго игрока ------------------------
char Game::opponent(char piece)
{
    if(piece == 'X')
        return 'O';
    else
        return 'X';
}
// ---------------------------------------------------------------------------

// -------------------- Метод определения победителя -------------------------
char Game::winner()
{
    // Все возможные выигрышные комбинации
    const int WINNING_ROWS[8][3] = { {0, 1, 2},
                                     {3, 4, 5},
                                     {6, 7, 8},
                                     {0, 3, 6},
                                     {1, 4, 7},
                                     {2, 5, 8},
                                     {0, 4, 8},
                                     {2, 4, 6} };
    const int TOTAL_ROWS = 8;

    // Если какой-либо столбец или строка имеет одинаковое значение (и не имеет значение EMPTY),
    // возращаем победителя (winner)
    for(int row = 0; row < TOTAL_ROWS; ++row)
    {
        if ( (board[WINNING_ROWS[row][0]] != EMPTY) &&
             (board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) &&
             (board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]]) )
        {
            return board[WINNING_ROWS[row][0]];
        }
    }

    // Если никто не победил, и не осталось пустых полей, вернуть ничью (TIE)
    if (count(board.begin(), board.end(), EMPTY) == 0)
        return TIE;

    // Если никто не победил, и еще не ничья, игра продолжается (NO_ONE)
    return NO_ONE;
}
// ---------------------------------------------------------------------------

// ----------- Метод определения победителя со вторым игроком -----------------
char Game::player2winner()
{
    const int WINNING_ROWS[8][3] = { {0, 1, 2},
                                     {3, 4, 5},
                                     {6, 7, 8},
                                     {0, 3, 6},
                                     {1, 4, 7},
                                     {2, 5, 8},
                                     {0, 4, 8},
                                     {2, 4, 6} };
    const int TOTAL_ROWS = 8;

    for(int row = 0; row < TOTAL_ROWS; ++row)
    {
        if ( (board[WINNING_ROWS[row][0]] != EMPTY) &&
             (board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) &&
             (board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]]) )
        {
            return board[WINNING_ROWS[row][0]];
        }
    }
    if (count(board.begin(), board.end(), EMPTY) == 0)
        return TIE;

    return NO_ONE;
}
// ---------------------------------------------------------------------------

// --------------------- Метод проверки занятости поля -----------------------
inline bool Game::isLegal(int move)
{
    return (board[move] == EMPTY);
}
// ---------------------------------------------------------------------------

// ---------------------- Метод обработки хода игрока ------------------------
int Game::humanMove()
{
    int move = askNumber();
    while (!isLegal(move))
    {
        cout << "\nДанное поле уже занято, глупый человек!\n";
        move = askNumber();
    }
    cout << "Прекрасно...\n";
    return move;
}
// ---------------------------------------------------------------------------

// ------------------ Метод обработки хода второго игрока --------------------
int Game::player2Move()
{
    cout << "Ходит Игрок 2.\n";
    int move = askNumber();
    while (!isLegal(move))
    {
        cout << "\nДанное поле уже занято!\n";
        move = askNumber();
    }
    return move;
}
// ---------------------------------------------------------------------------


// ------------------- Метод обработки хода компьютера -----------------------
int Game::computerMove(char computer)
{
    unsigned int move = 0;
    bool found = false;

    // Если компьютер может выиграть следующим ходом, (2 символа подряд) сделать этот ход
    while (!found && move < board.size())
    {
        if (isLegal(move))
        {
            // Попытка хода
            board[move] = computer;
            // Проверка на победу
            found = winner() == computer;
            board[move] = EMPTY;
        }

        if (!found)
        {
            ++move;
        }
    }

    // Иначе, если игрок может выиграть следующим ходом (2 символа подряд), прервать его
    if (!found)
    {
        move = 0;
        char human = opponent(computer);

        while (!found && move < board.size())
        {
            if (isLegal(move))
            {
                // Попытка хода
                board[move] = human;
                // Проверка на победу
                found = winner() == human;
                board[move] = EMPTY;
            }

            if (!found)
            {
                ++move;
            }
        }
    }

    // Иначе, занять самую выгодную из оставшихся позиций
    if (!found)
    {
        move = 0;
        unsigned int i = 0;

        const int BEST_MOVES[] = {4, 0, 2, 6, 8, 1, 3, 5, 7};

        while (!found && i <  board.size())
        {
            move = BEST_MOVES[i];
            if (isLegal(move))
            {
                found = true;
            }

            ++i;
        }
    }

    cout << "Я занимаю поле под номером " << move << endl;
    return move;
}
// ---------------------------------------------------------------------------

// --------------------- Метод объявления победителя -------------------------
void Game::announceWinner(char winner, char computer, char human)
{
    if (winner == computer)
    {
        cout << winner << "-> победил Компьютер!\n";
        cout << "Ты проигра, человек! Как я и предсказывал, компьютеры - высший разум\n";
        cout << "Ха-ха-ха!!!\n";
    }

    else if (winner == human)
    {
        cout << winner << "-> победил Игрок!\n";
        cout << "Неет, ты обставил меня, человек!\n";
        cout << "Но мы еще встретимся, и тебя уже никто не спасет!\n";
    }

    else
    {
        cout << "Ничья!\n";
        cout << "На этот раз тебе повезло, человек! \n";
        cout << "Празднуй... Но мы еще встретимся, и тебя уже никто не спасет!\n";
    }
}
// ---------------------------------------------------------------------------

// ------------- Метод объявления победителя (vs Player 2) -------------------
void Game::showPlayersWinner(char winner, char player2, char human)
{
    if (winner == player2)
    {
        cout << winner << "-> победил Игрок 2!\n";
    }

    else if (winner == human)
    {
        cout << winner << "-> победил Игрок 1!\n";
    }

    else
    {
        cout << "Ничья!\n";
    }
}
// ---------------------------------------------------------------------------
