# ---------------------------------------------------- #
# SINGLE-HEADER TERMINAL USER INTERFACE | VARIATION-UI #
#          SHARED-LIBRARY CONVERTING MAKEFILE          #
# ---------------------------------------------------- #

CC = gcc
lib = vn.h
win_out = vn.dll
uni_out = vn.so

ifeq ($(OS),Windows_NT)
	delete = del
else
	delete = rm
endif

.PHONY: win_run uni_run win_clean uni_clean

win_run: $(lib)
	$(CC) -shared -fPIC $(lib) -o $(win_out)

win_clean: $(win_out)
	$(delete) $(win_out)

uni_run: $(lib)
	$(CC) -shared -fPIC $(lib) -o $(uni_out)

uni_clean:
	$(delete) $(uni_out)

# MADE BY @hanilr #