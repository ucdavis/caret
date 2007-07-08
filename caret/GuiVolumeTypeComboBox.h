
#ifndef __GUI_VOLUME_TYPE_COMBO_BOX_H__
#define __GUI_VOLUME_TYPE_COMBO_BOX_H__

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

#include <vector>
#include <QComboBox>

#include "VolumeFile.h"

/// class for selecting a volume type (anatomy, functional, etc)
class GuiVolumeTypeComboBox : public QComboBox {
   Q_OBJECT
   
   public:
      // constructor
      GuiVolumeTypeComboBox(const bool showUnknown = false,
                            QWidget* parent = 0);
                            
      // destructor
      ~GuiVolumeTypeComboBox();
      
      // get the volume type
      VolumeFile::VOLUME_TYPE getVolumeType() const;
      
      // set the volume type
      void setVolumeType(const VolumeFile::VOLUME_TYPE vt);
      
   protected:
      /// the volume types in the combo box
      std::vector<VolumeFile::VOLUME_TYPE> types;
};

#endif // __GUI_VOLUME_TYPE_COMBO_BOX_H__

