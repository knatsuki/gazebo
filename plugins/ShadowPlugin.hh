/*
 * Copyright (C) 2017 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
#ifndef GAZEBO_PLUGINS_SHADOW_PLUGIN_HH_
#define GAZEBO_PLUGINS_SHADOW_PLUGIN_HH_

#include <string>

#include "gazebo/common/Plugin.hh"
#include "gazebo/util/system.hh"

namespace gazebo
{
  /// \brief A plugin to demonstrate setting scene shadow properties
  class GAZEBO_VISIBLE ShadowPlugin : public SensorPlugin
  {
    public: ShadowPlugin();

    /// \brief Destructor
    public: virtual ~ShadowPlugin();

    // Documentation Inherited
    public: virtual void Load(sensors::SensorPtr _sensor, sdf::ElementPtr _sdf);
  };
}
#endif
