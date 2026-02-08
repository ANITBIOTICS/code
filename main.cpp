#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep

using namespace pros;
// controller
Controller controller(E_CONTROLLER_MASTER);

// motor groups
MotorGroup leftMotors({13, -14, -15}, //replace this with the motors on the left side of your drive train
                           MotorGearset::blue);  //this is the color of the motor cartridge
MotorGroup rightMotors({-16, 17, 19}, MotorGearset::blue); 
// replace this with the motors on the right side of your drive train. Be sure to test ur drive train to see which ones need to be reversed (just put a negative sign in front of all of the motor ports)
Motor intake1(10);//The format for any other motors is "Motor [motor name] (port)"
Motor intake2(7);

adi::Pneumatics scraper('H', false);

// Imu imu(19); // your imu is your inertial sensor. it is useful in autos becuase it allows you to detect where ur robot is facing, how much it has turned etc. this way you do not have to solely rely on the inbuilt things in the motor
// you can ignore the imu and the whole PID section until you get your robot wired, tested and tuned for ur comp on saturday. I doubt you will have auto prepped

//the things below are odometry (which basically just help you keep track of your robot in auto). ignore it for now, since you do not have an odom wheel installed on the bottom of ur robot. 
// // tracking wheels
// Rotation verticalEnc(-6);

//when and if you actually have an odom wheel, you will need to know it's size, how far it is offset from the center of ur robot, etc. (as you can see below)
// //horizontal tracking wheel. 2.75" diameter, 5.75" offset, back of the robot (negative)
// //vertical tracking wheel. 2.75" diameter, 2.5" offset, left of the robot (negative)
//lemlib::TrackingWheel vertical(&verticalEnc, lemlib::Omniwheel::NEW_275, 0);




// drivetrain settings
//Instructions on how to fill this out are here. You will need to fill it out based on ur robot's size etc when you get to coding autos. 
lemlib::Drivetrain drivetrain(&leftMotors, // left motor group
                             &rightMotors, // right motor group
                             12.5, // 10 inch track width. FILL THIS IN WITH THE WIDTH OF YOUR ROBOT
                             lemlib::Omniwheel::NEW_325, // Fill this in with what type and size of wheels you are using. specific api things are on the website 
                             360, // drivetrain rpm is 360. this is based on your motor cartridge and gear ratio. Calculate this yourself
                             2 // horizontal drift is 2. If you had traction wheels, it would have been 8 (apparenlty)
);

// // everything below here is for tuning ur autos so that they go exactly where u want it to go in a preferred way (you can google PID on ur own)
// // there are instructions on how to tune your pid on the wbsite and I can help you with it as well
// // but you don't have time for this now. you should focus on making sure you can score. 
// // lateral motion controller

lemlib::ControllerSettings linearController(9, // proportional gain (kP)
                                           0, // integral gain (kI)
                                           15, // derivative gain (kD)
                                           3, // anti windup
                                           1, // small error range, in inches
                                           100, // small error range timeout, in milliseconds
                                           3, // large error range, in inches
                                           500, // large error range timeout, in milliseconds
                                           20 // maximum acceleration (slew)
);


// angular motion controller
lemlib::ControllerSettings angular_controller(2, // proportional gain (kP)
                                             0, // integral gain (kI)
                                             6, // derivative gain (kD)
                                             3, // anti windup
                                             1, // small error range, in inches
                                             100, // small error range timeout, in milliseconds
                                             3, // large error range, in inches
                                             500, // large error range timeout, in milliseconds
                                             0 // maximum acceleration (slew)
);


lemlib::ControllerSettings lateral_controller(10, // proportional gain (kP)
                                             0, // integral gain (kI)
                                             3, // derivative gain (kD)
                                             3, // anti windup
                                             1, // small error range, in inches
                                             100, // small error range timeout, in milliseconds
                                             3, // large error range, in inches
                                             500, // large error range timeout, in milliseconds
                                             20 // maximum acceleration (slew)
);


// // sensors for odometry
lemlib::OdomSensors sensors(nullptr, // vertical tracking wheel
                           nullptr, // vertical tracking wheel 2, set to nullptr as we don't have a second one
                           nullptr, // horizontal tracking wheel
                           nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                           nullptr // inertial sensor
);


