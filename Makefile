# Kompiler & Flag
CXX      := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -Iinclude

# Folder
SRC_DIR := src
INC_DIR := include
OBJ_DIR := build

# File Target Executable
TARGET := engine_1d.out

# Otomatis cari semua file .cpp di src/ dan tambahkan main.cpp
SRCS := $(wildcard $(SRC_DIR)/*.cpp) main.cpp
OBJS := $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Rule Utama
all: $(TARGET)

# Linksemua .o menjadi satu file binary/executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Kompilasi setiap file .cpp menjadi file objek .o di folder build/
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Jalankan program
run: $(TARGET)
	./$(TARGET)

# Bersihkan file hasil kompilasi
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all run clean