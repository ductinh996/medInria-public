// /////////////////////////////////////////////////////////////////
// Generated by dtkPluginGenerator
// /////////////////////////////////////////////////////////////////
#include "itkDataTensorImagePlugin.h"


#include <itkDataTensorImageDouble3.h>
#include <itkDataTensorImageFloat3.h>

#include <dtkCore/dtkLog.h>

#include <dtkItkLogForwarder/itkLogForwarder.h>


// /////////////////////////////////////////////////////////////////
// itkDataTensorImagePluginPrivate
// /////////////////////////////////////////////////////////////////

class itkDataTensorImagePluginPrivate
{
public:
  itkDataTensorImagePluginPrivate()
  {
      forwarder = itk::LogForwarder::New();
  }
  ~itkDataTensorImagePluginPrivate()
  {

  }
  // Class variables go here.
  itk::LogForwarder::Pointer forwarder;
};

// /////////////////////////////////////////////////////////////////
// itkDataTensorImagePlugin
// /////////////////////////////////////////////////////////////////

itkDataTensorImagePlugin::itkDataTensorImagePlugin(QObject *parent) : dtkPlugin(parent), d(new itkDataTensorImagePluginPrivate)
{

}

itkDataTensorImagePlugin::~itkDataTensorImagePlugin(void)
{
    delete d;

    d = NULL;
}

bool itkDataTensorImagePlugin::initialize(void)
{
    if(!itkDataTensorImageDouble3::registered()) dtkWarning() << "Unable to register itkDataTensorImageDouble3 type";
    if(!itkDataTensorImageFloat3::registered()) dtkWarning() << "Unable to register itkDataTensorImageFloat3 type";

    return true;
}

bool itkDataTensorImagePlugin::uninitialize(void)
{
    return true;
}

QString itkDataTensorImagePlugin::name(void) const
{
    return "itkDataTensorImagePlugin";
}

QString itkDataTensorImagePlugin::description(void) const
{
    return "Handle ITK tensor image types";
}

QStringList itkDataTensorImagePlugin::tags(void) const
{
    return QStringList() << "itk" << "data" << "tensor" << "image";
}

QStringList itkDataTensorImagePlugin::types(void) const
{
    return QStringList() << "itkDataTensorImageFloat3"
			 << "itkDataTensorImageDouble3";
}

Q_EXPORT_PLUGIN2(itkDataTensorImagePlugin, itkDataTensorImagePlugin)
