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



#ifndef __VE_DISPLAY_SETTINGS_METRIC_H__
#define __VE_DISPLAY_SETTINGS_METRIC_H__

#include <vector>

#include "DisplaySettings.h"

class BrainSet;

/// DisplaySettingsMetric is a class that maintains parameters for controlling
/// the display of metric data files.
class DisplaySettingsMetric : public DisplaySettings {
   public:
      /// Metric graphing
      enum METRIC_DATA_PLOT {
         METRIC_DATA_PLOT_OFF,
         METRIC_DATA_PLOT_NODE,
         METRIC_DATA_PLOT_NODE_AND_NEIGHBORS
      };
      
      /// Metric scaling for color mapping
      enum METRIC_OVERLAY_SCALE {
         /// auto scale using selected metric column min/max
         METRIC_OVERLAY_SCALE_AUTO_METRIC,
         /// auto scale using selection functional volume min/max
         METRIC_OVERLAY_SCALE_AUTO_FUNC_VOLUME,
         /// auto scale using user entered min/max
         METRIC_OVERLAY_SCALE_USER
      };
      
      /// Positive/Negative Display
      enum METRIC_DISPLAY_MODE {
         METRIC_DISPLAY_MODE_POSITIVE_AND_NEGATIVE,
         METRIC_DISPLAY_MODE_POSITIVE_ONLY,
         METRIC_DISPLAY_MODE_NEGATIVE_ONLY
      };
      
      /// type of thresholding
      enum METRIC_THRESHOLDING_TYPE {
         METRIC_THRESHOLDING_TYPE_FILE_COLUMN,
         METRIC_THRESHOLDING_TYPE_FILE_COLUMN_AVERAGE,
         METRIC_THRESHOLDING_TYPE_USER_VALUES,
      };
      
      /// Constructor
      DisplaySettingsMetric(BrainSet* bs);
      
      /// Destructor
      ~DisplaySettingsMetric();
      
      /// Reinitialize all display settings
      void reset();
      
      /// Update any selections due to changes in loaded metric file
      void update();
      
      /// get the type of metric thresholding
      METRIC_THRESHOLDING_TYPE getMetricThresholdingType() const { return thresholdType; }
      
      /// set the type of metric thresholding
      void setMetricThresholdingType(const METRIC_THRESHOLDING_TYPE mtt) 
         { thresholdType = mtt; }
         
      /// get the user thresholding values
      void getUserThresholdingValues(float& negThresh, float& posThresh) const;
      
      /// set the user thresholding values
      void setUserThresholdingValues(const float negThresh, const float posThresh);
      
      /// get column selected for display
      int getSelectedDisplayColumn(const int model);
      
      /// set column for display
      void setSelectedDisplayColumn(const int model,
                                    const int sdc);
      
      /// get column selected for thresholding
      int getSelectedThresholdColumn(const int model);
      
      /// set column for thresholding
      void setSelectedThresholdColumn(const int model,
                                      const int sdc);
      
      /// get selected overlay scale
      METRIC_OVERLAY_SCALE getSelectedOverlayScale() const { return overlayScale; }
      
      /// set selected overlay scale
      void setSelectedOverlayScale(const METRIC_OVERLAY_SCALE mos) { overlayScale = mos; }
      
      /// get the user scale minimum and maximum
      void getUserScaleMinMax(float& posMinValue, 
                              float& posMaxValue,
                              float& negMinValue,
                              float& negMaxValue) const;
      
      /// set the user scale minimum and maximum
      void setUserScaleMinMax(const float posMinValue,
                              const float posMaxValue,
                              const float negMinValue,
                              const float negMaxValue);
      
      /// get display color bar
      bool getDisplayColorBar() const { return displayColorBar; }

      /// set display color bar
      void setDisplayColorBar(const bool dcb) { displayColorBar = dcb; }

      /// get interpolate colors flag
      bool getInterpolateColors() const { return interpolateColors; }
      
      /// set interpolate colors flag
      void setInterpolateColors(const int ic) { interpolateColors = ic; }
      
