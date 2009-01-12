######################################################################
# Automatically generated by qmake (1.04a) Tue Jan 14 11:58:13 2003
######################################################################

TEMPLATE = app

#
# For JPEG support with static linking
#
QTPLUGIN += qgif qjpeg qtiff
LIBS     += -L$(QTDIR)/plugins/imageformats

INCLUDEPATH += .

#INCLUDEPATH += /usr/local/qt-software/qt-4.1.3/src/qt3support/dialogs 
#               /usr/local/qt-software/qt-4.1.3/src/qt3support/widgets
#               /usr/local/qt-software/qt-4.1.3/src/qt3support/network 
               
include(../caret_qmake_include.pro)

CONFIG += assistant

win32 {
   CONFIG(debug) {
      LIBS += ..\caret_common\debug\libCaretCommon.a \
         ..\caret_command_operations\debug\libCaretCommandOperations.a \
         ..\caret_brain_set\debug\libCaretBrainSet.a \
         ..\caret_vtk4_classes\debug\libCaretVtk4Classes.a \
         ..\caret_files\debug\libCaretFiles.a \
	      ..\caret_uniformize\debug\libCaretUniformize.a \
         ..\caret_statistics\debug\libCaretStatistics.a \
         ..\caret_widgets\debug\libCaretWidgets.a \
         ..\caret_common\debug\libCaretCommon.a 
   }
   CONFIG(release) {
      LIBS += ..\caret_common\release\libCaretCommon.a \
         ..\caret_command_operations\release\libCaretCommandOperations.a \
         ..\caret_brain_set\release\libCaretBrainSet.a \
         ..\caret_vtk4_classes\release\libCaretVtk4Classes.a \
         ..\caret_files\release\libCaretFiles.a \
	      ..\caret_uniformize\release\libCaretUniformize.a \
         ..\caret_statistics\release\libCaretStatistics.a \
         ..\caret_widgets\release\libCaretWidgets.a \
         ..\caret_common\release\libCaretCommon.a 
   }
   
   contains ( DEFINES, HAVE_ITK ) {
      LIBS += $$ITK_LIBS
   }
   
   LIBS += $$VTK_LIBS
   
   LIBS += $$QWT_LIBS

   contains( DEFINES, HAVE_MINC ) {
      LIBS += $$NETCDF_LIBS
   }

   RC_FILE = caret5.rc
}

win32::debug {
   CONFIG += console
}

macx {
   #INCLUDEPATH += \
	#	  /System/Library/Frameworks//ApplicationServices.framework/Versions/A/Frameworks/SpeechSynthesis.framework/Versions/A/Headers

   QMAKE_LFLAGS_APP -= -prebind
   
   LIBS +=  \
      -L../caret_command_operations -lCaretCommandOperations \
	   -L../caret_brain_set -lCaretBrainSet \
      -L../caret_vtk4_classes -lCaretVtk4Classes \
	   -L../caret_files -lCaretFiles \
	   -L../caret_uniformize -lCaretUniformize \
	   -L../caret_statistics -lCaretStatistics \
	   -L../caret_common -lCaretCommon \
	   -L../caret_widgets -lCaretWidgets 
      

   contains ( DEFINES, HAVE_ITK ) {
      LIBS += $$ITK_LIBS
   }
   
   LIBS += $$VTK_LIBS
   
   LIBS += $$QWT_LIBS

   contains( DEFINES, HAVE_MINC ) {
      LIBS += $$NETCDF_LIBS
   }

   LIBS += \
	   -framework Carbon \
	   -framework Quicktime 
   
#   RC_FILE		= caret5.icns
#   QMAKE_INFO_PLIST 	= Info.plist
}

unix {
   PRE_TARGETDEPS +=  \
      ../caret_command_operations/libCaretCommandOperations.a \
	   ../caret_brain_set/libCaretBrainSet.a \
      ../caret_vtk4_classes/libCaretVtk4Classes.a \
	   ../caret_files/libCaretFiles.a \
	   ../caret_uniformize/libCaretUniformize.a \
	   ../caret_statistics/libCaretStatistics.a \
	   ../caret_common/libCaretCommon.a \
	   ../caret_widgets/libCaretWidgets.a      
}

