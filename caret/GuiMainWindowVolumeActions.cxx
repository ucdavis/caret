/*LICENSE_START*/
/*
 *  Copyright 1995-2002 Washington University School of Medicine
 *
 *  http://brainmap.wustl.edu
 *
 *  This file is part of CARET.
 *
 *  CARET is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  CARET is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with CARET; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */
/*LICENSE_END*/

#include <iostream>
#include <sstream>

#include <QAction>
#include <QApplication>
#include <QMessageBox>

#include "AtlasSpaceFile.h"
#include "BrainSet.h"
#include "BrainModelVolume.h"
#include "BrainModelVolumeProbAtlasToFunctional.h"
#include "BrainModelVolumeSureFitErrorCorrection.h"
#include "BrainModelVolumeSureFitSegmentation.h"
#include "BrainModelVolumeVoxelColoring.h"
#include "DisplaySettingsVolume.h"
#include "FileUtilities.h"
#include "GuiBrainModelOpenGL.h"
#include "GuiFilesModified.h"
#include "GuiMainWindow.h"
#include "GuiMainWindowVolumeActions.h"
#include "GuiMessageBox.h"
#include "QtMultipleInputDialog.h"
#include "GuiVolumeCreateDialog.h"
#include "GuiVolumeHandleFinderDialog.h"
#include "GuiVolumeReconstructionDialog.h"
#include "GuiVolumeSegmentationEditorDialog.h"
#include "GuiVolumeSelectionDialog.h"
#include "GuiVolumeSureFitSegmentationDialog.h"
#include "GuiVolumeTopologyReportDialog.h"
#include "QtCheckBoxSelectionDialog.h"
#include "QtTextEditDialog.h"

#include "VolumeFile.h"
#include "global_variables.h"
#include "vtkTransform.h"

/**
 * Constructor.
 */
