CC = gcc
CFLAGS = -Wall -Wextra -Werror  -g3 -fsanitize=address
SOURCES = ./curl/c/*.c
TARGET = my_curl

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

.PHONY: fclean

fclean: clean

clean:
	@rm -rf $(TARGET)

make re:
	@rm -rf $(TARGET)
	@$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)