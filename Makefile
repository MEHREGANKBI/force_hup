DEBUG_FLAGS=-pedantic-errors -ggdb -O0 -Wall -Wextra -Wconversion -Wsign-conversion -o

RELEASE_FLAGS=-O2 -DNDEBUG -Wall -Wextra -Wconversion -Wsign-conversion  -o

CC=gcc

default: debug

debug: src/main.c
	$(CC) $(DEBUG_FLAGS) debug.elf $^

release: src/main.c
	$(CC) $(RELEASE_FLAGS) force_hup.elf $^

clean:
	rm -v *.elf

install: release
	mkdir -p ~/.local/bin/ && \
	mv -T ./force_hup.elf ~/.local/bin/force_hup && \
	echo "Success!"

uninstall:
	rm -v ~/.local/bin/force_hup