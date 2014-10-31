
#include <fcntl.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "rgxr-strings.h"
#include "rgxr-random.h"
#include "strtonum.h"

#define MAX_LEN 30

int main(int argc, char **argv)
{
    int output_len;
    regex_t regex;
    int randfd = -1;
    char output[MAX_LEN + 1];
    const char *errstr = NULL;
    int rc = EXIT_FAILURE;

    if (argc != 3) {
        printf(USAGE_STR, argv[0]);
        goto cleanup;
    }

    output_len = strtonum(argv[1], 1, MAX_LEN, &errstr);
    if (errstr) {
        printf(ERR_INVALID_LENGTH, argv[1], errstr);
        goto cleanup;
    }

    if (regcomp(&regex, argv[2], REG_EXTENDED) != 0) {
        printf(ERR_REGCOMP);
        goto cleanup;
    }

    randfd = open("/dev/urandom", O_RDONLY);
    if (randfd == -1) {
        printf(SYSERR(open));
        goto cleanup;
    }

    output[output_len] = '\0';
    for (;;) {
        if (getrandom_printable(randfd, output, output_len) == -1) {
            printf(ERR_GETRANDOM);
            goto cleanup;
        }

        if (regexec(&regex, output, 0, NULL, 0) == 0)
            break;        
    }

    printf("%s\n", output);
    rc = 0;
 cleanup:
    if (randfd != -1) {
        close(randfd);
    }
    return rc;
}