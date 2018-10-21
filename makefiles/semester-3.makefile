# @param BIN - название теста
# @param HARD: 0 - without Werror, 1 - Werror set

# Подсветка синтаксиса, если возможно
COLORGCC:=$(shell colorg++ --version 2>/dev/null)
ifdef COLORGCC
	CC = colorg++
else
	CC = g++
endif

# Директории
SOURCES_DIR = sources
TESTS_DIR = tests
OBJECTS_DIR = objects
HEADERS_DIR = headers
BINARY_DIR = binary

# Флаги
ifdef HARD
	CFLAGS_WARNINGS = -Wall -Wpedantic -Wextra -Werror
else
	CFLAGS_WARNINGS = -Wall -Wpedantic -Wextra
endif
CFLAGS = -g -std=c++14 -I./$(HEADERS_DIR)
CFLAGS_HEADERS = -c

# Файлы
SOURCES_LIB = $(wildcard $(SOURCES_DIR)/*.cpp)
SOURCES_EXECUTABLE = $(TESTS_DIR)/$(BIN).cpp
OBJECTS = $(addprefix $(OBJECTS_DIR)/,$(notdir $(SOURCES_LIB:.cpp=.o)))
EXECUTABLE = $(addprefix $(BINARY_DIR)/,$(BIN))

# Рецепты ------------------------------------------------------------------

$(EXECUTABLE): $(OBJECTS) $(SOURCES_EXECUTABLE)
	@$(CC) $(CFLAGS) $(CFLAGS_WARNINGS) $(OBJECTS) $(SOURCES_EXECUTABLE) -o $@

$(OBJECTS): $(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.cpp
	@$(CC) $(CFLAGS) $(CFLAGS_WARNINGS) $(CFLAGS_HEADERS) $< -o $@

run:
	@./$(EXECUTABLE)

all:
	@make make_dirs
	@make $(EXECUTABLE)

clean:
	@rm -rf $(OBJECTS_DIR)/*.o $(BINARY_DIR)/*

rebuild:
	@make clean -s
	@make test -s

make_dirs:
	@mkdir -p $(BINARY_DIR) $(OBJECTS_DIR)

test:
	@echo -en "\033[7;4mCompiling:\033[0m\n"
	@make -s
	@echo -en "\033[7;4mRunning:\033[0m\n"
	@make run -s
