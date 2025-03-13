
CC := g++

MIPSCC := /opt/codefidence_/bin/mipsel-linux-uclibc-g++ 

OUTPUT := log-client

INCLUDES := /usr/include/

LIBS := -lpthread
DEEP_WARNING =  1

FLAGS := -D_REENTRANT -DDEBUG

ifdef DEEP_WARNING
FLAGS += -Wall -Wextra
endif

STRIP := strip $(OUTPUT)

STRIP_MIPS := /opt/codefidencvoid PrintBuffer(uint8_t* buf, uint32_t bufSize)e/bin/mipsel-linux-uclibc-strip $(OUTPUT)


SOURCES = func.cpp main.cpp

all:
	$(MIPSCC) $(LIBS) $(FLAGS) -I $(INCLUDES) -o $(OUTPUT)  $(SOURCES)
pc:
	$(CC) $(LIBS) $(FLAGS) -ggdb -g3 -I $(INCLUDES) -o $(OUTPUT)_pc $(SOURCES)
	#$(STRIP)_gcc

clean:
	rm $(OUTPUT)	