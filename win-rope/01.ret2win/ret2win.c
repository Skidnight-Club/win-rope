#include <stdio.h>
#include <unistd.h>

const char* filename = 0;

int __attribute__((naked)) useful_gadget(void)
{
   asm volatile (
     "pop  rbp\r\n"
     "ret\r\n"
   );
}

void win(void)
{
    puts("Flag captured.");
}

void pwnme(void)
{
    fputs("ret2win by ROP Emporium (modified by VPR for win\nx86_64)\n\n"
          "For my first trick, I will attempt to fit 56 bytes of user input into 32 bytes of stack buffer!\n"
          "What could possibly go wrong?\n"
          "You there, may I have your input please? And don't worry about null bytes, we're using fread()!\n\n> ", stdout);
    fflush(stdout);

    char buffer[32] = { 0 };
    FILE* fp = NULL;
    if ( filename && (fp = fopen(filename, "rb")) )
    {
        fseek(fp, 0, SEEK_END);
        long n_bytes = ftell(fp);
        fseek(fp, 0, SEEK_SET);
        fread(buffer, n_bytes, sizeof(char), fp);
        fclose(fp);
    }
    else
    {
        read(0, buffer, 56);
    }

    puts("Thank you!");
}

int main(int argc, char** argv)
{
    if (argc > 1) { filename = argv[1]; };
    setvbuf(stdout, 0, 2, 0);
    pwnme();
    puts("\nExiting");
    fflush(stdout);
    return 0;
}
