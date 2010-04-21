/* processor.cpp - Copyright (C) 2010 Red Hat, Inc.
 * Written by Darryl L. Pierce <dpierce@redhat.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA  02110-1301, USA.  A copy of the GNU General Public License is
 * also available at http://www.gnu.org/copyleft/gpl.html.
 */

#include "processors.h"
#include "platform.h"

using namespace std;
namespace _qmf = qmf::com::redhat::matahari;

void
ProcessorsAgent::setup(ManagementAgent* agent, Manageable* parent)
{
  // setup the management object
  management_object = new _qmf::Processors(agent, this, parent);
  agent->addObject(management_object);

  Platform* platform = Platform::instance();

  management_object->set_model(platform->get_processor_model());
  management_object->set_cores(platform->get_number_of_cores());
}

void
ProcessorsAgent::update(void) const
{
  update_load_averages();
}

void
ProcessorsAgent::update_load_averages(void) const
{
  management_object->set_load_average(Platform::instance()->get_load_average());
}