//i have no clue what this is. just let it be :'D
// input curve for throttle input during driver control
lemlib::ExpoDriveCurve throttleCurve(3, // joystick deadband out of 127
                                    10, // minimum output where drivetrain will move out of 127
                                    1.019 // expo curve gain
);


// input curve for steer input during driver control
lemlib::ExpoDriveCurve steerCurve(3, // joystick deadband out of 127
                                 10, // minimum output where drivetrain will move out of 127
                                 1.019 // expo curve gain
);


// create the chassis
lemlib::Chassis chassis(drivetrain, linearController, angular_controller, sensors, &throttleCurve, &steerCurve);


/**
* Runs initialization code. This occurs as soon as the program is started.
*
* All other competition modes are blocked by initialize; it is recommended
* to keep execution time for this mode under a few seconds.
*/


// below is my old (very old) color sort. You do not need this but you can use this for reference if you ever need it in the future. (still its kinda bad lmao)
/*
bool side=false; //blue be true, red be false or smth
void colorthingidk(){
    int color;
while(true){
    color = optical.get_hue();
    if (color <= 15){ //red
        if (side == true){
            delay(400);
            intake.move(0);
            delay(100);
            intake.move(127);
        }

    }
    // color > 15 && color <200 

    
    else if (color >= 200){ // blue
        if (side == false){
            delay(400);
            intake.move(0);
            delay(100);
            intake.move(127);
        }

    }   

}

}
*/

void initialize() {
   lcd::initialize(); // initialize brain screen
   chassis.calibrate(); // calibrate sensors
   // print position to brain screen
   Task screen_task([&]() {
       while (true) {
           // print robot location to the brain screen
           lcd::print(0, "X: %f", chassis.getPose().x); // x
           lcd::print(1, "Y: %f", chassis.getPose().y); // y
           lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
           // delay to save resources
           delay(20);
       }
   });
}


/**
* Runs while the robot is disabled
*/
void disabled() {}


/**
* runs after initialize if the robot is connected to field control
*/
void competition_initialize() {
}


// get a path used for pure pursuit
// this needs to be put outside a function
ASSET(example_txt); // '.' replaced with "_" to make c++ happy


/**
* Runs during auto
*
* This is an example autonomous routine which demonstrates a lot of the features LemLib has to offer
*/



