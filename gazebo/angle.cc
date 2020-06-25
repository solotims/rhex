#include <gazebo/gazebo.hh>
#include <gazebo/physics/Joint.hh>
#include <gazebo/physics/JointController.hh>
#include <gazebo/physics/Model.hh>
#include <gazebo/physics/PhysicsTypes.hh>
#include <gazebo/common/Time.hh>
#include <gazebo/physics/physics.hh>
#include <math.h>

namespace gazebo
{

  class SetJointVelocityPlugin : public ModelPlugin
  {
    public: physics::JointControllerPtr jointController;

    public: virtual void Load(physics::ModelPtr _model, sdf::ElementPtr _sdf)
      {
        this->model = _model;
        this->updateConnection = event::Events::ConnectWorldUpdateBegin(
        std::bind(&SetJointVelocityPlugin::Update, this, std::placeholders::_1));
      }


    public: void Update(const common::UpdateInfo &_info)
      {


double a1 = this->model->GetJoint("link_0_JOINT_1")->Position(0);
a1 = fabs(a1 / 3.1416 * 180);
a1 = fmod(a1, 360);
double a2 = this->model->GetJoint("link_0_JOINT_2")->Position(0);
a2 = fabs(a2 / 3.1416 * 180);
a2 = fmod(a2, 360);
double b = 10 ;
double c = 2 ;
if ((a1 < 42.5)||(a1 > 317.5)) {
this->model->GetJoint("link_0_JOINT_1")->SetVelocity(0, -c);
this->model->GetJoint("link_0_JOINT_3")->SetVelocity(0, -c);
this->model->GetJoint("link_0_JOINT_5")->SetVelocity(0, -c);
}
else {
this->model->GetJoint("link_0_JOINT_1")->SetVelocity(0, -b);
this->model->GetJoint("link_0_JOINT_3")->SetVelocity(0, -b);
this->model->GetJoint("link_0_JOINT_5")->SetVelocity(0, -b);
}
if ((a2 > 137.5)&&(a2 < 222.5)) {
this->model->GetJoint("link_0_JOINT_1_0")->SetVelocity(0, -c);
this->model->GetJoint("link_0_JOINT_3_0")->SetVelocity(0, -c);
this->model->GetJoint("link_0_JOINT_2")->SetVelocity(0, -c);
}
else {
this->model->GetJoint("link_0_JOINT_1_0")->SetVelocity(0, -b);
this->model->GetJoint("link_0_JOINT_3_0")->SetVelocity(0, -b);
this->model->GetJoint("link_0_JOINT_2")->SetVelocity(0, -b);
}

//std::cout << a1 << std::endl;
     }


    public: physics::ModelPtr model;

    public: event::ConnectionPtr updateConnection;

		public: double a = 2;

  };

  GZ_REGISTER_MODEL_PLUGIN(SetJointVelocityPlugin)
}
