/*
 * SPDX-FileCopyrightText: 2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <yarp/os/Network.h>
#include <yarp/dev/PolyDriver.h>
#include <yarp/dev/WrapperSingle.h>

#include <catch2/catch_amalgamated.hpp>
#include <harness.h>

using namespace yarp::dev;
using namespace yarp::os;

TEST_CASE("dev::frameTransformGet_nwc_ros2_test", "[yarp::dev]")
{
    YARP_REQUIRE_PLUGIN("frameTransformGet_nwc_ros2", "device");

    Network::setLocalMode(true);

    SECTION("Checking the nwc alone")
    {
        PolyDriver ddnwc;

        ////////"Checking opening nws"
        {
            Property pcfg;
            pcfg.put("device", "frameTransformGet_nwc_ros2");
            pcfg.put("node_name", "controlboard_node");
            pcfg.put("topic_name","/controlBoard_nws_ros2/robot_part");
            REQUIRE(ddnwc.open(pcfg));
        }

        //"Close all polydrivers and check"
        {
            CHECK(ddnwc.close());
        }
    }

    Network::setLocalMode(false);
}
