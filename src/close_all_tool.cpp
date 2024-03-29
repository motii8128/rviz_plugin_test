#include <rclcpp/rclcpp.hpp>
#include <rviz_common/tool.hpp>
#include <rviz_common/display_group.hpp>
#include <rviz_common/display_context.hpp>

#include "close_all_tool.hpp"

namespace rviz_plugin_test
{
    CloseAllTool::CloseAllTool():rviz_common::Tool()
    {

    }

    CloseAllTool::~CloseAllTool()
    {

    }

    void CloseAllTool::onInitialize()
    {

    }

    void CloseAllTool::closeProperty(rviz_common::properties::Property *property)
    {
        property->collapse();
        if(property->numChildren() > 0)
        {
            for(size_t i = 0; i < property->numChildren(); i++)
            {
                closeProperty(property->childAt(i));
            }
            context_->queueRender();
        }
    }

    void CloseAllTool::activate()
    {
        rviz_common::DisplayGroup *display_group = context_->getRootDisplayGroup();
        closeProperty(display_group);
    }

    void CloseAllTool::deactivate()
    {

    }
}

#include <pluginlib/class_list_macros.hpp>
PLUGINLIB_EXPORT_CLASS(rviz_plugin_test::CloseAllTool, rviz_common::Tool)