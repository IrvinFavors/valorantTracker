CC = g++
CFLAGS = -Wall

TARGET = tracker
SRCS = trackerMain.cpp trackerMisc.cpp valorant.cpp tools.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
	$(CC) $(CFLAGS) -MM -MT $@ -MF $(patsubst %.o,%.d,$@) $<

-include $(DEPS)

trackerMain.o: headers/tracker.hpp