GuiMainWindowVolumeActions::GuiMainWindowVolumeActions(GuiMainWindow* mainWindowParent)
   : QObject(mainWindowParent)
{
   setObjectName("GuiMainWindowVolumeActions");
   
   createEmptyVolumeAction = new QAction(mainWindowParent);
   createEmptyVolumeAction->setText("Create New Volume...");
   createEmptyVolumeAction->setObjectName("createEmptyVolumeAction");
   QObject::connect(createEmptyVolumeAction, SIGNAL(activated()),
                    this, SLOT(slotCreateNewEmptyVolume()));

   resizeUnderlayVolumeAction = new QAction(mainWindowParent);
   resizeUnderlayVolumeAction->setText("Resize Underlay Volume...");
   resizeUnderlayVolumeAction->setObjectName("resizeUnderlayVolumeAction");
   QObject::connect(resizeUnderlayVolumeAction, SIGNAL(activated()),
                    this, SLOT(slotResizeUnderlayVolume()));

   showVoxelExtentAction = new QAction(mainWindowParent);
   showVoxelExtentAction->setText("Show Voxel Dimensional Extent...");
   showVoxelExtentAction->setObjectName("showVoxelExtentAction");
   QObject::connect(showVoxelExtentAction, SIGNAL(activated()),
                    this, SLOT(slotShowVoxelDimensionExtent()));

   editVolumeAttributesAction = new QAction(mainWindowParent);
   editVolumeAttributesAction->setText("Edit Volume Attributes...");
   editVolumeAttributesAction->setObjectName("editVolumeAttributesAction");
   QObject::connect(editVolumeAttributesAction, SIGNAL(activated()),
                    this, SLOT(slotEditAttributes()));

   findHandlesAction = new QAction(mainWindowParent);
   findHandlesAction->setText("Find Handles...");
   findHandlesAction->setObjectName("findHandlesAction");
   QObject::connect(findHandlesAction, SIGNAL(activated()),
                    this, SLOT(slotSegmentationFindHandles()));

   reconstructAction = new QAction(mainWindowParent);
   reconstructAction->setText("Reconstruct Into Surface...");
   reconstructAction->setObjectName("reconstructAction");
   QObject::connect(reconstructAction, SIGNAL(activated()),
                    this, SLOT(slotSegmentationReconstruct()));

   editSegmentationAction = new QAction(mainWindowParent);
   editSegmentationAction->setText("Edit Voxels...");
   editSegmentationAction->setObjectName("editSegmentationAction");
   QObject::connect(editSegmentationAction, SIGNAL(activated()),
                    this, SLOT(slotSegmentationEditVoxels()));

   surefitSegmentationAction = new QAction(mainWindowParent);
   surefitSegmentationAction->setText("SureFit Operations (Segmentation)...");
   surefitSegmentationAction->setObjectName("surefitSegmentationAction");
   QObject::connect(surefitSegmentationAction, SIGNAL(activated()),
                    this, SLOT(slotSureFitSegmentation()));

   surefitMultiHemSegmentationAction = new QAction(mainWindowParent);
   surefitMultiHemSegmentationAction->setText("SureFit Operations (Multi-Hem Segmentation IN DEVELOPMENT)");
   surefitMultiHemSegmentationAction->setObjectName("surefitMultiHemSegmentationAction");
   QObject::connect(surefitMultiHemSegmentationAction, SIGNAL(activated()),
                    this, SLOT(slotSureFitMultiHemSegmentation()));

   padSegmentationAction = new QAction(mainWindowParent);
   padSegmentationAction->setText("Pad Volume...");
   padSegmentationAction->setObjectName("padSegmentationAction");
   QObject::connect(padSegmentationAction, SIGNAL(activated()),
                    this, SLOT(slotSegmentPad()));

   removeIslandsAction = new QAction(mainWindowParent);
   removeIslandsAction->setText("Remove Islands");
   removeIslandsAction->setObjectName("removeIslandsAction");
   QObject::connect(removeIslandsAction, SIGNAL(activated()),
                    this, SLOT(slotSegmentRemoveIslands()));

   topologyReportAction = new QAction(mainWindowParent);
   topologyReportAction->setText("Topoogy Error Report...");
   topologyReportAction->setObjectName("topologyReportAction");
   QObject::connect(topologyReportAction, SIGNAL(activated()),
                    this, SLOT(slotSegmentationTopologyReport()));

   cerebralHullAction = new QAction(mainWindowParent);
   cerebralHullAction->setText("Generate Cerebral Hull Volume");
   cerebralHullAction->setObjectName("cerebralHullAction");
   QObject::connect(cerebralHullAction, SIGNAL(activated()),
                    this, SLOT(slotSegmentationCerebralHull()));

   fillCavitiesAction = new QAction(mainWindowParent);
   fillCavitiesAction->setText("Fill Cavities");
   fillCavitiesAction->setObjectName("fillCavitiesAction");
   QObject::connect(fillCavitiesAction, SIGNAL(activated()),
                    this, SLOT(slotSegmentationFillCavities()));

   applyRotationAction = new QAction(mainWindowParent);
   applyRotationAction->setText("Apply Rotation...");
   applyRotationAction->setObjectName("applyRotationAction");
   QObject::connect(applyRotationAction, SIGNAL(activated()),
                    this, SLOT(slotTransformApplyRotation()));

   enableRotationAction = new QAction(mainWindowParent);
   enableRotationAction->setText("Enable Rotation");
   enableRotationAction->setObjectName("enableRotationAction");
   enableRotationAction->setCheckable(true);
   QObject::connect(enableRotationAction, SIGNAL(activated()),
                    this, SLOT(slotTransformEnableRotation()));

   regionOfInterestAction = new QAction(mainWindowParent);
   regionOfInterestAction->setText("Region of Interest Operations...");
   regionOfInterestAction->setObjectName("regionOfInterestAction");
   QObject::connect(regionOfInterestAction, SIGNAL(activated()),
                    this, SLOT(slotRegionOfInterestDialog()));

   probAtlasToVolumeAction = new QAction(mainWindowParent);
   probAtlasToVolumeAction->setText("Convert Probabilistic Atlas to Functional Volume...");
   probAtlasToVolumeAction->setObjectName("probAtlasToVolumeAction");
   QObject::connect(probAtlasToVolumeAction, SIGNAL(activated()),
                    this, SLOT(slotProbAtlasConvertToFunctional()));

   anatomyBiasCorrectionAction = new QAction(mainWindowParent);
   anatomyBiasCorrectionAction->setText("Bias Correction...");
   anatomyBiasCorrectionAction->setObjectName("anatomyBiasCorrectionAction");
   QObject::connect(anatomyBiasCorrectionAction, SIGNAL(activated()),
                    mainWindowParent, SLOT(displayVolumeBiasCorrectionDialog()));
                    
   anatomyThresholdAction = new QAction(mainWindowParent);
   anatomyThresholdAction->setText("Threshold Into Segmentation...");
   anatomyThresholdAction->setObjectName("anatomyThresholdAction");
   QObject::connect(anatomyThresholdAction, SIGNAL(activated()),
                    this, SLOT(slotAnatomyThreshold()));

   editPaintVolumeAction = new QAction(mainWindowParent);
   editPaintVolumeAction->setText("Edit Voxels...");
   editPaintVolumeAction->setObjectName("editPaintVolumeAction");
   QObject::connect(editPaintVolumeAction, SIGNAL(activated()),
                    this, SLOT(slotPaintEditVoxels()));

   mathOperationsVolumeAction = new QAction(mainWindowParent);
   mathOperationsVolumeAction->setText("Mathematical Operations...");
   mathOperationsVolumeAction->setObjectName("mathOperationsVolumeAction");
   QObject::connect(mathOperationsVolumeAction, SIGNAL(activated()),
                    mainWindowParent, SLOT(displayVolumeMathDialog()));
}

