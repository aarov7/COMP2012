CPPFLAGS = -fsanitize=address,leak,undefined # -static-libgcc -static-libstdc++
COMPILER = g++11
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

all: lab7.exe

lab7.exe: $(OBJS)
	$(COMPILER) -o $@ $(CPPFLAGS) $^

%.o: %.cpp
	$(COMPILER) -o $@ $(CPPFLAGS) -MMD -MP -c $<

-include $(DEPS)

clean:
	rm -f *.o *.exe *.d
# (Windows) del *.o *.exe *.d
# (Linux or MacOS) rm -f *.o *.exe *.d