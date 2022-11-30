# ---------------------------------------------------- #
# SINGLE-HEADER TERMINAL USER INTERFACE | VARIATION-UI #
#          SHARED-LIBRARY CONVERTING MAKEFILE          #
# ---------------------------------------------------- #

CC = gcc
ANSI = -std=c89

lib = vn_ui.h
out = vn_ui.so

.PHONY: run clean install uninstall

run: $(lib)
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