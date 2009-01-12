
#ifndef __SURFACE_FILE_H__
#define __SURFACE_FILE_H__

#include "GiftiDataArrayFile.h"

/// class for storing a surface of coordinates, normals, and triangles
class SurfaceFile : public GiftiDataArrayFile {
   public:
      // constructor
      SurfaceFile();
      
      // constructor
      SurfaceFile(const int numberOfCoordinates,
                  const int numberOfTriangles);
      
      // copy constructor
      SurfaceFile(const SurfaceFile& sf);
      
      // destructor
      virtual ~SurfaceFile();
      
      // assignment operator
      SurfaceFile& operator=(const SurfaceFile& sf);
      
      // clear the file
      void clear();
      
      // get the number of coordinates
      int getNumberOfCoordinates() const;
      
      // set the number of coordinates
      void setNumberOfCoordinates(const int num);
      
      // get the number of triangles
      int getNumberOfTriangles() const;
      
      // set the number of triangles
      void setNumberOfTriangles(const int num);
      
      // get a coordinate (pointer to coordinates x/y/z)
      const float* getCoordinate(const int indx) const;
      
      // set a coordinate
      void setCoordinate(const int indx, const float xyz[3]);
      
      // set a coordinate
      void setCoordinate(const int indx, const float x, const float y, const float z);
      
      // get a triangles coordinate indices (3)
      const int32_t* getTriangle(const int indx) const;
      
      // set a triangle
      void setTriangle(const int indx, const int vertices[3]);
      
      // set a triangle
      void setTriangle(const int indx, const int v1, const int v2, const int v3);
      
      /// get the type of coordinates
      QString getCoordinateType() const;
      
      // set the type of coordinates
      void setCoordinateType(const QString& t);
      
      /// get the type of topology
      QString getTopologyType() const;
      
      // set the type of topology
      void setTopologyType(const QString& t);
      
      // get the coordinate metadata (NULL If invalid) const method
      const GiftiMetaData* getCoordinateMetaData() const;
      
      // get the topology metadata (NULL If invalid) const method
      const GiftiMetaData* getTopologyMetaData() const;
      
      // get the coordinate metadata (NULL If invalid)
      GiftiMetaData* getCoordinateMetaData();
      
      // get the topology metadata (NULL If invalid)
      GiftiMetaData* getTopologyMetaData();
      
      // convert configuration ID to spec file tag
      static QString convertConfigurationIDToSpecFileTag(const QString& configID);

   protected:
      // the copy helper used by copy constructor and assignement operator
      void copyHelperSurface(const SurfaceFile& sf);
      
      // read  file
      void readLegacyFileData(QFile& file, QTextStream& stream, QDataStream& binStream)
                                                                 throw (FileException);
      
      // write  file
      void writeLegacyFileData(QTextStream& stream, QDataStream& binStream)
                                                       throw (FileException);
      
      //
      // IF ANY MORE MEMBERS ADDED UPDATE CopyHelperSurface
      //
};

#endif // __SURFACE_FILE_H__

