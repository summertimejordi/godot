/*************************************************************************/
/*  input_event_editor_plugin.h                                          */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2022 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2022 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#ifndef INPUT_EVENT_EDITOR_PLUGIN_H
#define INPUT_EVENT_EDITOR_PLUGIN_H

#include "editor/action_map_editor.h"
#include "editor/editor_inspector.h"
#include "editor/editor_node.h"

class InputEventConfigContainer : public HBoxContainer {
	GDCLASS(InputEventConfigContainer, HBoxContainer);

	Label *input_event_text;
	Button *open_config_button;

	Ref<InputEvent> input_event;
	InputEventConfigurationDialog *config_dialog;

	void _config_dialog_confirmed();
	void _configure_pressed();

	void _event_changed();

protected:
	static void _bind_methods();

public:
	virtual Size2 get_minimum_size() const override;
	void set_event(const Ref<InputEvent> &p_event);

	InputEventConfigContainer();
};

class EditorInspectorPluginInputEvent : public EditorInspectorPlugin {
	GDCLASS(EditorInspectorPluginInputEvent, EditorInspectorPlugin);

public:
	virtual bool can_handle(Object *p_object) override;
	virtual void parse_begin(Object *p_object) override;
};

class InputEventEditorPlugin : public EditorPlugin {
	GDCLASS(InputEventEditorPlugin, EditorPlugin);

public:
	virtual String get_name() const override { return "InputEvent"; }

	InputEventEditorPlugin(EditorNode *p_node);
};

#endif // INPUT_EVENT_EDITOR_PLUGIN_H
