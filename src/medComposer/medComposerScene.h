/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2014. All rights reserved.
 See LICENSE.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#pragma once

#include <dtkComposer/dtkComposerScene.h>

#include <medComposerStack.h>

class medComposerScenePrivate;

class medComposerScene : public dtkComposerScene
{
public:
    medComposerScene(QObject* parent = 0);

public:
    void setFactory(dtkComposerFactory *factory);
    void setStack(medComposerStack *stack);
    void setGraph(dtkComposerGraph *graph);

public:
    void dropEvent(QGraphicsSceneDragDropEvent *event);

private:
    medComposerScenePrivate *d;
};