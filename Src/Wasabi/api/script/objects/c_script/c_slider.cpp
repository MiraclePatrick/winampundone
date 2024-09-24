/* This file was generated by Maki Compiler, do not edit manually */

#include <precomp.h>

#include "c_slider.h"
#include <api/script/objcontroller.h>

C_Slider::C_Slider(ScriptObject *object) : C_GuiObject(object) {
  inited = 0;
  obj = NULL;
  C_hook(object);
}

C_Slider::C_Slider() {
  inited = 0;
  obj = NULL;
}

void C_Slider::C_hook(ScriptObject *object) {
  ASSERT(!inited);
  ScriptObjectController *controller = object->vcpu_getController();
  obj = controller->cast(object, sliderGuid);
  if (obj != object && obj != NULL)
    controller = obj->vcpu_getController();
  else
    obj = NULL;

  int iter = WASABI_API_APP->app_getInitCount();
  if (!loaded || loaded != iter) {
    loaded = iter;
    onsetposition_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"onSetPosition", this);
    onpostedposition_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"onPostedPosition", this);
    onsetfinalposition_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"onSetFinalPosition", this);
    setposition_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"setPosition", this);
    getposition_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"getPosition", this);
    lock_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"lock", this);
    unlock_id = WASABI_API_MAKI->maki_addDlfRef(controller, L"unlock", this);
  }
  inited = 1;
}

C_Slider::~C_Slider() {
}

ScriptObject *C_Slider::getScriptObject() {
  if (obj != NULL) return obj;
  return C_SLIDER_PARENT::getScriptObject();
}

void C_Slider::onSetPosition(int newpos) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(newpos);
  scriptVar *params[1] = {&a};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), onsetposition_id, params);
}

void C_Slider::onPostedPosition(int newpos) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(newpos);
  scriptVar *params[1] = {&a};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), onpostedposition_id, params);
}

void C_Slider::onSetFinalPosition(int pos) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(pos);
  scriptVar *params[1] = {&a};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), onsetfinalposition_id, params);
}

void C_Slider::setPosition(int pos) {
  ASSERT(inited);
  scriptVar a = MAKE_SCRIPT_INT(pos);
  scriptVar *params[1] = {&a};
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), setposition_id, params);
}

int C_Slider::getPosition() {
  ASSERT(inited);
  return GET_SCRIPT_INT(WASABI_API_MAKI->maki_callFunction(getScriptObject(), getposition_id, NULL));
}

void C_Slider::lock() {
  ASSERT(inited);
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), lock_id, NULL);
}

void C_Slider::unlock() {
  ASSERT(inited);
  WASABI_API_MAKI->maki_callFunction(getScriptObject(), unlock_id, NULL);
}

int C_Slider::loaded=0;
int C_Slider::onsetposition_id=0;
int C_Slider::onpostedposition_id=0;
int C_Slider::onsetfinalposition_id=0;
int C_Slider::setposition_id=0;
int C_Slider::getposition_id=0;
int C_Slider::lock_id=0;
int C_Slider::unlock_id=0;