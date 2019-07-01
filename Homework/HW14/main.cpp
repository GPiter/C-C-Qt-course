/*
 * Задание 14 - Крестики-нолики
 *
 * Автор: Ганин П.А.
 */

#include "game.h"

using namespace std;

int main() {
    Game TicTacToe;
    int mode = TicTacToe.chooseMode(); // Выбор режима игры
    TicTacToe.instructions(); // Вывод правил игры

// --- Режим 1 - против компьютера ---

    if (mode == 1) {

// ------- Запрос хода игрока --------

    char human = TicTacToe.humanPiece();            // Спрашивает, будет ли игрок ходить первым
    char computer = TicTacToe.opponent(human);      // Определение хода компьютера
    char turn = X;                                  // Переменная для проверки условия первого хода

// --------------------------------------

    TicTacToe.displayBoard();                       // Отрисовка поля

    while (TicTacToe.winner() == NO_ONE)            // Пока не выявлен победитель
    {
        if (turn == human)
        {
            TicTacToe.move = TicTacToe.humanMove(); // Заполнение поля после хода игрока
            TicTacToe.board[TicTacToe.move] = human;
        }
        else
        {
            TicTacToe.move = TicTacToe.computerMove(computer); // Заполнение поля после хода компьютера
            TicTacToe.board[TicTacToe.move] = computer;
        }
        TicTacToe.displayBoard();
        turn = TicTacToe.opponent(turn);
        TicTacToe.panelControl(); // Отрисовка панели управления
    }

    TicTacToe.announceWinner(TicTacToe.winner(), computer, human); // Оглашение победителя
}

// --- Режим 2 - против компьютера ---

    if (mode == 2) {

    char human = X;
    char computer = O;
    char turn = X;

    TicTacToe.displayBoard();

    while (TicTacToe.player2winner() == NO_ONE)
    {
        if (turn == human)
        {
            TicTacToe.move = TicTacToe.humanMove();
            TicTacToe.board[TicTacToe.move] = human;
        }
        else
        {
            TicTacToe.move = TicTacToe.player2Move();
            TicTacToe.board[TicTacToe.move] = computer;
        }
        TicTacToe.displayBoard();
        turn = TicTacToe.opponent(turn);
        TicTacToe.panelControl();
    }

    TicTacToe.showPlayersWinner(TicTacToe.winner(), computer, human);
    }

    return 0;

}
