
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

#include <algorithm>
#include <iostream>

#define __HTML_COLORS_MAIN__
#include "HtmlColors.h"
#undef __HTML_COLORS_MAIN__


/**
 * get the names of all colors.
 */
void 
HtmlColors::getAllColorNames(std::vector<QString>& allColorNames)
{
   initializeColors();

   allColorNames.clear();
   
   for (unsigned int i = 0; i < colors.size(); i++) {
      allColorNames.push_back(colors[i].name);
   }
}

/**
 * get the RGB values for a color name (returns true if color name valid).
 */
bool 
HtmlColors::getRgbFromColorName(const QString& colorName,
                                unsigned char& redOut,
                                unsigned char& greenOut,
                                unsigned char& blueOut)
{
   initializeColors();
   
   bool validColor = false;
   const int num = getNumberOfColors();
   for (int i = 0; i < num; i++) {
      if (colors[i].name.toLower() == colorName.toLower()) {
         redOut   = colors[i].red;
         greenOut = colors[i].green;
         blueOut  = colors[i].blue;
         validColor = true;
         break;
      }
   }
   return validColor;
}

/**
 * get the number of colors.
 */
int 
HtmlColors::getNumberOfColors()
{
   initializeColors();
   
   return colors.size();
}

/**
 * get color information given a color index.
 */
void 
HtmlColors::getColorInformation(const int colorIndex,
                                QString& colorNameOut,
                                unsigned char& redOut,
                                unsigned char& greenOut,
                                unsigned char& blueOut)
{
   initializeColors();
   
   if ((colorIndex >= 0) && (colorIndex < static_cast<int>(getNumberOfColors()))) {
      colorNameOut = colors[colorIndex].name;
      redOut       = colors[colorIndex].red;
      greenOut     = colors[colorIndex].green;
      blueOut      = colors[colorIndex].blue;
   }
}
                                      
/**
 * intialize the colors.
 */
