#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

const char* filename = 0;
const char* useful_string = "type flag.txt";

int __attribute__((naked)) useful_gadget(void)
{
   asm volatile (
     "pop  rcx\r\n"
     "ret\r\n"
   );
}

void win(char* command)
{
    system(command);
}

void pwnme(void)
{
    fputs("split by ROP Emporium (modified by VPR for win\nx86_64)\n\n"
          "Contriving a reason to ask for user for data...\n\n> ", stdout);
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
        read(0, buffer, 0x60);
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
