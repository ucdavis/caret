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

#include "BrainModelVolumeGradient.h"
#include "BrainSet.h"
#include "CommandVolumeGradient.h"
#include "FileFilters.h"
#include "ProgramParameters.h"
#include "ScriptBuilderParameters.h"
#include "SureFitVectorFile.h"
#include "VolumeFile.h"

/**
 * constructor.
 */
CommandVolumeGradient::CommandVolumeGradient()
   : CommandBase("-volume-gradient",
                 "VOLUME GRADIENT")
{
}

/**
 * destructor.
 */
CommandVolumeGradient::~CommandVolumeGradient()
{
}

/**
 * get the script builder parameters.
 */
void 
CommandVolumeGradient::getScriptBuilderParameters(ScriptBuilderParameters& paramsOut) const
{
   paramsOut.clear();
   paramsOut.addFile("Input Volume File Name", FileFilters::getVolumeGenericFileFilter());
   paramsOut.addFile("Mask Volume File Name", FileFilters::getVolumeGenericFileFilter());
   paramsOut.addFile("Output Gradient Vector File", FileFilters::getSureFitVectorFileFilter());
   paramsOut.addInt("Lambda");
   paramsOut.addBoolean("Grad Flag");
   paramsOut.addBoolean("Mask Flag");
}

/**
 * get full help information.
 */
QString 
CommandVolumeGradient::getHelpInformation() const
{
   QString helpInfo =
      (indent3 + getShortDescription() + "\n"
       + indent6 + parameters->getProgramNameWithoutPath() + " " + getOperationSwitch() + "  \n"
       + indent9 + "<input-volume-file>\n"
       + indent9 + "<input-mask-volume-file>\n"
       + indent9 + "<gradient-vector-file-name>\n"
       + indent9 + "<lambda>\n"
       + indent9 + "<grad-flag>\n"
       + indent9 + "<mask-flag>\n"
       + indent9 + "\n"
       + indent9 + "Compute gradient.\n"
       + indent9 + "\n");
      
   return helpInfo;
}

/**
 * execute the command.
 */
void 
CommandVolumeGradient::executeCommand() throw (BrainModelAlgorithmException,
                                     CommandException,
                                     FileException,
                                     ProgramParametersException,
                                     StatisticException)
{
   const QString inputVolumeFileName =
      parameters->getNextParameterAsString("Input Volume File Name");
   const QString inputMaskVolumeFileName =
      parameters->getNextParameterAsString("Input Mask Volume File Name");
   const QString outputGradientFileName =
      parameters->getNextParameterAsString("Output Gradient Vector File Name");
   const int lambda =
      parameters->getNextParameterAsInt("Lambda");
   const int gradFlag =
      parameters->getNextParameterAsBoolean("Grad Flag");
   const int maskFlag =
      parameters->getNextParameterAsBoolean("Mask Flag");

   //
   // Read the input and mask volume files
   //
   VolumeFile vf;
   vf.readFile(inputVolumeFileName);
   VolumeFile maskVolume;
   maskVolume.readFile(inputMaskVolumeFileName);

   //
   // Gradient vector file
   //
   int xDim, yDim, zDim;
   vf.getDimensions(xDim, yDim, zDim);
   SureFitVectorFile gradFile(xDim, yDim, zDim);
   
   //
   // determine gradient
   //
   BrainSet bs;
   BrainModelVolumeGradient grad(&bs,
                                 lambda,
                                 gradFlag,
                                 maskFlag,
                                 &vf,
                                 &maskVolume,
                                 &gradFile);
   grad.execute();
   
   //
   // Write the gradient file
   //
   gradFile.writeFile(outputGradientFileName);
   
}

      

