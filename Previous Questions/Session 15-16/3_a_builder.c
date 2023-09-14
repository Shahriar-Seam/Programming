#include <stdio.h>

int main()
{
    int i;
    FILE *fp;
    char filename[] = "3_a.c";

    fp = fopen(filename, "w");

    fprintf(fp, "#include <stdio.h>\n");
    fprintf(fp, "\n");
    fprintf(fp, "int main()\n");
    fprintf(fp, "{\n");
    fprintf(fp, "\tint n;\n");
    fprintf(fp, "\tdouble money;\n");
    fprintf(fp, "\tscanf(%c%%d%c, &n);\n\n", 34, 34);
    fprintf(fp, "\tswitch (n) {\n");

    for (i = 0; i < 100; i++) {
        fprintf(fp, "\t\tcase %d:\n", i);
        fprintf(fp, "\t\t\tprintf(%c%d%c);\n", 34, i, 34);
        fprintf(fp, "\t\t\tbreak;\n");
    }

    fprintf(fp, "\n");

    for (i = 100; i < 200; i++) {
        fprintf(fp, "\t\tcase %d:\n", i);
        fprintf(fp, "\t\t\tmoney = (double) n - (n * 0.05);\n");
        fprintf(fp, "\t\t\tprintf(%c%%g%c, money);\n", 34, 34);
        fprintf(fp, "\t\t\tbreak;\n");
    }

    fprintf(fp, "\n");

    for (i = 200; i < 300; i++) {
        fprintf(fp, "\t\tcase %d:\n", i);
        fprintf(fp, "\t\t\tmoney = (double) n - (n * 0.075);\n");
        fprintf(fp, "\t\t\tprintf(%c%%g%c, money);\n", 34, 34);
        fprintf(fp, "\t\t\tbreak;\n");
    }

    fprintf(fp, "\n");

    fprintf(fp, "\t\tdefault:\n");
    fprintf(fp, "\t\t\tmoney = (double) n - (n * 0.1);\n");
    fprintf(fp, "\t\t\tprintf(%c%%g%c, money);\n", 34, 34);
    fprintf(fp, "\t\t\tbreak;\n");
    fprintf(fp, "\t}\n");

    fprintf(fp, "\n\n");

    fprintf(fp, "\treturn 0;\n");
    fprintf(fp, "}");
    
    fclose(fp);

    return 0;
}