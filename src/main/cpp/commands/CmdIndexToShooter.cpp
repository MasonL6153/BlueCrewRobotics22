/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdIndexToShooter.h"

CmdIndexToShooter::CmdIndexToShooter(SubIntake* subIntake) : m_subIntake(subIntake){
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subIntake);
}

// Called when the command is initially scheduled.
void CmdIndexToShooter::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdIndexToShooter::Execute() {
  double position = m_subIntake->GetIndexerPosition();
  position = position + 13000;
  m_subIntake->IndexShooterFeeder(position);
  m_subIntake->SetBallCount(m_subIntake->GetBallCount()-1);  
  
}

// Called once the command ends or is interrupted.
void CmdIndexToShooter::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdIndexToShooter::IsFinished() {
  return true;
}