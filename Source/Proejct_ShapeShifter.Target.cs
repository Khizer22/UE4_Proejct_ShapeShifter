// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class Proejct_ShapeShifterTarget : TargetRules
{
	public Proejct_ShapeShifterTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "Proejct_ShapeShifter" } );
	}
}
