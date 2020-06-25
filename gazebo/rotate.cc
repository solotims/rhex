#include <gazebo/gazebo.hh>
#include <gazebo/physics/Joint.hh>
#include <gazebo/physics/JointController.hh>
#include <gazebo/physics/Model.hh>
#include <gazebo/physics/PhysicsTypes.hh>

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

this->model->GetJoint("link_0_JOINT_1_0")->SetVelocity(0, -3.0);
this->model->GetJoint("link_0_JOINT_1")->SetVelocity(0, -3.0);
this->model->GetJoint("link_0_JOINT_2")->SetVelocity(0, -3.0);
this->model->GetJoint("link_0_JOINT_3_0")->SetVelocity(0, -3.0);
this->model->GetJoint("link_0_JOINT_3")->SetVelocity(0, -3.0);
this->model->GetJoint("link_0_JOINT_5")->SetVelocity(0, -3.0);
     }


    public: physics::ModelPtr model;

    public: event::ConnectionPtr updateConnection;


  };

  GZ_REGISTER_MODEL_PLUGIN(SetJointVelocityPlugin)
}
