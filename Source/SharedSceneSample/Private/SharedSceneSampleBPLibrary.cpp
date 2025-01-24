/*
Copyright (c) Meta Platforms, Inc. and affiliates.
All rights reserved.

This source code is licensed under the license found in the
LICENSE file in the root directory of this source tree.
*/

#include "SharedSceneSampleBPLibrary.h"

#include "OculusXRFunctionLibrary.h"

bool USharedSceneSampleBPLibrary::GetDeviceSupportsLocalMultiplayer()
{
	EOculusXRDeviceType type = UOculusXRFunctionLibrary::GetDeviceType();
	return type == EOculusXRDeviceType::MetaQuestPro
		|| type == EOculusXRDeviceType::MetaQuestProLink
		|| type == EOculusXRDeviceType::MetaQuest3
		|| type == EOculusXRDeviceType::OculusQuest2
		|| type == EOculusXRDeviceType::Quest2_Link
		|| type == EOculusXRDeviceType::MetaQuest3Link;
}
