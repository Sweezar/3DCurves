# Компилятор и флаги
CC = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -fopenmp
LDFLAGS = -L./build -lcurves -Wl,-rpath,'$$ORIGIN' -fopenmp
BUILD_DIR = build

APP_NAME = 3DCurves_app
APP = $(BUILD_DIR)/$(APP_NAME)

APP_DIR = 3DCurves_app

APP_SOURCE = $(APP_DIR)/main.cpp
APP_OBJECT = $(BUILD_DIR)/main.o

LIB_NAME = curves
LIB = lib$(LIB_NAME).so
LIB_DIR = 3DCurves_lib


# Правила сборки
all: lib_build $(APP)

# Запуск
run:
	./$(BUILD_DIR)/$(APP_NAME)

# Сборка библиотеки
lib_build:
	@echo "Сборка библиотеки"
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(LIB_DIR)/build && \
	cd $(LIB_DIR)/build && \
	cmake .. && \
	make && \
	cp $(LIB) ../../$(BUILD_DIR)
	@echo "Библиотека успешно собрана"

# Сборка исполняемого файла
$(APP): $(APP_OBJECT)
	$(CC) -o $@ $< $(LDFLAGS)

$(BUILD_DIR)/main.o: $(APP_SOURCE)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CXXFLAGS) -I./$(LIB_DIR)/inc -c $< -o $@ 

# Очистка
clean:
	@echo "Очистка"
	@rm -rf $(BUILD_DIR) $(LIB_DIR)/build
	@echo "Очистка завершена"

# Форматирование кода
clang:
	clang-format -style=google -i $(LIB_DIR)/src/*.cpp $(APP_SOURCE) $(LIB_DIR)/inc/*.h