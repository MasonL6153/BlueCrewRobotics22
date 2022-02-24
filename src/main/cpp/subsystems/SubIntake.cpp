/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubIntake.h"

SubIntake::SubIntake() = default;

// This method will be called once per scheduler run
void SubIntake::Periodic() {}

void SubIntake::ConfigureIntake(){
    // Write code here to configure the the motors of the Intake
    // Intake positioner configuration
    positionIntake->Config_kF(0,0.0,0);
    positionIntake->Config_kP(0,0.0937,0); // (75%)*1023/8192
    positionIntake->Config_kI(0,0,0);
    positionIntake->Config_kD(0,0,0);

    positionIntake->ConfigForwardSoftLimitThreshold(6500,0);
    positionIntake->ConfigReverseSoftLimitThreshold(0,0);
    positionIntake->ConfigForwardSoftLimitEnable(true,0);
    positionIntake->ConfigReverseSoftLimitEnable(true,0);

    positionIntake->ConfigNominalOutputForward(0,0);
    positionIntake->ConfigNominalOutputReverse(0,0);
    positionIntake->ConfigPeakOutputForward(1,0);
    positionIntake->ConfigPeakOutputReverse(1,0);

    positionIntake->ConfigPeakCurrentDuration(1,0);
    positionIntake->ConfigPeakCurrentLimit(10,0);
    positionIntake->ConfigContinuousCurrentLimit(5,0);
    positionIntake->EnableCurrentLimit(true);

    positionIntake->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder,0,0);
    positionIntake->SetSensorPhase(true);
    positionIntake->SetInverted(false);

    // Shooter feeder configuration
    shooterFeeder->Config_kF(0,0.0,0);
    shooterFeeder->Config_kP(0,0.12,0); // (96%)*1023/8192
    shooterFeeder->Config_kI(0,0,0);
    shooterFeeder->Config_kD(0,0,0);

    shooterFeeder->ConfigForwardSoftLimitThreshold(6500,0);
    shooterFeeder->ConfigReverseSoftLimitThreshold(0,0);
    shooterFeeder->ConfigForwardSoftLimitEnable(true,0);
    shooterFeeder->ConfigReverseSoftLimitEnable(true,0);

    shooterFeeder->ConfigNominalOutputForward(0,0);
    shooterFeeder->ConfigNominalOutputReverse(0,0);
    shooterFeeder->ConfigPeakOutputForward(1,0);
    shooterFeeder->ConfigPeakOutputReverse(1,0);

    shooterFeeder->ConfigPeakCurrentDuration(1,0);
    shooterFeeder->ConfigPeakCurrentLimit(10,0);
    shooterFeeder->ConfigContinuousCurrentLimit(5,0);
    shooterFeeder->EnableCurrentLimit(true);

    shooterFeeder->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder,0,0);
    shooterFeeder->SetSensorPhase(true);
    shooterFeeder->SetInverted(false);

    // Intake wheels spinner configuration
    frontSpinner->SetInverted(true);


}

void SubIntake::SpinFrontWheels(double speed) {
    // Write code here to spin the front wheels
    frontSpinner->Set(ControlMode::PercentOutput, speed);

}

void SubIntake::SpinShooterFeeder(double speed) {
    // Write code here to spin the shooter ball feeder
    shooterFeeder->Set(ControlMode::PercentOutput, speed);

}

void SubIntake::MoveIntakeToPosition(double position) {
    // Write code here to move the intake to position to intake balls etc.
    positionIntake->Set(ControlMode::Position, position);

}

void SubIntake::IndexShooterFeeder(double position) {
    shooterFeeder->Set(ControlMode::Position, position);
    m_indexPosition = position;

}
double SubIntake::GetIndexerPosition() {
    return m_indexPosition;
}
