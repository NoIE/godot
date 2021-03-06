/*************************************************************************/
/*  tabs.h                                                               */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                    http://www.godotengine.org                         */
/*************************************************************************/
/* Copyright (c) 2007-2015 Juan Linietsky, Ariel Manzur.                 */
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
#ifndef TABS_H
#define TABS_H

#include "scene/gui/control.h"

class Tabs : public Control {

	OBJ_TYPE( Tabs, Control );
private:


	struct Tab {

		String text;
		Ref<Texture> icon;
		int ofs_cache;
	};

	Vector<Tab> tabs;
	int current;
	Control *_get_tab(int idx) const;
	int _get_top_margin() const;

protected:

	void _input_event(const InputEvent& p_event);
	void _notification(int p_what);
	static void _bind_methods();

public:

	void add_tab(const String& p_str="",const Ref<Texture>& p_icon=Ref<Texture>());

	void set_tab_title(int p_tab,const String& p_title);
	String get_tab_title(int p_tab) const;

	void set_tab_icon(int p_tab,const Ref<Texture>& p_icon);
	Ref<Texture> get_tab_icon(int p_tab) const;

	int get_tab_count() const;
	void set_current_tab(int p_current);
	int get_current_tab() const;

	void remove_tab(int p_idx);

	Size2 get_minimum_size() const;

	Tabs();
};


#endif // TABS_H
