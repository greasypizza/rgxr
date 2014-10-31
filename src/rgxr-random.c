
#include <stdio.h>
#include <unistd.h>

#include "rgxr-random.h"
#include "rgxr-strings.h"

#define MIN_PRINTABLE ' '
#define MAX_PRINTABLE '~'

int getrandom_printable(int fd, char *buf, size_t buflen)
{
    int rc = -1;

    for (size_t i = 0; i < buflen; i++) {
        char c = 0;
        while (c < MIN_PRINTABLE || c > MAX_PRINTABLE) {
            int bytes = read(fd, &c, 1);
            if (bytes == -1) {
                printf(SYSERR(read));
                goto cleanup;
            }
        }
        buf[i] = c;
    }

    rc = 0;
 cleanup:
    return rc;
}