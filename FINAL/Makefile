CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla
EXEC = biquadris
OBJECTS = main.o gameboard.o cell.o existing.o block.o block_i.o block_l.o block_o.o block_t.o block_j.o block_s.o block_z.o block_lvl4.o level.o level_0.o level_1.o level_2.o level_3.o level_4.o board.o effects.o force.o heavy.o blind.o textdisp.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
