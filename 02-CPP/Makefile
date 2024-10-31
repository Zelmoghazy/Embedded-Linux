CC=gcc
EXT=c

OPT=
DBG=
STD=-std=c11
WARNINGS=-Wall -Wextra -Wsign-conversion -Wconversion
DEPFLAGS=-MP -MD
DEF=-DTRACY_ENABLE

INCS=$(foreach DIR,$(INC_DIRS),-I$(DIR))
LIBS=$(foreach DIR,$(LIB_DIRS),-L$(DIR))
LIBS+=-lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lws2_32 -ldbghelp -ldwmapi -luxtheme

PPFLAGS=$(INCS) $(DEPFLAGS) $(DEF)
CFLAGS=$(DBG) $(OPT) $(STD) $(WARNINGS) -ffast-math -fopenmp -mwindows 
LDFLAGS=$(LIBS)

FLAGS=$(PPFLAGS) $(CFLAGS) $(LDFLAGS) 

INC_DIRS=. ./external/include/ ./include/
LIB_DIRS=. ./external/lib
BUILD_DIR=build
CODE_DIRS=. src 
VPATH=$(CODE_DIRS)

SRC=$(foreach DIR,$(CODE_DIRS),$(wildcard $(DIR)/*.$(EXT)))
OBJ=$(addprefix $(BUILD_DIR)/,$(notdir $(SRC:.$(EXT)=.o)))
DEP=$(addprefix $(BUILD_DIR)/,$(notdir $(SRC:.$(EXT)=.d)))

PROJ=Main
EXEC=$(PROJ)

all: $(BUILD_DIR)/$(EXEC)
    @echo "========================================="   
    @echo "              BUILD SUCCESS              "
    @echo "========================================="

release: OPT += -O2 
release: all

debug: DBG += -g -gdwarf-2
debug: OPT += -O0
debug: all

$(BUILD_DIR)/%.o: %.$(EXT) | $(BUILD_DIR)
    $(CC) -c $< -o $@ $(FLAGS)
$(BUILD_DIR)/$(EXEC): $(OBJ)
    $(CC) $^ -o $@ $(FLAGS)

$(BUILD_DIR):
    mkdir $@
    cp ./external/lib/*.dll ./build/
    $(info SRC_DIRS : $(CODE_DIRS))
    $(info INC_DIRS : $(INC_DIRS))
    $(info INCS     : $(INCS))
    $(info SRC_FILES: $(SRC))
    $(info OBJ_FILES: $(OBJ))   
    @echo "========================================="

clean:
    rm -fR $(BUILD_DIR)

profile:
    start Tracy;start ./$(BUILD_DIR)/$(EXEC);

-include $(DEP)

.PHONY: all clean profile