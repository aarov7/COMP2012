CPPFLAGS = -std=c++11
SRCS = main.cpp board.cpp boardtree.cpp hashtable.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)
COMPILER = g++

all: pa3.exe

pa3.exe: $(OBJS)
	$(COMPILER) -o $@ $(CPPFLAGS) $^

%.o: %.cpp
	$(COMPILER) $(CPPFLAGS) -MMD -MP -c $< -o $@

-include $(DEPS)

clean:
	del *.o *.d pa3.exe

.PRECIOUS: $(OBJS)