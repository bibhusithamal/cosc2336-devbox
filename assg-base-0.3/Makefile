# compiler flags, tools and include variables
GCC_FLAGS=-Wall -Werror -pedantic -g
GCC=g++
INC=-Iinclude
RM=rm -rf


# source files in this project 
test_src  = catch2-main.cpp

SRC_DIR := src
OBJ_DIR := obj
DOC_DIR := doc
BIN_DIR := .

# sources and objects needed to be linked together for unit test executable
test_src := $(patsubst %.cpp, $(SRC_DIR)/%.cpp, $(test_src))
test_obj := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(test_src))
TEST_TARGET=$(test_obj)


## List of all valid targets in this project:
## ------------------------------------------
## all          : by default generate all object files
##
.PHONY : all
all : $(TEST_TARGET)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(GCC) $(GCC_FLAGS) $(INC) -c $< -o $@


$(OBJ_DIR):
	mkdir -p $@


## clean        : Remove auto-generated files for a completely
##                clean rebuild
##
.PHONY : clean
clean  :
	$(RM) $(TEST_TARGET) *.o *.gch
	$(RM) $(OBJ_DIR)


## help         : Get all build targets supported by this build.
##
.PHONY : help
help : Makefile
	@sed -n 's/^##//p' $^
