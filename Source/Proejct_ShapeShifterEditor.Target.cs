// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class Proejct_ShapeShifterEditorTarget : TargetRules
{
	public Proejct_ShapeShifterEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "Proejct_ShapeShifter" } );
	}
}
