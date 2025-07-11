# ---------------------------------------------------- #
# SINGLE-HEADER TERMINAL USER INTERFACE | VARIATION-UI #
#          SHARED-LIBRARY CONVERTING MAKEFILE          #
# ---------------------------------------------------- #

CC = gcc
ANSI = -std=c89
lib = vn_ui.h

ifdef OS
   	out = vn_ui.dll
   	rm = cmd /c del /F /Q
   	rmdir = cmd /c rmdir /S /Q
   	mk = cmd /c mkdir
   	cp = cmd /c copy
else
   	UNAME_S := $(shell uname -s)
   	ifeq ($(shell uname), Linux)
      out = vn_ui.so
	  rm = rm -f
	  rmdir = rm -rf
	  mk = mkdir -p
	  cp = cp
   	endif
endif

.PHONY: run compile clean install uninstall

run:
	@echo ""
	@echo " [ Make List ]"
	@echo " 1. Show make list 'make' or 'make run'"
	@echo " 2. Compile as shared-library 'make compile'"
	@echo " 3. Clean shared-library 'make clean'"
	@echo " 4. Install the library 'make install'"
	@echo " 5. Uninstall the library 'make uninstall'"
	@echo ""

compile: $(lib)
	@$(CC) $(ANSI) -shared -fPIC $(lib) -o $(out)
	
	@echo ""
	@echo "[ ---------------------------------------------- ] "
	@echo "[ Shared-Library successfully compiled for unix! ] "
	@echo "[ ---------------------------------------------- ] "
	@echo ""

clean:
	@$(rm) $(out)
	
	@echo ""
	@echo "[ ------------------------------------ ] "
	@echo "[ Shared-Library successfully cleaned! ] "
	@echo "[ ------------------------------------ ] "
	@echo ""

install: $(lib)
	@$(mk) vn
	@$(cp) vn_ui.h vn
	@$(cp) vn_ui/vn_ui_base.h vn
	@$(cp) vn_ui/vn_ui_widget.h vn

	@echo ""
	@echo "[ ------------------------------------ ] "
	@echo "[ Variation UI successfully installed! ] "
	@echo "[ ------------------------------------ ] "
	@echo ""

uninstall:
	@$(rmdir) vn

	@echo ""
	@echo "[ -------------------------------------- ] "
	@echo "[ Variation UI successfully uninstalled! ] "
	@echo "[ -------------------------------------- ] "
	@echo ""

# MADE BY @hanilr #