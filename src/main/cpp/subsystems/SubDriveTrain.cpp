// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubDriveTrain.h"

SubDriveTrain::SubDriveTrain() = default;

// This method will be called once per scheduler run
void SubDriveTrain::Periodic() {}

// Configure the TalonFX's on the Drive Train
void SubDriveTrain::DriveTrainConfigure() {
  // PID constants for Profile 0 low gear Profile 1 high gear of Talon left
  leftDriveMotor->SetConfig_kF(0, frc::SmartDashboard::GetNumber("LEFT_KF_0",LEFT_KF_0));
  leftDriveMotor->SetConfig_kP(0, frc::SmartDashboard::GetNumber("LEFT_KP_0",LEFT_KP_0));
  leftDriveMotor->SetConfig_kI(0, frc::SmartDashboard::GetNumber("LEFT_KI_0",LEFT_KI_0));
  leftDriveMotor->SetConfig_kD(0, frc::SmartDashboard::GetNumber("LEFT_KD_0",LEFT_KD_0));

  leftDriveMotor->SetConfig_kF(1, frc::SmartDashboard::GetNumber("LEFT_KF_1",LEFT_KF_1));
  leftDriveMotor->SetConfig_kP(1, frc::SmartDashboard::GetNumber("LEFT_KP_1",LEFT_KP_1));
  leftDriveMotor->SetConfig_kI(1, frc::SmartDashboard::GetNumber("LEFT_KI_1",LEFT_KI_1));
  leftDriveMotor->SetConfig_kD(1, frc::SmartDashboard::GetNumber("LEFT_KD_1",LEFT_KD_1));

  // PID constants for Profile 0 low gear Profile 1 high gear of Talon Right
  rightDriveMotor->SetConfig_kF(0, frc::SmartDashboard::GetNumber("RIGHT_KF_0",RIGHT_KF_0));
  rightDriveMotor->SetConfig_kP(0, frc::SmartDashboard::GetNumber("RIGHT_KP_0",RIGHT_KP_0));
  rightDriveMotor->SetConfig_kI(0, frc::SmartDashboard::GetNumber("RIGHT_KI_0",RIGHT_KI_0));
  rightDriveMotor->SetConfig_kD(0, frc::SmartDashboard::GetNumber("RIGHT_KD_0",RIGHT_KD_0));

  rightDriveMotor->SetConfig_kF(1, frc::SmartDashboard::GetNumber("RIGHT_KF_1",RIGHT_KF_1));
  rightDriveMotor->SetConfig_kP(1, frc::SmartDashboard::GetNumber("RIGHT_KP_1",RIGHT_KP_1));
  rightDriveMotor->SetConfig_kI(1, frc::SmartDashboard::GetNumber("RIGHT_KI_1",RIGHT_KI_1));
  rightDriveMotor->SetConfig_kD(1, frc::SmartDashboard::GetNumber("RIGHT_KD_1",RIGHT_KD_1));

  // Clear the Sticky Faults on the controllers
  leftDriveMotor->ClearStickyFault();
  rightDriveMotor->ClearStickyFault();
  leftFollowMotor->ClearStickyFault();
  rightFollowMotor->ClearStickyFault();

  // Set the right Drive motor inverted
  rightDriveMotor->SetInverted(true);

  // Set the right and left followers
  leftFollowMotor->SetFollower(leftDriveMotor->GetMotorController());
  rightFollowMotor->SetFollower(rightDriveMotor->GetMotorController());

  // Set the feedback sensor
  leftDriveMotor->SetSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor);
  rightDriveMotor->SetSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor);

  // Set the current limts on the motor
  leftDriveMotor->SetStatorCurrentLimit(true,25,30,0.5);
  rightDriveMotor->SetSupplyCurrentLimit(true,CONTINUOUS_CURRENT_LIMIT,PEAK_CURRENT_LIMIT,DURATION_CURRENT_LIMIT);


}

// Drives the Drive Train with ArcadeDrive
void SubDriveTrain::Drive(double speed, double rotation) {
    driveTrain->SetDeadband(0.02);
    driveTrain->ArcadeDrive(speed, rotation, false);
}