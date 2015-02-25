/*
 * Copyright 2012 Open Source Robotics Foundation
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

#include "ServerFixture.hh"
#include "physics/physics.hh"
#include "SimplePendulumIntegrator.hh"

using namespace gazebo;
class PhysicsTest : public ServerFixture
{
  public: void EmptyWorld(std::string _worldFile);
};

void PhysicsTest::EmptyWorld(std::string _worldFile)
{
  // Load an empty world
  Load(_worldFile, true);
  physics::WorldPtr world = physics::get_world("default");
  EXPECT_TRUE(world != NULL);

  // simulate a couple seconds
  world->StepWorld(2000);
  double t = world->GetSimTime().Double();
  // verify that time moves forward
  EXPECT_GT(t, 0);

  Unload();
}

TEST_F(PhysicsTest, EmptyWorldODE)
{
  //EmptyWorld("worlds/empty.world");
}

#ifdef HAVE_RTQL8
TEST_F(PhysicsTest, EmptyWorldRTQL8)
{
  //EmptyWorld("worlds/empty_rtql8.world");
}
#endif // HAVE_RTQL8

#ifdef HAVE_RTQL8
TEST_F(PhysicsTest, SimplePendulumRTQL8)
{
  EmptyWorld("worlds/simple_pendulum_rtql8.world");
}
#endif // HAVE_RTQL8

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
