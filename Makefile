CXXCOMPILER=g++
DEBUGGER=gdb
CXXFLAGS=-lstdc++ -x c++
DEBUG_CXXFLAGS=lstdc++ -x c++ -g
FILES= \
JDASM_CORE.cpp \
main.cpp

Build/JDASM: $(FILES)
	mkdir -p Build
	$(CXXCOMPILER) $(CXXFLAGS) -o Build/JDASM $(FILES)

Build/JDASM_debug: $(FILES)
	mkdir -p Build
	$(CXXCOMPILER) $(DEBUG_CXXFLAGS) -o Build/JDASM_debug $(FILES)
	objcopy --only-keep-debug Build/JDASM_debug JDASM_debug.debug
	mv JDASM_debug.debug Build/JDASM_debug.debug

Debug: Build/JDASM_debug
	$(DEBUGGER) -s Build/JDASM_debug.debug -x Build/JDASM_debug

run: Build/JDASM
	./Build/JDASM

install: Build/JDASM
	sudo install -D -m 755 Build/JDASM /usr/local/bin/jdasm

clean:
	rm -rf Build