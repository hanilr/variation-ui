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
	@$(CC) $(ANSI) -shared -fPIC $(lib) -o $(win_out)
	@echo ""
	@echo "[Compilation successfully completed!]"
else
	@$(CC) $(ANSI) -shared -fPIC $(lib) -o $(uni_out)
	@echo "\033[38;2;55;200;55m"
	@echo "\033[1m\033[4m[Compilation successfully completed!]"
	@echo "\033[0m"
endif

clean:
ifeq ($(OS),Windows_NT)
	@del $(win_out)
	@echo ""
	@echo "[File deleted!]"
else
	@rm $(uni_out)
	@echo "\033[38;2;55;200;55m"
	@echo "\033[1m\033[4m[File deleted!]"
	@echo "\033[0m"
endif

install: $(lib)
ifeq ($(OS),Windows_NT)
# INSTALL FOR WINDOWS SECTION
	@echo ""
	@echo "[There is no installation for Windows!]"
else
	@sudo mkdir -p /usr/include/vn
	@sudo cp vn_ui.h /usr/include/vn
	@sudo chmod -x /usr/include/vn/vn_ui.h

	@echo "\033[38;2;55;200;55m"
	@echo "\033[1m\033[4m[...Installation completed...]"
	@echo "\033[0m"
endif

uninstall:
ifeq ($(OS),Windows_NT)
# UNINSTALL FOR WINDOWS SECTION
	@echo ""
	@echo "[You can't able to do that!]"
else
	@sudo rm /usr/include/vn/vn_ui.h
	@if [ "$(ls -A "/usr/include/vn/" 2> /dev/null)" = "" ]; then sudo rm -rf /usr/include/vn/; fi

	@echo "\033[38;2;55;200;55m"
	@echo "\033[1m\033[4m[...Uninstallation completed...]"
	@echo "\033[0m"
endif

# MADE BY @hanilr #
