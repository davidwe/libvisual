/* Libvisual-plugins - Standard plugins for libvisual
 *
 * Copyright (C) 2004, 2005 Dennis Smit <ds@nerds-incorporated.org>
 *               2013 David <david@informatik.uni-bremen.de>
 *
 * Authors: Dennis Smit <ds@nerds-incorporated.org>
 *          David <david@informatik.uni-bremen.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

//TODO: Check this header

#include "actor_led.h"

static const unsigned int LED_COUNT = 4;

VISUAL_PLUGIN_API_VERSION_VALIDATOR

namespace {

  int         lv_led_init        (VisPluginData *plugin);
  void        lv_led_cleanup     (VisPluginData *plugin);
  void        lv_led_requisition (VisPluginData *plugin, int *width, int *height);
  void        lv_led_resize      (VisPluginData *plugin, int width, int height);
  int         lv_led_events      (VisPluginData *plugin, VisEventQueue *events);
  void        lv_led_render      (VisPluginData *plugin, VisVideo *video, VisAudio *audio);
  VisPalette *lv_led_palette     (VisPluginData *plugin);
}


/* Main plugin stuff */
const VisPluginInfo *get_plugin_info ()
{
	static VisActorPlugin actor;

	actor.requisition = lv_led_requisition;
	actor.palette     = lv_led_palette;
	actor.render      = lv_led_render;
	actor.vidoptions.depth = VISUAL_VIDEO_DEPTH_8BIT;

	static VisPluginInfo info;

	info.type     = VISUAL_PLUGIN_TYPE_ACTOR;
	info.plugname = "led";
	info.name     = "Libvisual LED plugin";
	info.author   = "David <david@informatik.uni-bremen.de>";
	info.version  = "0.1";
	info.about    = "Libvisual LED plugin";
	info.help     =  "This plugin controls LEDs"; //TODO: Add more description
	info.license  = VISUAL_PLUGIN_LICENSE_GPL,

	info.init     = lv_led_init;
	info.cleanup  = lv_led_cleanup;
	info.events   = lv_led_events;
	info.plugin   = &actor;

	return &info;
}

namespace {

int lv_led_init (VisPluginData *plugin)
{
    return true;
}

void lv_led_cleanup (VisPluginData *plugin)
{
}

void lv_led_requisition (VisPluginData *plugin, int *width, int *height)
{
	/*int reqw, reqh;

	reqw = *width;
	reqh = *height;

	if (reqw < 1)
		reqw = 1;

	if (reqh < 1)
		reqh = 1;

	*width = reqw;
	*height = reqh;*/
}

void lv_led_resize (VisPluginData *plugin, int width, int height)
{
}

int lv_led_events (VisPluginData *plugin, VisEventQueue *events)
{
	VisEvent ev;
	//VisParam *param;

	while (visual_event_queue_poll (events, &ev)) {
		switch (ev.type) {
			case VISUAL_EVENT_RESIZE:
				//lv_led_resize (plugin, ev.event.resize.width, ev.event.resize.height);
				break;

			case VISUAL_EVENT_PARAM:
				/*param = static_cast<VisParam *> (ev.event.param.param);

				if (visual_param_has_name (param, "transparent_bars")) {
					
				}*/

			default: /* to avoid warnings */
				break;
		}
	}

	return true;
}

VisPalette *lv_led_palette (VisPluginData *plugin)
{
	return nullptr;
}

void lv_led_draw(VisVideo *video, LV::Color (&colors)[LED_COUNT])
{
	const int width = video->get_width() / LED_COUNT;
	LV::Rect area(0, 0, width, video->get_height());

	for (unsigned int i = 0; i < LED_COUNT; i++)
	{
		video->fill_color ( colors[i], area );
		area.y += width;
	}
}


void lv_led_render (VisPluginData *plugin, VisVideo *video, VisAudio *audio)
{
	/*const unsigned int size = LED_COUNT;

	float freq[3][size];

	LV::BufferPtr fbuf = LV::Buffer::create ();
	fbuf->set (freq[0], size * sizeof(float));
	audio->get_spectrum (fbuf, size, VISUAL_AUDIO_CHANNEL_LEFT, false);

	fbuf->set (freq[1], size * sizeof(float));
	audio->get_spectrum (fbuf, size, VISUAL_AUDIO_CHANNEL_RIGHT, false);

	for (unsigned int i = 0; i < size; i++)
		freq[2][i] = (freq[0][i] + freq[1][i]) / 2;
*/
	LV::Color colors[LED_COUNT];
	for (unsigned int i = 0; i < LED_COUNT; i++)
	{
		colors[i] = LV::Color(30*i,0,0);
	}

	lv_led_draw(video, colors);
}

} // anonymous namespace
