######################################################################
# Automatically generated by qmake (1.04a) Tue Jan 14 11:58:13 2003
######################################################################

TARGET = CaretUniformize
CONFIG += staticlib

INCLUDEPATH += .
ubuntu {
	CONFIG -= staticlib
	CONFIG += plugin
}

include(../caret_qmake_include.pro)  

TEMPLATE = lib

# Input
HEADERS += \
   caret_uniformize.h \ 
   matrix.h

SOURCES += \
   matrix.cxx \
   caret_uniformize.cxx 
