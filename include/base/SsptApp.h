#ifndef SSPTAPP_H
#define SSPTAPP_H

#include "MooseApp.h"

class SsptApp;

template<>
InputParameters validParams<SsptApp>();

class SsptApp : public MooseApp
{
public:
  SsptApp(InputParameters parameters);
  virtual ~SsptApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* SSPTAPP_H */
