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

#include "BrainModelSurfaceNodeColoring.h"
#include "BrainSet.h"
#include "DisplaySettingsSurface.h"
#include "StringUtilities.h"

/**
 * The constructor.
 */
DisplaySettingsSurface::DisplaySettingsSurface(BrainSet* bs)
   : DisplaySettings(bs)
{
   drawMode = DRAW_MODE_TILES_WITH_LIGHT;
   nodeBrightness = 0.0;
   nodeContrast   = 1.0;
   nodeSize       = 2;
   linkSize       = 2;
   forceVectorDisplayLength = 10.0;
   
   identifyNodeColor = IDENTIFY_NODE_COLOR_GREEN;
   
   showNormals               = false;
   showMorphingTotalForces   = false;
   showMorphingAngularForces = false;
   showMorphingLinearForces  = false;
   partialView = PARTIAL_VIEW_ALL;

   sectionToHighlight = 10;
   sectionHighlightEveryX    = true;
   
   viewingProjection = VIEWING_PROJECTION_ORTHOGRAPHIC;

   showSurfaceAxes = false;
   showSurfaceAxesLetters = true;
   showSurfaceAxesHashMarks = true;
   surfaceAxesLength = 110.0;
   
   surfaceAxesOffset[0] = 0.0;
   surfaceAxesOffset[1] = 0.0;
   surfaceAxesOffset[2] = 0.0;
   
   reset();
}

/**
 * The destructor.
 */
DisplaySettingsSurface::~DisplaySettingsSurface()
{
}

/**
 * Reinitialize all display settings.
 */
void
DisplaySettingsSurface::reset()
{
}   

/**
 * Update any selections do to changes in loaded surface shape file.
 */
void
DisplaySettingsSurface::update()
{
}

/**
 * set the drawing mode.
 */
void 
DisplaySettingsSurface::setDrawMode(const DRAW_MODE dm) 
{ 
   drawMode = dm;

   BrainModelSurfaceNodeColoring* bsnc = brainSet->getNodeColoring();
   
   bool lightOn = false;
   switch (drawMode) {
      case DRAW_MODE_NODES:
         break;
      case DRAW_MODE_LINKS:
         break;
      case DRAW_MODE_LINK_HIDDEN_LINE_REMOVAL:
         break;
      case DRAW_MODE_LINKS_EDGES_ONLY:
         break;
      case DRAW_MODE_NODES_AND_LINKS:
         break;
      case DRAW_MODE_TILES:
         break;
      case DRAW_MODE_TILES_WITH_LIGHT:
         lightOn = true;
         break;
      case DRAW_MODE_TILES_LINKS_NODES:
         lightOn = true;
         break;
      case DRAW_MODE_NONE:
         break;
   }
   bsnc->setLightingOn(lightOn);
}

/**
 * get section highlighting.
 */
void 
DisplaySettingsSurface::getSectionHighlighting(int& sectionToHighlightOut, 
                                               bool& highlightEveryXOut) const
{
   sectionToHighlightOut = sectionToHighlight;
   highlightEveryXOut    = sectionHighlightEveryX;
}

/**
 * set section highlighting.
 */
void 
DisplaySettingsSurface::setSectionHighlighting(const int sectionToHighlightIn,
                                               const bool highlightEveryXIn) 
{
   sectionToHighlight     = sectionToHighlightIn;
   sectionHighlightEveryX = highlightEveryXIn;
}

/**
 * Get show surface axes info.
 */
void 
DisplaySettingsSurface::getSurfaceAxesInfo(bool& showAxes,
                                           bool& showLetters,
                                           bool& showHashMarks,
                                           float& axesLength,
                                           float axesOffset[3]) const
{
   showAxes = showSurfaceAxes;
   showLetters  = showSurfaceAxesLetters;
   showHashMarks = showSurfaceAxesHashMarks;
   axesLength = surfaceAxesLength;
   
   for (int i = 0; i < 3; i++) {
      axesOffset[i] = surfaceAxesOffset[i];
   }
}
                    
/**
 * set show surface axes info.
 */
void 
DisplaySettingsSurface::setSurfaceAxesInfo(const bool showAxes,
                                           const bool showLetters,
                                           const bool showHashMarks,
                                           const float axesLength,
                                           const float axesOffset[3])
{
   showSurfaceAxes = showAxes;
   showSurfaceAxesLetters = showLetters;
   showSurfaceAxesHashMarks = showHashMarks;
   surfaceAxesLength = axesLength;
   for (int i = 0; i < 3; i++) {
      surfaceAxesOffset[i] = axesOffset[i];
   }
}                          

