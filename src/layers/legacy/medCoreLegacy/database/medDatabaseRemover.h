#pragma once
/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2020. All rights reserved.
 See LICENSE.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#include <QSqlQuery>
#include <QtCore/QObject>

#include <medCoreLegacyExport.h>
#include <medDataIndex.h>
#include <medJobItemL.h>

class medDatabaseRemoverPrivate;

/**
 * @class medDatabaseRemover
 * @brief Removes given data from the database.
 */
class MEDCORELEGACY_EXPORT medDatabaseRemover : public medJobItemL
{
    Q_OBJECT

public:
     medDatabaseRemover(const medDataIndex &index);
    ~medDatabaseRemover();

signals:

    /**
    * Signal emitted when the removing process finishes.
    * @param index – the @medDataIndex of the removed item
    **/
    void removed(const medDataIndex &index);

public slots:
    void onCancel(QObject*);

protected:
    virtual void internalRun();

    void removeSeries( int patientId, int studyId, int seriesId );

    bool isStudyEmpty( int studyId );
    void removeStudy( int patientId, int studyId );

    bool isPatientEmpty( int patientId );
    void removePatient( int patientId );

    void removeFile( const QString & filename );
    void removeThumbnailIfNeeded(QSqlQuery query);
    void removeDataFile(const QString & filename );
    bool removeTableRow( const QString &table, int id );

private:
    medDatabaseRemoverPrivate *d;
};
