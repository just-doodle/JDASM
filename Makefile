# Copyright (C) 2021 arun007coder
# 
# This file is part of JDASM.
# 
# JDASM is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# JDASM is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with JDASM.  If not, see <http://www.gnu.org/licenses/>.

CXX=g++
DEBUGGER=gdb
CXXFLAGS=-lstdc++ -x c++ -Wno-write-strings
DEBUG_CXXFLAGS=-lstdc++ -x c++ -g
FILES= \
ASM/JDASM_CORE.cpp \
main.cpp

Build/JDASM: $(FILES)
	mkdir -p Build
	$(CXX) $(CXXFLAGS) -o Build/JDASM $(FILES)

Build/JDASM_debug: $(FILES)
	mkdir -p Build
	$(CXX) $(DEBUG_CXXFLAGS) -o Build/JDASM_debug $(FILES)
	objcopy --only-keep-debug Build/JDASM_debug JDASM_debug.debug
	mv JDASM_debug.debug Build/JDASM_debug.debug

Debug: Build/JDASM_debug
	$(DEBUGGER) -s Build/JDASM_debug.debug -e Build/JDASM_debug

run: Build/JDASM
	./Build/JDASM

install: Build/JDASM
	sudo install -D -m 755 Build/JDASM /usr/local/bin/jdasm
	rm -rf Build

clean:
	rm -rf Build