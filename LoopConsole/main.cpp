#include <windows.h>
#include "Tablero/Piece.h" 
#include "Tablero/PieceMatrix.h"

#include <wchar.h>

static const wchar_t* keyUp = L"\x1b[A";
static const wchar_t* keyDown = L"\x1b[B";
static const wchar_t* keyRight = L"\x1b[C";
static const wchar_t* keyLeft = L"\x1b[D";
static const wchar_t* keyEnter = L"\r";

static HANDLE consoleInputHandler, consoleOutputHandler;
static HWND windowHandler;

bool WindowsSetters()
{
    if (!SetConsoleMode(consoleOutputHandler, ENABLE_PROCESSED_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING)) return false;
    if (!SetConsoleMode(consoleInputHandler, ENABLE_VIRTUAL_TERMINAL_INPUT)) return false;
    if (!SetWindowPos(windowHandler, NULL, (1920 / 2) - GLOBALS::WINDOW_SIZE_X / 2, 0, GLOBALS::WINDOW_SIZE_X, 1080, SWP_SHOWWINDOW)) return false;
    if (!ShowScrollBar(windowHandler, SB_BOTH, false)) return false;
    if (!EnableScrollBar(windowHandler, SB_BOTH, ESB_DISABLE_BOTH)) return false;
    return true;
}

void HandlerCloser()
{
    CloseHandle(consoleInputHandler);
    CloseHandle(consoleOutputHandler);
    CloseHandle(windowHandler);
}

int main()
{
    consoleInputHandler = GetStdHandle(STD_INPUT_HANDLE);
    consoleOutputHandler = GetStdHandle(STD_OUTPUT_HANDLE);
    windowHandler = GetConsoleWindow();
    if (consoleOutputHandler == INVALID_HANDLE_VALUE or consoleInputHandler == INVALID_HANDLE_VALUE or windowHandler == INVALID_HANDLE_VALUE or !WindowsSetters())
    {
        HandlerCloser();
        return GetLastError();
    }

    Console::InitScreen();
    wchar_t buffer[16];
    DWORD bytesReaded;
    do
    {
        ReadConsole(consoleInputHandler, buffer, 16, &bytesReaded, NULL);
    } while (memcmp(buffer, keyEnter, bytesReaded * sizeof(wchar_t)));
    printf("\x1b[2J");
    

    Piece piece(Piece::Type::Line);
    PieceMatrix matrix;
    while (true && !Level::LEVELS_FINISHED)
    {
        ReadConsole(consoleInputHandler, buffer, 16, &bytesReaded, NULL);

        if (!memcmp(buffer, keyUp, bytesReaded * sizeof(wchar_t))) matrix.MoveUp();
        else if (!memcmp(buffer, keyRight, bytesReaded * sizeof(wchar_t))) matrix.MoveRight();
        else if (!memcmp(buffer, keyDown, bytesReaded * sizeof(wchar_t))) matrix.MoveDown();
        else if (!memcmp(buffer, keyLeft, bytesReaded * sizeof(wchar_t))) matrix.MoveLeft();
        else if (!memcmp(buffer, keyEnter, bytesReaded * sizeof(wchar_t))) matrix.Rotate();
    }
    printf("\x1b[2J");
    Console::EndScreen();
    Sleep(2000);
    HandlerCloser();
}