//this was our auto for High stakes I believe. It's pretty funny but you can look at it if you need some *cough* inspiration for ur autos. 
// one thing is that you can use jerry.io to plan out ur auto route. if you are in inches, jerry io basically gives you coordinates you can paste in 
// and use with the moveToPose and stuff Lemlib provides you with. (super helpful). 
// you will need to tune your code though. beucase 1. jerry io isnt perfect and 2. the robot isn't perfect
void autonomous() {

    /*
    // side=true; // this was code to control which side (red/blue) we were on
    // // Move to x: 20 and y: 15, and face heading 90. Timeout set to 4000 ms
    // chassis.moveToPose(20, 15, 90, 4000);
    // // Move to x: 0 and y: 0 and face heading 270, going backwards. Timeout set to 4000ms
    // chassis.moveToPose    1(0, 0, 270, 4000, {.forwards = false});
    // // cancel the movement after it has traveled 10 inches
    // chassis.waitUntil(10);
    // chassis.cancelMotion();
    // // Turn to face the point x:45, y:-45. Timeout set to 1000
    // // dont turn faster than 60 (out of a maximum of 127)
    // chassis.turnToPoint(45, -45, 1000, {.maxSpeed = 60});
    // // Turn to face a direction of 90º. Timeout set to 1000
    // // will always be faster than 100 (out of a maximum of 127)
    // // also force it to turn clockwise, the long way around
    // chassis.turnToHeading(90, 1000, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 100});
    // // Follow the path in path.txt. Lookahead at 15, Timeout set to 4000
    // // following the path with the back of the robot (forwards = false)
    // // see line 116 to see how to define a path
    // chassis.follow(example_txt, 15, 4000, false);
    // // wait until the chassis has traveled 10 inches. Otherwise the code directly after
    // // the movement will run immediately
    // // Unless its another movement, in which case it will wait
    // chassis.waitUntil(10);
    // lcd::print(4, "Traveled 10 inches during pure pursuit!");
    // // wait until the movement is done
    // chassis.waitUntilDone();
    // lcd::print(4, "pure pursuit finished!");


    // //TUNING PID
    // // set position to x:0, y:0, heading:0
    // chassis.setPose(0, 0, 0);
    // // turn to face heading 90 with a very long timeout
    // chassis.turnToHeading(90, 100000);


    // //TUNING LINEAR MOTION
    // chassis.setPose(0,0,0);
    // chassis.moveToPoint(0, 48, 10000);


    //LEFT SIDE AWP
    // intake.move(50);
    // delay(500);
    // intake.move(0);
    // chassis.setPose(-57.163, 44.404, 300);
    // chassis.moveToPose(-22.685, 22.685, 300, 1000, {.forwards = false});
    // chassis.waitUntilDone();
    // delay(300);
    // clamp.set_value(1);
    // delay(500);
    // chassis.turnToPoint(-23.228, 47.118, 1000, {.maxSpeed = 60});
    // chassis.moveToPose(-23.228, 47.118, 0, 2000, {.forwards = true});
    // intake.move(127);
    // hook.move(127);
    // delay(2500);
    // clamp.set_value(0);
    // chassis.turnToPoint(-13.455, -0.934, 1500, {.maxSpeed = 60});
    // chassis.moveToPose(-13.455, -0.934, 168, 1000, {.forwards = true});
    // intake.move(0);
    // hook.move(0);
    


    //SOLO AWP (START FROM RIGHT SIDE)
    // intake.move(50);
    // delay(500);
    // intake.move(0);
    // chassis.setPose(-54.204, -37.508, 237);
    // chassis.moveToPose(-20.785, -21.567, 237, 1000, {.forwards = false, .lead = 0, .maxSpeed = 60});
    // chassis.waitUntilDone();
    // delay(300);
    // clamp.set_value(1);
    // delay(500);
    // chassis.turnToPoint(-23.5, -48.715, 500, {.maxSpeed = 60});
    // chassis.moveToPose(-23.5, -48.715, 320, 1000, {.forwards = true});
    // intake.move(127);
    // hook.move(127);
    // delay(1000);
    // chassis.turnToPoint(-56.163, 8, 500, {.maxSpeed = 70});
    // chassis.moveToPose(-56.163, 8, 50, 1000, {.forwards = true, .minSpeed = 70});
    */

}


/**
* Runs in driver control
*/

//ARCADE
pros::Controller controller(pros::E_CONTROLLER_MASTER);

void opcontrol() {
    // loop forever
    while (true) {
        // get left y and right x positions
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int leftX = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);

        // move the robot
        chassis.arcade(leftY, leftX);

        // delay to save resources
        pros::delay(25);

//the code below is to map buttons to motors. ex: pressing R1 right now would intake and run the hooks. 
//You can modify this to your own motors and their names afer you set ur ports at the top of this file
       if(controller.get_digital(DIGITAL_R2)){ //outtake
           intake1.move(127);
           intake2.move(127);
       }else if(controller.get_digital(DIGITAL_R1)){ //scoring
        //when r2 is pressed, outtake (or something). i dont remember what exactly this did
           intake1.move(-127);
           intake2.move(-127); //a negative speed just means it is going in the opposite direction
       }else if(controller.get_digital(DIGITAL_L1)){ //intake
            intake2.move(-127);
            intake1.move(0);
        }else{ //if nothing is pressed, intake does not move
           intake1.move(0);
           intake2.move(0);
       }

       
//this is how you do pneumatics. (you use the bool armState and clampState to make it so that ur pneumatics are toggle-able or somethign)
       if (controller.get_digital_new_press(DIGITAL_DOWN)) {
            scraperState = !scraperState; //this means that whenever you press L1, you change clampstate to it's opposite. so if it were true, now it is false, and vice versa
            scraper.set_value(scraperState); //basically, you can control pneumaics by setting their value to true or false (basically extended, retracted)
        }


   }

}