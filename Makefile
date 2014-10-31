
HDR = $(wildcard include/*.h)
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
BIN = rgxr

CFLAGS += -Iinclude
CFLAGS += -Wall -Wextra -Werror -Wstrict-prototypes
CFLAGS += -std=gnu99 -D_GNU_SOURCE
CLFAGS += -O3

all: $(BIN)

%.o: %.c $(HDR)
	@ echo "CC -c -o $@"
	@ $(CC) $(CFLAGS) -c -o $@ $<

$(BIN): $(OBJ)
	@ echo "CC -o $@"
	@ $(CC) $(LDFLAGS) -o $@ $^

clean:
	$(RM) $(BIN) $(OBJ)