/*
 * Copyright (c) 2017 syscl/lighting/Yating Zhou. All rights reserved.
 *
 * Courtesy to vit9696's Lilu => https://github.com/vit9696/Lilu/
 *
 * Credit also corerobe for his codebase
 */

#include <Headers/plugin_start.hpp>
#include <Headers/kern_api.hpp>

#include "EnableLidWake.hpp"

static LidWake patchset;

const char* kBootArgvDisable[] = { "-elwoff"  };
const char* kBootArgvDebug[]   = { "-elwdbg"  };
const char* kBootArgvBeta[]    = { "-elwbeta" };


PluginConfiguration ADDPR(config) =
{
	xStringify(PRODUCT_NAME),
    parseModuleVersion(xStringify(MODULE_VERSION)),
    LiluAPI::AllowNormal | LiluAPI::AllowInstallerRecovery,
    
	kBootArgvDisable, arrsize(kBootArgvDisable),
    
    kBootArgvDebug,   arrsize(kBootArgvDebug),
    
	kBootArgvBeta,    arrsize(kBootArgvBeta),
    
    // minKernel: 10.10.x - maxKernel: 10.13.z
	KernelVersion::Yosemite, KernelVersion::HighSierra,

    // now let's get start
	[]() { patchset.init(); }
};
