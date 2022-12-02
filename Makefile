# ---------------------------------------------------- #
# SINGLE-HEADER TERMINAL USER INTERFACE | VARIATION-UI #
#          SHARED-LIBRARY CONVERTING MAKEFILE          #
# ---------------------------------------------------- #

CC = gcc
ANSI = -std=c89

lib = vn_ui.h
out = vn_ui.so

.PHONY: run compile clean install uninstall

run:
	@echo ""
	@echo "\t\t\033[38;2;55;55;200m[\033[38;2;233;233;233mMake List\033[38;2;55;55;200m]"
	@echo "\033[0m"
	@echo "\033[38;2;55;200;55m1.\033[38;2;233;233;233m Show make list \033[38;2;200;55;55m\033[1m'make' or 'make run'\033[0m"
	@echo "\033[38;2;55;200;55m2.\033[38;2;233;233;233m Compile as shared-library \033[38;2;200;55;55m\033[1m'make compile'\033[0m"
	@echo "\033[38;2;55;200;55m3.\033[38;2;233;233;233m Clean shared-library \033[38;2;200;55;55m\033[1m'make clean'\033[0m"
	@echo "\033[38;2;55;200;55m4.\033[38;2;233;233;233m Install the library \033[38;2;200;55;55m\033[1m'make install'\033[0m"
	@echo "\033[38;2;55;200;55m5.\033[38;2;233;233;233m Uninstall the library \033[38;2;200;55;55m\033[1m'make uninstall'\033[0m"
	@echo ""

compile: $(lib)
	@$(CC) $(ANSI) -shared -fPIC $(lib) -o $(out)
	@echo "\033[38;2;55;200;55m"
	@echo "\033[1m\033[4m[Compilation successfully completed!]"
	@echo "\033[0m"

clean:
	@rm $(out)
	@echo "\033[38;2;55;200;55m"
	@echo "\033[1m\033[4m[File deleted!]"
	@echo "\033[0m"

install: $(lib)
	@sudo mkdir -p /usr/include/vn
	@sudo cp vn_ui.h /usr/include/vn
	@sudo chmod -x /usr/include/vn/vn_ui.h

	@echo "\033[38;2;55;200;55m"
	@echo "\033[1m\033[4m[...Installation completed...]"
	@echo "\033[0m"

uninstall:
	@sudo rm /usr/include/vn/vn_ui.h
	@if [ "$(ls -A "/usr/include/vn/" 2> /dev/null)" = "" ]; then sudo rm -rf /usr/include/vn/; fi

	@echo "\033[38;2;55;200;55m"
	@echo "\033[1m\033[4m[...Uninstallation completed...]"
	@echo "\033[0m"

# MADE BY @hanilr #