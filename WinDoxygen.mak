DOXYGEN=C:/cppdev/doxygen-1.8.13/doxygen.exe
CFG=Doxyfile
OUT=doxygen/html/
INDEX=index.html
PROJECT_DIR = $(shell pwd)

all:
	$(DOXYGEN) -s $(CFG)

open:
	start $(OUT)$(INDEX) &