static const QString DRAW_MODE_NODES_VALUE("DRAW_MODE_NODES");
static const QString DRAW_MODE_LINKS_VALUE("DRAW_MODE_LINKS");
static const QString DRAW_MODE_LINK_HIDDEN_LINE_REMOVAL_VALUE("DRAW_MODE_LINK_HIDDEN_LINE_REMOVAL");
static const QString DRAW_MODE_LINKS_EDGES_ONLY_VALUE("DRAW_MODE_LINKS_EDGES_ONLY");
static const QString DRAW_MODE_NODES_AND_LINKS_VALUE("DRAW_MODE_NODES_AND_LINKS");
static const QString DRAW_MODE_TILES_VALUE("DRAW_MODE_TILES");
static const QString DRAW_MODE_TILES_WITH_LIGHT_VALUE("DRAW_MODE_TILES_WITH_LIGHT");
static const QString DRAW_MODE_TILES_LINKS_NODES_VALUE("DRAW_MODE_TILES_LINKS_NODES");
static const QString DRAW_MODE_NONE_VALUE("DRAW_MODE_NONE");

/**
 * apply a scene (set display settings).
 */
void 
DisplaySettingsSurface::showScene(const SceneFile::Scene& scene, QString& /*errorMessage*/) 
{
   const int numClasses = scene.getNumberOfSceneClasses();
   for (int nc = 0; nc < numClasses; nc++) {
      const SceneFile::SceneClass* sc = scene.getSceneClass(nc);
      if (sc->getName() == "DisplaySettingsSurface") {
         const int num = sc->getNumberOfSceneInfo();
         for (int i = 0; i < num; i++) {
            const SceneFile::SceneInfo* si = sc->getSceneInfo(i);
            const QString infoName = si->getName();      
            
            if (infoName == "surfaceDrawMode") {
               const QString drawModeValue = si->getValueAsString();
               if (drawModeValue == DRAW_MODE_NODES_VALUE) {
                  drawMode = DRAW_MODE_NODES;
               }
               else if (drawModeValue == DRAW_MODE_LINKS_VALUE) {
                  drawMode = DRAW_MODE_LINKS;
               }
               else if (drawModeValue == DRAW_MODE_LINK_HIDDEN_LINE_REMOVAL_VALUE) {
                  drawMode = DRAW_MODE_LINK_HIDDEN_LINE_REMOVAL;
               }
               else if (drawModeValue == DRAW_MODE_LINKS_EDGES_ONLY_VALUE) {
                  drawMode = DRAW_MODE_LINKS_EDGES_ONLY;
               }
               else if (drawModeValue == DRAW_MODE_NODES_AND_LINKS_VALUE) {
                  drawMode = DRAW_MODE_NODES_AND_LINKS;
               }
               else if (drawModeValue == DRAW_MODE_TILES_VALUE) {
                  drawMode = DRAW_MODE_TILES;
               }
               else if (drawModeValue == DRAW_MODE_TILES_WITH_LIGHT_VALUE) {
                  drawMode = DRAW_MODE_TILES_WITH_LIGHT;
               }
               else if (drawModeValue == DRAW_MODE_TILES_LINKS_NODES_VALUE) {
                  drawMode = DRAW_MODE_TILES_LINKS_NODES;
               }
               else if (drawModeValue == DRAW_MODE_NONE_VALUE) {
                  drawMode = DRAW_MODE_NONE;
               }
            }
            else if (infoName == "nodeBrightness") {
               si->getValue(nodeBrightness);
            }
            else if (infoName == "nodeContrast") {
               si->getValue(nodeContrast);
            }
            else if (infoName == "nodeSize") {
               si->getValue(nodeSize);
            }
            else if (infoName == "linkSize") {
               si->getValue(linkSize);
            }
            else if (infoName == "forceVectorDisplayLength") {
               si->getValue(forceVectorDisplayLength);
            }
            else if (infoName == "showNormals") {
               si->getValue(showNormals);
            }
            else if (infoName == "showMorphingTotalForces") {
               si->getValue(showMorphingTotalForces);
            }
            else if (infoName == "showMorphingAngularForces") {
               si->getValue(showMorphingAngularForces);
            }
            else if (infoName == "showMorphingLinearForces") {
               si->getValue(showMorphingLinearForces);
            }
            else if (infoName == "partialView") {
               int val;
               si->getValue(val);
               partialView = static_cast<PARTIAL_VIEW_TYPE>(val);
            }
            else if (infoName == "sectionToHighlight") {
               si->getValue(sectionToHighlight);
            }
            else if (infoName == "sectionHighlightEveryX") {
               si->getValue(sectionHighlightEveryX);
            }
            else if (infoName == "viewingProjection") {
               int val;
               si->getValue(val);
               viewingProjection = static_cast<VIEWING_PROJECTION>(val);
            }
            else if (infoName == "showSurfaceAxes") {
               si->getValue(showSurfaceAxes);
            }
            else if (infoName == "showSurfaceAxesLetters") {
               si->getValue(showSurfaceAxesLetters);
            }
            else if (infoName == "showSurfaceAxesHashMarks") {
               si->getValue(showSurfaceAxesHashMarks);
            }
            else if (infoName == "surfaceAxesLength") {
               si->getValue(surfaceAxesLength);
            }
            else if (infoName == "surfaceAxesOffset") {
               const QString val = si->getValueAsString();
               std::vector<QString> tokens;
               StringUtilities::token(val, " ", tokens);
               if (tokens.size() >= 3) {
                  surfaceAxesOffset[0] = tokens[0].toFloat();
                  surfaceAxesOffset[1] = tokens[1].toFloat();
                  surfaceAxesOffset[2] = tokens[2].toFloat();
               }
            }
            else if (infoName == "identifyNodeColor") {
               identifyNodeColor = static_cast<IDENTIFY_NODE_COLOR>(si->getValueAsInt());
            }
         }
      }
   }
}

