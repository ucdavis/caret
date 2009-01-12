######################################################################
# Automatically generated by qmake (1.04a) Wed Jan 15 08:45:10 2003
######################################################################

TARGET       = CaretBrainSet
CONFIG  += staticlib 
INCLUDEPATH += .

include(../caret_qmake_include.pro)

TEMPLATE     = lib

# Input
HEADERS += BorderFileProjector.h \
	   BorderProjectionUnprojector.h \
	   BorderToTopographyConverter.h \
	   BorderUncertaintyToArealEstimationConverter.h \
      BrainModel.h \
	   BrainModelAlgorithm.h \
	   BrainModelAlgorithmException.h \
      BrainModelAlgorithmMultiThreadExecutor.h \
	   BrainModelAlgorithmMultiThreaded.h \
      BrainModelAlgorithmRunAsThread.h \
	   BrainModelBorderSet.h \
	   BrainModelContours.h \
	   BrainModelContourToSurfaceConverter.h \
      BrainModelIdentification.h \
      BrainModelOpenGL.h \
      BrainModelOpenGLSelectedItem.h \
      BrainModelRunExternalProgram.h \
      BrainModelStandardSurfaceReplacement.h \
      BrainModelSurface.h \
      BrainModelSurfaceAffineRegression.h \
	   BrainModelSurfaceAndVolume.h \
      BrainModelSurfaceBorderCutter.h \
      BrainModelSurfaceBorderLandmarkIdentification.h \
      BrainModelSurfaceCellAttributeAssignment.h \
      BrainModelSurfaceCellDensityToMetric.h \
      BrainModelSurfaceClusterToBorderConverter.h \
	   BrainModelSurfaceConnectedSearch.h \
	   BrainModelSurfaceConnectedSearchMetric.h \
      BrainModelSurfaceConnectedSearchPaint.h \
	   BrainModelSurfaceCurvature.h \
	   BrainModelSurfaceCutter.h \
	   BrainModelSurfaceDeformDataFile.h \
	   BrainModelSurfaceDeformation.h \
	   BrainModelSurfaceDeformationFlat.h \
      BrainModelSurfaceDeformationMapCreate.h \
      BrainModelSurfaceDeformationMeasurement.h \
	   BrainModelSurfaceDeformationSpherical.h \
      BrainModelSurfaceDeformationSphericalSlits.h \
	   BrainModelSurfaceDistortion.h \
      BrainModelSurfaceFindExtremum.h \
	   BrainModelSurfaceFlatHexagonalSubsample.h \
	   BrainModelSurfaceFlattenFullHemisphere.h \
      BrainModelSurfaceFlattenHemisphere.h \
	   BrainModelSurfaceFlattenPartialHemisphere.h \
      BrainModelSurfaceFociSearch.h \
      BrainModelSurfaceFociUncertaintyToRgbPaint.h \
	   BrainModelSurfaceGeodesic.h \
      BrainModelSurfaceMetricAnovaOneWay.h \
      BrainModelSurfaceMetricAnovaTwoWay.h \
	   BrainModelSurfaceMetricClustering.h \
      BrainModelSurfaceMetricCoordinateDifference.h \
      BrainModelSurfaceMetricFindClustersBase.h \
      BrainModelSurfaceMetricFullWidthHalfMaximum.h \
      BrainModelSurfaceMetricInGroupDifference.h \
      BrainModelSurfaceMetricInterHemClusters.h \
      BrainModelSurfaceMetricKruskalWallisRankTest.h \
      BrainModelSurfaceMetricOneAndPairedTTest.h \
      BrainModelSurfaceMetricTwinComparison.h \
      BrainModelSurfaceMetricTwoSampleTTest.h \
      BrainModelSurfaceMetricSmoothing.h \
	   BrainModelSurfaceMorphing.h \
	   BrainModelSurfaceMultiresolutionMorphing.h \
      BrainModelSurfaceNodeColoring.h \
      BrainModelSurfaceOverlay.h \
      BrainModelSurfacePaintAssignRelativeToLine.h \
      BrainModelSurfacePaintSulcalIdentification.h \
      BrainModelSurfacePaintToBorderConverter.h \
	   BrainModelSurfacePointLocator.h \
	   BrainModelSurfacePointProjector.h \
      BrainModelSurfaceROIAssignMetric.h \
      BrainModelSurfaceROIAssignPaint.h \
      BrainModelSurfaceROIAssignShape.h \
      BrainModelSurfaceROICreateBorderUsingGeodesic.h \
      BrainModelSurfaceROICreateBorderUsingMetricShape.h \
      BrainModelSurfaceROIFoldingMeasurementReport.h \
      BrainModelSurfaceROIIntegratedFoldingIndexReport.h \
      BrainModelSurfaceROIMetricClusterReport.h \
      BrainModelSurfaceROINodeSelection.h \
      BrainModelSurfaceROIOperation.h \
      BrainModelSurfaceROIPaintReport.h \
      BrainModelSurfaceROIProbAtlasOverlapReport.h \
      BrainModelSurfaceROIShapeCorrelationReport.h \
      BrainModelSurfaceROISurfaceXYZMeansReport.h \
      BrainModelSurfaceROITextReport.h \
	   BrainModelSurfaceResection.h \
	   BrainModelSurfaceSmoothing.h \
      BrainModelSurfaceSphericalTessellator.h \
	   BrainModelSurfaceSulcalDepth.h \
      BrainModelSurfaceSulcalDepthWithNormals.h \
      BrainModelSurfaceSulcalIdentificationProbabilistic.h \
	   BrainModelSurfaceToVolumeConverter.h \
      BrainModelSurfaceToVolumeSegmentationConverter.h \
      BrainModelSurfaceTopologyCorrector.h \
	   BrainModelVolume.h \
      BrainModelVolumeBiasCorrection.h \
      BrainModelVolumeCrossoverHandleFinder.h \
      BrainModelVolumeFociDensity.h \
      BrainModelVolumeFociUnprojector.h \
      BrainModelVolumeGradient.h \
	   BrainModelVolumeHandleFinder.h \
      BrainModelVolumeLigaseSegmentation.h \
      BrainModelVolumeNearToPlane.h \
      BrainModelVolumeProbAtlasToFunctional.h \
      BrainModelVolumeRegionOfInterest.h \
      BrainModelVolumeSegmentationStereotaxic.h \
      BrainModelVolumeSureFitErrorCorrection.h \
      BrainModelVolumeSureFitSegmentation.h \
      BrainModelVolumeTFCE.h \
      BrainModelVolumeThresholdSegmentation.h \
	   BrainModelVolumeToSurfaceConverter.h \
      BrainModelVolumeToSurfaceMapper.h \
      BrainModelVolumeToSurfaceMapperAlgorithmParameters.h \
      BrainModelVolumeToSurfaceMapperPALS.h \
      BrainModelVolumeToVtkSurfaceMapper.h \
      BrainModelVolumeTopologicalError.h \
      BrainModelVolumeTopologyGraph.h \
      BrainModelVolumeTopologyGraphCorrector.cxx \
	   BrainModelVolumeVoxelColoring.h \
      BrainSet.h  \
      BrainSetDataFileReader.h \
      BrainSetMultiThreadedSpecFileReader.h \
	   BrainSetNodeAttribute.h \
	   CellFileProjector.h \
      CellProjectionUnprojector.h \
      DisplaySettings.h \
      DisplaySettingsArealEstimation.h \
      DisplaySettingsBorders.h \
      DisplaySettingsCells.h \
	   DisplaySettingsCoCoMac.h \
	   DisplaySettingsContours.h \
	   DisplaySettingsCuts.h \
	   DisplaySettingsDeformationField.h \
      DisplaySettingsFoci.h \
      DisplaySettingsGeodesicDistance.h \
      DisplaySettingsImages.h \
      DisplaySettingsMetric.h \
	   DisplaySettingsModels.h \
      DisplaySettingsNodeAttributeFile.h \
	   DisplaySettingsSurface.h \
      DisplaySettingsPaint.h \
      DisplaySettingsProbabilisticAtlas.h \
      DisplaySettingsRgbPaint.h \
      DisplaySettingsScene.h \
      DisplaySettingsSection.h \
      DisplaySettingsStudyMetaData.h \
      DisplaySettingsSurfaceShape.h \
      DisplaySettingsSurfaceVectors.h \
      DisplaySettingsTopography.h \
	   DisplaySettingsVolume.h \
      DisplaySettingsWustlRegion.h \
      FociFileToPalsProjector.h \
      MapFmriAtlasSpecFileInfo.h \
	   MetricsToRgbPaintConverter.h \
      Tessellation.h 