unix:!macx {
   LIBS +=  \
      -L../caret_command_operations -lCaretCommandOperations \
	   -L../caret_brain_set -lCaretBrainSet \
      -L../caret_vtk4_classes -lCaretVtk4Classes \
	   -L../caret_files -lCaretFiles \
	   -L../caret_uniformize -lCaretUniformize \
	   -L../caret_statistics -lCaretStatistics \
	   -L../caret_common -lCaretCommon \
	   -L../caret_widgets -lCaretWidgets

   contains ( DEFINES, HAVE_ITK ) {
      LIBS += $$ITK_LIBS
   }
   
   LIBS += $$VTK_LIBS
   
   LIBS += $$QWT_LIBS

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

   # for SGI systems
   exists( /usr/lib/libgen.so ) {
      LIBS	 += -lgen -LD_LAYOUT:lgot_buffer=500
   }
}

# Input
HEADERS += global_variables.h \
	   CommunicatorClientAFNI.h \
	   CommunicatorClientFIV.h \
	   CommunicatorClientBase.h \
	   GuiAddCellsDialog.h \
	   GuiAlignSurfaceToStandardOrientationDialog.h \
	   GuiApplyDeformationMapDialog.h \
	   GuiAverageBorderDialog.h \
	   GuiAverageCoordinateDialog.h \
	   GuiAutomaticRotationDialog.h \
	   GuiBatchCommandDialog.h \
	   GuiBorderAttributesDialog.h \
      GuiBorderComparisonDialog.h \
      GuiBorderDrawUpdateDialog.h \
	   GuiBorderNamesListBoxSelectionDialog.h \
      GuiBorderOperationsDialog.h \
	   GuiBorderProjectionDialog.h \
      GuiBordersCreateInterpolatedDialog.h \
      GuiBrainModelOpenGL.h \
      GuiBrainModelOpenGLKeyEvent.h \
	   GuiBrainModelOpenGLMouseEvent.h \
	   GuiBrainModelOpenGLPopupMenu.h \
      GuiBrainModelSelectionComboBox.h \
      GuiBrainModelSurfaceSelectionComboBox.h \
      GuiBrainModelViewingWindow.h \
      GuiBrainSetAndModelSelectionControl.h \
      GuiCaptureWindowImageDialog.h \
      GuiCaretCommandDialog.h \
      GuiCaretCommandScriptBuilderDialog.h \
      GuiCaretCommandWidget.h \
      GuiCaretTipsDialog.h \
      GuiCategoryComboBox.h \
      GuiCellAndFociAttributeAssignmentDialog.h \
      GuiCellAndFociReportDialog.h \
	   GuiCellAttributesDialog.h \
      GuiCellsOrFociProjectionDialog.h \
	   GuiChooseNodeAttributeColumnDialog.h \
      GuiChooseSpecFileDialog.h \
	   GuiColorFileEditorDialog.h \
      GuiColorFileEditorWidget.h \
      GuiColorKeyDialog.h \
	   GuiColorSelectionDialog.h \
      GuiCommaSeparatedValueFileEditor.h \
	   GuiCommunicatorClientConnectDialog.h \
	   GuiContourAlignmentDialog.h \
	   GuiContourDrawDialog.h \
	   GuiContourReconstructionDialog.h \
	   GuiContourSectionControlDialog.h \
	   GuiContourSetScaleDialog.h \
	   GuiConvertDataFileDialog.h \
      GuiCopySpecFileDialog.h \
	   GuiCurrentColoringToRgbPaintDialog.h \
	   GuiDataFileCommentDialog.h \
      GuiDataFileImportOptionsDialog.h \
      GuiDataFileMathDialog.h \
      GuiDataFileOpenDialog.h \
      GuiDataFileSaveDialog.h \
	   GuiDeformationFieldDialog.h \
	   GuiDeleteBordersByNameDialog.h \
	   GuiDisplayControlDialog.h \
      GuiDisplayControlSurfaceOverlayWidget.h \
	   GuiDistortionDialog.h \
	   GuiDrawBorderDialog.h \
      GuiFilesModified.h \
      GuiFileDialogWithInstructions.h \
      GuiFileSelectionButton.h \
      GuiFileSelectionButtonAndLineEditWidget.h \
      GuiFileSelectionListWidget.h \
      GuiFociPalsProjectionDialog.h \
      GuiFociSearchWidget.h \
	   GuiFociUncertaintyLimitsDialog.h \
      GuiFlattenFullHemisphereDialog.h \
	   GuiFlattenHemisphereDialog.h \
	   GuiFlattenHemisphereInstructionsDialog.h \
	   GuiGenerateArealEstimationDialog.h \
	   GuiGenerateSulcalDepthDialog.h \
	   GuiGenerateSurfaceCurvatureDialog.h \
      GuiGraphWidget.h \
      GuiGraphWidgetDialog.h \
      GuiHelpAssistantWindow.h \
      GuiHelpViewerWindow.h \
      GuiHistogramDisplayDialog.h \
      GuiHtmlColorChooserDialog.h \
	   GuiHyperLinkTextBrowser.h \
      GuiIdentifyDialog.h \
      GuiImageEditorWindow.h \
      GuiImageFormatComboBox.h \
      GuiImageResizeDialog.h \
      GuiImageViewingWindow.h \
	   GuiInflateAndSmoothFingersDialog.h \
	   GuiInflateSurfaceDialog.h \
	   GuiInterpolateSurfacesDialog.h \
      GuiLoadedFileManagementDialog.h \
      GuiMacOSXApplication.h \
      GuiMainWindow.h \
      GuiMainWindowAttributesActions.h \
	   GuiMainWindowAttributesMenu.h \
      GuiMainWindowCommActions.h \
	   GuiMainWindowCommMenu.h \
      GuiMainWindowFileActions.h \
      GuiMainWindowFileMenu.h \
      GuiMainWindowHelpActions.h \
      GuiMainWindowHelpMenu.h \
      GuiMainWindowLayersActions.h \
	   GuiMainWindowLayersMenu.h \
      GuiMainWindowSurfaceActions.h \
      GuiMainWindowSurfaceMenu.h \
      GuiMainWindowTimingActions.h \
      GuiMainWindowTimingMenu.h \
      GuiMainWindowVolumeActions.h \
	   GuiMainWindowVolumeMenu.h \
      GuiMainWindowWindowActions.h \
      GuiMainWindowWindowMenu.h \
      GuiMapFmriAtlasDialog.h \  
      GuiMapFmriDialog.h \
      GuiMapFmriMappingSet.h \
      GuiMapFmriMetricInfo.h \
      GuiMapFmriSpecFileTopoCoordDialog.h \
      GuiMapFmriThresholdDialog.h \
      GuiMapFmriVolume.h \
      GuiMapStereotaxicFocusDialog.h \
	   GuiMetricModificationDialog.h \
	   GuiMetricsToRgbPaintDialog.h \
      GuiModelSelectionControl.h \
      GuiModelsEditorDialog.h \
	   GuiMorphingDialog.h \
	   GuiMorphingMeasurementsDialog.h \
      GuiMouseModePopupMenu.h \
	   GuiMultipleInputDialog.h \
	   GuiMultiresolutionMorphingDialog.h \
	   GuiNameSelectionDialog.h \
	   GuiNodeAttributeColumnSelectionComboBox.h \
	   GuiNodeAttributeFileClearResetDialog.h \
	   GuiLoadNodeAttributeFileColumnSelectionDialog.h \
	   GuiPaintColumnNamesListBoxSelectionDialog.h \
	   GuiPaintNameEditorDialog.h \
      GuiPaletteColorSelectionDialog.h \
      GuiPaletteEditorDialog.h \
      GuiParamsFileEditorDialog.h \
	   GuiPreferencesDialog.h \
      GuiPreviousSpecFileComboBox.h \
	   GuiRecordingDialog.h \
	   GuiResectionDialog.h \
	   GuiSectionControlDialog.h \
	   GuiSetTopologyDialog.h \
	   GuiSetViewDialog.h \
      GuiShapeOrVectorsFromCoordinateSubtractionDialog.h \
      GuiShellCommandWindow.h \
	   GuiSmoothingDialog.h \
      GuiSpecAndSceneFileCreationDialog.h \
      GuiSpecFileCreationDialog.h \
      GuiSpecFileDialog.h \
      GuiSpeciesComboBox.h \
      GuiStandardMeshDialog.h \
      GuiStereotaxicSpaceComboBox.h \
      GuiStructureComboBox.h \
      GuiStudyCollectionFileEditorDialog.h \
      GuiStudyInfoEditorWidget.h \
      GuiStudyMetaDataFileEditorDialog.h \
      GuiStudyMetaDataLinkCreationDialog.h \
      GuiSumsDialog.h \
	   GuiSurfaceDeformationDialog.h \
	   GuiSurfaceInformationDialog.h \
	   GuiSurfaceRegionOfInterestDialog.h \
	   GuiSurfaceRegionOfInterestDialogOLD.h \
	   GuiSurfaceSpmTransformDialog.h \
	   GuiSurfaceToVolumeDialog.h \
      GuiSurfaceTopologyReportDialog.h \
      GuiSurfaceTypeComboBox.h \
      GuiTextBrowser.h \
	   GuiToolBar.h \
      GuiToolBarActions.h \
	   GuiTopologyFileComboBox.h \
      GuiTopologyTypeComboBox.h \
	   GuiTransformationMatrixDialog.h \
      GuiTransformationMatrixSelectionControl.h \
	   GuiUserViewSaveDialog.h \
      GuiVocabularyFileEditorDialog.h \
	   GuiVolumeAttributesDialog.h \
      GuiVolumeBiasCorrectionDialog.h \
      GuiVolumeCreateDialog.h \
	   GuiVolumeFileOrientationComboBox.h \
	   GuiVolumeFileSelectionComboBox.h \
      GuiVolumeFileTypeComboBox.h \
	   GuiVolumeHandleFinderDialog.h \
      GuiVolumePaintEditorDialog.h \
	   GuiVolumeReconstructionDialog.h \
	   GuiVolumeRegionOfInterestDialog.h \
      GuiVolumeRescaleDialog.h \
	   GuiVolumeResizingDialog.h \
	   GuiVolumeSegmentationEditorDialog.h \
      GuiVolumeSelectionControl.h \
      GuiVolumeSelectionDialog.h \
      GuiVolumeSureFitSegmentationDialog.h \
      GuiVolumeThresholdSegmentationDialog.h \
      GuiVolumeTopologyReportDialog.h \
      GuiVolumeTypeComboBox.h \
      GuiVolumeVoxelDataTypeComboBox.h \
      GuiZipSpecFileDialog.h

