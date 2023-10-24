#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char opcode[10], operand[10], label[10], code[10], mnemonic[3];
    int locctr, start, length;

    FILE *finp, *fopt, *fsym, *fintt;

    finp = fopen("input.txt", "r");
    fopt = fopen("optab.txt", "r");
    fsym = fopen("symtab.txt", "w");
    fintt = fopen("intertab.txt", "w");

    fscanf(finp, "%s\t%s\t%s", label, opcode, operand);
    printf("%s\t%s\t%s", label, opcode, operand);

    if (strcmp(opcode, "START") == 0)
    {
        start = atoi(operand);
        locctr = start;
        fprintf(fintt, "\t%s\t%s\t%s", label, opcode, operand);
        fscanf(finp, "%s\t%s\t%s", label, opcode, operand);
    }

    fclose(finp);
    fclose(fopt);
    fclose(fsym);
    fclose(fintt);

    return 0;
}