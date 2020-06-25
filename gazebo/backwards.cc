#include <gazebo/gazebo.hh>
#include <gazebo/physics/Joint.hh>
#include <gazebo/physics/JointController.hh>
#include <gazebo/physics/Model.hh>
#include <gazebo/physics/PhysicsTypes.hh>
#include <gazebo/common/Time.hh>
#include <gazebo/physics/physics.hh>
#include <math.h>
#include <gazebo/common/common.hh>

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

std::vector<std::string> jo  = {"link_0_JOINT_1", "link_0_JOINT_2", "link_0_JOINT_3", "link_0_JOINT_4", "link_0_JOINT_5", "link_0_JOINT_6"};

a1 = a1 + 0.001 * vel1 ;
double a1s = fabs(a1 / 3.1416 * 180);
a1s = fmod(a1s, 360);
a2 = a2 + 0.001 * vel2;

double a2s = fabs(a2 / 3.1416 * 180);
a2s = fmod(a2s, 360);

double act1 = this->model->GetJoint("link_0_JOINT_1")->Position(0);
double act2 = this->model->GetJoint("link_0_JOINT_2")->Position(0);

int kp = 1;
act1 = (a1 - act1)*kp;
act2 = (a2 - act2)*kp;


double true1 = vel1 + act1;
double true2 = vel2 + act2; 

for (int i = 0; i <= 2; i++){
this->model->GetJoint(jo[2*i])->SetVelocity(0, true1);
this->model->GetJoint(jo[2*i + 1])->SetVelocity(0, true2);
}

if ((a1s < 42.5)||(a1s > 317.5)) {
vel1 = 2; 
}
else
{
 vel1 = 10;
}
if ((a2s < 42.5)||(a2s > 317.5)) {
 vel2 = 2; 
}
else
{
 vel2 = 10;
}
//std::cout << true2 << std::endl;

     }

		public: double a1 = 0;
		public: double a2 = 3.14;
		public: double vel1 = 2;
		public: double vel2 = 10;


    public: physics::ModelPtr model;

    public: event::ConnectionPtr updateConnection;


  };

  GZ_REGISTER_MODEL_PLUGIN(SetJointVelocityPlugin)
}
