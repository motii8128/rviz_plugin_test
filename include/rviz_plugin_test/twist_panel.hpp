#ifndef RVIZ_PLUGIN_TEST_TWIST_PANEL
#define RVIZ_PLUGIN_TEST_TWIST_PANEL

#ifndef Q_MOC_RUN
#include <rclcpp/rclcpp.hpp>
#include <rviz_common/panel.hpp>
#include <QtWidgets>
#endif

#include <geometry_msgs/msg/twist.hpp>
#include <geometry_msgs/msg/twist_stamped.hpp>

namespace rviz_plugin_test
{
    class TouchWidget : public QWidget
    {
        Q_OBJECT
        public:
            TouchWidget(QWidget *parent = 0);

            bool grayout;
            float x_value;
            float y_value;
            int hcen;
            int vcen;
            int rsize;

            virtual void setEnabled(bool enable);
            virtual void paintEvent(QPaintEvent *event);
            virtual void mouseMoveEvent(QMouseEvent *event);
            virtual void mousePressEvent(QMouseEvent *event);
            virtual void mouseReleaseEvent(QMouseEvent *event);
            virtual void leaveEvent(QEvent *event);
            void set_value(float x, float y);
        
        public Q_SLOTS:
            void checkGrayout(int state);
        
        Q_SIGNALS:
            void modifyPosition(QString);
    };

    class TwistPanel : public rviz_common::Panel
    {
        Q_OBJECT
        public:
            TwistPanel(QWidget *parent = nullptr);

            virtual void onInitialize();
            virtual void load(const rviz_common::Config &config);
            virtual void save(rviz_common::Config config) const;
    };
}

#endif