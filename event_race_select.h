/* 
 * PPRacer 
 * Copyright (C) 2004-2005 Volker Stroebel <volker@planetpenguin.de>
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#ifndef _EVENT_RACE_SELECT_H_
#define _EVENT_RACE_SELECT_H_

#include "loop.h"

#include "course_mgr.h"

#include "ppgltk/ssbutton.h"
#include "ppgltk/listbox.h"
#include "ppgltk/textarea.h"
#include "ppgltk/label.h"

#include "player.h"


class EventRaceSelect : public GameMode
{
	pp::Label *mp_titleLbl;
	pp::Textarea *mp_descTa;
	pp::Listbox<CourseData> *mp_raceListbox;
	pp::Button *mp_backBtn;
	pp::Button *mp_startBtn;
	pp::SSButton *mp_conditionsSSBtn;
	pp::SSButton *mp_snowSSBtn;
	pp::SSButton *mp_windSSBtn;
	pp::SSButton *mp_mirrorSSBtn;
	
	PlayerCourseData m_data;

	enum {
		DEAD,
		RACEWON,
		PLAYABLE,
		UNPLAYABLE		
	} state;
	
	void updateStates();
	
	void setWidgetPositionsAndDrawDecorations();	
	void drawStatusMsg( int x_org, int y_org, int box_width, int box_height );

public:
	EventRaceSelect();
	~EventRaceSelect();

	void loop(float timeStep);

	void start();
	void back();
	void listboxItemChange();

	bool keyPressEvent(SDLKey key);

};

#endif // _EVENT_RACE_SELECT_H_
