/*
 * Copyright 2016 Open Source Robotics Foundation
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

#ifndef PRIUSCUP_PLUGINS_PRIUSHYBRIDPLUGIN_HH_
#define PRIUSCUP_PLUGINS_PRIUSHYBRIDPLUGIN_HH_

#include <string>
#include <thread>

#include <ignition/math/Vector3.hh>

#include <gazebo/physics/physics.hh>
#include <gazebo/transport/transport.hh>
#include <gazebo/msgs/msgs.hh>
#include <gazebo/common/Plugin.hh>

namespace gazebo
{
  // Forward declaration
  class PriusHybridPluginPrivate;

  class PriusHybridPlugin : public ModelPlugin
  {
    /// \brief Constructor.
    public: PriusHybridPlugin();

    /// \brief Destructor.
    public: virtual ~PriusHybridPlugin();

    /// \brief Load the controller.
    public: void Load(physics::ModelPtr _parent, sdf::ElementPtr _sdf);

    /// \brief Callback each time a key message is received.
    /// \param[in] _msg Keypress message.
    private: void OnKeyPress(ConstAnyPtr &_msg);

    private: void Update();

    private: void UpdateHandWheelRatio();

    private: double CollisionRadius(physics::CollisionPtr _collision);

    private: ignition::math::Vector3d CollisionPosition(physics::LinkPtr _link,
        const unsigned int _id);

    private: double GasTorqueMultiplier();

    /// \brief Private data
    private: std::unique_ptr<PriusHybridPluginPrivate> dataPtr;
  };
}
#endif