/**
 * Destructor.
 */
GuiMainWindowVolumeActions::~GuiMainWindowVolumeActions()
{
}

/**
 * called to create a new empty volume.
 */
void 
GuiMainWindowVolumeActions::slotCreateNewEmptyVolume()
{
   GuiVolumeCreateDialog cd(theMainWindow);
   cd.exec();
}
      
/**
 * called to display volume region of interest dialog.
 */
void 
GuiMainWindowVolumeActions::slotRegionOfInterestDialog()
{
   theMainWindow->getVolumeRegionOfInterestDialog(true);
/*
   if (GuiMessageBox::question(theMainWindow,
                               "Choose",
                               "New or Old ROI Dialog?",
                               "New", "Old") == 0) {
      theMainWindow->getVolumeRegionOfInterestDialog(true);
   }
   else {
      theMainWindow->getVolumeRegionOfInterestDialogOld(true);
   }
*/
}
      
/**
 * called to crop the underlay volume.
 */
void 
GuiMainWindowVolumeActions::slotResizeUnderlayVolume()
{
   theMainWindow->getVolumeResizingDialog(true);
}

/**
 * Called to view/edit volume attributes.
 */
void
GuiMainWindowVolumeActions::slotEditAttributes()
{
   theMainWindow->getVolumeAttributesDialog(true);
}

/**
 * Called to show voxel dimensional extent
 */
void
GuiMainWindowVolumeActions::slotShowVoxelDimensionExtent()
{
   BrainModelVolume* bmv = theMainWindow->getBrainModelVolume();
   if (bmv != NULL) {
      QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
      int extent[6];
      VolumeFile* vf = bmv->getMasterVolumeFile();
      if (vf != NULL) {
         vf->getNonZeroVoxelExtent(extent);
         std::ostringstream str;
         str << "Non-zero voxel dimensional extent: " << std::endl
             << "   Parasagittal: (" << extent[0] << ", " << extent[1] << ")" << std::endl
             << "   Coronal:      (" << extent[2] << ", " << extent[3] << ")" << std::endl
             << "   Horizontal:   (" << extent[4] << ", " << extent[5] << ")" << std::endl;
      
         QMessageBox* mb = new QMessageBox("Voxel Dimensional Extent",
                                        str.str().c_str(),
                                        QMessageBox::NoIcon,
                                        QMessageBox::Ok,
                                        Qt::NoButton,
                                        Qt::NoButton,
                                        theMainWindow,
                                        Qt::MSWindowsFixedSizeDialogHint);
         mb->setModal(false);
         mb->show();
         mb->setAttribute(Qt::WA_DeleteOnClose);
         QApplication::restoreOverrideCursor();
      }
   }
}

/**
 * Called to display apply rotation dialog. 
 */
void
GuiMainWindowVolumeActions::slotTransformEnableRotation()
{
   //
   // Toggle 
   //
   //enableRotationAction->setChecked(!enableRotationAction->isChecked());

   //
   // If enabling rotation and volume in main window, change mouse mode to VIEW
   //
   if (enableRotationAction->isChecked()) {
      if (theMainWindow->getBrainModelOpenGL()->getDisplayedBrainModelVolume() != NULL) {
         theMainWindow->getBrainModelOpenGL()->setMouseMode(GuiBrainModelOpenGL::MOUSE_MODE_VIEW);
      }
   }
   
   //
   // Update main window status bar
   //
   theMainWindow->updateStatusBarLabel();
}

/**
 * Called to display apply rotation dialog. 
 */