SOURCES += BorderFileProjector.cxx \
	   BorderProjectionUnprojector.cxx \
	   BorderToTopographyConverter.cxx \
	   BorderUncertaintyToArealEstimationConverter.cxx \
	   BrainModel.cxx \
      BrainModelAlgorithm.cxx \
      BrainModelAlgorithmException.cxx \
      BrainModelAlgorithmMultiThreadExecutor.cxx \
	   BrainModelAlgorithmMultiThreaded.cxx \
      BrainModelAlgorithmRunAsThread.cxx \
	   BrainModelBorderSet.cxx \
	   BrainModelContours.cxx \
	   BrainModelContourToSurfaceConverter.cxx \
      BrainModelIdentification.cxx \
      BrainModelOpenGL.cxx \
      BrainModelOpenGLSelectedItem.cxx \
      BrainModelRunExternalProgram.cxx \
      BrainModelStandardSurfaceReplacement.cxx \
      BrainModelSurface.cxx \
      BrainModelSurfaceAffineRegression.cxx \
	   BrainModelSurfaceAndVolume.cxx \
      BrainModelSurfaceBorderCutter.cxx \
      BrainModelSurfaceBorderLandmarkIdentification.cxx \
      BrainModelSurfaceCellAttributeAssignment.cxx \
      BrainModelSurfaceCellDensityToMetric.cxx \
      BrainModelSurfaceClusterToBorderConverter.cxx \
	   BrainModelSurfaceConnectedSearch.cxx \
	   BrainModelSurfaceConnectedSearchMetric.cxx \
      BrainModelSurfaceConnectedSearchPaint.cxx \
	   BrainModelSurfaceCurvature.cxx \
	   BrainModelSurfaceCutter.cxx \
	   BrainModelSurfaceDeformDataFile.cxx \
	   BrainModelSurfaceDeformation.cxx \
	   BrainModelSurfaceDeformationFlat.cxx \
      BrainModelSurfaceDeformationMapCreate.cxx \
      BrainModelSurfaceDeformationMeasurement.cxx \
      BrainModelSurfaceDeformationSphericalSlits.cxx \
	   BrainModelSurfaceDeformationSpherical.cxx \
	   BrainModelSurfaceDistortion.cxx \
      BrainModelSurfaceFindExtremum.cxx \
	   BrainModelSurfaceFlatHexagonalSubsample.cxx \
	   BrainModelSurfaceFlattenFullHemisphere.cxx \
      BrainModelSurfaceFlattenHemisphere.cxx \
	   BrainModelSurfaceFlattenPartialHemisphere.cxx \
      BrainModelSurfaceFociSearch.cxx \
      BrainModelSurfaceFociUncertaintyToRgbPaint.cxx \
	   BrainModelSurfaceGeodesic.cxx \
      BrainModelSurfaceMetricAnovaOneWay.cxx \
      BrainModelSurfaceMetricAnovaTwoWay.cxx \
	   BrainModelSurfaceMetricClustering.cxx \
      BrainModelSurfaceMetricCoordinateDifference.cxx \
      BrainModelSurfaceMetricFindClustersBase.cxx \
      BrainModelSurfaceMetricFullWidthHalfMaximum.cxx \
      BrainModelSurfaceMetricInGroupDifference.cxx \
      BrainModelSurfaceMetricInterHemClusters.cxx \
      BrainModelSurfaceMetricKruskalWallisRankTest.cxx \
      BrainModelSurfaceMetricOneAndPairedTTest.cxx \
      BrainModelSurfaceMetricTwinComparison.cxx \
      BrainModelSurfaceMetricTwoSampleTTest.cxx \
      BrainModelSurfaceMetricSmoothing.cxx \
	   BrainModelSurfaceMorphing.cxx \
	   BrainModelSurfaceMultiresolutionMorphing.cxx \
      BrainModelSurfaceNodeColoring.cxx \
      BrainModelSurfaceOverlay.cxx \
      BrainModelSurfacePaintAssignRelativeToLine.cxx \
      BrainModelSurfacePaintSulcalIdentification.cxx \
      BrainModelSurfacePaintToBorderConverter.cxx \
	   BrainModelSurfacePointLocator.cxx \
	   BrainModelSurfacePointProjector.cxx \
      BrainModelSurfaceROIAssignMetric.cxx \
      BrainModelSurfaceROIAssignPaint.cxx \
      BrainModelSurfaceROIAssignShape.cxx \
      BrainModelSurfaceROICreateBorderUsingGeodesic.cxx \
      BrainModelSurfaceROICreateBorderUsingMetricShape.cxx \
      BrainModelSurfaceROIFoldingMeasurementReport.cxx \
      BrainModelSurfaceROIIntegratedFoldingIndexReport.cxx \
      BrainModelSurfaceROIMetricClusterReport.cxx \
      BrainModelSurfaceROINodeSelection.cxx \
      BrainModelSurfaceROIOperation.cxx \
      BrainModelSurfaceROIPaintReport.cxx \
      BrainModelSurfaceROIProbAtlasOverlapReport.cxx \
      BrainModelSurfaceROIShapeCorrelationReport.cxx \
      BrainModelSurfaceROISurfaceXYZMeansReport.cxx \
      BrainModelSurfaceROITextReport.cxx \
	   BrainModelSurfaceResection.cxx \
      BrainModelSurfaceSphericalTessellator.cxx \
	   BrainModelSurfaceSmoothing.cxx \
	   BrainModelSurfaceSulcalDepth.cxx \
      BrainModelSurfaceSulcalDepthWithNormals.cxx \
      BrainModelSurfaceSulcalIdentificationProbabilistic.cxx \
	   BrainModelSurfaceToVolumeConverter.cxx \
      BrainModelSurfaceToVolumeSegmentationConverter.cxx \
      BrainModelSurfaceTopologyCorrector.cxx \
	   BrainModelVolume.cxx \
      BrainModelVolumeBiasCorrection.cxx \
      BrainModelVolumeCrossoverHandleFinder.cxx \
      BrainModelVolumeFociDensity.cxx \
      BrainModelVolumeFociUnprojector.cxx \
      BrainModelVolumeGradient.cxx \
	   BrainModelVolumeHandleFinder.cxx \
      BrainModelVolumeLigaseSegmentation.cxx \
      BrainModelVolumeNearToPlane.cxx \
      BrainModelVolumeProbAtlasToFunctional.cxx \
      BrainModelVolumeRegionOfInterest.cxx \
      BrainModelVolumeSegmentationStereotaxic.cxx \
      BrainModelVolumeSureFitErrorCorrection.cxx \
      BrainModelVolumeSureFitSegmentation.cxx \
      BrainModelVolumeTFCE.cxx \
      BrainModelVolumeThresholdSegmentation.cxx \
	   BrainModelVolumeToSurfaceConverter.cxx \
      BrainModelVolumeToSurfaceMapper.cxx \
      BrainModelVolumeToSurfaceMapperAlgorithmParameters.cxx \
      BrainModelVolumeToSurfaceMapperPALS.cxx \
      BrainModelVolumeToVtkSurfaceMapper.cxx \
      BrainModelVolumeTopologicalError.cxx \
      BrainModelVolumeTopologyGraph.cxx \
      BrainModelVolumeTopologyGraphCorrector.cxx \
	   BrainModelVolumeVoxelColoring.cxx \
      BrainSet.cxx \
      BrainSetDataFileReader.cxx \
      BrainSetMultiThreadedSpecFileReader.cxx \
	   BrainSetNodeAttribute.cxx \
	   CellFileProjector.cxx \
      CellProjectionUnprojector.cxx \
      DisplaySettings.cxx \
      DisplaySettingsArealEstimation.cxx \
      DisplaySettingsBorders.cxx \
      DisplaySettingsCells.cxx \
	   DisplaySettingsCoCoMac.cxx \
	   DisplaySettingsContours.cxx \
	   DisplaySettingsCuts.cxx \
	   DisplaySettingsDeformationField.cxx \
      DisplaySettingsFoci.cxx \
      DisplaySettingsGeodesicDistance.cxx \
      DisplaySettingsImages.cxx \
      DisplaySettingsMetric.cxx \
	   DisplaySettingsModels.cxx \
      DisplaySettingsNodeAttributeFile.cxx \
      DisplaySettingsPaint.cxx \
	   DisplaySettingsSurface.cxx \
      DisplaySettingsProbabilisticAtlas.cxx \
      DisplaySettingsRgbPaint.cxx \
      DisplaySettingsScene.cxx \
      DisplaySettingsSection.cxx \
      DisplaySettingsStudyMetaData.cxx \
      DisplaySettingsSurfaceShape.cxx \
      DisplaySettingsSurfaceVectors.cxx \
      DisplaySettingsTopography.cxx \
	   DisplaySettingsVolume.cxx \
      DisplaySettingsWustlRegion.cxx \
      FociFileToPalsProjector.cxx \
      MapFmriAtlasSpecFileInfo.cxx \
	   MetricsToRgbPaintConverter.cxx \
      Tessellation.cxx 
