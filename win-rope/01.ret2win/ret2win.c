#include <stdio.h>

int main(void)
{
    fputs("ret2win by ROP Emporium\nx86_64\n\n"
          "For my first trick, I will attempt to fit 56 bytes of user input into 32 bytes of stack buffer!\n"
          "What could possibly go wrong?\n"
          "You there, may I have your input please? And don't worry about null bytes, we're using read()!\n> ", stdout);

    char buffer[16] = { 0 };
    if (scanf("%s", buffer) != 1)
    {
        fputs("Failed to read your input.\n\nExiting\n", stderr);
        return 1;
    }

    fputs("Thank you!\n\nExiting\n", stdout);

    return 0;
}
