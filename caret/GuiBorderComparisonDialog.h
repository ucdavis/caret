
#ifndef __GUI_BORDER_COMPARISON_DIALOG_H__
#define __GUI_BORDER_COMPARISON_DIALOG_H__

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

#include "QtDialog.h"

class QLineEdit;

/// dialog for comparing borders
class GuiBorderComparisonDialog : public QtDialog {
   Q_OBJECT
   
   public:
      /// constructor
      GuiBorderComparisonDialog(QWidget* parent);
      
      /// destructor
      ~GuiBorderComparisonDialog();
      
   protected slots:
      /// called when apply button is pressed
      void slotApplyButton();
      
      /// called when border file A button is pressed
      void slotButtonBorderFileA();
      
      /// called when border file B button is pressed
      void slotButtonBorderFileB();
      
   protected:
      /// line edit for border file A name
      QLineEdit* borderFileALineEdit;
      
      /// line edit for border file B name
      QLineEdit* borderFileBLineEdit;
      
};

#endif // __GUI_BORDER_COMPARISON_DIALOG_H__
