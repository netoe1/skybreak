#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ncurses.h>
#include <signal.h>

enum WIFI_TYPES
{
    WEP,
    WPA
};

void main_menu();      // Main menu for skybreak.
void configncurses();  // Setting ncurses default's settings
void settingSignals(); // Configuring default's settings for signals
void signal_handler(int signum);
int main(void)
{
    setlocale(LC_ALL, "");
    initscr(); // Start ncurses win.
    configncurses();
    settingSignals();
    main_menu();
    endwin(); // Close ncurses's win.
    return EXIT_FAILURE;
}
void main_menu()
{
    printw("Welcome to the Skybreak wifi cracking tool.\nInspired in WTTG2, thanks Adam!\n");
    getch();
}
void configncurses()
{
    if (!has_colors())
    {
        endwin();
        printf("skybreak-error: Colors are not allowed on this version...\n");
        exit(EXIT_FAILURE);
    }

    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    attron(COLOR_PAIR(1));
}
void signal_handler(int signum)
{
    if (signum == SIGINT || signum == SIGTERM || signum == SIGKILL)
    {
        endwin();
    }
}
void settingSignals()
{
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);
    signal(SIGKILL, signal_handler);
}