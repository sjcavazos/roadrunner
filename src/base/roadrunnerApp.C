#include "roadrunnerApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
roadrunnerApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

roadrunnerApp::roadrunnerApp(InputParameters parameters) : MooseApp(parameters)
{
  roadrunnerApp::registerAll(_factory, _action_factory, _syntax);
}

roadrunnerApp::~roadrunnerApp() {}

void
roadrunnerApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"roadrunnerApp"});
  Registry::registerActionsTo(af, {"roadrunnerApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
roadrunnerApp::registerApps()
{
  registerApp(roadrunnerApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
roadrunnerApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  roadrunnerApp::registerAll(f, af, s);
}
extern "C" void
roadrunnerApp__registerApps()
{
  roadrunnerApp::registerApps();
}
