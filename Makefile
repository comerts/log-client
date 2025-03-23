#CROSS_COMPILE=aarch64-linux-gnu-

CXX ?= $(CROSS_COMPILE)g++

TARGET ?= log-client

INCLUDES ?= -I/usr/include/

LDFLAGS ?=  -lpthread -lrt

CFLAGS ?= -Werror -Wall -Wextra -Wno-format-truncation -D_REENTRANT -DDEBUG

STRIP_PC ?= strip $(TARGET)_pc

STRIP ?= $(CROSS_COMPILE)strip $(TARGET)

SOURCES = func.cpp main.cpp

all:
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $(TARGET)  $(SOURCES)
#	$(STRIP)
pc:
	g++ $(CFLAGS) $(LDFLAGS) -ggdb -g3 $(INCLUDES) -o $(TARGET)_pc $(SOURCES)
#	$(STRIP_PC)

clean:
	rm -rf *.o $(TARGET) $(TARGET)_pc