void
GuiMainWindowVolumeActions::slotTransformApplyRotation()
{
   BrainModelVolume* bmv = theMainWindow->getBrainModelVolume();
   if (bmv != NULL) {
      std::vector<QString> itemLabels;
      
      int itemIndex = 0;
      
      //
      // Primary overlay
      //
      int primaryOverlayIndex = -1;
      VolumeFile* primaryOverlay = bmv->getOverlayPrimaryVolumeFile();
      if (primaryOverlay != NULL) {
         QString name("Primary Overlay: ");
         name.append(FileUtilities::basename(primaryOverlay->getFileName()));
         itemLabels.push_back(name);
         primaryOverlayIndex = itemIndex;
         itemIndex++;
      }
      
      //
      // Secondary overlay
      //
      int secondaryOverlayIndex = -1;
      VolumeFile* secondaryOverlay = bmv->getOverlaySecondaryVolumeFile();
      if (secondaryOverlay != NULL) {
         QString name("Secondary Overlay: ");
         name.append(FileUtilities::basename(secondaryOverlay->getFileName()));
         itemLabels.push_back(name);
         secondaryOverlayIndex = itemIndex;
         itemIndex++;
      }
      
      //
      // Underlay
      //
      int underlayIndex = -1;
      VolumeFile* underlay = bmv->getUnderlayVolumeFile();
      if (underlay != NULL) {
         QString name("Underlay: ");
         name.append(FileUtilities::basename(underlay->getFileName()));
         itemLabels.push_back(name);
         underlayIndex = itemIndex;
         itemIndex++;
      }
      
      //
      // Default apply to all 
      //
      std::vector<bool> itemSelections(itemLabels.size(), "true");
      
      //
      // Create the checkbox dialog
      //
      QtCheckBoxSelectionDialog cbsd(theMainWindow,
                                     "Apply Rotation",
                                     "Apply to these volumes:",
                                     itemLabels,
                                     itemSelections);
      
      //
      // Did user press OK ?
      //
      if (cbsd.exec() == QDialog::Accepted) {
         QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
   
         vtkTransform* transform = vtkTransform::New();
         switch (bmv->getSelectedAxis(0)) {
            case VolumeFile::VOLUME_AXIS_X:
               transform->RotateX(-bmv->getDisplayRotation(0));
               break;
            case VolumeFile::VOLUME_AXIS_Y:
               transform->RotateY(bmv->getDisplayRotation(0));
               break;
            case VolumeFile::VOLUME_AXIS_Z:
               transform->RotateZ(-bmv->getDisplayRotation(0));
               break;
            case VolumeFile::VOLUME_AXIS_ALL:
            case VolumeFile::VOLUME_AXIS_OBLIQUE:
            case VolumeFile::VOLUME_AXIS_OBLIQUE_X:
            case VolumeFile::VOLUME_AXIS_OBLIQUE_Y:
            case VolumeFile::VOLUME_AXIS_OBLIQUE_Z:
            case VolumeFile::VOLUME_AXIS_OBLIQUE_ALL:
            case VolumeFile::VOLUME_AXIS_UNKNOWN:
               break;
         }
         //
         // Apply to primary overlay volume
         //
         if (primaryOverlayIndex >= 0) {
            if (cbsd.getCheckBoxStatus(primaryOverlayIndex)) {
               primaryOverlay->applyTransformationMatrix(transform);
            }
         }
         
         //
         // Apply to secondary overlay volume
         //
         if (secondaryOverlayIndex >= 0) {
            if (cbsd.getCheckBoxStatus(secondaryOverlayIndex)) {
               secondaryOverlay->applyTransformationMatrix(transform);
            }
         }
         
         //
         // Apply to underlay volume
         //
         if (underlayIndex >= 0) {
            if (cbsd.getCheckBoxStatus(underlayIndex)) {
               underlay->applyTransformationMatrix(transform);
            }
         }
         
         transform->Delete();
         
         //
         // Reset the transformations
         //
         bmv->resetViewingTransform(0);
         GuiFilesModified fm;
         fm.setVolumeModified();
         theMainWindow->fileModificationUpdate(fm);
         GuiBrainModelOpenGL::updateAllGL();
         
         QApplication::restoreOverrideCursor();
      }
   }
}

/**
 * Called when anatomy threshold menu item selected.
 */
void 
GuiMainWindowVolumeActions::slotAnatomyThreshold()
{
   theMainWindow->getVolumeThresholdSegmentationDialog(true);
}

