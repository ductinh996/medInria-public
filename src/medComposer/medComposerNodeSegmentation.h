/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2014. All rights reserved.
 See LICENSE.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/


#pragma once

#include <dtkComposer/dtkComposerNodeLeafProcess.h>

class medComposerNodeSegmentationPrivate;
class medComposer;

// /////////////////////////////////////////////////////////////////
// numComposerNodeMeshBuilder interface
// /////////////////////////////////////////////////////////////////

class medComposerNodeSegmentation : public dtkComposerNodeLeafProcess
{
public:
     medComposerNodeSegmentation(void);
    ~medComposerNodeSegmentation(void);

public:
    QString type(void);
    QString titleHint(void);

public:
    QString  inputLabelHint(int port);
    QString outputLabelHint(int port);

public:
    bool isAbstractProcess(void) const;

    QString abstractProcessType(void) const;

public:
    void setProcess(dtkAbstractProcess *process);

    dtkAbstractProcess *process(void) const;

public:
    bool isInteractive() const;

public:
    void run(void);

private:
    medComposerNodeSegmentationPrivate *d;
};

