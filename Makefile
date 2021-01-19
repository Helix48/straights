ROOT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
CXX = g++
CXXFLAGS = -g -std=c++14 -Wall -MMD -I$(ROOT_DIR)
EXEC = straights 
SRCDIR = src
OBJDIR = objs
SOURCES = $(shell find ${SRCDIR} -type f -name "*.cc")
OBJECTS := $(patsubst $(SRCDIR)/%.cc,$(OBJDIR)/%.o,$(SOURCES))
DEPENDS = ${OBJECTS:.o=.d}

${BINDIR}/${EXEC}: ${OBJECTS} 
	${CXX} -g ${OBJECTS} -o ${EXEC} -lncurses

$(OBJDIR)/%.o: $(SRCDIR)/%.cc | ${OBJDIR}
	$(CXX) $(CXXFLAGS) -c -o $@ $<

${OBJDIR}:
	mkdir $@

-include ${DEPENDS}

.PHONY: clean

clean:
	rm -r ${OBJDIR} ${BINDIR} 