/**
 * called to edit paint volume voxels.
 */
void 
GuiMainWindowVolumeActions::slotPaintEditVoxels()
{
   theMainWindow->getVolumePaintEditorDialog(true);
}

/**
 * called to convert prob atlas volume to a functional volume.
 */
void 
GuiMainWindowVolumeActions::slotProbAtlasConvertToFunctional()
{
   GuiVolumeSelectionDialog vsd(theMainWindow,
                                false,
                                true,
                                false,
                                false,
                                false,
                                false,
                                false,
                                GuiVolumeSelectionControl::LABEL_MODE_FILE_LABEL_AND_NAME,
                                "selectFuncForProbAtlasDialog",
                                true,
                                true,
                                true);
   if (vsd.exec() == QDialog::Accepted) {
      QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
      BrainModelVolumeProbAtlasToFunctional bmvpatf(theMainWindow->getBrainSet(),
                                                    vsd.getSelectedVolumeFile(),
                                                    vsd.getSelectedVolumeFileName(),
                                                    vsd.getSelectedVolumeDescriptiveLabel());
      try {
         bmvpatf.execute();
      }
      catch (BrainModelAlgorithmException& e) {
         GuiMessageBox::critical(theMainWindow, "ERROR", e.whatQString(), "OK");
         return;
      }
      GuiFilesModified fm;
      fm.setVolumeModified();
      theMainWindow->fileModificationUpdate(fm);
      GuiBrainModelOpenGL::updateAllGL();
      QApplication::beep();
      QApplication::restoreOverrideCursor();
   }
}

/**
 * Called to remove islands from segmentation volume.
 */
void 
GuiMainWindowVolumeActions::slotSegmentRemoveIslands()
{
   BrainModelVolume* bmv = theMainWindow->getBrainSet()->getBrainModelVolume(-1);
   if (bmv != NULL) {
      VolumeFile* vf = bmv->getSelectedVolumeSegmentationFile();
      
      if (vf != NULL) {
         QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
         vf->removeIslandsFromSegmentation();
         GuiFilesModified fm;
         fm.setVolumeModified();
         theMainWindow->fileModificationUpdate(fm);
         GuiBrainModelOpenGL::updateAllGL();
         QApplication::restoreOverrideCursor();
      }
   }
}      

/**
 * Called to generate the cerebral hull volume from the segmentation volume.
 */
void 
GuiMainWindowVolumeActions::slotSegmentationCerebralHull()
{
   BrainModelVolume* bmv = theMainWindow->getBrainSet()->getBrainModelVolume(-1);
   if (bmv != NULL) {
      VolumeFile* vf = bmv->getSelectedVolumeSegmentationFile();
      
      if (vf != NULL) {
         QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
         try {
            theMainWindow->getBrainSet()->generateCerebralHullVtkFile(vf, true);
         }
         catch (BrainModelAlgorithmException& e) {
            GuiMessageBox::critical(theMainWindow, "ERROR", e.whatQString(), "OK");
            return;
         }
         DisplaySettingsVolume* dsv = theMainWindow->getBrainSet()->getDisplaySettingsVolume();
         dsv->setSelectedSegmentationVolume(theMainWindow->getBrainSet()->getNumberOfVolumeSegmentationFiles() - 1);
         GuiFilesModified fm;
         fm.setVolumeModified();
         theMainWindow->fileModificationUpdate(fm);
         GuiBrainModelOpenGL::updateAllGL();
         QApplication::restoreOverrideCursor();
      }
   }
}

/**
 * Called to display topology information.
 */
void 
GuiMainWindowVolumeActions::slotSegmentationTopologyReport()
{
   static GuiVolumeTopologyReportDialog* trd = NULL;
   if (trd == NULL) {
      trd = new GuiVolumeTopologyReportDialog(theMainWindow);
   }
   trd->show();
   trd->activateWindow();
}

/**
 * Called to fill cavities.
 */
void 
GuiMainWindowVolumeActions::slotSegmentationFillCavities()
{
   BrainModelVolume* bmv = theMainWindow->getBrainSet()->getBrainModelVolume(-1);
   if (bmv != NULL) {
      VolumeFile* vf = bmv->getSelectedVolumeSegmentationFile();
      
      if (vf != NULL) {
         QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
         vf->fillSegmentationCavities();
         GuiFilesModified fm;
         fm.setVolumeModified();
         theMainWindow->fileModificationUpdate(fm);
         GuiBrainModelOpenGL::updateAllGL();
         QApplication::restoreOverrideCursor();
      }
   }
}
      
