TARGET = ./a.out

HDRS_DIR = \
		matrix

SRCS = \
		matrix_impl.cpp \
		matrix_main.cpp

.PHONY: all, build, clean, run

$(TARGET):
		g++ -I $(HDRS_DIR) $(SRCS) -o $(TARGET)

all: clean build

build: $(TARGET)

clean: 
		rm -rf $(TARGET)
run:
		$(TARGET)