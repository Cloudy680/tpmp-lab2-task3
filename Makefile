# Makefile для tp-lab2-gr12b
# Автор: Янушкевич Максим
# Группа: 12

# Компилятор и флаги
CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -std=c99 -g
LDFLAGS =

# Директории
SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

# Исходные файлы
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/group.c
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/group.o
TARGET = $(BIN_DIR)/lab3-task3

# Цель по умолчанию
all: $(TARGET)

# Сборка исполняемого файла
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)
	@echo "Сборка завершена. Исполняемый файл: $@"

# Компиляция main.c
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c $(INCLUDE_DIR)/group.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Компиляция group.c
$(OBJ_DIR)/group.o: $(SRC_DIR)/group.c $(INCLUDE_DIR)/group.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Создание директорий
$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

# Очистка проекта
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo "Проект очищен."

# Запуск программы
run: $(TARGET)
	$(TARGET)

# Для GitHub Actions
check: all
	@echo "Проверка сборки завершена."

# Псевдо-цели
.PHONY: all clean run check
