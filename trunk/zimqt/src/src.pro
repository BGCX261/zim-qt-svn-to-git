SOURCES += main.cpp \
 launcher.cpp
TEMPLATE = app
CONFIG += warn_on \
	  thread \
          qt
TARGET = ../bin/zimqt

QT -= gui