void 
HtmlColors::initializeColors()
{
   if (colorsInitializedFlag) {
      return;
   }
   colorsInitializedFlag = true;
   
   {
      const QString colorsInit[] = {
         "AliceBlue", 	"#F0F8FF",
         "AntiqueWhite", 	"#FAEBD7",	 
         "Aqua", 	"#00FFFF",	 
         "Aquamarine", 	"#7FFFD4",	 
         "Azure", 	"#F0FFFF",	 
         "Beige", 	"#F5F5DC",	 
         "Bisque", 	"#FFE4C4",	 
         "Black", 	"#000000",	 
         "BlanchedAlmond", 	"#FFEBCD",	 
         "Blue", 	"#0000FF",	 
         "BlueViolet", 	"#8A2BE2",	 
         "Brown", 	"#A52A2A",	 
         "BurlyWood", 	"#DEB887",	 
         "CadetBlue", 	"#5F9EA0",	 
         "Chartreuse", 	"#7FFF00",	 
         "Chocolate", 	"#D2691E",	 
         "Coral", 	"#FF7F50",	 
         "CornflowerBlue", 	"#6495ED",	 
         "Cornsilk", 	"#FFF8DC",	 
         "Crimson", 	"#DC143C",	 
         "Cyan", 	"#00FFFF",	 
         "DarkBlue", 	"#00008B",	 
         "DarkCyan", 	"#008B8B",	 
         "DarkGoldenRod", 	"#B8860B",	 
         "DarkGray", 	"#A9A9A9",	 
         "DarkGrey", 	"#A9A9A9",	 
         "DarkGreen", 	"#006400",	 
         "DarkKhaki", 	"#BDB76B",	 
         "DarkMagenta", 	"#8B008B",	 
         "DarkOliveGreen", 	"#556B2F",	 
         "Darkorange", 	"#FF8C00",	 
         "DarkOrchid", 	"#9932CC",	 
         "DarkRed", 	"#8B0000",	 
         "DarkSalmon", 	"#E9967A",	 
         "DarkSeaGreen", 	"#8FBC8F",	 
         "DarkSlateBlue", 	"#483D8B",	 
         "DarkSlateGray", 	"#2F4F4F",	 
         "DarkSlateGrey", 	"#2F4F4F",	 
         "DarkTurquoise", 	"#00CED1",	 
         "DarkViolet", 	"#9400D3",	 
         "DeepPink", 	"#FF1493",	 
         "DeepSkyBlue", 	"#00BFFF",	 
         "DimGray", 	"#696969",	 
         "DimGrey", 	"#696969",	 
         "DodgerBlue", 	"#1E90FF",	 
         "FireBrick", 	"#B22222",	 
         "FloralWhite", 	"#FFFAF0",	 
         "ForestGreen", 	"#228B22",	 
         "Fuchsia", 	"#FF00FF",	 
         "Gainsboro", 	"#DCDCDC",	 
         "GhostWhite", 	"#F8F8FF",	 
         "Gold", 	"#FFD700",	 
         "GoldenRod", 	"#DAA520",	 
         "Gray", 	"#808080",	 
         "Grey", 	"#808080",	 
         "Green", 	"#008000",	 
         "GreenYellow", 	"#ADFF2F",	 
         "HoneyDew", 	"#F0FFF0",	 
         "HotPink", 	"#FF69B4",
         "IndianRed",  	"#CD5C5C",	 
         "Indigo",  	"#4B0082",	 
         "Ivory", 	"#FFFFF0",	 
         "Khaki", 	"#F0E68C",	 
         "Lavender", 	"#E6E6FA",	 
         "LavenderBlush", 	"#FFF0F5",	 
         "LawnGreen", 	"#7CFC00",	 
         "LemonChiffon", 	"#FFFACD",	 
         "LightBlue", 	"#ADD8E6",	 
         "LightCoral", 	"#F08080",	 
         "LightCyan", 	"#E0FFFF",	 
         "LightGoldenRodYellow", 	"#FAFAD2",	 
         "LightGray", 	"#D3D3D3",	 
         "LightGrey", 	"#D3D3D3",	 
         "LightGreen", 	"#90EE90",	 
         "LightPink", 	"#FFB6C1",	 
         "LightSalmon", 	"#FFA07A",	 
         "LightSeaGreen", 	"#20B2AA",	 
         "LightSkyBlue", 	"#87CEFA",	 
         "LightSlateGray", 	"#778899",	 
         "LightSlateGrey", 	"#778899",	 
         "LightSteelBlue", 	"#B0C4DE",	 
         "LightYellow", 	"#FFFFE0",	 
         "Lime", 	"#00FF00",	 
         "LimeGreen", 	"#32CD32",	 
         "Linen", 	"#FAF0E6",	 
         "Magenta", 	"#FF00FF",	 
         "Maroon", 	"#800000",	 
         "MediumAquaMarine", 	"#66CDAA",	 
         "MediumBlue", 	"#0000CD",	 
         "MediumOrchid", 	"#BA55D3",	 
         "MediumPurple", 	"#9370D8",	 
         "MediumSeaGreen", 	"#3CB371",	 
         "MediumSlateBlue", 	"#7B68EE",	 
         "MediumSpringGreen", 	"#00FA9A",	 
         "MediumTurquoise", 	"#48D1CC",	 
         "MediumVioletRed", 	"#C71585",	 
         "MidnightBlue", 	"#191970",	 
         "MintCream", 	"#F5FFFA",	 
         "MistyRose", 	"#FFE4E1",	 
         "Moccasin", 	"#FFE4B5",	 
         "NavajoWhite", 	"#FFDEAD",	 
         "Navy", 	"#000080",	 
         "OldLace", 	"#FDF5E6",	 
         "Olive", 	"#808000",	 
         "OliveDrab", 	"#6B8E23",	 
         "Orange", 	"#FFA500",	 
         "OrangeRed", 	"#FF4500",	 
         "Orchid", 	"#DA70D6",	 
         "PaleGoldenRod", 	"#EEE8AA",	 
         "PaleGreen", 	"#98FB98",	 
         "PaleTurquoise", 	"#AFEEEE",	 
         "PaleVioletRed", 	"#D87093",	 
         "PapayaWhip", 	"#FFEFD5",	 
         "PeachPuff", 	"#FFDAB9",	 
         "Peru", 	"#CD853F",	 
         "Pink", 	"#FFC0CB",	 
         "Plum", 	"#DDA0DD",	 
         "PowderBlue", 	"#B0E0E6",	 
         "Purple", 	"#800080",	 
         "Red", 	"#FF0000",	 
         "RosyBrown", 	"#BC8F8F",	 
         "RoyalBlue", 	"#4169E1",	 
         "SaddleBrown", 	"#8B4513",	 
         "Salmon", 	"#FA8072",	 
         "SandyBrown", 	"#F4A460",	 
         "SeaGreen", 	"#2E8B57",	 
         "SeaShell", 	"#FFF5EE",	 
         "Sienna", 	"#A0522D",	 
         "Silver", 	"#C0C0C0",	 
         "SkyBlue", 	"#87CEEB",	 
         "SlateBlue", 	"#6A5ACD",	 
         "SlateGray", 	"#708090",	 
         "SlateGrey", 	"#708090",	 
         "Snow", 	"#FFFAFA",	 
         "SpringGreen", 	"#00FF7F",	 
         "SteelBlue", 	"#4682B4",	 
         "Tan", 	"#D2B48C",	 
         "Teal", 	"#008080",	 
         "Thistle", 	"#D8BFD8",	 
         "Tomato", 	"#FF6347",	 
         "Turquoise", 	"#40E0D0",	 
         "Violet", 	"#EE82EE",	 
         "Wheat", 	"#F5DEB3",	 
         "White", 	"#FFFFFF",	 
         "WhiteSmoke", 	"#F5F5F5",	 
         "Yellow", 	"#FFFF00",	 
         "YellowGreen", 	"#9ACD32",
         "THE_END", "THE_END"
      };
   
      for (int i = 0; ; i += 2) {
         const int indxName  = i;
         const int indxValue = (indxName + 1);
         
         if (colorsInit[indxName] == "THE_END") {
            break;
         }
         
         const QString cs = colorsInit[indxValue];
         if (cs.size() >= 7) {
            bool ok = false;
            const unsigned char r = static_cast<unsigned char>(cs.mid(1, 2).toInt(&ok, 16));
            const unsigned char g = static_cast<unsigned char>(cs.mid(3, 2).toInt(&ok, 16));
            const unsigned char b = static_cast<unsigned char>(cs.mid(5, 2).toInt(&ok, 16));
            
            NameRGB nrgb(colorsInit[indxName], r, g, b);
            colors.push_back(nrgb);
         }
         else {
            std::cout << "HtmlColors: invalid color value: " << cs.toAscii().constData()
                      << std::endl;
         }
      }
      
      std::sort(colors.begin(), colors.end());
   }
}


/**
 * constructor.
 */
HtmlColors::NameRGB::NameRGB(const QString& nameIn,
                             const unsigned char redIn,
                             const unsigned char greenIn,
                             const unsigned char blueIn)
{
   name = nameIn;
   red  = redIn;
   green = greenIn;
   blue = blueIn;
}
                                         
/**
 * comparison operator.
 */
bool 
HtmlColors::NameRGB::operator<(const NameRGB& nrgb) const
{
   return (name < nrgb.name);
}
            
