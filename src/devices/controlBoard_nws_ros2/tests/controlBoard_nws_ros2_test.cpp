/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <yarp/os/Network.h>
#include <yarp/dev/PolyDriver.h>
#include <yarp/dev/WrapperSingle.h>

#include <catch2/catch_amalgamated.hpp>
#include <harness.h>

using namespace yarp::dev;
using namespace yarp::os;

TEST_CASE("dev::controlBoard_nws_ros2_test", "[yarp::dev]")
{
    YARP_REQUIRE_PLUGIN("controlBoard_nws_ros2", "device");

    Network::setLocalMode(true);

    SECTION("Checking controlBoard_nws_ros2 device")
    {
        PolyDriver ddnws;

        ////////"Checking opening nws"
        {
            Property pcfg;
            pcfg.put("device", "controlBoard_nws_ros2");
            pcfg.put("name", "/controlboard");
            REQUIRE(ddnws.open(pcfg));
        }

        //"Close all polydrivers and check"
        {
            CHECK(ddnws.close());
        }
    }

    Network::setLocalMode(false);
}