      /// get the display mode
      METRIC_DISPLAY_MODE getDisplayMode() const { return displayMode; }
      
      /// set the display mode
      void setDisplayMode(const METRIC_DISPLAY_MODE mdm) { displayMode = mdm; }
      
      /// get the selected palette index
      int getSelectedPaletteIndex() const { return paletteIndex; }

      /// set the selected palette index
      void setSelectedPaletteIndex(const int pi) { paletteIndex = pi; }

      /// get popup plot of metric data when node identified
      METRIC_DATA_PLOT getMDataPlotOnNodeID() const { return metricDataPlot; }
      
      /// set popup plot of metric data when node identified
      void setDataPlotOnNodeID(const METRIC_DATA_PLOT dp) { metricDataPlot = dp; }
      
      /// get manual data plot scaling
      bool getDataPlotManualScaling(float& minPlot, float& maxPlot) const;
      
      /// set manual data plot scaling
      void setDataPlotManualScaling(const bool b, const float minPlot,
                                    const float maxPlot);
                                    
      /// get show special color for thresholded nodes
      bool getShowSpecialColorForThresholdedNodes() const
             { return showSpecialColorForThresholdedNodes; }
             
      /// set show special color for thresholded nodes
      void setShowSpecialColorForThresholdedNodes(const bool b)
             { showSpecialColorForThresholdedNodes = b; }
             
      /// get special color for thresholded nodes
      void getSpecialColorsForThresholdedNodes(unsigned char negThreshColor[3],
                                               unsigned char posThreshColor[3]) const;
                                               
      /// get apply to left and right structures flag
      bool getApplySelectionToLeftAndRightStructuresFlag() const 
             { return applySelectionToLeftAndRightStructuresFlag; }
      
      /// set apply to left and right structures flag
      void setApplySelectionToLeftAndRightStructuresFlag(const bool b) 
             { applySelectionToLeftAndRightStructuresFlag = b; }
      
      /// apply a scene (set display settings)
      virtual void showScene(const SceneFile::Scene& scene, QString& errorMessage) ;
      
      /// create a scene (read display settings)
      virtual void saveScene(SceneFile::Scene& scene, const bool onlyIfSelected);
                       
      /// for node attribute files - all column selections for each surface are the same
      virtual bool columnSelectionsAreTheSame(const int bm1, const int bm2) const;
      
   private:
      /// selected column for dislay
      std::vector<int> displayColumn;
      
      /// selected column for thresholding
      std::vector<int> thresholdColumn;
      
      /// metric thresholding type
      METRIC_THRESHOLDING_TYPE thresholdType;
      
      /// user negative threshold
      float userNegativeThreshold;
      
      /// user positive threshold
      float userPositiveThreshold;
      
      /// overlay scale
      METRIC_OVERLAY_SCALE overlayScale;
      
      /// user scale positive minimum value
      float userScalePositiveMinimum;
      
      /// user scale positive maximum
      float userScalePositiveMaximum;
      
      /// user scale negative minimum value
      float userScaleNegativeMinimum;
      
      /// user scale negative maximum
      float userScaleNegativeMaximum;
      
      /// interpolate colors
      bool interpolateColors;
      
      /// display metric color bar
      bool displayColorBar;

      /// selected palette index
      int paletteIndex;

      /// positive / negative display mode
      METRIC_DISPLAY_MODE displayMode;
      
      /// type of data plot
      METRIC_DATA_PLOT metricDataPlot;
      
      /// metric data plot manual scale
      bool metricDataPlotManualScaleFlag;
      
      /// metric data plot manual scale minimum
      float metricDataPlotManualScaleMinimum;
      
      /// metric data plot manual scale maximum
      float metricDataPlotManualScaleMaximum;
      
      /// show thresholded nodes in special color
      bool showSpecialColorForThresholdedNodes;
      
      /// apply coloring with corresponding structures
      bool applySelectionToLeftAndRightStructuresFlag;
};

#endif
