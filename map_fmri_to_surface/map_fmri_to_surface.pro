######################################################################
# Automatically generated by qmake (1.04a) Tue Jan 14 11:58:13 2003
######################################################################

TEMPLATE = app
CONFIG   += qt thread
INCLUDEPATH += .

include(../caret_qmake_include.pro)

win32 {
   contains( DEFINES, HAVE_BORLAND_COMPILER ) {
      LIBS += ..\caret_brain_set\CaretBrainSet.lib \
         ..\caret_common\CaretCommon.lib \
         ..\caret_files\CaretFiles.lib \
	      ..\caret_widgets\CaretWidgets.lib 
   }

   contains( DEFINES, HAVE_GCC_COMPILER ) {
      LIBS += \
         ..\caret_brain_set\libCaretBrainSet.a \
         ..\caret_files\libCaretFiles.a \
         ..\caret_common\libCaretCommon.a \
	      ..\caret_widgets\libCaretWidgets.a
   }

   contains ( DEFINES, HAVE_ITK ) {
      LIBS += $$ITK_LIBS
   }

   LIBS += $$VTK_LIBS

   contains( DEFINES, HAVE_MINC ) {
      LIBS += $$NETCDF_LIBS
   }
}

win32::debug {
   CONFIG += console
}

macx {
   LIBS += -L../caret_brain_set -lCaretBrainSet \
	   -L../caret_files -lCaretFiles \
	   -L../caret_common -lCaretCommon \
	   -L../caret_widgets -lCaretWidgets 

   contains ( DEFINES, HAVE_ITK ) {
      LIBS += $$ITK_LIBS
   }

   LIBS += $$VTK_LIBS

   contains( DEFINES, HAVE_MINC ) {
      LIBS += $$NETCDF_LIBS
   }
   
   LIBS += -lqt-mt \
	   -lz \
	   -framework Carbon \
	   -framework Quicktime
}

unix:!macx {
   LIBS += -L../caret_brain_set -lCaretBrainSet \
	   -L../caret_files   -lCaretFiles \
	   -L../caret_common -lCaretCommon \
	   -L../caret_widgets -lCaretWidgets 

   contains ( DEFINES, HAVE_ITK ) {
      LIBS += $$ITK_LIBS
   }

   LIBS += $$VTK_LIBS

   contains( DEFINES, HAVE_MINC ) {
      LIBS += $$NETCDF_LIBS
   }

   # FreeBSD 5.3 uses vtk 4.3, which does not have separate libraries
   # for jpeg, png, and expat.
   # FreeBSD also does not have libdl, but integrates its functions
   # into libc.
   !exists( /etc/rc.conf ) {
      LIBS += -lvtkjpeg \
              -lvtkpng \
              -lvtkexpat \
              -ldl 
   }       
           
   LIBS +=-lGLw \
	   -lGL

   # for SGI systems
   exists( /usr/lib/libgen.so ) {
      LIBS       += -lgen -LD_LAYOUT:lgot_buffer=500
   }
}

# Input
HEADERS += AtlasDirectoryInfo.h \
	   FMRIDataMapper.h \
	   FMRISurfaceInfo.h \
	   FMRIVolumeInfo.h \
	   GuiMapFmriAlgorithmDialog.h \
	   GuiMapFmriAtlasSelectionDialog.h \
	   GuiMapFmriIndivParametersDialog.h \
	   GuiMapFmriMainWindow.h \
	   GuiMapFmriMainWindowAtlasMenu.h \
	   GuiMapFmriMainWindowFileMenu.h \
	   GuiMapFmriMainWindowHelpMenu.h \
	   GuiMapFmriMetricNamingDialog.h 

SOURCES += AtlasDirectoryInfo.cxx \
	   FMRIDataMapper.cxx \
	   FMRISurfaceInfo.cxx \
	   FMRIVolumeInfo.cxx \
	   GuiMapFmriAlgorithmDialog.cxx \
	   GuiMapFmriAtlasSelectionDialog.cxx \
	   GuiMapFmriIndivParametersDialog.cxx \
	   GuiMapFmriMainWindow.cxx \
	   GuiMapFmriMainWindowAtlasMenu.cxx \
	   GuiMapFmriMainWindowFileMenu.cxx \
	   GuiMapFmriMainWindowHelpMenu.cxx \
	   GuiMapFmriMetricNamingDialog.cxx \
           main.cxx 