SOURCES += CommunicatorClientAFNI.cxx \
	   CommunicatorClientFIV.cxx \
	   CommunicatorClientBase.cxx \
	   GuiAddCellsDialog.cxx \
	   GuiAlignSurfaceToStandardOrientationDialog.cxx \
	   GuiApplyDeformationMapDialog.cxx \
	   GuiAutomaticRotationDialog.cxx \
	   GuiAverageBorderDialog.cxx \
	   GuiAverageCoordinateDialog.cxx \
	   GuiBatchCommandDialog.cxx \
	   GuiBorderAttributesDialog.cxx \
      GuiBorderComparisonDialog.cxx \
      GuiBorderDrawUpdateDialog.cxx \
	   GuiBorderNamesListBoxSelectionDialog.cxx \
      GuiBorderOperationsDialog.cxx \
	   GuiBorderProjectionDialog.cxx \
      GuiBordersCreateInterpolatedDialog.cxx \
	   GuiBrainModelOpenGL.cxx \
      GuiBrainModelOpenGLKeyEvent.cxx \
	   GuiBrainModelOpenGLMouseEvent.cxx \
	   GuiBrainModelOpenGLPopupMenu.cxx \
      GuiBrainModelSelectionComboBox.cxx \
      GuiBrainModelSurfaceSelectionComboBox.cxx \
      GuiBrainModelViewingWindow.cxx \
      GuiBrainSetAndModelSelectionControl.cxx \
      GuiCaptureWindowImageDialog.cxx \
      GuiCaretCommandDialog.cxx \
      GuiCaretCommandScriptBuilderDialog.cxx \
      GuiCaretCommandWidget.cxx \
      GuiCaretTipsDialog.cxx \
      GuiCategoryComboBox.cxx \
      GuiCellAndFociAttributeAssignmentDialog.cxx \
      GuiCellAndFociReportDialog.cxx \
	   GuiCellAttributesDialog.cxx \
      GuiCellsOrFociProjectionDialog.cxx \
	   GuiChooseNodeAttributeColumnDialog.cxx \
      GuiChooseSpecFileDialog.cxx \
	   GuiColorFileEditorDialog.cxx \
      GuiColorFileEditorWidget.cxx \
      GuiColorKeyDialog.cxx \
	   GuiColorSelectionDialog.cxx \
      GuiCommaSeparatedValueFileEditor.cxx \
	   GuiCommunicatorClientConnectDialog.cxx \
	   GuiContourAlignmentDialog.cxx \
	   GuiContourDrawDialog.cxx \
	   GuiContourReconstructionDialog.cxx \
	   GuiContourSectionControlDialog.cxx \
	   GuiContourSetScaleDialog.cxx \
	   GuiConvertDataFileDialog.cxx \
      GuiCopySpecFileDialog.cxx \ 
	   GuiCurrentColoringToRgbPaintDialog.cxx \
	   GuiDataFileCommentDialog.cxx \
      GuiDataFileImportOptionsDialog.cxx \
      GuiDataFileMathDialog.cxx \
      GuiDataFileOpenDialog.cxx \
      GuiDataFileSaveDialog.cxx \
	   GuiDeformationFieldDialog.cxx \
	   GuiDeleteBordersByNameDialog.cxx \
	   GuiDisplayControlDialog.cxx \
      GuiDisplayControlSurfaceOverlayWidget.cxx \
	   GuiDistortionDialog.cxx \
	   GuiDrawBorderDialog.cxx \
      GuiFilesModified.cxx \
      GuiFileDialogWithInstructions.cxx \
      GuiFileSelectionButton.cxx \
      GuiFileSelectionButtonAndLineEditWidget.cxx \
      GuiFileSelectionListWidget.cxx \
      GuiFociPalsProjectionDialog.cxx \
      GuiFociSearchWidget.cxx \
	   GuiFociUncertaintyLimitsDialog.cxx \
      GuiFlattenFullHemisphereDialog.cxx \
	   GuiFlattenHemisphereDialog.cxx \
	   GuiFlattenHemisphereInstructionsDialog.cxx \
	   GuiGenerateArealEstimationDialog.cxx \
	   GuiGenerateSulcalDepthDialog.cxx \
	   GuiGenerateSurfaceCurvatureDialog.cxx \
      GuiGraphWidget.cxx \
      GuiGraphWidgetDialog.cxx \
      GuiHelpAssistantWindow.cxx \
      GuiHelpViewerWindow.cxx \
      GuiHistogramDisplayDialog.cxx \
      GuiHtmlColorChooserDialog.cxx \
	   GuiHyperLinkTextBrowser.cxx \
      GuiIdentifyDialog.cxx \
      GuiImageEditorWindow.cxx \
      GuiImageFormatComboBox.cxx \
      GuiImageResizeDialog.cxx \
      GuiImageViewingWindow.cxx \
	   GuiInflateAndSmoothFingersDialog.cxx \
	   GuiInflateSurfaceDialog.cxx \
	   GuiInterpolateSurfacesDialog.cxx \
      GuiLoadedFileManagementDialog.cxx \
      GuiMacOSXApplication.cxx \
      GuiMainWindow.cxx \
      GuiMainWindowAttributesActions.cxx \
	   GuiMainWindowAttributesMenu.cxx \
      GuiMainWindowCommActions.cxx \
	   GuiMainWindowCommMenu.cxx \
      GuiMainWindowFileActions.cxx \
      GuiMainWindowFileMenu.cxx \
      GuiMainWindowHelpActions.cxx \
      GuiMainWindowHelpMenu.cxx \
      GuiMainWindowLayersActions.cxx \
	   GuiMainWindowLayersMenu.cxx \
      GuiMainWindowTimingActions.cxx \
      GuiMainWindowTimingMenu.cxx \
      GuiMainWindowSurfaceActions.cxx \
      GuiMainWindowSurfaceMenu.cxx \
      GuiMainWindowVolumeActions.cxx \
	   GuiMainWindowVolumeMenu.cxx \
      GuiMainWindowWindowActions.cxx \
      GuiMainWindowWindowMenu.cxx \
      GuiMapFmriAtlasDialog.cxx \
      GuiMapFmriDialog.cxx \
      GuiMapFmriMappingSet.cxx \
      GuiMapFmriMetricInfo.cxx \
      GuiMapFmriSpecFileTopoCoordDialog.cxx \
      GuiMapFmriThresholdDialog.cxx \
      GuiMapFmriVolume.cxx	\
      GuiMapStereotaxicFocusDialog.cxx \
	   GuiMetricModificationDialog.cxx \
	   GuiMetricsToRgbPaintDialog.cxx \
      GuiModelSelectionControl.cxx \
      GuiModelsEditorDialog.cxx \
	   GuiMorphingDialog.cxx \
	   GuiMorphingMeasurementsDialog.cxx \
      GuiMouseModePopupMenu.cxx \
	   GuiMultipleInputDialog.cxx \
	   GuiMultiresolutionMorphingDialog.cxx \
	   GuiNameSelectionDialog.cxx \
	   GuiNodeAttributeColumnSelectionComboBox.cxx \
	   GuiNodeAttributeFileClearResetDialog.cxx \
	   GuiLoadNodeAttributeFileColumnSelectionDialog.cxx \
	   GuiPaintColumnNamesListBoxSelectionDialog.cxx \
	   GuiPaintNameEditorDialog.cxx \
      GuiPaletteColorSelectionDialog.cxx \
      GuiPaletteEditorDialog.cxx \
      GuiParamsFileEditorDialog.cxx \
	   GuiPreferencesDialog.cxx \
      GuiPreviousSpecFileComboBox.cxx \
	   GuiRecordingDialog.cxx \
	   GuiResectionDialog.cxx \
	   GuiSetTopologyDialog.cxx \
	   GuiSetViewDialog.cxx \
      GuiShapeOrVectorsFromCoordinateSubtractionDialog.cxx \
	   GuiSectionControlDialog.cxx \
      GuiShellCommandWindow.cxx \
	   GuiSmoothingDialog.cxx \
      GuiSpecAndSceneFileCreationDialog.cxx \
      GuiSpecFileCreationDialog.cxx \
      GuiSpecFileDialog.cxx \
      GuiSpeciesComboBox.cxx \
      GuiStandardMeshDialog.cxx \
      GuiStereotaxicSpaceComboBox.cxx \
      GuiStructureComboBox.cxx \
      GuiStudyCollectionFileEditorDialog.cxx \
      GuiStudyInfoEditorWidget.cxx \
      GuiStudyMetaDataFileEditorDialog.cxx \
      GuiStudyMetaDataLinkCreationDialog.cxx \
      GuiSumsDialog.cxx \
	   GuiSurfaceDeformationDialog.cxx \
	   GuiSurfaceInformationDialog.cxx \
	   GuiSurfaceRegionOfInterestDialog.cxx \
	   GuiSurfaceRegionOfInterestDialogOLD.cxx \
	   GuiSurfaceSpmTransformDialog.cxx \
	   GuiSurfaceToVolumeDialog.cxx \
      GuiSurfaceTopologyReportDialog.cxx \
      GuiSurfaceTypeComboBox.cxx \
      GuiTextBrowser.cxx \
      GuiTopologyTypeComboBox.cxx \
	   GuiToolBar.cxx \
      GuiToolBarActions.cxx \
	   GuiTopologyFileComboBox.cxx \
	   GuiTransformationMatrixDialog.cxx \
      GuiTransformationMatrixSelectionControl.cxx \
	   GuiUserViewSaveDialog.cxx \
      GuiVocabularyFileEditorDialog.cxx \
	   GuiVolumeAttributesDialog.cxx \
      GuiVolumeBiasCorrectionDialog.cxx \
      GuiVolumeCreateDialog.cxx \
	   GuiVolumeFileOrientationComboBox.cxx \
	   GuiVolumeFileSelectionComboBox.cxx \
      GuiVolumeFileTypeComboBox.cxx \
	   GuiVolumeHandleFinderDialog.cxx \
      GuiVolumePaintEditorDialog.cxx \
	   GuiVolumeReconstructionDialog.cxx \
	   GuiVolumeRegionOfInterestDialog.cxx \
      GuiVolumeRescaleDialog.cxx \
	   GuiVolumeResizingDialog.cxx \
	   GuiVolumeSegmentationEditorDialog.cxx \
      GuiVolumeSelectionControl.cxx \
      GuiVolumeSelectionDialog.cxx \
      GuiVolumeSureFitSegmentationDialog.cxx \
      GuiVolumeThresholdSegmentationDialog.cxx \
      GuiVolumeTopologyReportDialog.cxx \
      GuiVolumeTypeComboBox.cxx \
      GuiVolumeVoxelDataTypeComboBox.cxx \
      GuiZipSpecFileDialog.cxx \
      main.cxx
