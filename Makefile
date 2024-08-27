# 定義變數
CC = gcc
TARGET = a.out
INPUT = in.txt

# 預設目標
all: clean $(TARGET)
	./$(TARGET) < $(INPUT)

# 編譯 C 檔案
$(TARGET): $(S)
	$(CC) $(S) -o $(TARGET) -lm

# 清理目標
clean:
	rm -f $(TARGET)

# 允許 make 時傳入 S 變數
.PHONY: all run clean
