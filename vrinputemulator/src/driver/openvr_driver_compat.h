#ifndef _OPENVR_DRIVER_COMPAT_H
#define _OPENVR_DRIVER_COMPAT_H

#include <openvr_driver.h>
#include "openvr_controller_component.h"

namespace vr
{

// https://github.com/ValveSoftware/openvr/issues/724

inline IVRServerDriverHost_004 *VR_CALLTYPE VRServerDriverHost_004()
{
    static IVRServerDriverHost_004 *m_pVRServerDriverHost = nullptr;
    if (m_pVRServerDriverHost == nullptr)
    {
        EVRInitError eError;
        m_pVRServerDriverHost = (IVRServerDriverHost_004 *)VRDriverContext()->GetGenericInterface(IVRServerDriverHost_Version_004, &eError);
    }
    return m_pVRServerDriverHost;
}

} // namespace vr

#endif // _OPENVR_DRIVER_COMPAT_H