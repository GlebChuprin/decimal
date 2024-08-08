CC = gcc

# Флаги
CFLAGS = -Wall -Wextra -Werror -std=c11 -g -O0 
GCOVFLAGS = -fprofile-arcs -ftest-coverage
DEBUG = -DDEBUG
LDFLAGS = -lgcov

# Директории
DECIMAL_DIR = decimal
TEST_DIR = tests

# Поддиректории
BINARY = binary
BINARY_ARITHMETIC = $(BINARY)/binary_arithmetic
ARITHMETIC = arithmetic
ARITHMETIC_SERVICE = $(ARITHMETIC)/service
CONVERSION = conversion
COMPARISON = comparison
OTHER = other

# Обьявление общих директорий для DECIMAL_DIR и TEST_DER
COMMON_DIR = $(ARITHMETIC) $(COMPARISON) $(CONVERSION) $(OTHER)

# Наполнений директорий SRC_DIRS и TEST_DIRS
SRC_DIRS = $(addprefix $(DECIMAL_DIR)/, $(COMMON_DIR) $(BINARY) $(BINARY_ARITHMETIC) $(ARITHMETIC_SERVICE))
TEST_DIRS = $(addprefix $(TEST_DIR)/, $(COMMON_DIR)) $(TEST_DIR)

# Присвоение суфикса /*.c и создания множества .c файлов
SRCS = $(wildcard $(addsuffix /*.c, $(SRC_DIRS)))
TEST_SRCS = $(wildcard $(addsuffix /*.c, $(TEST_DIRS)))

# Объектные файлы
OBJS = $(SRCS:.c=.o)
TEST_OBJS = $(TEST_SRCS:.o=.c)

# Инклюды
INCLUDES = $(addprefix -I, $(SRC_DIRS) $(TEST_DIRS) $(DECIMAL_DIR))

OS = $(shell uname)

ifeq ($(OS), Linux)
	CHECKFLAGS = -lcheck -lm -lsubunit 
else
	CHECKFLAGS = -lcheck 
endif

all : decimal.a test gcov_report

decimal.a: $(OBJS) 
	@ar rcs $@ $^

debug: CFLAGS += $(DEBUG)
debug: test

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

test : $(TEST_DIR)/decimal_test.c decimal.a $(TEST_OBJS)
	$(CC) $^ $(CHECKFLAGS) $(CFLAGS) $(INCLUDES) -o $@

gcov_report:
	$(CC) $(SRCS) $(TEST_SRCS) $(CHECKFLAGS) $(CFLAGS) $(INCLUDES) $(GCOVFLAGS) $(LDFLAGS) -o report.out
	./report.out
	find ./ -type f -iname '*.gcda'
	lcov -o report.info -c -d .
	rm -rf ./cov-report
	mkdir ./cov-report
	genhtml -o ./cov-report/ report.info
	rm *.gcno *.gcda report.out report.info

.PHONY: decimal.a test debug clean *.o 

SRC_CLEAN = $(addsuffix /*.o, $(SRC_DIRS))
TEST_CLEAN = $(addsuffix /*.o, $(TEST_DIRS)) $(TEST_DIR)/*.o

clean:
	rm -f $(SRC_CLEAN) $(TEST_CLEAN) rm *.gcno *.gcda \
	report.out report.info test decimal.a
