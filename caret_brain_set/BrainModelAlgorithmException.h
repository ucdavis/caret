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



#ifndef __VE_BRAIN_MODEL_ALGORITHM_EXCEPTION_H__
#define __VE_BRAIN_MODEL_ALGORITHM_EXCEPTION_H__

#include <exception>
#include <QString>

class FileException;
class StatisticException;

/// Class for exceptions thrown by algorithms that operate on BrainModels
class BrainModelAlgorithmException : public std::exception {
   public:
      /// Constructor
      BrainModelAlgorithmException(const QString& msg);
      
      /// Constructor
      BrainModelAlgorithmException(const FileException& fioe);
      
      /// Constructor
      BrainModelAlgorithmException(const StatisticException& fioe);
      
      /// Destructor
      virtual ~BrainModelAlgorithmException() throw();
      
      /// get description of exception
      virtual QString whatQString() const throw();
            
   protected:
      /// Description of the exception
      QString description;
      
   private:
      /// get description of exception (private to prevent its use)
      virtual const char* what() const throw() { return ""; }
};

#endif // __VE_BRAIN_MODEL_ALGORITHM_EXCEPTION_H__

