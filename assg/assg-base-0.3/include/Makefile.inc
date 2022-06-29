# compiler flags, tools and include variables
VERSION=0.3
BASE_NAME=assg-base-$(VERSION)
BASE_DIR := ../$(BASE_NAME)
GCC_FLAGS=-Wall -Werror -pedantic -g
GCC=g++
INC=-Iinclude -I$(BASE_DIR)/include

FORMATTER=clang-format
DOC=doxygen
PANDOC=pandoc
RM=rm -rf

FORMATTER_FLAGS=-i
DOC_FLAGS=$(BASE_DIR)/config/Doxyfile
PANDOC_FLAGS=-s --variable geometry:margin=0.75in --variable urlcolor:NavyBlue --variable colorlinks:true
PANDOC_HIGHLIGHT=--highlight-style tango


SRC_DIR := src
OBJ_DIR := obj
DOC_DIR := doc
BIN_DIR := .
TEST_TARGET=$(BIN_DIR)/test
DEBUG_TARGET=$(BIN_DIR)/debug


# sources and objects needed to be linked together for unit test executable
test_src := $(patsubst %.cpp, $(SRC_DIR)/%.cpp, $(test_src))
test_obj := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(test_src))
catch_test_obj := $(BASE_DIR)/$(OBJ_DIR)/catch2-main.o

# objects needed to be linked together for main/debug executable
debug_src := $(patsubst %.cpp, $(SRC_DIR)/%.cpp, $(debug_src))
debug_obj := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(debug_src))

# pdf files for assignment description documentation
assg_doc := $(patsubst %.pdf, $(DOC_DIR)/%.pdf, $(assg_doc))

## List of all valid targets in this project:
## ------------------------------------------
## all          : by default generate all executables
##                (test and debug)
##
.PHONY : all
all : $(TEST_TARGET) $(DEBUG_TARGET)


## test         : Build and link together unit test executable
##
$(TEST_TARGET) : $(test_obj) $(catch_test_obj) $(template_files)
	$(GCC) $(GCC_FLAGS) $(test_obj) $(catch_test_obj) -o $@


## debug        : Build and link together debug executable
##
$(DEBUG_TARGET) : $(debug_obj) $(template_files)
	$(GCC) $(GCC_FLAGS) $(debug_obj) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(GCC) $(GCC_FLAGS) $(INC) -c $< -o $@

$(BASE_DIR)/$(OBJ_DIR)/%.o: $(BASE_DIR)/$(SRC_DIR)/%.cpp | $(BASE_DIR)/$(OBJ_DIR)
	$(GCC) $(GCC_FLAGS) $(INC) -c $< -o $@


$(OBJ_DIR):
	mkdir -p $@

$(BASE_DIR)/$(OBJ_DIR):
	mkdir -p $@


## tests        : Run the unit tests showing failing tests only
##
tests : $(TEST_TARGET)
	./$(TEST_TARGET) --use-colour yes


## format       : Run the code formatter/beautifier by hand if needed
##
.PHONY : format
format :
	$(FORMATTER) $(FORMATTER_FLAGS) include/*.hpp src/*.cpp


## refdocs      : Create doxygen reference documentation from
##                doc comments.
##
.PHONY : refdocs
refdocs :
	@echo "Generating doxygen documentation..."
	$(DOC) $(DOC_FLAGS) 2>&1 | grep -A 1 warning | egrep -v "assg.*\.md" | grep -v "Found unknown command" | grep -v "Searching for include" | sed -e "s|${PWD}/||g"


## assgdocs     : Create assignment description documentation from
##                README.md project markdown file.
##
.PHONY : assgdocs
assgdocs : $(assg_doc)

$(assg_doc) : README.md
	${PANDOC} ${PANDOC_FLAGS} ${PANDOC_HIGHLIGHT} -o $@ $^


## submit       : Create a tared and compressed file of
##                assignment files for submission
##
.PHONY : submit
submit :: beautify
	tar cvfz $(PROJECT_NAME).tar.gz include src

## clean        : Remove auto-generated files for a completely
##                clean rebuild
##
.PHONY : clean
clean  :
	$(RM) $(TEST_TARGET) $(DEBUG_TARGET) *.o *.gch
	$(RM) output html latex
	$(RM) $(OBJ_DIR)


## help         : Get all build targets supported by this build.
##
.PHONY : help
help : Makefile $(BASE_DIR)/include/Makefile.inc
	@sed -n 's/^##//p' $^
