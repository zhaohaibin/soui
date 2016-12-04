######################################################################
# Automatically generated by qmake (2.01a) ?? ?? 23 19:28:51 2014
######################################################################

TEMPLATE = lib
TARGET =  resprovider-7zip

!LIB_ALL:!COM_LIB{
	RC_FILE += ResProvider-7Zip.rc
	CONFIG += dll
}
else{
	CONFIG += staticlib
}

DEPENDPATH += .
INCLUDEPATH += . \
			   ../../third-part/7z \
			   ../../soui/include \
			   ../../utilities/include \

DEFINES += RESPROVIDER7ZIP_EXPORTS
QMAKE_LFLAGS += /SAFESEH:NO

dir = ../..
include($$dir/common.pri)

CONFIG(debug,debug|release){
	LIBS += 7zd.lib utilitiesd.lib
}
else{
	LIBS += 7z.lib utilities.lib
}


PRECOMPILED_HEADER = stdafx.h

# Input
HEADERS += SResProvider7Zip.h Zip7Archive.h
SOURCES += cursoricon.cpp \
           SResProvider7Zip.cpp \
           zip7Archive.cpp