/**
 * create a scene (read display settings).
 */
void 
DisplaySettingsSurface::saveScene(SceneFile::Scene& scene, const bool onlyIfSelected)
{
   if (onlyIfSelected) {
      const int num = brainSet->getNumberOfBrainModels();
      bool haveSurfacesFlag = false;
      for (int i = 0; i < num; i++) {
         if (brainSet->getBrainModelSurface(i) != NULL) {
            haveSurfacesFlag = true;
            break;
         }
      }
      if (haveSurfacesFlag == false) {
         return;
      }
   }
   
   SceneFile::SceneClass sc("DisplaySettingsSurface");
   
   QString drawModeValue(DRAW_MODE_NODES_VALUE);
   switch (drawMode) {
      case DRAW_MODE_NODES:
         drawModeValue = DRAW_MODE_NODES_VALUE;
         break;
      case DRAW_MODE_LINKS:
         drawModeValue = DRAW_MODE_LINKS_VALUE;
         break;
      case DRAW_MODE_LINK_HIDDEN_LINE_REMOVAL:
         drawModeValue = DRAW_MODE_LINK_HIDDEN_LINE_REMOVAL_VALUE;
         break;
      case DRAW_MODE_LINKS_EDGES_ONLY:
         drawModeValue = DRAW_MODE_LINKS_EDGES_ONLY_VALUE;
         break;
      case DRAW_MODE_NODES_AND_LINKS:
         drawModeValue = DRAW_MODE_NODES_AND_LINKS_VALUE;
         break;
      case DRAW_MODE_TILES:
         drawModeValue = DRAW_MODE_TILES_VALUE;
         break;
      case DRAW_MODE_TILES_WITH_LIGHT:
         drawModeValue = DRAW_MODE_TILES_WITH_LIGHT_VALUE;
         break;
      case DRAW_MODE_TILES_LINKS_NODES:
         drawModeValue = DRAW_MODE_TILES_LINKS_NODES_VALUE;
         break;
      case DRAW_MODE_NONE:
         drawModeValue = DRAW_MODE_NONE_VALUE;
         break;
   }
   sc.addSceneInfo(SceneFile::SceneInfo("surfaceDrawMode",
                                        drawModeValue));
   sc.addSceneInfo(SceneFile::SceneInfo("nodeBrightness",
                                        nodeBrightness));
   sc.addSceneInfo(SceneFile::SceneInfo("nodeContrast",
                                        nodeContrast));
   sc.addSceneInfo(SceneFile::SceneInfo("nodeSize",
                                        nodeSize));
   sc.addSceneInfo(SceneFile::SceneInfo("linkSize",
                                        linkSize));
   sc.addSceneInfo(SceneFile::SceneInfo("forceVectorDisplayLength",
                                        forceVectorDisplayLength));
   sc.addSceneInfo(SceneFile::SceneInfo("showNormals",
                                        showNormals));
   sc.addSceneInfo(SceneFile::SceneInfo("showMorphingTotalForces",
                                        showMorphingTotalForces));
   sc.addSceneInfo(SceneFile::SceneInfo("showMorphingAngularForces",
                                        showMorphingAngularForces));
   sc.addSceneInfo(SceneFile::SceneInfo("showMorphingLinearForces",
                                        showMorphingLinearForces));
   sc.addSceneInfo(SceneFile::SceneInfo("partialView",
                                        partialView));
   sc.addSceneInfo(SceneFile::SceneInfo("sectionToHighlight",
                                        sectionToHighlight));
   sc.addSceneInfo(SceneFile::SceneInfo("sectionHighlightEveryX",
                                        sectionHighlightEveryX));
   sc.addSceneInfo(SceneFile::SceneInfo("viewingProjection",
                                        viewingProjection));
   sc.addSceneInfo(SceneFile::SceneInfo("showSurfaceAxes",
                                        showSurfaceAxes));
   sc.addSceneInfo(SceneFile::SceneInfo("showSurfaceAxesLetters",
                                        showSurfaceAxesLetters));
   sc.addSceneInfo(SceneFile::SceneInfo("showSurfaceAxesHashMarks",
                                        showSurfaceAxesHashMarks));
   sc.addSceneInfo(SceneFile::SceneInfo("surfaceAxesLength",
                                        surfaceAxesLength));
   sc.addSceneInfo(SceneFile::SceneInfo("identifyNodeColor",
                                        identifyNodeColor));
   std::vector<float> offsets;
   offsets.push_back(surfaceAxesOffset[0]);
   offsets.push_back(surfaceAxesOffset[1]);
   offsets.push_back(surfaceAxesOffset[2]);
   sc.addSceneInfo(SceneFile::SceneInfo("surfaceAxesOffset",
                                        StringUtilities::combine(offsets, " ")));
   scene.addSceneClass(sc);
}
                       
