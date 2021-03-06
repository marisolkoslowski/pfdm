#include "SsptApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<SsptApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

SsptApp::SsptApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  SsptApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  SsptApp::associateSyntax(_syntax, _action_factory);
}

SsptApp::~SsptApp()
{
}

// External entry point for dynamic application loading
extern "C" void SsptApp__registerApps() { SsptApp::registerApps(); }
void
SsptApp::registerApps()
{
  registerApp(SsptApp);
}

// External entry point for dynamic object registration
extern "C" void SsptApp__registerObjects(Factory & factory) { SsptApp::registerObjects(factory); }
void
SsptApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void SsptApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { SsptApp::associateSyntax(syntax, action_factory); }
void
SsptApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
