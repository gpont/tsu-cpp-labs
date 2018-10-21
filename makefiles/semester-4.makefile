# @param TEST - название теста
# @param IMPORTS - список нужных объектных файлов C++

# Подсветка синтаксиса, если возможно
COLORGCC:=$(shell colorg++ --version 2>/dev/null)
ifdef COLORGCC
	CPPC = colorg++
else
	CPPC = g++
endif

DEBUGGER = gdb

# Директории
SOURCES_CPP_DIR = sources
OBJECTS_DIR = objects
HEADERS_DIR = headers
BINARY_DIR = binary
TESTS_DIR = tests

# Флаги
CPPFLAGS = -g -std=c++14 -I./$(HEADERS_DIR)
CPPFLAGS_WARNINGS = -Wall -Wpedantic -Wextra
CPPFLAGS_HEADERS = -c

GDB_FLAGS = -tui -q

# Файлы
SOURCES_CPP = $(addsuffix .cpp,$(addprefix $(SOURCES_CPP_DIR)/,$(IMPORTS)))
OBJECTS_CPP = $(addsuffix .o,$(addprefix $(OBJECTS_DIR)/,$(IMPORTS)))
SOURCE_TEST = $(TESTS_DIR)/$(TEST).cpp
TEST_BIN = $(BINARY_DIR)/$(TEST)

# Рецепты ------------------------------------------------------------------

$(TEST_BIN): $(OBJECTS_CPP) $(SOURCE_TEST)
	@echo "\033[7;4mCompiling "$@":\033[0m"
	@$(CPPC) $(CPPFLAGS) $(CPPLAGS_WARNINGS) $(OBJECTS_CPP) $(SOURCE_TEST) -o $@

$(OBJECTS_CPP): $(OBJECTS_DIR)/%.o: $(SOURCES_CPP_DIR)/%.cpp
	@echo "\033[7;4mCompiling "$@":\033[0m"
	@$(CPPC) $(CPPFLAGS) $(CPPFLAGS_WARNINGS) $(CPPFLAGS_HEADERS) $< -o $@

run:
	@echo "\033[7;4mRunning $(TEST_BIN):\033[0m"
	@./$(TEST_BIN)

all: $(TEST_BIN)
	@make mkdirs
	@make IMPORTS="$(IMPORTS)" $(TEST) test

clean:
	@rm -rf $(OBJECTS_CPP) $(TEST_BIN)

mkdirs:
	@mkdir -p $(BINARY_DIR) $(OBJECTS_DIR)

tests:
	@make clean -s
	@make -s
	@make run -s

debug:
	@make clean -s
	@make -s
	@echo "\033[7;4mDebugger running:\033[0m"
	@$(DEBUGGER) $(GDB_FLAGS) $(TEST_BIN)