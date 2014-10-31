
#define USAGE_STR \
"Usage: %s output_length regex\n"

#define ERR_INVALID_LENGTH \
"Invalid output_length: %s (%s)\n"

#define ERR_GETRANDOM \
"getrandom failure\n"

#define ERR_REGCOMP \
"regcomp failure. Invalid regex?\n"

#define SYSERR(syscall) \
#syscall " error: %m\n"