/**
 * Called to pad the segmentation volume.
 */
void 
GuiMainWindowVolumeActions::slotSegmentPad()
{
   BrainModelVolume* bmv = theMainWindow->getBrainSet()->getBrainModelVolume(-1);
   if (bmv != NULL) {
      VolumeFile* vf = bmv->getSelectedVolumeSegmentationFile();
      
      if (vf != NULL) {
         std::vector<QString> labels, values;
         labels.push_back("X Left      ");   values.push_back("0");
         labels.push_back("X Right     ");   values.push_back("0");
         labels.push_back("Y Posterior ");   values.push_back("0");
         labels.push_back("Y Anterior  ");   values.push_back("0");
         labels.push_back("Z Inferior  ");   values.push_back("0");
         labels.push_back("Z Superior  ");   values.push_back("0");
         QtMultipleInputDialog mip(theMainWindow,
                                   "Pad Segmentation Volume",
                                   "",
                                   labels,
                                   values,
                                   true,
                                   true);
         if (mip.exec() == QDialog::Accepted) {
            QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
            std::vector<int> values;
            mip.getValues(values);
            int padding[6];
            for (int i = 0; i < 6; i++) {
               padding[i] = values[i];
            }
            
            vf->padSegmentation(padding);
            GuiFilesModified fm;
            fm.setVolumeModified();
            theMainWindow->fileModificationUpdate(fm);
            GuiBrainModelOpenGL::updateAllGL();
            QApplication::restoreOverrideCursor();
         }
      }
   }
}

/**
 * Segment the selected anatomical volume.
 */
void
GuiMainWindowVolumeActions::slotSureFitSegmentation()
{
   GuiVolumeSureFitSegmentationDialog* sd = new GuiVolumeSureFitSegmentationDialog(theMainWindow);
   sd->show();
   sd->activateWindow();
}

/**
 * Segment the selected anatomical volume multi hem.
 */
void
GuiMainWindowVolumeActions::slotSureFitMultiHemSegmentation()
{
   theMainWindow->getVolumeSureFitMultiHemSegmentationDialog(true);
}

/**
 * Called to display the segmentation volume editor
 */
void
GuiMainWindowVolumeActions::slotSegmentationEditVoxels()
{
   theMainWindow->getVolumeSegmentationEditorDialog(true);
}

/**
 * Called to find handles in segmentation volume.
 */
void
GuiMainWindowVolumeActions::slotSegmentationFindHandles()
{
   static GuiVolumeHandleFinderDialog* hdf = NULL;
   if (hdf == NULL) {
      hdf = new GuiVolumeHandleFinderDialog(theMainWindow);
   }
   hdf->show();
   hdf->activateWindow();
}

/**
 * Called to reconstruct a segmentation volume into a surface..
 */
void
GuiMainWindowVolumeActions::slotSegmentationReconstruct()
{
   BrainModelVolume* bmv = theMainWindow->getBrainSet()->getBrainModelVolume(-1);
   if (bmv != NULL) {
      VolumeFile* vf = bmv->getSelectedVolumeSegmentationFile();
      
      if (vf != NULL) {
         GuiVolumeReconstructionDialog vrd(theMainWindow, vf, true);
         vrd.exec();
      }
   }
}

/**
 * update the actions (typically called when menu is about to show)
 */
void 
GuiMainWindowVolumeActions::updateActions()
{
   bool haveUnderlayVolume = false;
   BrainModelVolume* bmv = theMainWindow->getBrainModelVolume();
   if (bmv != NULL) {
      haveUnderlayVolume = (bmv->getUnderlayVolumeFile() != NULL);
   }
   
   resizeUnderlayVolumeAction->setEnabled(haveUnderlayVolume);

   anatomyThresholdAction->setEnabled(theMainWindow->getBrainSet()->getNumberOfVolumeAnatomyFiles() > 0);
   
   applyRotationAction->setEnabled(enableRotationAction->isChecked());

   editPaintVolumeAction->setEnabled(theMainWindow->getBrainSet()->getNumberOfVolumePaintFiles() > 0);

   probAtlasToVolumeAction->setEnabled(theMainWindow->getBrainSet()->getNumberOfVolumeProbAtlasFiles() > 0);

}

