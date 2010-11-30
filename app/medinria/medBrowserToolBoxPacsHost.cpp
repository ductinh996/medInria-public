/* medBrowserToolBoxPacsHost.cpp ---
 * 
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Tue Oct  5 15:49:05 2010 (+0200)
 * Version: $Id$
 * Last-Updated: Wed Oct  6 11:37:23 2010 (+0200)
 *           By: Julien Wintz
 *     Update #: 55
 */

/* Commentary: 
 * 
 */

/* Change log:
 * 
 */

#include "medBrowserToolBoxPacsHost.h"

#include <QtGui>

class medBrowserToolBoxPacsHostPrivate
{
public:
    QLineEdit *title;
    QLineEdit *port;
    QPushButton *apply;
};

medBrowserToolBoxPacsHost::medBrowserToolBoxPacsHost(QWidget *parent) : medToolBox(parent), d(new medBrowserToolBoxPacsHostPrivate)
{
    QWidget *page = new QWidget(this);

    QValidator* validator = new QIntValidator( 0, 65535, this );
    d->title = new QLineEdit(page);
    d->port = new QLineEdit(page);
    d->port->setValidator(validator);
    d->apply = new QPushButton("Apply", page);

    QFormLayout *layout = new QFormLayout(page);
    layout->addRow("Title", d->title);
    layout->addRow("Port", d->port);
    layout->addRow(d->apply);

    this->setTitle("DICOM Server");
    this->setWidget(page);

    connect(d->apply, SIGNAL(clicked()), this, SLOT(onSettingsApplied()));

    this->readSettings();
}

medBrowserToolBoxPacsHost::~medBrowserToolBoxPacsHost(void)
{
    this->writeSettings();

    delete d;

    d = NULL;
}

void medBrowserToolBoxPacsHost::readSettings(void)
{
    QSettings settings("inria", "medinria");
    settings.beginGroup("medBrowserToolBoxPacsHost");
    d->title->setText(settings.value("title").toString());
    d->port->setText(settings.value("port").toString());
    settings.endGroup();
}

void medBrowserToolBoxPacsHost::writeSettings(void)
{
    QSettings settings("inria", "medinria");
    settings.beginGroup("medBrowserToolBoxPacsHost");
    settings.setValue("title", d->title->text());
    settings.setValue("port", d->port->text());
    settings.endGroup();
}

QString medBrowserToolBoxPacsHost::title(void)
{
    return d->title->text();
}

QString medBrowserToolBoxPacsHost::port(void)
{
    return d->port->text();
}

void medBrowserToolBoxPacsHost::onSettingsApplied(void)
{
    this->writeSettings();
}