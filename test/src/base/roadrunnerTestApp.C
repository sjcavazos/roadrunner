//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "roadrunnerTestApp.h"
#include "roadrunnerApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
roadrunnerTestApp::validParams()
{
  InputParameters params = roadrunnerApp::validParams();
  return params;
}

roadrunnerTestApp::roadrunnerTestApp(InputParameters parameters) : MooseApp(parameters)
{
  roadrunnerTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

roadrunnerTestApp::~roadrunnerTestApp() {}

void
roadrunnerTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  roadrunnerApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"roadrunnerTestApp"});
    Registry::registerActionsTo(af, {"roadrunnerTestApp"});
  }
}

void
roadrunnerTestApp::registerApps()
{
  registerApp(roadrunnerApp);
  registerApp(roadrunnerTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
roadrunnerTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  roadrunnerTestApp::registerAll(f, af, s);
}
extern "C" void
roadrunnerTestApp__registerApps()
{
  roadrunnerTestApp::registerApps();
}
