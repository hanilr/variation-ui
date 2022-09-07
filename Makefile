# ---------------------------------------------------- #
# SINGLE-HEADER TERMINAL USER INTERFACE | VARIATION-UI #
#          SHARED-LIBRARY CONVERTING MAKEFILE          #
# ---------------------------------------------------- #

CC = gcc
ANSI = -std=c89

lib = vn_ui.h
win_out = vn_ui.dll
uni_out = vn_ui.so

.PHONY: run clean install uninstall

run: $(lib)
ifeq ($(OS),Windows_NT)
	$(CC) $(ANSI) -shared -fPIC $(lib) -o $(win_out)
else
	$(CC) $(ANSI) -shared -fPIC $(lib) -o $(uni_out)
endif

clean:
ifeq ($(OS),Windows_NT)
	del $(win_out)
else
	rm $(uni_out)
endif

install: $(lib)
ifeq ($(OS),Windows_NT)
# INSTALL FOR WINDOWS SECTION
else
	sudo mkdir /usr/include/vn
	sudo cp vn_ui.h /usr/include/vn
	sudo chmod -x /usr/include/vn/vn_ui.h
endif

uninstall:
ifeq ($(OS),Windows_NT)
# UNINSTALL FOR WINDOWS SECTION
else
	sudo rm -rf /usr/include/vn
endif

# MADE BY @hanilr #