CXX = gcc
CXXFLAGS = -I./include
OUT = bin/run.out

SRC = run.c src/*.c build/*.c debug/*.c

run:
	@$(CXX) $(SRC) $(CXXFLAGS) -o $(OUT) -lm
	@./$(OUT)

