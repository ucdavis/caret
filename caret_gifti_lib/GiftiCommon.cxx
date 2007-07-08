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

#include <QTextStream>

#define __GIFTI_COMMON_MAIN__
#include "GiftiCommon.h"
#undef __GIFTI_COMMON_MAIN__

/**
 * get name for this system's endian.
 */
QString 
GiftiCommon::getSystemsEndianName()
{
   int wordSize;
   bool bigEndian;
   qSysInfo(&wordSize, &bigEndian);
   if (bigEndian) {
      return GiftiCommon::endianBig;
   }
   return GiftiCommon::endianLittle;
}
      
/**
 * used to write indentation space.
 */
void 
GiftiCommon::writeIndentationXML(QTextStream& stream,
                                 const int indentOffset)
{
   const int offsetTotal = indentOffset * 3;
   for (int i = 0; i < offsetTotal; i++) {
      stream << " ";
   }
}                    

/**
 * get attribute for a specific dimensions.
 */
QString 
GiftiCommon::getAttDim(const int dimNum)
{
   QString d(attDim);
   d += QString::number(dimNum);
   return d;
}

/**
 * get all space labels.
 */
void 
GiftiCommon::getAllSpaceLabels(QStringList& labels)
{
   labels.clear();
   labels << spaceLabelUnknown;
   labels << spaceLabelScannerCoords;
   labels << spaceLabelAlignedAnatomical;
   labels << spaceLabelTalairach;
   labels << spaceLabelMNI152;
}      
