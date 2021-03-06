#pragma once
/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2020. All rights reserved.
 See LICENSE.txt for details.
 
  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#include <QtCore/QObject>
#include <QString>

#include <medPacsExport.h>

class MEDPACS_EXPORT medAbstractPacsKey : public QObject
{
    Q_OBJECT

public:
   medAbstractPacsKey() = default;
   ~medAbstractPacsKey() override = default;
    
   int group;
   int elem;
   QString value;
};
