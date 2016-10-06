#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp = fopen("1.txt", "r");
    FILE *output = fopen("output.txt", "w");
    if (!fp) {
        printf("ERROR opening input file orig.txt\n");
        exit(0);
    }
    int i = 0;
    char append[50], find[50];
    double one_sum_a = 0.0, one_sum_f = 0.0, one_a, one_f;
    for (i = 0; i < 100; i++) {
        if (feof(fp)) {
            printf("ERROR: You need 100 datum instead of %d\n", i);
            printf("run 'make run' longer to get enough information\n\n");
            exit(0);
        }
        fscanf(fp, "%s %s %lf %lf\n", append, find, &one_a, &one_f);
        one_sum_a += one_a;
        one_sum_f += one_f;
    }
    fclose(fp);

    fp = fopen("2.txt", "r");
    if (!fp) {
        fp = fopen("orig.txt", "r");
        if (!fp) {
            printf("ERROR opening input file opt.txt\n");
            exit(0);
        }
    }
    double two_sum_a = 0.0, two_sum_f = 0.0, two_a, two_f;
    for (i = 0; i < 100; i++) {
        if (feof(fp)) {
            printf("ERROR: You need 100 datum instead of %d\n", i);
            printf("run 'make run' longer to get enough information\n\n");
            exit(0);
        }
        fscanf(fp, "%s %s %lf %lf\n", append, find, &two_a, &two_f);
        two_sum_a += two_a;
        two_sum_f += two_f;
    }
    fclose(fp);

    fp = fopen("4.txt", "r");
    if (!fp) {
        fp = fopen("orig.txt", "r");
        if (!fp) {
            printf("ERROR opening input file opt.txt\n");
            exit(0);
        }
    }
    double four_sum_a = 0.0, four_sum_f = 0.0, four_a, four_f;
    for (i = 0; i < 100; i++) {
        if (feof(fp)) {
            printf("ERROR: You need 100 datum instead of %d\n", i);
            printf("run 'make run' longer to get enough information\n\n");
            exit(0);
        }
        fscanf(fp, "%s %s %lf %lf\n", append, find, &four_a, &four_f);
        four_sum_a += four_a;
        four_sum_f += four_f;
    }
    fclose(fp);

    fp = fopen("8.txt", "r");
    if (!fp) {
        fp = fopen("orig.txt", "r");
        if (!fp) {
            printf("ERROR opening input file opt.txt\n");
            exit(0);
        }
    }
    double eight_sum_a = 0.0, eight_sum_f = 0.0, eight_a, eight_f;
    for (i = 0; i < 100; i++) {
        if (feof(fp)) {
            printf("ERROR: You need 100 datum instead of %d\n", i);
            printf("run 'make run' longer to get enough information\n\n");
            exit(0);
        }
        fscanf(fp, "%s %s %lf %lf\n", append, find, &eight_a, &eight_f);
        eight_sum_a += eight_a;
        eight_sum_f += eight_f;
    }


    fp = fopen("16.txt", "r");
    if (!fp) {
        fp = fopen("orig.txt", "r");
        if (!fp) {
            printf("ERROR opening input file opt.txt\n");
            exit(0);
        }
    }
    double onesix_sum_a = 0.0, onesix_sum_f = 0.0, onesix_a, onesix_f;
    for (i = 0; i < 100; i++) {
        if (feof(fp)) {
            printf("ERROR: You need 100 datum instead of %d\n", i);
            printf("run 'make run' longer to get enough information\n\n");
            exit(0);
        }
        fscanf(fp, "%s %s %lf %lf\n", append, find, &onesix_a, &onesix_f);
        onesix_sum_a +=onesix_a;
        onesix_sum_f +=onesix_f;
}


    fprintf(output, "append() %lf %lf %lf %lf %lf\n",one_sum_a / 100.0, two_sum_a / 100.0, four_sum_a / 100.0, eight_sum_a / 100.0,onesix_sum_a/100.0);
    fprintf(output, "findName() %lf %lf %lf %lf %lf", one_sum_f / 100.0, two_sum_f / 100.0, four_sum_f / 100.0, eight_sum_f / 100.0,onesix_sum_f/100.0);
    fclose(output);
    fclose(fp);
    return 0;
}












/*



    FILE *fp = fopen("orig.txt", "r");
    FILE *output = fopen("output.txt", "w");
    if (!fp) {
        printf("ERROR opening input file orig.txt\n");
        exit(0);
    }
    char append[50], find[50];
    double orig_sum_a = 0.0, orig_sum_f = 0.0, orig_a, orig_f;
    for (int i = 0; i < 100; i++) {
        if (feof(fp)) {
            printf("ERROR: You need 100 datum instead of %d\n", i);
            printf("run 'make run' longer to get enough information\n\n");
            exit(0);
        }
        fscanf(fp, "%s %s %lf %lf\n", append, find,&orig_a, &orig_f);
        orig_sum_a += orig_a;
        orig_sum_f += orig_f;
    }
    fclose(fp);

    fp = fopen("opt.txt", "r");
    if (!fp) {
        fp = fopen("orig.txt", "r");
        if (!fp) {
            printf("ERROR opening input file opt.txt\n");
            exit(0);
        }
    }
    double opt_sum_a = 0.0, opt_sum_f = 0.0, opt_a, opt_f;
    for (int i = 0; i < 100; i++) {
        if (feof(fp)) {
            printf("ERROR: You need 100 datum instead of %d\n", i);
            printf("run 'make run' longer to get enough information\n\n");
            exit(0);
        }
        fscanf(fp, "%s %s %lf %lf\n", append, find,&opt_a, &opt_f);
        opt_sum_a += opt_a;
        opt_sum_f += opt_f;
    }
    fprintf(output, "append() %lf %lf\n", orig_sum_a / 100.0,
            opt_sum_a / 100.0);
    fprintf(output, "findName() %lf %lf", orig_sum_f / 100.0,
            opt_sum_f / 100.0);
    fclose(output);
    fclose(fp);
    return 0;
*/

