// -*- C++ -*-
/*!
 * @file  WhillTest.cpp
 * @brief Whill RT-component
 * @date $Date$
 *
 * @author Sugar Sweet Robotics Co., Ltd.
 *
 * MIT
 *
 * $Id$
 */

#include "WhillTest.h"

// Module specification
// <rtc-template block="module_spec">
static const char* whill_spec[] =
  {
    "implementation_id", "WhillTest",
    "type_name",         "WhillTest",
    "description",       "Whill RT-component",
    "version",           "1.0.0",
    "vendor",            "SugarSweetRobotics",
    "category",          "MobileRobot",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.port_name", "COM1",
    "conf.default.initial_pose_x", "0",
    "conf.default.initial_pose_y", "0.0",
    "conf.default.initial_pose_a", "0.0",

    // Widget
    "conf.__widget__.port_name", "text",
    "conf.__widget__.initial_pose_x", "text",
    "conf.__widget__.initial_pose_y", "text",
    "conf.__widget__.initial_pose_a", "text",
    // Constraints

    "conf.__type__.port_name", "string",
    "conf.__type__.initial_pose_x", "double",
    "conf.__type__.initial_pose_y", "double",
    "conf.__type__.initial_pose_a", "double",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
WhillTest::WhillTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_targetVelocityIn("targetVelocity", m_targetVelocity),
    m_currentPoseOut("currentPose", m_currentPose)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
WhillTest::~WhillTest()
{
}



RTC::ReturnCode_t WhillTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("currentPose", m_currentPoseIn);
  
  // Set OutPort buffer
  addOutPort("targetVelocity", m_targetVelocityOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("port_name", m_port_name, "COM1");
  bindParameter("initial_pose_x", m_initial_pose_x, "0");
  bindParameter("initial_pose_y", m_initial_pose_y, "0.0");
  bindParameter("initial_pose_a", m_initial_pose_a, "0.0");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t WhillTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t WhillTest::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t WhillTest::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t WhillTest::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t WhillTest::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t WhillTest::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t WhillTest::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t WhillTest::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t WhillTest::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t WhillTest::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t WhillTest::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void WhillTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(whill_spec);
    manager->registerFactory(profile,
                             RTC::Create<WhillTest>,
                             RTC::Delete<WhillTest>);
  }
  
};


